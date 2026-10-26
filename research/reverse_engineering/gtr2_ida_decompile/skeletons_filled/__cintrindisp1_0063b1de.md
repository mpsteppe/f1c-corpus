## __cintrindisp1_0063b1de — CRT __cintrindisp1: integer result dispatch wrapper

**Summary:** MSVC CRT x87 helper wrapper: takes an integer conversion request on the FPU stack/registers and forwards it to _trandisp1 (transcendental/FPU dispatch), then returns via cintrinexit. Part of the __cintrindisp1 family used by the C runtime's "cintrindisp" (convert-to-int dispatch) support.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 009137d8 | dword_9137D8 | R | CRT transcendental-dispatch state/flag word consulted on the trandisp1/cintrin exit path |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00638190 | Trandisp1 [structural] | Performs the actual FPU/transcendental dispatch using the passed register arguments |
| 0063b26a | cintrinexit | Common CRT exit/epilogue for the cintrin dispatch family; returns the result |

**Guard conditions:** None — no branches in the body. Execution unconditionally calls _trandisp1 (passing edx parameter, cx parameter, stack pointer to savedregs, fpstat and the st0 double) then cintrinexit; nothing is checked or blocked.
