## sub_6CD02C_006cd02c — dispatch event code 11

**Summary:** Thin wrapper that tail-calls the shared dispatcher sub_6CCA8D with constant event/opcode 11 and a zero extra argument.

**Called by:** sub_6A1C41 (006a1c41), sub_6B321C (006b321c)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006cca8d | sub_6CCA8D | Shared event/message dispatcher; invoked here with this, code 11, and 0 |

**Guard conditions:** None — no branches; unconditionally forwards to sub_6CCA8D(this, 11, 0).
