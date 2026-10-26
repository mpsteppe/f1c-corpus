## GuardedDispatchWithStateCheck_004ba740 — Session-cleanup-gated render refresh

**Summary:** Conditionally calls cleanup sub when SessionCleanupFlag is set and this[0]==1. Always runs RenderToggleRefresh and clears byte flag at this+4.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Post (0042da30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | State/type identifier (==1 enables cleanup path) |
| this | 0x4 | RW | 0 | Byte flag; cleared to 0 every call |

**Written-by note (persistence):**
- this 0x4: unconditionally cleared to 0 each call; does not persist across frames

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007d005c | dword_7D005C | R | SessionCleanupFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b97e0 | RenderToggleRefresh | Refresh/re-render UI element |
| 004b9880 | sub_4B9880 | Session cleanup processing when flag is active |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 1 | State/type identifier |

**Guard interpretation:** Condition for sub_4B9880: PASSES when dword_7D005C != 0 AND this[0]==1. Otherwise BLOCKS sub_4B9880 call. RenderToggleRefresh and byte clear always execute regardless.
