#include <iostream>

using namespace std;

int main() {
  int s;
  cin >> s;
  for(int il = 1; il <= 9; il++)
    for(int jl = 0; jl <= 9; jl++)
      for(int kl = 0; kl <= 9; kl++)
      {
        if(il + jl + kl == s)
        {
          //cout << il << jl << kl;
          for(int ir = 1; ir <= 9; ir++)
            for(int jr = 0; jr <= 9; jr++)
              for(int kr = 0; kr <= 9; kr++)
              {
                if(ir + jr + kr == s)
                {
                  cout << il << jl << kl << ir << jr << kr << endl;
                  break;
                }
              }
          break;
        }
      }
  return 0;
}
