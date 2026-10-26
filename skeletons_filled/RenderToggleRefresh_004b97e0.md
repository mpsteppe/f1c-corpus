## RenderToggleRefresh_004b97e0 — RenderToggleRefresh

**Summary:** Calls sub_4B7500 with the first DWORD of `this` and a boolean indicating whether a global scoring/cut-scene flag is active. Part of render toggle / scene refresh system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GuardedDispatchWithStateCheck (004ba740)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | first DWORD of struct (passed to sub_4B7500 as argument) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007d0038 | dword_7D0038 | R | ScoringGateFlag [DERIVED] (also: ` — global flag) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b7500 | sub_4B7500 | performs render toggle / scene refresh operation |

**Guard conditions:** None — always calls sub_4B7500 with the flag from dword_7D0038.
