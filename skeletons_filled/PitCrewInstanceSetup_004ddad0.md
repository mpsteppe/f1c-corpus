## PitCrewInstanceSetup_004ddad0 — PitCrewTexturePathsBuilder

**Summary:** Builds full file paths for 9 pit-crew/vehicle texture types (car body, driver, arms, wing, helmet, pit body, pit helmet, lollipop, refueler) by combining base directory, team/track config strings, and fallback paths, then calls TextureAdjuster for each.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ZeroInitWrapper (004ddf70), sub_4E2A60 (004e2a60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | base path string pointer (dereferenced as char*) — if NULL, falls back to byte_5EA438 (default app directory) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004ddf4c | jpt_4DDC40 | R | jump table for switch on texture-type index (0-8), maps each case to wc-variant and regular-variant string pairs |
| 005c6984 | aTrackname | R | "TrackName" configuration string key, used to look up track-specific texture overrides |
| 005cd5d8 | aTeamMas | R | "TeamMass" configuration string key, loaded for team-based texture path building |
| 005d4c0c | aBmp | R | ".bmp" file extension string, appended as fallback when no extension found |
| 005d4c14 | aRefueler | R | "Refueler" texture variant string (non-wc), used as fallback for refueler texture |
| 005d4c20 | aWcrefueler | R | "WcRefueler" texture variant string (wc-prefixed), primary refueler texture key |
| 005d4c2c | aLollipop_0 | R | "Lollipop" texture variant string (non-wc), fallback for lollipop man texture |
| 005d4c38 | aWclollipop | R | "WcLollipop" texture variant string (wc-prefixed), primary lollipop texture key |
| 005d4c44 | aPithelmet | R | "PitHelmet" texture variant string (non-wc), fallback for pit helmet |
| 005d4c50 | aWcpithelmet | R | "WcPitHelmet" texture variant string (wc-prefixed), primary pit helmet key |
| 005d4c5c | aPitbody | R | "PitBody" texture variant string (non-wc), fallback for pit crew body texture |
| 005d4c64 | aWcpitbody | R | "WcPitBody" texture variant string (wc-prefixed), primary pit body key |
| 005d4c70 | aHelmet_0 | R | "Helmet" texture variant string (non-wc), fallback for driver helmet |
| 005d4c78 | aWchelmet | R | "WcHelmet" texture variant string (wc-prefixed), primary driver helmet key |
| 005d4c84 | aWing | R | "Wing" texture variant string (non-wc), fallback for rear wing texture |
| 005d4c8c | aWcwing | R | "WcWing" texture variant string (wc-prefixed), primary wing texture key |
| 005d4c94 | aArms_0 | R | "Arms" texture variant string (non-wc), fallback for driver arms texture |
| 005d4c9c | aWcarms | R | "WcArms" texture variant string (wc-prefixed), primary arms texture key |
| 005d4ca4 | aDriver | R | "Driver" texture variant string (non-wc), fallback for driver body texture |
| 005d4cac | aWcdriver | R | "WcDriver" texture variant string (wc-prefixed), primary driver texture key |
| 005d4cb8 | aWccarbody | R | "WcCarBody" texture variant string (wc-prefixed), primary car body texture key |
| 005ea438 | byte_5EA438 | R | default application directory fallback path (empty string), used when pointers are NULL |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c58a0 | StringCopyWithValidation | Copies and validates a configuration string from settings storage into a buffer |
| 004dc770 | TextureAdjuster | Selects/adjusts texture for given variant key and returns index (0-2) of chosen texture source |
| 0053cbc0 | sub_53CBC0 | Builds a file path from base directory and config string |
| 0053ce40 | PhysicsObjectLinkedListRemoval | Cleans up physics object linked list (called on the path-build result) |
| 005665b0 | sub_5665B0 | Appends or modifies a string in place (used to strip file extensions and append ".bmp") |
| 00566650 | StringCopyWithBufferRealloc | Copies a string with dynamic buffer reallocation |
| 00587bcf | FreeWrapper_7bcf | Frees allocated memory (custom free wrapper) |
| 00587c03 | OperatorNewNhMallocWrapper | Allocates memory with no-throw new (operator new wrapper) |
| 00588410 | sub_588410 | String comparison (strcmp equivalent); used to match track name config entries |
| 00589db0 | sub_589DB0 | Finds last occurrence of a character in string (used to strip file extension before appending .bmp) |

**Guard conditions:** If a1 (the base struct pointer) is NULL, the function returns immediately without doing anything. The main processing loop iterates exactly 9 times (texture types 0-8). For texture types 5-8 (pit body, pit helmet, lollipop, refueler), an additional fallback path (v45) can be included as a third texture source. After the loop, if the path-build result (v46) is allocated, it is cleaned up via PhysicsObjectLinkedListRemoval.