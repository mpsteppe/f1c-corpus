## sub_664CBF_00664cbf — Bulk/elementwise VM math executor

**Summary:** Bulk evaluator for a builtin VM math function over arrays of register ids: first detects whether a3 is constant (all ids equal), then either materializes the ids straight into the outputs (state bit 0x200), evaluates one angle-wrapped value and broadcasts it to both output arrays (state bit 0x100), or carves a scratch block into 27 lane buffers and runs a chained polynomial/phase computation through sub_6641F3, copying the result lanes into a4/a5. Returns 0 or a negative error (0x8007000E when allocation fails).

**Called by:** sub_66963D (0066963d)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | VM state pointer (this[2]); allocator handles and flag byte live off it |
| this | 0x20 | R | — | temp/tag word (this[8]) stored into the per-lane buffer v98 (constant lane operand) |
| this | 0x74 | R | — | state flag byte (state+108, flattened): bit 0x200 selects the simple materialize path, bit 0x100 (with all-equal ids) selects the broadcast path |
| this | 0x80 | R | — | state allocator handle (state+120) used by sub_681AAA to create the constant number objects (1/(2π), 0.25, 0.5, 2π, -π, polynomial coefficients) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f2358 | dbl_6F2358 | R | read-only double constant operand of the elementwise/angle math evaluation |
| 006f2378 | dbl_6F2378 | R | read-only double constant operand of the elementwise/angle math evaluation |
| 006f5c60 | dbl_6F5C60 | R | read-only double constant operand of the elementwise/angle math evaluation |
| 0073a990 | dbl_73A990 | R | read-only double constant operand of the elementwise/angle math evaluation |
| 0073a998 | dbl_73A998 | R | read-only double constant operand of the elementwise/angle math evaluation |
| 0073aa20 | dbl_73AA20 | R | read-only double constant operand of the elementwise/angle math evaluation |
| 0073aa28 | dbl_73AA28 | R | read-only double constant operand of the elementwise/angle math evaluation |
| 0073aa30 | dbl_73AA30 | R | read-only double constant operand of the elementwise/angle math evaluation |
| 0073aa38 | dbl_73AA38 | R | read-only double constant operand of the elementwise/angle math evaluation |
| 0073aa40 | dbl_73AA40 | R | read-only double constant operand of the elementwise/angle math evaluation |
| 0073aa48 | dbl_73AA48 | R | read-only double constant operand of the elementwise/angle math evaluation |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00630739 | ??2@YAPAXI@Z | MSVC operator new: allocate the 108-bytes-by-lane scratch block carved into 27 lane buffers |
| 006308d3 | j__free | free the scratch block on exit (LABEL_67) |
| 006624cc | sub_6624CC | initialize the first 15 lane buffers; a negative result aborts the lane path |
| 00662830 | sub_662830 | materialize the value of *a3 into the double pair v47 in the all-equal path |
| 006641f3 | sub_6641F3 | execute the chained VM sub-operations implementing the per-lane math |
| 00681aaa | sub_681AAA | create the constant number objects in the VM state (0.25, 0.5, 2π, -π, 1/(2π), polynomial coefficients) |

**Guard conditions:** v109 = "a3 is constant" (all a6 entries equal a3[0]; a6 <= 1 counts as constant). Dispatch on state byte 0x74 (state+108): bit 0x200 set → direct materialize path (opcodes 0x10800000/0x10900000 per output, a4 path first, then a5 only if present, skipping a4 when null); else bit 0x100 set and v109 true → single-value wrap in [-π, π] then broadcast via 0x50300004 into both outputs with memset32; otherwise → general lane path (requires the 108×lanes allocation; NULL → return 0x8007000E). Any failing sub_6641F3 call propagates its negative code after freeing Block; object lookups that fail return negative codes as well.
