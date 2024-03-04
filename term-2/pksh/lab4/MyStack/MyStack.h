#ifndef MyStack_h           // защита от повторной компиляции
#define MyStack_h           // модуль подключен


// Шаблонный класс ListNode (узел односвязного списка)
template<class INF, class FRIEND>
class ListNode              // узел списка
{
private:
    INF d;                  // информационная часть узла
    ListNode* next;         // указатель на следующий узел списка
    ListNode() {
        next = nullptr;
        d = INF();
    }
    friend FRIEND;
};


// Шаблонный класс MyStack на основе односвязного списка.
template<class INF>
class MyStack {
    typedef class ListNode<INF, MyStack<INF>> Node;
    Node* top;
public:
    MyStack() {
        top = nullptr;
    }
    ~MyStack() {          // освободить динамическую память
        if (top == nullptr)
            return;

        Node* nextNode;
        while (top->next != nullptr) {
            nextNode = top->next;
            delete top;
            top = nextNode;
        }
        delete top;
    }
    bool empty() {
        if (top == nullptr)
            return true;
        return false;
    }
    bool push(INF n) {        // добавить узел в вершину стека
        Node* newNode = new Node;
        newNode->d = n;
        newNode->next = top;
        top = newNode;
        return true;
    }
    bool pop() {          // удалить узел из вершины стека
        if (top == nullptr)
            return false;
        Node* nextNode = top->next;
        delete top;
        top = nextNode;
        return true;
    }

    INF top_inf() {      // считать информацию из вершины стека
        return top->d;
    }
};

#endif


