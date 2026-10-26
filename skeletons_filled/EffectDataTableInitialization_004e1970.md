## EffectDataTableInitialization_004e1970 — SubsystemReadyTableInit

**Summary:** Queries readiness for all 14 subsystems (indices 0-13) via SubsystemReadyQuery and stores results in an array at offset 0xB70. Called during loading/initialization phase to populate subsystem status table.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LoadingPhase1 (004b87c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB70 | RW | — | array of 14 DWORD subsystem ready flags, populated per call |

**Written-by note (persistence):**
- this 0xB70: all 14 entries overwritten each call; no persistence across calls

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e18c0 | SubsystemReadyQuery | check if subsystem by index is initialized and ready |

**Guard conditions:** None — always iterates all 14 subsystems.
