//#include<bits/stdc++.h>
#ifndef REFERENCE_ARRAY2D
#define REFERENCE_ARRAY2D

#include<functional>
#include "Array2D.cpp"

template<class T>
class  Array2D<std::reference_wrapper<T>>
{
    private:
        int m_rows;
        int m_cols;
        class Node
        {
            public:
                Array1D<std::reference_wrapper<T>> m_data;
                Node* m_next;
                Node(Array1D<std::reference_wrapper<T>> &data): m_data(data), m_next(nullptr) {}
        };
        Node* m_data_head;
        Node* m_data_tail;
        void deepCopyNodes(const Array2D& arr)
        {
            Node* temp1=arr.m_data_head;
            m_data_head=new Node(temp1->m_data);
            Node* temp2=m_data_head;
            temp1=temp1->m_next;
            while(temp1)
            {
                Node* newNode=new Node(temp1->m_data);
                temp2->m_next=newNode;
                temp2=newNode;
                temp1=temp1->m_next;
            }
            m_data_tail=temp2;
        }
    public:
        Array2D(): m_rows(0), m_cols(0) ,m_data_head(nullptr),m_data_tail(nullptr) {}

        Array2D(const Array2D& array): m_rows(array.m_rows), m_cols(array.m_cols)
        {
            deepCopyNodes(array);
        }

        Array2D& operator=(const Array2D<T>& arr)
        {
            assert(m_rows==arr.getRows() && m_cols==arr.getCols());
            for(int row=0;row<m_rows;row++)
               for(int col=0;col<m_cols;col++)
                    (*this)[row][col]=arr[row][col];        
            return *this;
        }

        Array2D& operator=(const Array2D& arr)
        {
            assert(m_rows==arr.getRows() && m_cols==arr.getCols());
            for(int row=0;row<m_rows;row++)
               for(int col=0;col<m_cols;col++)
                    (*this)[row][col]=arr[row][col];        
            return *this;
        }

        Array2D& operator=(std::initializer_list<std::initializer_list<T>> list)
        {
            assert(m_rows==list.size());// && m_cols==arr.getCols());
            for(auto &x:list)
                assert(m_cols == static_cast<int>(x.size()));
            int row=0;
            for(auto &x : list)
            {
                int col=0;
                for(auto &y : x)
                {
                    (*this)[row][col]=y;
                    col++;
                }
                row++;
            }
            return *this;
        }

        void add(Array1D<std::reference_wrapper<T>>& arr)
        {
            //std::cout<<arr<<"\n";
            Node* newNode=new Node(arr);
            if(!m_data_head)
                m_data_head=newNode;
            else
                m_data_tail->m_next=newNode;
            m_data_tail=newNode;
            m_cols=arr.getLength();
            m_rows++;
        }

        // void display() const
        // {
        //     Node* temp=m_data_head;
        //     while(temp)
        //     {
        //         std::cout<<temp->m_data;
        //         temp=temp->m_next;
        //     }
        // }

        int getRows() const { return m_rows; }
        int getCols() const { return m_cols; }

        Array1D<std::reference_wrapper<T>>& operator[](int index)
        {
            assert(index>=0 && index < m_rows);
            int len=0;
            Node *temp=m_data_head;
            while(len < index)
            {
                temp = temp->m_next;
                len++;
            }
            return temp->m_data;
        }

        const Array1D<std::reference_wrapper<T>>& operator[](int index) const
        {
            assert(index>=0 && index < m_rows);
            int len=0;
            Node *temp=m_data_head;
            while(len < index)
            {
                temp = temp->m_next;
                len++;
            }
            return temp->m_data;
        }

        operator Array2D<T>() const 
        {
            Array2D<T> ret(m_rows,m_cols);
            for(int row=0;row<m_rows;row++)
                for(int col=0;col<m_cols;col++)
                    ret[row][col]=(*this)[row][col];
            return ret;
        }

        ~Array2D()
        {
            while(m_data_head!=nullptr)
            {
                Node* temp=m_data_head;
                m_data_head=m_data_head->m_next;
                delete temp;
            }
        }

};

#endif