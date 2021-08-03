-----------------------------
-- Preparar la base de datos
-----------------------------
SELECT AddGeometryColumn ('public','trips','pickup_geom',4326,'POINT',2);
SELECT AddGeometryColumn ('public','trips','dropoff_geom',4326,'POINT',2);

UPDATE trips SET pickup_geom = ST_SetSRID(ST_MakePoint(pickup_longitude, pickup_latitude), 4326)::geometry;
UPDATE trips SET dropoff_geom = ST_SetSRID(ST_MakePoint(dropoff_longitude, dropoff_latitude), 4326)::geometry;


-----------------------------
-- Información de interés
-----------------------------

-- Cantidad de viajes 
SELECT COUNT(trips.id)
FROM trips;

-----------------------------------------------------------------------------
-- CONSULTA 1 - ¿Qué viajes tuvieron como origen y destino el mismo barrio?
-----------------------------------------------------------------------------

-- Número de viajes
SELECT COUNT(trips.id)
FROM trips
JOIN taxi_zones zones
ON ST_Intersects(trips.pickup_geom, zones.geom) AND ST_Intersects(trips.dropoff_geom, zones.geom);


-- Primeros 10 viajes
SELECT trips.id, zones.zone as neighborhood, trips.pickup_latitude, trips.pickup_longitude, trips.dropoff_latitude, trips.dropoff_longitude
FROM trips
JOIN taxi_zones zones
ON ST_Intersects(trips.pickup_geom, zones.geom) AND ST_Intersects(trips.dropoff_geom, zones.geom)
LIMIT 10;



-----------------------------------------------------------------------------
-- CONSULTA 2 - ¿Cuáles son los barrios con mayor cantidad de viajes? 
-- Retornar los top 5. (Considerando apenas las coordenadas de partida).
-----------------------------------------------------------------------------

SELECT zones.zone as neighborhood, COUNT(zones.zone) 
FROM trips
JOIN taxi_zones zones
ON ST_Intersects(trips.pickup_geom, zones.geom)
GROUP BY zones.zone
ORDER BY COUNT(zones.zone) DESC
LIMIT 5;


-----------------------------------------------------------------------------
-- CONSULTA 3 - Dados dos puntos P1 y P2 que representan una región 
-- rectangular, retornar el número de viajes que comenzaron en tal región.
-----------------------------------------------------------------------------

SELECT COUNT(trips.id)
FROM trips
WHERE ST_Intersects(trips.pickup_geom,
						ST_MakeEnvelope( -73.907257080078125, 40.773754119873047, --P1
									 	 -73.991691589355469, 40.691108703613281, --P2
									 	 4326)::geometry
);

-----------------------------------------------------------------------------
-- CONSULTA 4 - Dado un punto P y una distancia D, encontrar los viajes que 
-- empezaron o terminaron a una distancia D como máximo a partir del punto P.
-----------------------------------------------------------------------------

WITH constants(circumference) as(
	values(ST_Buffer(ST_MakePoint( -73.907257080078125, 40.773754119873047 --POINT
	)::geography, 25 --DISTANCE IN METERS
					)::geometry)
)
SELECT trips.id, trips.pickup_latitude, trips.pickup_longitude, trips.dropoff_latitude, trips.dropoff_longitude
FROM trips, constants
WHERE ST_Intersects(trips.pickup_geom, circumference) OR ST_Intersects(trips.dropoff_geom, circumference);

