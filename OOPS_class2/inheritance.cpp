#include<iostream>
#include<string>
using namespace std;

class Bird{
	public:
	int age, weight;//months and grams
	string color;
	int nol;

	void eat(){
		cout << "Bird is eating" << endl;	
	}
	void doesfly(){
		cout << "Bird is flying" << endl;
	}
	
};

class Sparrow : public Bird{
	public:
	Sparrow(int age, int weight, string color, int nol){
		this->age = age;
		this->weight = weight;
		this->color = color;
		this->nol = nol;
	}
	void grassing(){
		cout << "sparrow is grassing" << endl;	
	}


};

class Pegion : public Bird{
	public:
	void guttering(){
		cout << "pegion is guttering" << endl;	
	}


};

int main(){
	Sparrow s1(6, 750, "Brown", 2);
	cout << "Sparrows age: " << s1.age << " weight: " << s1. weight << " color: " << s1.color << " no. of legs" << s1.nol << endl;
	s1.eat();
	s1.doesfly();
	s1.grassing();
	

	return 0;
}

