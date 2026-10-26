## ??1ios_base@std@@UAE@XZ_0_00438030 — std::ios_base destructor

**Summary:** MSVC STL std::ios_base destructor: overwrites the object's vtable pointer at this+0x0 with off_712568 and, when the dword at this+0x10C is zero, re-zeroes that field and runs the internal base-teardown helper (sub_4DA470) on this+0x110. C++ runtime / iostream base-class cleanup.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable slot — overwritten with the ios_base vtable pointer off_712568 during destruction |
| this | 0x10C | RW | 0 | Dword ownership/counter field; when it is 0 the buffer/holder at this+0x110 is destroyed and the field is re-zeroed |

**Written-by note (persistence):**
- this 0x0: written unconditionally on every destructor invocation (vtable pointer store); only a destruction event rewrites it, so an external poke survives until the object is destroyed.
- this 0x10C: written (to 0) only inside the branch taken when it is already 0 — the value is unchanged. A poke of a nonzero value makes the branch fail, so the poke survives and the cleanup path is skipped.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0043807b | loc_43807B | R | Code label inside this function referenced by the SEH/unwind region (structural exception-handling artifact of the MSVC EH model) |
| 004380b0 | loc_4380B0 | R | Code label inside this function referenced by the SEH/unwind region (structural) |
| 004380d7 | off_4380D7 | R | Location inside this function referenced from the exception/unwind metadata (structural) |
| 006e5134 | ??1ios_base@std@@UAE@XZ_0_SEH | R | SEH scope table for this destructor (structured exception handling/unwind bookkeeping) |
| 00712568 | off_712568 | R | Vtable pointer written to this+0x0 (ios_base vtable) |
| 016c67f8 | off_16C67F8 | R | Referenced from the function's exception-handling/unwind path (structural) |
| 016cdcf3 | dword_16CDCF3 | R | Referenced from the function's exception-handling/unwind path (structural) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** One branch: if the dword at this+0x10C equals 0, the cleanup executes — field re-zeroed and the base-teardown helper (sub_4DA470 in the body) is called on this+0x110. If this+0x10C is nonzero, the branch is BLOCKED and only the vtable store at this+0x0 occurs.
