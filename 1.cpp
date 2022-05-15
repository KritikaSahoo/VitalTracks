#include <iostream>
#include <fstream>
using namespace std;

// class that stores data
class patient
{
    int patient_id;
    string date;
    char name[50];
    char mental_health[150];
    char extra[150];
    double height, weight, blood_pressure_sys, blood_pressure_dias, sugar_fasting, sugar_post_meal;
    string choice1,choice2,choice3,choice4;
    float red_cell_count,white_cell_count,haemoglobin,pH,glucose,protein,bilirubin,blood,leukocytes;
    float BMI;
    string ht_wt_check,BP_check,sugar_check,CBC_check,urine_check;
    

public:
    void getdata();
    void showdata() const;
    void calculate();
    int retpatientid() const;
};
// class ends here
void patient::calculate()
{
    BMI=(weight/(height*height));
    if(BMI <= 18.5)
    ht_wt_check="underweight";
    else if(BMI>18.5 && BMI <= 24.9)
    ht_wt_check="normal weight";
    else if(BMI>24.9 && BMI <= 29.9)
    ht_wt_check="overweight";
    else if(BMI>29.9 && BMI <=34.9)
    ht_wt_check="class I obesity";
    else if(BMI>34.9 && BMI <=39.9)
    ht_wt_check="class II obesity";
    else
    ht_wt_check="class III obesity";

    if(blood_pressure_sys <= 120 && blood_pressure_dias <80)
    BP_check = "Healthy";
    else if((blood_pressure_sys>120 && blood_pressure_sys <= 129) && blood_pressure_dias <80)
    BP_check = "Elevated";
    else if((blood_pressure_sys>129 && blood_pressure_sys <= 139) && (blood_pressure_dias >80 && blood_pressure_dias <= 89))
    BP_check = "Stage I hypertension";
    else if(blood_pressure_sys>=140 && blood_pressure_dias >= 90)
    BP_check = "Stage II hypertension";
    else if(blood_pressure_sys>=180 && blood_pressure_dias >= 120)
    BP_check = "Hypertension crisis"; 
    else
    BP_check = "Abnormal";

    if((sugar_fasting>=70 && sugar_fasting<=100) && (sugar_post_meal>=70 && sugar_post_meal<=140))
    sugar_check="Normal";
    else if((sugar_fasting>100 && sugar_fasting<=125) && (sugar_post_meal>140 && sugar_post_meal<=200))
    sugar_check="Pre-Diabetes";
    else if((sugar_fasting>125) && (sugar_post_meal>200))
    sugar_check="Diabetes";
    else
    sugar_check="Abnormal";

    if(choice1 == "yes" || choice1 == "YES")
    {
    if((red_cell_count>=4.5 && red_cell_count<=5.7) && (white_cell_count>=4.0 && white_cell_count<=10.0) && (haemoglobin>=133 && haemoglobin<=167))
    {
    CBC_check="Normal";
    }
    else
    {
    CBC_check="Abnormality consult doctor";
    }
    }

    if(choice2 == "yes" || choice2 == "YES")
    {
    if((pH>=5 && pH<=9) && (glucose<20) && (protein<20) && (bilirubin<1.80) && (blood<0.02) && (leukocytes>=15 && leukocytes <=40))
    {
    urine_check="Normal";
    }
    else
    {
    urine_check="Abnormal consult doctor";
    }
    }
}
void patient::getdata()
{
    cout << "\nEnter patient ID: "<<endl<<"(Write ID as per the given example:-"<<endl<<"(Date+report number, Example- 5thmarch2022 with report number 2 as '050320222'): ";
    cin>>patient_id;
    cout << "\nEnter date of report:-"<<endl<<"(Write date as per the given example:-"<<endl<<"Example- 5th march 2022 as '05/03/2022'): ";
    cin >> date;
    cout << "\n\nEnter patient name: ";
    cin.ignore();
    cin.getline(name, 50);
    cout<<endl<<"Enter the following patient's medical test details carefully:- "<<endl<<"(All are compulsary):- ";
    cout<<endl<<"Enter height of the patient(in metres): ";
    cin>>height;
    cout<<endl<<"Enter weight of the patient(in kgs): ";
    cin>>weight;
    cout<<endl<<"Enter systolic blood pressure of the patient(in mm hg): ";
    cin>>blood_pressure_sys;
    cout<<endl<<"Enter diastolic blood pressure of the patient(in mm hg): ";
    cin>>blood_pressure_dias;;
    cout<<endl<<"Enter before meal blood sugar levels of the patient(in mg/dl): ";
    cin>>sugar_fasting;
    cout<<endl<<"Enter after meal bllod sugar levels of the patient(in mg/dl): ";
    cin>>sugar_post_meal;
    cout<<endl<<"Enter the following patient's medical test details carefully ,type 'yes' or 'no' accordingly:- "<<endl<<"(All are optional):- ";    
    cout<<endl<<"Do you want to enter your CBC(complete blood count) Test report data?(yes/no): ";
    cin.ignore();
    cin>>choice1;
    if(choice1 == "yes" || choice1 == "YES")
    {
        cout<<endl<<"Red cell count (x 10^12/L ): ";
        cin>>red_cell_count;
        cout<<endl<<"White cell count (x 10^9/L): ";
        cin>>white_cell_count;
        cout<<endl<<"Haemoglobin (x g/L): ";
        cin>>haemoglobin;
    } 
    else if(choice1 == "no"|| choice1 == "NO")
    {
        cout<<endl<<"Okay!";
    } 
    cout<<endl<<"Do you want to enter your Urine Test report data? (yes/no): ";
    cin.ignore();
    cin>>choice2;
    if(choice2 == "yes" || choice2 == "YES")
    {
        cout<<endl<<"pH (x pH ): ";
        cin>>pH;
        cout<<endl<<"Glucose (x mg/dL): ";
        cin>>glucose;
        cout<<endl<<"Protein (x mg/dL): ";
        cin>>protein;
        cout<<endl<<"Bilirubin (x mg/dL): ";
        cin>>bilirubin;
        cout<<endl<<"Blood (x mg/L): ";
        cin>>blood;
        cout<<endl<<"Leukocytes (x WBCs u/L): ";
        cin>>leukocytes;
    } 
    else if(choice2 == "no"|| choice2 == "NO")
    {
        cout<<endl<<"Okay!";   
    }
    cout<<endl<<"Do you want to brief about your mental health status?(yes/no): ";
    cin.ignore();
    cin>>choice3;
    if(choice3 == "yes"|| choice3 == "YES")
    {
        cin.ignore();
        cin.getline(mental_health,150);
    }
    else if(choice3 == "no"|| choice3 == "NO")
    {
        cout<<endl<<"Okay!";
    }
    calculate();
}
void patient::showdata() const
{
    cout<<endl<<"Patient's ID: "<<patient_id;
    cout<<endl<<"Report Date: "<<date;
    cout<<endl<<"Patient's Name: "<<name;

    cout<<endl<<endl<<"Height: "<<height;
    cout<<endl<<"Weight: "<<weight;
    cout<<endl<<"Body Mass Index(BMI): "<<BMI;
    cout<<endl<<"Body mass Index(BMI) Status: "<<ht_wt_check;

    cout<<endl<<endl<<"Systolic Blood Pressure/Diastolic Blood Pressure: "<<blood_pressure_sys<<"/"<<blood_pressure_dias;
    cout<<endl<<"Blood Pressure Status: "<<BP_check;

    cout<<endl<<endl<<"Fasting Blood Sugar Level/Post Meal Blood Sugar Level: "<<sugar_fasting<<"/"<<sugar_post_meal;
    cout<<endl<<"Sugar Level Status: "<<sugar_check;
    
    if(choice1 == "yes" || choice1 =="YES")
    {
    cout<<endl<<endl<<"Complete Blood Count(CBC) Report:- ";
    cout<<endl<<"Red cell count (x 10^12/L ): "<<red_cell_count;
    cout<<endl<<"White cell count (x 10^9/L): "<<white_cell_count;
    cout<<endl<<"Haemoglobin (x g/L): "<<haemoglobin;
    cout<<endl<<"CBC Test Status: "<<CBC_check;
    }

    if(choice2 == "yes" || choice2 == "YES")
    {
    cout<<endl<<endl<<"Urine Report:- ";
    cout<<endl<<"pH (x pH ): "<<pH;
    cout<<endl<<"Glucose (x mg/dL): "<<glucose;
    cout<<endl<<"Protein (x mg/dL): "<<protein;
    cout<<endl<<"Bilirubin (x mg/dL): "<<bilirubin;
    cout<<endl<<"Blood (x mg/L): "<<blood;
    cout<<endl<<"Leukocytes (x WBCs u/L): "<<leukocytes;
    cout<<endl<<"Urine Test Status: "<<urine_check;
    }
    
    if(choice3 == "yes"|| choice3 =="YES")
    {
    cout<<endl<<endl<<"Mental Health Status: "<<mental_health;
    }
}
int patient::retpatientid() const
{
    return patient_id;
}
//function declaration
void create_patient();
void display_all(); // display all records
void delete_patient(int);//delete particular record
//MAIN
int main()
{
char ch;
do
{
char ch;
int num;
system("cls");
cout<<"\n\n\n\tMENU";
cout<<"\n\n\t1.Create patient record";
cout<<"\n\n\t2.Display all patients records ";
cout<<"\n\n\t3.Delete patient record";
cout<<"\n\n\t4.Exit";
cout<<endl<<endl<<"What is your Choice (1/2/3/4)? :  ";
cin>>ch;
system("cls");
switch(ch)
{
case '1': create_patient(); break;
case '2': display_all(); break;
case '3': cout<<"\n\n\tEnter patient ID: "; 
cin>>num;
delete_patient(num);break;
case '4': cout<<"Exiting, Thank you!";exit(0);
}
}while(ch!='6');
return 0;
}
//write student details to file
void create_patient()
{
patient stud;
ofstream oFile;
oFile.open("patient.dat",ios::binary|ios::app);
stud.getdata();
oFile.write(reinterpret_cast<char *> (&stud), sizeof(patient));
oFile.close();
     cout<<"\n\npatient record Has Been Created ";
cin.ignore();
cin.get();
}
// read file records
void display_all()
{
patient stud;
ifstream inFile;
inFile.open("patient.dat",ios::binary);
if(!inFile)
{
cout<<"File could not be opened !! Press any Key to exit";
cin.ignore();
cin.get();
return;
}
cout<<"\n\n\n\t\tDISPLAYING ALL RECORDS\n\n";
while(inFile.read(reinterpret_cast<char *> (&stud), sizeof(patient)))
{
stud.showdata();
cout<<"\n\n====================================\n";
}
inFile.close();
cin.ignore();
cin.get();
}
//delete record with particular roll number
void delete_patient(int n)
{
patient stud;
ifstream iFile;
iFile.open("patient.dat",ios::binary);
if(!iFile)
{
cout<<"File could not be opened... Press any Key to exit...";
cin.ignore();
cin.get();
return;
}
ofstream oFile;
oFile.open("Temp.dat",ios::out);
iFile.seekg(0,ios::beg);
while(iFile.read(reinterpret_cast<char *> (&stud), sizeof(patient)))
{
if(stud.retpatientid()!=n)
{
oFile.write(reinterpret_cast<char *> (&stud), sizeof(patient));
}
}
oFile.close();
iFile.close();
remove("patient.dat");
rename("Temp.dat","patient.dat");
cout<<"\n\n\tRecord Deleted ..";
cin.ignore();
cin.get();
}