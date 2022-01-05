#include "accounting_aux.hpp"

PricedItem::PricedItem(string* id, double price)
		:id(id), price(price){}

string PricedItem::toString() const{
	return *id + " : " + to_string(price);
}

Participant::Participant(string* id, vector<string*>* item_id_list)
		:id(id), item_id_list(item_id_list){}

string Participant::toString() const{
	string result = "id : " + *id+"\n";
	for(string* item: *item_id_list){
		result += "\t" + *item + "\n";
	}
	return result;
}

Document::Document(vector<PricedItem>* priced_items, vector<Participant>* participants)
		:priced_items(priced_items), participants(participants){}