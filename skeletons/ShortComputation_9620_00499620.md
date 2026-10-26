## ShortComputation_9620_00499620 — Conditional double-free wrapper

**Summary:** Conditionally frees inner pointer at this+0 then optionally frees this itself. Part of object/container teardown.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_495300 (00495300)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | inner pointer to memory block — freed when flag is set |
| this | 0xC | R | — | byte flag indicating whether inner pointer should be freed |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | frees heap memory |

**Guard conditions:** Two guards. Guard 1: `this+0xC != 0` — PASSES frees inner pointer at this+0; BLOCKED skips inner free. Guard 2: `a2 & 1` — PASSES frees this (container); BLOCKED skips container free.
