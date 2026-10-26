## DisplayMessage0x11c_0041a4a0 — SessionEvent284Emitter

**Summary:** Inserts a fixed event (type 284) into the session event table when race is active and track condition is valid. No parameters — always uses same event ID and defaults.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4BCCC0 (004bccc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | Zero threshold constant (~0.0f) |
| 005ea618 | flt_5EA618 | R | Pointer to session event table |
| 007cf3c8 | flt_7CF3C8 | R | Track condition state — must be nonzero |
| 007d0308 | dword_7D0308 | R | Race active flag — must be nonzero |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144f0 | DriverDataTableLookupAndTimeConversion | Fills local struct with fixed event 284 and computed time |
| 00418560 | InsertDriverTableEntry | Inserts event 284 into session event table |

**Guard conditions:** dword_7D0308 (race active) must be nonzero. flt_7CF3C8 (track condition) must be != 0.0.
