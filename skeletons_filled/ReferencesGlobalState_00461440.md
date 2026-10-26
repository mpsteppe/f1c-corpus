## ReferencesGlobalState_00461440 — SessionStateAndGlobalFlagCheck

**Summary:** Returns true if session phase is 1 or 2 AND a global session flag byte_7D1074 is set.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** InputCommandDispatchToEntities (0045f4a0), TeamRadioNetworkMessageProcessing (0045f710)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3FC4 | R | — | Session phase/state value (compared to 1 or 2) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007d1074 | byte_7D1074 | R | Global session flag (must be non-zero for true result) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Returns false when session state not 1 or 2, or when byte_7D1074 is 0.
