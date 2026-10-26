## sub_665ADF_00665adf — Elementwise atan/atan2 evaluator (bulk lanes)

**Summary:** Bulk evaluator for the builtin arctangent function over arrays of register ids: when state mode byte 0x75 has bit 2 set it dispatches the native VM ops 0x20600000 (two-operand/atan2 form when a4 is given) or 0x10C00000 (single-operand atan) into output a5, otherwise it runs an explicit polynomial implementation (classic atan series coefficients 0.999866, -0.3302995, 0.180141, -0.085133, 0.0208351 with -2, π/2, -π) across 48 scratch lane buffers chained through sub_6641F3. Returns 0 or a negative error (0x8007000E on allocation failure).

**Called by:** sub_66963D (0066963d)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | VM state pointer (this[2]); allocator handle and mode byte live off it |
| this | 0x20 | R | — | temp/tag word (this[8]) written into lane buffer v82; serves as the fallback second input when a4 is null |
| this | 0x75 | R | — | state mode byte (state+109, flattened): bit 1 (value 2) set selects the native ops (0x20600000/0x10C00000); clear selects the polynomial path |
| this | 0x80 | R | — | state allocator handle (state+120) used by sub_681AAA to create the atan polynomial constant objects |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f4ba8 | dbl_6F4BA8 | R | read-only double constant operand of the atan evaluation (polynomial coefficient or -2/±π constant) |
| 00714750 | dbl_714750 | R | read-only double constant operand of the atan evaluation (polynomial coefficient or -2/±π constant) |
| 0073a998 | dbl_73A998 | R | read-only double constant operand of the atan evaluation (polynomial coefficient or -2/±π constant) |
| 0073aa70 | dbl_73AA70 | R | read-only double constant operand of the atan evaluation (polynomial coefficient or -2/±π constant) |
| 0073aa78 | dbl_73AA78 | R | read-only double constant operand of the atan evaluation (polynomial coefficient or -2/±π constant) |
| 0073aa80 | dbl_73AA80 | R | read-only double constant operand of the atan evaluation (polynomial coefficient or -2/±π constant) |
| 0073aa88 | dbl_73AA88 | R | read-only double constant operand of the atan evaluation (polynomial coefficient or -2/±π constant) |
| 0073aa90 | dbl_73AA90 | R | read-only double constant operand of the atan evaluation (polynomial coefficient or -2/±π constant) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00630739 | ??2@YAPAXI@Z | MSVC operator new: allocate the 192-bytes-by-lane scratch block carved into 48 lane buffers |
| 006308d3 | j__free | free the scratch block before returning |
| 006624cc | sub_6624CC | initialize the first 39 lane buffers; a negative result aborts |
| 006641f3 | sub_6641F3 | execute the chained sub-operations of the atan/atan2 evaluation (and the final store into a5) |
| 00681aaa | sub_681AAA | create the constant number objects in the VM state (atan coefficients, -2, π/2, -π) |

**Guard conditions:** Dispatch on state byte 0x75 (state+109) bit 2: set → native path — if a4 != 0 use opcode count|0x20600000 with the 64-bit operand {a4, 0} into a5, else opcode count|0x10C00000 with operand 0 into a5 (a3 always the input). Clear → polynomial path: scratch = 192 × count bytes, NULL → 0x8007000E; if a4 is null it is replaced by lane buffer v82 (this[8] constant); any sub_6624CC or sub_6641F3 failure aborts the chain and is returned as-is; success at the end of either path is normalized to 0.
