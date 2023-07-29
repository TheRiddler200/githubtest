#include <iostream>
#include <fstream>
#include <string>


class Person;       //forward decleration of class

void insert_text_file_if_under_21(Person &person_obj);          //forward decleration of function

class Person{
private:
    friend std::ostream &operator<<(std::ostream &os, const Person &person_obj);
protected:
    std::string name;
    std::string skill;
    int age;
public:
    Person(std::string name_val, std::string skill_val, int age_val)
        :name(name_val), skill(skill_val), age(age_val) {
            if (age < 21) {
                insert_text_file_if_under_21(*this);
            }
        }


    ~Person() {}

    std::string get_name() const {return name;}
    std::string get_skill() const {return skill;}
    int get_age() const {return age;}                
};

//insertion operator overloaded
std::ostream &operator<<(std::ostream &os, const Person &person_obj){
    os << "Name: " << person_obj.get_name()  << "\t\tskill: " << person_obj.get_skill() << "\t\tAge: " << person_obj.get_age();
    return os; 
}



//make a function that inserts objcet into text file if age under 21
void insert_text_file_if_under_21(Person &person_obj) {
    std::fstream under_21_file("under_21.txt", std::ios::app);
    //check if file is open
    if (under_21_file.is_open()){
        under_21_file << person_obj;
        under_21_file << "\n";
        under_21_file.close();
        std::cout<<"done..."<<std::endl;
    }else {
        std::cout<<"Error: file did not open"<<std::endl;
    }
}





int main() {


    //peson class

    Person person1("Alice", "Law", 22);
    
    std::cout << person1 <<std::endl;



    return 0;   
}