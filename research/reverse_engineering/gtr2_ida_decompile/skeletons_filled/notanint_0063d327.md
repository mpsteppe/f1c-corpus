## notanint_0063d327 — "not an integer" pow stub

**Summary:** Trivial MSVC CRT math stub: the "argument is not an integer" branch of the pow special-case checks; it does nothing itself and transfers control straight to the empty isintTOSret return point. Purely a control-flow label target.

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

**Guard conditions:** None — no conditions are tested here. The body unconditionally transfers to isintTOSret (the shared empty return point); all integer/non-integer classification has already been performed by the caller.
