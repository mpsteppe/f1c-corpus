## ScoringGateTimeoutCheck_004cdad0 — ScoringGateTimeoutCheck

**Summary:** Removes particles that timeout (current time before their birth time) when scoring system is active (dword_8AB6E4 == 2). Delegates to scoring system then iterates particle array removing entries whose birth time exceeds current time.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x64 | R | — | particle count (a1[25]) |
| this | 0x68 | R | — | particle array pointer (a1[26]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ab6ec | dword_8AB6EC | R | ScoringDataPtr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b9ce0 | Delegation | delegate to scoring system method |
| 004cb5a0 | ArrayElementRemoval | remove timed-out particle from array |

**Guard conditions:** Outer guard: dword_8AB6E4 == 2. PASSES: enter scoring gate mode, delegate, remove particles with current time < birth time (v5+8). BLOCKED (≠ 2): skip entirely.
