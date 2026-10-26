## CameraTargetNameResolver_0040db00 — CameraTargetNameResolver

**Summary:** Compares argument string a2 against known camera target names ("Original", "Last", "AnyTrackside", "None", "Player") and returns the corresponding camera target pointer from this's fields, or delegates to TracksideCameraTargetLookup. Returns 0 for unrecognized/empty strings.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RaceCommentaryDirectorSystem (0040d4c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | pointer passed to TracksideCameraTargetLookup for non-matching names |
| this | 0x8C | R | — | camera target pointer field returned for "Original" name |
| this | 0x90 | R | — | camera target pointer field returned for "Last" name |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005beb10 | aNone | R | NoneString [DERIVED] |
| 005beb18 | aAnyTrackside | R | AnyTracksideString [DERIVED] |
| 005beb28 | aLast | R | Str_Last [DERIVED] |
| 005beb30 | aOriginal | R | StringOriginal [DERIVED] |
| 005beb3c | aPlayer_1 | R | PlayerString [DERIVED] |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040c890 | TracksideCameraTargetLookup | look up camera target for trackside/none name |
| 0040d0b0 | ModeDispatchedSubsystemCall | call subsystem dispatch for player mode |
| 00588410 | sub_588410 | string comparison (strcmp-like) |

**Guard conditions:** (1) a2 == 0 → return 0; (2) matches "Player" → call ModeDispatchedSubsystemCall; (3) matches "Original" → return this+0x8C; (4) matches "Last" → return this+0x90; (5) matches "AnyTrackside" → return 0; (6) fails "None" match → call TracksideCameraTargetLookup
