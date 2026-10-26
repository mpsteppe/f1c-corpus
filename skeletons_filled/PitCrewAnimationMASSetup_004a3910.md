## PitCrewAnimationMASSetup_004a3910 — PitCrewAnimationMASFileLoader

**Summary:** Loads pit-crew animation MAS files from season/track-specific directories, builds file paths with left/normal hand variants, and sets up animation range parameters for pit crew members. Part of pit stop animation system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4A4900 (004a4900)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x74) | 0x10 | R | — | animation duration/length from loaded MAS data (offset 16 into sub-object) |
| *(this+0x74) | 0x2C | R | — | animation parameter at offset 44 into sub-object (used for range upper bound) |
| this | 0x0 | RW | 0 | 16-bit zero-initialized header (zeroed before path copy) |
| this | 0x70 | R | — | animation slot count / state counter (used as guard threshold) |
| this | 0x74 | R | — | pointer to animation data array (each entry has duration + range data) |
| this | 0x7C | RW | — | animation range initializer output (set via RangeProportionInitializer) |
| this | 0x80 | RW | — | second animation range initializer output (offset 128, second slot) |

**Written-by note (persistence):**
- this 0x0: init-once — external poke survives until next file load
- this 0x7C: init-once — external poke survives until next file load
- this 0x80: init-once — external poke survives until next file load

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c6e74 | aNormal_0 | R | Str_Normal [DERIVED] |
| 005cd480 | aPitanimsMas | R | StringPitAnimsMas [DERIVED] |
| 005cd490 | byte_5CD490 | R | UnknownByteConstant [DERIVED] |
| 005cd49c | aAnm | R | Ext_Anm [DERIVED] |
| 005cd4a4 | byte_5CD4A4 | R | UnknownByteFlag [DERIVED] |
| 005cd4b0 | aLeft | R | LeftString [DERIVED] |
| 005cd4b8 | aPits_0 | R | Str_Pits_0 [DERIVED] |
| 005cd4c0 | aPitguycMts | R | StringPitGuyCMts [DERIVED] |
| 005ea3ec | byte_5EA3EC | R | LeftHandPitFlag [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec3d8 | dword_5EC3D8 | R | SeasonDir [DERIVED] |
| 005ec420 | dword_5EC420 | R | TrackDir [DERIVED] |
| 007cf884 | dword_7CF884 | R | DetailLevel [DERIVED] (also: ` â€” detail level (â‰¤1 = load pitcrew meshes) |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a1fd0 | RangeProportionInitializer | initializes animation range start/end values for a slot |
| 004a21d0 | StringCopyWithReverse | copies string and conditionally reverses character order |
| 004a22d0 | sub_4A22D0 | loads and sets up animation data from a built filepath |
| 004a3b50 | Camera | sets up camera/transform data for the pit-crew animation |
| 004a3fe0 | ShortComputation_3fe0 | finalizes animation setup with a short computation step |
| 0053c800 | StringRegistry | registers/retrieves a string from the global string table |
| 0053c900 | StringMatchWithFlagSet | string matching with flag set operation |
| 0053cbc0 | sub_53CBC0 | builds file path string, possibly concatenating directory + filename |
| 0053ce40 | PhysicsObjectLinkedListRemoval | removes a physics-linked-list object (cleanup after loading) |
| 005665b0 | sub_5665B0 | appends a string component to a path buffer |
| 00566650 | StringCopyWithBufferRealloc | copies string with buffer reallocation if needed |
| 00587bcf | FreeWrapper_7bcf | frees allocated memory (destructor cleanup) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x70 | > | 0 | animation slot count > 0 — at least one animation loaded |
| this | 0x70 | > | 1 | animation slot count > 1 — second animation slot available |

**Guard interpretation:** `this+0x70 > 0`: first animation loaded successfully → initialize first range with RangeProportionInitializer (start=0.0, end=duration). BLOCKED: skip first range init. `this+0x70 > 1`: second animation loaded successfully → initialize second range contiguous with first (start=previousEnd, end=previousEnd+duration2). BLOCKED: skip second range init.
