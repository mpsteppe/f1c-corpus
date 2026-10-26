## ctranexit_0063b263 — CRT _ctranexit: clear transcendental-in-progress flag

**Summary:** MSVC CRT x87 transcendental helper exit path: clears bit 0 of the flag byte at [ebp-0x2C8] in the trandisp frame (the "transcendental op in progress" marker set during _ctrandisp handling), then returns through the shared cintrin exit helper. Called by __ctrandisp2 and __ctrandisp1 when their FPU work is finished.

**Called by:** __ctrandisp2 (0063b21b), __ctrandisp1 (0063b3b1)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — no conditional checks. The body unconditionally clears bit 0 (`&= ~1`) of the byte at ebp-712 (0x2C8), then tail-calls cintrinexit() to return the pending result.
