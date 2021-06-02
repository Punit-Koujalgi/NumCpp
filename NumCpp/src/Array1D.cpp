#ifndef ARRAY1D
#define ARRAY1D


#include<cassert>
#include<iostream>
#include<initializer_list>
#include<functional>

template<typename array>
class Array1DIterator{
    public:
        using ValueType= typename array::ValueType;
        using PointerType=ValueType*;
        using ReferenceType=ValueType&;

        Array1DIterator(PointerType ptr): m_ptr{ptr} {}
    private:
        PointerType m_ptr;
    public:
        Array1DIterator& operator++()
        { 
            m_ptr++;
            return *this;
        }

        Array1DIterator operator++(int)
        {
            Array1DIterator iterator=*this;
            ++(*this);
            return iterator;
        }

        Array1DIterator& operator--()
        { 
            m_ptr--;
            return *this;
        }

        Array1DIterator operator--(int)
        {
            Array1DIterator iterator=*this;
            --(*this);
            return iterator;
        }

        ReferenceType operator[](int index) { return *(m_ptr + index);}
        PointerType operator->() { return m_ptr; }
        ReferenceType operator*() { return *m_ptr; }

        bool operator==(const Array1DIterator& other) const { return m_ptr == other.m_ptr;}
        bool operator!=(const Array1DIterator& other) const { return !(*this == other); }
};

template<typename T> class Array1D;
// template<typename S>
// bool operator==(const Array1D<S> &a,const Array1D<S> &b);
// template<class S>
// Array1D<bool> operator==(Array1D<S> &arr,S comp);


template<typename T>
class Array1D
{
    public:
        using ValueType=T;
        using Iterator=Array1DIterator<Array1D<T>>;
    private:
        int m_length{};
        T* m_data{};
    public:
        Array1D()=default;

        Array1D(int length):m_length{length}
        {
            assert(length>=0);
            if(length>0)
                m_data = new T[length]{};
        }

        Array1D(std::initializer_list<T> list): Array1D(static_cast<int>(list.size()))
        {
            int count{0};
            for(auto element : list)
            {
                m_data[count] = element;
                ++count;
            }
        }

        Array1D(const Array1D<T> &array): Array1D<T>(array.m_length)
        {
            for(int i{0};i<m_length;i++)
                m_data[i]=array.m_data[i];
        }

        Array1D& operator=(std::initializer_list<T> list)
        {
            erase();
            int newLength=static_cast<int>(list.size());
            if(newLength > 0)
            {
                m_data=new T[newLength];
                m_length=newLength;
                int count{0};
                for(auto element : list)
                {
                    m_data[count]=element;
                    ++count;
                }
            }
            return *this;
        }  

        
        Array1D& operator=(const Array1D &array)
        {
            erase();
            if(array.m_length > 0)
            {
                m_data=new T[array.m_length]{};
                m_length=array.m_length;
                for(int count{0};count < array.m_length; ++count)
                    m_data[count]=array.m_data[count];
            }
            return *this;
        }      

        void erase()
        {
            delete[] m_data;
            m_data = nullptr;
            m_length = 0;
        }

        ~Array1D()
        {
            delete[] m_data;
        }

        T& operator[](int index)
        {
            assert(index >=0 && index < m_length);
            return m_data[index];
        }

        const T& operator[](int index) const 
        {
            assert(index >=0 && index < m_length);
            return m_data[index];
        }

        Array1D<T> operator[](const Array1D<bool> &arr)
        {
            assert(m_length == arr.getLength());
            Array1D<T> ret;
            for(int i=0;i<m_length;i++)
            {
                if(arr[i] == true)
                {
                    ret.resize(ret.m_length+1);
                    ret[ret.m_length-1]=m_data[i];
                }
            }
            return ret;
        } 

        int getLength() const {return m_length;}
        
        void reallocate(int length)
        {
            erase();
            if(length <= 0)
                return;
            
            m_data = new T[length]{};
            m_length = length;
        }

        void resize(int length)
        {
            if(m_length == length)
                return;
            
            if(length <= 0)
            {
                erase();
                return;
            }

            T* data{new T[length]{}};
            if(m_length > 0)
            {
                int elementsToCopy{(length > m_length) ? m_length : length};
                for(int i{0};i < elementsToCopy ; i++)
                    data[i]=m_data[i];
            }
            delete[] m_data;
            m_data = data;
            m_length = length;
        }

        void insertBefore(T value,int index)
        {
            assert(index >= 0 && index <= m_length);
            T* data{new T[m_length+1]};
            for(int i{0} ; i < index; i++)
                data[i] = m_data[i];
            data[index]=value;
            for(int i{index} ; i<m_length ; i++)
                data[i+1]=m_data[i];

            delete[] m_data;
            m_data=data;
            ++m_length;
        }

        void remove(int index)
        {
            assert(index >=0 && index < m_length);
            if(m_length == 1)
            {
                erase();
                return;
            }

            T* data{new T[m_length-1]};
            for(int i{0} ; i < index ; i++)
                data[i]=m_data[i];
            for(int i{index+1} ; i < m_length ; i++)
                data[i-1]=m_data[i];

            delete[] m_data;
            m_data=data;
            --m_length;
        }

        const Iterator begin() const{  return Iterator(m_data); }
        Iterator begin() {  return Iterator(m_data); }

        const Iterator end() const {  return Iterator(m_data + m_length); }
        Iterator end()  {  return Iterator(m_data + m_length); }

        void insertAtBeginning(T value) { insertBefore(value, 0); }
        void insertAtEnd(T value) { insertBefore(value, m_length); }

        T sum() const 
        {
            T ret;
            for(auto &x: (*this))
                ret = ret + x;
            return ret;
        }

        T min() const 
        {
            T ret(m_data[0]);
            for(int i=1;i<m_length;i++)
                if( m_data[i] < ret)
                    ret = m_data[i];
            return ret;
        } 

        T max() const 
        {
            T ret(m_data[0]);
            for(int i=1;i<m_length;i++)
                if( m_data[i] > ret)
                    ret = m_data[i];
            return ret;
        } 

        void sort() const
        {
            for(int i=0;i<m_length-1;i++)
            {
                int min=i,j;
                for(j=i+1;j<m_length;j++)
                {
                    if(m_data[j] < m_data[min])
                        min = j;
                }
                if(i != min)
                {
                    T temp=m_data[i];
                    m_data[i]=m_data[min];
                    m_data[min]=temp;
                }
            }
        }

        Array1D operator+(const Array1D& rhs) const
        {
            assert(m_length==rhs.m_length);
            Array1D<T> temp(m_length);
            for(int i=0;i<m_length;i++)
                temp[i]=m_data[i]+rhs.m_data[i];
            return temp;
        }

        Array1D operator-(const Array1D& rhs) const
        {
            assert(m_length==rhs.m_length);
            Array1D<T> temp(m_length);
            for(int i=0;i<m_length;i++)
                temp[i]=m_data[i]-rhs.m_data[i];
            return temp;
        }
        Array1D operator*(const Array1D& rhs) const
        {
            assert(m_length==rhs.m_length);
            Array1D<T> temp(m_length);
            for(int i=0;i<m_length;i++)
                temp[i]=m_data[i]*rhs.m_data[i];
            return temp;
        }
        Array1D operator/(const Array1D& rhs) const
        {
            assert(m_length==rhs.m_length);
            Array1D<T> temp(m_length);
            for(int i=0;i<m_length;i++)
                temp[i]=m_data[i]/rhs.m_data[i];
            return temp;
        }

        Array1D operator+(T rhs) const
        {
            Array1D<T> temp(m_length);
            for(int i=0;i<m_length;i++)
                temp[i]=m_data[i]+rhs;
            return temp;
        }
        Array1D operator-(T rhs) const
        {
            Array1D<T> temp(m_length);
            for(int i=0;i<m_length;i++)
                temp[i]=m_data[i]-rhs;
            return temp;
        }
        Array1D operator*(T rhs) const
        {
            Array1D<T> temp(m_length);
            for(int i=0;i<m_length;i++)
                temp[i]=m_data[i]*rhs;
            return temp;
        }
        Array1D operator/(T rhs) const
        {
            Array1D<T> temp(m_length);
            for(int i=0;i<m_length;i++)
                temp[i]=m_data[i]/rhs;
            return temp;
        }
        
        Array1D<bool> operator==(T comp)
        {
            Array1D<bool> ret(m_length);
            for(int i=0;i<m_length;i++)
            {
                if(m_data[i] == comp)
                    ret[i]=true;
                else
                    ret[i]=false;
            }
            return ret;
        }

        bool operator==(const Array1D<T> &b)
        {
            if(m_length == b.m_length)
            {
                for(int i=0;i< m_length;i++)
                {
                    if(m_data[i] != b.m_data[i])
                        return false;
                }
                return true;
            }
            return false;
        }


        T& operator()(int index)
        {
            assert(index>=0 && index < m_length);
            return m_data[index];
        }

        Array1D<std::reference_wrapper<T>> operator()(int start,int end, int step=1)
        {
            assert(start >=0 && end <= m_length && start < end);
            Array1D<std::reference_wrapper<T>> ret;
            for(int i=start;i<end;i+=step)
                ret.add(m_data[i]);
            return ret;
        }

        //friend bool operator==<T>(const Array1D<T> &a,const Array1D<T> &b);
        //friend Array1D<bool> operator==<T>(Array1D<T> &arr,T comp);
        template<class S>
        friend Array1D<bool> operator> (Array1D<S> &arr,S comp);

        template<class S>
        friend Array1D<bool> operator< (Array1D<S> &arr,S comp);

        template<class S>
        friend Array1D<bool> operator>= (Array1D<S> &arr,S comp);

        template<class S>
        friend Array1D<bool> operator>= (Array1D<S> &arr,S comp);

        template<class S>
        friend std::ostream& operator<< (std::ostream& out,const Array1D<S> &arr);

};

template<class S>
Array1D<bool> operator> (Array1D<S> &arr,S comp)
{
    Array1D<bool> ret(arr.m_length);
    for(int i=0; i<arr.m_length; i++)
    {
        if(arr.m_data[i] > comp)
            ret[i] = true;
        else
            ret[i] = false;
    }
    return ret;
}

template<class S>
Array1D<bool> operator>= (Array1D<S> &arr,S comp)
{
    Array1D<bool> ret(arr.m_length);
    for(int i=0; i<arr.m_length; i++)
    {
        if(arr.m_data[i] >= comp)
            ret[i] = true;
        else
            ret[i] = false;
    }
    return ret;
}

template<class S>
Array1D<bool> operator< (Array1D<S> &arr,S comp)
{
    Array1D<bool> ret(arr.m_length);
    for(int i=0; i<arr.m_length; i++)
    {
        if(arr.m_data[i] < comp)
            ret[i] = true;
        else
            ret[i] = false;
    }
    return ret;
}

template<class S>
Array1D<bool> operator<= (Array1D<S> &arr,S comp)
{
    Array1D<bool> ret(arr.m_length);
    for(int i=0; i<arr.m_length; i++)
    {
        if(arr.m_data[i] <= comp)
            ret[i] = true;
        else
            ret[i] = false;
    }
    return ret;
}

Array1D<bool> operator&(const Array1D<bool> &arr1,const Array1D<bool> &arr2)
{
    assert(arr1.getLength() == arr2.getLength());
    Array1D<bool> ret(arr1.getLength());
    for(int i=0;i<arr1.getLength();i++)
        ret[i]=arr1[i] & arr2[i];
    return ret;
}

Array1D<bool> operator|(const Array1D<bool> &arr1,const Array1D<bool> &arr2)
{
    assert(arr1.getLength() == arr2.getLength());
    Array1D<bool> ret(arr1.getLength());
    for(int i=0;i<arr1.getLength();i++)
        ret[i]=arr1[i] | arr2[i];
    return ret;
}

template<class S>
std::ostream& operator<< (std::ostream& out,const Array1D<S> &arr)
{
    std::cout<<"[";
    for(int i=0;i<arr.getLength()-1;i++)
    {
        std::cout<<" "<<arr[i]<<" ,";
    }
    if(arr.getLength() > 0) std::cout<<" "<<arr[arr.getLength() - 1]<<" ";
    std::cout<<"]";
    return out;
}

//template<class S>
// Array1D<bool> operator==(Array1D<S> &arr,S comp)
// {
//     Array1D<bool> ret(arr.getLength());
//     for(int i=0;i<arr.getLength();i++)
//     {
//         if(arr.m_data[i] == comp)
//             ret.m_data[i]=true;
//         else
//             ret.m_data[i]=false;
//     }
//     return ret;
// }

//template<class S>
// bool operator==(const Array1D<S> &a,const Array1D<S> &b)
// {
//     if(a.m_length == b.m_length)
//     {
//         for(int i=0;i< a.m_length;i++)
//         {
//             if(a.m_data[i] != b.m_data[i])
//                 return false;
//         }
//         return true;
//     }
//     return false;
// }

#endif