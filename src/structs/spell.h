/*
 * DBC to SQL Converter
 * Copyright (C) 2009  David Vas, Anubisss
 * <http://code.google.com/p/dbctosql/>

 * Updated by Dagfinn (Droidfinn) in 2012.

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY"}, without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __SPELL_H__
#define __SPELL_H__

char const *SPELL_DBC   = "Spell.dbc";
char const *SPELL_SQL   = "Spell.sql";
char const *SPELL_TABLE = "Spell";
char const *SPELL_CLIENT_VERSION = "3.3.5a";

#define SPELL_DBC_CLIENT_BUILD  12340 // 3.3.5a

#define SPELL_DBC_COLUMN_NUMS   234
#define SPELL_DBC_ROWS_NUMS    49839

// Spell.dbc struct: TrinityCore2
const std::string spell_definition[SPELL_DBC_COLUMN_NUMS][2] =
{
    {"uint16", "id"},                                           // 0        m_ID
    {"uint16", "Category"},                                     // 1        m_category
    {"uint16", "Dispel"},                                       // 2        m_dispelType
    {"uint16", "Mechanic"},                                     // 3        m_mechanic
    {"uint16", "Attributes"},                                   // 4        m_attributes
    {"uint16", "AttributesEx"},                                 // 5        m_attributesEx
    {"uint16", "AttributesEx2"},                                // 6        m_attributesExB
    {"uint16", "AttributesEx3"},                                // 7        m_attributesExC
    {"uint16", "AttributesEx4"},                                // 8        m_attributesExD
    {"uint16", "AttributesEx5"},                                // 9        m_attributesExE
    {"uint16", "AttributesEx6"},                                // 10       m_attributesExF
    {"uint16", "AttributesEx7"},                                // 11       m_attributesExG
    {"uint16", "Stances"},                                      // 12       m_shapeshiftMask
    {"uint16", "unk_320_2"},                                    // 13       3.2.0
    {"uint16", "StancesNot"},                                   // 14       m_shapeshiftExclude
    {"uint16", "unk_320_3"},                                    // 15       3.2.0
    {"uint16", "Targets"},                                      // 16       m_targets
    {"uint16", "TargetCreatureType"},                           // 17       m_targetCreatureType
    {"uint16", "RequiresSpellFocus"},                           // 18       m_requiresSpellFocus
    {"uint16", "FacingCasterFlags"},                            // 19       m_facingCasterFlags
    {"uint16", "CasterAuraState"},                              // 20       m_casterAuraState
    {"uint16", "TargetAuraState"},                              // 21       m_targetAuraState
    {"uint16", "CasterAuraStateNot"},                           // 22       m_excludeCasterAuraState
    {"uint16", "TargetAuraStateNot"},                           // 23       m_excludeTargetAuraState
    {"uint16", "casterAuraSpell"},                              // 24       m_casterAuraSpell
    {"uint16", "targetAuraSpell"},                              // 25       m_targetAuraSpell
    {"uint16", "excludeCasterAuraSpell"},                       // 26       m_excludeCasterAuraSpell
    {"uint16", "excludeTargetAuraSpell"},                       // 27       m_excludeTargetAuraSpell
    {"uint16", "CastingTimeIndex"},                             // 28       m_castingTimeIndex
    {"uint16", "RecoveryTime"},                                 // 29       m_recoveryTime
    {"uint16", "CategoryRecoveryTime"},                         // 30       m_categoryRecoveryTime
    {"uint16", "InterruptFlags"},                               // 31       m_interruptFlags
    {"uint16", "AuraInterruptFlags"},                           // 32       m_auraInterruptFlags
    {"uint16", "ChannelInterruptFlags"},                        // 33       m_channelInterruptFlags
    {"uint16", "procFlags"},                                    // 34       m_procTypeMask
    {"uint16", "procChance"},                                   // 35       m_procChance
    {"uint16", "procCharges"},                                  // 36       m_procCharges
    {"uint16", "maxLevel"},                                     // 37       m_maxLevel
    {"uint16", "baseLevel"},                                    // 38       m_baseLevel
    {"uint16", "spellLevel"},                                   // 39       m_spellLevel
    {"uint16", "DurationIndex"},                                // 40       m_durationIndex
    {"uint16", "powerType"},                                    // 41       m_powerType
    {"uint16", "manaCost"},                                     // 42       m_manaCost
    {"uint16", "manaCostPerlevel"},                             // 43       m_manaCostPerLevel
    {"uint16", "manaPerSecond"},                                // 44       m_manaPerSecond
    {"uint16", "manaPerSecondPerLevel"},                        // 45       m_manaPerSecondPerLeve
    {"uint16", "rangeIndex"},                                   // 46       m_rangeIndex
    {"float", "Speed"},                                        // 47       m_speed
    {"uint16", "modalNextSpell"},                             // 48       m_modalNextSpell not used
    {"uint16", "StackAmount"},                                  // 49       m_cumulativeAura
    {"uint16", "Totem[1]"},                                     // 50-51    m_totem
    {"uint16", "Totem[2]"},                                     // 50-51    m_totem
    {"int16", "Reagent[1]"},                  // 52-59    m_reagent
    {"int16", "Reagent[2]"},                  // 52-59    m_reagent
    {"int16", "Reagent[3]"},                  // 52-59    m_reagent
    {"int16", "Reagent[4]"},                  // 52-59    m_reagent
    {"int16", "Reagent[5]"},                  // 52-59    m_reagent
    {"int16", "Reagent[6]"},                  // 52-59    m_reagent
    {"int16", "Reagent[7]"},                  // 52-59    m_reagent
    {"int16", "Reagent[8]"},                  // 52-59    m_reagent
    {"uint16", "ReagentCount[1]"},             // 60-67    m_reagentCount
    {"uint16", "ReagentCount[2]"},             // 60-67    m_reagentCount
    {"uint16", "ReagentCount[3]"},             // 60-67    m_reagentCount
    {"uint16", "ReagentCount[4]"},             // 60-67    m_reagentCount
    {"uint16", "ReagentCount[5]"},             // 60-67    m_reagentCount
    {"uint16", "ReagentCount[6]"},             // 60-67    m_reagentCount
    {"uint16", "ReagentCount[7]"},             // 60-67    m_reagentCount
    {"uint16", "ReagentCount[8]"},             // 60-67    m_reagentCount
    {"int16", "EquippedItemClass"},                            // 68       m_equippedItemClass (value)
    {"int16", "EquippedItemSubClassMask"},                     // 69       m_equippedItemSubclass (mask)
    {"int16", "EquippedItemInventoryTypeMask"},                // 70       m_equippedItemInvTypes (mask)
    {"uint16", "Effect[1]"},                    // 71-73    m_effect
    {"uint16", "Effect[2]"},                    // 71-73    m_effect
    {"uint16", "Effect[3]"},                    // 71-73    m_effect
    {"int16", "EffectDieSides[1]"},            // 74-76    m_effectDieSides
    {"int16", "EffectDieSides[2]"},            // 74-76    m_effectDieSides
    {"int16", "EffectDieSides[3]"},            // 74-76    m_effectDieSides
    {"float", "EffectRealPointsPerLevel[1]"},  // 77-79    m_effectRealPointsPerLevel
    {"float", "EffectRealPointsPerLevel[2]"},  // 77-79    m_effectRealPointsPerLevel
    {"float", "EffectRealPointsPerLevel[3]"},  // 77-79    m_effectRealPointsPerLevel
    {"int16", "EffectBasePoints[1]"},          // 80-82    m_effectBasePoints (must not be used in spell/auras explicitly, must be used cached Spell::m_currentBasePoints)
    {"int16", "EffectBasePoints[2]"},          // 80-82    m_effectBasePoints (must not be used in spell/auras explicitly, must be used cached Spell::m_currentBasePoints)
    {"int16", "EffectBasePoints[3]"},          // 80-82    m_effectBasePoints (must not be used in spell/auras explicitly, must be used cached Spell::m_currentBasePoints)
    {"uint16", "EffectMechanic[1]"},            // 83-85    m_effectMechanic
    {"uint16", "EffectMechanic[2]"},            // 83-85    m_effectMechanic
    {"uint16", "EffectMechanic[3]"},            // 83-85    m_effectMechanic
    {"uint16", "EffectImplicitTargetA[1]"},     // 86-88    m_implicitTargetA
    {"uint16", "EffectImplicitTargetA[2]"},     // 86-88    m_implicitTargetA
    {"uint16", "EffectImplicitTargetA[3]"},     // 86-88    m_implicitTargetA
    {"uint16", "EffectImplicitTargetB[4]"},     // 89-91    m_implicitTargetB
    {"uint16", "EffectImplicitTargetB[5]"},     // 89-91    m_implicitTargetB
    {"uint16", "EffectImplicitTargetB[6]"},     // 89-91    m_implicitTargetB
    {"uint16", "EffectRadiusIndex[1]"},         // 92-94    m_effectRadiusIndex - spellradius.dbc
    {"uint16", "EffectRadiusIndex[2]"},         // 92-94    m_effectRadiusIndex - spellradius.dbc
    {"uint16", "EffectRadiusIndex[3]"},         // 92-94    m_effectRadiusIndex - spellradius.dbc
    {"uint16", "EffectApplyAuraName[1]"},       // 95-97    m_effectAura
    {"uint16", "EffectApplyAuraName[2]"},       // 95-97    m_effectAura
    {"uint16", "EffectApplyAuraName[3]"},       // 95-97    m_effectAura
    {"uint16", "EffectAmplitude[1]"},           // 98-100   m_effectAuraPeriod
    {"uint16", "EffectAmplitude[2]"},           // 98-100   m_effectAuraPeriod
    {"uint16", "EffectAmplitude[3]"},           // 98-100   m_effectAuraPeriod
    {"float", "EffectValueMultiplier[1]"},      // 101-103
    {"float", "EffectValueMultiplier[2]"},      // 101-103
    {"float", "EffectValueMultiplier[3]"},      // 101-103
    {"uint16", "EffectChainTarget[1]"},         // 104-106  m_effectChainTargets
    {"uint16", "EffectChainTarget[2]"},         // 104-106  m_effectChainTargets
    {"uint16", "EffectChainTarget[3]"},         // 104-106  m_effectChainTargets
    {"uint16", "EffectItemType[1]"},            // 107-109  m_effectItemType
    {"uint16", "EffectItemType[2]"},            // 107-109  m_effectItemType
    {"uint16", "EffectItemType[3]"},            // 107-109  m_effectItemType
    {"int16", "EffectMiscValue[4]"},           // 110-112  m_effectMiscValue
    {"int16", "EffectMiscValue[5]"},           // 110-112  m_effectMiscValue
    {"int16", "EffectMiscValue[6]"},           // 110-112  m_effectMiscValue
    {"int16", "EffectMiscValueB[1]"},          // 113-115  m_effectMiscValueB
    {"int16", "EffectMiscValueB[2]"},          // 113-115  m_effectMiscValueB
    {"int16", "EffectMiscValueB[3]"},          // 113-115  m_effectMiscValueB
    {"uint16", "EffectTriggerSpell[1]"},        // 116-118  m_effectTriggerSpell
    {"uint16", "EffectTriggerSpell[2]"},        // 116-118  m_effectTriggerSpell
    {"uint16", "EffectTriggerSpell[3]"},        // 116-118  m_effectTriggerSpell
    {"float", "EffectPointsPerComboPoint[1]"}, // 119-121  m_effectPointsPerCombo
    {"float", "EffectPointsPerComboPoint[2]"}, // 119-121  m_effectPointsPerCombo
    {"float", "EffectPointsPerComboPoint[3]"}, // 119-121  m_effectPointsPerCombo
    {"flag96", "EffectSpellClassMask[1]"},      // 122-130
    {"flag96", "EffectSpellClassMask[2]"},      // 122-130
    {"flag96", "EffectSpellClassMask[3]"},      // 122-130
    {"flag96", "EffectSpellClassMask[4]"},      // 122-130
    {"flag96", "EffectSpellClassMask[5]"},      // 122-130
    {"flag96", "EffectSpellClassMask[6]"},      // 122-130
    {"flag96", "EffectSpellClassMask[7]"},      // 122-130
    {"flag96", "EffectSpellClassMask[8]"},      // 122-130
    {"flag96", "EffectSpellClassMask[9]"},      // 122-130
    {"uint16", "SpellVisual[1]"},                               // 131-132  m_spellVisualID
    {"uint16", "SpellVisual[2]"},                               // 131-132  m_spellVisualID
    {"uint16", "SpellIconID"},                                  // 133      m_spellIconID
    {"uint16", "activeIconID"},                                 // 134      m_activeIconID
    {"uint16", "spellPriority"},                              // 135 not used
    {"char*", "SpellName[1]"},                                // 136-151  m_name_lang
    {"char*", "SpellName[2]"},                                // 136-151  m_name_lang
    {"char*", "SpellName[3]"},                                // 136-151  m_name_lang
    {"char*", "SpellName[4]"},                                // 136-151  m_name_lang
    {"char*", "SpellName[5]"},                                // 136-151  m_name_lang
    {"char*", "SpellName[6]"},                                // 136-151  m_name_lang
    {"char*", "SpellName[7]"},                                // 136-151  m_name_lang
    {"char*", "SpellName[8]"},                                // 136-151  m_name_lang
    {"char*", "SpellName[9]"},                                // 136-151  m_name_lang
    {"char*", "SpellName[10]"},                                // 136-151  m_name_lang
    {"char*", "SpellName[11]"},                                // 136-151  m_name_lang
    {"char*", "SpellName[12]"},                                // 136-151  m_name_lang
    {"char*", "SpellName[13]"},                                // 136-151  m_name_lang
    {"char*", "SpellName[14]"},                                // 136-151  m_name_lang
    {"char*", "SpellName[15]"},                                // 136-151  m_name_lang
    {"char*", "SpellName[16]"},                                // 136-151  m_name_lang
    {"uint16", "SpellNameFlag"},                              // 152 not used
    {"char*", "Rank[1]"},                                     // 153-168  m_nameSubtext_lang
    {"char*", "Rank[2]"},                                     // 153-168  m_nameSubtext_lang
    {"char*", "Rank[3]"},                                     // 153-168  m_nameSubtext_lang
    {"char*", "Rank[4]"},                                     // 153-168  m_nameSubtext_lang
    {"char*", "Rank[5]"},                                     // 153-168  m_nameSubtext_lang
    {"char*", "Rank[6]"},                                     // 153-168  m_nameSubtext_lang
    {"char*", "Rank[7]"},                                     // 153-168  m_nameSubtext_lang
    {"char*", "Rank[8]"},                                     // 153-168  m_nameSubtext_lang
    {"char*", "Rank[9]"},                                     // 153-168  m_nameSubtext_lang
    {"char*", "Rank[10]"},                                     // 153-168  m_nameSubtext_lang
    {"char*", "Rank[11]"},                                     // 153-168  m_nameSubtext_lang
    {"char*", "Rank[12]"},                                     // 153-168  m_nameSubtext_lang
    {"char*", "Rank[13]"},                                     // 153-168  m_nameSubtext_lang
    {"char*", "Rank[14]"},                                     // 153-168  m_nameSubtext_lang
    {"char*", "Rank[15]"},                                     // 153-168  m_nameSubtext_lang
    {"char*", "Rank[16]"},                                     // 153-168  m_nameSubtext_lang
    {"uint16", "RankFlags"},                                  // 169 not used
    {"char*", "Description[1]"},                            // 170-185  m_description_lang not used
    {"char*", "Description[2]"},                            // 170-185  m_description_lang not used
    {"char*", "Description[3]"},                            // 170-185  m_description_lang not used
    {"char*", "Description[4]"},                            // 170-185  m_description_lang not used
    {"char*", "Description[5]"},                            // 170-185  m_description_lang not used
    {"char*", "Description[6]"},                            // 170-185  m_description_lang not used
    {"char*", "Description[7]"},                            // 170-185  m_description_lang not used
    {"char*", "Description[8]"},                            // 170-185  m_description_lang not used
    {"char*", "Description[9]"},                            // 170-185  m_description_lang not used
    {"char*", "Description[10]"},                            // 170-185  m_description_lang not used
    {"char*", "Description[11]"},                            // 170-185  m_description_lang not used
    {"char*", "Description[12]"},                            // 170-185  m_description_lang not used
    {"char*", "Description[13]"},                            // 170-185  m_description_lang not used
    {"char*", "Description[14]"},                            // 170-185  m_description_lang not used
    {"char*", "Description[15]"},                            // 170-185  m_description_lang not used
    {"char*", "Description[16]"},                            // 170-185  m_description_lang not used
    {"uint16", "DescriptionFlags"},                           // 186 not used
    {"char*", "ToolTip[1]"},                                // 187-202  m_auraDescription_lang not used
    {"char*", "ToolTip[2]"},                                // 187-202  m_auraDescription_lang not used
    {"char*", "ToolTip[3]"},                                // 187-202  m_auraDescription_lang not used
    {"char*", "ToolTip[4]"},                                // 187-202  m_auraDescription_lang not used
    {"char*", "ToolTip[5]"},                                // 187-202  m_auraDescription_lang not used
    {"char*", "ToolTip[6]"},                                // 187-202  m_auraDescription_lang not used
    {"char*", "ToolTip[7]"},                                // 187-202  m_auraDescription_lang not used
    {"char*", "ToolTip[8]"},                                // 187-202  m_auraDescription_lang not used
    {"char*", "ToolTip[9]"},                                // 187-202  m_auraDescription_lang not used
    {"char*", "ToolTip[10]"},                                // 187-202  m_auraDescription_lang not used
    {"char*", "ToolTip[11]"},                                // 187-202  m_auraDescription_lang not used
    {"char*", "ToolTip[12]"},                                // 187-202  m_auraDescription_lang not used
    {"char*", "ToolTip[13]"},                                // 187-202  m_auraDescription_lang not used
    {"char*", "ToolTip[14]"},                                // 187-202  m_auraDescription_lang not used
    {"char*", "ToolTip[15]"},                                // 187-202  m_auraDescription_lang not used
    {"char*", "ToolTip[16]"},                                // 187-202  m_auraDescription_lang not used
    {"uint16", "ToolTipFlags"},                               // 203 not used
    {"uint16", "ManaCostPercentage"},                           // 204      m_manaCostPct
    {"uint16", "StartRecoveryCategory"},                        // 205      m_startRecoveryCategory
    {"uint16", "StartRecoveryTime"},                            // 206      m_startRecoveryTime
    {"uint16", "MaxTargetLevel"},                               // 207      m_maxTargetLevel
    {"uint16", "SpellFamilyName"},                              // 208      m_spellClassSet
    {"flag96", "SpellFamilyFlags[1]"},                             // 209-211
    {"flag96", "SpellFamilyFlags[2]"},                             // 209-211
    {"flag96", "SpellFamilyFlags[3]"},                             // 209-211
    {"uint16", "MaxAffectedTargets"},                           // 212      m_maxTargets
    {"uint16", "DmgClass"},                                     // 213      m_defenseType
    {"uint16", "PreventionType"},                               // 214      m_preventionType
    {"uint16", "StanceBarOrder"},                             // 215      m_stanceBarOrder not used
    {"float", "EffectDamageMultiplier[1]"},    // 216-218  m_effectChainAmplitude
    {"float", "EffectDamageMultiplier[2]"},    // 216-218  m_effectChainAmplitude
    {"float", "EffectDamageMultiplier[3]"},    // 216-218  m_effectChainAmplitude
    {"uint16", "MinFactionId"},                               // 219      m_minFactionID not used
    {"uint16", "MinReputation"},                              // 220      m_minReputation not used
    {"uint16", "RequiredAuraVision"},                         // 221      m_requiredAuraVision not used
    {"uint16", "TotemCategory[1]"},                             // 222-223  m_requiredTotemCategoryID 
    {"uint16", "TotemCategory[2]"},                             // 222-223  m_requiredTotemCategoryID
    {"int16", "AreaGroupId"},                                  // 224      m_requiredAreaGroupId
    {"uint16", "SchoolMask"},                                   // 225      m_schoolMask
    {"uint16", "runeCostID"},                                   // 226      m_runeCostID
    {"uint16", "spellMissileID"},                             // 227      m_spellMissileID not used
    {"uint16", "PowerDisplayId"},                               // 228      PowerDisplay.dbc, new in 3.1
    {"float", "EffectBonusMultiplier[1]"},     	// 229-231  3.2.0
    {"float", "EffectBonusMultiplier[2]"},     // 229-231  3.2.0
    {"float", "EffectBonusMultiplier[3]"},     // 229-231  3.2.0
    {"uint16", "spellDescriptionVariableID"},                   // 232      3.2.0
    {"uint16", "SpellDifficultyId"},                            // 233      3.3.0
};

#endif
