## sub_6CCF96_006ccf96 — dispatch event code 92

**Summary:** Thin wrapper that tail-calls the shared dispatcher sub_6CCA8D with constant event/opcode 92 and a zero extra argument. One of a family of per-code event stubs on the same object.

**Called by:** sub_6A1C41 (006a1c41), sub_6B0326 (006b0326)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006cca8d | sub_6CCA8D | Shared event/message dispatcher; invoked here with this, code 92, and 0 |

**Guard conditions:** None — no branches; unconditionally forwards to sub_6CCA8D(this, 92, 0).
