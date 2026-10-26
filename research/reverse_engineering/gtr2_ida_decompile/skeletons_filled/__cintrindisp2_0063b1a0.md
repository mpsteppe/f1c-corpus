## __cintrindisp2_0063b1a0 — Intrinsic dispatch entry #2 (x87 emulation path)

**Summary:** Borland-style runtime intrinsic dispatcher: forwards the incoming x87 state and two double operands to _trandisp2, then exits through cintrinexit; used when a binary floating-point intrinsic (8-byte operands) must be emulated/dispatched.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 009137d8 | dword_9137D8 | R | unknown — not visible in the decompiled body (referenced from the IDB as runtime dispatch state touched on this path) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006381f7 | __trandisp2 | Transcendental/binary-intrinsic dispatcher: receives the operand from edx, a pointer to the saved-register area, the FPU status word, and the two stack doubles (st1, st0) |
| 0063b26a | cintrinexit | Shared exit stub for the intrinsic path; invoked immediately after _trandisp2 returns |

**Guard conditions:** None — straight-line code: _trandisp2 is called unconditionally with the incoming operands, then cintrinexit runs and its return value is returned. No values are tested and no path is blocked.
