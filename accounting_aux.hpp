#ifndef ACC_AUX_H
#define ACC_AUX_H

#include <vector>
#include <string>
using namespace std;

struct PricedItem{
	PricedItem(string* id, double price);
	string* id;
	double price;
	string toString() const;
};

struct Participant{
	Participant(string* id, vector<string*>* item_id_list, bool disqualify_list);
	bool disqualify_list;
	string* id;
	vector<string*>* item_id_list;
	string toString() const;
};

struct Document{
	Document(vector<PricedItem>* priced_items, vector<Participant>* participants);
	vector<PricedItem>* priced_items;
	vector<Participant>* participants;
};	

#endif