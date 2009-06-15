/*
 * DBC to SQL Converter
 * Copyright (C) 2009  David Vas, Anubisss
 * <http://code.google.com/p/dbctosql/>

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __SPEL_H__
#define __SPEL_H__

char const *SPELL_DBC   = "Spell.dbc";
char const *SPELL_SQL   = "spell_dbc.sql";
char const *SPELL_TABLE = "dbc_spell";

#define SPELL_DBC_CLIENT_BUILD  9551 // 3.0.9

#define SPELL_DBC_COLUMN_NUMS   231
#define SPELL_DBC_ROWS_NUMS     42163

// Spell.dbc struct: TrinityCore2 r3917
char const *sql_translation_table[SPELL_DBC_COLUMN_NUMS][2] =
{
    {"uint32",  "id"},                          // 0 - Id
    {"uint32",  "1"},                           // Category
    {"uint32",  "2"},                           // Dispel
    {"uint32",  "3"},                           // Mechanic
    {"uint32",  "4"},                           // Attributes
    {"uint32",  "5"},                           // AttributesEx
    {"uint32",  "6"},                           // AttributesEx2
    {"uint32",  "7"},                           // AttributesEx3
    {"uint32",  "8"},                           // AttributesEx4
    {"uint32",  "9"},                           // AttributesEx5
    {"uint32",  "10"},                          // AttributesEx6
    {"uint32",  "11"},                          // Stances
    {"uint32",  "12"},                          // StancesNot
    {"uint32",  "13"},                          // Targets
    {"uint32",  "14"},                          // TargetCreatureType
    {"uint32",  "15"},                          // RequiresSpellFocus
    {"uint32",  "16"},                          // FacingCasterFlags
    {"uint32",  "17"},                          // CasterAuraState
    {"uint32",  "18"},                          // TargetAuraState
    {"uint32",  "19"},                          // CasterAuraStateNot
    {"uint32",  "20"},                          // TargetAuraStateNot
    {"uint32",  "21"},                          // casterAuraSpell
    {"uint32",  "22"},                          // targetAuraSpell
    {"uint32",  "23"},                          // excludeCasterAuraSpell
    {"uint32",  "24"},                          // excludeTargetAuraSpell
    {"uint32",  "25"},                          // CastingTimeIndex
    {"uint32",  "26"},                          // RecoveryTime
    {"uint32",  "27"},                          // CategoryRecoveryTime
    {"uint32",  "28"},                          // InterruptFlags
    {"uint32",  "29"},                          // AuraInterruptFlags
    {"uint32",  "30"},                          // ChannelInterruptFlags
    {"uint32",  "31"},                          // procFlags
    {"uint32",  "32"},                          // procChance
    {"uint32",  "33"},                          // procCharges
    {"uint32",  "34"},                          // maxLevel
    {"uint32",  "35"},                          // baseLevel
    {"uint32",  "36"},                          // spellLevel
    {"uint32",  "37"},                          // DurationIndex
    {"uint32",  "38"},                          // powerType
    {"uint32",  "39"},                          // manaCost
    {"uint32",  "40"},                          // manaCostPerlevel
    {"uint32",  "41"},                          // manaPerSecond
    {"uint32",  "42"},                          // manaPerSecondPerLevel
    {"uint32",  "43"},                          // rangeIndex
    {"float",   "44"},                          // speed
    {"uint32",  "45"},                          // modalNextSpell, not used
    {"uint32",  "46"},                          // StackAmount
    {"uint32",  "47"},                          // Totem[0]
    {"uint32",  "48"},                          // Totem[1]
    {"int32",   "49"},                          // Reagent[0]
    {"int32",   "50"},                          // Reagent[1]
    {"int32",   "51"},                          // Reagent[2]
    {"int32",   "52"},                          // Reagent[3]
    {"int32",   "53"},                          // Reagent[4]
    {"int32",   "54"},                          // Reagent[5]
    {"int32",   "55"},                          // Reagent[6]
    {"int32",   "56"},                          // Reagent[7]
    {"uint32",  "57"},                          // ReagentCount[0]
    {"uint32",  "58"},                          // ReagentCount[1]
    {"uint32",  "59"},                          // ReagentCount[2]
    {"uint32",  "60"},                          // ReagentCount[3]
    {"uint32",  "61"},                          // ReagentCount[4]
    {"uint32",  "62"},                          // ReagentCount[5]
    {"uint32",  "63"},                          // ReagentCount[6]
    {"uint32",  "64"},                          // ReagentCount[7]
    {"int32",   "65"},                          // EquippedItemClass
    {"int32",   "66"},                          // EquippedItemSubClassMask
    {"int32",   "67"},                          // EquippedItemInventoryTypeMask
    {"uint32",  "68"},                          // Effect[0]
    {"uint32",  "69"},                          // Effect[1]
    {"uint32",  "70"},                          // Effect[2]
    {"int32",   "71"},                          // EffectDieSides[0]
    {"int32",   "72"},                          // EffectDieSides[1]
    {"int32",   "73"},                          // EffectDieSides[2]
    {"int32",   "74"},                          // EffectBaseDice[0]
    {"int32",   "75"},                          // EffectBaseDice[1]
    {"int32",   "76"},                          // EffectBaseDice[2]
    {"float",   "77"},                          // EffectDicePerLevel[0]
    {"float",   "78"},                          // EffectDicePerLevel[1]
    {"float",   "79"},                          // EffectDicePerLevel[2]
    {"float",   "80"},                          // EffectRealPointsPerLevel[0]
    {"float",   "81"},                          // EffectRealPointsPerLevel[1]
    {"float",   "82"},                          // EffectRealPointsPerLevel[2]
    {"int32",   "83"},                          // EffectBasePoints[0]
    {"int32",   "84"},                          // EffectBasePoints[1]
    {"int32",   "85"},                          // EffectBasePoints[2]
    {"uint32",  "86"},                          // EffectMechanic[0]
    {"uint32",  "87"},                          // EffectMechanic[1]
    {"uint32",  "88"},                          // EffectMechanic[2]
    {"uint32",  "89"},                          // EffectImplicitTargetA[0]
    {"uint32",  "90"},                          // EffectImplicitTargetA[1]
    {"uint32",  "91"},                          // EffectImplicitTargetA[2]
    {"uint32",  "92"},                          // EffectImplicitTargetB[0]
    {"uint32",  "93"},                          // EffectImplicitTargetB[1]
    {"uint32",  "94"},                          // EffectImplicitTargetB[2]
    {"uint32",  "95"},                          // EffectRadiusIndex[0]
    {"uint32",  "96"},                          // EffectRadiusIndex[1]
    {"uint32",  "97"},                          // EffectRadiusIndex[2]
    {"uint32",  "98"},                          // EffectApplyAuraName[0]
    {"uint32",  "99"},                          // EffectApplyAuraName[1]
    {"uint32",  "100"},                         // EffectApplyAuraName[2]
    {"uint32",  "101"},                         // EffectAmplitude[0]
    {"uint32",  "102"},                         // EffectAmplitude[1]
    {"uint32",  "103"},                         // EffectAmplitude[2]
    {"float",   "104"},                         // EffectMultipleValue[0]
    {"float",   "105"},                         // EffectMultipleValue[1]
    {"float",   "106"},                         // EffectMultipleValue[2]
    {"uint32",  "107"},                         // EffectChainTarget[0]
    {"uint32",  "108"},                         // EffectChainTarget[1]
    {"uint32",  "109"},                         // EffectChainTarget[2]
    {"uint32",  "110"},                         // EffectItemType[0]
    {"uint32",  "111"},                         // EffectItemType[1]
    {"uint32",  "112"},                         // EffectItemType[2]
    {"int32",   "113"},                         // EffectMiscValue[0]
    {"int32",   "114"},                         // EffectMiscValue[1]
    {"int32",   "115"},                         // EffectMiscValue[2]
    {"int32",   "116"},                         // EffectMiscValueB[0]
    {"int32",   "117"},                         // EffectMiscValueB[1]
    {"int32",   "118"},                         // EffectMiscValueB[2]
    {"uint32",  "119"},                         // EffectTriggerSpell[0]
    {"uint32",  "120"},                         // EffectTriggerSpell[1]
    {"uint32",  "121"},                         // EffectTriggerSpell[2]
    {"float",   "122"},                         // EffectPointsPerComboPoint[0]
    {"float",   "123"},                         // EffectPointsPerComboPoint[1]
    {"float",   "124"},                         // EffectPointsPerComboPoint[2]
    {"flag96",  "125"},                         // EffectSpellClassMask[0]
    {"flag96",  "126"},                         // EffectSpellClassMask[1]
    {"flag96",  "127"},                         // EffectSpellClassMask[2]
    {"uint32",  "128"},                         //
    {"uint32",  "129"},                         //
    {"uint32",  "130"},                         //
    {"uint32",  "131"},                         //
    {"uint32",  "132"},                         //
    {"uint32",  "133"},                         //
    {"uint32",  "134"},                         // SpellVisual[0]
    {"uint32",  "135"},                         // SpellVisual[1]
    {"uint32",  "136"},                         // SpellIconID
    {"uint32",  "137"},                         // activeIconID
    {"uint32",  "138"},                         // spellPriority, not used
    {"char*",   "139"},                         // SpellName[0]
    {"char*",   "140"},                         // SpellName[1]
    {"char*",   "141"},                         // SpellName[2]
    {"char*",   "142"},                         // SpellName[3]
    {"char*",   "143"},                         // SpellName[4]
    {"char*",   "144"},                         // SpellName[5]
    {"char*",   "145"},                         // SpellName[6]
    {"char*",   "146"},                         // SpellName[7]
    {"char*",   "147"},                         // SpellName[8]
    {"char*",   "148"},                         // SpellName[9]
    {"char*",   "149"},                         // SpellName[10]
    {"char*",   "150"},                         // SpellName[11]
    {"char*",   "151"},                         // SpellName[12]
    {"char*",   "152"},                         // SpellName[13]
    {"char*",   "153"},                         // SpellName[14]
    {"char*",   "154"},                         // SpellName[15]
    {"uint32",  "155"},                         // SpellNameFlag, not used
    {"char*",   "156"},                         // Rank[0]
    {"char*",   "157"},                         // Rank[1]
    {"char*",   "158"},                         // Rank[2]
    {"char*",   "159"},                         // Rank[3]
    {"char*",   "160"},                         // Rank[4]
    {"char*",   "161"},                         // Rank[5]
    {"char*",   "162"},                         // Rank[6]
    {"char*",   "163"},                         // Rank[7]
    {"char*",   "164"},                         // Rank[8]
    {"char*",   "165"},                         // Rank[9]
    {"char*",   "166"},                         // Rank[10]
    {"char*",   "167"},                         // Rank[11]
    {"char*",   "168"},                         // Rank[12]
    {"char*",   "169"},                         // Rank[13]
    {"char*",   "170"},                         // Rank[14]
    {"char*",   "171"},                         // Rank[15]
    {"uint32",  "172"},                         // RankFlags, not used
    {"char*",   "173"},                         // Description[0]
    {"char*",   "174"},                         // Description[1]
    {"char*",   "175"},                         // Description[2]
    {"char*",   "176"},                         // Description[3]
    {"char*",   "177"},                         // Description[4]
    {"char*",   "178"},                         // Description[5]
    {"char*",   "179"},                         // Description[6]
    {"char*",   "180"},                         // Description[7]
    {"char*",   "181"},                         // Description[8]
    {"char*",   "182"},                         // Description[9]
    {"char*",   "183"},                         // Description[10]
    {"char*",   "184"},                         // Description[11]
    {"char*",   "185"},                         // Description[12]
    {"char*",   "186"},                         // Description[13]
    {"char*",   "187"},                         // Description[14]
    {"char*",   "188"},                         // Description[15]
    {"uint32",  "189"},                         // DescriptionFlags, not used
    {"char*",   "190"},                         // ToolTip[0], not used
    {"char*",   "191"},                         // ToolTip[1], not used
    {"char*",   "192"},                         // ToolTip[2], not used
    {"char*",   "193"},                         // ToolTip[3], not used
    {"char*",   "194"},                         // ToolTip[4], not used
    {"char*",   "195"},                         // ToolTip[5], not used
    {"char*",   "196"},                         // ToolTip[6], not used
    {"char*",   "197"},                         // ToolTip[7], not used
    {"char*",   "198"},                         // ToolTip[8], not used
    {"char*",   "199"},                         // ToolTip[9], not used
    {"char*",   "200"},                         // ToolTip[10], not used
    {"char*",   "201"},                         // ToolTip[11], not used
    {"char*",   "202"},                         // ToolTip[12], not used
    {"char*",   "203"},                         // ToolTip[13], not used
    {"char*",   "204"},                         // ToolTip[14], not used
    {"char*",   "205"},                         // ToolTip[15], not used
    {"uint32",  "206"},                         // ToolTipFlags, not used
    {"uint32",  "207"},                         // ManaCostPercentage
    {"uint32",  "208"},                         // StartRecoveryCategory
    {"uint32",  "209"},                         // StartRecoveryTime
    {"uint32",  "210"},                         // MaxTargetLevel
    {"uint32",  "211"},                         // SpellFamilyName
    {"flag96",  "212"},                         // SpellFamilyFlags[0]
    {"flag96",  "213"},                         // SpellFamilyFlags[1]
    {"flag96",  "214"},                         // SpellFamilyFlags[2]
    {"uint32",  "215"},                         // MaxAffectedTargets
    {"uint32",  "216"},                         // DmgClass
    {"uint32",  "217"},                         // PreventionType
    {"uint32",  "218"},                         // StanceBarOrder, not used
    {"float",   "219"},                         // DmgMultiplier[0]
    {"float",   "220"},                         // DmgMultiplier[1]
    {"float",   "221"},                         // DmgMultiplier[2]
    {"uint32",  "222"},                         // MinFactionId
    {"uint32",  "223"},                         // MinReputation
    {"uint32",  "224"},                         // RequiredAuraVision
    {"uint32",  "225"},                         // TotemCategory[0]
    {"uint32",  "226"},                         // TotemCategory[1]
    {"int32",   "227"},                         // AreaGroupId
    {"uint32",  "228"},                         // SchoolMask
    {"uint32",  "229"},                         // runeCostID
    {"uint32",  "230"},                         // spellMissileID
};

char const *SPELL_TABLE_INDEX = sql_translation_table[0][1];

#endif
