#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {
    
  /* Enter your code here */
  if(dynamic_cast<Fireball*>(spell) != nullptr){
      Fireball* fire_ptr = dynamic_cast<Fireball*>(spell);
      fire_ptr->revealFirepower();
  }else if(dynamic_cast<Frostbite*>(spell) != nullptr){
      Frostbite* frost_ptr = dynamic_cast<Frostbite*>(spell);
      frost_ptr->revealFrostpower();
  }else if(dynamic_cast<Thunderstorm*>(spell) != nullptr){
      Thunderstorm* thunder_ptr = dynamic_cast<Thunderstorm*>(spell);
      thunder_ptr->revealThunderpower();
  }else if(dynamic_cast<Waterbolt*>(spell) != nullptr){
      Waterbolt* water_ptr = dynamic_cast<Waterbolt*>(spell);
      water_ptr->revealWaterpower();
  }else{
      string scroll_name = spell->revealScrollName();
      string journal_str = SpellJournal::read();
      vector<vector<int>>dp(scroll_name.length()+1, vector<int>(journal_str.length()+1,0));
      for(int i = 1; i < scroll_name.length()+1; i++){
          for(int j = 1; j < journal_str.length()+1; j++){
              if(scroll_name[i-1] == journal_str[j-1]){
                  dp[i][j] = 1 + dp[i-1][j-1];
              }
              if(dp[i-1][j] > dp[i][j]){
                  dp[i][j] = dp[i-1][j];
              }
              if(dp[i][j-1] > dp[i][j]){
                  dp[i][j] = dp[i][j-1];
              }
          }
      }
      cout << dp[scroll_name.length()][journal_str.length()] << endl;
  }

}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}