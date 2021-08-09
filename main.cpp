#include <iostream>
#include <string>
#include <list>
struct A
{
    std::string name;
    A(std::string n)
        : name(n)
    {}
};

struct Arr
{
    A * arr_ptr1;
    A * arr_ptr2;
    A * arr_ptr3;
    typedef A* A_ptr;;
    Arr()
        : arr_ptr1(NULL)
        , arr_ptr2(NULL)
        , arr_ptr3(NULL)
    {}
    ~Arr()
    {
        delete arr_ptr1;
        delete arr_ptr2;
    }
};

void allocate_mem(std::list<A*> & m)
{
    A * ptr = new A("1");
    m.push_front(ptr);
    ptr = new A("2");
    m.push_front(ptr);
    ptr = new A("3");
    //m.push_front(ptr);
}

A* allocate_mem2()
{
    return new A("1");
}

void allocate_mem3(Arr & a)
{
    a.arr_ptr1 = new A("1");
    a.arr_ptr2 = new A("2");
    a.arr_ptr3 = new A("3");
}
int testing()
{
    std::list<A*> list_a;
    allocate_mem(list_a);
    for(std::list<A*>::iterator it = list_a.begin(); it != list_a.end(); it++)
        std::cout << (*it)->name << std::endl;
    A* ptr = allocate_mem2();
    std::cout << ptr->name << std::endl;
    Arr a;
    allocate_mem3(a);
    return 0;
}
int main()
{
    testing();
    return 0;
}
