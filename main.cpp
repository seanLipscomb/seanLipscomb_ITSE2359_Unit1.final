#include <iostream>
#include <fstream>

using namespace std;

int main(){
ifstream inFile("student_data.txt");
int size = 53;
string names[53];
int ages[53];
int oldest = 0;
int youngest = 99;
float gpas[53];
float totalGPA = 0;
float averageGPA;
float highGrade = 0;
string oldStudent;
string youngStudent;
string bestStudents;
/*this statement lets me know if the file I'm trying to read DNE*/
if (!inFile){
    cerr << "File could not be opened!" << endl;
}
/*this loop feeds data into my parallel arr ays*/
for (int i = 0; i < size; ++i){
    inFile >> names[i];
    inFile >> ages[i];
    inFile >> gpas[i];
}
/*this loop finds the class total GPA*/
for (int i = 0; i < size; ++i){
    totalGPA += gpas[i];
}
/*this expression finds the average GPA of the whole class*/
averageGPA = totalGPA / size;
/*this loop stores highest grade to a floating point variable, stores the oldest and youngest students' ages into integer variables*/
for (int i = 0; i < size; ++i){
    if (gpas[i] >= highGrade){
        highGrade = gpas[i];
    }
    if (ages[i] >= oldest){
        oldest = ages[i];
    }
    if (ages[i] <= youngest){
        youngest = ages[i];
    }
}
/*this loops adds the students' names with the highest scores to a string variable,
then compares the oldest and youngest ages in the class against the names of the students
and stores the oldest and youngest students' names into string variables. It does assume that there are multiple of each.*/
for (int i = 0; i < size; ++i){
    if (gpas[i] == highGrade){
        bestStudents += names[i] + ", ";
    }
    if (ages[i] == oldest){
        oldStudent += names[i] + ", ";
    }
    if (ages[i] == youngest){
        youngStudent += names[i] + ", ";
    }
}

inFile.close();
/*making sure all of my arrays are filled properly
for (int i = 0; i < size; ++i){
    cout << names[i] << ages[i] << gpas[i] << endl;
}
*/
cout << "The average GPA for this class is " << averageGPA << endl;
cout << "The highest grade achieved in this class was achieved by " << bestStudents << "at a GPA of " << highGrade << "." << endl;
cout << "The oldest students are " << oldStudent << "and they are " << oldest << "." << endl;
cout << "The youngest students are " << youngStudent << "and they are " << youngest << "." << endl;
return 0;
}