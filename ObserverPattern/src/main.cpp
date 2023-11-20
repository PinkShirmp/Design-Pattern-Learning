#include "iostream"
#include "string"
#include "vector"
#include <vector>
class IObserver{
public:
  virtual ~IObserver() =default;
  virtual void update(const int temp)=0;
  virtual void whatisthetemp()=0;
protected:
  int temp=0;
};

class IObservable{
public:
  virtual ~IObservable()=default;
  virtual int add(IObserver* ob)=0;
  virtual void remove(int idx)=0;
  virtual void notify()=0;
protected:
  std::vector<IObserver*> observers;
  int temp=0;
};


class Phone:public IObserver{
public:
  void update(const int temp) override{
    this->temp=temp;
  }
  void whatisthetemp() override{
    std::cout<<this->temp<<"\n";
  }
};

class WeatherStation:public IObservable{
public:
  int add(IObserver* ob) override{
    this->observers.emplace_back(ob);
    return this->observers.size()-1;
  }
  void remove(int index) override{
    this->observers.erase(this->observers.begin()+index);
  }
  void notify() override{
    for(auto observer:this->observers){
      observer->update(this->temp);
    }
  }
  void set_temp(int temp){
    this->temp=temp;
  }
};




int main(){
  WeatherStation _weatherStation;
  Phone phone1,phone2;

  _weatherStation.add(&phone1);
  _weatherStation.add(&phone2);


  _weatherStation.set_temp(25);
  _weatherStation.notify();

  phone1.whatisthetemp();
  phone2.whatisthetemp();
  _weatherStation.set_temp(30);
  _weatherStation.notify();
  phone1.whatisthetemp();
  phone2.whatisthetemp();



  return 0;
}
