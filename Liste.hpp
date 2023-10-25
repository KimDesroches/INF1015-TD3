////////////////////////////////////////////////////////////////////////////////
/// \file   Liste.hpp
/// \authors Kim Desroches et Raissa Oumarou Petitot
///
/// Les d�clarations et prototypes de la classe Liste. 
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <iostream>
#include <memory>
#include <cassert>
#include "gsl/span"
#include "cppitertools/range.hpp"

template <typename T>
class Liste
{
public:
	//TODO: Constructeurs et surcharges d'op�rateurs
	Liste() : nElements_(0), capacite_(1), elements_(std::make_unique<std::shared_ptr<T>[]>(capacite_)) {}

	Liste(const Liste<T>& list) {
		*this = list;
	}
	Liste<T>& operator= (const Liste<T>& list) {
		elements_ = std::make_unique<std::shared_ptr<T>[]>(list.capacite_);
		capacite_ = list.capacite_;
		nElements_ = list.nElements_;
		for (unsigned i = 0; i < nElements_; i++) {
			elements_[i] = list.elements_[i];
		}
		return *this;
	}

	std::shared_ptr<T>& operator[](unsigned index) {
		return elements_[index];
	}

	friend std::ostream& operator<<(std::ostream& os, Liste<T> liste) { return liste.affichage(os); }

	std::ostream& affichage(std::ostream& os){
		for (unsigned i = 0; i < nElements_; i++)
			os << *elements_[i];
		return os;
	}

	//TODO: M�thode pour ajouter un �l�ment � la liste
	void ajouterElement(std::shared_ptr<T> element) {
		if (nElements_ == capacite_)
			changerCapacite();
		elements_[nElements_] = std::move(element);
		nElements_++;			
	}

	// Pour size, on utilise le m�me nom que les accesseurs de la biblioth�que standard, qui permet d'utiliser certaines fonctions de la bibliotheque sur cette classe.
	unsigned size() const         { return nElements_; }
	unsigned getCapacite() const  { return capacite_; }
	void setSize(unsigned nElements) { nElements_ = nElements; }

	//TODO: M�thode pour changer la capacit� de la liste
	void changerCapacite() {
		capacite_ = 2 * capacite_;
		auto ptrElements = std::make_unique<std::shared_ptr<T>[]>(capacite_);
		for (unsigned i = 0; i < nElements_; i++)
			ptrElements[i] = std::move(elements_[i]);
		elements_ = std::move(ptrElements);		
	}

	//TODO: M�thode pour trouver une �l�ment selon un crit�re (lambda).
	std::shared_ptr<T> trouverElement(std::function <bool(const T&)> critere) const {
		for (unsigned i = 0; i < nElements_; i++)
			if(critere(*elements_[i]))
				return elements_[i];
		return nullptr;
	}

private:
	unsigned nElements_;
	unsigned capacite_;
	//TODO: Attribut contenant les �l�ments de la liste.
	std::unique_ptr<std::shared_ptr<T>[]> elements_;
	
};
