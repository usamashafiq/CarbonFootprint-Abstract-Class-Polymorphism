#include<iostream>
using namespace std;
class Carbonfootprint{
	public:
		virtual double getCarbonFootprint()=0;
};
class Building:public Carbonfootprint{
	private:
		double people;
		double carbn_pr_prsn;
		double equipment;
		double carbn_pr_eqp;
	public:
		Building(double ,double, double, double);
		virtual double getCarbonFootprint();	
};
Building::Building(double p,double c,double e,double q){
	people=p;
	carbn_pr_prsn=c;
	equipment=e;
	carbn_pr_eqp=q;
}
double Building::getCarbonFootprint(){
	double ans;
	ans=(people*carbn_pr_prsn)+(equipment*carbn_pr_eqp);
	return ans;
}
class Car:public Carbonfootprint{
	private:
		double people;
		double carbn_pr_prsn;
		double carbn_pr_vhcl;
		double no_of_cars;
	public:
		Car(double ,double ,double ,double);
		virtual double getCarbonFootprint();	
};
Car::Car(double p,double c,double q,double n){
	people=p;
	carbn_pr_prsn=c;
	carbn_pr_vhcl=q;
	no_of_cars=n;
}
double Car::getCarbonFootprint(){
	double ans;
	ans=(people*carbn_pr_prsn)+(no_of_cars*carbn_pr_vhcl);
	return ans;
}
class Bicycle:public Carbonfootprint{
	private:
		double people;
		double carbn_pr_prsn;
	public:
		Bicycle(double ,double );
		virtual double getCarbonFootprint();	
};
Bicycle::Bicycle(double p,double c){
	people=p;
	carbn_pr_prsn=c;
}
double Bicycle::getCarbonFootprint(){
	double ans;
	ans=people*carbn_pr_prsn;
	return ans;
}
int main(){
	Carbonfootprint *fp[3];
	cout<<"Carbon Dioxide Released by each person daily is 200.67 Pounds"<<endl;
	cout<<"Carbon Dioxide Released by each Equipment daily is 400.34 Pounds"<<endl;
	cout<<"Carbon Dioxide Released by each Vehicle daily is 600.86 Pounds"<<endl;
	cout<<"Number of Person in Bulding are 8"<<endl;
	cout<<"Number of Equipments in the Building are 4"<<endl;
	cout<<"Numbers of Vehicles are 3"<<endl<<endl;
	cout<<"------------------------------------------"<<endl<<endl;
	Building b(8,200.67,4,400.34);
	Car c(4,200.67,3,600.86);
	Bicycle l(1,200.67);
	fp[0]=&b;
	fp[1]=&c;
	fp[2]=&l;
	cout<<"Daily Carbon FootPrints Released by Bulding : ";
	cout<<fp[0]->getCarbonFootprint()<<" Pounds"<<endl<<endl;
	cout<<"Daily Carbon FootPrints Released by Cars : ";
	cout<<fp[1]->getCarbonFootprint()<<" Pounds"<<endl<<endl;
	cout<<"Daily Carbon FootPrints Released by Bicycle : ";
	cout<<fp[2]->getCarbonFootprint()<<" Pounds";
return 0;
}
