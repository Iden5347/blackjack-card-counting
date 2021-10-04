#include <iostream>
#include <array>
#include <vector>

using namespace std;

void vectorPrint (vector<int> vector) {
  for(int i = 0; i < vector.size(); i++) {
    cout << vector[i] << " ";
  }
}

void shuffleDeck(vector<int> *deck, int numOfDecks) {
  int values[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 ,11};
  vector<int> orderedDeck(52 * numOfDecks, 0);
  for(int i = 0; i < numOfDecks * 4; i++) {
    for(int j = 0; j < 13; j++) {
      orderedDeck[i * 13 + j] = values[j];
    };
  };
  vector<int> shuffledDeck(52 * numOfDecks, 0);
  for(int i = 0; i < 52 * numOfDecks; i++) {
    int randomNum = rand() % orderedDeck.size();
    shuffledDeck[i] = orderedDeck[randomNum];
    orderedDeck.erase(orderedDeck.begin()+randomNum);
  }
  *deck = shuffledDeck;
}

int main() {
  bool allowDas, allowEarlySurrender, allowLateSurrender, allowResplitAces, allowResplitPairs, allowDoubleOnAll/*, allowMidShoeEnter*/, standOnSoftSeventeen;
  int numOfDecks;
  float blackjackPayout;

  cout << "This is a simulator for American/Las Vegas strip blackjack. When true/false, true is 1 and false is 0." << endl;
  cout << "numOfDecks: ";
  cin >> numOfDecks;
  cout << "allowDas: ";
  cin >> allowDas;
  cout <<"allowEarlySurrender: ";
  cin >> allowEarlySurrender;
  cout << "allowLateSurrender: ";
  cin >> allowLateSurrender;
  cout << "allowResplitAces: ";
  cin >> allowResplitAces;
  cout << "allowResplitPairs: ";
  cin >> allowResplitPairs;
  cout << "allowDoubleOnAll: ";
  cin >> allowDoubleOnAll;
  cout << "standOnSoftSeventeen: ";
  cin >> standOnSoftSeventeen;
  cout << "standOnSoftSeventeen: ";
  cin >> blackjackPayout;

  cout << numOfDecks << allowDas <<endl << allowEarlySurrender << allowLateSurrender << allowResplitAces << allowResplitPairs << allowDoubleOnAll << standOnSoftSeventeen  << blackjackPayout << endl;


  vector<int> deck(52 * numOfDecks, 0);
  shuffleDeck(&deck, numOfDecks);
  vectorPrint(deck);

  cout << endl << endl;
  return 0;
}
