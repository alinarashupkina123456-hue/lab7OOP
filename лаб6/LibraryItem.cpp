#include "LibraryItem.h"

void LibraryItem::Write(std::ofstream& fout) const {
	fout << title << "\n" << author << "\n" << year << "\n";
}

void LibraryItem::Read(std::ifstream& fin) {
	fin >> title >> author >> year;
}