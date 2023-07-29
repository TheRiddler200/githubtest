#include <iostream>
#include <string>



class Person{
private:
    friend std::ostream &operator<<(std::ostream &os, const Person &person_obj);
protected:
    std::string name;
    std::string skill;
    int age;
public:
    Person(std::string name_val, std::string skill_val, int age_val)
        :name(name_val), skill(skill_val), age(age_val) {}


    ~Person() {}

    std::string get_name() const {return name;}
    std::string get_skill() const {return skill;}
    int get_age() const {return age;}                
};



std::ostream &operator<<(std::ostream &os, const Person &person_obj){
    os << "Name: " << person_obj.get_name()  << "\t\tskill: " << person_obj.get_skill() << "\t\tAge: " << person_obj.get_age();
    return os; 
}



int main() {


    //peson class

    Person person1("Alice", "Law", 22);
    
    std::cout << person1 <<std::endl;



    return 0;   
}