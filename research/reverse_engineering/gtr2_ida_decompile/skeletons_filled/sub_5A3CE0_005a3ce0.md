## sub_5A3CE0_005a3ce0 — GetField0x7C

**Summary:** Trivial getter returning the dword field at this+0x7C (index 31); no state change.

**Called by:** sub_59B880 (0059b880), sub_59BA90 (0059ba90), sub_59C960 (0059c960), sub_59CA30 (0059ca30), sub_5A0970 (005a0970)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x7C | R | — | Dword field returned to the caller; meaning unknown from this function alone |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional `return this[31]`; nothing checked, nothing blocked.
