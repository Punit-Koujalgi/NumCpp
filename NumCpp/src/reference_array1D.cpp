//#include<bits/stdc++.h>
#ifndef REFERENCE_ARRAY1D
#define REFERENCE_ARRAY1D


#include<functional>
#include "Array1D.cpp"

template<class T>
class Array1D<std::reference_wrapper<T>>
{
    private:
        int m_length;
        class Node
        {
            public:
                std::reference_wrapper<T> m_data;
                Node* m_next;
                Node(T &data): m_data(data),m_next(nullptr){}
        };
        Node* m_data_head;
        Node* m_data_tail;
    public: 
        Array1D(): m_length(0),m_data_head(nullptr),m_data_tail(nullptr) {}

        Array1D(const Array1D& array):m_length(array.getLength())
        {
            //m_data_head=array.m_data_head;
            //m_data_tail=array.m_data_tail;
            if(array.getLength() > 0)
            {
                Node* temp1=array.m_data_head;
                m_data_head=new Node((temp1->m_data).get());
                Node* temp2=m_data_head;
                temp1=temp1->m_next;
                while(temp1)
                {
                    Node* newNode=new Node((temp1->m_data).get());
                    temp2->m_next=newNode;
                    temp2=newNode;
                    temp1=temp1->m_next;
                }
                m_data_tail=temp2;
            }
            else
                m_data_head=m_data_tail=nullptr;
        }

        void add(T &newData)
        {
            Node* newNode=new Node(newData);
            if(!m_data_head)
                m_data_head=newNode;
            else
                m_data_tail->m_next=newNode;
            m_data_tail=newNode;
            m_length++;
        }

        T& operator[](int index)
        {
            assert(index >=0 && index < m_length);
            int len=0;
            Node* temp=m_data_head;
            while(len < index )
            {
                temp=temp->m_next;
                len++;
            }
            return (temp->m_data).get();
        } 

        const T& operator[](int index) const
        {
            assert(index >=0 && index < m_length);
            int len=0;
            Node* temp=m_data_head;
            while(len < index )
            {
                temp=temp->m_next;
                len++;
            }
            return (temp->m_data).get();
        }


        int getLength() const { return m_length; }

        Array1D& operator=(std::initializer_list<T> list)
        {
            assert(m_length == static_cast<int>(list.size()));
            Node* temp=m_data_head;
            for(auto element : list)
            {
                (temp->m_data).get() = element;
                temp=temp->m_next;
            }
            return *this;
        }
        

        operator Array1D<T>() const
        {
            Array1D<T> ret(m_length);
            for(int i=0;i<m_length;i++)
                ret[i]=(*this)[i];
            return ret;
        } 

        ~Array1D()
        {
            while(m_data_head!=nullptr )
            {
                Node* temp=m_data_head;
                m_data_head=m_data_head->m_next;
                delete temp;
            }
        }
};

#endif