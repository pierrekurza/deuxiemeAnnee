#!/bin/bash
pandoc --toc -t beamer -V theme:Madrid --template artois.beamer title.md soutenancePT.markdown --slide-level 2 -o soutenancePT.pdf
