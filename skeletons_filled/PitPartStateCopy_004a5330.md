## PitPartStateCopy_004a5330 — PitPartStateCopy

**Summary:** Copies pit-stop part state from a source vehicle object into a destination pit-stop state structure, including tire brand lookup, compound index search, scoring interval computation, and callback chain processing. Part of the pit-stop state management system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SuspensionAndWheelPhysics (004e5f60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | pointer to first pit-stop callback linked list (processed via FlagBasedLoopConditionalCall) |
| this | 0x10 | R | — | pointer to second pit-stop callback linked list |
| this | 0x6C | RW | — | pit-stop state value (copied from source vehicle state) |
| this | 0x75 | RW | 0 | boolean: pit-stop status flag (cleared on copy) |
| this | 0xA8 | R | — | valid-part count (read from copied part data, gates search loop) |
| this | 0xAC | RW | 1 | current part index / search result (defaults to 1 if no match found) |
| this | 0xEC | R | — | previous part state value (self-read, then copied forward to 0xF0) |
| this | 0xF0 | RW | — | current part state value (copied from previous slot at 0xEC) |
| this | 0xF5 | RW | 0 | boolean: secondary pit-stop status flag (cleared on copy) |
| this | 0x158 | RW | — | tire brand lookup result for current part |
| this | 0x15C | RW | — | compound index for current part (may be overridden for session types 5-7) |
| this | 0x160 | RW | — | scoring base value (copied from source vehicle) |
| this | 0x164 | RW | 1024 | first part interval start index (constant 1024) |
| this | 0x168 | RW | — | first part interval value (source data or scaled computation) |
| this | 0x16C | RW | 2048 | second part interval start index (constant 2048) |
| this | 0x170 | RW | — | second part interval value |
| this | 0x174 | RW | 3072 | third part interval start index (constant 3072) |
| this | 0x178 | RW | — | third part interval value |
| this | 0x17C | RW | — | part-interval scale factor (float, copied from source; zero triggers default intervals) |
| this | 0x184 | RW | 0 | accumulator field (zeroed on copy) |
| this | 0x188 | RW | 0 | accumulator field (zeroed on copy) |
| this | 0x18C | RW | 0 | accumulator field (zeroed on copy) |

**Written-by note (persistence):**
- this 0x6C: recalc every frame — external poke does NOT persist
- this 0x75: recalc every frame — external poke does NOT persist
- this 0xAC: recalc every frame — external poke does NOT persist
- this 0xF0: recalc every frame — external poke does NOT persist
- this 0xF5: recalc every frame — external poke does NOT persist
- this 0x158: recalc every frame — external poke does NOT persist
- this 0x15C: recalc every frame — external poke does NOT persist
- this 0x160: recalc every frame — external poke does NOT persist
- this 0x164: recalc every frame — external poke does NOT persist
- this 0x168: recalc every frame — external poke does NOT persist
- this 0x16C: recalc every frame — external poke does NOT persist
- this 0x170: recalc every frame — external poke does NOT persist
- this 0x174: recalc every frame — external poke does NOT persist
- this 0x178: recalc every frame — external poke does NOT persist
- this 0x17C: recalc every frame — external poke does NOT persist
- this 0x184: recalc every frame — external poke does NOT persist
- this 0x188: recalc every frame — external poke does NOT persist
- this 0x18C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007d0374 | dword_7D0374 | R | ScoringSessionValue [DERIVED] |
| 008ad254 | dword_8AD254 | R | StateFlagPair [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a3440 | FlagBasedLoopConditionalCall | iterate and conditionally invoke callback chain on linked list |
| 004a5600 | PitstopStateTransition | execute pit-stop state transition for callback list |
| 004a5660 | ArithmeticComparison_5660 | arithmetic comparison dispatch for state decision |
| 004a56b0 | StateTransition | trigger state transition with parameter |
| 004a57f0 | FindZeroResultIndex | search for zero-result index in part data |
| 004a5820 | NthValidPartLookup | lookup Nth valid part entry from global part table |
| 004d7570 | CompoundIndexLookup | resolve compound index from part identifier |
| 004d7880 | TireBrandLookup | lookup tire brand from part data |
| 00587bdc | CRTFtol | convert floating-point to integer (C runtime truncation) |

**Guard conditions:** Part-count loop gate: iterates while index < valid-part count (this+0xA8). Session-type override: when compound index (this+0x15C) < 0 AND session type (dword_7C56A4) in range [5,7], performs compound-index override from source. Scale-factor branch: when source scale factor (a2+0x1994) == 0.0, uses constant interval boundaries (1024/2048/3072); otherwise computes scaled intervals via CRTFtol. Search-fallback: when part search fails (index >= count), defaults index to 1.