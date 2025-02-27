#include <iostream>
#include <vector> 
using namespace std;
class Subject{
    public:
    string subjectname;
    int credit;
    float gradepoint;


    Subject(string name,int cr,float gp)
    {
        subjectname=name;
        credit = cr;
        gradepoint = gp;

    }
};

class Student{
    public :
    string name;
    vector<Subject>subjects;
    
    Student(string studentName)
    {
        name = studentName;
    }
    void addSubject(string subjectName,int credit,float gradepoint)

{
    Subject newSubject (subjectName,credit,gradepoint);
    subjects.push_back(newSubject);
}
    float calculatecgpa()
    {
        int totalcredit = 0;
        float weightedgradepoint=0;
        for (const Subject & subject:subjects)
        {
            totalcredit+=subject.credit;
            weightedgradepoint+=subject.credit*subject.gradepoint;
        }
        return (totalcredit>0)?(weightedgradepoint/totalcredit):0;
    }
    void displaycgpa()
    {
        cout << "student name" <<name<<endl;
        float cgpa=calculatecgpa();
        cout <<"CGPA:"<<cgpa<<endl;
    };
   
};

int main()
{
    string studentname;
    int numsub;

    cout << "Student name:";
    getline(cin,studentname);

    cout << "No. of subjects:";
    cin >> numsub;
    Student student(studentname);
    
    

    for(int j=0;j<numsub;j++)
    {
        string subjectname;
        int credit;
        float gradepoint;

        cout << "enter the Subject name:";

        cin.ignore();
        getline (cin,subjectname);

        cout << "enter the credit";
        cin >> gradepoint;
        student.addSubject(subjectname,credit,gradepoint);

    }
student.displaycgpa();
}
