## evenint_0063d32e — "even integer exponent" pow stub

**Summary:** Trivial MSVC CRT math stub: the "exponent is an even integer" branch of the pow special-case checks. It performs no computation of its own and transfers control to the empty isintTOSret return point (the caller has already applied the sign correction for an even exponent).

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — no checks in this body. Control unconditionally flows to isintTOSret; the parity classification that selected this branch was performed by the caller.
