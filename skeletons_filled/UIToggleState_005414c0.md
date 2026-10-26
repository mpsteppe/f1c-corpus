## UIToggleState_005414c0 — Toggle UI boolean state (0↔1)

**Summary:** Toggles an integer state field at offset 0x1148 between 0 and 1. Returns the new value.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5613E0 (005613e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1148 | RW | — | UI boolean toggle state |

**Written-by note (persistence):**
- this 0x1148: written every call (toggle 0↔1), no conditional guard; external poke overwrites each invocation.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always executes. No early return or skip path.
