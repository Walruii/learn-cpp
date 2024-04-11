#include <iostream>
#include <vector>
using namespace std;

int main() {
  const string vowels[] = {"n", "a", "i", "u", "e", "o"};
  const string cons[] = {"w", "r", "y", "m", "h", "n", "t", "s", "k"};
  vector<string> setOfGana;
  vector<string> setOfGanaDone;
  for (string vowel : vowels) {
    if (vowel == "n") {
      setOfGana.push_back("n");
    } else {
      setOfGana.push_back(vowel);
      for (string con : cons) {
        if (con == "w") {
          if (vowel == "a") {
            setOfGana.push_back(con + vowel);
          }
        } else if (con == "y") {
          if (vowel == "a" || vowel == "u" || vowel == "o") {
            setOfGana.push_back(con + vowel);
          }
        } else {
          setOfGana.push_back(con + vowel);
        }
      }
    }
  }
  /* for (string gana : setOfGana) { */
  /*   cout << gana << endl; */
  /* } */

  vector<string> gameGana = setOfGana;
  bool flag = true;
  while (flag) {
    int index = rand() % (gameGana.size() + 1);
    cout << gameGana[index] << endl;
    gameGana.erase(index);
  }
  return 0;
}
/* const game = async () => { */
/*   let flag = true */
/*   while (flag) { */
/*     if (setOfGanaDone.length === 45) { */
/*       flag = false */
/*     } */
/*     let getRandom = Math.floor(Math.random() * 45) */
/*     if (setOfGanaDone.indexOf(setOfGana[getRandom]) === -1) { */
/*       console.log(setOfGana[getRandom]) */
/*       setOfGanaDone.push(setOfGana[getRandom]) */
/*       let a = await rl.question("ENTER", (enter) => { }) */
/*     } */
/*   } */
/* } */
