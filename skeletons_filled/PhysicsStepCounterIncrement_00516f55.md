## PhysicsStepCounterIncrement_00516f55 — PhysicsStepIncrementCounter

**Summary:** Checks flag byte at this+0x4A; if set, dispatches virtual call via function table at this+0x1A4 (entry +8). Always increments step counter at sub-object offset 0xC (accessed via this+0x17C). Returns either virtual call result or this pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x17C) | 0xC | R | — | step counter in sub-object, incremented each call |
| *(this+0x1A4) | 0x8 | R | — | function pointer at entry +8 in dispatch table, called when flag set |
| this | 0x4A | R | — | byte flag controlling whether virtual dispatch occurs |
| this | 0x17C | R | — | pointer to sub-object containing step counter |
| this | 0x1A4 | R | — | pointer to function dispatch table |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:**
1. *(this+0x4A) != 0: flag set — dispatches virtual call to function at *(this+0x1A4)+8, result used as return value
2. *(this+0x4A) == 0: flag clear — skip dispatch, return this pointer
