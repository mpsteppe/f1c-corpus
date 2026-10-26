## FlagBasedLoopConditionalCall_004a3440 — PitCrewFlaggedArrayProcessor

**Summary:** Processes an array of pit-crew-related objects when the pending flag (bit 0) is set. Iterates through objects at base `this[4]` (each 120 bytes), calls Bit12FlagSet on non-null entries. Optionally updates UI widgets if detail level ≥ 2 and `this[5]` is non-zero. Clears flag bits 0-1 at end.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PitCrewAnimationLoader (004a2a90), PitPartStateCopy (004a5330), PitstopStateTransition (004a5600), AIStateMachineWithModeDispatch (004a5d10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Flags field; bit 0 = pending-process flag, bits 0-1 cleared as acknowledgment |
| this | 0xC | R | — | Count of elements in the array to process |
| this | 0x10 | R | — | Pointer to base of 120-byte-element array of pit object pointers |
| this | 0x14 | R | — | Boolean enabling UI widget recursive update |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cf884 | dword_7CF884 | R | DetailLevel [DERIVED] (also: ` â€” detail level (≤1 = load pitcrew meshes) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054c1a0 | Bit12FlagSet | Sets bit 12 on the target pit-crew-related object (activation/enable flag) |
| 0054c1b0 | UIWidgetRecursiveStateUpdate | Recursively shows/hides UI widgets (visibility update) |

**Guard conditions:** Checks `(*(_BYTE *)this & 1) != 0`. PASSES when bit 0 of field at offset 0 is set (pending flag active). BLOCKED (early skip of entire body) when bit 0 is clear.
