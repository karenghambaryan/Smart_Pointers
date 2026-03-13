#include <iostream>
#include <memory>

namespace My
{
    template <typename T>
    class shared_ptr
    {
        private:
            T* m_ptr;
            size_t* m_count;
            void reset()
            {
                if(m_count) 
                {
                    --(*m_count);
                    if(*m_count == 0)
                    {
                        delete m_ptr;
                        delete m_count;
                    }
                }
                m_ptr = nullptr;
                m_count = nullptr;
            }
        public:
            shared_ptr() : m_ptr(nullptr),m_count(nullptr){}
            shared_ptr(T* ptr) : m_ptr(ptr)
            {
                m_count = new size_t(1);
            }
            ~shared_ptr()
            {
                reset();
            }
            shared_ptr(const shared_ptr& other) : m_ptr(other.m_ptr),m_count(other.m_count)
            {
                if(m_count)
                {
                    (*m_count)++;
                }
            }
            shared_ptr& operator=(const shared_ptr& other)
            {
                if(this != &other)
                {
                    reset();
                    m_ptr = other.m_ptr;
                    m_count = other.m_count;
                    if(m_count)
                    {
                        (*m_count)++;
                    }
                }
                return *this;
            }
            shared_ptr(shared_ptr&& other) : m_ptr(other.m_ptr),m_count(other.m_count)
            {
                other.m_ptr = nullptr;
                other.m_count = nullptr;
            }
            shared_ptr& operator=(shared_ptr&& other)
            {
                if(this != &other)
                {
                    reset();
                    m_ptr = other.m_ptr;
                    m_count = other.m_count;
                    other.m_ptr = nullptr;
                    other.m_count = nullptr;
                }
                return *this;
            }
            T* operator->()
            {
                return m_ptr;
            }
            const T* operator->() const
            {
                return m_ptr;
            }
            T& operator*()
            {
                return *m_ptr;
            }
            const T& operator*() const
            {
                return *m_ptr;
            }
            size_t use_count()
            {
                if(m_count)
                {
                    return *m_count;
                }
                else
                {
                    return 0;
                }
            }
    };



}
int main()
{
    My::shared_ptr<int> p(new int(7));
    My::shared_ptr<int> p1 = p;
    std::cout << p.use_count() << std::endl;   
    My::shared_ptr<int> p2 = std::move(p1);
    std::cout << p.use_count() << std::endl;   
    return 0;
}
