#include <iostream>

class SpellStrat{
  public:
    virtual int cast_spell(int base,int bonnus)=0;
    virutal ~SpellStrat()=default;
};

class fireball:public SpellStrat{
  int cast_spell(int base,int bonnus) override {
    return base+bonnus;
  }
};
class ice:public SpellStrat{
  int cast_spell(int base,int bonnus) override{
    return base+2+bonnus;
  }
};

class Player{
  public:
    void SetStrat(SpellStrat* stat){
      this->strat=stat;
    }

    int attack(int base_dmg,int bonnus){
      std::cout<<"plr is attacking"<<"\n";
      return strat->cast_spell(base_dmg,bonnus);
    }

  private:
    SpellStrat* strat;
};

int main(){
  Player* plr = new Player();
  fireball* fb=new fireball();
  ice* ic=new ice();
  plr->SetStrat(fb);
  std::cout<<plr->attack(2,3);
  plr->SetStrat(ic);
  std::cout<<plr->attack(2,3);
  delete fb;
  delete ic;
  delete  plr;

  return 0;
}
