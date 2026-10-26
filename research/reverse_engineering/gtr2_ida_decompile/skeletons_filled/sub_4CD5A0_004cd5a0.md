## sub_4CD5A0_004cd5a0 — function-pointer thunk (indirect forwarder)

**Summary:** Thunk/forwarder: passes the incoming `this` and second argument straight through to the function pointer stored at off_16CA268 and returns its result unchanged. The real implementation lives behind the indirect pointer (likely an import or runtime-assigned handler), so behavior depends on whatever is installed there.

**Called by:** sub_4970B0 (004970b0), sub_4CD9B0 (004cd9b0), sub_4CDC40 (004cdc40), sub_4CEAF0 (004ceaf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 016ca268 | off_16CA268 | R | Indirect function pointer holding the real target; called with (this, a2) and its return value forwarded back |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — the indirect call through off_16CA268 is unconditional; no fields or values checked, nothing blocked.
