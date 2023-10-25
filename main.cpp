////////////////////////////////////////////////////////////////////////////////
/// \file   main.cpp
/// \authors Kim Desroches et Raissa Oumarou Petitot
///
/// La fonction principale du programme et les fonctions du TD3.
////////////////////////////////////////////////////////////////////////////////

#include "bibliotheque_cours.hpp"
#include "verification_allocation.hpp"
#include "Liste.hpp"
#include "Concepteur.hpp"
#include "Jeu.hpp"
#include "lectureFichierJeux.hpp"
#include <iostream>
#include <fstream>
using namespace std;

//TODO: Vos surcharges d'opérateur <<

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{
	#pragma region "Bibliothèque du cours"
	// Permet sous Windows les "ANSI escape code" pour changer de couleur
	// https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac
	// les supportent normalement par défaut.
	bibliotheque_cours::activerCouleursAnsi(); 
	#pragma endregion
	
	Liste<Jeu> lj = creerListeJeux("jeux.bin");
	static const string ligneSeparation = "\n\033[92m"
		"══════════════════════════════════════════════════════════════════════════"
		"\033[0m\n";

	//TODO: Les l'affichage et l'écriture dans le fichier devraient fonctionner.
	//Question 6
	cout << ligneSeparation << lj;
	ofstream("sortie.txt") << lj;
	cout << ligneSeparation;

	//TODO: Compléter le main avec les tests demandés.
	//Question 3
	cout << "Tests question 3) : " << endl;
	cout << "\tNombre de jeux : " << lj.size() << endl
		<< "\tCapacite : " << lj.getCapacite() << endl;
	cout << endl;

	//Question 4
	cout << "Tests question 4) : " << endl;
	//Le titre du jeu à l'indice 2 et son concepteur à l'indice 1
	cout << '\t' << "" << lj[2]->getTitre() << endl
		<< '\t' << lj[2]->getConcepteur(1)->getNom() << endl;
	cout << endl;

	//Question 5
	cout << "Tests question 5) : " << endl;
	string nomExemple = "Yoshinori Kitase";
	auto critere = [=](const Concepteur& concepteur)-> bool {return nomExemple == concepteur.getNom(); };
	cout << "\tAdresse : " << lj[0]->trouverConcepteur(critere) << endl;
	cout << "\tAnnée : " << lj[0]->trouverConcepteur(critere)->getAnneeNaissance() << endl;
	cout << "\tAdresse : " << lj[1]->trouverConcepteur(critere) << endl;
	cout << "\tAnnée : " << lj[1]->trouverConcepteur(critere)->getAnneeNaissance() << endl;
	cout << endl;

	//Question 7
	cout << "Tests question 7) : " << endl;
	Jeu copieJeu = *lj[2];
	copieJeu.setConcepteur(1,lj[0]->getConcepteur(2));
	cout << *lj[2] << endl;
	cout << "Jeu copie et modifie : " << endl;
	cout << copieJeu;

	//TODO: S'assurer qu'aucune ligne de code est non couverte.
	//NOTE: Il n'est pas nécessaire de couvrir les getters/setters simples fournis; il faut tester si vous en ajoutez ou les modifiez.
	//NOTE: Pour Liste, qui est générique, on demande de couvrir uniquement pour Liste<Jeu>, pas pour tous les types.
}