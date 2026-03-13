#include <iostream>
#include <memory>


namespace My 
{
    template <typename T>
    class Matrix
    {
        private:
            size_t m_rows;
            size_t m_cols;
            std::unique_ptr<T[]> m_data;
        public:
            Matrix() : m_rows(0),m_cols(0),m_data(nullptr){}
            Matrix(size_t rows,size_t cols) : m_rows(rows),m_cols(cols),m_data(std::make_unique<T[]>(m_rows * m_cols)){}
            ~Matrix() = default;
            T& operator() (size_t row, size_t col)
            {
                return m_data[row*m_cols + col];
            }
            const T& operator() (size_t row, size_t col) const
            {
                return m_data[row*m_cols + col];
            }
            void Init()
            {
                for(size_t i = 0; i < m_rows; i++)
                {
                    for(size_t j = 0; j < m_cols; j++)
                    {
                        m_data[i*m_cols + j] = i + j;                
                    }
                }
            }
            void Print()
            {
                for(size_t i = 0; i < m_rows; i++)
                {
                    for(size_t j = 0; j < m_cols; j++)
                    {
                        std::cout << m_data[i*m_cols + j] << " ";        
                    }
                    std::cout << std::endl;
                }
            }
    };
}


int main()
{
    My::Matrix<int> matrix(4,5);
    matrix.Init();
    matrix.Print();
    std::cout << std::endl;
    matrix(3,0) = 47;
    matrix.Print();


    return 0;
}