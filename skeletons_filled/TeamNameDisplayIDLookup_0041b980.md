## TeamNameDisplayIDLookup_0041b980 — TeamNameToDisplayIDLookup

**Summary:** Matches a team name string (e.g. "1999 Arrows", "2002 Ferrari") read from a data struct at offset +252 against a hardcoded chain of team name constants spanning seasons 1999-2002, producing a numeric display ID (293-336). Inserts the resulting driver data entry into a UI table via DriverDataTableLookupAndTimeConversion and InsertDriverTableEntry. Part of the UI team display/rendering system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIRenderUpdateChain (00476d70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005c2748 | a2002Williams | R | Williams2002String [DERIVED] |
| 005c2758 | a2002Toyota | R | Toyota2002String [DERIVED] |
| 005c2764 | a2002Sauber | R | Str_2002Sauber [DERIVED] |
| 005c2770 | a2002Renault | R | String2002Renault [DERIVED] |
| 005c2780 | a2002Minardi | R | Team2002MinardiString [DERIVED] |
| 005c2790 | a2002Mclaren | R | Year_2002_McLarenString [DERIVED] |
| 005c27a0 | a2002Jordan | R | Year2002JordanString [DERIVED] |
| 005c27ac | a2002Jaguar | R | Year2002JaguarString [DERIVED] |
| 005c27b8 | a2002Ferrari | R | Year2002FerrariString [DERIVED] |
| 005c27c8 | a2002Bar | R | Bar2002Field [DERIVED] |
| 005c27d4 | a2002Arrows | R | TeamName_2002Arrows [DERIVED] |
| 005c27e0 | a2001Williams | R | String_2001Williams [DERIVED] |
| 005c27f0 | a2001Sauber | R | Sauber2001String [DERIVED] |
| 005c27fc | a2001Prost | R | Team2001Prost [DERIVED] |
| 005c2808 | a2001Minardi | R | TeamName_2001Minardi [DERIVED] |
| 005c2818 | a2001Mclaren | R | String_2001Mclaren [DERIVED] |
| 005c2828 | a2001Jordan | R | s_TeamName2001Jordan [DERIVED] |
| 005c2834 | a2001Jaguar | R | Year2001_Jaguar [DERIVED] |
| 005c2840 | a2001Ferrari | R | TeamName_2001Ferrari_String [DERIVED] |
| 005c2850 | a2001Benetton | R | TeamName2001Benetton [DERIVED] |
| 005c2860 | a2001Bar | R | Bar2001String [DERIVED] |
| 005c286c | a2001Arrows | R | Arrows2001String [DERIVED] |
| 005c2878 | a2000Williams | R | Str_2000Williams [DERIVED] |
| 005c2888 | a2000Sauber | R | String2000Sauber [DERIVED] |
| 005c2894 | a2000Prost | R | Team2000ProstString [DERIVED] |
| 005c28a0 | a2000Minardi | R | Year_2000_MinardiString [DERIVED] |
| 005c28b0 | a2000Mclaren | R | Year2000McLarenString [DERIVED] |
| 005c28c0 | a2000Jordan | R | Year2000JordanString [DERIVED] |
| 005c28cc | a2000Jaguar | R | Year2000JaguarString [DERIVED] |
| 005c28d8 | a2000Ferrari | R | Ferrari2000Field [DERIVED] |
| 005c28e8 | a2000Benetton | R | TeamName_2000Benetton [DERIVED] |
| 005c28f8 | a2000Bar | R | String_2000Bar [DERIVED] |
| 005c2904 | a2000Arrows | R | Arrows2000String [DERIVED] |
| 005c2910 | a1999Williams | R | Team1999Williams [DERIVED] |
| 005c2920 | a1999Stewart | R | TeamName_1999Stewart [DERIVED] |
| 005c2930 | a1999Sauber | R | String_1999Sauber [DERIVED] |
| 005c293c | a1999Prost | R | s_TeamName1999Prost [DERIVED] |
| 005c2948 | a1999Minardi | R | Year1999_Minardi [DERIVED] |
| 005c2958 | a1999Mclaren | R | TeamName_1999McLaren_String [DERIVED] |
| 005c2968 | a1999Jordan | R | TeamName1999Jordan [DERIVED] |
| 005c2974 | a1999Ferrari | R | Ferrari1999String [DERIVED] |
| 005c2984 | a1999Benetton | R | Benetton1999String [DERIVED] |
| 005c2994 | a1999Bar | R | Str_1999Bar [DERIVED] |
| 005c29a0 | a1999Arrows | R | String1999Arrows [DERIVED] |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 007cf3c8 | flt_7CF3C8 | R | TrackConditionState [CONFIRMED] |
| 007d0308 | dword_7D0308 | R | RaceActiveFlag [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144d0 | StructInitWithSentinelValues | initializes float array v3 with sentinel/zero default values before driver lookup |
| 004144f0 | DriverDataTableLookupAndTimeConversion | looks up driver data entry by display ID and converts time/lap values |
| 00418560 | InsertDriverTableEntry | inserts the resolved driver data entry into the UI driver table at flt_5EA618 |
| 00566810 | sub_566810 | string comparison — checks if team name string at a1+252 matches a given team name constant |

**Guard conditions:** Three conditions must all PASS: `dword_7D0308 != 0` (race is active), `flt_7CF3C8 != 0.0` (track condition state is non-zero/valid), and `a1 != 0` (pointer is non-null). If any fails, function returns immediately (BLOCKED). Within the if-else chain, if no team name matches, function returns without inserting any entry. Only the first matching team name (checked in order 1999→2000→2001→2002, within each year alphabetically) produces an ID and triggers the table insert.