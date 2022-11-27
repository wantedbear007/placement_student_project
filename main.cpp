#include<bits/stdc++.h>
using namespace std;

class Student
{
    // File management classes
    ifstream readFile; 
    ofstream writeFile;
    
    string salary, place, mode, role, vacancy, code, company, country, branch;
    string title, announcement, date, author_name, division, college;

    public:
    void student_login(int reg_num, string passwd); // student login
    void student_registration(string name, int reg_num, string passwd, string department, string email_address); // student registration

    void apply_position(int reg_num, string name, string branch, string desc, string job_code, string email) {
        writeFile.open("CSVs/studentsJobReq.csv", ios_base::app);
        writeFile << reg_num << "," << name << "," << branch << "," << desc << "," << job_code << "," << email << "," << endl;
        writeFile.close();
    }; // this function will allow student to register for a job or internship

    void get_announcements() {
        readFile.open("CSVs/announcements.csv");

        cout<<"\n\n\n\n";
        cout << "\t\t\t||========================================================================================================================================||"<<endl;
        cout << "\t\t\t\tAnnouncements (Division of Placements)                                             Lovely Professional University, Phagwara" << endl;
        cout << "\t\t\t||========================================================================================================================================||"<<endl;

        while(readFile.good()) {
            getline(readFile, title, ',');
            getline(readFile, announcement, ',');
            getline(readFile, date, ',');
            getline(readFile, author_name, ',');

            cout << endl; 
            cout << "-----------------------------------------" << endl;
            cout << "Title: " <<  title << endl;
            cout << announcement << endl;
            cout << "Date: " << date << endl;
            cout << "By: " << author_name << endl;
            cout << "Division of Placements" << endl;
            cout << "Lovely Professional University, Phagwara, Punjab" << endl;

            cout << "-----------------------------------------" << endl;
            cout << endl;
        }
        readFile.close();
    }; // to get the announcements given by the placement wing 


        void log_request(int reg_num, string name, string branch, string title, string body) {


        writeFile.open("CSVs/student_logs.csv", ios_base::app);
        writeFile << reg_num << "," << name << "," << branch << "," << title << "," << body << "," << endl;
        writeFile.close();

    }; // to log request to placement cell
    // void log_request(string reg_num, string name, string branch, string title, string body) {

    //     writeFile.open("CSVs/student_logs.csv", ios_base::app);
    //     writeFile << reg_num << "," << name << "," << branch << "," << title << "," << body << "," << endl;
    //     writeFile.close();

    // }; // to log request to placement cell

    void companies_today() {
        readFile.open("CSVs/companies_today.csv");

        // to get date and time
        time_t now = time(0);
        char* date = ctime(&now);

        cout<<"\n\n\n\n";
        cout << "\t\t\t||========================================================================================================================================||"<<endl;
        cout << "\t\t\t\tCompanies Today in Campus Date: "<< date << " Lovely Professional University, Phagwara" << endl;
        cout << "\t\t\t||========================================================================================================================================||"<<endl;

        while(readFile.good()) {
            // string company, country, branch;
            getline(readFile, company, ',');
            getline(readFile, salary, ',');
            getline(readFile, place, ',');
            getline(readFile, mode, ',');
            getline(readFile, vacancy, ',');
            getline(readFile, role, ',');
            getline(readFile, code, ',');

            cout << endl; 
            cout << "-----------------------------------------" << endl;
            cout << "Company " <<  company << endl;
            cout << "Salary: " << salary << endl;
            cout << "Place: " << place << endl;
            cout << "Mode: " << mode << endl;
            cout << "Vacancy: " << vacancy << endl;
            cout << "Role: " << role << endl;
            cout << "Job Code: " << code << endl;

            cout << "-----------------------------------------" << endl;
            cout << endl;
        }
        readFile.close();


    }; // to list out the companies available today

    void list_visited_companies() {

        readFile.open("CSVs/companies.csv");
 
        cout<<"\n\n\n\n";
        cout << "\t\t\t||==============================================================================================||"<<endl;
        cout << "\t\t\t\tPrevious Visited Companies for Placement          Lovely Professional University, Phagwara" << endl;
        cout << "\t\t\t||==============================================================================================||"<<endl;

        while(readFile.good()) {
            // string company, country, branch;
            getline(readFile, company, ',');
            getline(readFile, country, ',');
            getline(readFile, branch, ',');

            cout << endl; 
            cout << "-----------------------------------------" << endl;
            cout << "Company " <<  company << endl;
            cout << "Country: " << country << endl;
            cout << "Branch: " << branch << endl;
            cout << "-----------------------------------------" << endl;
            cout << endl;
        }

        readFile.close();

    }; // to list all the companies visited to our campus 

    void internships_available() {

        readFile.open("CSVS/internships.csv");
        // string salary, place, mode, role, vacancy, code;

        // cout << "List of internships available: " << endl;
        cout<<"\n\n\n\n";
        cout << "\t\t\t||==============================================================================================||"<<endl;
        cout << "\t\t\t\tInternships Available                        Lovely Professional University, Phagwara" << endl;
        cout << "\t\t\t||==============================================================================================||"<<endl;
        while(readFile.good()) {
            getline(readFile, salary, ',');
            getline(readFile, place, ',');
            getline(readFile, mode, ',');
            getline(readFile, role, ',');
            getline(readFile, vacancy, ',');
            getline(readFile, code, ',');

            cout << "-----------------------------------------" << endl;
            cout << "Stipend is: " << salary << endl;
            cout << "Place: " << place << endl;
            cout << "Mode of Internship: " << mode << endl;
            cout << "Role: " << role << endl;
            cout << "No. of Vacancy available: " << vacancy << endl;
            cout << "Code Number: " << code << endl;

            cout << "-----------------------------------------" << endl;

        }
        readFile.close();

    }; // to see all the internships available today

};

class Placement
{

    ofstream writeFile;
    ifstream readFile;

    string reg_num, name, branch, title, body, job_code, desc;
    string student_name, student_email, ctc, id, company_name;

    public:
    void placement_cell_login(int reg_num, string passwd); // login from placement cell

    void placement_announcement(string title, string body, string author, string date) {
        writeFile.open("CSVs/announcements.csv");
        writeFile << title << "," << body << "," << date << "," << author << "," << "Division Of Placement" << "," << "Lovely Professional University, Phagwara, Punjab" << "," << endl;
        writeFile.close();

    } // function for making public announcement 

    void student_requests() {
        cout<<"\n\n\n\n";
        cout << "\t\t\t||========================================================================================================================================||"<<endl;
        cout << "\t\t\t\tStudents Requests (Division of Placements)                                         Lovely Professional University, Phagwara" << endl;
        cout << "\t\t\t||========================================================================================================================================||"<<endl;

        readFile.open("CSVs/student_logs.csv");

        while (readFile.good()) {
            getline(readFile, reg_num, ',');
            getline(readFile, name, ',');
            getline(readFile, branch, ',');
            getline(readFile, title, ',');
            getline(readFile, body, ',');

             cout << endl; 
            cout << "-----------------------------------------------------------" << endl;
            cout << "Registration Number:  " <<  reg_num << endl;
            cout << "Student Name: " << name << endl;
            cout << "Branch: " << branch << endl;
            cout << "Title: " << title << endl;
            cout << body << endl;
            cout << "-----------------------------------------------------------" << endl;
            cout << endl;
        }

    }; // to view all the request from the student
    void add_companies(string company_name, string salary, string place, string mode, string availability, string role, string company_code) {
        writeFile.open("CSVs/companies_today.csv", ios_base::app);
        writeFile << company_name << "," << salary << "," << place << "," << mode << "," << availability << "," << role << "," << company_code << "," << endl;
        writeFile.close();

    }; // to add companies available today

    void registered_users() {
        readFile.open("CSVs/registered_users.csv");

        cout<<"\n\n\n\n";
        cout << "\t\t\t||========================================================================================================================================||"<<endl;
        cout << "\t\t\t\tRegistered Users (Division of Placements)                                         Lovely Professional University, Phagwara" << endl;
        cout << "\t\t\t||========================================================================================================================================||"<<endl;
        
        while (readFile.good()) {
            getline(readFile, reg_num, ',');
            getline(readFile, student_name, ',');
            getline(readFile, branch, ',');
            getline(readFile, student_email, ',');

                cout << endl; 
            cout << "-----------------------------------------------------------" << endl;
            cout << "Registration Number: " <<  reg_num << endl;
            cout << "Student Name:  " << student_name << endl;
            cout << "Branch: " << branch << endl;
            cout << "Email-address: " << student_email << endl;
            cout << "-----------------------------------------------------------" << endl;
            cout << endl;
        }

        readFile.close();
    }; // to list all the registered users available 

    void placed_students() {
        readFile.open("CSVs/placed_students.csv");

        cout<<"\n\n\n\n";
        cout << "\t\t\t||========================================================================================================================================||"<<endl;
        cout << "\t\t\t\tPlaced Students (Division of Placements)                                         Lovely Professional University, Phagwara" << endl;
        cout << "\t\t\t||========================================================================================================================================||"<<endl;
        
        while (readFile.good()) {
            getline(readFile, id, ',');
            getline(readFile, student_name, ',');
            getline(readFile, student_email, ',');
            getline(readFile, ctc, ',');
            getline(readFile, company_name, ',');

            cout << endl; 
            cout << "-----------------------------------------------------------" << endl;
            cout << "Student Name: " <<  student_name << endl;
            cout << "Student Email:  " << student_email << endl;
            cout << "Cost to Company(CTC): " << ctc << endl;
            cout << "Company Name: " << company_name << endl;
            cout << "-----------------------------------------------------------" << endl;
            cout << endl;
        }
        readFile.close();

    }; // to list all the placed students 


    void add_visited_companies(string company_name, string country, string branch) {
        writeFile.open("CSVs/companies.csv", ios_base::app);
        writeFile << company_name << "," << country << "," << branch << "," << endl;
        writeFile.close();
    }; // to add visited companies 

    void student_job_requests() {
        readFile.open("CSVs/studentsJobReq.csv");

        cout<<"\n\n\n\n";
        cout << "\t\t\t||========================================================================================================================================||"<<endl;
        cout << "\t\t\t\tStudent Job Requests                                                             Lovely Professional University, Phagwara" << endl;
        cout << "\t\t\t||========================================================================================================================================||"<<endl;

        while (readFile.good()) {
            getline(readFile, reg_num, ',');
            getline(readFile, student_name, ',');
            getline(readFile, branch, ',');
            getline(readFile, desc, ',');
            getline(readFile, job_code, ',');
            getline(readFile, student_email, ',');

            cout << endl; 
            cout << "-----------------------------------------------------------" << endl;
            cout << "Registration Number: " <<  reg_num << endl;
            cout << "Student Name:  " << student_name << endl;
            cout << "Student Email: " << student_email << endl;
            cout << "Student Branch: " << branch << endl;
            cout << desc << endl;
            cout << "Job code: " << job_code << endl;
            cout << "-----------------------------------------------------------" << endl;
            cout << endl;
        }

        readFile.close();
    }
};

class InitialOpening
{
    // int user_input;
    public:
    // int indexPage(int user_input); 
    InitialOpening() {
        cout << "Welcome to placement cell  \n" << endl;
        cout << "Select from the following options: " << endl;
        cout << "1 for Student" << endl;
        cout << "2 for Placement cell" << endl;
        cout << "3 to exit \n" << endl;
        cout << "Enter your options: ";
    }
    
    int indexPage(int user_input) // initial index page of the project
    {

        Student s1;
        Placement p1;
        int user_ipt, reg_num = 0;
        string registration_no;
        string  student_name = "none", branch = "none", desc = "none", job_code = "none", email = "none", log_title = "none", lol="l";

        if (user_input == 1) {
            cout<<"\n\n\n\n";
            cout << "\t\t\t||========================================================================================================================================||"<<endl;
            cout << "\t\t\t\tStudent Placement Portal                                                        Lovely Professional University, Phagwara" << endl;
            cout << "\t\t\t||========================================================================================================================================||"<<endl;

            // cout << "Select for the following: \n" << endl;
            // cout << "1. Visited Companies" << endl;
            // cout << "2. Internships Available" << endl;
            // cout << "3. Companies today" << endl;
            // cout << "4. Placement Cell Announcements" << endl;
            // cout << "5. Apply for Job / Internship Position" << endl;
            // cout << "6. Log request\n" << endl;

            // cout << "To select enter the 1, 2, 3, 4, 5, 6 according to your requirements: "; cin >> user_input;

            // while (inside_student) {

            cout << "Select for the following: \n" << endl;
            cout << "1. Visited Companies" << endl;
            cout << "2. Internships Available" << endl;
            cout << "3. Companies today" << endl;
            cout << "4. Placement Cell Announcements" << endl;
            cout << "5. Apply for Job / Internship Position" << endl;
            cout << "6. Log request\n" << endl;
            

            cout << "To select enter the 1, 2, 3, 4, 5, 6 according to your requirements: "; cin >> user_input;


            switch (user_input)
            {
                case 1:
                cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                s1.list_visited_companies();
                cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                break;

                case 2:
                cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                s1.internships_available();
                cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                break;

                
                case 3:
                cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                s1.companies_today();
                cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                break;


                case 4:
                cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                s1.get_announcements();
                cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                break;


                case 5:
                cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                cout << endl;

                cout<<"\n\n\n\n";
                cout << "\t\t\t||========================================================================================================================================||"<<endl;
                cout << "\t\t\t\t Apply for JOB / Internships                                                      Lovely Professional University, Phagwara" << endl;
                cout << "\t\t\t||========================================================================================================================================||"<<endl;   

                cout << "-- Enter the following Details (* means Mandatory) --" << endl;
                cout << "Registration number:* "; cin >> reg_num;
                getline(cin, lol);
                cout << "Name:* "; 
                getline(cin, student_name);
                cout << "Branch:* "; 
                getline(cin, branch);
                cout << "Message: "; 
                getline(cin, desc);
                cout << "Job Code (Available in the companies details):* "; 
                getline(cin, job_code);
                cout << "Email ID:* ";
                getline(cin, email);
                
                s1.apply_position(reg_num, student_name, branch, desc, job_code, email);
                cout << "Your Request has been successfully sent to the Division of Placement.\n Division of Placement" << endl;
                cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                break;


                case 6:
                cout<<"\n\n\n\n";
                cout << "\t\t\t||========================================================================================================================================||"<<endl;
                cout << "\t\t\t\t Log request to Division of Placement                                                      Lovely Professional University, Phagwara" << endl;
                cout << "\t\t\t||========================================================================================================================================||\n\n"<<endl;  

                cout << "\n\n--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                // string name, branch, title, body, lol;

                cout << "-- Enter the following Details (* means Mandatory) --\n\n" << endl;
                cout << "Registration number:* "; cin >> reg_num;
                cout << ""; 
                getline(cin,lol);
                
                cout << "Name:* ";
                getline(cin,student_name);
                cout << "Branch:* ";
                getline(cin,branch);
                cout << "Title:* ";
                getline(cin,log_title);
                cout << "Message: ";
                getline(cin,desc);

                s1.log_request(reg_num, student_name, branch, log_title, desc);
                cout << "Your Request has been successfully sent to the Division of Placement.\n Division of Placement" << endl;
                cout << "\n\n--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                return 3;
                break;

                // default:
                // cout << "Invalid Input";
                // // inside_student = false;
                // break;
            }


            // switch (user_input)
            // {
            //     case 1:
            //     cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            //     s1.list_visited_companies();
            //     cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            //     break;

            //     case 2:
            //     cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            //     s1.internships_available();
            //     cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            //     break;

                
            //     case 3:
            //     cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            //     s1.companies_today();
            //     cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            //     break;


            //     case 4:
            //     cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            //     s1.get_announcements();
            //     cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            //     break;


            //     case 5:
            //     cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            //     cout << endl;

            //     cout<<"\n\n\n\n";
            //     cout << "\t\t\t||========================================================================================================================================||"<<endl;
            //     cout << "\t\t\t\t Apply for JOB / Internships                                                      Lovely Professional University, Phagwara" << endl;
            //     cout << "\t\t\t||========================================================================================================================================||"<<endl;   

            //     cout << "-- Enter the following Details (* means Mandatory) --" << endl;
            //     cout << "Registration number:* "; cin >> reg_num;
            //     cout << "Name:* "; cin >> student_name;
            //     cout << "Branch:* "; cin >> branch;
            //     cout << "Message: "; cin >> desc;
            //     cout << "Job Code (Available in the companies details):* "; cin >> job_code;
            //     cout << "Email ID:* "; cin >> email;
                
            //     s1.apply_position(reg_num, student_name, branch, desc, job_code, email);
            //     cout << "Your Request has been successfully sent to the Division of Placement.\n Division of Placement" << endl;
            //     cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            //     break;


            //     case 6:
            //     cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            //     cout<<"\n\n\n\n";
            //     cout << "\t\t\t||========================================================================================================================================||"<<endl;
            //     cout << "\t\t\t\t Log request to Division of Placement                                                      Lovely Professional University, Phagwara" << endl;
            //     cout << "\t\t\t||========================================================================================================================================||"<<endl;  
                
            //     cout << "-- Enter the following Details (* means Mandatory) --" << endl;
            //     cout << "Registration number:* "; cin >> reg_num;
            //     cout << "Name:* "; cin >> student_name;
            //     cout << "Branch:*"; cin >> branch;
            //     cout << "Title:* "; cin >> log_title;
            //     cout << "Message: "; cin >> desc;
            //     s1.log_request(reg_num, student_name, branch, log_title, desc);
            //     cout << "Your Request has been successfully sent to the Division of Placement.\n Division of Placement" << endl;

            //     cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            //     break;

            //     default:
            //     cout << "Invalid Input";
            //     break;
            // }

            // s1.list_visited_companies(); // module for listing visited companies
            // s1.internships_available(); // module for listing internships available
            // s1.companies_today(); // module for listing out companies available today in the campus
            // s1.log_request("12212215", "Bhanupratap singh", "Computer Application",  "TEsting", "This module is I guess working file as of now"); // This module is to log request from the students
            // s1.get_announcements(); // to get all the announcements done by the division of placements
            // s1.apply_position("12212215", "Bhanupratap", "Computer Application", "I want to apply for this company.", "546", "pratapsinghbhanu444@gmail.com");
            return 0;
        }
        else if (user_input == 2) {
            cout << "Welcome to Division of Placements" << endl;
            // p1.placement_announcement("Bhnaupratap", "google is one of the biggest companies in the world", "Suraj pratap", "November 27"); // module for dropping announcements for students
            // p1.student_requests(); // module to see all the requests from user
            // p1.add_companies("Kindle", "24000", "Pouradhar", "Online", "4", "SDE", "879"); // to add companies in the campus
            // p1.add_visited_companies("XIaomi", "Balgladesh", "Commerce"); // all the numbers of companies visited companies
            // p1.placed_students(); // to list all the placed students
            // p1.registered_users(); // to list all the registered users in the placements 
            // p1.student_job_requests(); // to list all the job requests from the students 
            
            return 0;
        }
        else if (user_input == 3) {
            cout << "Bye Thankyou" << endl;
            return 1;
        }
        // else {
            cout << "Invalid Input" << endl;
            return -1;
        // }
        // return 2;

    }

};

int main() {
    bool start = true;
    int user_input, ret_val;
    while (start) {
        cout << endl;
        InitialOpening pStarts;
        cin >> user_input;
        ret_val = pStarts.indexPage(user_input);
        if (ret_val == 1) start = false;
        cout << ret_val << endl;

        // create a about this project page
    }
}