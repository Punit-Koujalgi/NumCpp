#ifndef ARRAY2D
#define ARRAY2D

#include<cassert>
#include<iostream>
#include<initializer_list>
#include "reference_array1D.cpp"


template<class vector>
class Array2DIterator
{
    public:
        using ValueType=typename vector::ValueType;
        using PointerType=ValueType*;
        using ReferenceType=ValueType&;

        Array2DIterator(Array1D<ValueType>* arr): m_arr{arr},m_iter(arr->begin()) {}
    private:
        Array1D<ValueType>* m_arr;
        Array1DIterator<Array1D<ValueType>> m_iter;
    public:
        Array2DIterator& operator++()
        {
            if(m_iter != --(m_arr->end()))
                ++m_iter;
            else 
            {
                m_arr++;
                m_iter=m_arr->begin();
            }
            return *this;
        }

        Array2DIterator operator++(int)
        {
            Array2DIterator iterator=*this;
            ++(*this);
            return iterator;
        }

        //ReferenceType operator[](int index) { return *(m_ptr + index);}
        PointerType operator->() { return m_iter; }
        ReferenceType operator*() { return *m_iter; }

        bool operator==(const Array2DIterator& other) const { return m_arr == other.m_arr;}
        bool operator!=(const Array2DIterator& other) const { return !(*this == other); }

};

template<typename T>
class Array2D
{
    public:
        using ValueType=T;
        using Iterator=Array2DIterator<Array2D<T>>;
    private:
        int m_rows{};
        int m_cols{};
        Array1D<T>* m_data{};
        static void broadcastArrays(Array2D<T> &arr1,Array2D<T> &arr2)
        {
            if(arr1.m_rows != arr2.m_rows)
            {
                assert(arr1.m_rows==1 || arr2.m_rows==1);
                if(arr1.m_rows==1)
                {
                    arr1.resize(arr2.m_rows,arr1.m_cols);
                    for(int i=1;i<arr1.m_rows;i++)
                        arr1[i]=arr1[0];
                }
                else
                {
                    arr2.resize(arr1.m_rows,arr2.m_cols);
                    for(int i=1;i<arr2.m_rows;i++)
                        arr2[i]=arr2[0];
                }
            }
            if(arr1.m_cols != arr2.m_cols)
            {
                assert(arr1.m_cols==1 || arr2.m_cols==1);
                if(arr1.m_cols == 1)
                {
                    arr1.m_cols=arr2.m_cols;
                    for(int i=0;i<arr1.m_rows;i++)
                    {
                        arr1[i].resize(arr2.m_cols);
                        for(int j=1;j<arr1.m_cols;j++)
                            arr1[i][j]=arr1[i][0];
                    }
                }
                else //resize arr2
                {
                    arr2.m_cols=arr1.m_cols;
                    for(int i=0;i<arr2.m_rows;i++)
                    {
                        arr2[i].resize(arr1.m_cols);
                        for(int j=1;j<arr2.m_cols;j++)
                            arr2[i][j]=arr2[i][0];
                    }
                }
            }
        }
    public:
        Array2D()=default;

        Array2D(int rows,int cols): m_rows(rows),m_cols(cols)
        {
            assert(rows>=0 && cols>=0);
            m_data=new Array1D<T>[rows]{};
            for(int i=0;i<rows;i++)
                m_data[i]=Array1D<T>(cols);
        }

        Array2D(std::initializer_list<std::initializer_list<T>> list): 
                            m_rows{static_cast<int>(list.size())},m_cols{0}
        {
            for(auto &x : list)
                if(static_cast<int>(x.size()) > m_cols)
                    m_cols=static_cast<int>(x.size());
            m_data=new Array1D<T>[m_rows]{};
            auto it=list.begin();
            for(int i=0;i<m_rows;i++)
            {   m_data[i]=Array1D<T>(m_cols);//try resize
                int j=0;
                for(auto &x : *it)
                {
                    m_data[i][j]=x;
                    j++;
                }
                ++it;
            }
        }

        Array2D(const Array2D<T> &array):Array2D<T>(array.m_rows,array.m_cols)
        {
            for(int i{0};i < m_rows ; i++)
                m_data[i]=array[i];
        }
        Array2D& operator=(const Array2D &array)
        {
            erase();
            if(array.m_rows > 0)
            {
                m_data=new Array1D<T>[array.m_rows]{};
                m_rows=array.m_rows;m_cols=array.m_cols;
                for(int count{0};count<m_rows;count++)
                    m_data[count]=array.m_data[count];
            }
            return *this;
        }

        void erase()
        {
            delete[] m_data;
            m_rows=0;
            m_cols=0;
            m_data=nullptr;    
        }

        void reallocate(int rows,int cols)
        {
            erase();
            if(rows <= 0 || cols<=0) return;
            m_data=new Array1D<T>[rows]{};
            for(int count{0};count<rows;count++)
                m_data[count]=Array1D<T>(cols);
        }

        void resize(int rows, int cols)
        {
            if(rows <= 0 || cols <= 0) 
            {
                erase();
                return;
            }
            if(m_rows != rows)
            {
                //resize rows
                Array1D<T>* data{new Array1D<T>[rows]{}};
                if(m_rows > 0)
                {
                    int toCopy{(rows < m_rows?rows:m_rows)};
                    for(int i=0;i<toCopy;i++)
                        data[i]=m_data[i];
                }
                delete[] m_data;
                m_rows=rows;
                m_data=data;
            }
            if(m_cols != cols)
            {
                //resize cols
                for(int i=0;i<rows;i++)
                    m_data[i].resize(cols); //resize of Array1D
                m_cols=cols;
            }
        }

        ~Array2D(){delete[] m_data;}

        Iterator begin(){  return Iterator(m_data); }
        Iterator end()  { return Iterator(m_data + m_rows); }
        int getRows() const { return m_rows; }
        int getCols() const { return m_cols; }

        Array1D<T>& operator[](int index)
        {
            assert(index>=0 && index < m_rows);
            return m_data[index];
        }

        Array1D<T> operator[](int index) const
        {
            assert(index>=0 && index < m_rows);
            return m_data[index];
        }

        Array2D<T> operator+(const Array2D<T> &rhs) const
        {
            Array2D<T> arr1(*this);
            Array2D<T> arr2(rhs);
            broadcastArrays(arr1,arr2);
            for(int i=0;i<arr1.m_rows;i++)
                arr1[i]=arr1[i]+arr2[i];
            return arr1;
        }

        Array2D<T> operator+(const T& rhs) const
        {
            Array2D<T> arr(1,1);
            arr[0][0]=rhs;
            return *this+arr;
        }

        Array2D<T> operator+(const Array1D<T>& rhs) const
        {
            Array2D<T> arr(1,rhs.getLength());
            arr[0]=rhs;
            return *this+arr;
        }

        Array2D<T> operator*(const Array2D<T> &rhs) const
        {
            Array2D<T> arr1(*this);
            Array2D<T> arr2(rhs);
            broadcastArrays(arr1,arr2);
            for(int i=0;i<arr1.m_rows;i++)
                arr1[i]=arr1[i] * arr2[i];
            return arr1;
        }

        Array2D<T> operator*(const T& rhs) const
        {
            Array2D<T> arr(1,1);
            arr[0][0]=rhs;
            return (*this) * arr;
        }

        Array2D<T> operator*(const Array1D<T>& rhs) const
        {
            Array2D<T> arr(1,rhs.getLength());
            arr[0]=rhs;
            return (*this) * arr;
        }


        T sum() const
        {
            Array1D<T> ret(sum(1));
            return ret.sum();   
        }

        Array1D<T> sum(int axis) const
        {
            if(axis == 0)     // collapse rows
            {
                Array1D<T> ret(m_cols);
                for(int col=0;col<m_cols;col++)
                {
                    T total{};
                    for(int row=0;row<m_rows;row++)
                        total+=m_data[row][col];
                    ret[col]=total;
                }
                return ret;
            }
            else if(axis == 1)//collapse columns 
            {
                Array1D<T> ret(m_rows);
                for(int row=0;row<m_rows;row++)
                {
                    T total{};
                    for(int col=0;col<m_cols;col++)
                        total+=m_data[row][col];
                    ret[row]=total;                
                }
                return ret;
            }
        }

        T min() const
        {
            Array1D<T> ret(min(1));
            return ret.min();   
        }

        T max() const
        {
            Array1D<T> ret(max(1));
            return ret.max();   
        }

        Array1D<T> min(int axis) const
        {
            if(axis == 0)     // collapse rows
            {
                Array1D<T> ret(m_cols);
                for(int col=0;col<m_cols;col++)
                {
                    T min(m_data[0][col]);
                    for(int row=1;row<m_rows;row++)
                        if(m_data[row][col] < min)
                            min = m_data[row][col];
                    ret[col]=min;
                }
                return ret;
            }
            else if(axis == 1)//collapse columns 
            {
                Array1D<T> ret(m_rows);
                for(int row=0;row<m_rows;row++)
                {
                    T min(m_data[row][0]);
                    for(int col=1;col<m_cols;col++)
                        if(m_data[row][col] < min)
                            min = m_data[row][col];
                    ret[row]=min;                
                }
                return ret;
            }
        }

        Array1D<T> max(int axis) const
        {
            if(axis == 0)     // collapse rows
            {
                Array1D<T> ret(m_cols);
                for(int col=0;col<m_cols;col++)
                {
                    T max(m_data[0][col]);
                    for(int row=1;row<m_rows;row++)
                        if(m_data[row][col] > max)
                            max = m_data[row][col];
                    ret[col]=max;
                }
                return ret;
            }
            else if(axis == 1)//collapse columns 
            {
                Array1D<T> ret(m_rows);
                for(int row=0;row<m_rows;row++)
                {
                    T max(m_data[row][0]);
                    for(int col=1;col<m_cols;col++)
                        if(m_data[row][col] > max)
                            max = m_data[row][col];
                    ret[row]=max;                
                }
                return ret;
            }
        }

        Array2D<T> dot(const Array2D& arr)
        {
            assert( m_cols == arr.m_rows);
            
            Array2D<T> ret(m_rows,arr.m_cols);
            for(int i=0;i<m_rows;i++)
            {
                for(int j=0;j<arr.m_cols;j++)
                {
                    int total=0;
                    for(int k=0;k<m_cols;k++)
                        total+=m_data[i][k]*arr.m_data[k][j];
                    ret[i][j]=total;
                }
            }
            return ret;
        }

        Array2D<std::reference_wrapper<T>> operator()(int rowStart,int rowEnd,int colStart,int colEnd,int rowStep=1,int colStep=1)
        {
            assert(rowStart >= 0 && rowEnd <= m_rows);
            assert(colStart >=0 && colEnd <= m_cols);

            Array2D<std::reference_wrapper<T>> ret;
            for(int row=rowStart;row < rowEnd; row += rowStep)
            {
                Array1D<std::reference_wrapper<T>> arr;// = new Array1D<std::reference_wrapper<T>>();
                for(int col=colStart;col < colEnd; col+= colStep)
                    arr.add(m_data[row][col]);
                ret.add(arr);
            }
            return ret;
        }

        template<class S>
        friend std::ostream& operator<<(std::ostream &out,const Array2D<S>& arr);
};

template<class S>
std::ostream& operator<<(std::ostream& out,const Array2D<S> &arr)
{
    std::cout<<"[";
    if(arr.getRows() == 1) 
    {
        std::cout<<arr[0]<<"]";
        return out;
    }
    if(arr.getRows() > 0) std::cout<<arr[0]<<",\n";
    for(int i=1;i<arr.getRows()-1;i++)
    {
        std::cout<<" "<<arr[i]<<",\n";
    }
    if(arr.getRows() > 0 && arr.getRows()!=1) std::cout<<" "<<arr[arr.getRows() - 1];
    std::cout<<"]";
    return out;
}

#endif