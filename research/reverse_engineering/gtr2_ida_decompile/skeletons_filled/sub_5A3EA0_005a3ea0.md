## sub_5A3EA0_005a3ea0 — ThunkOff16C96C0

**Summary:** Thunk that forwards its `this` argument to the function pointer stored in global off_16C96C0 and returns that call's double result — an indirection trampoline (likely for an import or dynamically resolved routine).

**Called by:** AnimationValueFetchWithTiming [structural] (0059b410), sub_59B780 (0059b780), sub_59E020 (0059e020), sub_59F010 (0059f010), sub_59FD00 (0059fd00), sub_5A0B40 (005a0b40), sub_5A19D0 (005a19d0), sub_5A5000 (005a5000)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 016c96c0 | off_16C96C0 | R | Function pointer read and called with `this`; target produces the returned double |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional indirect call `off_16C96C0(this)`; no values checked; nothing blocked.
