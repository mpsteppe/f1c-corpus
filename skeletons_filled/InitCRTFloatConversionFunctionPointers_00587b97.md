## InitCRTFloatConversionFunctionPointers_00587b97 — Populate CRT float conversion vtable

**Summary:** Initializes six global function pointer entries (off_5E6730–off_5E6744) with CRT float conversion/dispatch routines (sub_58BD29, CfltcvtCRTFloatConversionDispatch, sub_58BD8F, sub_58BCCF, sub_58BD77). Returns CfltcvtCRTFloatConversionDispatch.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** InitWrapperCalling3Subroutines (00587b7f)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0058bccf | sub_58BCCF | R | Float conversion routine; stored in off_5E673C |
| 0058bd29 | sub_58BD29 | R | Float conversion routine; stored in off_5E6734 |
| 0058bd77 | sub_58BD77 | R | Float conversion routine; stored in off_5E6740 |
| 0058bd8f | sub_58BD8F | R | Float conversion routine; stored in off_5E6738 |
| 0058c07f | CfltcvtCRTFloatConversionDispatch | R | Main float conversion dispatch; stored in off_5E6730 and off_5E6744; also returned |
| 005e6730 | off_5E6730 | W | CRT function table entry 0 |
| 005e6734 | off_5E6734 | W | Float conversion vtable entry 0 |
| 005e6738 | off_5E6738 | W | CRT fassign function pointer |
| 005e673c | off_5E673C | W | CRT float convert function pointer |
| 005e6740 | off_5E6740 | W | CRT cvt function table entry 0 |
| 005e6744 | off_5E6744 | W | CRT function pointer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional initialization of all six pointers.
