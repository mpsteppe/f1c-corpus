## StreamMagicNumberCheck_0058a6d5 — MagicNumberDispatchCheck

**Summary:** Checks if a double-indirect pointer's first DWORD matches magic value -529697949 (0xE0D8B623). If match, dispatches to SEH handler function; otherwise returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_58A677 (0058a677), SEHAwareVirtualCallDispatchLoop (0059379b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | First DWORD of pointed-to object (magic signature) |
| this | 0x0 | R | — | Pointer to object whose first DWORD is checked |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x0 | == | -529697949 (0xE0D8B623) | Magic signature identifying valid object for SEH dispatch |

**Guard interpretation:** If **a1 == 0xE0D8B623 (magic matches), calls SEH dispatch function (PASS). Otherwise returns 0 (BLOCKED — no dispatch).
