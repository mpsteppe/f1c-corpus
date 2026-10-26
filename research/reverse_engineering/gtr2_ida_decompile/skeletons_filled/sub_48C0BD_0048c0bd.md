## sub_48C0BD_0048c0bd — forwarder to sub_59D866 (int, char)

**Summary:** Thin wrapper that tail-calls sub_59D866 with the same two arguments (an int and a char) and returns its result unchanged.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0059d866 | sub_59D866 | Callee that performs the actual work on (a1, a2); return value passed through |

**Guard conditions:** None. Unconditional pass-through.
