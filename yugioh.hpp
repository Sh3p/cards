#ifndef YUGIOH_H
#define YUGIOH_H

#include <boost/math/distributions/hypergeometric.hpp>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class yugioh
{
public:
  yugioh ();

  ~yugioh ();

  yugioh (string);

  string
  getDeck () const;

  int
  getSize () const;

  std::vector<string>
  create (int count);

  int
  addCard (string name);

  void
  deckInfo (std::vector<string>& a);

  void
  menu ();

  int
  eraseCard (string name);

  void
  setDeckName (string name);

  void
  deckList ();

  double prob (string);

  void
  generate ();
  double
  hypergeometrictest (int, int, int, int);
  
private:
  string deck_name;
  int deck_size;
  std::vector<string> data;
};

#endif