## SceneStateSetup_00541500 — Initialize scene state node

**Summary:** Creates a new scene state object via vtable call with type-dependent initialization parameters (a2: 1, 2, or 4). Increments state counter at 0x13B4 on success.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StringCopyWithFlagUnion (0055d2a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1100) | 0xB0 | R | — | vtable offset 176 (0xB0) — scene state creation method |
| this | 0x0 | RW | — | stores result of scene creation call (handle/pointer) |
| this | 0x1100 | R | — | pointer to vtable-bearing object for scene creation |
| this | 0x13B4 | RW | — | scene state counter, incremented on each successful creation |
| this | 0x13D8 | R | — | guard flag; must be non-zero to proceed |

**Written-by note (persistence):**
- this 0x0: written every successful call (result of scene creation); overwritten each invocation.
- this 0x13B4: incremented by 1 each successful call; external poke survives between calls.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ad208 | dbl_5AD208 | R | LifetimeClampThreshold [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** this[0x13D8] (guard flag) must be non‑zero. If zero, function returns 0 immediately — scene state creation blocked.
