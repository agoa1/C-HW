

#include<conio>
#include<stdio>
#include<process>
#include<fstream>
#include<iomanip>

class final
{
    int studid; //student ID number 
    char name[50]; //
    int p_marks,c_marks,m_marks,e_marks,cs_marks; //grade for phys. ed, chem, math, english, and comsci
    float percent; // student's average
    char grade; // final letter grade
    int std;
    void calculate()
    {
        percent=(p_marks+c_marks+m_marks+e_marks+cs_marks)/5.0;
        if(percent>=80) //anything above 80 is an A
            grade='A';
        else if(percent>=70 && per<80) //anything between 70-80 is a B
            grade='B';
        else if(percent>=60 && per<70) //between 60-70 is a C
            grade='C';
        else
            grade='F'; // anything below a 60 is an F
    }

public:
    void getdata()
    {
        cout<<"\nEnter the student ID number of student";
        cin>>studid;
        cout<<"\n\nEnter the name of student ";
        gets(name);
        cout<<"\nEnter the student's grade in Physical Education out of 100 : ";
        cin>>p_marks;
        cout<<"\nEnter the student's grade in Chemistry out of 100: ";
        cin>>c_marks;
        cout<<"\nEnter the student's grade in Math out of 100: ";
        cin>>m_marks;
        cout<<"\nEnter the student's grade in English out of 100: ";
        cin>>e_marks;
        cout<<"\nEnter the student's grade in Computer Science out of 100: ";
        cin>>cs_marks;
        calculate();
    }

    void showdata()
    {
        cout<<"\nStudent ID number: "<<studid;
        cout<<"\nName of student : "<<name;
        cout<<"\nGrade in Physical Education : "<<p_marks;
        cout<<"\nGrade in Chemistry : "<<c_marks;
        cout<<"\nGrade in Maths : "<<m_marks;
        cout<<"\nGrade in English : "<<e_marks;
        cout<<"\nGrade in Computer Science :"<<cs_marks;
        cout<<"\nPercentage:"<<setprecision(2)<<percent;
        cout<<"\nStudent's final grade:"<<grade;
    }

    void show_tabular()
    {
        cout<<studid<<setw(12)<<name<<setw(10)<<p_marks<<setw(3)<<c_marks<<setw(3)<<m_marks<<setw(3)<<e_marks<<setw(3)<<cs_marks<<setw(6)<<setprecision(3)<<percent<<"   "<<grade<<endl;
    }

    int  getstudid()
    {
        return studid;
    }

};         




fstream fp;
student st;

//

void write_student()
{
    fp.open("student.dat",ios::out|ios::app);
    st.getdata();
    fp.write((char*)&st,sizeof(student));
    fp.close();
    cout<<"\n\nStudent Record has been created ";
    getch();
}


//read all records from file


void display_all()
{
    clrscr();
    cout<<"\n\n\n\t\tDisplay all records.\n\n";
    fp.open("student.dat",ios::in);
    while(fp.read((char*)&st,sizeof(student)))
    {
        st.showdata();
        cout<<"\n\n====================================\n";
        getch();
    }
    fp.close();
    getch();
}


//read specific record from file


void display_sp(int n)
{
    int flag=0;
    fp.open("student.dat",ios::in);
    while(fp.read((char*)&st,sizeof(student)))
    {
        if(st.retrollno()==n)
        {
            clrscr();
            st.showdata();
            flag=1;
        }
    }
    fp.close();
    if(flag==0)
        cout<<"\n\nError: record not exist";
    getch();
}


//modify record of file



void modify_student()
{
    int no,found=0;
    clrscr();
    cout<<"\n\n\tTo Modify ";
    cout<<"\n\n\tPlease Enter The student id number of student";
    cin>>no;
    fp.open("student.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)) && found==0)
    {
        if(st.retrollno()==no)
        {
            st.showdata();
            cout<<"\nEnter student's new information"<<endl;
            st.getdata();
            int pos=-1*sizeof(st);
            fp.seekp(pos,ios::cur);
            fp.write((char*)&st,sizeof(student));
            cout<<"\n\n\t Record has been updated";
            found=1;
        }
    }
    fp.close();
    if(found==0)
        cout<<"\n\n Error: record not found ";
    getch();
}


//function to delete record of file



void delete_student()
{
    int no;
    clrscr();
    cout<<"\n\n\n\tDelete Record";
    cout<<"\n\nPlease Enter The student id number of student";
    cin>>no;
    fp.open("student.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&st,sizeof(student)))
    {
        if(st.retstudid()!=no)
        {
            fp2.write((char*)&st,sizeof(student));
        }
    }
    fp2.close();
    fp.close();
    remove("student.dat");
    rename("Temp.dat","student.dat");
    cout<<"\n\n\tRecord has been deleted";
    getch();
}


//display all students grade report


void class_result()
{
    clrscr();
    fp.open("student.dat",ios::in);
    if(!fp)
    {
        cout<<"Error: file could not be opened \n\n\n Go to Entry Menu to create a file";
        cout<<"\n\n\n Program is closing ";
        getch();
        exit(0);
    }

    cout<<"\n\n\t\tALL STUDENTS RESULT \n\n";
    cout<<"====================================================\n";
    cout<<"Student ID          P  C  M  E  CS  %age Grade\n";
    cout<<"====================================================\n";

    while(fp.read((char*)&st,sizeof(student)))
    {
        st.show_tabular();
    }
    fp.close();
    getch();
}



//
//display result menu

void result()
{
    int ans,rno;
    char ch;
    clrscr();
    cout<<"\n\n\nRESULT MENU";
    cout<<"\n\n\n1. Class Result
    \n\n2. Student Report Card
    \n\n3.Back to Main Menu";
    cout<<"\n\n\nEnter Choice ";
    cin>>ans;
    switch(ans)
    {
    case 1 :
        class_result();
        break;
    case 2 :
    {
        do
        {
            clrscr();
            char ans;
            cout<<"\n\nEnter student id number of student : ";
            cin>>rno;
            display_sp(rno);
            cout<<"\n\nDo you want to See More Result (y/n)?";
            cin>>ans;
        }
        while(ans=='y'||ans=='n');

        break;
    }
    case 3:
        break;
    default:
        cout<<"\a";
    }
}

//INTRODUCTION 

void intro()
{
    clrscr();
    gotoxy(35,11);
    cout<<"STUDENT";
    gotoxy(33,14);
    cout<<"REPORT CARD";
    gotoxy(35,17);
    cout<<"PROJECT";
    getch();

}




//ENTRY / EDIT MENU FUNCTION

void entry_menu()
{
    clrscr();
    char ch2;
    cout<<"\n\n\n\tENTRY MENU";
    cout<<"\n\n\t1.Create student record";
    cout<<"\n\n\t2.Display all records";
    cout<<"\n\n\t3.Search student records ";
    cout<<"\n\n\t4.Modify student record";
    cout<<"\n\n\t5.Delete srudent record";
    cout<<"\n\n\t6.BACK TO MAIN MENU";
    cout<<"\n\n\tPlease Select Your Option ";
    ch2=getche();
    switch(ch2)
    {
    case '1':
        clrscr();
        write_student();
        break;
    case '2':
        display_all();
        break;
    case '3':
        int num;
        clrscr();
        cout<<"\n\n\tPlease Enter The student id number ";
        cin>>num;
        display_sp(num);
        break;
    case '4':
        modify_student();
        break;
    case '5':
        delete_student();
        break;
    case '6':
        break;
    default:
        cout<<"\a";
        entry_menu();
    }
}


//THE MAIN FUNCTION OF PROGRAM


void main()
{
    char ch;
    intro();
    do
    {
        clrscr();
        cout<<"\n\n\n\tMAIN MENU";
        cout<<"\n\n\t01. Result menu";
        cout<<"\n\n\t02. Entry/edit menu";
        cout<<"\n\n\t03. EXIT";
        cout<<"\n\n\tPlease Select Your Option  ";
        ch=getche();
        switch(ch)
        {
        case '1':
            clrscr();
            result();
            break;
        case '2':
            entry_menu();
            break;
        case '3':
            exit(0);
        default :
            cout<<"\a";
        }
    }
    while(ch!='3');
}

