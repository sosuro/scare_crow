        #include "BinarySearchTree.h"
        #include <iostream.h>
        /**
         * Implementa un árbol de búsqueda binario desequilibrado.
         * Tenga en cuenta que todas las "coincidencias" se basan en el <método.
         * /
        / **
         * Construye el árbol.
         */
        template <class Comparable>
        BinarySearchTree<Comparable>::BinarySearchTree( const Comparable & notFound ) :
          root( NULL ), ITEM_NOT_FOUND( notFound )
        {
        }

        template <class Comparable>
        BinarySearchTree<Comparable>::
        BinarySearchTree( const BinarySearchTree<Comparable> & rhs ) :
          root( NULL ), ITEM_NOT_FOUND( rhs.ITEM_NOT_FOUND )
        { 
            
        }

        template <class Comparable>
        BinarySearchTree<Comparable>::~BinarySearchTree( )
        {
            makeEmpty( );
        }

        /**
         * Insertar x en el árbol; los duplicados son ignorados
         */
        template <class Comparable>
        void BinarySearchTree<Comparable>::insert( const Comparable & x )
        {
            insert( x, root );
        }

        /**
         *Quita x del árbol. No se hace nada si no se encuentra x. 
         */
        template <class Comparable>
        void BinarySearchTree<Comparable>::remove( const Comparable & x )
        {
            remove( x, root );
        }

        /**
         * Encuentra el elemento más pequeño en el árbol.
         * Devuelve el elemento más pequeño o ITEM_NOT_FOUND si está vacío.
         */
        template <class Comparable>
        const Comparable & BinarySearchTree<Comparable>::findMin( ) const
        {
            return elementAt( findMin( root ) );
        }

        /**
         * Encuentra el elemento más grande en el árbol.
         * Devuelve el artículo más grande de ITEM_NOT_FOUND si está vacío.
         */
        template <class Comparable>
        const Comparable & BinarySearchTree<Comparable>::findMax( ) const
        {
            return elementAt( findMax( root ) );
        }

        /**
         * Encuentra el artículo x en el árbol.
         * Devuelve el elemento correspondiente o ITEM_NOT_FOUND si no se encuentra.
         */
        template <class Comparable>
        const Comparable & BinarySearchTree<Comparable>::
                                 find( const Comparable & x ) const
        {
            return elementAt( find( x, root ) );
        }

        /**
         * Hacer el árbol lógicamente vacío
         */
        template <class Comparable>
        void BinarySearchTree<Comparable>::makeEmpty( )
        {
            makeEmpty( root );
        }

        /**
         * Probar si el árbol está lógicamente vacío.
         * Devuelve verdadero si está vacío, falso de lo contrario.
         */
        template <class Comparable>
        bool BinarySearchTree<Comparable>::isEmpty( ) const
        {
            return root == NULL;
        }

        /**
         * Imprimir los contenidos del árbol en orden ordenado.
         */
        template <class Comparable>
        void BinarySearchTree<Comparable>::printTree( ) const
        {
            if( isEmpty( ) )
                cout << "Empty tree" << endl;
            else
                printTree( root );
        }

        /**
         * Deep copy.
         */
        template <class Comparable>
        const BinarySearchTree<Comparable> &
        BinarySearchTree<Comparable>::
        operator=( const BinarySearchTree<Comparable> & rhs )
        {
            if( this != &rhs )
            {
                makeEmpty( );
                root = clone( rhs.root );
            }
            return *this;
        }

        /**
         * Método interno para obtener el campo del elemento en el nodo t.
         * Devuelve el campo del elemento o ITEM_NOT_FOUND si t es NULL.
         */
        template <class Comparable>
        const Comparable & BinarySearchTree<Comparable>::
        elementAt( BinaryNode<Comparable> *t ) const
        {
            if( t == NULL )
                return ITEM_NOT_FOUND;
            else
                return t->element;
        }

        /**
         * Método interno para insertar en un subárbol.
         * x es el elemento a insertar.
         * t es el nodo que arraiga el árbol.
         * Establecer la nueva raíz.
         */
        template <class Comparable>
        void BinarySearchTree<Comparable>::
        insert( const Comparable & x, BinaryNode<Comparable> * & t ) const
        {
            if( t == NULL )
                t = new BinaryNode<Comparable>( x, NULL, NULL );
            else if( x < t->element )
                insert( x, t->left );
            else if( t->element < x )
                insert( x, t->right );
            else
                ;  // Duplicar; no hacer nada
        }

        /**
         * Método interno para eliminar de un subárbol.
         * x es el elemento a eliminar.
         * t es el nodo que arraiga el árbol.
         * Establecer la nueva raíz.
         */
        template <class Comparable>
        void BinarySearchTree<Comparable>::
        remove( const Comparable & x, BinaryNode<Comparable> * & t ) const
        {
            if( t == NULL )
                return;   // Objeto no encontrado; no hacer nada
            if( x < t->element )
                remove( x, t->left );
            else if( t->element < x )
                remove( x, t->right );
            else if( t->left != NULL && t->right != NULL ) // Dos niños
            {
                t->element = findMin( t->right )->element;
                remove( t->element, t->right );
            }
            else
            {
                BinaryNode<Comparable> *oldNode = t;
                t = ( t->left != NULL ) ? t->left : t->right;
                delete oldNode;
            }
        }

        /**
         * Método interno para encontrar el elemento más pequeño en un subárbol t.
         * Nodo de retorno que contiene el elemento más pequeño.
         */
        template <class Comparable>
        BinaryNode<Comparable> *
        BinarySearchTree<Comparable>::findMin( BinaryNode<Comparable> *t ) const
        {
            if( t == NULL )
                return NULL;
            if( t->left == NULL )
                return t;
            return findMin( t->left );
        }

        /**
         + Método interno para encontrar el elemento más grande en un subárbol t.
         * Nodo de retorno que contiene el artículo más grande.
         */
        template <class Comparable>
        BinaryNode<Comparable> *
        BinarySearchTree<Comparable>::findMax( BinaryNode<Comparable> *t ) const
        {
            if( t != NULL )
                while( t->right != NULL )
                    t = t->right;
            return t;
        }

        
        template <class Comparable>
        BinaryNode<Comparable> *
        BinarySearchTree<Comparable>::
        find( const Comparable & x, BinaryNode<Comparable> *t ) const
        {
            if( t == NULL )
                return NULL;
            else if( x < t->element )
                return find( x, t->left );
            else if( t->element < x )
                return find( x, t->right );
            else
                return t;    // Match
        }
/****** VERSIÓN NO RECURSIVA*************************
        template <class Comparable>
        BinaryNode<Comparable> *
        BinarySearchTree<Comparable>::
        find( const Comparable & x, BinaryNode<Comparable> *t ) const
        {
            while( t != NULL )
                if( x < t->element )
                    t = t->left;
                else if( t->element < x )
                    t = t->right;
                else
                    return t;    // Match

            return NULL;   // No match
        }
*****************************************************/

        /**
         * Internal method to make subtree empty.
         */
        template <class Comparable>
        void BinarySearchTree<Comparable>::
        makeEmpty( BinaryNode<Comparable> * & t ) const
        {
            if( t != NULL )
            {
                makeEmpty( t->left );
                makeEmpty( t->right );
                delete t;
            }
            t = NULL;
        }

        /**
         * Método interno para imprimir un subárbol arraigado en t en orden ordenado.
         */
        template <class Comparable>
        void BinarySearchTree<Comparable>::printTree( BinaryNode<Comparable> *t ) const
        {
            if( t != NULL )
            {
                printTree( t->left );
                cout << t->element << endl;
                printTree( t->right );
            }
        }

        /**
         * Método interno para clonar subárbol.
         */
        template <class Comparable>
        BinaryNode<Comparable> *
        BinarySearchTree<Comparable>::clone( BinaryNode<Comparable> * t ) const
        {
            if( t == NULL )
                return NULL;
            else
                return new BinaryNode<Comparable>( t->element, clone( t->left ), clone( t->right ) );
        }