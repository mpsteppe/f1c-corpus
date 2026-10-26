## __CIasin_00631ad0 — x87 FPU asin entry stub

**Summary:** Internal x87 floating-point helper `_CIasin`: validates the FPU top-of-stack state for the argument passed in st(0), then jumps into the real x87 asin routine (`start_0`). Part of the compiler's x87 math library for the `asin` builtin.

**Called by:** sub_40D5D0 (0040d5d0), sub_43A2B0 (0043a2b0), sub_43BBD0 (0043bbd0), sub_44B730 (0044b730), sub_46E5D0 (0046e5d0), sub_470210 (00470210), sub_498850 (00498850), sub_4992F0 (004992f0), sub_4E4420 (004e4420), sub_56E190 (0056e190), sub_574810 (00574810), sub_614B30 (00614b30) … +4 more

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00631aed | start_0 | Real x87 asin implementation; receives the argument still on the FPU stack (via spilling its st(0) value into the local slots) |
| 00638448 | __checkTOS_withFB | Verifies the x87 top-of-stack / tag word state for the st(0) argument before the math routine consumes it |

**Guard conditions:** No explicit C-level branches. The only validation is inside `_checkTOS_withFB(x, high half)`, which checks the FPU stack state for the incoming st(0) value; if that check fails (invalid/empty TOS) the subsequent `start_0` computation is not reached with a valid operand. Otherwise the call passes through to `start_0` unconditionally.
