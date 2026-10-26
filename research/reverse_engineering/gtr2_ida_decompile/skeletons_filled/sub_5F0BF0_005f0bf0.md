## sub_5F0BF0_005f0bf0 — Object teardown dispatcher

**Summary:** Teardown/destructor helper: depending on mode bit this+0x10 bit0 it calls one of two cleanup routines with the matching sub-object pointer (this+0xB0 when set, this+0xAC when clear), then always runs the refcounted resource release helper sub_5F0620. Part of the object shutdown path.

**Called by:** sub_5F0DA0 (005f0da0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | Mode flags; bit0 selects which cleanup routine and which sub-object pointer is used |
| this | 0xAC | R | — | Sub-object pointer passed when bit0 is clear |
| this | 0xB0 | R | — | Sub-object pointer passed when bit0 is set |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005e4bf0 | sub_5E4BF0 | Cleanup routine run when this+0x10 bit0 is set — called with the object and the pointer from this+0xB0 |
| 005e7f70 | sub_5E7F70 | Cleanup routine run when this+0x10 bit0 is clear — called with the object and the pointer from this+0xAC |
| 005f0620 | sub_5F0620 | Refcounted resource release helper — always invoked afterwards to decrement/release the held resource |

**Guard conditions:** `(*(this+16) & 1) != 0`: if bit0 of this+0x10 is SET, sub_5E4BF0 is called with *(this+0xB0); if clear, sub_5E7F70 is called with *(this+0xAC). sub_5F0620 runs unconditionally after whichever branch was taken. No early-outs; the function always returns 0.
