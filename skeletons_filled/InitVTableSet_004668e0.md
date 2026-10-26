## InitVTableSet_004668e0 — InitVTableSet_NetworkVTable

**Summary:** Constructor helper. Calls UIConstructorWithVTableParams(a2, a3) for base initialization, then sets vtable pointer to off_59F210 (NetworkVTable).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConstructorWithVTableAndFloatInit (00466a30), UIComponentInit2 (00479c80), ShortComputation_9db0 (00479db0), ConstructorVTableFUN004668e0 (00479e30), sub_47A000 (0047a000), ShortComputation_a190 (0047a190), sub_47A210 (0047a210), ShortComputation_a3a0 (0047a3a0), FloatValueConstructor (0047a550), FloatReturnStub (0047a580), ObjectInit_a5b0 (0047a5b0), sub_47A5E0 (0047a5e0), UIComponentInit3 (0047a620), ConstructorWithRangeInit_a800 (0047a800), ShortComputation_a8f0 (0047a8f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to off_59F210 (NetworkVTable) |

**Written-by note (persistence):**
- this 0x0: once (constructor). External poke overwrites.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059f210 | off_59F210 | R | NetworkVTable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048d3a0 | UIConstructorWithVTableParams | base UI constructor with vtable parameters |

**Guard conditions:** None — unconditional.
