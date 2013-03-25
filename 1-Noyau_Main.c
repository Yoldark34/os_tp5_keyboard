
#include "Ecran.h"
#include "Info_Boot.h"
#include "Alien.h"

void OS_Start(T_BOOT_INFO* P_Info) {
	Efface_Ecran();
	Affiche_Alien_2(VERT);
	Affiche_Chaine(">>>BOOT");
	BYTE prevColor = Donne_Couleur();
	Regle_Couleur(10);
	Affiche_Chaine("OK\n");

	if ((P_Info->Flags & BOOT_INFO_MEMOIRE) == BOOT_INFO_MEMOIRE) {
		Affiche_Chaine("\n Adresse Basse (640ko maxi) : ");
		Affiche_Chaine(Entier_Vers_Chaine_Hexa(P_Info->Adresse_Basse, 4));

		Affiche_Chaine("\n Adresse Haute (Au dessus des 1 Mo) : ");
		Affiche_Chaine(Entier_Vers_Chaine_Hexa(P_Info->Adresse_Haute, 4));
		Affiche_Chaine("\n\tIl y a donc : ");

		UINT32 L_Taille_Memoire = P_Info->Adresse_Basse + P_Info->Adresse_Haute + 1024;
		Affiche_Chaine(Entier_Vers_Chaine(L_Taille_Memoire));
		Affiche_Chaine(" Ko de memmoire --> ");
		Affiche_Chaine(Entier_Vers_Chaine(L_Taille_Memoire / 1024));
		Affiche_Chaine(" Mo ");
	}

	if ((P_Info->Flags & BOOT_LIGNE_COMMANDE) == BOOT_LIGNE_COMMANDE) {
		Affiche_Chaine("\n Ligne de commenda passée au noyau : ");
		Affiche_Chaine((UCHAR*) P_Info->Ligne_De_Commande);
	}

	if ((P_Info->Flags & BOOT_INFO_BOOTLOADER) == BOOT_INFO_BOOTLOADER) {
		Affiche_Chaine("\n Nom du bootloader: ");
		Affiche_Chaine((UCHAR*) P_Info->Nom_BootLoader);
	}
	Regle_Couleur(prevColor);

	while (1) {

		int i = 0;
		long boucle = 5000000L;

		Affiche_Alien_1(VERT);
		for (i = 0; i < boucle; i++) {
			asm("NOP");
		}


		Affiche_Alien_2(VERT);
		for (i = 0; i < boucle / 2; i++) {
			asm("NOP");
		}

	}
}
