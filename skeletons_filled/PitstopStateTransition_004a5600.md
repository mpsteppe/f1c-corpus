## PitstopStateTransition_004a5600 — PitstopActiveObjectSwitcher

**Summary:** Transitions pitstop state machine from the current active sub-object to a new one (`a2`). Conditionally runs cleanup on the old sub-object (FlagBasedLoopConditionalCall) or skips cleanup based on operation state flags (offsets 0x184/0x190). Then either reinitializes the new sub-object (sub_4A3390) or directly activates it based on the old object's pending flag.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PitPartStateCopy (004a5330), ConditionalDispatch_55e0 (004a55e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x8) | 0x0 | R | — | Bit 0 of current active sub-object's flags (pending/active state) |
| this | 0x8 | RW | — | Pointer to the current active sub-object (swapped during transition) |
| this | 0x184 | R | — | Operation state/phase; values 3 and 4 are special (skip cleanup) |
| this | 0x190 | R | — | Additional state byte; when state=3, must be non-zero to skip cleanup |

**Written-by note (persistence):**
- this 0x8: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a3390 | sub_4A3390 | Reinitializes/sets up a sub-object after transition (called when old object had pending flag) |
| 004a3440 | FlagBasedLoopConditionalCall | Activates or processes a sub-object (cleanup on old, start on new) |

**Guard conditions:** Checks `a2 != NULL` (skip if null) and `a2 != current` (skip if no change). Then checks state at offset 0x184: skips the entire cleanup-and-transition block if state is 3 (and byte at 0x190 is non-zero) or state is 4.