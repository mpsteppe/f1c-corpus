## ?CatchGuardHandler@@YA?AW4_EXCEPTION_DISPOSITION@@PAUEHExceptionRecord@@PAUCatchGuardRN@@PAX2@Z_00630bc5 — CatchGuardHandler (catch-pass guard)

**Summary:** MSVC C++ EH guard handler: verifies that the registration node's state matches the expected catch-pass marker (dword_912B08). On a match it forwards to sub_6365D0 to dispatch the catch with the frame, FuncInfo and context captured in the registration node; on mismatch it flags the exception record (bit 8) and returns ContinueSearch. Registered by the compiler around catch bodies.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | — | Exception record's flags dword — OR'd with 0x8 on the mismatch path |

**Written-by note (persistence):**
- this 0x4: written only on the mismatch branch (`ExceptionFlags |= 8`); a poke of that bit would be overwritten the next time a non-matching catch guard runs.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00912b08 | dword_912B08 | R | Expected catch-pass marker compared against the registration node's state field |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006365d0 | sub_6365D0 | Catch dispatch routine — invoked with the exception record, handler frame, context, FuncInfo, state and registration node to transfer control into the matching catch |

**Guard conditions:** Compares the registration node's state field (a2->state) with dword_912B08. Equal → PASSES to sub_6365D0 (catch is dispatched with handler/FuncInfo/context pulled from a2[1]) and its return value is returned. Not equal → BLOCKED: sets bit 3 (8) in the exception record's flags and returns 1 (ExceptionContinueSearch); no dispatch happens.
