#include<iostream>
#include<string.h>
using namespace std;

class myhome {
	// friend class friendhome;
public:
	myhome() {
		cout << "myhome的构造函数" << endl;
		room = "xclroom";
		// badroom = "xclbadroom";
	}
	string room;


	~myhome() {
		cout << "myhome的析构函数" << endl;
	}

private:
	// string badroom;
};


class friendhome {
public:
	
	friendhome() {
		cout << "friendhome的构造函数" << endl;
		m = new myhome;
	}
	
	void visite() {
		cout << "myfriend home " << m->room << endl;
		// cout << "myfriend home " << m->badroom << endl;
	}

	~friendhome() {
		cout << "friendhome的析构函数" << endl;
	}
private:
	myhome *m;
	
};

void test() {
	friendhome f;
	f.visite();
}

int main() {
	test();
	return 0;
}