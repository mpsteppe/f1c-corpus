## sub_48BCF0_0048bcf0 — apply stored value pair and clear dirty flag

**Summary:** Forwards the float at this+0x134 and the dword at this+0x138 to sub_435990 together with the global context byte_B64150, runs sub_434BB0 once, then clears the byte at this+0x130 to 0 and returns 0. Looks like a "commit/apply pending setting" routine.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x130 | RW | 0 | Byte flag cleared to 0 after the apply step (pending/dirty indicator) |
| this | 0x134 | R | — | Float passed as the 3rd argument to sub_435990 |
| this | 0x138 | R | — | Dword passed as the 2nd argument to sub_435990 |

**Written-by note (persistence):**
- this 0x130: cleared to 0 on every call — an external poke survives only until the next call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00b64150 | byte_B64150 | R | Global context/state object passed as the 1st argument to sub_435990 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00434bb0 | sub_434BB0 | Follow-up processing/commit step invoked once after the value is forwarded |
| 00435990 | sub_435990 | Applies/forwards the value pair from this+0x138 and this+0x134 with the global context |

**Guard conditions:** None. Runs unconditionally and always returns 0.
