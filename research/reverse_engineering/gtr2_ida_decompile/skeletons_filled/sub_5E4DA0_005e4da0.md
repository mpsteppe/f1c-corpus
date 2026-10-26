## sub_5E4DA0_005e4da0 — get position triple (wrapper for sub_5D7600)

**Summary:** Thin getter that forwards the transform context at this+0x158 (this+86 floats) plus three output pointers to sub_5D7600, which retrieves the x/y/z coordinate. Used by callers that need the transform position.

**Called by:** sub_5FBCC0 (005fbcc0), sub_5FCE80 (005fce80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005d7600 | sub_5D7600 | reads the live x/y/z coordinate from the transform at this+0x158 into the three output pointers |

**Guard conditions:** No conditional branches — the call is forwarded unconditionally and its result returned.
