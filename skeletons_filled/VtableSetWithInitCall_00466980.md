## VtableSetWithInitCall_00466980 — InitVTableSet_WithDifferentVTable

**Summary:** Constructor helper. Calls UIConstructorWithVTableParams(this, a2, a3) for base initialization, then sets vtable pointer to off_59F2C8.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIComponentInit (00479730), InitWithFloatConstants (00479760), ConstructorWithRangeInitAndVTable (00479790), ShortComputation_97c0 (004797c0), ShortComputation_97f0 (004797f0), ConstructorVTableFUN00466980 (00479820), FloatConstructorWithRangeSetup (00479850), VtableSetWithRangeCall (00479880), ConstructorWithRangeInit (004798b0), VTableSetterWithFloatParams (004798e0), sub_479910 (00479910), ShortComputation_9940 (00479940), FunctionCallWrapper_9970 (00479970), ObjectConstructorWithFloatParams (004799a0), InitWithVTable (004799e0), ShortComputation_9a10 (00479a10), FloatRangeConstructor (00479a40), UISliderConstructor_9bd0 (00479bd0), ObjectInit_9c00 (00479c00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to off_59F2C8 |

**Written-by note (persistence):**
- this 0x0: once (constructor). External poke overwrites.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059f2c8 | off_59F2C8 | R | alternate UI vtable pointer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048d3a0 | UIConstructorWithVTableParams | base UI constructor with vtable parameters |

**Guard conditions:** None — unconditional.
