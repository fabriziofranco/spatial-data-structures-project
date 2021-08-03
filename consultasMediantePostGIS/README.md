# Consultas Mediante PostGIS

Para la validación de resultados, nosotros utilizamos la estructura 
proporcionada por el repositorio sugerido en clase. Cargamos el archivo de _green data trips_ 
del mes de enero del año 2015 en la carpeta `data` y procedemos a inicializar la base de datos 
y cargar la data en dicha base con los comandos `.sh` proporcionados por el repositorio.

Una vez realizado ello, contamos con dos tablas de interés: **trips** y **taxi_zone**.

La primera cuenta con todos los viajes realizados en el mes de enero del año 2015 de los taxis verdes. 
Y la segunda cuenta con los polígonos y nombres de todos los neighborhoods de NY.

Para iniciar a realizar el cálculo, realizamos una principal alteración a la base de datos trips. 
Pasamos las coordenadas de dropoff y pickup a tipos de dato geometría para poder trabajar con ellos:
```SQL
SELECT AddGeometryColumn ('public','trips','pickup_geom',4326,'POINT',2);
SELECT AddGeometryColumn ('public','trips','dropoff_geom',4326,'POINT',2);

UPDATE trips SET pickup_geom = ST_SetSRID(ST_MakePoint(pickup_longitude, pickup_latitude), 4326)::geometry;
UPDATE trips SET dropoff_geom = ST_SetSRID(ST_MakePoint(dropoff_longitude, dropoff_latitude), 4326)::geometry;
```

**NOTA**: Cabe recalcar que durante el documento visualizaremos muchas veces el número `4326`. Este es el SRID que utilizamos 
para indicarle a nuestra geometría que estamos trabajando bajo un sistema de coordenadas geográficas.

Después, procedemos a verificar cuántos viajes hay en la base de datos:
```SQL
-- Cantidad de viajes
SELECT COUNT(trips.id)
FROM trips trips;
```
y efectivamente nos encontramos con **1 508 501** viajes.


## Consulta 1

¿Qué viajes tuvieron como origen y destino el mismo barrio?

```SQL
-- Número de viajes
SELECT COUNT(trips.id)
FROM trips
JOIN taxi_zones zones
ON ST_Intersects(trips.pickup_geom, zones.geom) AND ST_Intersects(trips.dropoff_geom, zones.geom);
```

Utilizando la función `ST_Intersects` proporcionada por PostGIS podemos calcular si verdaderamente 
se cuenta con una intersección entre dos geometrías. Así, en una simple consulta SQL podemos 
realizar un join con las zonas y filtrarlo únicamente cuando existe intersecciones en el pickup y dropoff.
Así, obtenemos **220 095** que se realizaron en el mismo neighborhood.

Ahora, para validar la veracidad de la consulta, realizamos una pequeña variación para poder conseguir los 3 primeros viajes que cumplieron dicha condición:

```SQL
-- Primeros 10 viajes
SELECT trips.id, zones.zone as neighborhood, trips.pickup_latitude, trips.pickup_longitude, trips.dropoff_latitude, trips.dropoff_longitude
FROM trips
JOIN taxi_zones zones
ON ST_Intersects(trips.pickup_geom, zones.geom) AND ST_Intersects(trips.dropoff_geom, zones.geom)
LIMIT 10;
```
| id | neighborhood | pickup\_latitude | pickup\_longitude | dropoff\_latitude | dropoff\_longitude |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 969597 | Steinway | 40.77593994140625 | -73.91082763671875 | 40.768695831298828 | -73.891334533691406 |
| 969599 | Bedford | 40.690994262695313 | -73.954818725585937 | 40.6824951171875 | -73.949989318847656 |
| 969606 | Bushwick South | 40.697311401367188 | -73.935569763183594 | 40.692031860351563 | -73.922607421875 |

donde realizando una búsqueda en Google Maps podemos verificar la veracidad de ellas.

| QUERY PLAN de la consulta 1 |
| :--- |
| Finalize Aggregate  \(cost=31764910.78..31764910.79 rows=1 width=8\) \(actual time=25888.337..25894.826 rows=1 loops=1\) |
|   -&gt;  Gather  \(cost=31764910.57..31764910.78 rows=2 width=8\) \(actual time=25888.319..25894.820 rows=3 loops=1\) |
|         Workers Planned: 2 |
|         Workers Launched: 2 |
|         -&gt;  Partial Aggregate  \(cost=31763910.57..31763910.58 rows=1 width=8\) \(actual time=25800.712..25800.713 rows=1 loops=3\) |
|               -&gt;  Nested Loop  \(cost=0.14..31760535.28 rows=1350115 width=8\) \(actual time=1.484..25751.857 rows=73365 loops=3\) |
|                     -&gt;  Parallel Seq Scan on trips  \(cost=0.00..140958.46 rows=630246 width=72\) \(actual time=0.096..855.915 rows=502834 loops=3\) |
|                     -&gt;  Index Scan using taxi\_zones\_geom\_idx on taxi\_zones zones  \(cost=0.14..50.16 rows=1 width=6027\) \(actual time=0.047..0.048 rows=0 loops=1508501\) |
|                           Index Cond: \(\(geom && trips.pickup\_geom\) AND \(geom && trips.dropoff\_geom\)\) |
|                           Filter: \(st\_intersects\(trips.pickup\_geom, geom\) AND st\_intersects\(trips.dropoff\_geom, geom\)\) |
|                           Rows Removed by Filter: 0 |
| Planning Time: 0.948 ms |
| Execution Time: 25894.901 ms |



## Consulta 2
¿Cuáles son los barrios con mayor cantidad de viajes?
Retornar los top 5. (Considerando apenas las coordenadas de partida).

Debido a que nos piden calcular los barrios con mayor cantidad de viajes, utilizamos 
la sentencia **GROUP BY** de SQL. Asimismo, la intersección la realizamos con las coordenadas 
de partida como lo solicita el ejercicio.
```SQL
SELECT zones.zone as neighborhood, COUNT(zones.zone)
FROM trips
JOIN taxi_zones zones
ON ST_Intersects(trips.pickup_geom, zones.geom)
GROUP BY zones.zone
ORDER BY COUNT(zones.zone) DESC
LIMIT 5;
```

Así, obtenemos el siguiente resultado:

| neighborhood | count |
| :--- | :--- |
| Williamsburg \(North Side\) | 80206 |
| Astoria | 74203 |
| East Harlem North | 73977 |
| Central Harlem | 71976 |
| East Harlem South | 69399 |


| QUERY PLAN de la consulta 2 |
| :--- |
| Limit  \(cost=16075912.71..16075912.72 rows=5 width=23\) \(actual time=36777.876..36782.270 rows=5 loops=1\) |
|   -&gt;  Sort  \(cost=16075912.71..16075913.36 rows=260 width=23\) \(actual time=36777.874..36782.267 rows=5 loops=1\) |
|         Sort Key: \(count\(zones.zone\)\) DESC |
|         Sort Method: top-N heapsort  Memory: 25kB |
|         -&gt;  Finalize GroupAggregate  \(cost=16075842.52..16075908.39 rows=260 width=23\) \(actual time=36775.706..36782.187 rows=238 loops=1\) |
|               Group Key: zones.zone |
|               -&gt;  Gather Merge  \(cost=16075842.52..16075903.19 rows=520 width=23\) \(actual time=36775.696..36781.581 rows=660 loops=1\) |
|                     Workers Planned: 2 |
|                     Workers Launched: 2 |
|                     -&gt;  Sort  \(cost=16074842.50..16074843.15 rows=260 width=23\) \(actual time=36649.550..36649.589 rows=220 loops=3\) |
|                           Sort Key: zones.zone |
|                           Sort Method: quicksort  Memory: 41kB |
|                           Worker 0:  Sort Method: quicksort  Memory: 41kB |
|                           Worker 1:  Sort Method: quicksort  Memory: 42kB |
|                           -&gt;  Partial HashAggregate  \(cost=16074829.47..16074832.07 rows=260 width=23\) \(actual time=36649.014..36649.091 rows=220 loops=3\) |
|                                 Group Key: zones.zone |
|                                 Batches: 1  Memory Usage: 61kB |
|                                 Worker 0:  Batches: 1  Memory Usage: 61kB |
|                                 Worker 1:  Batches: 1  Memory Usage: 61kB |
|                                 -&gt;  Nested Loop  \(cost=0.14..16002809.67 rows=14403960 width=15\) \(actual time=0.777..34055.295 rows=501619 loops=3\) |
|                                       -&gt;  Parallel Seq Scan on trips  \(cost=0.00..140958.46 rows=630246 width=32\) \(actual time=0.140..925.894 rows=502834 loops=3\) |
|                                       -&gt;  Index Scan using taxi\_zones\_geom\_idx on taxi\_zones zones  \(cost=0.14..25.16 rows=1 width=6042\) \(actual time=0.059..0.063 rows=1 loops=1508501\) |
|                                             Index Cond: \(geom && trips.pickup\_geom\) |
|                                             Filter: st\_intersects\(trips.pickup\_geom, geom\) |
|                                             Rows Removed by Filter: 1 |
| Planning Time: 0.802 ms |
| Execution Time: 36782.397 ms |


## Consulta 3
Dados dos puntos `P1` y `P2` que representan una región rectangular, retornar el número de viajes que comenzaron en tal región.

Para este caso nos apoyamos de la función `ST_MakeEnvelope` que nos permite generar una región rectangular en base a 2 puntos. 
Luego, apoyados del `ST_Intersects` realizamos la intersección respectiva con nuestro pickup location.

```SQL
SELECT COUNT(trips.id)
FROM trips
WHERE ST_Intersects(trips.pickup_geom,
        ST_MakeEnvelope( -73.907257080078125, 40.773754119873047, --P1
                         -73.991691589355469, 40.691108703613281, --P2
                         4326)::geometry
);
```

obteniendo unos **420 068** viajes que se generaron dentro de ese recuadro de coordenadas.

| QUERY PLAN de la consulta 3 |
| :--- |
| Finalize Aggregate  \(cost=15898551.05..15898551.06 rows=1 width=8\) \(actual time=817.241..821.505 rows=1 loops=1\) |
|   -&gt;  Gather  \(cost=15898550.83..15898551.04 rows=2 width=8\) \(actual time=817.146..821.494 rows=3 loops=1\) |
|         Workers Planned: 2 |
|         Workers Launched: 2 |
|         -&gt;  Partial Aggregate  \(cost=15897550.83..15897550.84 rows=1 width=8\) \(actual time=771.404..771.404 rows=1 loops=3\) |
|               -&gt;  Parallel Seq Scan on trips  \(cost=0.00..15897114.71 rows=174447 width=8\) \(actual time=0.106..755.326 rows=140023 loops=3\) |
|                     Filter: st\_intersects\(pickup\_geom, '0103000020E6100000010000000500000000000080107A52C0000000600A63444000000080107A52C00000004076584440000000E0777F52C00000004076584440000000E0777F52C0000000600A63444000000080107A52C0000000600A634440'::geometry\) |
|                     Rows Removed by Filter: 362811 |
| Planning Time: 0.148 ms |
| Execution Time: 821.558 ms |




## Consulta 4
Dado un punto `P` y una distancia `D`, encontrar los viajes que empezaron o terminaron a una distancia `D` como máximo a partir del punto `P`.

En este caso, el primer paso es realizar nuestra circunferencia de búsqueda de radio `D` que parta en el punto `P`. Para ello, 
la generamos apoyados de la función `ST_MakePoint` para realizar el punto y `ST_Buffer` para hacer la circunferencia, señalándole un radio 
en metros. Luego de calcular la geometría en cuestión, la almacenamos en una tabla de constantes para poder utilizarla después en 
nuestra consulta.

Ahora, para encontrar dichos viajes que empezaron y terminaron, seguimos una lógica muy similar a lo observado en consultas anteriores. 
Simplemente debemos de filtrar la data en las intersecciones, apoyados de `ST_Intersects`, de las geometrías pickup o dropoff con la geometría 
de nuestra circunferencia de búsqueda.


```SQL
WITH constants(circumference) as(
    values(ST_Buffer(ST_MakePoint( -73.907257080078125, 40.773754119873047 --POINT
                         )::geography, 2 --DISTANCE IN METERS
        )::geometry)
)
SELECT trips.id, trips.pickup_latitude, trips.pickup_longitude, trips.dropoff_latitude, trips.dropoff_longitude
FROM trips, constants
WHERE ST_Intersects(trips.pickup_geom, circumference) OR ST_Intersects(trips.dropoff_geom, circumference);
```

Podemos ahora visualizar que los siguientes viajes, con los siguientes ID's, se originaron o concluyeron a 2M a la redonda 
de las coordenadas -73.907257080078125, 40.773754119873047.


| id | pickup\_latitude | pickup\_longitude | dropoff\_latitude | dropoff\_longitude |
| :--- | :--- | :--- | :--- | :--- |
| 984833 | 40.758876800537109 | -73.919090270996094 | 40.773746490478516 | -73.907241821289063 |
| 1004415 | 40.773750305175781 | -73.907249450683594 | 40.755535125732422 | -73.968315124511719 |
| 1022796 | 40.773765563964844 | -73.907257080078125 | 40.781814575195313 | -73.913345336914063 |
| 1120661 | 40.773746490478516 | -73.907257080078125 | 40.763683319091797 | -73.914421081542969 |
| 1138549 | 40.756671905517578 | -73.920738220214844 | 40.773765563964844 | -73.907241821289063 |
| 93467 | 40.754650115966797 | -73.923690795898437 | 40.77374267578125 | -73.907257080078125 |
| 486841 | 40.773754119873047 | -73.907257080078125 | 40.775943756103516 | -73.910316467285156 |
| 724450 | 40.773754119873047 | -73.907249450683594 | 40.755527496337891 | -73.990486145019531 |


| QUERY PLAN de la consulta 3|
| :--- |
| Gather  \(cost=1000.00..31654271.06 rows=1 width=56\) \(actual time=17.188..912.496 rows=8 loops=1\) |
|   Workers Planned: 2 |
|   Workers Launched: 2 |
|   -&gt;  Parallel Seq Scan on trips  \(cost=0.00..31653270.96 rows=1 width=56\) \(actual time=296.209..857.100 rows=3 loops=3\) |
|         Filter: \(st\_intersects\(pickup\_geom, '0103000020E61000000100000021000000AE099D1C107A52C0B41A1E5E0A63444028C0C31E107A52C05161AC400A634440F50EA724107A52C076D86E240A63444040090D2E107A52C0D9537B0A0A6344402A39993A107A52C0F521D1F309634440672DD049107A52C0633C4FE109634440A7371C5B107A52C039B6ABD3096344402C2DD36D107A52C0D4BC6CCB09634440D6F03C81107A52C0D96FE3C80963444076869A94107A52C008C328CC09634440B0692DA7107A52C0DA881CD50963444042E03EB8107A52C0FFAE66E309634440B3FF26C7107A52C0DDA07AF6096344403D2153D3107A52C08BAE9C0D0A63444091844BDC107A52C04643E9270A634440F2E9B7E1107A52C063A45D440A63444064F662E3107A52C09DE2E1610A63444095403CE1107A52C0239C537F0A63444056F258DB107A52C04D25919B0A63444066F8F2D1107A52C05DAA84B50A63444097C866C5107A52C0C3DC2ECC0A63444032D42FB6107A52C0D7C2B0DE0A6344408AC9E3A4107A52C06C4954EC0A63444070D32C92107A52C00F4393F40A634440170FC37E107A52C01F901CF70A634440CC78656B107A52C0CF3CD7F30A6344400595D258107A52C0AE76E3EA0A634440161EC147107A52C0165099DC0A6344408BFED838107A52C0B45D85C90A6344402ADDAC2C107A52C0864F63B20A6344403D7AB423107A52C061BA16980A6344407215481E107A52C00359A27B0A634440AE099D1C107A52C0B41A1E5E0A634440'::geometry\) OR st\_intersects\(dropoff\_geom, '0103000020E61000000100000021000000AE099D1C107A52C0B41A1E5E0A63444028C0C31E107A52C05161AC400A634440F50EA724107A52C076D86E240A63444040090D2E107A52C0D9537B0A0A6344402A39993A107A52C0F521D1F309634440672DD049107A52C0633C4FE109634440A7371C5B107A52C039B6ABD3096344402C2DD36D107A52C0D4BC6CCB09634440D6F03C81107A52C0D96FE3C80963444076869A94107A52C008C328CC09634440B0692DA7107A52C0DA881CD50963444042E03EB8107A52C0FFAE66E309634440B3FF26C7107A52C0DDA07AF6096344403D2153D3107A52C08BAE9C0D0A63444091844BDC107A52C04643E9270A634440F2E9B7E1107A52C063A45D440A63444064F662E3107A52C09DE2E1610A63444095403CE1107A52C0239C537F0A63444056F258DB107A52C04D25919B0A63444066F8F2D1107A52C05DAA84B50A63444097C866C5107A52C0C3DC2ECC0A63444032D42FB6107A52C0D7C2B0DE0A6344408AC9E3A4107A52C06C4954EC0A63444070D32C92107A52C00F4393F40A634440170FC37E107A52C01F901CF70A634440CC78656B107A52C0CF3CD7F30A6344400595D258107A52C0AE76E3EA0A634440161EC147107A52C0165099DC0A6344408BFED838107A52C0B45D85C90A6344402ADDAC2C107A52C0864F63B20A6344403D7AB423107A52C061BA16980A6344407215481E107A52C00359A27B0A634440AE099D1C107A52C0B41A1E5E0A634440'::geometry\)\) |
|         Rows Removed by Filter: 502831 |
| Planning Time: 0.962 ms |
| Execution Time: 912.543 ms |
