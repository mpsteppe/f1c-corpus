## sub_48CAC0_0048cac0 — Forward wrapper around sub_48CA60

**Summary:** Trivial forwarding wrapper: passes this to sub_48CA60 and returns 0. All real work happens in sub_48CA60.

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
| 0048ca60 | sub_48CA60 | Target routine: performs the polling loop and branch on this+0x248 |

**Guard conditions:** None — unconditional call to sub_48CA60(this), then constant return 0.
