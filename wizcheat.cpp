/*

    wizcheat.cpp

    Copyright © 2021 Oka Motofumi <chikuzen.mo at gmail dot com>

    This work is free. You can redistribute it and/or modify it under the
    terms of the Do What The Fuck You Want To Public License, Version 2,
    as published by Sam Hocevar. See the COPYING file for more details.

*/



#include <cstdint>
#include <cstring>
#include <iostream>
#include <fstream>
#include <filesystem>
#include "json.hpp"


auto json = R"***(
{
    "scenario": [
        "#1 PROVING GROUNDS OF THE MAD OVERLORD!",
        "#2 THE KNIGHT OF DIAMONDS",
        "#3 THE LEGACY OF LLYLGAMYN"
    ],
    "condition": [
        "OK",
        "ASLEEP",
        "AFRAID",
        "PARALY",
        "STONED",
        "DEAD",
        "ASHED",
        "LOST"
    ],
    "race": [
        "NO RACE",
        "HUMAN",
        "ELF",
        "DWARF",
        "GNOME",
        "HOBBIT"
    ],
    "class": [
        "FIGHTER",
        "MAGE",
        "PRIEST",
        "THIEF",
        "BISHOP",
        "SAMURAI",
        "LORD",
        "NINJA"
    ],
    "alignment": [
        "UNALIGN",
        "GOOD",
        "NEUTRAL",
        "EVIL"
    ],
    "experience": {
        "FIGHTER": 289709,
        "MAGE": 318529,
        "PRIEST": 304132,
        "THIEF": 260639,
        "BISHOP": 438479,
        "SAMURAI": 456601,
        "LORD": 475008,
        "NINJA": 529757
    },
    "itemlist": [
        [
            "BROKEN ITEM",       "LONG SWORD",        "SHORT SWORD",       "ANOINTED MACE",   "ANOINTED FLAIL",
            "STAFF",             "DAGGER",            "SMALL SHIELD",      "LARGE SHIELD",    "ROBES",
            "LEATHER ARMOR",     "CHAIN MAIL",        "BREAST PLATE",      "PLATE MAIL",      "HELM",
            "POSITIONofDIOS",    "POTIONofLATUMOFIS", "LONG SWORD+1",      "SHORT SWORD+1",   "MACE+1",
            "STAFFofMOGREF",     "SCROLLofKATINO",    "LEATHER+1",         "CHAIN MAIL+1",    "PLATE MAIL+1",
            "SHIELD+1",          "BREAST PLATE+1",    "SCROLLofBADIOS[A]", "SCROLLofHALITO",  "LONG SWORD-1",
            "SHORT SWORD-1",     "MACE-1",            "STAFF+2",           "SLAYERofDRAGONS", "HELM+1",
            "LEATHER-1",         "CHAIN-1",           "BREAST PLATE-1",    "SHIELD-1",        "AMULETofJEWELS",
            "SCROLLofBADIOS[B]", "POTIONofSOPIC",     "LONG SWORD+2",      "SHORT SWORD+2",   "MACE+2",
            "SCROLLofLOMILWA",   "SCROLLofDILTO",     "GLOVESofCOPPER",    "LEATHER+2",       "CHAIN+2",
            "PLATE MAIL+2",      "SHIELD+2",          "HELM+2 (E)",        "POTIONofDIAL",    "RINGofPORFIC",
            "WERE SLAYER",       "MAGE MASHER",       "MACEofPOISON",      "STAFFofMONTINO",  "BLADE CUSINART'",
            "AMULETofMANIFO",    "RODofFLAME",        "CHAIN+2 (E)",       "PLATE+2 (N)",     "SHIELD+3 (E)",
            "AMULETofMAKANITO",  "HELMofMALOR",       "SCROLLofBADIAL",    "SHORT SWORD-2",   "DAGGER+2",
            "MACE-2",            "STAFF-2",           "DAGGERofSPEED",     "ROBEofCURSES",    "LEATHER-2",
            "CHAIN-2",           "BREAST PLATE-2",    "SHIELD-2",          "HELMofCURSES",    "BREAST PLATE+2",
            "GLOVESofSILVER",    "SWORD+3 (E)",       "S-SWORD+3 (E)",     "DAGGERofTHIEVES", "BREAST PLATE+3",
            "GARBofLORDS",       "MURAMASA BLADE!",   "SHURIKENS",         "COLD CHAIN MAIL", "PLATE+3 (E)",
            "SHIELD+3",          "RINGofHEALING",     "PRIESTS RING",      "RINGofDEATH!",    "AMULETofWERDNA",
            "STATUEofBEAR",      "STATUEofFROG",      "KEYofBRONZE",       "KEYofSILVER",     "KEYofGOLD",
            "BLUE RIBBON",       "**ERR**",           "**ERR**",           "**ERR**",         "**ERR**",
            "**ERR**",           "**ERR**",           "**ERR**",           "**ERR**",         "**ERR**"
        ],
        [
            "BROKEN ITEM",       "LONG SWORD",        "SHORT SWORD",       "ANOINTED MACE",   "ANOINTED FLAIL",
            "STAFF",             "DAGGER",            "SMALL SHIELD",      "LARGE SHIELD",    "ROBES",
            "LEATHER ARMOR",     "CHAIN MAIL",        "BREAST PLATE",      "PLATE MAIL",      "HELM",
            "POSITIONofDIOS",    "POTIONofLATUMOFIS", "LONG SWORD+1",      "SHORT SWORD+1",   "MACE+1",
            "STAFFofMOGREF",     "SCROLLofKATINO",    "LEATHER+1",         "CHAIN MAIL+1",    "PLATE MAIL+1",
            "SHIELD+1",          "BREAST PLATE+1",    "SCROLLofBADIOS[A]", "SCROLLofHALITO",  "LONG SWORD-1",
            "SHORT SWORD-1",     "MACE-1",            "STAFF+2",           "SLAYERofDRAGONS", "HELM+1",
            "LEATHER-1",         "CHAIN-1",           "BREAST PLATE-1",    "SHIELD-1",        "AMULETofJEWELS",
            "SCROLLofBADIOS[B]", "POTIONofSOPIC",     "LONG SWORD+2",      "SHORT SWORD+2",   "MACE+2",
            "SCROLLofLOMILWA",   "SCROLLofDILTO",     "GLOVESofCOPPER",    "LEATHER+2",       "CHAIN+2",
            "PLATE MAIL+2",      "SHIELD+2",          "HELM+2 (E)",        "POTIONofDIAL",    "RINGofPORFIC",
            "WERE SLAYER",       "MAGE MASHER",       "MACEofPOISON",      "STAFFofMONTINO",  "BLADE CUSINART'",
            "AMULETofMANIFO",    "RODofFLAME",        "CHAIN+2 (E)",       "PLATE+2 (N)",     "SHIELD+3 (E)",
            "AMULETofMAKANITO",  "HELMofMALOR",       "SCROLLofBADIAL",    "SHORT SWORD-2",   "DAGGER+2",
            "MACE-2",            "STAFF-2",           "DAGGERofSPEED",     "ROBEofCURSES",    "LEATHER-2",
            "CHAIN-2",           "BREAST PLATE-2",    "SHIELD-2",          "HELMofCURSES",    "BREAST PLATE+2",
            "GLOVESofSILVER",    "SWORD+3 (E)",       "S-SWORD+3 (E)",     "DAGGERofTHIEVES", "BREAST PLATE+3",
            "GARBofLORDS",       "MURAMASA BLADE!",   "SHURIKENS",         "COLD CHAIN MAIL", "PLATE+3 (E)",
            "SHIELD+3",          "RINGofHEALING",     "PRIESTS RING",      "RINGofDEATH!",    "RODofRISING",
            "AMULETofCOVER",     "ROBE+3",            "WINTER MITTENS",    "MAGIC CHARMS",    "STAFFofLIGHT",
            "LONG SWORD+5",      "SWORDofSWINGS",     "PRIEST PUNCHER",    "PRIEST'S MACE",   "S-SWORDofSWINGS",
            "RINGofFIRE",        "CURSED PLATE+1",    "PLATE+5",           "STAFFofCURING",   "RINGofLIFE",
            "METAMORPH RING",    "GRANITE STONE",     "DREAMER'S STONE",   "DAMIEN STONE",    "WANDofMAGES",
            "COINofPOWER",       "STONEofYOUTH",      "MIND STONE",        "STONEofPIETY",    "BLARNEY STONE",
            "AMULETofSKILL",     "AMULETofSKILL[U]",  "WANDofMAGES[U]",    "COINofPOWER[U]",  "STAFFofGNILDA",
            "HRATHNIR",          "KOD'S HELM",        "KOD'S SHIELD",      "KOD'S GAUNTLETS", "KOD'S ARMOR"
        ],
        [
            "BROKEN ITEM",       "ORBofEARITHIN",   "NEUTRAL CRYSTAL",    "CRYSTALofEVIL",   "CRYSTALofGOOD",
            "SHIP IN BOTTLE",    "STAFFofEARTH",    "AMULETofAIR",        "HOLY WATER",      "RODofFIRE",
            "GOLD MEDALLION",    "ORBofMHUUZFES",   "BUTTERFLY KNIFE[U]", "SHORT SWORD",     "BROADSWORD",
            "MACE",              "STAFF",           "HAND AXE",           "BATTLE AXE",      "DAGGER",
            "FLAIL",             "ROUND SHIELD",    "HEATER SHIELD",      "MAGE'S ROBES",    "CUIRASS",
            "HAUBERK",           "BREASTPLATE",     "PLATE ARMOR",        "SALLET",          "POTIONofDIOS",
            "POTIONofLATUMOFIS", "SHORT SWORD+1",   "BROADSWORD+1",       "MACE+1",          "BATTLE AXE+1",
            "NUNCHAKA",          "DAGGER+1",        "SCROLLofKATINO",     "CUIRASS+1",       "HAUBERK+1",
            "BREASTPLATE+1",     "PLATE ARMOR+1",   "HEATER+1",           "BASCINET",        "GLOVESofIRON",
            "SCROLLofBADIOS",    "POTIONofHALITO",  "SHORT SWORD-1",      "BROADSWORD-1",    "MACE-1",
            "DAGGER-1",          "BATTLE AXE-1",    "MARGAUX'S FLAIL",    "BAGofGEMS",       "WIZARD'S STAFF",
            "FLAMETONGUE",       "ROUND SHIELD-1",  "CUIRASS-1",          "HAUBERK-1",       "BREASTPLATE-1",
            "PLATE ARMOR-1",     "SALLET-1",        "ofSOPIC",            "GOLD RING",       "SALAMANDER RING",
            "SERPENT'S TOOTH",   "SHORT SWORD+2",   "BROADSWORD+2",       "BATTLE AXE+2",    "IVORY BLADE (G)",
            "EBONY BLADE (E)",   "AMBER BLADE (N)", "MACE+2",             "GLOVESofMITHRIL", "AMULETofDIALKO",
            "CUIRASS+2",         "HEATER+2",        "DISPLACER ROBES",    "HAUBERK+2",       "BREASTPLATE+2",
            "PLATE ARMOR+2",     "ARMET",           "WARGAN ROBES",       "GIANT'S CLUB",    "BLADE CUISINART'",
            "SHEPHERD CROOK",    "UNHOLY AXE",      "RODofDEATH",         "GEMofEXORCISM",   "BAGofEMERALDS",
            "BAGofGARNETS",      "BLUE PEARL",      "RUBY SLIPPERS",      "NECROLOGY ROD",   "BOOKofLIFE",
            "BOOKofDEATH",       "DRAGON'S TOOTH",  "TROLLKIN RING",      "RABBIT'S FOOT",   "THIEF'S PICK",
            "BOOKofDEMONS",      "BUTTERFLY KNIFE", "GOLD TIARA",         "MANTIS GLOVES"
        ]
    ],
)***"
R"***(
    "itemset": [
        {
            "FIGHTER": {
                "GOOD": [
                    "BLADE CUSINART'", "SHIELD+3", "PLATE MAIL+2", "HELMofMALOR", "GLOVESofSILVER", "RINGofHEALING"
                ],
                "NEUTRAL": [
                    "BLADE CUSINART'", "SHIELD+3", "PLATE MAIL+2", "HELMofMALOR", "GLOVESofSILVER", "RINGofHEALING"
                ],
                "EVIL": [
                    "BLADE CUSINART'", "SHIELD+3", "PLATE+3 (E)", "HELM+2 (E)", "GLOVESofSILVER", "RINGofHEALING"
                ]
            },
            "MAGE": {
                "GOOD": [
                    "DAGGERofSPEED", "HELMofMALOR", "RINGofHEALING"
                ],
                "NEUTRAL": [
                    "DAGGERofSPEED", "HELMofMALOR", "RINGofHEALING"
                ],
                "EVIL": [
                    "DAGGERofSPEED", "HELMofMALOR", "RINGofHEALING"
                ]
            },
            "PRIEST": {
                "GOOD": [
                    "MACE+2", "SHIELD+3", "COLD CHAIN MAIL", "HELMofMALOR", "RINGofHEALING"
                ],
                "NEUTRAL": [
                    "MACE+2", "SHIELD+3", "COLD CHAIN MAIL", "HELMofMALOR", "RINGofHEALING"
                ],
                "EVIL": [
                    "MACE+2", "SHIELD+3", "PLATE+3 (E)", "HELMofMALOR", "RINGofHEALING"
                ]
            },
            "THIEF": {
                "GOOD": [
                    "SHORT SWORD+2", "SHIELD+3", "LEATHER+2", "HELMofMALOR", "RINGofHEALING"
                ],
                "NEUTRAL": [
                    "SHORT SWORD+2", "SHIELD+3", "LEATHER+2", "HELMofMALOR", "RINGofHEALING"
                ],
                "EVIL": [
                    "S-SWORD+3 (E)", "SHIELD+3", "LEATHER+2", "HELMofMALOR", "RINGofHEALING"
                ]
            },
            "BISHOP": {
                "GOOD": [
                    "MACE+2", "LEATHER+2", "HELMofMALOR", "RINGofHEALING"
                ],
                "NEUTRAL": [
                    "MACE+2", "LEATHER+2", "HELMofMALOR", "RINGofHEALING"
                ],
                "EVIL": [
                    "MACE+2", "LEATHER+2", "HELMofMALOR", "RINGofHEALING"
                ]
            },
            "SAMURAI": {
                "GOOD": [
                    "MURAMASA BLADE!", "SHIELD+3", "PLATE MAIL+2", "HELMofMALOR", "GLOVESofSILVER", "RINGofHEALING"
                ],
                "NEUTRAL": [
                    "MURAMASA BLADE!", "SHIELD+3", "PLATE MAIL+2", "HELMofMALOR", "GLOVESofSILVER", "RINGofHEALING"
                ],
                "EVIL": [
                    "MURAMASA BLADE!", "SHIELD+3", "PLATE+3 (E)", "HELM+2 (E)", "GLOVESofSILVER", "RINGofHEALING"
                ]
            },
            "LORD": {
                "GOOD": [
                    "BLADE CUSINART'", "SHIELD+3", "GARBofLORDS", "HELMofMALOR", "GLOVESofSILVER", "RINGofHEALING"
                ],
                "NEUTRAL": [
                    "BLADE CUSINART'", "SHIELD+3", "PLATE MAIL+2", "HELMofMALOR", "GLOVESofSILVER", "RINGofHEALING"
                ],
                "EVIL": [
                    "BLADE CUSINART'", "SHIELD+3", "PLATE+3 (E)", "HELM+2 (E)", "GLOVESofSILVER", "RINGofHEALING"
                ]
            },
            "NINJA": {
                "GOOD": [
                    "SHURIKENS", "SHIELD+3", "PLATE MAIL+2", "HELMofMALOR", "GLOVESofSILVER", "RINGofHEALING"
                ],
                "NEUTRAL": [
                    "SHURIKENS", "SHIELD+3", "PLATE MAIL+2", "HELMofMALOR", "GLOVESofSILVER", "RINGofHEALING"
                ],
                "EVIL": [
                    "SHURIKENS", "SHIELD+3", "PLATE+3 (E)",  "HELM+2 (E)",  "GLOVESofSILVER", "RINGofHEALING"
                ]
            }
        },
        {
            "FIGHTER": {
                "GOOD": [
                    "LONG SWORD+5", "SHIELD+3", "PLATE+5", "HELMofMALOR", "WINTER MITTENS", "AMULETofCOVER"
                ],
                "NEUTRAL": [
                    "LONG SWORD+5", "SHIELD+3", "PLATE+5", "HELMofMALOR", "WINTER MITTENS", "AMULETofCOVER"
                ],
                "EVIL": [
                    "LONG SWORD+5", "SHIELD+3", "PLATE+5", "HELM+2 (E)", "WINTER MITTENS", "AMULETofCOVER"
                ]
            },
            "MAGE": {
                "GOOD": [
                    "STAFFofLIGHT", "ROBE+3", "HELMofMALOR", "AMULETofCOVER"
                ],
                "NEUTRAL": [
                    "STAFFofLIGHT", "ROBE+3", "HELMofMALOR", "AMULETofCOVER"
                ],
                "EVIL": [
                    "STAFFofLIGHT", "ROBE+3", "HELMofMALOR", "AMULETofCOVER"
                ]
            },
            "PRIEST": {
                "GOOD": [
                    "RODofRISING", "SHIELD+3", "PLATE+5", "HELMofMALOR", "AMULETofCOVER"
                ],
                "NEUTRAL": [
                    "RODofRISING", "SHIELD+3", "PLATE+5", "HELMofMALOR", "AMULETofCOVER"
                ],
                "EVIL": [
                    "RODofRISING", "SHIELD+3", "PLATE+5", "HELMofMALOR", "AMULETofCOVER"
                ]
            },
            "THIEF": {
                "GOOD": [
                    "STAFFofLIGHT", "SHIELD+3", "LEATHER+2", "HELMofMALOR", "WINTER MITTENS", "AMULETofCOVER"
                ],
                "NEUTRAL": [
                    "STAFFofLIGHT", "SHIELD+3", "LEATHER+2", "HELMofMALOR", "WINTER MITTENS", "AMULETofCOVER"
                ],
                "EVIL": [
                    "STAFFofLIGHT", "SHIELD+3", "LEATHER+2", "HELMofMALOR", "WINTER MITTENS", "AMULETofCOVER"
                ]
            },
            "BISHOP": {
                "GOOD": [
                    "RODofRISING", "LEATHER+2", "HELMofMALOR", "AMULETofCOVER"
                ],
                "NEUTRAL": [
                    "RODofRISING", "LEATHER+2", "HELMofMALOR", "AMULETofCOVER"
                ],
                "EVIL": [
                    "RODofRISING", "LEATHER+2", "HELMofMALOR", "AMULETofCOVER"
                ]
            },
            "SAMURAI": {
                "GOOD": [
                    "MURAMASA BLADE!", "SHIELD+3", "PLATE+5", "HELMofMALOR", "WINTER MITTENS", "AMULETofCOVER"
                ],
                "NEUTRAL": [
                    "MURAMASA BLADE!", "SHIELD+3", "PLATE+5", "HELMofMALOR", "WINTER MITTENS", "AMULETofCOVER"
                ],
                "EVIL": [
                    "MURAMASA BLADE!", "SHIELD+3", "PLATE+5", "HELM+2 (E)", "WINTER MITTENS", "AMULETofCOVER"
                ]
            },
            "LORD": {
                "GOOD": [
                    "LONG SWORD+5", "SHIELD+3", "GARBofLORDS", "HELMofMALOR", "WINTER MITTENS", "AMULETofCOVER"
                ],
                "NEUTRAL": [
                    "LONG SWORD+5", "SHIELD+3", "GARBofLORDS", "HELMofMALOR", "WINTER MITTENS", "AMULETofCOVER"
                ],
                "EVIL": [
                    "LONG SWORD+5", "SHIELD+3", "GARBofLORDS", "HELM+2 (E)", "WINTER MITTENS", "AMULETofCOVER"
                ]
            },
            "NINJA": {
                "GOOD": [
                    "SHURIKENS", "SHIELD+3", "PLATE+5", "HELMofMALOR", "WINTER MITTENS", "AMULETofCOVER"
                ],
                "NEUTRAL": [
                    "SHURIKENS", "SHIELD+3", "PLATE+5", "HELMofMALOR", "WINTER MITTENS", "AMULETofCOVER"
                ],
                "EVIL": [
                    "SHURIKENS", "SHIELD+3", "PLATE+5", "HELM+2 (E)", "WINTER MITTENS", "AMULETofCOVER"
                ]
            }
        },
        {
            "FIGHTER": {
                "GOOD": [
                    "BLADE CUISINART'", "HEATER+2", "PLATE ARMOR+2", "ARMET", "MANTIS GLOVES", "TROLLKIN RING"
                ],
                "NEUTRAL": [
                    "BLADE CUISINART'", "HEATER+2", "PLATE ARMOR+2", "ARMET", "MANTIS GLOVES", "TROLLKIN RING"
                ],
                "EVIL": [
                    "BLADE CUISINART'", "HEATER+2", "PLATE ARMOR+2", "ARMET", "MANTIS GLOVES", "TROLLKIN RING"
                ]
            },
            "MAGE": {
                "GOOD": [
                    "WIZARD'S STAFF", "DISPLACER ROBES", "GOLD TIARA", "TROLLKIN RING"
                ],
                "NEUTRAL": [
                    "WIZARD'S STAFF", "DISPLACER ROBES", "GOLD TIARA", "TROLLKIN RING"
                ],
                "EVIL": [
                    "WIZARD'S STAFF", "DISPLACER ROBES", "GOLD TIARA", "TROLLKIN RING"
                ]
            },
            "PRIEST": {
                "GOOD": [
                    "MACE+2", "HEATER+2", "BREASTPLATE+2", "GOLD TIARA", "MANTIS GLOVES", "TROLLKIN RING"
                ],
                "NEUTRAL": [
                    "MACE+2", "HEATER+2", "BREASTPLATE+2", "GOLD TIARA", "MANTIS GLOVES", "TROLLKIN RING"
                ],
                "EVIL": [
                    "MACE+2", "HEATER+2", "BREASTPLATE+2", "GOLD TIARA", "MANTIS GLOVES", "TROLLKIN RING"
                ]
            },
            "THIEF": {
                "GOOD": [
                    "SHORT SWORD+2", "CUIRASS+2", "GOLD TIARA", "GLOVESofMITHRIL", "TROLLKIN RING"
                ],
                "NEUTRAL": [
                    "SHORT SWORD+2", "CUIRASS+2", "GOLD TIARA", "GLOVESofMITHRIL", "TROLLKIN RING"
                ],
                "EVIL": [
                    "SHORT SWORD+2", "CUIRASS+2", "GOLD TIARA", "GLOVESofMITHRIL", "TROLLKIN RING"
                ]
            },
            "BISHOP": {
                "GOOD": [
                    "MACE+2", "BREASTPLATE+2", "GOLD TIARA", "TROLLKIN RING"
                ],
                "NEUTRAL": [
                    "MACE+2", "BREASTPLATE+2", "GOLD TIARA", "TROLLKIN RING"
                ],
                "EVIL": [
                    "MACE+2", "BREASTPLATE+2", "GOLD TIARA", "TROLLKIN RING"
                ]
            },
            "SAMURAI": {
                "GOOD": [
                    "BLADE CUISINART'", "HEATER+2", "PLATE ARMOR+2", "ARMET", "MANTIS GLOVES", "TROLLKIN RING"
                ],
                "NEUTRAL": [
                    "BLADE CUISINART'", "HEATER+2", "PLATE ARMOR+2", "ARMET", "MANTIS GLOVES", "TROLLKIN RING"
                ],
                "EVIL": [
                    "BLADE CUISINART'", "HEATER+2", "PLATE ARMOR+2", "ARMET", "MANTIS GLOVES", "TROLLKIN RING"
                ]
            },
            "LORD": {
                "GOOD": [
                    "BLADE CUISINART'", "HEATER+2", "PLATE ARMOR+2", "ARMET", "MANTIS GLOVES", "TROLLKIN RING"
                ],
                "NEUTRAL": [
                    "BLADE CUISINART'", "HEATER+2", "PLATE ARMOR+2", "ARMET", "MANTIS GLOVES", "TROLLKIN RING"
                ],
                "EVIL": [
                    "BLADE CUISINART'", "HEATER+2", "PLATE ARMOR+2", "ARMET", "MANTIS GLOVES", "TROLLKIN RING"
                ]
            },
            "NINJA": {
                "GOOD": [
                    "BUTTERFLY KNIFE[U]", "HEATER+2", "PLATE ARMOR+2", "ARMET", "TROLLKIN RING"
                ],
                "NEUTRAL": [
                    "BUTTERFLY KNIFE[U]", "HEATER+2", "PLATE ARMOR+2", "ARMET", "TROLLKIN RING"
                ],
                "EVIL": [
                    "BUTTERFLY KNIFE[U]", "HEATER+2", "PLATE ARMOR+2", "ARMET", "TROLLKIN RING"
                ]
            }
        }

    ]
}
)***"_json;


template <typename T>
void setValue(nlohmann::json& j, const char* val, T& target) noexcept
{
    auto itr = std::find(j.begin(), j.end(), std::string(val));
    if (itr == j.end()) return;
    target = T(std::distance(j.begin(), itr));
}

#pragma pack(1)

class CharName {
    char length;
    char name[15];
public:
    std::string get() noexcept
    {
        return std::string(name, name + length);
    }
    void reset() noexcept
    {
        length = 0;
    }
};

class Race {
    int16_t race;
public:
    std::string get() noexcept
    {
        return json["race"][race];
    }
    void set(const char* r) noexcept
    {
        setValue(json["race"], r, race);
    }
};

class JobClass {
    int16_t job;
public:
    std::string get() noexcept
    {
        return json["class"][job];
    }
    void set(const char* j) noexcept
    {
        setValue(json["class"], j, job);
    }
};

class Week {
    int16_t week;
public:
    int16_t get() noexcept
    {
        return week;
    }
    void set(int16_t w) noexcept
    {
        if (w < 0 || w > 80 * 52) {
            return;
        }
        week = w;
    }
    void setAge(int16_t age) noexcept
    {
        if (age < 0 || age > 80) {
            return;
        }
        week = age * 52;
    }
};

class Condition {
    int16_t status;
public:
    std::string get()
    {
        return json["condition"][status];
    }
    void set(const char* s) noexcept
    {
        setValue(json["condition"], s, status);
    }
};

class Alignment {
    int16_t alignment;
public:
    std::string get() noexcept
    {
        return json["alignment"][alignment];
    }
    void set(const char* a) noexcept
    {
        setValue(json["alignment"], a, alignment);
    }
};

class Stats {
    uint32_t STRENGTH : 5;
    uint32_t IQ : 5;
    uint32_t PIETY : 5;
    uint32_t pad1 : 1;
    uint32_t VITALITY : 5;
    uint32_t AGILITY : 5;
    uint32_t LUCK : 5;
    uint32_t pad2 : 1;
public:
    int get(const char* w) noexcept
    {
        std::string which(w);
        if (which == "STRENGTH") {
            return (int)STRENGTH;
        }
        if (which == "IQ") {
            return (int)IQ;
        }
        if (which == "PIETY") {
            return (int)PIETY;
        }
        if (which == "VITALITY") {
            return (int)VITALITY;
        }
        if (which == "AGILITY") {
            return (int)AGILITY;
        }
        if (which == "LUCK") {
            return (int)LUCK;
        }
        return 0;
    }
    void set(uint8_t s, uint8_t i, uint8_t p, uint8_t v, uint8_t a, uint8_t l) noexcept
    {
        if (s > 18 || i > 18 || p > 18 || v > 18 || a > 18 || l > 18) {
            return;
        }
        if (s != 0) STRENGTH = s;
        if (i != 0) IQ = i;
        if (p != 0) PIETY = p;
        if (v != 0) VITALITY = v;
        if (a != 0) AGILITY = a;
        if (l != 0) LUCK = l;
    }
};

class GoldExp {
    int16_t low;
    int16_t middle;
    int16_t high;
public:
    int64_t get() noexcept
    {
        return int64_t(high) * 100000000 + int64_t(middle) * 10000 + low;
    }
    void set(int64_t val) noexcept
    {
        if (val < 0 || val > 999999999999) {
            return;
        }
        low = int16_t(val % 10000);
        val /= 10000;
        middle = int16_t(val % 10000);
        high = int16_t(val / 10000);
    }
};

struct Level {
    int16_t current;
    int16_t last;
};

struct HitPoints {
    int16_t current;
    int16_t maximum;
};

class Item {
    int16_t isEquipped;
    int16_t unkown;
    int16_t identify;
    int16_t index;
public:
    std::string get(int scenario) noexcept
    {
        return json["itemlist"][scenario][index - (scenario == 2 ? 1000 : 0)];
    }
    void set(const char* name, int scenario)
    {
        setValue(json["itemlist"][scenario], name, index);
        if (scenario == 2) {
            index += 1000;
        }
        identify = 1;
        isEquipped = 0;
    }
};

struct CharData {
    CharName characterName;
    CharName passwd;
    int16_t isOut;
    Race race;
    JobClass jclass;
    Week week;
    Condition condition;
    Alignment alignment;
    Stats stats;
    int32_t pad0;
    GoldExp gold;
    int16_t num_items;
    Item items[8];
    GoldExp experience;
    Level level;
    HitPoints hp;
    int16_t pad3;
    int32_t pad4[17];
    void dump(int scenario) noexcept;
    void setItems(int scenario) noexcept;
    void setExp(int up) noexcept;
};

#pragma pack()


void CharData::dump(int scenario) noexcept
{
    std::cerr << "\nSCENARIO: " << json["scenario"][scenario] << "\n";
    std::cerr << "NAME     : " << characterName.get() << "\n";
    std::cerr << "PASSWORD : " << passwd.get() << "\n";
    std::cerr << "RACE     : " << race.get() << "\n";
    std::cerr << "CLASS    : " << jclass.get() << "\n";
    std::cerr << "AGE      : " << week.get() / 52 << "\n";
    std::cerr << "CONDITION: " << condition.get() << "\n";
    std::cerr << "ALIGNMENT: " << alignment.get() << "\n";
    std::cerr << "STRENGTH : " << stats.get("STRENGTH") << "\n";
    std::cerr << "IQ       : " << stats.get("IQ") << "\n";
    std::cerr << "PIETY    : " << stats.get("PIETY") << "\n";
    std::cerr << "VITALITY : " << stats.get("VITALITY") << "\n";
    std::cerr << "AGILITY  : " << stats.get("AGILITY") << "\n";
    std::cerr << "LUCK     : " << stats.get("LUCK") << "\n";
    std::cerr << "GOLD     : " << gold.get() << "\n";
    for (int i = 0; i < num_items; ++i) {
        std::cerr << "ITEM[" << i << "] : " << items[i].get(scenario) << "\n";
    }
    std::cerr << "EXP      : " << experience.get() << "\n";
    std::cerr << "LEVEL    : " << level.current << " / " << level.last << "\n";
    std::cerr << "H.P.     : " << hp.current << " / " << hp.maximum<< "\n";
}

void CharData::setItems(int scenario) noexcept
{
    std::cerr << "set items: " << jclass.get() << "\n";
    auto list = json["itemset"][scenario][jclass.get()][alignment.get()].get<std::vector<std::string>>();

    int i = 0;
    for (const auto& itm : list) {
        items[i++].set(itm.c_str(), scenario);
    }
    num_items = int16_t(list.size());
}

void CharData::setExp(int up) noexcept
{
    int64_t current = experience.get();
    int64_t val = json["experience"][jclass.get()].get<int64_t>() * up;
    experience.set(current + val);
}

void usage() noexcept
{
    std::cerr << "usage: wizcheat <DSK file> <character's name> <action> [<action> ...]\n";
    std::cerr << "A character editor for Wizardry#1, #2 and #3 for IBM-PC(Dosbox)\n\n";
    std::cerr << "example: wizcheat C:\\wiz1to3\\SAVE1.DSK DEADPOOL NEUTRAL NINJA ALL18 ITEM EXP EXP GOLD\n";
    std::cerr << "    (A character named DEADPOOL becomes a NEUTRAL NINJA with\n";
    std::cerr << "     all stats values of 18, and gains the strongest equipments,\n";
    std::cerr << "     20 levels of experience and 1,000,000 gold.)\n\n";
    std::cerr << "actions:\n";
    std::cerr << "    FIGHTER - change character's class to FIGHTER.\n";
    std::cerr << "    MAGE    - change character's class to MAGE.\n";
    std::cerr << "    PRIEST  - change character's class to PRIEST.\n";
    std::cerr << "    THIEF   - change character's class to THIEF.\n";
    std::cerr << "    BISHOP  - change character's class to BISHOP.\n";
    std::cerr << "    SAMURAI - change character's class to SAMURAI.\n";
    std::cerr << "    LORD    - change character's class to LORD.\n";
    std::cerr << "    NINJA   - change character's class to NINJA.\n";
    std::cerr << "    GOOD    - change character's alignment to GOOD.\n";
    std::cerr << "    NEUTRAL - change character's alignment to NEUTRAL.\n";
    std::cerr << "    EVIL    - change character's alignment to EVIL.\n";
    std::cerr << "    HUMAN   - change character's race to HUMAN.\n";
    std::cerr << "    ELF     - change character's race to ELF.\n";
    std::cerr << "    DWARF   - change character's race to DWARF.\n";
    std::cerr << "    GNOME   - change character's race to GNOME.\n";
    std::cerr << "    HOBBIT  - change character's race to HOBBIT.\n";
    std::cerr << "    ALL18   - change character's all stats to 18.\n";
    std::cerr << "    CURE    - change character's condition\n";
    std::cerr << "              ('PARALY', 'STONED', 'DEAD', 'ASHED' and 'LOST') to 'OK'.\n";
    std::cerr << "    ITEM    - change character's items to the most powerful ones for the class.\n";
    std::cerr << "    AGE     - decrease character's age to zero.\n";
    std::cerr << "    GOLD    - increase character's gold by 1,000,000.\n";
    std::cerr << "    EXP     - increase character's experience by 10 levels.\n";
    std::cerr << "    RESET   - reset character's password.\n";
    std::cerr << "    others  - print the character's status, and quit without saving.\n\n";
    std::cerr << "*** NOTE ***\n";
    std::cerr << "This tool will rewrite the DSK file.\nYou should make a backup before using this.\n";
}


int get_scenario(std::string& str) noexcept
{
    if (str.find("THE LEGACY OF LLYLGAMYN") != std::string::npos) {
        return 2;
    }
    if (str.find("THE KNIGHT OF DIAMONDS") != std::string::npos) {
        return 1;
    }
    if (str.find("PROVING GROUNDS OF THE MAD OVERLORD") != std::string::npos) {
        return 0;
    }
    return -1;
}

int main(int argc, char** argv)
{
    if (argc < 3) {
        usage();
        return -1;
    }
    try {
        size_t fsize = std::filesystem::file_size(argv[1]);
        std::ifstream ifs(argv[1], std::ios::in | std::ios::binary);
        std::vector<char> buff(fsize);
        ifs.read(buff.data(), fsize);
        ifs.close();

        std::string str(buff.begin(), buff.end());
        int scenario = get_scenario(str);
        if (scenario < 0) {
            throw std::runtime_error("this file is invalid DSK file.");
        }
        std::string cname(argv[2]);
        auto pos = str.find(cname);
        if (pos == std::string::npos) {
            throw std::runtime_error("there is no character '" + cname + "'.");
        }
        --pos;
        if (size_t(buff[pos]) != cname.size()) {
            throw std::runtime_error("This character's name '" + cname + "' is not searchable.\nplease chane the name.");
        }

        CharData cd;
        std::memcpy(&cd, buff.data() + pos, sizeof(CharData));

        if (argc == 3) {
            cd.dump(scenario);
            return 0;
        }

        for (auto idx = 3; idx < argc; ++idx) {
            std::string action(argv[idx]);
            if (action == "FIGHTER") {
                cd.jclass.set("FIGHTER");
            } else if (action == "MAGE") {
                cd.jclass.set("MAGE");
            } else if (action == "PRIEST") {
                cd.jclass.set("PRIEST");
            } else if (action == "THIEF") {
                cd.jclass.set("THIEF");
            } else if (action == "BISHOP") {
                cd.jclass.set("BISHOP");
            } else if (action == "SAMURAI") {
                cd.jclass.set("SAMURAI");
            } else if (action == "LORD") {
                cd.jclass.set("LORD");
            } else if (action == "NINJA") {
                cd.jclass.set("NINJA");
            } else if (action == "GOOD") {
                cd.alignment.set("GOOD");
            } else if (action == "NEUTRAL") {
                cd.alignment.set("NEUTRAL");
            } else if (action == "EVIL") {
                cd.alignment.set("EVIL");
            } else if (action == "HUMAN") {
                cd.race.set("HUMAN");
            } else if (action == "ELF") {
                cd.race.set("ELF");
            } else if (action == "DWARF") {
                cd.race.set("DWARF");
            } else if (action == "GNOME") {
                cd.race.set("GNOME");
            } else if (action == "HOBBIT") {
                cd.race.set("HOBBIT");
            } else if (action == "CURE") {
                cd.condition.set("OK");
                cd.hp.current = cd.hp.maximum;
            } else if (action == "ITEM") {
                cd.setItems(scenario);
            } else if (action == "AGE") {
                cd.week.set(15);
            } else if (action == "GOLD") {
                cd.gold.set(cd.gold.get() + 1000000);
            } else if (action == "EXP") {
                cd.setExp(10);
            } else {
                cd.dump(scenario);
                return 0;
            }
        }

        cd.dump(scenario);
        std::memcpy(buff.data() + pos, &cd, sizeof(CharData));
        std::ofstream ofs(argv[1], std::ios::out | std::ios::binary);
        ofs.write(buff.data(), fsize);
        ofs.close();
    } catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    return 0;
}
