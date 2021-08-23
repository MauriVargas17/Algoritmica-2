### Este README.md contiene todas las descripciones de las estructuras

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

# BIT

## Que es?

El BIT es una estructura que busca resolver problemas similares a los que el Segment Tree y es tambien conocido como Fenwick Tree. Se basa en el uso de el bit menos significativo de cada numero para poder armar el conocido arbol de padres. Para calcular el bit menos significativo utilizamos una operacion muy importante: `lsb(x) = (x & -x)` en la cual aplicamos la operacion AND con el numero x en su forma binaria y el inverso de la forma binaria de x mas 1. 
## Como funciona?

El codigo de la estructura BIT es mas facil que la del Segment Tree, debido a que no usamos una clase extra ni muchas lineas de codigo. Se basa en los metodos `constructBit()` el cual primero inicializa al arreglo `BITtree[]` colocando todos los valores en 0. La idea es que la casilla 0 en el BITtree es el padre de todos, y por tanto las casillas se recorreran un espacio para ser tomadas en cuenta. Luego recorremos todo el arreglo que nos entregan inicialmente y aplicamos la funcion `updateBIT()` la cual recorre desde la casilla que le mandemos + 1, actualizando a todos sus padres:
```
void updateBIT(int BITree[], int n, int index, int val){
    index = index + 1;
    while (index <= n){
    BITree[index] += val;
    index += index & (-index);
    }
}
```
Mas tarde podremos actualizar las casillas con el mismo metodo. Ya que no implementamos una clase especifica, solamente podemos guardar en cada casilla un resultado; puede ser suma o multiplicacion. 

# Union Find

## Que es?

Union Find es una manera de como su mismo nombre lo dice, unificar grupos de nodos y tambien de encontrar a sus padres para poder realizar la unificacion de la manera mas adecuada. La idea consiste en recibir un arreglo, donde inicialmente todos los nodos son padres de si mismos y pueden ser unidos con otros, obteniendo padres nuevos, y de esta forma facilitar la busqueda DFS que de otra forma tendria que recorrer muchos espacios, y al unificar, hacemos que unicamente se recorran unos pocos niveles desde el padre o raiz.
## Como funciona?

En la implementacion de codigo, contamos principalmente con 3 metodos que nos seran utiles para el funcionamiento. El primero es `makeSet()` el cual tomara la informacion de todos los valores en un arreglo comun para asignarles sus respectivos padres (ellos mismos seran sus padres inicialmente). Luego tenemos al metodo `find()` que se encarga de buscar recursivamente al nodo raiz de un determinado nodo. Finalmente, el metodo `union()` convierte al padre de b en el nuevo padre del padre de a.
