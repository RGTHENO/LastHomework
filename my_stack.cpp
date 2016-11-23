#ifndef __STACK_H__
#define __STACK_H__
 
#include <iostream>
#include <vector>
 
template<class T> class Stack;

template<class T>
Stack<T> operator+(const Stack<T> &s1,const Stack<T> &s2)
{	
	Stack<T> concatened = s1;
	for(int i=0;i<s2.my_stack.size();++i){ concatened.my_stack.push_back(s2.my_stack[i]); }
	return concatened;
}



template<class T>
class Stack{
	
	private:
		friend Stack<T> operator+<>(const Stack<T> &s1, const Stack<T> & s2);
		std::vector<T> my_stack;
	
	public:
		Stack();
		bool empty()const;
		void push(const T &);
		const T& top();
		void pop();
};

template<class T>
Stack<T>::Stack(){}


template<class T>
bool Stack<T>::empty()const{ return my_stack.empty();}

template<class T>
void Stack<T>::push(const T &item){ my_stack.push_back(item);}

template<class T>
const T& Stack<T>::top(){
	return my_stack.back();
}

template<class T>
void Stack<T>::pop(){
	 if(!my_stack.empty())
	  my_stack.pop_back();
}


int main(){
	
	Stack<int> cola, cola2, concatened; 
	cola.push(6);
	cola.push(5);
	cola.pop();  
	int a = cola.top();
	std::cout<<"Cola.top() : "<<a<<"\n\n";
	cola2.push(4);cola2.push(19); cola2.push(5);cola2.pop();	
	std::cout<<"Cola2.top():"<<cola2.top();
	
	concatened = cola+cola2;
	std::cout<<"\n\nEl nuevo elemento que se encuentra en Cola.top():"<<concatened.top(); 
	
 
	return 0;
}

#endif