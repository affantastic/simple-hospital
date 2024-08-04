#include <iostream>
using namespace std;
class Person{
protected:
    string name;
    int age;
public:
    Person(string n, int a){
        name=n;
        age=a;
    }
    void displayDetails(){
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
    }
    string getName()const{
        return name;
    }
};
class Doctor: public Person{
protected:
    string specialization;
public:
    Doctor(string s, string n, int a):Person(n,a){
        specialization=s;
    }
    void displayDetails(){
        Person::displayDetails();
        cout<<"Specialization : "<<specialization<<endl;
    }
    void prescribeMed(string med){
        cout<<"Doctor"<<name<<"has prescribed "<<med<<endl;
    }
    void conductExamination(Person &patient){
        cout<<"Doctor"<<name<<"is conducting an examination on"<<patient.getName()<<endl;
    }
};
class Patient: public Person{
protected:
    string ailment;
public:
    Patient(string l, string n, int a):Person(n,a){
        ailment=l;
    }
    void displayDetails(){
        Person::displayDetails();
        cout<<"Ailment : "<<ailment<<endl;
    }
    void requestAppointment(){
        cout<<name<<" is requesting an appointment"<<endl;
    }
    void undergoTreatment(string treatment){
        cout<<name<< "is undergoing "<<treatment<<endl;
    }
};
class Hospital:public Doctor, public Patient{
private:
    static const int MAX_PATIENTS = 100;
    Patient* patients[MAX_PATIENTS];
    int numPatients;

public:
    Hospital(){
        numPatients=0;
    }
    void admitPatient(Patient* patient) {
        if (numPatients < MAX_PATIENTS) {
            patients[numPatients++] = patient;
            cout << "Patient admitted to the hospital." << endl;
        } else {
            cout << "Hospital is full, cannot admit more patients." << endl;
        }
    }

    void displayPatientDetails() {
        cout << "Patient Details:" << endl;
        for (int i = 0; i < numPatients; ++i) {
            cout << (i + 1) << ". ";
            patients[i]->displayDetails();
        }
    }
};
main(){
    Doctor doc1("Greggory House",44,"Diagnostics");
    Patient pat1("Adams",32,"Huntington's");
    doc1.displayDetails();
    pat1.displayDetails();
    Hospital hospital(10);
    hospital.admitPatient(pat1);
    hospital.assignDoctor(pat1, doc1);
    pat1.requestAppointment();
    doc1.conductExamination(pat1);
    doc1.prescribeMedication("Tetrabenazine");
    pat1.undergoTreatment("Exercise and Medication");
    hospital.displayPatientDetails();
}
