## ObjectConstructorWithAllocationAndSubInit_00553980 — ObjectConstructorWithAllocationAndSubInit

**Summary:** Allocates 36-byte object via OperatorNew, zero-initializes it, then conditionally sets sub-fields through multiple setters. Returns allocated object pointer via output parameter a1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_494690 (00494690), F_2DRectangleRender (0049ea10), FloatComputation_eb40 (0049eb40), sub_4D8CF0 (004d8cf0), sub_4DCBA0 (004dcba0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Object state/flags set by initializers |

**Written-by note (persistence):**
- this 0x0: Initialized by callees; standard heap object, survives until freed

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b78a0 | dword_8B78A0 | R | SoundManager [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005532a0 | ObjectAllocationWithZeroInit | Zero-initializes the allocated object memory |
| 00553370 | sub_553370 | Conditional sub-object field setter (when a2 != 0) |
| 00553620 | SetterWrites0x10Returns0 | Writes value a3 to field at offset 0x10 (when a3 != 0) |
| 00553630 | TwoFieldSetter_3630 | Sets two fields from a4, a5 unconditionally |
| 0055c2a0 | sub_55C2A0 | Post-init hook / finalization for the allocated object |
| 00587c03 | OperatorNewNhMallocWrapper | Heap allocation of 36 bytes |

**Guard conditions:** OperatorNew may fail (returns nullptr) — then v6 is 0 and all subsequent setters operate on null, which would crash. Callers should ensure a2/a3 non-null checks pass through conditionally.
