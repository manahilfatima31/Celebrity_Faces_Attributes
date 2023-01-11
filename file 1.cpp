#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

class AttrNode
{
public:
	string data;
	AttrNode* next;
	AttrNode* prev;
	AttrNode()
	{
		data = "";
		next = NULL;
		prev = NULL;
	}

	AttrNode(string d, AttrNode* n)
	{
		data = d;
		next = n;
		prev = NULL;
	}
};
class AttrList
{
public:
	AttrNode* head;
	AttrNode* tail;

	AttrList()
	{
		head = NULL;
		tail = NULL;
	}
	void InsertStart(string data)
	{
		AttrNode* nnode = new AttrNode(data, NULL);

		nnode->next = head;
		nnode->prev = NULL;
		head->prev = nnode;
		head = nnode;
	}
	void InsertEnd(string data)
	{
		AttrNode* nnode = new AttrNode(data, NULL);

		if (head == NULL)
		{
			nnode->prev = NULL;
			head = nnode;
			return;
		}

		AttrNode* temp = head;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = nnode;
		nnode->prev = temp;
	}


	void print()
	{
		AttrNode* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " | ";
			temp = temp->next;
		}
		cout << "\n";
	}
	void print_rev()
	{
		AttrNode* temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		while (temp != NULL)
		{
			cout << temp->data << " | ";
			temp = temp->prev;
		}
		cout << "\n";
	}

	bool Checker(string attr1)
	{
		AttrNode* temp = head;
		bool flag = false;
		int count = 1;
		if (attr1 == "Arched_Eyebrows")
		{
			if (head->data == "1" && head->next->data == "1")
			{
				//cout << "In question:  " << head->data << " AND:   " << head->next->data << endl;
				return true;
			}
		}
		else if (attr1 == "Bags_Under_Eyes")
		{
			while (temp->next != NULL)
			{
				if (count == 3)
				{
					if (temp->data == "1" && head->next->data == "1")
					{
						return true;
					}
				}
				count++;
				temp = temp->next;
			}
		}
		else if (attr1 == "Big_Lips")
		{
			while (temp->next != NULL)
			{
				if (count == 4)
				{
					if (temp->data == "1" && head->next->data == "1")
					{
						return true;
					}
				}
				count++;
				temp = temp->next;
			}
		}
		else if (attr1 == "Black_Hair")
		{
			while (temp->next != NULL)
			{
				if (count == 5)
				{
					if (temp->data == "1" && head->next->data == "1")
					{
						return true;
					}
				}
				count++;
				temp = temp->next;
			}
		}
		else if (attr1 == "Blond_Hair")
		{
			while (temp->next != NULL)
			{
				if (count == 6)
				{
					if (temp->data == "1" && head->next->data == "1")
					{
						return true;
					}
				}
				count++;
				temp = temp->next;
			}
		}
		else if (attr1 == "Chubby")
		{
			while (temp->next != NULL)
			{
				if (count == 7)
				{
					if (temp->data == "1" && head->next->data == "1")
					{
						return true;
					}
				}
				count++;
				temp = temp->next;
			}
		}
		else if (attr1 == "Double_Chin")
		{
			while (temp->next != NULL)
			{
				if (count == 8)
				{
					if (temp->data == "1" && head->next->data == "1")
					{
						return true;
					}
				}
				count++;
				temp = temp->next;
			}
		}
		else if (attr1 == "Heavy_Makeup")
		{
			while (temp->next != NULL)
			{
				if (count == 9)
				{
					if (temp->data == "1" && head->next->data == "1")
					{
						return true;
					}
				}
				count++;
				temp = temp->next;
			}
		}
		else if (attr1 == "Wearing_Lipstick")
		{
			while (temp != NULL)
			{
				if (count == 10)
				{
					if (temp->data == "1" && head->next->data == "1")
					{
						return true;
					}
				}
				count++;
				temp = temp->next;
			}
		}
		else
		{
			return false;
		}
	}
};

int datacount = 0;
class ImageNode
{
public:
	string data;
	AttrList attr;
	ImageNode* next;
	ImageNode* prev;
	ImageNode()
	{
		data = "";
		next = NULL;
		prev = NULL;
	}

	ImageNode(string d, ImageNode* n)
	{
		data = d;
		next = n;
		prev = NULL;
	}
};
class ImageList
{
public:
	ImageNode* head = NULL;
	ImageNode* tail;

	ImageList()
	{
		head = NULL;
		tail = NULL;
	}
	void InsertStart(string data)
	{
		ImageNode* nnode = new ImageNode(data, NULL);

		nnode->next = head;
		nnode->prev = NULL;
		head->prev = nnode;
		head = nnode;
	}
	void InsertEnd(string data)
	{
		ImageNode* nnode = new ImageNode(data, NULL);

		if (head == NULL)
		{
			nnode->prev = NULL;
			head = nnode;
			return;
		}

		ImageNode* temp = head;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = nnode;
		nnode->prev = temp;
	}
	
	
	void print()
	{
		ImageNode* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " | ";
			temp->attr.print();
			cout << endl;
			temp = temp->next;
		}
		cout << "\n";
	}
	void print_rev()
	{
		ImageNode* temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		while (temp != NULL)
		{
			cout << temp->data << " | ";
			temp = temp->prev;
		}
		cout << "\n";
	}

	void Teller(string attr, string attr2, int num)
	{
		ImageNode* temp = head;
		float count = 0, count2 = 0;
		if (num == 1)
		{
			while (temp->next != NULL)
			{
				if (temp->attr.Checker(attr) == true)
				{
					count++;
				}
				temp = temp->next;
			}
			float perc = (count / datacount) * 100;
			cout << "\n\n\nChance of person being attractive when they are/have:\n1. " << attr << "\n\n" << perc << "%";
			return;
		}
		else if (num == 2)
		{
			while (temp->next != NULL)
			{
				if (temp->attr.Checker(attr) == true)
				{
					count++;
				}
				if (temp->attr.Checker(attr2) == true)
				{
					count2++;
				}
				temp = temp->next;
			}
		}
		float perc = ((count + count2) / (datacount * 2)) * 100;
		cout << "\n\n\nChance of person being attractive when they are/have:\n1. " << attr << "\n2. " << attr2 << "\n\n" << perc << "%";
		//cout << "COUNTER: " << count + count2;
	}
};
void printItems()
{
	cout << "\nList of variables to check attractiveness with: ";
	cout << "\n1. Arched Eyebrows\n2. Bags Under Eyes\n3. Big Lips\n4. Black Hair\n5. Blond Hair\n6. Chubby";
	cout << "\n7. Double Chin\n8. Heavy Makeup\n9. Wearing Lipstick";
}

int main()
{
	system("color 3F");
	ImageList img;
	
	cout << "LOADING DATASET..";
	ifstream fin;
	string line;
	fin.open("Data(limited).csv");

	int c = 0;
	while (!fin.eof())
	{
		fin >> line;
		
		line = line + ',';
		string temp;
		for (int i = 0; i < line.length(); i++)
		{
			if (c % 1000 == 0 && c < 20000)
			{
				cout << ".";
				c++;
			}
			if (line[i] != ',')
			{
				temp = temp + line[i];
			}
			else if (line[i] == ',')
			{
				if (temp != "-1" && temp != "1")
				{
					img.InsertEnd(temp);
					//temp2->attr->InsertEnd(temp);
				}
				//list.Checker(temp);
				//cout << temp;
				temp = "";
			}
			//img.print();
		}
		datacount++;
		//img.print();
		//temp2 = temp2->next;
		//cout << line << " " << endl;
	}

	fin.close();
	fin.open("Data(limited).csv");
	ImageNode* temp2 = img.head;
	c = 0;
	while (!fin.eof())
	{
		fin >> line;
		

		line = line + ',';
		string temp;
		for (int i = 0; i < line.length(); i++)
		{
			if (c % 1000 == 0 && c < 30000)
			{
				cout << ".";
				c++;
			}
			if (line[i] != ',')
			{
				temp = temp + line[i];
			}
			else if (line[i] == ',')
			{
				if (temp == "-1" || temp == "1")
				{
					//cout << temp;
					//img.InsertEnd(temp);
					temp2->attr.InsertEnd(temp);
				}
				//list.Checker(temp);
				//cout << temp;
				temp = "";
			}
		}
		//temp2->attr.print();
		temp2 = temp2->next;
		c++;
		//cout << line << " " << endl;
	}
	
	int var;
	datacount = datacount - 1;
	there2:
	system("CLS");
	cout << "This program checks that if given a max of 2 variables, what is the chance that a person is attractive based on given dataset:\n";
	there:
	cout << "Enter if you want to check attractiveness with 1 or 2 variables: ";
	cin >> var;
	if (var == 1)
	{
		printItems();
		cout << "\n\nSELECT ANY 1 AND ENTER ITS CORRESPONDING NUMBER: ";
		int varc;
		cin >> varc;
		if (varc == 1)
		{
			img.Teller("Arched_Eyebrows", "", 1);
		}
		if (varc == 2)
		{
			img.Teller("Bags_Under_Eyes", "", 1);
		}
		if (varc == 3)
		{
			img.Teller("Big_Lips", "", 1);
		}
		if (varc == 4)
		{
			img.Teller("Black_Hair", "", 1);
		}
		if (varc == 5)
		{
			img.Teller("Blond_Hair", "", 1);
		}
		if (varc == 6)
		{
			img.Teller("Chubby", "", 1);
		}
		if (varc == 7)
		{
			img.Teller("Double_Chin", "", 1);
		}
		if (varc == 8)
		{
			img.Teller("Heavy_Makeup", "", 1);
		}
		if (varc == 9)
		{
			img.Teller("Wearing_Lipstick", "", 1);
		}
	}
	else if (var == 2)
	{
		printItems();
		cout << "\n\nSELECT ANY 2 AND ENTER ITS CORRESPONDING NUMBERS: \nNUMBER 1: ";
		int varc = 0;
		cin >> varc;
		cout << "NUMBER 2: ";
		int varc2;
		cin >> varc2;

		string attr1, attr2;

		if (varc == 1)
		{
			attr1 = "Arched_Eyebrows";
		}
		if (varc == 2)
		{
			attr1 = "Bags_Under_Eyes";
		}
		if (varc == 3)
		{
			attr1 = "Big_Lips";
		}
		if (varc == 4)
		{
			attr1 = "Black_Hair";
		}
		if (varc == 5)
		{
			attr1 = "Blond_Hair";
		}
		if (varc == 6)
		{
			attr1 = "Chubby";
		}
		if (varc == 7)
		{
			attr1 = "Double_Chin";
		}
		if (varc == 8)
		{
			attr1 = "Heavy_Makeup";
		}
		if (varc == 9)
		{
			attr1 = "Wearing_Lipstick";
		}

		//divider

		if (varc2 == 1)
		{
			attr2 = "Arched_Eyebrows";
		}
		if (varc2 == 2)
		{
			attr2 = "Bags_Under_Eyes";
		}
		if (varc2 == 3)
		{
			attr2 = "Big_Lips";
		}
		if (varc2 == 4)
		{
			attr2 = "Black_Hair";
		}
		if (varc2 == 5)
		{
			attr2 = "Blond_Hair";
		}
		if (varc2 == 6)
		{
			attr2 = "Chubby";
		}
		if (varc2 == 7)
		{
			attr2 = "Double_Chin";
		}
		if (varc2 == 8)
		{
			attr2 = "Heavy_Makeup";
		}
		if (varc2 == 9)
		{
			attr2 = "Wearing_Lipstick";
		}

		img.Teller(attr1, attr2, 2);
	}
	else
	{
		cout << "\nPlease enter 1 or 2 as your choice\n";
		goto there;
	}
	cout << "\n\nDo you want to check again? (Y/N): ";
	char choice;
	cin >> choice;
	if (choice == 'Y' || choice == 'y')
	{
		goto there2;
	}
	cout << "\n";
    return 0;
}