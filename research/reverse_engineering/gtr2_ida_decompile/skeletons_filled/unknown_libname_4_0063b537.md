## unknown_libname_4_0063b537 — CRT x87 division emulation dispatcher (denormal operands)

**Summary:** MSVC CRT x87 support routine: decodes the low 6 bits of a trapped FPU opcode byte (AL) and dispatches all 64 Fdiv/Fdivr/Fdivp/Fdivrp encodings. Straightforward variants execute the x87 instruction inline; denormal/special operand variants spill both long-double operands to the stack, call the software divide helper unknown_libname_3, then restore the FPU stack order with the appropriate fxch st(n) rotations. Effectively the software (emulated) division path of the CRT's floating-point trap handler.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0091320e | jpt_63B53D | R | 64-entry jump table for `switch (a1 & 0x3F)` — maps each FPU opcode low-6-bit encoding to its handler block |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0063b420 | unknown_libname_3 | Software long-double divide helper; called with the two spilled TBYTE operands whenever the opcode variant requires the emulated path |

**Guard conditions:** No boolean guards — a single `switch (a1 & 0x3F)` over 64 opcode variants (mask confines AL to 0..0x3F; no default case). Cases 0/2/4 execute hardware `fdiv`/`fdivr` inline and return; cases 5/6/7 execute `fdivp`/`fdivr`/`fdivrp` inline; the higher groups (8, 0xA, 0xC, ... up to 0x3F) take the software path: operands are stored to the stack frame, unknown_libname_3 is called, and the x87 stack is rebuilt with the fxch rotation matching the operand's register position (st(1) for the earliest group, increasing to st(6)/st(7) for the last), then the function returns. Odd cases in each pair contain an `int 6` artifact from the jump-table target sharing and fall through to the following even case.
