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
