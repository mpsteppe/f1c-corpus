## sub_4FB7E0_004fb7e0 — thunk to function pointer (3 args)

**Summary:** Thin thunk forwarding the object pointer plus a2 and a3 to the global function pointer off_16CA56C and returning its result.

**Called by:** sub_4278D0 (004278d0), sub_447150 (00447150), sub_4503F0 (004503f0), sub_457A50 (00457a50), sub_576AA0 (00576aa0), sub_57BCB0 (0057bcb0), sub_57BDB0 (0057bdb0), sub_57BE70 (0057be70), sub_57C120 (0057c120), sub_582400 (00582400)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 016ca56c | off_16CA56C | R | target function pointer invoked as off_16CA56C(this, a2, a3) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional tail call through the pointer.
