#include <iostream>
#include <vector>
#include <list>
#include <memory>
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
	void setTitle(std::string _title);
    void setNum(double _num);
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
    void setSizeLst(size_t _sizeLst);
    void pushBack(std::vector<Data>&&);
    void popBack();
    std::list<std::vector<Data>>& getLst();
    std::vector<Data>& operator[](size_t indx);
    void printLst(size_t numLst);
};

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
    Data task2("public and private", 11.77);
    Data task3("class", 99.45);

    std::vector<Data> tmp;
    tmp.reserve(3);
    tmp.push_back(std::move(task1));
    tmp.push_back(std::move(task2));
    tmp.push_back(std::move(task3));
    List lst(std::move(tmp));

    Data task4("vds", 88.32);
    Data task5("virtual server", 325.4);
    std::vector<Data> tmp2;
    tmp2.push_back(std::move(task4));
    tmp2.push_back(std::move(task5));

    lst.pushBack(std::move(tmp2));
	
	lst.printLst(0);
	lst.printLst(1);
	lst.popBack();
	lst.popBack();
	
    return 0;
}
