## NthValidPartLookup_004a5820 — NthAvailablePartFinder

**Summary:** Finds the Nth (1-indexed) available part by iterating through a part list. Filters out parts whose byte at +20 is set (occupied/busy) during a valid race session, unless the out-of-session flag is active. Optionally filters by compound type via `this[87]`. Returns the matching part pointer or 0 if not found.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PitPartStateCopy (004a5330), FindZeroResultIndex (004a57f0), PitRepairStatusDisplay (004a58b0), GuardedCallWithCheck (004a5c10), PitStopOperationTimer (004a6340)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x158 | R | — | Pointer to part list structure (field at +16 holds element count) |
| this | 0x15C | R | — | Filter index; if ≥0, only count parts matching this compound type |
| this | 0x168 | R | — | unknown — not directly referenced in this function |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] — race session type (0-5); values ≤0 or >5 bypass session filter |
| 008afed4 | dword_8AFED4 | R | OutOfSessionGateFlag [DERIVED] — when set, bypasses session-based filtering |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7570 | CompoundIndexLookup | Converts a part index to a part data pointer |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x15C | >= | 0 | Filter activation flag |

**Guard interpretation:** Outer guard: `a2 > 0` — entire function returns 0 when requested index ≤ 0. Inner guard: `this[0x15C] >= 0` — enables compound-type filtering via CompoundIndexLookup(this[87]); when negative, no filter is applied and all non-occupied parts qualify.