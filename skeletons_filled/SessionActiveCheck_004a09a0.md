## SessionActiveCheck_004a09a0 — SessionActiveCheck

**Summary:** Checks if session is active by dereferencing the standings buffer. If active, delegates to get vehicle setup path, loads track scene, and calls session sub-initializer. Returns 1 if inactive, 0 if active.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4A0590 (004a0590)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007d2db0 | dword_7D2DB0 | R | RaceStandingsSortBuffer [CONFIRMED] |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a09f0 | sub_4A09F0 | Session scene sub-initializer |
| 004c2850 | LinkedListDereference | Dereferences linked list to check session activity |
| 004c29d0 | DelegationChain | Retrieves vehicle setup path via delegation chain |
| 004c55b0 | TrackSceneLoader | Loads track scene from path string |

**Guard conditions:** LinkedListDereference non-null PASSES (session active → v2=0, load scene), null BLOCKS (v2=1, skip); DelegationChain result non-null PASSES (load scene + sub-init), null BLOCKS (still return 0)
