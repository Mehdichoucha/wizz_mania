architecture du projet :
 wizz-mania/
├── common/
│   └── protocol.h
├── server/
│   ├── Server.h
│   ├── Server.cpp
│   └── main_server.cpp
├── client/
│   ├── Client.h
│   ├── Client.cpp
│   ├── main_client.cpp
│   └── ui/   (Qt plus tard)
└── CMakeLists.txt


planning : 
 Planning WIZZ Mania – 2 semaines
Semaine 1 : Mise en place et développement de base

Jour
Tâches Serveur (A)
Tâches Client (B)
Tâches Interface / Tests / Rendu (C)
Jour 1
Installation environnement C++, Qt, Git
Idem
Création maquettes UI et diagramme architecture
Jour 2
Création serveur TCP, écoute des connexions
Création client TCP, connexion au serveur
Préparer wireframes et design de l’écran de chat
Jour 3
Gestion multi-clients (threads)
Envoi / réception messages simples
Commencer intégration de l’UI Qt pour fenêtre connexion
Jour 4
Gestion des wizz et déconnexions propres
Gestion du wizz côté client
Préparer checklists de tests unitaires et multi-client
Jour 5
Tests unitaires côté serveur
Tests unitaires côté client
Intégration UI fenêtre chat (zone message, champ saisie)
💡 Objectif fin semaine 1 :


Serveur et client fonctionnels en console (connexion, message simple, wizz).


UI de base prête à être intégrée.



Semaine 2 : Intégration, tests et rendu

Jour
Tâches Serveur (A)
Tâches Client (B)
Tâches Interface / Tests / Rendu (C)
Jour 6
Optimisation serveur, logs, stabilité
Optimisation client, gestion erreurs
Intégration UI complète (bouton Wizz, notifications)
Jour 7
Tests multi-clients
Tests multi-clients
Début tests UI et ergonomie
Jour 8
Correction bugs serveur
Correction bugs client
Tests robustesse (déconnexions, messages simultanés)
Jour 9
Validation communication complète
Validation communication complète
Préparer slides + capture écran / scénario démo
Jour 10
Revue finale du serveur
Revue finale du client
Finalisation UI + démo + support présentation
💡 Objectif fin semaine 2 :


Application client/serveur fonctionnelle avec interface Qt.


Tests réalisés et bugs critiques corrigés.


Slides et démo prêts pour la soutenance.



✅ Conseils pratiques :


Chaque jour : synchronisation rapide (10‑15 min) pour signaler blocages.


Commit Git quotidien pour ne pas perdre les avancées.


Les bugs bloquants doivent être notés sur Trello directement dans “Bugs & Problèmes”.


shéma client/serveur : 

[ Client Qt ] ─┐
[ Client Qt ] ─┼── TCP ──> [ Serveur ]
[ Client Qt ] ─┘