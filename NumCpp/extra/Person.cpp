#include<iostream>
#include<string>

class Person
{
    private:
        std::string m_name;
        int m_age;
        std::string m_occupation;
    public:
        Person()=default;
        Person(const std::string &name,int age,const std::string &occupation): 
                    m_name(name),m_age(age),m_occupation(occupation) {}
        friend std::ostream& operator<<(std::ostream& out,const Person& person);
};

std::ostream& operator<<(std::ostream& out,const Person& person)
{
    std::cout<<"( Name: "<<person.m_name<<" ,";
    std::cout<<"Age: "<<person.m_age<<" ,";
    std::cout<<"Occupation: "<<person.m_occupation<<" )"; 
}