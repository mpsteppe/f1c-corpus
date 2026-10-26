## ConditionalStateUpdate_004ba150 — Session flag-gated update

**Summary:** Conditionally triggers a session update when the session is active (this[0]==1) and a packed flag at offset 8 is not yet set. Passes session time and message count to CallWrapper_9870.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GamePostMainLoop (0042d8a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Session active flag (==1 = active) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007d2e50 | dword_7D2E50 | R | SessionMsgCount [DERIVED] (also: ` — session message counter) |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b9870 | CallWrapper_9870 | Wrapper call to process session update with msg count + time |
| 004b9a00 | PackedFlagRead_9a00 | Read packed bit flag at this+0x8 (guard check) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 1 | Session active flag |

**Guard interpretation:** PASSES when this[0]==1 (session active) AND PackedFlagRead_9a00(this+0x8)==0 (trigger flag not yet set). BLOCKS if session inactive or flag already set.
