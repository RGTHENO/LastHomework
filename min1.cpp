#include <iostream>

template<typename T>
T min(const T a, const T b){
	return a>b? b : a;
} 

int main(){
	std::cout<<"EL minimo es: "<<min<int>(5,5);
	
	return 0;
}