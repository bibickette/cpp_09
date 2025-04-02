 std::tm timeStruct = {};
    timeStruct.tm_year = year - 1900; 
    timeStruct.tm_mon = month - 1;
    timeStruct.tm_mday = day;

    std::time_t t = std::mktime(&timeStruct);
    if (t == -1 || timeStruct.tm_year + 1900 != year || 
        timeStruct.tm_mon + 1 != month || timeStruct.tm_mday != day)
        return false;


ex01 
int main(int argc, char **argv)
{
 argc != 2
 return caca

std::strgin arg = argv[1];
if(arg.empty())
return 1

 return 0
}

void RPN(string str) 3 2 1 + -
stack = 3 2 1
{
  std::stack<int> nB;
  int i = -1;
  while(str[++i]) // la je stock
  {
    if( str[i] == ' ')
      i++;
    if(isdigit str[i]) // donc ya que des chiffres entre 0  et 9
    {
      stack.push( atoi str[i].c_str());
    }
    else if ( str[i] + - * / )
    {
    // 3 2 1 +  => 3 3 => erreur : 3 3 => pas doperateur = erreur
    // 3 2 1 + -  => 3 3 - => pas erreur  : 3 2 + 1 - => 3 3 - => 3 - 3
      if stack.size() < 2
        return err trop petit; 
    // start calcul
    int a = stack.top();
    stack.pop();
    int b = stack.top();
    stack.pop()
     switch(str[i])
     {
     case '+':
       stack.push(b + a);
       break;
      case '/':
        if(a == 0)
        print peut pas diviser par 0;
        return;
     ...
     }
    else
      print char pas bien return;
  }
 if  stack.size() != 1
   pint missing operator return
  cout << stack.top()<< endl;
  

}

ex02
int main(int argc, char argv)
{
  if(argc == 1)
    caca;
  std::vector<int> vect;
  int i = -1;
  int nb;
  while argv[++i]
  {
    // check int max a ajouter
    int nb = atoi(argv[i]); // en gros on met la string dans iss 
    if(nb < 0)
    {
      invalid arg;
    }
    vect.push_back(nb);
  }
  //affiche stack before
  for int i = 0 i < vector.size(); i++
  {
    cout << vector[i] << " " ;
  }
  std::clock_t start = std::clock();
  tamersort(vec);
  std::clock_t end = std::clock();
  
  //affiche stack after
  for int i = 0 i < vector.size(); i++
  {
    cout << vector[i] << " " ;
  }
  
  double time = 1 000 000.0 * (end - start) / CLOCKS_PER_SEC ; // converti en microsd
  cout << "time elapsed = " << time << " µs" << endl;
  
}

2 3 4 5
  2 3 smaller 2 larger 3
  4 5 smaller 4 larger 5
  2 4
  3 5

9 5 7 2
  9 5 smaller 5 larger 9
  7 2 smaller 2 larger 7
  smaller 5 2
  larger 9 7
  tamersort avec 9 7
  smaller 5 2 => 7 9

// ici on trie dans 2 categ par 2 chiffre a la fois
// on met dans smaller et larger, ca fait des pairs
// on fait pair et on trie
void tamersort(std::vector<int> &vec)
{
  if(vec.size() < 2)
    return tamer;
  std::vector<int> smaller;
  std::vector<int> larger;
  for size t i = 0; i < vec.size() - 1; i +=2
  {
  // le 3 trie le larger eleme de chaque pair bah la on met le larger direct dans un autre list
    if(vec[i] < vec[i + 1])
    {
      smaller.pushback(vec i);
      larger.pushback(vec i + 1); 
    }
    else
    {
     smaller.pushback(vec i + 1);
      larger.pushback(vec i ); 
    }
  }
  if(vec.size() % 2 != 0)
    larger.pushback(vec[vec.size() - 1])
  tamersort(larger); // recursivily trier le larger elem
  insert(smaller, larger);
}

 std::vector<int>  generatejacbos( int n)
 {
  std::vector<int> newvec;
  int j0 = 0;
  int j1 = 1;
  int jn = j1 + 2 * j0;
  // 
  while(jn < n)
  {
    j0 = j1;
    j1 = jn;
    jn =  j1 + 2 * j0;
  }
   return newvec;
}

void insert (std::vector<int> &smaller, vector &larger)
{
  std::vector<int>::iterator iterator;
  std::vector<int> jacbostal = generatejacbos(smaller.size());
  std::vector<bool> isinserted(smaller.size(), false);

for size t i = 0; i < jacobstal.size(); i++
{
  int index = jacobstal[i];
  std::vector<int>::iterator pos = std::lower_bound(larger.begin, larger.end, smaller[i]);
  larger.insert(pos, smaller[index]);
  isinserted[index] = true;
} 
  for size t i = 0; i < smmaler.size(); i++
  {
    if(!isinserted[i])
    {
      iterator = std::lower_bound(larger.begin, larger.end, smaller[i]);
      larger.insert(iterator, smaller[i]);
    }
  }
}


