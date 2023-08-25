#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
template <typename Type>
class node
{
public:
Type data;
node* next;
node* prev;
};
template <typename Type>
class headerNode
{
public:
char sign;
int countNodes;
node<Type>* next;
node<Type>* prev;
};
template <typename Type>
class bigInteger {
private:
node<Type>* head; int count; headerNode<Type>* headNode;
public:
bigInteger() {
head = NULL; count = 0; headNode = NULL;
}
node<Type>* getHead() {
return head;
}
headerNode<Type>* getHeadNode() {
//cout << " head " << headNode->sign << endl;
return headNode;
}
int getCount() {
return count;
}
void insertBeg(Type value);
void insertHeader(int sign, bigInteger l1);
void insertEnd(Type value);
void delBeg();
void delEnd();
void displayList();
int compare(bigInteger l2, bigInteger l1);
void reverselist();
void stringAddition(bigInteger l1, bigInteger l2);
void stringSubtraction(bigInteger l1, bigInteger l2);
void stringMultiplication(bigInteger l1, bigInteger l2);
bigInteger stringMULAddition(bigInteger l1, bigInteger l2);
void stringDivision(bigInteger l1, long divisor);
void deleteList(node<Type>** head);
void stringconversion1l(bigInteger<int>& list, string str1);
void stringconversion2l(bigInteger<int>& list, string str1);
void menu();
};
template <typename Type>
void bigInteger<Type>::insertBeg(Type value) {
if (head == NULL) {
node<Type>* temp;
temp = new node<Type>;
temp->data = value;
temp->next = NULL;
count++;
headerNode<Type>* hnode = new headerNode<Type>;
hnode->countNodes = count;
hnode->next = temp;
temp->prev = NULL;
hnode
->prev = NULL;
head = temp;
headNode = hnode;
}
else {
node<Type>* temp;
temp = new node<Type>;
node<Type>* hnode = head
->prev;
temp
->data = value;
temp
->next = head;
temp
->prev = hnode;
head
->prev = temp;
hnode
->next = temp;
/*temp
->prev = NULL;*/
head = temp;
}
headNode
->countNodes = count++;
}
template <typename Type>
void bigInteger<Type>::insertHeader(int sign, bigInteger l1) {
headerNode<Type>* hn = new headerNode<Type>;
hn->next = l1.head;
hn->prev = NULL;
hn->sign = sign;
hn->countNodes = count;
}
template <typename Type>
void bigInteger<Type>::insertEnd(Type value) {
if (head == NULL) {
node<Type>* temp;
temp = new node<Type>;
temp->data = value;
temp->next = NULL;
count++;
headerNode<Type>* hnode = new headerNode<Type>;
hnode->countNodes = count;
hnode->next = temp;
temp->prev = NULL;
hnode->prev = NULL;
head = temp;
headNode = hnode;
}
else
{
node<Type>* temp = head;
while (temp->next != NULL)
{
temp = temp->next;
}
node<Type>* p = new node<Type>; p->data = value; p->next = NULL;
temp->next = p;
p->prev = temp;
}
headNode->countNodes = count++;
}
template <typename Type>
void bigInteger<Type>::delBeg() {
if (head == NULL) {
cout << "No nodes in linked list" << endl;
exit(0);
}
else {
node<Type>* temp = head;
headerNode<Type>* hnode;
hnode->next = temp->next;
head = head->next;
temp->next = NULL;
head->prev = NULL;
delete temp;
headNode->countNodes = count--;
}
}
template <typename Type>
void bigInteger<Type>::delEnd() {
if (head == NULL) {
cout << "No nodes in linked list" << endl;
exit(0);
}
else {
node<Type>* temp = head;
node<Type>* p = NULL;
while (temp->next != NULL)
{
p = temp;
temp = temp->next;
}
p->next = NULL;
temp->prev = NULL;
headNode->countNodes = count--;
}
}
//------------------------------------------------------------------------------------------------
//displaying data in the list
template <typename Type>
void bigInteger<Type>::displayList()
{
cout << " \n Result Data is" << endl;
node<Type>* temp = head;
cout << " ";
cout << "Number of nodes in list are: " << headNode->countNodes << endl;
cout << "Sign of number in linkedlsit is: " << headNode->sign << endl;
cout << headNode->sign;
while (temp != NULL)
{
cout << temp->data;
temp = temp->next;
}
cout << endl << endl;
}
//-----------------------------------------------------------------------------------------------
//comparing data in the lists and returning value accordingly
template <typename Type>
int bigInteger<Type>::compare(bigInteger l2, bigInteger l1)
{
if (l1.count > l2.count)
{
return 1;
}
else if (l1.count < l2.count)
{
return 2;
}
else
{
//reversing the lists because numbers are stored in reverse order
//to compare which number is greater
l1.reverselist();
l2.reverselist();
int num = 0;
node<Type>* temp = l1.head;
node<Type>* temp2 = l2.head;
while (temp != NULL && temp2 != NULL)
{
if (temp->data > temp2->data)
{
//reversing again to get back to normal list
l1.reverselist();
l2.reverselist();
return 1;
}
else if (temp->data < temp2->data)
{
l1.reverselist();
l2.reverselist();
return 2;
}
else
{
num++;
}
temp = temp->next;
temp2 = temp2->next;
}
if (count == num)
{
l1.reverselist();
l2.reverselist();
return 1;//if nodes are equal then you can return anything
}
}
}
//----------------------------------------------------------------------------
//function to reverse the lists
template <typename Type>
void bigInteger<Type>::reverselist()
{
node<Type>* current = head;
node<Type>* prev = NULL, * next = NULL;
while (current != NULL) {
next = current->next;
current->next = prev;
prev = current;
current = next;
}
head = prev;
}
//=============================================================
=====================
//function to perform big number addition
template <typename Type>
void bigInteger<Type>::stringAddition(bigInteger l1, bigInteger l2)
{
headerNode<Type>* hd = new headerNode<Type>;
int sum = 0, x, num, carry = 0;
node<Type>* temp1 = l1.head;
node<Type>* temp2 = l2.head;
//hd = l1.getHeadNode();
// cout << " running head "<< l1.headNode->sign << endl;
bigInteger<Type> l3;
x = compare(l2, l1);
//comparing the lists and setting the lists accordingly
if (x == 1) {
temp1 = l1.head;
temp2 = l2.head;
}
else if (x == 2)
{
temp2 = l1.head;
temp1 = l2.head;
}
//appending 0's at the end of list
if (l1.count > l2.count)
{
while (l1.count != l2.count)
{
l2.insertEnd(0000);
}
}
else if (l1.count < l2.count)
{
while (l1.count != l2.count)
{
l1.insertEnd(0000);
}
}
//adding the lists
while (temp1 != NULL)
{
sum = temp1->data + temp2->data + carry;
num = sum % 10000;//to get the number to be appended in the list
carry = sum / 10000;// to get the carry
l3.insertEnd(num);
temp1 = temp1->next;
temp2 = temp2->next;
}
if (x == 1)
{
l3.headNode->sign = l1.headNode->sign;
}
else if (x == 2)
{
l3.headNode->sign = l2.headNode->sign;
}
//displaying the string
l3.reverselist();

l3.displayList();
}
//=============================================================
=========================
//subtraction of big integers
template <typename Type>
void bigInteger<Type>::stringSubtraction(bigInteger l1, bigInteger l2)
{
headerNode<Type>* hd = new headerNode<Type>;
int x, y, num, carry = 0;
node<Type>* temp1 = l1.head;
node<Type>* temp2 = l2.head;
//hd = l1.getHeadNode();
// cout << " running head "<< l1.headNode->sign << endl;
node<Type>* temp = NULL;
bigInteger<Type> l3;
x = compare(l2, l1);
y = compare(l2, l1);
//comparing the lists and setting the lists accordingly
if (x == 1) {
temp1 = l1.head;
temp2 = l2.head;
}
else if (x == 2)
{
temp2 = l1.head;
temp1 = l2.head;
}
//appending 0's at the end of list
if (l1.count > l2.count)
{
while (l1.count != l2.count)
{
l2.insertEnd(0);
}
}
else if (l1.count < l2.count)
{
while (l1.count != l2.count)
{
l1.insertEnd(0);
}
}
while (temp1 != NULL)
{
if (temp1->data >= temp2->data)//if the 1st data is smaller then 2nd data
{
goto label1;
}
//if 1st data is greater lists haven't reached the end
//getting borrow form the next data
if (temp1->data < temp2->data && l1.count>1 || l2.count > 1 && temp1->next
!= NULL && temp2->next != NULL)
{
temp = temp1->next;
num = temp->data % 10;
num = num * 10000;
temp1->data = num + temp1->data;
temp->data -= 1;
temp1->next = temp;
}
label1://performing subtraction on the data and appending the lists
x = temp1->data - temp2->data;
num = x % 10000;
l3.insertEnd(num);
temp1 = temp1->next;
temp2 = temp2->next;
}
if (y == 1)
{
l3.headNode->sign = l1.headNode->sign;
}
else if (y == 2)
{
l3.headNode->sign = l2.headNode->sign;
}
l3.reverselist();
l3.displayList();
}
//=============================================================
==========================
//////performing big integer multiplication on the lists
template <typename Type>
void bigInteger<Type>::stringMultiplication(bigInteger l1, bigInteger l2)
{
headerNode<Type>* hd = new headerNode<Type>;
int x, num, carry = 0, iter = 0;
node<Type>* temp1 = l1.head;
node<Type>* temp2 = l2.head;
//hd = l1.getHeadNode();
// cout << " running head "<< l1.headNode->sign << endl;
node<Type>* templ3 = NULL;
node<Type>* temp = NULL;
bigInteger<Type> l3, prev;
//appending 0's at the begining of list and creating some nodes
while (temp1 != NULL) {
prev.insertBeg(0);
temp1 = temp1->next;
}
//multiplying the numbers
while (temp2 != NULL)
{
carry = 0;
temp1 = l1.head;
while (temp1 != NULL)
{//multplying one node of list 2 wit all nodes of list 1
x = (temp2->data * temp1->data) + carry;
num = x % 10;
carry = x / 10;
l3.insertEnd(num);
temp1 = temp1->next;
}
//if theres any left over carry appending it in the string
if (carry > 0)
l3.insertEnd(carry);
++iter;
if (iter > 1) {//appending 0's at the end of number to be added
for (int i = 1; i < iter; i++)
{
l3.insertBeg(0);
}
}
temp2 = temp2->next;
//adding the results of two operations and proceeding
prev = stringMULAddition(l3, prev);
templ3 = l3.head;
deleteList(&l3.head);
}
if ((l1.headNode->sign == '+' && l2.headNode->sign == '-') || (l1.headNode->sign
== '-' && l2.headNode->sign == '+'))
{
prev.headNode->sign = '-';
}
else if ((l1.headNode->sign == '+' && l2.headNode->sign == '+') || (l1.headNode-
>sign == '-' && l2.headNode->sign == '-'))
{
prev.headNode->sign = '+';
}
//displaying data
prev.reverselist();
prev.displayList();
}
template <typename Type>
bigInteger<Type> bigInteger<Type>::stringMULAddition(bigInteger l1, bigInteger l2)
{//having another function of addition for multiplication
//because 1 digit was stored in one node
headerNode<Type>* hd = new headerNode<Type>;
int sum = 0, x, num, carry = 0;
node<Type>* temp1 = l1.head;
node<Type>* temp2 = l2.head;
bigInteger<Type> l3;
x = compare(l2, l1);
if (x == 1) {
temp1 = l1.head;
temp2 = l2.head;
}
else if (x == 2) {
temp2 = l1.head;
temp1 = l2.head;
}
if (l1.count > l2.count) {
while (l1.count != l2.count) {
l2.insertEnd(0);
}
}
else if (l1.count < l2.count) {
while (l1.count != l2.count) {
l1.insertEnd(0);
}
}
while (temp1 != NULL) {
sum = temp1->data + temp2->data + carry;
num = sum % 10;
carry = sum / 10;
l3.insertEnd(num);
temp1 = temp1->next;
temp2 = temp2->next;
}
return l3;
}
template <typename Type>
void bigInteger<Type>::stringDivision(bigInteger l1, long divisor) {
l1.reverselist();
bigInteger<Type> temp3;
node<Type>* temp1 = l1.head;
float idx = 0.0, ans = 0.0;
while (temp1 != NULL) {
if (temp1->data >= divisor || temp1->data == 0000)
{
	ans = temp1->data / divisor;
	while (i > 0)
{
substring = str1.substr(i, 4);
x = stoi(substring);//converting string to integers
list.insertEnd(x);//inserting in the list
num = num - 4;
i = i - 4;
}
str1.resize(num);// resizing string to fetch the remaining part
x = stoi(str1);//converting string to integers
list.insertEnd(x);//inserting in the list
list.headNode->sign = sign;
//list.insertHeader(sign, list);
}
template <typename Type>
void bigInteger<Type>::stringconversion2l(bigInteger<int>& list, string str1)
{
//function to store 1 digit in a node
int x, num, i;
char sign;// x is used to store the 'string' into 'int' conversions
//num is used to store the length of remaining part of string
string substring;
/*substring = str1.substr(0, 1);*/
sign = str1[0];
/*sign = stoi(substring);*/
str1.erase(0, 1);
reverse(str1.begin(), str1.end());
for (int i = 0; i < str1.length(); i++)
{
x = str1[i] - '0';//converting string to integers
list.insertEnd(x);//inserting in the list
}
list.headNode->sign = sign;
//list.insertHeader(sign, list);
}
//=============================================================
===================
//displaying menu
template <typename Type>
void bigInteger<Type>::menu()
{
bigInteger<int> list1, list2, list3; //creating an empty list
char choice;
string str1;
string str2;
do {
cout << "\n Choose the operation you want to perform on matrix : " << endl;
cout << "Press A for Addition" << endl;
cout << "Press S for Subtraction" << endl;
cout << "Press M for Multiplication" << endl;
cout << "Press D for Division" << endl; cin >> choice;
if (choice == 'A' || choice == 'a')
{
cout << " Enter the 1st big integer : "; cin >> str1;
cout << " Enter the 2nd big integer : "; cin >> str2;
stringconversion1l(list1, str1);
stringconversion1l(list2, str2);
if ((list1.headNode->sign == '+' && list2.headNode->sign == '-') ||
(list1.headNode->sign == '-' && list2.headNode->sign == '+'))
{
stringSubtraction(list1, list2);
}
else if ((list1.headNode->sign == '+' && list2.headNode->sign == '+') ||
(list1.headNode->sign == '-' && list2.headNode->sign == '-'))
{
stringAddition(list1, list2);
}
exit(0);
}
else if (choice == 'S' || choice == 's')
{
cout << " Enter the 1st big integer : "; cin >> str1;
cout << " Enter the 2nd big integer : "; cin >> str2;
stringconversion1l(list1, str1);
stringconversion1l(list2, str2);
if ((list1.headNode->sign == '+' && list2.headNode->sign == '-') ||
(list1.headNode->sign == '-' && list2.headNode->sign == '+'))
{
stringAddition(list1, list2);
}
else if ((list1.headNode->sign == '+' && list2.headNode->sign == '+') ||
(list1.headNode->sign == '-' && list2.headNode->sign == '-'))
{
stringSubtraction(list1, list2);
}
exit(0);
}
else if (choice == 'm' || choice == 'M')
{
cout << " Enter the 1st big integer : "; cin >> str1;
cout << " Enter the 2nd big integer : "; cin >> str2;
stringconversion2l(list1, str1);
stringconversion2l(list2, str2);
stringMultiplication(list1, list2);
exit(0);
}
else if (choice == 'd' || choice == 'D')
{
cout << " Enter the 1st big integer : "; cin >> str1;
long divisor;
cout << " Enter the divisor: "; cin >> divisor;
stringconversion1l(list1, str1);
stringDivision(list1, divisor);
exit(0);
}
else
cout << " You Entered Wrong choice, Kindly Retype :";
} while (choice != 'A' && choice != 'a' && choice != 'S' && choice != 'M' && choice !=
'm' && choice != 'D' && choice != 'd');
}
//=============================================================
==================================
//*******driver******
int main()
{
bigInteger<int> obj;
obj.menu();
return 0;
}

