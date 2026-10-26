## FieldSetter_fca0_0054fca0 — Render state field setter

**Summary:** Stores a single integer value into a field at this+0x64. Used by render state setup functions to set a state parameter.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_546F70 (00546f70), sub_546FE0 (00546fe0), ConditionalRenderStateSetup (00547040), GuardedRenderStateSet (005470a0), ConditionalCheckCall (00547100)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x64 | RW | — | Render state parameter value |

**Written-by note (persistence):**
- this 0x64: unconditionally overwritten each call; survives until next call or external modification

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — unconditionally writes the value.
