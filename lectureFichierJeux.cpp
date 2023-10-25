////////////////////////////////////////////////////////////////////////////////
/// \file   lectureFichierJeux.cpp
/// \authors Kim Desroches et Raissa Oumarou Petitot
///
/// Fonctions pour la lecture de fichier jeux.
////////////////////////////////////////////////////////////////////////////////

// Fonctions pour lire le fichier binaire.
#include "lectureFichierJeux.hpp"
#include <fstream>
#include "cppitertools/range.hpp"
using namespace std;

#pragma region "Fonctions de lecture de base"
UInt8 lireUint8(istream& fichier)
{
	UInt8 valeur = 0;
	fichier.read(reinterpret_cast<char*>(&valeur), sizeof(valeur));
	return valeur;
}

UInt16 lireUint16(istream& fichier)
{
	UInt16 valeur = 0;
	fichier.read(reinterpret_cast<char*>(&valeur), sizeof(valeur));
	return valeur;
}

string lireString(istream& fichier)
{
	string texte;
	texte.resize(lireUint16(fichier));
	fichier.read(reinterpret_cast<char*>(&texte[0]), streamsize(sizeof(texte[0])) * texte.length());
	return texte;
}
#pragma endregion

shared_ptr<Concepteur> chercherConcepteur(Liste<Jeu>& listeJeux, string nom)
{
	//TODO: Compléter la fonction (équivalent de trouverDesigner du TD2).
	auto critere = [=](const Concepteur& concepteur) {return nom == concepteur.getNom(); };
	shared_ptr<Concepteur> concepteur = make_shared<Concepteur>();
	for (unsigned i = 0; i < listeJeux.size(); i++) {
		concepteur = listeJeux[i]->trouverConcepteur(critere);
		if (concepteur != nullptr)
			return concepteur;
	}
	return nullptr;
}	

shared_ptr<Concepteur> lireConcepteur(Liste<Jeu>& lj, istream& f)
{
	string nom              = lireString(f);
	unsigned anneeNaissance = lireUint16(f);
	string pays             = lireString(f);

	//TODO: Compléter la fonction (équivalent de lireDesigner du TD2).
	if(chercherConcepteur(lj, nom) == nullptr)
		return make_shared<Concepteur>(nom, anneeNaissance, pays);
	return chercherConcepteur(lj, nom);
}

shared_ptr<Jeu> lireJeu(istream& f, Liste<Jeu>& lj)
{
	string titre          = lireString(f);
	unsigned anneeSortie  = lireUint16(f);
	string developpeur    = lireString(f);
	unsigned nConcepteurs = lireUint8(f);

	//TODO: Attribut de la liste des concepteurs du jeu
	auto jeu = make_shared<Jeu>(titre, anneeSortie, developpeur);

	//TODO: Compléter la fonction (équivalent de lireJeu du TD2).
	for (unsigned int i = 0; i < nConcepteurs; i++)
		jeu->ajouterConcepteur(move(lireConcepteur(lj, f)));

	return jeu;
}

Liste<Jeu> creerListeJeux(const string& nomFichier)
{
	ifstream f(nomFichier, ios::binary);
	f.exceptions(ios::failbit);
	int nElements = lireUint16(f);
	//TODO: Compléter la fonction.
	Liste<Jeu> listeJeux;
	for ([[maybe_unused]] int i : iter::range(nElements))
		listeJeux.ajouterElement(move(lireJeu(f, listeJeux)));
	
	return listeJeux ;
}
