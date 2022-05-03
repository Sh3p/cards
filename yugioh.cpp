#include "yugioh.h"
#include <numeric>



int
main ()
{
  string deckName;
  string loader;
  ofstream myFile;
  ifstream inFile;
  string fileName;

  int deckSize;
  cout << "Would you like to open a new deck or load a saved one, type load to "
          "load a deck"
       << endl;
  cin >> loader;
  yugioh deck1 (deckName);
  if (loader == "load")
  {
    cout << "Enter file name" << endl;
    cin >> fileName;
    inFile.open (fileName);
    if (inFile.fail ())
    {
      cout << "file bad or doesnt exist, adios" << endl;
      exit (1);
    }
    string word;
    while (inFile >> word)
    {
      deck1.data.push_back (word);
    }
  }
  else
  {
    cout << "enter deck name: ";

    cin >> deckName;
    cout << "enter deck size: ";

    cin >> deckSize;
    deck1.create (deckSize);
    cout << "If you would wish to save this deck, type yes, if not type no"
         << endl;
    string answer;
    cin >> answer;
    if (answer == "yes")
    {
      string save;
      cout << "what would you like to save the deck as, make sure to add .txt "
              "to end"
           << endl;
      cin >> save;
      myFile.open (save);
      std::ofstream output_file (save);
      std::ostream_iterator<std::string> output_iterator (output_file, "\n");
      std::copy (deck1.data.begin (), deck1.data.end (), output_iterator);
    }
  }
  int exit = 0;
  while (exit != 9)
  {
    int choice = 0;
    deck1.menu ();
    cin >> choice;
    if (choice == 1)
    {
      string name;
      cout << "what would you like the new cards name to be:" << endl;
      cout << "note: use dashes instead of spaces" << endl;
      cin >> name;
      myFile << name;
      deck1.addCard (name);
    }
    if (choice == 2)
    {
      string name;
      cout << "what card would you like to delete:" << endl;
      cin >> name;
      deck1.eraseCard (name);
    }
    if (choice == 3)
    {
      string name;
      cout << "what would you like the new deck name to be:" << endl;
      cin >> name;
      deck1.setDeckName (name);
    }
    if (choice == 4)
    {
      cout << "here is the deck name and a list of all the cards currently in "
              "the deck:"
           << endl;
      cout << "deck name:" << deck1.getDeck () << endl;
      cout << " card list:" << endl;
      deck1.deckList ();
    }
    if (choice == 5)
    {
      cout << "Random hand generated:" << endl;
      deck1.generate ();
    }
    if (choice == 6)
    {
      string name;
      cout << "enter the card name you would like to find the probability of "
              "drawing"
           << endl;
      cin >> name;
      cout << "the probability of drawing " << name << " is "
           << deck1.prob (name) << "%" << endl;
    }
    if (choice == 9)
    {
      exit = 9;
    }
  }
  return 0;
}


yugioh::yugioh ()
{
  deck_size = 0;
}

yugioh::yugioh (string deck)
{
  deck_name = deck;
  std::vector<string> data;
}

yugioh::~yugioh ()
{
}

string
yugioh::getDeck () const
{
  return deck_name;
}

int
yugioh::getSize () const
{
  return data.size ();
}
int
yugioh::addCard (string name)
{
  this->data.push_back (name);
  return 0;
};
int
yugioh::eraseCard (string name)
{
  vector<string>::iterator ptr = data.begin ();
bool card = true;

  for (unsigned int i = 0; i < data.size (); ++i)
  {
    
    if (data[i] == name)
    {
      this->data.erase (ptr);
      card = false;
      break;
    }
  ++ptr;
  }
  return 0;
}
void
yugioh::setDeckName (string name)
{
  deck_name = name;
}
void
yugioh::deckList ()
{
  for (unsigned int i = 0; i < data.size (); ++i)
  {
    cout << data[i] << endl;
  }
}
void
yugioh::menu ()
{
  cout << endl;
  cout << "what action would you like to perform:" << endl;
  cout << "press 1 for adding a card:" << endl;
  cout << "press 2 for deleting a card:" << endl;
  cout << "press 3 for editing deck name:" << endl;
  cout << "press 4 for deck name and deck list:" << endl;
  cout << "press 5 for random hand generator:" << endl;
  cout << "press 6 for probabilty of drawing a card" << endl;
  cout << "press 9 to exit menu:" << endl;
}

std::vector<string>
yugioh::create (int count)
{
  string cardName;
  int num;
  int tracker = 0;
  for (int i = 1; i <= count; ++i)
  {
    std::cout
      << "enter the card name and how many you would like in the deck: ";
    std::cin >> num;
    std::cin >> cardName;
    i += num - 1;
    tracker += num;
    if (tracker > count)
    {
      cout << endl
           << "*an extra card(s) has been added, check deck list for extra  "
              "card(s)* "
           << endl;
    }
    for (int i = 0; i < num; ++i)
    {
      data.push_back (cardName);
    }
  }

  return data;
}

void
yugioh::generate ()
{
  int output;
  int first;
  int second;
  int third;
  int fourth;
  for (int i = 0; i < 5; ++i)
  {
    output = (rand () % (int)(data.size () - 1 + 1));
    if (i == 0)
    {
      first = output;
      cout << data[output] << endl;
    }
    if (i == 1)
    {
      while (output == first)
      {
        output = (rand () % (int)(data.size () - 1 + 1));
      }
      second = output;
      cout << data[output] << endl;
    }
    if (i == 2)
    {
      while (output == first || output == second)
      {
        output = (rand () % (int)(data.size () - 1 + 1));
      }
      third = output;
      cout << data[output] << endl;
    }
    if (i == 3)
    {
      while (output == first || output == second || output == third)
      {
        output = (rand () % (int)(data.size () - 1 + 1));
      }
      fourth = output;
      cout << data[output] << endl;
    }
    if (i == 4)
    {
      while (output == first || output == second || output == third ||
             output == fourth)
      {
        output = (rand () % (int)(data.size () - 1 + 1));
      }
      cout << data[output] << endl;
    }
  }
}
double
yugioh::hypergeometrictest (int n1_val, int n2_val, int n3_val, int n4_val)
{
  double pdf;
  unsigned int n1 = n1_val;
  unsigned int n2 = n2_val;
  unsigned int t = n3_val;
  unsigned int k = n4_val;
  // hg_dist(r,n,N)
  //r = success
  //n =
  boost::math::hypergeometric_distribution<double> hg_dist (n1, t, n1 + n2);
  pdf = boost::math::pdf<double> (hg_dist, k);

  return pdf;
}
double
yugioh::prob (string name)
{
  int count = 0;
  for (unsigned int i = 0; i < data.size (); ++i)
  {
    if (data[i] == name)
    {
      ++count;
    }
  }
  return this->hypergeometrictest (count, this->data.size () - count, 5, 1) *
         100;
}

