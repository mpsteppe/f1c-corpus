## ModeDispatchedSubsystemCall_0040d0b0 — DispatchModeSubsystemCall

**Summary:** Dispatches to a subsystem via UtilityFunction_a610 with argument selected by DispatchModeSelector (0→2, 1→1, 2→0, 3→3). Uses stored object pointer at this+0x18.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CameraTargetNameResolver (0040db00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x18 | R | — | pointer to subsystem object passed to UtilityFunction_a610 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0040d0ec | jpt_40D0C3 | R | jump table for dispatch mode selector |
| 007cfdc4 | dword_7CFDC4 | R | DispatchModeSelector [CONFIRMED] — selects second argument (0-3) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040a610 | UtilityFunction_a610 | subsystem function called with object and mode-dependent argument |

**Guard conditions:** if this+0x18 is null, returns 0 immediately
