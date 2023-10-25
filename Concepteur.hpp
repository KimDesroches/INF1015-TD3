////////////////////////////////////////////////////////////////////////////////
/// \file   Concepteur.hpp
/// \authors Kim Desroches et Raissa Oumarou Petitot
///
/// Les déclarations et prototypes de la classe Concepteur. 
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <string>

class Concepteur
{
public:
	//TODO: Un constructeur par défaut et un constructeur paramétré.
	Concepteur() : nom_(""), anneeNaissance_(NULL), pays_("") {}
	Concepteur(std::string nom, unsigned anneeNaissance, std::string pays) : nom_(nom), anneeNaissance_(anneeNaissance), pays_(pays) {}
	
	friend std::ostream& operator<<(std::ostream& os, Concepteur concepteur) {return concepteur.affichage(os);}

	std::ostream& affichage(std::ostream& os) {
		os << '\t' << nom_ << " , " << anneeNaissance_ << " , " << pays_ << std::endl;
		return os;
	}

	const std::string& getNom() const     { return nom_; }
	void setNom(const std::string& nom)   { nom_ = nom; }
	int getAnneeNaissance() const         { return anneeNaissance_; }
	void setAnneeNaissance(int annee)     { anneeNaissance_ = annee; }
	const std::string& getPays() const    { return pays_; }
	void setPays(const std::string& pays) { pays_ = pays; }

private:
	std::string nom_;
	unsigned anneeNaissance_;
	std::string pays_;
};
