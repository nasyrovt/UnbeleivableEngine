//
// Created by Nasyrov Takhir on 31/10/2023.
//

#ifndef CUSTOMENGINE_DELEGATE_H
#define CUSTOMENGINE_DELEGATE_H

class Delegate
{
public:
    Delegate()
            : object_ptr(0)
            , stub_ptr(0)
    {}

    template <class T, void (T::*TMethod)(int)>
    static Delegate FromMethod(T* object_ptr)
    {
        Delegate d;
        d.object_ptr = object_ptr;
        d.stub_ptr = &method_stub<T, TMethod>; // #1
        return d;
    }

    void operator()(int a1) const
    {
        return (*stub_ptr)(object_ptr, a1);
    }

private:
    typedef void (*stub_type)(void* object_ptr, int);

    void* object_ptr;
    stub_type stub_ptr;

    template <class T, void (T::*TMethod)(int)>
    static void method_stub(void* object_ptr, int a1)
    {
        T* p = static_cast<T*>(object_ptr);
        return (p->*TMethod)(a1); // #2
    }
};


#endif //CUSTOMENGINE_DELEGATE_H
