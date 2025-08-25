#include <iostream>
#include <vector>
#include <list>
#include <string>

class Data{
private:
    std::string title;
    double num;
public:
    Data(std::string _title, double _num) : title(_title), num(_num){}
    Data(const Data&) = delete;
    Data& operator=(const Data&) = delete;
    Data(Data&&);
    Data& operator=(Data&&);
    std::string& getTitle();
    double getNum();
    friend std::ostream& operator<<(std::ostream& os, Data&);
};

Data::Data(Data&& rhs){
    title = std::move(rhs.title);
    num = std::move(rhs.num);
	rhs.num = 0;
}

Data& Data::operator=(Data&& rhs){
	if(this != &rhs){
		title = std::move(rhs.title);
		num = std::move(rhs.num);
		rhs.num = 0;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, Data& obj){
    os << obj.title << " " << obj.num;
    return os;
}

std::string& Data::getTitle(){ return title; }

double Data::getNum(){ return num; }

class List{
private:
    std::list<std::vector<Data>> lst;
    size_t sizeLst{0};
public:
    List(std::vector<Data>&& vecData);
    List(const List&) = delete;
	List& operator=(const List&) = delete;
	List(List&&) = delete;
	List& operator=(List&&) = delete;
	size_t getSizeLst();
    void pushBack(std::vector<Data>&&);
    std::list<std::vector<Data>>::iterator insertVector(size_t, std::vector<Data>&&);
	void popBack();
    std::vector<Data>& operator[](size_t indx);
    void printLst(size_t numLst);
};

std::list<std::vector<Data>>::iterator List::insertVector(size_t indx, std::vector<Data>&& vecData){
	if(indx >= sizeLst){
		pushBack(std::move(vecData));
		return lst.end();
	}
	if(indx < sizeLst){
		auto it = lst.begin();
		size_t cnt{0};
		while(it != lst.end()){
			if(indx == cnt){
				++sizeLst;
				return lst.insert(it, std::move(vecData));
			}
		it++;
		cnt++;
		}
	}
}

std::vector<Data>& List::operator[](size_t indxLst){
	auto it = lst.begin();
    size_t cnt{0};
    while(it != lst.end()){
        if(indxLst == cnt){ return *it; }
        cnt++;
        it++;
    }
}

List::List(std::vector<Data>&& vecData){
    pushBack(std::move(vecData));
}

size_t List::getSizeLst() { return sizeLst; }

void List::pushBack(std::vector<Data>&& _vec){
    lst.push_back(std::move(_vec));
    ++sizeLst;
}

void List::popBack(){
    if(sizeLst){
        lst.pop_back();
        --sizeLst;
    }
}

void List::printLst(size_t indxLst){
    if(indxLst >= sizeLst){ std::cerr << "index out of range!" << std::endl; return ;}
    
    for(size_t i = 0; i < (*this)[indxLst].size(); ++i){
        std::cout << (*this)[indxLst][i] << "\n";
    }
}

int main(){
    Data task1("test info", 55.21);
    Data task2("arduino open-source electronic prototyping platform enabling users to create interactive electronic objects.", 11.77);
    Data task3("raspberry pi", 99.45);

    std::vector<Data> tmp;
    tmp.reserve(3);
    tmp.push_back(std::move(task1));
    tmp.push_back(std::move(task2));
    tmp.push_back(std::move(task3));
    
	List lst(std::move(tmp));

    Data task4("vds", 88.32);
    Data task5("virtual server", 325.4);
    std::vector<Data> tmp2;
	tmp.reserve(2);
    tmp2.push_back(std::move(task4));
    tmp2.push_back(std::move(task5));

    lst.pushBack(std::move(tmp2));
	
	Data task6("lenovo", 881.12);
	Data task7("apple macbook", 914.09);
	std::vector<Data> tmp3;
	tmp3.reserve(2);
	tmp3.push_back(std::move(task6));
	tmp3.push_back(std::move(task7));
	
	lst.insertVector(1, std::move(tmp3));

	for(size_t i = 0; i < lst.getSizeLst(); ++i){
		std::cout << i << ":\n";
		lst.printLst(i);
	}
	std::cout << lst.getSizeLst() << std::endl;
	
	lst.popBack();

    return 0;
}
