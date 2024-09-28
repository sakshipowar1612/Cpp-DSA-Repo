#include<iostream>
#include<fstream>
#include<string.h>
#include<sstream>
#include<string>
#include <cstdlib>

using namespace std;

ofstream outf;
ifstream myFileStream;

class contactNode
{
	long long int number;
	char fname[20], lname[20];
	char* email; // Pointer to email
	contactNode *left, *right;

	contactNode() : email(nullptr), left(nullptr), right(nullptr) {} // Initialize email to nullptr

	~contactNode() {
		if (email) {
			delete[] email;
		}
	}

	friend class tree;
};

class tree
{
public:
	contactNode *root;

	tree() {
		root = nullptr;
	}

	void create2(contactNode *p) {
		contactNode *parent;
		contactNode *tmp = root;
		p->left = nullptr;
		p->right = nullptr;
		if (root == nullptr) {
			root = p;
		} else {
			while (tmp != nullptr) {
				parent = tmp;
				if (strcmp(p->fname, tmp->fname) < 0)
					tmp = tmp->left;
				else
					tmp = tmp->right;
			}
			if (strcmp(p->fname, parent->fname) < 0)
				parent->left = p;
			else
				parent->right = p;
		}
	}

	void create() {
		int k = 0;
		contactNode *tmp, *p, *parent = nullptr;
		tmp = root;
		p = new contactNode();

		cout << "\nFirst Name: ";
		cin >> p->fname;
		cout << "\nLast Name: ";
		cin >> p->lname;

		do {
			cout << "\nPhone number: ";
			cin >> p->number;
			k = numchck(p->number);
		} while (k != 1);

		char emailOption;
		cout << "\nDo you want to add an Email-ID? (y/n): ";
		cin >> emailOption;

		if (emailOption == 'y' || emailOption == 'Y') {
			char emailInput[40];
			do {
				cout << "\nEmail-ID: ";
				cin >> emailInput;
				k = mailchck(emailInput);
			} while (k != 1);

			p->email = new char[strlen(emailInput) + 1];
			strcpy(p->email, emailInput);
		}

		p->left = nullptr;
		p->right = nullptr;

		if (root == nullptr) {
			root = p;
		} else {
			while (tmp != nullptr) {
				parent = tmp;
				if (strcmp(p->fname, tmp->fname) < 0)
					tmp = tmp->left;
				else
					tmp = tmp->right;
			}
			if (strcmp(p->fname, parent->fname) < 0)
				parent->left = p;
			else
				parent->right = p;
		}
	}

	int numchck(long long int d) {
		int c = 0;
		while (d > 0) { c++; d /= 10; }
		if (c == 10) return 1;
		cout << "Number Invalid";
		return 0;
	}

	int mailchck(char a[]) {
		int j = 0, i = 0;
		while (a[i] != '\0') {
			if (a[i] == '@') j++;
			i++;
		}
		if (j == 1) return 1;
		cout << "Email id Invalid";
		return 0;
	}

	void inorder() {
		inordertrav(root);
	}

	void inordertrav(contactNode *t) {
		if (t != nullptr) {
			inordertrav(t->left);
			cout << "\nContact Details:\n";
			cout << "First name: " << t->fname << "\tLast name: " << t->lname;
			cout << "\nPhone Number: " << t->number;
			if (t->email) {
				cout << "\tEmail id: " << t->email;
			} else {
				cout << "\tEmail id: Not provided";
			}
			inordertrav(t->right);
		}
	}

	contactNode* minValueNode(contactNode* l) {
		contactNode* current = l;
		while (current && current->left != nullptr)
			current = current->left;
		return current;
	}

	contactNode* deleteNode(contactNode* root, char a[20]) {
		if (root == nullptr) return root;

		if (strcmp(a, root->fname) < 0)
			root->left = deleteNode(root->left, a);
		else if (strcmp(a, root->fname) > 0)
			root->right = deleteNode(root->right, a);
		else {
			if (root->left == nullptr) {
				contactNode *temp = root->right;
				delete root;
				return temp;
			} else if (root->right == nullptr) {
				contactNode *temp = root->left;
				delete root;
				return temp;
			}

			contactNode* temp = minValueNode(root->right);
			root->number = temp->number;
			strcpy(root->lname, temp->lname);
			strcpy(root->fname, temp->fname);
			if (temp->email) {
				root->email = new char[strlen(temp->email) + 1];
				strcpy(root->email, temp->email);
			} else {
				root->email = nullptr;
			}
			root->right = deleteNode(root->right, temp->fname);
		}
		return root;
	}

	contactNode* edit(contactNode* root, char a[]) {
		if (root == nullptr) return root;

		if (strcmp(a, root->fname) < 0)
			root->left = edit(root->left, a);
		else if (strcmp(a, root->fname) > 0)
			root->right = edit(root->right, a);
		else {
			int x;
			cout << "Enter the data choice to edit:\n1.First name\t2.Last name\t3.Phone number\t4.Email id:\n";
			cin >> x;
			cout << "\nEnter the new value:";
			switch (x) {
			case 1:cin >> root->fname; break;
			case 2:cin >> root->lname; break;
			case 3:cin >> root->number; break;
			case 4: 
				if (root->email) delete[] root->email;
				root->email = new char[40];
				cin >> root->email; 
				break;
			default: cout << "Value not modified";
			}
		}
		return root;
	}

	void searc(contactNode* root, char a[]) {
		if (root) {
			if (strcmp(a, root->fname) < 0)
				searc(root->left, a);
			else if (strcmp(a, root->fname) > 0)
				searc(root->right, a);
			else {
				cout << "\nContact Details:\n";
				cout << "First name: " << root->fname << "\tLast name: " << root->lname;
				cout << "\nPhone Number: " << root->number;
				if (root->email) {
					cout << "\tEmail id: " << root->email;
				} else {
					cout << "\tEmail id: Not provided";
				}
			}
		}
	}

	void filee(contactNode* t) {
		if (t != nullptr) {
			filee(t->left);
			outf << t->fname << " " << t->lname << " " << t->number << " ";
			if (t->email) {
				outf << t->email;
			}
			outf << "\n";
			filee(t->right);
		}
	}

	void writeExisting() {
		string num, line, fname, lname, email;
		myFileStream.open("Contacts.txt");
		if (!myFileStream.is_open()) {
			cout << "File failed to open" << endl;
			return;
		}

		contactNode *tmp, *p, *parent = nullptr;
		tmp = root;

		while (getline(myFileStream, line)) {
			p = new contactNode();
			stringstream ss(line);
			getline(ss, fname, ' ');
			getline(ss, lname, ' ');
			getline(ss, num, ' ');
			p->number = atoll(num.c_str());
			getline(ss, email, ' ');

			strcpy(p->fname, fname.c_str());
			strcpy(p->lname, lname.c_str());

			if (!email.empty()) {
				p->email = new char[email.length() + 1];
				strcpy(p->email, email.c_str());
			}

			create2(p);
		}
		myFileStream.close();
	}
};

int main() {
	tree q;
	char c, a[20];
	int x;
	q.writeExisting();
	cout << "\nCreation Successful\n";
	do {
		cout << "Enter the choice :\n1.Insert\n2.Delete\n3.Edit\n4.Search\n5.Print Phone book\n6.Exit\n";
		cin >> x;
		switch (x) {
		case 1: q.create(); break;
		case 2: 
			cout << "\nEnter the contact name to be deleted : "; 
			cin >> a;
			q.root = q.deleteNode(q.root, a); 
			break;
		case 3: 
			cout << "\nEnter the contact name to be edited : "; 
			cin >> a; 
			q.root = q.edit(q.root, a); 
			break;
		case 4: 
			cout << "\nEnter the contact name to be searched : "; 
			cin >> a; 
			q.searc(q.root, a); 
			break;
		case 5: 
			q.inorder(); 
			break;
		case 6: 
			outf.open("Contacts.txt");
			q.filee(q.root); 
			outf.close(); 
			exit(0);
		default: 
			cout << "Invalid choice.";
		}
		cout << "\nDo you want to continue? (y/n): "; 
		cin >> c;
	} while (c == 'y' || c == 'Y');
	return 0;
}
