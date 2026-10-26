## sub_4CC4D8_004cc4d8 — function-pointer thunk via byte_2630004C

**Summary:** Thunk that tail-calls the function pointer stored in global byte_2630004C, forwarding no arguments. Likely an indirect dispatch trampoline to a runtime-selected implementation.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 2630004c | byte_2630004C | R | Holds the target function pointer that this thunk reads and tail-calls |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — no branches; the read of byte_2630004C and the call through it are unconditional (IDA marks this as a thunk).
