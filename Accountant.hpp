#ifndef ACCOUNTANT_H
#define ACCOUNTANT_H

#include "accounting_aux.hpp"
#include <map>
#include <set>
using namespace std;

class Accountant{
public:
	Accountant(Document document, bool delete_document_after_initialization = true, bool verbose = true);
	void printCostsPerParticipant();
	map<string, double> getCostsPerParticipant();

	static void printDocumentContent(Document document);
	static void deleteDocument(Document document);

private:
	map<string, double> items_details;
	map<string, set<string>> participants_details;

	void initializeItemAndParticipantsDetails(Document document);
	void initializeParticipantsDetails(Document document);
	void initializeItemDetails(Document document);
	set<string> getParticipantsPayingFor(const string& item_id);
};

#endif