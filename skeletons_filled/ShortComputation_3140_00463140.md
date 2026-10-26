## ShortComputation_3140_00463140 — Dual Virtual Dispatch and State Reset

**Summary:** Dispatches via DualVirtualDispatchWrapper on sub-object at +0x3FB8, then resets state at +0x3FC4 to 0. Returns dispatch wrapper result.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionStateByte7CE25FSetter (00464600), sub_4A0490 (004a0490)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x3FB8 | R | — | sub-object pointer for dual virtual dispatch |
| obj | 0x3FC4 | RW | 0 | state field reset to 0 after dispatch |
| this | 0x0 | R | — | vtable/primary pointer |

**Written-by note (persistence):**
- obj 0x3FC4: written once per call (set to 0); external poke survives until next dispatch

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057a660 | DualVirtualDispatchWrapper | dual virtual dispatch on sub-object (+0x3FB8) |

**Guard conditions:** none — always dispatches and resets unconditionally.
