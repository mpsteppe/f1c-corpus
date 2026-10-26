## StringMatchWithFlagSet_0053c900 — StringTableLookupOrRegister

**Summary:** Searches a global string table for a matching entry. If found, sets a 0x400 flag on that entry. Always delegates to SearchPathPrune for further processing regardless of match outcome.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49CD80 (0049cd80), PITANIMSMASAnimationFileLoader (004a3220), PitCrewAnimationMASSetup (004a3910), sub_4A4900 (004a4900), SpecialFX_Init (004cf070), StringCompareCopy (004dc450), VidMan_Post (004fac00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b5a38 | dword_8B5A38 | R | StringTableFlags [DERIVED] (also: ` — flags) |
| 008b5a3c | byte_8B5A3C | R | AudioEntryArray [DERIVED] (also: ` — entry array base (stride 0x84) |
| 008b8e30 | dword_8B8E30 | R | RegisteredEntryCount [DERIVED] (also: ` — entry count (max 0x20) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053ca00 | SearchPathPrune | Search path pruning / processing subroutine |
| 00589901 | sub_589901 | String transformation before comparison |

**Guard conditions:** Checks if input string is non-empty (*a2 != 0); if empty, returns input pointer immediately without lookup. Checks table entry count (dword_8B8E30): if zero, skips search entirely. During search, each iteration checks if index exceeds entry count — if all entries scanned without match, returns SearchPathPrune result early.
