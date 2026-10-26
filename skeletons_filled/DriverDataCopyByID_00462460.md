## DriverDataCopyByID_00462460 — DriverDataLookupByID

**Summary:** Searches driver entries by ID byte, copies matching entry data (0x8C bytes) and a corresponding DWORD value from a parallel array.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetCommSessionMessageDispatcher (0045d890), DeferredTextureObjectLoader (0046e1b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x3E14 | R | — | Driver count (loop limit) |
| this | 0x0 | R | — | This pointer dereference |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x3E14 | <= | 0 | Driver count — returns 0 immediately when 0 or negative |

**Guard interpretation:** When driver count <= 0, returns 0 (not found) without looping. When ID byte at entry+0x7C (1040-916=124=0x7C) matches a2, copies entry data and returns 1.
