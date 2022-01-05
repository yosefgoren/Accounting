#include "Accountant.hpp"
#include <iostream>
#include <assert.h>

//=========================== public ====================================
Accountant::Accountant(Document document, bool delete_document_after_initialization, bool verbose){
	if(verbose){
		printDocumentContent(document);
	}
	initializeItemDetails(document);
	initializeParticipantsDetails(document);
	if(delete_document_after_initialization){
		deleteDocument(document);
	}
}

void Accountant::printCostsPerParticipant(){
	cout << "printing participant prices:" << endl;
	map<string, double> participant_prices = getCostsPerParticipant();
	for(pair<const string, double> p: participant_prices){
		cout << "\t" << p.first << " : " << p.second << endl;
	}
}

map<string, double> Accountant::getCostsPerParticipant(){
	map<string, double> participant_prices;
	for(pair<const string, set<string>> p: participants_details){
		participant_prices.insert(pair<string, double>(p.first, 0));
	}
	for(pair<const string, double> p: items_details){
		const string& item_id = p.first;
		set<string> participants_paying = getParticipantsPayingFor(item_id);
		if(participants_paying.size() == 0){
			cout << "error: no one is paying for: " << item_id << "." << endl;
			exit(1);
		}
		double price = p.second;
		double price_per_participant = price/participants_paying.size();
		for(const string& participant_id: participants_paying){
			participant_prices[participant_id] += price_per_participant;
		}
	}
	return participant_prices;
}

void Accountant::printDocumentContent(Document document){
	cout << "printing document detials." << endl;
	vector<PricedItem>* priced_items = document.priced_items;
	cout << "items list:" << endl;
	for(auto item: *priced_items){
		cout << "\t" << item.toString() << endl;
	}

	vector<Participant>* participants = document.participants;
	for(auto item: *participants){
		cout << item.toString();
	}
}
//TODO:
void Accountant::deleteDocument(Document document){
	//currently memleak.
}

//=========================== private ====================================
void Accountant::initializeItemDetails(Document document){
	for(PricedItem item: *document.priced_items){
		items_details.insert(pair<string, double>(*item.id, item.price));
	}
}

void Accountant::initializeParticipantsDetails(Document document){
	for(Participant participant: *document.participants){
		participants_details.insert(std::pair<string, set<string>>(*participant.id, set<string>()));
		set<string>& wanted_items_set = participants_details[*participant.id];
		for(string* item_id: *participant.item_id_list){
			wanted_items_set.insert(*item_id);
		}
	}
}
set<string> Accountant::getParticipantsPayingFor(const string& item_id){
	set<string> participants;
	for(pair<const string, set<string>>& p: participants_details){
		if(p.second.count(item_id))
			participants.insert(p.first);
	}
	return participants;
}