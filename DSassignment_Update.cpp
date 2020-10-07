#include<iostream>
#include<iomanip>
#define number_of_course 3
#define NL <<endl

using namespace std;
class Course{
    int course_number;
    float course_gp;
    float course_credits;
    void put_course_number(int Course_number){
        course_number = Course_number;
    }
    int get_course_number(){
        return course_number;
    }
    void put_course_gp(float Course_gp){
        course_gp = Course_gp;
    }
    float get_course_gp(){
        return course_gp;
    }
    void put_course_credits(float Course_credits){
        course_credits = Course_credits;
    }
public:
    float get_course_credits(){
        return course_credits;
    }
    void set_course_information(int Course_number,float Course_gp,float Course_credits){
        put_course_number(Course_number);
        put_course_gp(Course_gp);
        put_course_credits(Course_credits);
    }
    float get_gp_multiplyby_credits(){
        return get_course_gp()*get_course_credits();
    }
};
class Student{
    Course course[number_of_course];
    int student_id;
    void put_student_id(int Student_id){
        student_id = Student_id;
    }
public:
    void get_student_information();
    void print_student_information();
    int get_student_id(){
        return student_id;
    }
    float get_cgpa(){
        float total_gp = 0.0,total_credits = 0.0;
        for(int i=0;i<number_of_course;i++){
            total_gp += course[i].get_gp_multiplyby_credits();
            total_credits += course[i].get_course_credits();
        }
        return (total_gp+0.0)/total_credits;
    }
    void swap_student(Student& student){
        Student temp_student = student;
        student = *this;
        *this = temp_student;
    }
};
void Student::get_student_information(){
    int student_id;
    cout<<"Enter Student ID: ";
    cin>>student_id;
    put_student_id(student_id);
    float course_gp,course_credits;
    for(int i=0;i<number_of_course;i++){
        cout<<"Enter Course "<<i+1<<" Grad point: ";
        cin>>course_gp;
        cout<<"Enter course "<<i+1<<" Credits: ";
        cin>>course_credits;
        course[i].set_course_information(i+1,course_gp,course_credits);
    }
}
void Student::print_student_information(){
    cout<<"student id: "<<get_student_id() NL;
    cout<<"Cgpa: "<<setprecision(3)<<get_cgpa() NL;
}
void merit_prossting(Student student[],int number_of_student){
    bool swaped;
    ///Bubble sort according to student cgpa
    for(int i=0;i<number_of_student;i++){
        swaped = false;
        for(int j=0;j<number_of_student-1-i;j++){
            if(student[j].get_cgpa() < student[j+1].get_cgpa()){
                student[j].swap_student(student[j+1]);
                swaped = true;
            }
        }if(!swaped) break;
    }
}
///Linear search
int search_student(Student student[],int student_id,int number_of_student){
    for(int i=0;i<number_of_student;i++){
        if(student[i].get_student_id() == student_id) return i;
    }return -1;
}
int main(){
    cout<<"Enter the number of Student: ";
    int number_of_student;
    cin>>number_of_student;
    Student student[number_of_student];
    for(int i=0;i<number_of_student;i++){
        student[i].get_student_information();
    }
    merit_prossting(student,number_of_student);
    cout NL <<"Student Merit Position are : " NL NL;
    for(int i=0;i<number_of_student;i++){
        cout<<"Merit: "<<i+1 NL;
        student[i].print_student_information();
        cout NL;
    }
    ///Quarry
    int number_of_quarry;
    cout<<"Enter the quarry number: ";
    cin>>number_of_quarry;
    int student_id;
    while(number_of_quarry--){
        cout<<"Enter student id: ";
        cin>>student_id;
        int index = search_student(student,student_id,number_of_student);
        if(index == -1){
            cout<<"Student id not found." NL NL;
            continue;
        }
        cout<<"Merit: "<<index+1 NL;
        student[index].print_student_information();
        cout NL;
    }
    return 0;
}
