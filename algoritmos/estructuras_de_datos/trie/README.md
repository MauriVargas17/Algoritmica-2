# Trie

## Que es?

Un trie es una estructura de datos de tipo árbol que permite la recuperación de información 
en un tiempo de complejidad mucho menor que realizar una busqueda estandar en una lista. 
La información almacenada en un trie es un conjunto de claves, donde una clave es una 
secuencia de símbolos pertenecientes a un alfabeto. Las claves son almacenadas en las hojas del árbol 
y los nodos internos son pasarelas para guiar la búsqueda. El árbol se estructura de forma que 
cada letra de la clave se sitúa en un nodo de forma que los hijos de un nodo representan 
las distintas posibilidades de símbolos diferentes que pueden continuar al símbolo representado por el nodo padre.
## Como funciona?

Creamos una estructura llamada `nodo`, a la cual le daremos algunos atributos, como ser el caracter que contiene, si es una palabra
y cuantos nodos hijos tiene, es decir, a cuantas otras palabras se deriva este nodo:
```
struct node {
    char currentCharacter;       
    bool isWord;                
    struct node *children[27];  
}*trie;
```
Los metodos que acompañan al arbol son `init`, el cual nos sirve para agregar el nodo inicial y comenzar la creación de otros nodos;
`insertWord`, en el cual tomamos un string e iteramos sobre el, revisando si sus caracteres ya forman parte del árbol y agregando los que todavía no pertenecen, hasta terminar el proceso y modificar el último nodo indicando que es fin de palabra; `searchWord`, el cual nos ayuda a determinar si en el árbol existe un string que le pasemos o no. Por último, el método `deleteWord` busca una palabra y le quita la calidad de ser fin de palabra.

# Segment Tree

## Que es?

En ciencias de la computación, un árbol de segmento (en inglés: Segment tree) es una estructura de datos en forma de árbol para guardar intervalos o segmentos. Permite consultar cuál de los segmentos guardados contiene un punto. Un árbol de segmento para un conjunto I de n intervalos usa O(n log n) de memoria de almacenamiento y puede construirse en un tiempo O(n log n). Los árboles de segmento soportan búsqueda para todos los intervalos que contienen un punto de consulta en O(log n + k), k el número de intervalos o segmentos recuperados.
## Como funciona?

Un árbol de segmento desde el conjunto de segmentos I, puede ser construido como sigue. Creamos una estructura `node` que comunmente guarda resultados como el maximo, minimo y/o la suma de sus nodos hijos:
```
struct node {
    int maximo;
    int minimo;
    int sum = 0;
}segmentTree[1000000];
```
Ademas, crearemos una variable de tipo `int[]` para poder almacenar los datos que nos pase el usuario. Esos datos los convertiremos en nodos en nuestra propia estructura `segmentTree[]`. Contamos con algunos metodos principales, como ser por ejemplo el metodo `init()` que inicia el segment tree, o el `query()` que responde a una consulta de un nodo especifico o en su defecto del conjunto de nodos que se encuentren abarcando cierto intervalo. Por ultimo tenemos al metodo `update()` el cual es muy importante porque nos permite realizar una actualización de la información contenida en una casilla del arreglo original, modificando los resultados de los nodos que correspondan, ahorrando el procesos de recalcular todo nuevamente.

