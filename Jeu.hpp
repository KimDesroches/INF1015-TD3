////////////////////////////////////////////////////////////////////////////////
/// \file   Jeu.hpp
/// \authors Kim Desroches et Raissa Oumarou Petitot
///
/// Les déclarations et prototypes de la classe Jeu. 
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "Liste.hpp"
#include "Concepteur.hpp"
#include <string>
#include <memory>
#include <functional>

class Jeu
{
public:
	//TODO: un constructeur par défaut et un constructeur paramétré.
	Jeu() : titre_(""), anneeSortie_(0), developpeur_(""), concepteurs_(Liste<Concepteur>()) {};

	Jeu(std::string titre, unsigned anneeSortie, std::string developpeur) :titre_(titre), anneeSortie_(anneeSortie), developpeur_(developpeur), concepteurs_(Liste<Concepteur>()) {}
	
	//faire copie de Jeu
	Jeu(const Jeu& jeu) {
		*this = jeu;
	}
	Jeu& operator=(const Jeu& jeu) {
		titre_ = jeu.titre_;
		anneeSortie_ = jeu.anneeSortie_;
		developpeur_ = jeu.developpeur_;
		concepteurs_ = jeu.concepteurs_;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, Jeu& jeu) { return jeu.affichage(os); }

	std::ostream& affichage(std::ostream& os) {
		std::string ligneSeparation = "\033[94m""******************************************************""\033[0m\n";
		os << ligneSeparation << titre_ << " , " << anneeSortie_ << " , " << developpeur_ << std::endl << concepteurs_ << std::endl;
		return os;
	}

	const std::string& getTitre() const     { return titre_; }
	void setTitre(const std::string& titre) { titre_ = titre; }
	unsigned getAnneeSortie() const         { return anneeSortie_; }
	void setAnneeSortie(unsigned annee)     { anneeSortie_ = annee; }
	const std::string& getDeveloppeur() const { return developpeur_; }
	void setDeveloppeur(const std::string& developpeur) { developpeur_ = developpeur; }

	//TODO: Pouvoir accéder à la liste de concepteurs.
	std::shared_ptr<Concepteur>& getConcepteur(unsigned index) { return concepteurs_[index]; }
	void setConcepteur(unsigned index, std::shared_ptr<Concepteur>concepteur) { concepteurs_[index] = concepteur; }

	//TODO: Votre méthode pour trouver un concepteur selon un critère donné par une lambda, en utilisant la méthode de Liste.
	std::shared_ptr<Concepteur> trouverConcepteur(std::function<bool(const Concepteur&)> critere) {
		return concepteurs_.trouverElement(critere);
	}

	//Méthode pour ajouter un concepteur à la liste
	void ajouterConcepteur(std::shared_ptr<Concepteur> concepteur) {
			concepteurs_.ajouterElement(std::move(concepteur));
	}
private:
	std::string titre_;
	unsigned anneeSortie_;
	std::string developpeur_;
	//TODO: Attribut de la liste des concepteurs du jeu
	Liste<Concepteur> concepteurs_;

};
