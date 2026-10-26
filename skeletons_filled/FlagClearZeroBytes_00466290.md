## FlagClearZeroBytes_00466290 — ClearFlagBytesF4F5

**Summary:** Clears both flag bytes (0xF4 and 0xF5) to 0 and calls FieldSetterCall with argument 2.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x40 | R | — | pointer passed to FieldSetterCall |
| this | 0xF4 | RW | 0 | flag byte cleared to 0 (inactive) |
| this | 0xF5 | RW | 0 | flag byte cleared to 0 (inactive) |

**Written-by note (persistence):**
- this 0xF4: overwritten to 0 every call. External poke survives.
- this 0xF5: overwritten to 0 every call. External poke survives.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004988a0 | FieldSetterCall | set field state on sub-object at this+0x40, param 2 (clear) |

**Guard conditions:** None — unconditional.
