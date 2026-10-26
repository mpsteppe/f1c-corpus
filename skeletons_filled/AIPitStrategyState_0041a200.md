## AIPitStrategyState_0041a200 — PitStrategyEventHandler

**Summary:** Handles AI pit strategy state transitions for commentary. When driver is pitting (pittingStatus==1), checks pit strategy type and inserts appropriate event (42 or 52) into session event table. When not pitting, fires a Boolean OR check (event 42). Restricted to player vehicle during active race.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIStateMachineWithModeDispatch (004a5d10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3450 | R | — | pittingStatus — if 1, driver is pitting |
| this | 0x4040 | R | — | Pit strategy type (2 = entering pit, -1 = unknown, else = other) |
| this | 0x4894 | R | — | Driver ID — used to match against player vehicle ID in guard |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | Zero threshold constant (~0.0f) |
| 005ea618 | flt_5EA618 | R | Pointer to session event table (insert target) |
| 007c54e8 | dword_7C54E8 | R | Player vehicle pointer — used to get player driver ID for guard match |
| 007c56a8 | dword_7C56A8 | R | Race phase — must not be 8 (post-race) to proceed |
| 007cf3c8 | flt_7CF3C8 | R | Track condition state — must be nonzero |
| 007d0308 | dword_7D0308 | R | Race active flag — must be nonzero |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144f0 | DriverDataTableLookupAndTimeConversion | Fills local struct with event type ID and computed time |
| 00418560 | InsertDriverTableEntry | Inserts pit strategy event into session event table |
| 00418a20 | BooleanOROfTwoChecks | Fires Boolean OR check on two event flags (event 42) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x3450 | == | 1 | pittingStatus — if 1, driver is pitting |

**Guard interpretation:** Global guards: dword_7D0308 (race active) must be nonzero, flt_7CF3C8 (track condition) != 0.0, dword_7C56A8 (race phase) != 8, and input driver ID (this+0x4894) must match player vehicle driver ID. If pittingStatus == 1: evaluate pit type (this+0x4040); if 2 or -1 use event 52, else event 42; then lookup data and insert entry. If pittingStatus != 1: fire BooleanOROfTwoChecks with event 42.
