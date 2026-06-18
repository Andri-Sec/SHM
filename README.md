# SHM-Scanner 🔍

[![Status](https://img.shields.io/badge/status-Work__In__Progress-orange)](#)

Un scanner furtif de mémoire partagée (System V & POSIX) développé en C, respectant la Norme 42.

## 🚀 Objectifs du Projet
Le but de cet outil est de parser `/proc/[PID]/maps` pour identifier, s'attacher et scanner les segments de mémoire partagée (`/dev/shm`) afin d'y détecter des chaînes de caractères spécifiques ou des payloads.

## 🛠️ Fonctionnalités prévues & État d'avancement
- [x] Parsing de `/proc/[PID]/maps`
- [x] Attachement aux segments POSH SHM via `mmap`
- [ ] Implémentation de l'algorithme de recherche de strings (En cours)
- [ ] Intégration des règles YARA (À faire)

## 📦 Installation & Compilation

Le projet utilise un `Makefile` standard.

