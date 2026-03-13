#include <iostream>
#include <memory>

namespace My
{
    template <typename T>
    class Unique_ptr
    {
        private:
            T* my_ptr;
        public:
            Unique_ptr() : my_ptr(nullptr) {}
            ~Unique_ptr()
            {
                delete my_ptr;
            }
            explicit Unique_ptr(T* ptr) : my_ptr(ptr){}
            Unique_ptr(const Unique_ptr& other) = delete;
            Unique_ptr& operator=(const Unique_ptr& other) = delete;
            Unique_ptr(Unique_ptr&& other) : my_ptr(other.my_ptr) 
            {
                other.my_ptr = nullptr;
            }
            Unique_ptr& operator=(Unique_ptr&& other) 
            {
                if(this != &other)
                {
                    delete my_ptr;
                    my_ptr = other.my_ptr;
                    other.my_ptr = nullptr;
                }
                return *this;
            }
            T* operator->()
            {
                return my_ptr;
            }
            T& operator*()
            {
                return *my_ptr;
            }
            const T* operator->() const
            {
                return my_ptr;
            }
            const T& operator*() const
            {
                return *my_ptr;
            }
    };
}

int main()
{
    My::Unique_ptr<int> ptr(new int(150));
    std::cout << "*ptr= " << *ptr << std::endl;
    std::cout << "ptr= " << ptr.operator->() << std::endl;
    My::Unique_ptr<int> ptr_2;
    ptr_2 = std::move(ptr);
    std::cout << "*ptr_2= " << *ptr_2 << std::endl;
    std::cout << "ptr_2= " << ptr_2.operator->() << std::endl;
    return 0;
}
