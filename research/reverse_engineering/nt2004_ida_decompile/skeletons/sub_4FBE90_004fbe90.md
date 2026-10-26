## sub_4FBE90_004fbe90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_42FE80 (0042fe80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xA3 | RW | 1 | [LLM] |
| this | 0xE4 | R | — | [LLM] |
| this | 0xFC | RW | 0 | [LLM] |
| this | 0x104 | RW | 0 | [LLM] |
| this | 0x108 | RW | — | [LLM] |
| this | 0x10C | RW | — | [LLM] |
| this | 0x110 | RW | — | [LLM] |
| this | 0x4B0 | RW | — | [LLM] |
| this | 0x4B4 | RW | — | [LLM] |
| this | 0x4B8 | RW | — | [LLM] |
| this | 0x4BC | RW | — | [LLM] |
| this | 0x4C0 | RW | — | [LLM] |
| this | 0x4C4 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0xA3: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xFC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x104: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x108: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x10C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x110: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4B0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4B4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4B8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4BC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4C0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4C4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004fc2a4 | jpt_4FC20C | R | [LLM] |
| 005d54dc | flt_5D54DC | R | [LLM] |
| 005d54e0 | flt_5D54E0 | R | [LLM] |
| 005d5bfc | flt_5D5BFC | R | [LLM] |
| 005fd7a0 | aRoadCourse | R | [LLM] |
| 005fd7ac | aTrackType | R | [LLM] |
| 00611a24 | aDDevNascar2004_21 | R | [LLM] |
| 00611c34 | aNoSector2PolyF | R | [LLM] |
| 00611c4c | aXsector2 | R | [LLM] |
| 00611c58 | aNoSector1PolyF | R | [LLM] |
| 00611c70 | aXsector1 | R | [LLM] |
| 00611c7c | aNoFinishPolyFo | R | [LLM] |
| 00611c94 | aXfinish | R | [LLM] |
| 00611c9c | aXpitbad | R | [LLM] |
| 00611ca4 | aNoPitOutPolyFo | R | [LLM] |
| 00611cbc | aXpitout | R | [LLM] |
| 00611cc4 | aNoPitInPolyFou | R | [LLM] |
| 00611cdc | aXpitin | R | [LLM] |
| 00611ce4 | aPtlit01 | R | [LLM] |
| 00611cec | aPtglow01 | R | [LLM] |
| 00611cf8 | aPtlit02 | R | [LLM] |
| 00611d00 | aPtglow02 | R | [LLM] |
| 00611d0c | aStlite | R | [LLM] |
| 00611d14 | aStglow | R | [LLM] |
| 00611d1c | aEnteredSteward_0 | R | [LLM] |
| 00628f60 | flt_628F60 | R | [LLM] |
| 006290d0 | flt_6290D0 | R | [LLM] |
| 0075cba8 | dword_75CBA8 | R | [LLM] |
| 00766124 | byte_766124 | R | [LLM] |
| 0076618c | dword_76618C | R | [LLM] |
| 00766cbc | dword_766CBC | R | [LLM] |
| 007689cc | dword_7689CC | R | [LLM] |
| 007d5da4 | dword_7D5DA4 | R | [LLM] |
| 007d6a30 | byte_7D6A30 | R | [LLM] |
| 007d7920 | dword_7D7920 | R | [LLM] |
| 007da9b8 | dword_7DA9B8 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00403d10 | sub_403D10 | [LLM] |
| 0042f6c0 | sub_42F6C0 | [LLM] |
| 004ba330 | sub_4BA330 | [LLM] |
| 004e8e50 | sub_4E8E50 | [LLM] |
| 004f8c90 | sub_4F8C90 | [LLM] |
| 004f8d70 | sub_4F8D70 | [LLM] |
| 004f9d90 | sub_4F9D90 | [LLM] |
| 00500f90 | sub_500F90 | [LLM] |
| 00500fe0 | sub_500FE0 | [LLM] |
| 005975f0 | sub_5975F0 | [LLM] |
| 0059e0c0 | TripleFieldQuery [exact] | [LLM] |
| 0059eed0 | sub_59EED0 | [LLM] |
| 005be8bc | __ftol | [LLM] |
| 005be8e3 | ??2@YAPAXI@Z | [LLM] |
| 005bf290 | __strcmpi | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `Road Course`
- `Track Type`
- `D:\dev\NASCAR_2004\Source\steward.cpp`
- `D:\dev\NASCAR_2004\Source\steward.cpp`
- `D:\dev\NASCAR_2004\Source\steward.cpp`
- `D:\dev\NASCAR_2004\Source\steward.cpp`
- `D:\dev\NASCAR_2004\Source\steward.cpp`
- `D:\dev\NASCAR_2004\Source\steward.cpp`
- `No sector 2 poly found`
- `XSECTOR2`
- `No sector 1 poly found`
- `XSECTOR1`
- `No finish poly found`
- `XFINISH`
- `XPITBAD`
- `No pit-out poly found`
- `XPITOUT`
- `No pit-in poly found`
- `XPITIN`
- `PTLIT01`
- … +6 more
