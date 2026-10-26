## CameraPositionGetter_00545670 — Read drawable object category counters into output pointers

**Summary:** Reads three category counters from the drawable object manager at offsets 0x11C, 0x124, 0x12C and writes them to caller-supplied output pointers. Skips null output pointers.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FCEE0 (004fcee0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x11C | R | — | Counter for drawable object category 1 |
| this | 0x124 | R | — | Counter for drawable object category 4 |
| this | 0x12C | R | — | Counter for drawable object category 2 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Per-output null check: PASSES (write counter value) when pointer non-null; BLOCKED (skip write) when null.
