## ConditionalFieldSetter_004bc2f0 — AIDriverStateChange

**Summary:** Conditionally updates AI driver state at this+0x2C with transition notification. If new state differs from current, calls AIDriverStateTransition with old/new values on global state array, then updates field.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetCommPlayerSlotSync (0045fc50), sub_462E20 (00462e20), sub_4B3400 (004b3400), AIDriverSorting (004bf390), sub_4BFF70 (004bff70), sub_4C01A0 (004c01a0), sub_4C0850 (004c0850)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | pointer to this AI driver's state array (for transition callback) |
| this | 0x2C | RW | — | AI driver current state identifier |

**Written-by note (persistence):**
- this 0x2C: written when state changes; external poke overwritten on next transition

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 [DERIVED] — global game state array passed to AIDriverStateTransition |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00419120 | AIDriverStateTransition | notifies state transition system of old->new state change |

**Guard conditions:** BLOCKED when current state (this+0x2C) equals new value (a2) — no transition needed. PASSES when states differ: calls transition, updates field.
