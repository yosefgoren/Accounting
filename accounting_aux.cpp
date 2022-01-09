#include "accounting_aux.hpp"

PricedItem::PricedItem(string* id, double price)
		:id(id), price(price){}

string PricedItem::toString() const{
	return *id + " : " + to_string(price);
}

Participant::Participant(string* id, vector<string*>* item_id_list, bool disqualify_list)
		:id(id), item_id_list(item_id_list), disqualify_list(disqualify_list){}

string Participant::toString() const{
	string result = *id+(disqualify_list?" does not want":"wants")+":"+"\n";
	for(string* item: *item_id_list){
		result += "\t" + *item + "\n";
	}
	return result;
}

Document::Document(vector<PricedItem>* priced_items, vector<Participant>* participants)
		:priced_items(priced_items), participants(participants){}