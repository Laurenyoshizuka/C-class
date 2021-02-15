//
//  Header.h
//  Practical 7
//
//  Created by Lauren Yoshizuka on 15/02/2021.
//

#ifndef ex1_header_h
#define ex1_header_h

#include <vector>
#include <string>
#include <list>

using namespace std;

namespace bloodPressures {

class Date {
    
private:
    int day;
    int month;
    int year;
    
public:
    
    Date(){
        this -> day = 0;
        this -> month = 0;
        this -> year = 0000;
    }
    Date(const int day, const int month, const int year){
        this -> day = day;
        this -> month = month;
        this -> year = year;
    }
    
    string getDate() {
        string strday = to_string(day);
        string strmonth = to_string(month);
        string stryear = to_string(year);
        return strday + "/" + strmonth + "/" + stryear;
    }
    
};

class Blood{
    
private:
    int systolic;
    int diastolic;
    Date date;
    vector<string> vect;
    
public:
    
    Blood(){
        this -> systolic = 0;
        this -> diastolic = 0;
        this -> date = Date();
    }
    
    Blood(const int systolic, const int diastolic, const Date date){
        this -> systolic = systolic;
        this -> diastolic = diastolic;
        this -> date = date;
    }
    
    int getSystolic(){return this -> systolic;}
    int getDiastolic(){return this -> diastolic;}
    string getDate(){return date.getDate();}
    
    virtual void printData(){
        string strSystolic = to_string(systolic);
        string strDiastolic = to_string(diastolic);
        this -> vect.push_back(strSystolic);
        this -> vect.push_back(strDiastolic);
        this -> vect.push_back(date.getDate());
        cout << vect[0] << " " << vect[1] << " " << vect[2] << endl;
    }
};

class Patient{
    
private:
    string first_name;
    Blood blood;
    vector<int> vectSystolic;
    vector<int> vectDiastolic;
    vector<string> vectDate;
    list<int> maxPressure;
    
public:
    Patient(){this -> first_name = "John";}
    
    Patient (string first_name){
        this -> first_name = first_name;
        cout << first_name << "'s blood pressure report." << endl;
        cout << "Systolic: " << "Diastolic: " << "Date: " << endl;
    }
    
    virtual void addRecord(Blood blood){
        this -> vectSystolic.push_back(blood.getSystolic());
        this -> vectDiastolic.push_back(blood.getDiastolic());
        this -> vectDate.push_back(blood.getDate());
        blood.printData();
    }
    
    virtual const void printReport(){
        cout << "REPORT:" << endl;
        
        // max systolic pressure reading
        int maxSystolic = 0;
        for (int index = 0; index < vectSystolic.size(); ++index){
            if (vectSystolic[index+1] > vectSystolic[index]){
                maxSystolic = index+1;}
            }
        if (vectSystolic[maxSystolic] > 140){
            cout << "Warning! Some systolic measurements are above 140." << endl;
            cout << "Max systolic blood pressure reading: " << vectDate[maxSystolic] << endl;
        }
        else {cout << "No measurement was too high." << endl;}
        
        // average diastolic pressure reading
        int sum = 0;
        for (int index = 0; index < vectSystolic.size(); ++index){
            sum += vectDiastolic[index];}
        int average = sum/vectSystolic.size();
        cout << "Average diastolic pressure reading: " << average << endl;
        
        // the list (possibly containing a single element) of maximal pressure records for a patient
        int maxDiastolicIndex = 0;
        int maxDiastolic = 0;
        for (int index =0; index < vectDiastolic.size(); ++index){
            if (vectDiastolic[index] > maxDiastolic){
                maxDiastolicIndex = index;
                maxDiastolic = vectDiastolic[index];
            }
        }
        
        maxPressure.push_back(maxSystolic);
        if (maxDiastolicIndex == maxSystolic){}
        else {maxPressure.push_back(maxDiastolicIndex);}
        cout << "Maximal pressure readings: " << endl;
        for (list <int> ::iterator i = maxPressure.begin(); i != maxPressure.end(); ++i){
            cout << vectDate[*i] << " systolic: " << vectSystolic[*i] << " diastolic: " <<
            vectDiastolic[*i] << endl;
        }
        
        cout << "----END OF REPORT----" << endl;
        }
};
    
}


#endif /* ex1_header_h */
