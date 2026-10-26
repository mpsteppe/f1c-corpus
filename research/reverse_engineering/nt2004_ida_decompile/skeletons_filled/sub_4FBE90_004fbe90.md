## sub_4FBE90_004fbe90 — StewardTrackInit

**Summary:** Initializes track steward data — finds and registers track polygons (pit-in XSECTOR2, pit-out, finish, sector markers), allocates timing/sector arrays, configures track type (road course vs oval), and sets steward state based on game mode. Source: steward.cpp.

**Called by:** sub_42FE80 (0042fe80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xA3 | RW | 1 | road-course flag (1=road course, 0=oval) |
| this | 0xE4 | R | — | unknown |
| this | 0xFC | RW | 0 | steward state reset |
| this | 0x104 | RW | 0 | steward timer reset |
| this | 0x108 | RW | — | allocated timing elements array |
| this | 0x10C | RW | — | number of timing elements |
| this | 0x110 | RW | — | allocated sector index array |
| this | 0x4B0 | RW | — | pit-in polygon ID (XSBECTOR2) |
| this | 0x4B4 | RW | — | pit-out polygon ID |
| this | 0x4B8 | RW | — | pit-bad polygon ID |
| this | 0x4BC | RW | — | finish-line polygon ID |
| this | 0x4C0 | RW | — | sector-1 polygon ID |
| this | 0x4C4 | RW | — | sector-2 polygon ID |

**Written-by note (persistence):**
- this 0xA3: written once during track init — survives whole session
- this 0xFC: written once during init — survives until next restart
- this 0x104: written once during init — survives until next restart
- this 0x108: allocated once — stable pointer, survives until free
- this 0x10C: written once during init — survives until next restart
- this 0x110: allocated once — stable pointer, survives until free
- this 0x4B0: written once during init (polygon lookup) — survives session
- this 0x4B4: written once during init — survives session
- this 0x4B8: written once during init — survives session
- this 0x4BC: written once during init — survives session
- this 0x4C0: written once during init — survives session
- this 0x4C4: written once during init — survives session

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004fc2a4 | jpt_4FC20C | R | jump table for game-mode switch (dword_7689CC) |
| 005d54dc | flt_5D54DC | R | float constant (timing allocation factor) |
| 005d54e0 | flt_5D54E0 | R | float constant 0.0 (guard) |
| 005d5bfc | flt_5D5BFC | R | float constant |
| 005fd7a0 | aRoadCourse | R | string "Road Course" — compared against track type |
| 005fd7ac | aTrackType | R | string "Track Type" — config key |
| 00611a24 | aDDevNascar2004_21 | R | source file path "D:\dev\NASCAR_2004\Source\steward.cpp" |
| 00611c34 | aNoSector2PolyF | R | error message "No sector 2 poly found" |
| 00611c4c | aXsector2 | R | polygon name "XSECTOR2" |
| 00611c58 | aNoSector1PolyF | R | error message "No sector 1 poly found" |
| 00611c70 | aXsector1 | R | polygon name "XSECTOR1" |
| 00611c7c | aNoFinishPolyFo | R | error message "No finish poly found" |
| 00611c94 | aXfinish | R | polygon name "XFINISH" |
| 00611c9c | aXpitbad | R | polygon name "XPITBAD" |
| 00611ca4 | aNoPitOutPolyFo | R | error message "No pit-out poly found" |
| 00611cbc | aXpitout | R | polygon name "XPITOUT" |
| 00611cc4 | aNoPitInPolyFou | R | error message "No pit-in poly found" |
| 00611cdc | aXpitin | R | polygon name "XPITIN" |
| 00611ce4 | aPtlit01 | R | light object name "PTLIT01" |
| 00611cec | aPtglow01 | R | glow object name "PTGLOW01" |
| 00611cf8 | aPtlit02 | R | light object name "PTLIT02" |
| 00611d00 | aPtglow02 | R | glow object name "PTGLOW02" |
| 00611d0c | aStlite | R | start-light object name "STLITE" |
| 00611d14 | aStglow | R | start-glow object name "STGLOW" |
| 00611d1c | aEnteredSteward_0 | R | debug log "Entered Steward::..." |
| 00628f60 | flt_628F60 | R | track length float |
| 006290d0 | flt_6290D0 | R | track length / sector spacing float |
| 0075cba8 | dword_75CBA8 | R | current game state |
| 00766124 | byte_766124 | R | unknown flag |
| 0076618c | dword_76618C | R | flag: practice mode (controls steward state) |
| 00766cbc | dword_766CBC | R | flag: qualifying mode |
| 007689cc | dword_7689CC | R | current game mode pointer |
| 007d5da4 | dword_7D5DA4 | R | unknown (checked ==2) |
| 007d6a30 | byte_7D6A30 | R | unknown |
| 007d7920 | dword_7D7920 | R | debug log channel |
| 007da9b8 | dword_7DA9B8 | R | unknown |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00403d10 | sub_403D10 | get track-related float value |
| 0042f6c0 | sub_42F6C0 | set game state (dword_75CBA8) |
| 004ba330 | sub_4BA330 | unknown |
| 004e8e50 | sub_4E8E50 | get config string value for key |
| 004f8c90 | sub_4F8C90 | register light/glow object pair by name |
| 004f8d70 | sub_4F8D70 | reset timing element |
| 004f9d90 | sub_4F9D90 | initialize steward scoring state |
| 00500f90 | sub_500F90 | debug log level check |
| 00500fe0 | sub_500FE0 | debug log output |
| 005975f0 | sub_5975F0 | find polygon by name (returns ID) |
| 0059e0c0 | TripleFieldQuery [exact] | query three fields from track data |
| 0059eed0 | sub_59EED0 | register polygon for collision/timing |
| 005be8bc | __ftol | float-to-long conversion |
| 005be8e3 | ??2@YAPAXI@Z | operator new |
| 005bf290 | __strcmpi | standard stricmp |

**Guard conditions:** Polygon-lookup failures logged but non-fatal. Game-mode switch (dword_7689CC) determines steward state: case 1/5 set state to 0/4, case 2/3 check practice/qualifying flags for state 7/5/4, case 6 checks dword_7D5DA4. Road course detection: _strcmpi of track type against "Road Course" sets this+0xA3.

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
