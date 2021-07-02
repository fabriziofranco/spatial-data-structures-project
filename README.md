

Universidad de Ingeniería y Tecnología

CS3102 - Estructuras de Datos avanzados

Escuela de Ciencia de la Computación

Propuesta de Proyecto: Consultas

Geo-referenciadas con Estructuras de Datos

Espaciales

Autores

Carlos Reátegui

carlos.reategui@utec.edu.pe

201810461

Docente

Rommel Quintanilla

Fabrizio Franco

fabrizio.franco@utec.edu.pe

201710466

Christian Ledgard

christian.ledgard@utec.edu.pe

201710403

21 de junio de 2021





Índice general

[1.](#br3)[ ](#br3)[El](#br3)[ ](#br3)[Problema/reto](#br3)

2

[2.](#br4)[ ](#br4)[Objetivos](#br4)

3

3

3

[2.1.](#br4)[ ](#br4)[Objetiv](#br4)[o](#br4)[ ](#br4)[Principal](#br4)[ ](#br4). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

[2.2.](#br4)[ ](#br4)[Objetivos](#br4)[ ](#br4)[Secundar](#br4)[ios](#br4)[ ](#br4). . . . . . . . . . . . . . . . . . . . . . . . . . . . .

[3.](#br6)[ ](#br6)[Antecedentes](#br6)

5

5

6

[3.1.](#br6)[ ](#br6)[Alternativas](#br6)[ ](#br6)[contempladas](#br6)[ ](#br6). . . . . . . . . . . . . . . . . . . . . . . . . . .

[3.2.](#br6)[ ](#br6)[Elección](#br6)[ ](#br6)[de](#br6)[ ](#br6)[la](#br6)[ ](#br6)[estructura](#br6)[ ](#br6)[de](#br6)[ ](#br6)[datos](#br7)[ ](#br7). . . . . . . . . . . . . . . . . . . . . . . .

[4.](#br8)[ ](#br8)[Solución](#br8)[ ](#br8)[propuesta](#br8)

7

7

7

7

9

[4.1.](#br8)[ ](#br8)[Descripción](#br8)[ ](#br8)[de](#br8)[ ](#br8)[la](#br8)[ ](#br8)[estructura](#br8)[ ](#br8). . . . . . . . . . . . . . . . . . . . . . . . . .

[4.2.](#br8)[ ](#br8)[Operaciones](#br8)[ ](#br8)[de](#br8)[ ](#br8)[la](#br8)[ ](#br8)[estructura](#br8)[ ](#br8)[que](#br8)[ ](#br8)[pueden](#br8)[ ](#br8)[ayudarnos](#br8)[ ](#br8)[a](#br8)[ ](#br8)[solucionar](#br8)[ ](#br8)[el](#br8)[ ](#br8)[problema](#br8)[ ](#br8).

[4.2.1.](#br8)[ ](#br8)[Point](#br8)[ ](#br8)[query](#br8)[ ](#br8)[.](#br8)[ ](#br8)[.](#br8)[ ](#br8)[.](#br8)[ ](#br8)[.](#br8)[ ](#br8)[.](#br8)[ ](#br8)[.](#br8)[ ](#br8)[.](#br8)[ ](#br8)[.](#br8)[ ](#br8)[.](#br8)[ ](#br8)[.](#br8)[ ](#br8)[.](#br8)[ ](#br8)[.](#br8)[ ](#br8)[.](#br8)[ ](#br8)[.](#br8)[ ](#br8)[.](#br8)[ ](#br8)[.](#br8)[ ](#br8)[.](#br8)[ ](#br8)[.](#br8)[ ](#br8)[.](#br8)[ ](#br8)[.](#br8)[ ](#br8)[.](#br8)[ ](#br8)[.](#br8)[ ](#br8)[.](#br8)[ ](#br8)[.](#br8)[ ](#br8)[.](#br8)[ ](#br8)[.](#br8)[ ](#br8)[.](#br8)[ ](#br8)[.](#br8)[ ](#br8)[.](#br8)[ ](#br8)[.](#br8)[ ](#br8).

[4.2.2.](#br8)[ ](#br8)[Enclosure](#br8)[ ](#br8)[q](#br8)[uery](#br10)[ ](#br10). . . . . . . . . . . . . . . . . . . . . . . . . . . .

[4.2.3.](#br10)[ ](#br10)[Range](#br10)[ ](#br10)[query](#br10)[ ](#br10)[.](#br10)[ ](#br10). . . . . . . . . . . . . . . . . . . . . . . . . . . . . 10

[4.2.4.](#br11)[ ](#br11)[Inserción](#br11)[ ](#br11)[.](#br11)[ ](#br11). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 11

[5.](#br14)[ ](#br14)[Acciones](#br14)[ ](#br14)[y](#br14)[ ](#br14)[cronograma](#br14)

13

[5.1.](#br14)[ ](#br14)[Fases](#br14)[ ](#br14)[.](#br14)[ ](#br14)[.](#br14)[ ](#br14)[.](#br14)[ ](#br14)[.](#br14)[ ](#br14)[.](#br14)[ ](#br14)[.](#br14)[ ](#br14)[.](#br14)[ ](#br14). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 13

[5.2.](#br14)[ ](#br14)[Acciones](#br14)[ ](#br14). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 13

[5.3.](#br16)[ ](#br16)[Cronograma](#br16)[ ](#br16). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 15

[6.](#br18)[ ](#br18)[Riesgos](#br18)

17

[6.1.](#br18)[ ](#br18)[Riesgos](#br18)[ ](#br18)[al](#br18)[ ](#br18)[generar](#br18)[ ](#br18)[la](#br18)[ ](#br18)[información](#br18)[ ](#br18). . . . . . . . . . . . . . . . . . . . . . . 17

[6.2.](#br18)[ ](#br18)[Riesgos](#br18)[ ](#br18)[al](#br18)[ ](#br18)[almacenar](#br18)[ ](#br18)[la](#br18)[ ](#br18)[información](#br18)[ ](#br18). . . . . . . . . . . . . . . . . . . . . . 18

[6.3.](#br19)[ ](#br19)[Riesgos](#br19)[ ](#br19)[al](#br19)[ ](#br19)[utilizar](#br19)[ ](#br19)[la](#br19)[ ](#br19)[información/operacionales](#br19)[ ](#br19). . . . . . . . . . . . . . . . 19

[7.](#br22)[ ](#br22)[Alcance](#br22)[ ](#br22)[y](#br22)[ ](#br22)[Limitaciones](#br22)

[Referencias](#br23)

21

22

1





Capítulo 1

El Problema/reto

El mundo se encuentra cada vez más conectado. [Department](#br23)[ ](#br23)nos menciona que en el 2012

existían 8,7 miles de millones de dispositivos [electrónicos](#br23)[ ](#br23)[conectados](#br23)[ ](#br23)a internet. Ahora, se

estima que este número sobrepasa los 50 miles de millones de dispositivos. Es decir, el creci-

miento ha sido de manera exponencial en los últimos años. En ese contexto, todos y cada uno

de los dispositivos se encuentra recolectando, enviando y recibiendo constantemente informa-

ción. Los datos enviados son procesados, almacenados y analizados por diversas empresas

tecnológicas para obtener insights con el ﬁn de generar conocimiento.

Por lo tanto, identiﬁcamos la necesidad de contar con estructuras eﬁcientes que nos asegu-

ren escalabilidad en el uso de memoria y tiempo de ejecución para procesar el masivo volumen

de datos dentro del tiempo y espacio de memoria proporcionado. Lamentablemente, esta no

es una tarea fácil, por lo que las decisiones de diseño deben tomarse basadas en un profundo

análisis teórico y referencias bibliográﬁcas conﬁables.

En este proyecto trabajaremos con el conjunto de datos de viajes de taxi entre 2015 y 2020

de la ciudad de Nueva York, una de las ciudades con mayor densidad poblacional en donde el

servicio de taxis es reconocido por su frecuente uso. Para producir consultas adecuadas en un

tiempo razonable, utilizaremos una estructuras de datos espacial para las siguientes consultas:

\1. ¿Qué viajes tuvieron como origen y destino el mismo barrio?

\2. ¿Cuáles son los barrios con mayor cantidad de viajes? Retornar los k primeros del top.

\3. Dados dos puntos P1 y P2 que representan una región rectangular, retornar el número

de viajes que comenzaron en tal región.

\4. Determinar por cuales vecindarios pasó un taxi en un determinado viaje, considerando

la ruta como una línea recta.

\5. Dado un punto P y una distancia D, encontrar los viajes que empezaron o terminaron a

una distancia D como máximo a partir del punto P.

2





Capítulo 2

Objetivos

2.1. Objetivo Principal

Implementar una estructura de datos espacial dinámica que permita realizar consultas

eﬁcientes sobre conjunto de datos de viajes de taxi en la ciudad de Nueva York.

2.2. Objetivos Secundarios

\1. Analizar la complejidad computacional al manejar los grandes volúmenes de datos en

las consultas encomendadas y elegir la que sea menos costosa en tiempo.

Key Results:

Desarrollar algoritmos con la mejor complejidad teórica posible para las consultas

asignadas.

Descartar algoritmos que sobrepasen una complejidad en tiempo determinada tras

realizar el análisis respectivo.

Comprobar experimentalmente el tiempo de respuesta.

\2. Realizar un estado del arte relacionado a estructuras espaciales para tener el conoci-

miento necesario para proponer la que se aducue mejor a las consultas y los datos

proporcionados.

Key Results:

Leer al menos 3 papers por desarrollador antes de iniciar la fase de desarrollo.

Diseñar algoritmos basados en la literatura analizada, donde se evidencie que se

han seguido las recomendaciones y pautas de los diferentes autores.

Veriﬁcar a través de una segunda ronda de estado del arte que la elección sobre

la estructura de datos sea la correcta, esto a través de una comparativa entre lo

desarrollado por nosotros y lo desarrollado por los nuevos autores leídos en sus

respectivas aproximaciones al problema de consultas espaciales.

3





\3. Contar con un conjunto de datos integro, completo y homogéneo, lo cual permitirá una

adecuada experimentación en el desarrollo de la estructura propuesta.

Key Results:

Consolidar los datos para que estos se encuentren estandarizados y no cuenten con

errores de formato.

Veriﬁcar que todos los datos descargados de la fuente correspondas efectivamente

a nuestra región y problema de interés.

\4. Elaborar una propuesta de diseño sobre la estructura elegida para el presente trabajo.

Se abordarán las ventajas y desventajas acordes para poder tener un mejor panorama y

tomar la mejor decisión.

Key Results:

Realizar un análisis teórico sobre todas las posibles estructuras contempladas al

terminar la primera ronda del estado del arte. En base a ello, elegir la estructura

cuya complejidad en tiempo sea menor para las consultas requeridas.

Veriﬁcar si es posible realizar alguna optimización para los algoritmos desarrolla-

dos, de ser el caso desarrollarla.

\5. Determinar posibles limitantes de la solución propuestas con el objetivo de acotar el

diseño al alcance determinado para este proyecto.

Key Results:

Realizar una prueba de micro-benchmark para determinar las limitaciones de la

estructura propuesta.

Veriﬁcar a través de Catch y/o Google Test que la estructura propuesta se comporta

adecuadamente en todos los escenarios correspondientes.

Tras la etapa de testing, determinar posibles cuellos de botella y proponer alterna-

tivas de solución sobre dichos problemas, de ser posible.

\6. Analizar la correctitud la estructura propuesta.

Key Results:

Realizar un análisis matemático de la invariante del algoritmo para veriﬁcar si

verdaderamente resuelve el problema computacional para el cual fue diseñado.

Veriﬁcar que la solución propuesta entregue los resultados experimentales espera-

dos de cada query (comparar contra los obtenidos en un DBMS sobre SQL).

Veriﬁcar experimental que el tiempo de ejecución del algoritmo desarrollado sea

ﬁnito.

4





Capítulo 3

Antecedentes

3.1. Alternativas contempladas

Durante el estado del arte, nos sumergimos en el conjunto de estructura de datos espaciales,

luego de indagar individualmente, coincidimos en 3 estructuras candidatas para la propuesta

de solución:

\1. KD-Tree [(Otair,](#br23)[ ](#br23)[2013)](#br23)

Esta estructura es un árbol binario, en donde cada nodo representa una tupla/objeto con k

dimensiones. Dicha estructura, inventada en el año 1975 por Jon Bentle, es una estructura

de generalización multidimencional para un árbol de búsqueda binaria. Acorde a [Otair](#br23)

esta puede ser utilizada eﬁcientemente para realizar consultas de rango o búsq[uedas](#br23)

de vecinos más cercanos (KNN) cuando la dimensión no es muy alta. Asimismo, nos

menciona que se utiliza típicamente en dos dimensiones, ya que cuándo se agregan más

dimensiones, su performance se degrada rápidamente.

\2. Region QuadTree [(D’Angelo,](#br23)[ ](#br23)[1984)](#br23)

Acorde a [D’Angelo](#br23)[ ](#br23)el quadtree es una estructura de datos espaciales jerárquica. Es un

árbol en [el](#br23)[ ](#br23)[que](#br23)[ ](#br23)[cada](#br23)[ ](#br23)nivel corresponde a un mayor detalle del espacio en cuestión.

Asimismo, el autor nos comenta que existen varias variaciones de dicha estructura pero

la idea principal se mantiene: descomponer recursivamente el espacio para almacenar

información de interés. Para la variación especíﬁca del Region Quadtrees, la data se

encuentra almacenada en los nodos hoja y la información que almacena se encuentra

estrechamente relacionada a dicho espacio que representa. Una de sus aplicaciones más

utilizadas son el almacenamiento de imágenes en donde en lugar de tener una matriz

de tamaño completo, el Quadtree captura dicha información y la divide en niveles

eliminando posibles redundancias y ahorrándonos gran espacio de almacenamiento.

\3. R-Tree [(Hadjieleftheriou,](#br23)[ ](#br23)[Manolopoulos,](#br23)[ ](#br23)[Theodoridis,](#br23)[ ](#br23)[y](#br23)[ ](#br23)[Tsotras,](#br23)[ ](#br23)[2008)](#br23)[ ](#br23)y [(Guttman,](#br23)

[1984)](#br23)

5





Esta estructura [(Guttman,](#br23)[ ](#br23)[1984),](#br23)[ ](#br23)es una de las más inﬂuyentes cuando hablamos de

manejo de data [espacial.](#br23)[ ](#br23)[Se](#br23)[ ](#br23)[encuentra](#br23)[ ](#br23)basada en B -trees y es utilizada para la organi-

\+

zación dinámica de conjunto de datos geométricos. Guttman diseño dicha estructura con

el objetivo de manejar datos geométricos como puntos, lineas, segmentos, superﬁcies y

volúmenes. Hoy en día, esta estructura es crucial en el almacenamiento masivo de datos

referentes a geo-localización.

[Hadjieleftheriou](#br23)[ ](#br23)[y](#br23)[ ](#br23)[cols.](#br23)[ ](#br23)nos menciona que los R-trees pueden ser utilizados para procesar

[consultas](#br23)[ ](#br23)[espaciales,](#br23)[ ](#br23)[entre](#br23)[ ](#br23)ellas encontramos ejemplos como identiﬁcar datos en una

región determinada, determinar los vecinos más y joins espaciales, como por ejemplo

encontrar pares de datos que satisfagan una condición dada.

3.2. Elección de la estructura de datos

El KD-Tree fue descartado porque está limitado a contener únicamente puntos, mas no

rectángulos. Decidimos usar el R-Tree sobre las otras opciones porque el proyecto requiere

diseñar consultas que hacen uso de muchas búsquedas, y de todas las estructuras analizadas,

la que tiene menor complejidad en tiempo es el R-Tree, ya que es un árbol que se mantiene

balanceado y por este motivo realiza sus búsquedas en tiempo logarítmico, mientras que los

otros dos árboles (KD-Tree y el Region QuadTree) pueden presentar desbalanceo, lo que podría

empeorar signiﬁcativamente el tiempo de las consultas. Asimismo, el Region QuadTree puede

presentar mucho nodos casi vacíos, lo cual es un gran desperdicio de memoria, especialmente

para el volumen de datos que vamos a manejar en el proyecto.

6





Capítulo 4

Solución propuesta

4.1. Descripción de la estructura

Un R-Tree es un árbol balanceado que realiza consultas espaciales eﬁcientes gracias a su

estructura de índice. Cada nodo guarda sus límites usando dos puntos (esquina inferior derecha

y esquina superior derecha de un rectángulo) y un puntero a sus hĳos. Solo los nodos hoja

guardan punteros a los objetos de datos a consultar [(Guttman,](#br23)[ ](#br23)[1984).](#br23)

En la ﬁgura [4.2](#br13)[ ](#br13)se puede observar un ejemplo [del](#br23)[ ](#br23)[R-Tree](#br23)[ ](#br23)[propues](#br23)to por Guttman.

4.2. Operaciones de la estructura que pueden ayudarnos a

solucionar el problema

A continuación, señalaremos las operaciones encontradas en la literatura cuya implemen-

tación en el proyecto consideramos pertinente para poder lograr los objetivos anteriormente

mencionados.

Nota: M es la cantidad máxima de hĳos por nodo interno en un R-Tree.

4.2.1. Point query

Descripción

Consulta que retorna los objetos del árbol que contienen a un punto.

Recibe: un punto y la raíz del árbol.

Retorna: objetos que contienen al punto.

Se puede observar un pseudocódigo a continuación [(Cheung,](#br23)[ ](#br23)[2000):](#br23)

point\_query(point, root):

result = {}

point\_query\_helper(point, root, result)

return result

7





Figura 4.1: Un R-Tree [(Guttman,](#br23)[ ](#br23)[1984).](#br23)

8





point\_query\_helper(point, node, result):

if (node.is\_internal):

for (child in node.children):

if (point is inside child):

point\_query\_helper(point, child, result)

else: // si el nodo es hoja

for (object in node.objects):

if (point is inside object):

add point to result

Performance

Dado que un R-Tree es un árbol balanceado, la búsqueda de un punto tomará O(MlogM (n))

en tiempo, ya que la altura del árbol es dlog (n)e − 1 [(Guttman,](#br23)[ ](#br23)[1984)](#br23)[ ](#br23)y en cada nivel se

M

hacen como máximo M operaciones.

Asimismo, tomará O(logM (n)) en espacio, ya que al ser una función recursiva utiliza

espacio constante del stack en cada llamada, y habrán como máximo dlog (n)e − 1 llamadas

M

a la función.

Consulta(s) que nos puede ayudar a resolver

¿Qué viajes tuvieron como origen y destino el mismo barrio?

4.2.2. Enclosure query

Descripción

Consulta que retorna los objetos del árbol que contienen a otro objeto (el objeto consultado).

Recibe: un objeto y la raíz del árbol.

Retorna: los objetos que contienen al objeto del input.

Se puede observar un pseudocódigo a continuación [(Cheung,](#br23)[ ](#br23)[2000):](#br23)

enclosure\_query(object\_q, root):

result = {}

enclosure\_query\_helper(object\_q, root, result)

return result

enclosure\_query\_helper(object\_q, node, result):

if (node.is\_internal):

for (child in node.children):

if (object\_q is inside child):

point\_query\_helper(object\_q, child, result)

else: // si el nodo es hoja

for (object in node.objects):

if (object\_q is inside object):

9





add object to result

Performance

Misma complejidad computacional en tiempo y en espacio que el algoritmo de Point query

por las mismas razones mencionadas anteriormente.

Tiempo: O(MlogM (n)).

Espacio: O(logM (n)).

Consulta(s) que nos puede ayudar a resolver

Determinar por cuáles vecindarios pasó un taxi en un determinado viaje, considerando

la ruta como una línea recta.

4.2.3. Range query

Descripción

Consulta que retorna todos los objetos que tienen al menos un punto dentro de una ventana.

Recibe: la ventana.

Retorna: los objetos.

Se puede observar un pseudocódigo a continuación:

range\_query(window, root):

result = {}

range\_query\_helper(window, root, result)

return result

range\_query\_helper(window, node, result):

if (node.is\_internal):

for (child in node.children):

if (child intersects window):

range\_query\_helper(window, node, result)

else:

for (objects in node.objects):

if (object intersects window):

add object to result

Performance

Misma complejidad computacional en tiempo y en espacio que el algoritmo de Point query

por las mismas razones mencionadas anteriormente.

Tiempo: O(MlogM (n)).

Espacio: O(logM (n)).

10





Consulta(s) que nos puede ayudar a resolver

Dado un punto P y una distancia D, encontrar los viajes que empezaron o terminaron a

una distancia D como máximo a partir del punto P.

Dados dos puntos P1 y P2 que representan una región rectangular, retornar el número

de viajes que comenzaron en tal región.

4.2.4. Inserción

Descripción

Inserta un objeto en un árbol R-Tree.

Recibe: el objeto y la raíz del árbol.

Retorna: nada.

Se puede observar un pseudocódigo a continuación [(Cheung,](#br23)[ ](#br23)[2000):](#br23)

insert(object, node):

if (node.is\_internal):

for (child in node.children):

if (object is inside child):

insert(object, child);

return

/\* si se alcanza esta sección, eso quiere decir que

el objeto no entra en ningún subárbol \*/

/\* Encontrar un hijo del nodo tal que alargar a

a este hijo agregará la menor área posible \*/

/\* Actualizar límites del árbol \*/

insert(object, selected\_child)

else:

if (node has space):

// función que inserta un objeto en un nodo hoja

insert\_obj(node, object)

else:

// partir nodo hoja en 2

// actualizar límites de los nuevos nodos

// actualizar nodos del padre

// verificar si el padre debe hacer split

Performance

En el mejor de los casos, la inserción toma O(Mlog (n)) en tiempo, asumiendo que no

M

hay que aumentar el tamaño de los nodos ni hacer split.

La literatura indica que la complejidad de inserción puede variar, ya que existen diferentes

algoritmos para partir los nodos cuando hay overﬂow para encontrar los nuevos nodos que

minimicen el perímetro total. Guttman [(Guttman,](#br23)[ ](#br23)[1984)](#br23)[ ](#br23)propuso algoritmos cuadráticos, ex-

ponenciales y lineales para partir [nodos;](#br23)[ ](#br23)[cada](#br23)[ ](#br23)[algoritmo](#br23)[ ](#br23)da diferentes resultados, siendo el

11





exponencial el que siempre retorna la mejor opción.

En términos de complejidad en espacio, ocupa O(MlogM (n)) por el espacio del stack.

Consulta(s) que nos puede ayudar a resolver

La inserción es indispensable, puesto que la estructura debe estar poblada para realizar las

operaciones de búsquedas, por ello ayuda a resolver todas las consultas, ya que las búsquedas

que se ejecuten la requieren de forma indirecta.

Figura 4.2: Taxis de Nueva York que generan la data recolectada: Recuperado de LaVanguardia

12





Capítulo 5

Acciones y cronograma

5.1. Fases

El proyecto contará con las siguientes fases, y durante cada una de ellas se realizarán

diferentes actividades.

Fase

Código

Descripción

Obtener / optimizar recursos necesarios

para la implementación.

Fase inicial

F1

Obtener los resultados esperados a las

preguntas de las indicaciones del proyecto

a través del uso de SQL.

Fase de obtención de resultados esperados

F2

Implementación de la estructura de datos,

junto con las operaciones

necesarias para resolver las indicaciones del proyecto.

Realizar la documentación del proyecto, detallando la

estructura diseñada y las operaciones que esta soporta.

Fase de implementación

Fase de documentación

F3

F4

5.2. Acciones

A continuación se puede observar la tabla de acciones a realizar durante el desarrollo del

proyecto. El tiempo que tomará cada una de las acciones fue estimado usando la fórmula del

Program evaluation and review technique (PERT) en días hábiles.

PERT weighted average = OT +4~~·~~M6LT +P T , donde OT es optimistic time, MLT es most

likely time y PT es pessimistic time.

Objetivo

Descripción

cuantitativa

Acción

Código Fase

PERT

relacionado

13





Analizar el dominio de datos

y diseñar un programa en Python

para limpiar los primeros doce (12)

archivos .csv del repositorio de taxis.

Crear una (1) base de datos para almacenar

los doce (12) archivos de datos

inicialmente limpiados. Almacenar

todo en una sola tabla diseñando

las consultas correspondientes.

Crear el repositorio de trabajo en

github.com para poder

Limpieza

de datos

\- Objetivo

A1

F1

3

secundario 3

Ingresar datos

en PostgreSQL

\- Objetivo

secundario 6

A2

A3

A4

F1

F1

F1

2

1

4

\- Objetivo

general

Crear repositorio

programar colaborativamente.

Diseñar una solución a alto nivel

(sin implementación) que aplique las

recomendaciones de la bibliografía

consultada, con el ﬁn de presentar

una propuesta eﬁciente y correcta.

Diseñar las consultas en la base

de datos creada anteriormente para

obtener la respuesta correcta a las

cinco (5) preguntas del proyecto,

con el ﬁn de tomarlas como

referencia al momento de

\- Objetivo

secundario 2

\- Objetivo

Diseñar una

solución a alto nivel

secundario 4

Obtener resultados

esperados en SQL

\- Objetivo

secundario 6

A5

F2

5

empezar la fase de

implementación (F3).

Implementar la operación de inserción

sobre la estructura a utilizar.

Probar insertando cincuenta (50)

datos aleatorios, con el ﬁn

Implementar

\- Objetivo

general

A6

A7

A8

F3

F3

F3

4

3

3

inserción dinámica

de analizar la correctitud de

la operación.

Implementar la operación de

point query. Esta recibe un

Implementar

point query

\- Objetivo

general

punto y retorna el vecindario

en el cual este se encuentra.

Implementar la operación de

range query. Dado un

Implementar

range query

\- Objetivo

general

intervalo en 2D, retornar

todos los puntos en

el plano que se encuentran

dentro de este.

14





Implementar la operación de

enclosure query. Dado un

objeto en 2D, retornar

Implementar

\- Objetivo

general

A9

F3

F4

4

6

enclosure query

todos los puntos en

el plano que se

encuentran dentro de este.

Redactar la documentación de

la estructura utilizada, detallando:

\- Objetivo

general

\- Objetivo

secundario 1

\- Objetivo

secundario 5

\- Cómo cargar los datos

a la estructura.

Redactar

documentación

A10

\- Cómo usar las

operaciones implementadas.

\- La complejidad computacional

en espacio y tiempo de cada

una de las operaciones.

\- Posibles mejoras a realizar.

5.3. Cronograma

A continuación se puede observar el cronograma del proyecto:

15





~~Tarea~~

Fase 1

~~Duración~~

~~Inicio~~

~~Fin~~

~~Código~~

2 semanas 21-jun 4-julio

Limpieza

3 días

2 día

1 día

21-jun 23-jun

24-jun 25-jun

27-jun 27-jun

A1

A2

A3

A4

de datos

Ingresar datos

en PostgreSQL

Crear

repositorio

Diseñar una

solución a alto nivel

Fase 2

Obtener resultados

esperados en SQL

Fase 3

4 días

1 semana

5 días

28-jun

5-jul

5-jul

2-jul

11-jul

9-jul

A5

2 semanas 12-jul

25-jul

15-jul

Implementar

inserción dinámica

Implementar

point query

Implementar

range query

Implementar

enclosure query

Fase 4

4 días

3 días

3 días

12-jul

16-jul

19-jul

A6

A7

A8

A9

18-jul

21-jul

4 días

1 semana

6 días

22-jul

26-jul

26-jul

25-jul

1-ago

31-jul

Redactar

A10

\-

documentación

Cerrar

1 día

1-ago

1-ago

proyecto

16





Capítulo 6

Riesgos

Acorde a lo propuesto por [Laudon,](#br23)[ ](#br23)[Laudon,](#br23)[ ](#br23)[Alfono,](#br23)[ ](#br23)[y](#br23)[ ](#br23)[Fernando](#br23)[ ](#br23)en Managing the Digital

Firm, los riesgos [operacionales](#br23)[ ](#br23)[vinculados](#br23)[ ](#br23)[a](#br23)[ ](#br23)[software](#br23)[ ](#br23)[que](#br23)[ ](#br23)[maneje](#br23)[ ](#br23)volúmenes masivos de

información pueden dividirse en tres secciones, las cuales tomaremos para desarrollo de este

proyecto, asimismo las acciones a tomar están orientadas a la prevención y anticipación de

riesgos:

Al generar la información

Al almacenar la información

Al utilizar la información/operacionales

6.1. Riesgos al generar la información

\1. Tuplas incompletas

Detalle: Los datos del dataset 1 referente a los viajes realizados en NY, podrían

tener tuplas con campos faltantes, lo cual generaría errores al realizar consultas

como las de rango, ya que se requiere que todas y cada una de las tuplas tengan sus

valores completos.

Risk Trigger:

• Error de memoria al intentar acceder a un dato inexistente.

Probabilidad: Media.

Impacto Cualitativo: Medio.

Impacto Cuantitativo: Los datos no completos tendrán que ser eliminados, redu-

ciendo así el tamaño del dataset en una porción aún desconocida.

Acciones a tomar:

• Eliminar la tupla, en caso sea un caso atípico.

17





• Eliminar el subset, en caso no contemple alguno de los campos requeridos o

en caso la falta de datos sea frecuente.

\2. Datos que no reﬂejen las valores reales recolectados

Detalle: Los datos tienen datos irreales, producto de haber sido reportados erró-

neamente, por ejemplo, una latitud que no corresponde a la real. Esto provocaría

que los resultados de las consultas pierdan signiﬁcancia, por ejemplo podría haber

una tupla cuya latitud corresponda a una ubicación fuera de NY, por ejemplo, la

ciudad de Lima, y este valor atípico arruinaría las consultas.

Risk Trigger:

• Obtener un resultado durante las consultas que carezca de sentido.

Probabilidad: Bajo.

Impacto Cualitativo: Bajo.

Impacto Cuantitativo: Tiempo en la limpieza de datos erróneos, tras su detección

en el proceso de testing.

Acciones a tomar:

• Eliminar la tupla tras ser detectada.

• Eliminar el subset, en caso sea frecuente dicho error en esa porción de la data.

6.2. Riesgos al almacenar la información

\1. Falta de estandarización en los datos

Detalle: Los valores de latitud y longitud del dataset 1 pueden estar expresados en

diferentes unidades ya que son grados. Por lo tanto, si no se estandariza la unidad

los resultados de las consultas serían erróneos.

Risk Trigger:

• Obtener un resultado durante las consultas que carezca de sentido.

Probabilidad: Bajo.

Impacto Cualitativo: Alto.

Impacto Cuantitativo: Tiempo en estandarizar la data, se estima aprox. 2h en

realizarlo. No es necesario depurar ningún dato.

Acciones a tomar:

• Realizar una revisión general de los datos.

\2. Almacenar datos durante una consulta en ejecución (Thread safety)

Detalle: Modiﬁcar la estructura mientras es consultada, generaría errores en el

manejo de threads.

18





Risk Trigger:

• Error en el manejo de threads detectado por Helgrind.

Probabilidad: Alto.

Impacto Cualitativo: Alto.

Impacto Cuantitativo: Tiempo en aplicar el mecanismo de bloqueo que asegure la

exclusión mutua se estima aprox. 4h en realizarlo.

Acciones a tomar:

• Se aplicará un bloqueo de tipo reader-writer, el cual implica múltiples lectores

en paralelo, pero la escritura solo puede realizarse cuando ningún otro thread

desea acceder a la estructura.

6.3. Riesgos al utilizar la información/operacionales

\1. Datos que no favorezcan la etapa de testing

Detalle: Se puede volver sumamente diﬁcultoso testear con volúmenes de datos tan

grandes o los datos no están organizados de tal manera que los resultados obtenidos

permitan encontrar errores lógico en el código.

Risk Trigger:

• Horas de debugging sin progreso.

Probabilidad: Bajo.

Impacto Cualitativo: Alto.

Impacto Cuantitativo: N horas perdidas intentando encontrar errores lógicos sin

tener éxito. 1 hora invertida en generar un dataset de conveniencia para debuggear

con mayor facilidad

Acciones a tomar:

• Generar un dataset de convenciencia con ﬁnes de testing.

\2. No estimar correctamente las acciones y el calendario de actividades

Detalle: Una mala estimación de tiempos podría comprometer los requerimientos

del proyecto.

Risk Trigger:

• Elaboración del calendario.

Probabilidad: Medio.

Impacto Cualitativo: Alto.

Impacto Cuantitativo: No culminar un aproximado de 2-3 requerimientos (consul-

tas) del proyecto

Acciones a tomar:

19





• Realizar todas las estimaciones de tiempo siguiendo un enfoque PERT[(Laudon](#br23)

[y](#br23)[ ](#br23)[cols.,](#br23)[ ](#br23)[2016)](#br23)

\3. Código que diﬁculte el proceso de debugging

Detalle: Conforme crezca la implementación del código, esta podría tornarse poco

legible teniendo malas prácticas

Risk Trigger:

• Iinicio de implementación del código.

Probabilidad: Alto.

Impacto Cualitativo: Medio.

Impacto Cuantitativo: Generar errores lógicos debido a la poca legilibidad del

código. Tiempo perdido estimado: 3 horas.

Acciones a tomar:

• Seguir durante toda la implementación del proyecto las recomendaciones y

lineamientos de Clean Code [(Martin,](#br23)[ ](#br23)[2008)](#br23)

20





Capítulo 7

Alcance y Limitaciones

\1. La estructura de datos estará diseñada para la base de datos proporcionada por

el proveedor. Por ello, el desarrollo del proyecto se realizará con sus datos, ya se

informó los riesgos que esto implica, sin embargo, que todo el proceso de desarrollo de

software esté basado en dicha data, es un sesgo y es importante reconocerlo a la hora de

implementar la estructura, ya que en caso se quisiera aplicar la estructura obtenida al ﬁnal

del proyecto para otros escenarios con consultas similares, sería necesaria desarrollar

algunas modiﬁcaciones que aseguren el correcto funcionamiento en un nuevo contexto

fuera del alcance previsto para este proyecto.

\2. En línea de producción las consultas con las siguientes complejidades funcionarán

adecuadamente para los siguientes volúmenes de datos, dado un tiempo máximo

estimado de 5 segundos. Se asume que el servidor donde estará deployado el back-end

es capaz de ejecutar 10 operaciones por segundo. Si se deseara ampliar el volumen

8

máximo, tendría que ampliarse el tiempo máximo de respuesta aceptado, dicha decisión

corre por parte de la empresa de taxis de NY, ya que serán los usuarios del software

desarrollado en este proyecto.

Complejidad de consultas Máximo volumen (n)

N!

N3 ∗ lg(N)

12 datos

600 datos

800 datos

11k datos

22k datos

64M datos

500M datos

N3

N2 ∗ lg(N)

N2

N ∗ lg(N)

N

lg(N)

105∗108

datos

21





Referencias

Cheung, S. Y. (2000). Descargado de [http://www.mathcs.emory.edu/~cheung/](http://www.mathcs.emory.edu/~cheung/Courses/554/Syllabus/3-index/R-tree.html)

[Courses/554/Syllabus/3-index/R-tree.html](http://www.mathcs.emory.edu/~cheung/Courses/554/Syllabus/3-index/R-tree.html)

Depar[tment,](http://www.mathcs.emory.edu/~cheung/Courses/554/Syllabus/3-index/R-tree.html)[ ](http://www.mathcs.emory.edu/~cheung/Courses/554/Syllabus/3-index/R-tree.html)[S.](http://www.mathcs.emory.edu/~cheung/Courses/554/Syllabus/3-index/R-tree.html)[ ](http://www.mathcs.emory.edu/~cheung/Courses/554/Syllabus/3-index/R-tree.html)[R.](http://www.mathcs.emory.edu/~cheung/Courses/554/Syllabus/3-index/R-tree.html)[ ](http://www.mathcs.emory.edu/~cheung/Courses/554/Syllabus/3-index/R-tree.html)[(s.f.).](http://www.mathcs.emory.edu/~cheung/Courses/554/Syllabus/3-index/R-tree.html)[ ](http://www.mathcs.emory.edu/~cheung/Courses/554/Syllabus/3-index/R-tree.html)[Internet](http://www.mathcs.emory.edu/~cheung/Courses/554/Syllabus/3-index/R-tree.html)[ ](http://www.mathcs.emory.edu/~cheung/Courses/554/Syllabus/3-index/R-tree.html)[de](http://www.mathcs.emory.edu/~cheung/Courses/554/Syllabus/3-index/R-tree.html)[ ](http://www.mathcs.emory.edu/~cheung/Courses/554/Syllabus/3-index/R-tree.html)[las](http://www.mathcs.emory.edu/~cheung/Courses/554/Syllabus/3-index/R-tree.html)[ ](http://www.mathcs.emory.edu/~cheung/Courses/554/Syllabus/3-index/R-tree.html)[cosas:](http://www.mathcs.emory.edu/~cheung/Courses/554/Syllabus/3-index/R-tree.html)[ ](http://www.mathcs.emory.edu/~cheung/Courses/554/Syllabus/3-index/R-tree.html)[dispositiv](http://www.mathcs.emory.edu/~cheung/Courses/554/Syllabus/3-index/R-tree.html)os interconectados en el mun-

do 2020. Descargado de [https://es.statista.com/estadisticas/638100/](https://es.statista.com/estadisticas/638100/internet-de-las-cosas-numero-de-dispositivos-conectados-en-todo-el-mundo--2020/)

[internet-de-las-cosas-numero-de-dispositivos-conectados-en-todo-el](https://es.statista.com/estadisticas/638100/internet-de-las-cosas-numero-de-dispositivos-conectados-en-todo-el-mundo--2020/)

[-mundo--2020/](https://es.statista.com/estadisticas/638100/internet-de-las-cosas-numero-de-dispositivos-conectados-en-todo-el-mundo--2020/)

D’Angelo, A. (1984). A brief introduction to quadtrees and their application. Descargado

de [http://people.scs.carleton.ca/~maheshwa/courses/5703COMP/16Fall/](http://people.scs.carleton.ca/~maheshwa/courses/5703COMP/16Fall/quadtrees-paper.pdf)

[quadtrees-paper.pdf](http://people.scs.carleton.ca/~maheshwa/courses/5703COMP/16Fall/quadtrees-paper.pdf)

[Guttman,](http://people.scs.carleton.ca/~maheshwa/courses/5703COMP/16Fall/quadtrees-paper.pdf)[ ](http://people.scs.carleton.ca/~maheshwa/courses/5703COMP/16Fall/quadtrees-paper.pdf)[A.](http://people.scs.carleton.ca/~maheshwa/courses/5703COMP/16Fall/quadtrees-paper.pdf)[ ](http://people.scs.carleton.ca/~maheshwa/courses/5703COMP/16Fall/quadtrees-paper.pdf)[(1984).](http://people.scs.carleton.ca/~maheshwa/courses/5703COMP/16Fall/quadtrees-paper.pdf)[ ](http://people.scs.carleton.ca/~maheshwa/courses/5703COMP/16Fall/quadtrees-paper.pdf)[R-trees.](http://people.scs.carleton.ca/~maheshwa/courses/5703COMP/16Fall/quadtrees-paper.pdf)[ ](http://people.scs.carleton.ca/~maheshwa/courses/5703COMP/16Fall/quadtrees-paper.pdf)[a](http://people.scs.carleton.ca/~maheshwa/courses/5703COMP/16Fall/quadtrees-paper.pdf)[ ](http://people.scs.carleton.ca/~maheshwa/courses/5703COMP/16Fall/quadtrees-paper.pdf)dynamic index structure for spatial searching.

Hadjieleftheriou, M., Manolopoulos, Y., Theodoridis, Y., y Tsotras, V. J. (2008). R-

trees – a dynamic index structure for spatial searching. En S. Shekhar y H. Xiong

(Eds.), Encyclopedia of gis (pp. 993–1002). Boston, MA: Springer US. Descar-

gado de <https://doi.org/10.1007/978-0-387-35973-1_1151>[ ](https://doi.org/10.1007/978-0-387-35973-1_1151)doi: 10.1007/

[978-0-387-35973-1_1151](https://doi.org/10.1007/978-0-387-35973-1_1151)

Laudon, K. C., Laudon, J. P., Alfono, V. R. E., y Fernando, S. S. P. (2016). Sistemas de

informacion gerencial. Pearson Educacion.

Martin, R. C. (2008). Clean code: A handbook of agile software craftsmanship (1.a ed.). USA:

Prentice Hall PTR.

Otair, M. (2013). Approximate k-nearest neighbour based spatial clustering using k-d tree.

CoRR, abs/1303.1951. Descargado de <http://arxiv.org/abs/1303.1951>

22


