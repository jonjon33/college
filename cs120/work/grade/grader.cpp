/*****************************
Jonathan Hanson
CS 120 - 01
October 11, 2013
Assignment #6

This program functions properly, printing
student ID numbers, the averages of each
part of the course in percents (test, quiz,
and final out of 100), the weighted course
average, and a letter grade for each student.
Then it prints the total class average.

*****************************/
#include<iostream>
using namespace std;

class student{
public:
	int sn;
	float ta;
	float qa;
	float ca;
	int t[3];
	int q[8];
	int f;
	char grade;
	
	float calcavg(int,int);
	char dograde();
};


int main(){
	int i,j;
	float classavg;
	float test_weight = 0.45;
	float quiz_weight = 0.30;
	float final_weight = 0.25;
	student s[11];

//////// TAKE INPUT ////////
	for(i=0;i<11;i++){
		cin >> s[i].sn;
		for(j=0;j<3;j++){
			cin >> s[i].t[j];
		}
		for(j=0;j<8;j++){
			cin >> s[i].q[j];
		}
		cin >> s[i].f;
	}

//////// DO AVERAGES ////////
	for(i=0;i<11;i++){
		s[i].ta = s[i].calcavg(3,300);
	}
	for(i=0;i<11;i++){
		s[i].qa = s[i].calcavg(8,84);
	}
	for(i=0;i<11;i++){
		s[i].ca = s[i].ta * test_weight + s[i].qa * quiz_weight + s[i].f * final_weight;
	}
	classavg = (s[1].ca + s[2].ca + s[3].ca + s[4].ca + s[5].ca + s[6].ca + s[7].ca + s[8].ca + s[9].ca + s[10].ca)/10.;

//////// GET GRADE ////////
	for(i=0;i<11;i++){
		s[i].grade = s[i].dograde();
	}

//////// OUTPUT ////////
	cout << "Class Grades (with Weighted Totals)\n";
	cout << "ID #\tT Avg\tQ Avg\tFinal\tTotal\tGrade\n";	
	for(i=1;i<11;i++){
		cout << s[i].sn << "\t" << s[i].ta << "\t" << s[i].qa << "\t" << s[i].f << "\t" << s[i].ca << "\t" << s[i].grade << endl;
	}
	cout << "\t\tClass Average\t" << classavg << endl;
}



float student::calcavg(int num, int max){
	int i;
	int sum = 0;
	float avg;
	if(num==3){
		for(i=0;i<num;i++) sum += t[i];
		avg = (float(sum)/float(max))*100;
	}
	if(num==8){
		for(i=0;i<num;i++) sum += q[i];
		avg = (float(sum)/float(max))*100;
	}
	return avg;
}

char student::dograde(){
	if(ca >= 90.) return 'A';
	if(90. > ca && ca >= 80.) return 'B';
	if(80. > ca && ca >= 70.) return 'C';
	if(70. > ca && ca >= 60.) return 'D';
	if(60. > ca) return 'F';
}
