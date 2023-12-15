#ifndef LIST_HPP
#define LIST_HPP
#include "alloc.hpp"
#include <memory>


namespace my_stl{
    template<class T, class Alloc = std::allocator<T>>
    
    class List {
    private:
    struct Node {
        T data;
        Node* next;
    };
    Node* _head;
    int _size;

    void Copy(Node* head){
        if (head == nullptr)
            throw std::logic_error("NULL Head");
        
        Node* p = head; 
        bool f_first = true;
        Node* p2 = nullptr;
        Node* p3 = nullptr;

        _size = 0; 

        while (p != nullptr){
            p2 = Alloc_Node_traits::allocate(_m_alloc,1);
            p2->data = p->data;
            p2->next = nullptr;

            if (f_first){
                _head = p2;
                p3 = p2;
                f_first = false;
            }
            else{
                p3->next = p2;
                p3 = p3->next;
            }
            _size++;
            p = p->next;
        }
    }

        protected:

        using Alloc_traits = std::allocator_traits<Alloc>;
        using Alloc_Node = typename Alloc_traits::template rebind_alloc<Node>;
        using Alloc_Node_traits = std::allocator_traits<Alloc_Node>;


        Alloc_Node _m_alloc;


    public:

        class Iterator{
            friend List;
            Node* p;
        public:

            Iterator(const Iterator& it) : p(it.p) {}
            
            Iterator(): p(nullptr){};
            
            Iterator(Node* it): p(it){};
                        
            ~Iterator(){p = nullptr;};

            
            bool operator!=(const Iterator &it){ return p != it.p;};
            
            bool operator==(const Iterator &it){ return p == it.p;};
            
            T& operator*(){ return p->data;};

            T* operator->(){ return &p->data;};
            
            Iterator& operator++(){
                p = p->next;
                return *this;
            };

            Iterator& operator++(int){
                p = p->next;
                return *this;
            };
        };

        class ConstIterator{
            friend List;
            Node* p;
        public:

            ConstIterator(const ConstIterator& it) : p(it.p) {}

            ConstIterator(): p(nullptr){};
            
            ConstIterator(Node* it): p(it){};
                        
            ~ConstIterator(){p = nullptr;};

            
            bool operator!=(const ConstIterator &it) const{ return p != it.p;};
            
            bool operator==(const ConstIterator &it) const{ return p == it.p;};
            
            T& operator*() const{ return p->data;};

            T* operator->() const{ return &p->data;};
            
            ConstIterator& operator++(){
                p = p->next;
                return *this;
            };

            ConstIterator& operator++(int){
                p = p->next;
                return *this;
            };
        };
    
        List(): _m_alloc(){
            _head = Alloc_Node_traits::allocate(_m_alloc,1);
            _head = nullptr;
            _size = 0;
            
        };

        List(const List<T,Alloc>& other): _m_alloc(){
            Copy(other._head);
        };

        List(List<T,Alloc>&& other): _m_alloc(){
            Copy(other._head);
            other.clear();
        };

        ~List() = default;


        List<T,Alloc>& operator=(const List<T,Alloc> &other);

        Iterator begin();

        ConstIterator cbegin() const;

        Iterator end();

        ConstIterator cend() const;

        void Add(T item, int position); 
        void Remove(int index); 

        T Head();

        void Show();

        void clear();

        bool IsEmpty(){ return _size == 0;};

        int Size() const { return _size;};
    };
    
    template<class T, class Alloc>
    List<T,Alloc>& List<T,Alloc>::operator=(const List<T,Alloc>& other){
        if(this != &other){
            clear(); // очищаем текущий список
            Node* current = other._head; // устанавливаем указатель на начало другого списка
            while (current != nullptr) {
                push_back(current->data); // добавляем элементы в конец текущего списка
            current = current->next; // переходим к следующему элементу в другом списке
            }
        }
        return *this;
    }

    template<class T, class Alloc>
    void List<T,Alloc>::clear() {
        Node* current = _head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        _head = nullptr;
    }

    template<class T, class Alloc>
    typename List<T,Alloc>::Iterator List<T,Alloc>::begin(){
        return Iterator(_head);
    }

    template<class T, class Alloc>
    typename List<T,Alloc>::ConstIterator List<T,Alloc>::cbegin() const{
        return ConstIterator(_head);
    }

    template<class T, class Alloc>
    typename List<T,Alloc>::Iterator List<T,Alloc>::end(){
        Node* pt = nullptr;
        return Iterator(pt);
    }

    template<class T, class Alloc>
    typename List<T,Alloc>::ConstIterator List<T,Alloc>::cend() const{
        Node* pt = nullptr;
        return ConstIterator(pt);
    }
    
    template<class T, class Alloc>
    void List<T, Alloc>::Add(T item, int position) {
        if (position < 0 || position > _size) {
            throw std::out_of_range("Invalid position");
        }
        Node* new_node = Alloc_Node_traits::allocate(_m_alloc, 1); // выделяем память под новый узел
        new_node->data = item; // устанавливаем данные нового узла
        if (position == 0) {
            new_node->next = _head;
            _head = new_node; // обновляем голову списка
        }
        else if(position == _size){
            Node* current = _head;
            while (current->next != nullptr) {
                current = current->next; 
            }
            current->next = new_node; // Добавляем новый узел в конец списка
            new_node->next = nullptr; // Устанавливаем указатель нового узла на nullptr, так как он теперь последн
        }
        else {
            Node* current = _head;
            for (int i = 0; i < position - 1; i++) {
                current = current->next; // дойдем до узла, предшествующего позиции вставки
            }
            new_node->next = current->next; // перезаписываем указатель нового узла, чтобы он указывал на следующий узел
            current->next = new_node; // перезаписываем указатель предыдущего узла, чтобы он указывал на новый узел
        }
        _size++; // увеличиваем размер списка
    }

    
    template<class T, class Alloc>
    void List<T,Alloc>::Remove(int index){
        if (_size == 0) {
            throw std::logic_error("Empty List");
        } 
        else if (index < 0 || index >= _size) {
            throw std::out_of_range("Index out of range");
        }
        else if (index == 0) {
            Node* temp = _head;
            _head = _head->next;
            Alloc_Node_traits::deallocate(_m_alloc, temp, 1);
        }
        else {
            Node* current = _head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            Node* temp = current->next;
            current->next = current->next->next;
            Alloc_Node_traits::deallocate(_m_alloc, temp, 1);
        }
        _size--;
    }


    template<class T, class Alloc>
    T List<T,Alloc>::Head(){
        if (_size == 0)
            return 0;

        return _head->data;
    }

    template<class T, class Alloc>
    void List<T,Alloc>::Show(){
        Node* p = _head;
        std::cout << "List => ";
        while (p != nullptr){
            std::cout << p->data << "  ";
            p = p->next;
        }
        std::cout << std::endl;
    }

};

#endif 
