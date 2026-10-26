## sub_6CD12F_006cd12f — dispatch event code 80

**Summary:** Thin wrapper that tail-calls the shared dispatcher sub_6CCA8D with constant event/opcode 80 and a zero extra argument.

**Called by:** sub_6ACF7B (006acf7b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006cca8d | sub_6CCA8D | Shared event/message dispatcher; invoked here with this, code 80, and 0 |

**Guard conditions:** None — no branches; unconditionally forwards to sub_6CCA8D(this, 80, 0).
