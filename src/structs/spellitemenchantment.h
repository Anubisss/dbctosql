/*
 * DBC to SQL Converter
 * Copyright (C) 2012  Dagfinn (Uberdaff)
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

#ifndef __SPELLITEMENCH_H__
#define __SPELLITEMENCH_H__

char const *SPELLITEMENCH_DBC   = "SpellItemEnchantment.dbc";
char const *SPELLITEMENCH_SQL   = "SpellItemEnchantment.sql";
char const *SPELLITEMENCH_TABLE = "SpellItemEnchantment";
char const *SPELLITEMENCH_CLIENT_VERSION = "3.3.5a";

#define SPELLITEMENCH_DBC_CLIENT_BUILD  12340 // 3.3.5a

#define SPELLITEMENCH_DBC_COLUMN_NUMS   38
#define SPELLITEMENCH_DBC_ROWS_NUMS    2656

const std::string spellItemEnch_definition[SPELLITEMENCH_DBC_COLUMN_NUMS][2] =
{
    {"uint16", "ID"},                                       // 0        m_ID
    {"uint16", "charges"},                                  // 1        m_charges
    {"uint16", "type[1]"},                                  // 2-4      m_effect[MAX_ITEM_ENCHANTMENT_EFFECTS]
    {"uint16", "type[2]"},                                  // 2-4      m_effect[MAX_ITEM_ENCHANTMENT_EFFECTS]
    {"uint16", "type[3]"},                                  // 2-4      m_effect[MAX_ITEM_ENCHANTMENT_EFFECTS]
    {"uint16", "amount[1]"},                                // 5-7      m_effectPointsMin[MAX_ITEM_ENCHANTMENT_EFFECTS]
    {"uint16", "amount[2]"},                                // 5-7      m_effectPointsMin[MAX_ITEM_ENCHANTMENT_EFFECTS]
    {"uint16", "amount[3]"},                                // 5-7      m_effectPointsMin[MAX_ITEM_ENCHANTMENT_EFFECTS]
    {"uint16", "amount2[1]"},                               // 8-10     m_effectPointsMax[MAX_ITEM_ENCHANTMENT_EFFECTS]
    {"uint16", "amount2[2]"},                               // 8-10     m_effectPointsMax[MAX_ITEM_ENCHANTMENT_EFFECTS]
    {"uint16", "amount2[3]"},                              // 8-10     m_effectPointsMax[MAX_ITEM_ENCHANTMENT_EFFECTS]
    {"uint16", "spellid[1]"},                              // 11-13    m_effectArg[MAX_ITEM_ENCHANTMENT_EFFECTS]
    {"uint16", "spellid[2]"},                              // 11-13    m_effectArg[MAX_ITEM_ENCHANTMENT_EFFECTS]
    {"uint16", "spellid[3]"},                              // 11-13    m_effectArg[MAX_ITEM_ENCHANTMENT_EFFECTS]
    {"char*",  "description[1]"},                          // 14-29    m_name_lang[16]
    {"char*",  "description[2]"},                          // 14-29    m_name_lang[16]
    {"char*",  "description[3]"},                          // 14-29    m_name_lang[16]
    {"char*",  "description[4]"},                          // 14-29    m_name_lang[16]
    {"char*",  "description[5]"},                          // 14-29    m_name_lang[16]
    {"char*",  "description[6]"},                          // 14-29    m_name_lang[16]
    {"char*",  "description[7]"},                          // 14-29    m_name_lang[16]
    {"char*",  "description[8]"},                          // 14-29    m_name_lang[16]
    {"char*",  "description[9]"},                          // 14-29    m_name_lang[16]
    {"char*",  "description[10]"},                          // 14-29    m_name_lang[16]
    {"char*",  "description[11]"},                          // 14-29    m_name_lang[16]
    {"char*",  "description[12]"},                          // 14-29    m_name_lang[16]
    {"char*",  "description[13]"},                          // 14-29    m_name_lang[16]
    {"char*",  "description[14]"},                          // 14-29    m_name_lang[16]
    {"char*",  "description[15]"},                          // 14-29    m_name_lang[16]
    {"char*",  "description[16]"},                          // 14-29    m_name_lang[16]
    {"uint16", "descriptionFlags"},                         // 30 name flags
    {"uint16", "aura_id"},                                  // 31       m_itemVisual
    {"uint16", "slot"},                                     // 32       m_flags
    {"uint16", "GemID"},                                    // 33       m_src_itemID
    {"uint16", "EnchantmentCondition"},                     // 34       m_condition_id
    {"uint16", "requiredSkill"},                            // 35       m_requiredSkillID
    {"uint16", "requiredSkillValue"},                       // 36       m_requiredSkillRank
    {"uint16", "requiredLevel"},                            // 37       m_requiredLevel
};

#endif
