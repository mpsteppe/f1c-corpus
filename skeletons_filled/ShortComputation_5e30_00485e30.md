## ShortComputation_5e30_00485e30 — UIComponentInitWithZeroSentinelPairs

**Summary:** Initializes a UI-like component: sets vtable pointer, zeros numerous fields, initializes five (min=0, max=-1) sentinel-guarded range pairs, then runs a final setup sub-routine.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_47A9E0 (0047a9e0), ConstructorWithByteParams (00487220), UIObjectInitWithByteParams (00487660), InitWithVTableFlags (00487ed0), UITextDisplayConstructor (00488180), ConstructorInitVTable (00488b00), VTableSetWithFlag (00488f90), sub_4893C0 (004893c0), ConstructorWithStringCopy (0048b420), UIConstructorWithVTableParams (0048d3a0), Constructor_e070 (0048e070), UIStructInit (0048e600), LargeConstructor (0048eaa0), ShortComputation_fb70 (0048fb70), UIComponentInit5 (0048fe60), ObjectInitWithFieldZeroing_0250 (00490250), sub_493FC0 (00493fc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (set to off_5AB8C0) |
| this | 0x44 | RW | 0 | zero-initialized general-purpose field |
| this | 0x48 | RW | 0 | zero-initialized general-purpose field |
| this | 0x4C | RW | 0 | zero-initialized general-purpose field |
| this | 0x50 | RW | 0 | zero-initialized general-purpose field |
| this | 0x54 | RW | 0 | zero-initialized general-purpose field |
| this | 0x58 | RW | 0 | zero-initialized general-purpose field |
| this | 0x5C | RW | 0 | zero-initialized general-purpose field |
| this | 0x60 | RW | 0 | zero-initialized general-purpose field |
| this | 0x70 | RW | 0 | zero-initialized general-purpose field |
| this | 0x74 | RW | 0 | zero-initialized general-purpose field |
| this | 0x78 | RW | 0 | zero-initialized general-purpose field |
| this | 0x7C | RW | 0 | zero-initialized general-purpose field |
| this | 0xA0 | RW | 0 | zero-initialized general-purpose field |
| this | 0xA4 | RW | 18446744073709551615 | max/end sentinel of range pair 1 |
| this | 0xA8 | RW | 0 | min/start sentinel of range pair 1 |
| this | 0xAC | RW | 18446744073709551615 | max/end sentinel of range pair 2 |
| this | 0xB0 | RW | 0 | min/start sentinel of range pair 2 |
| this | 0xB4 | RW | 18446744073709551615 | max/end sentinel of range pair 3 |
| this | 0xB8 | RW | 0 | min/start sentinel of range pair 3 |
| this | 0xBC | RW | 18446744073709551615 | max/end sentinel of range pair 4 |
| this | 0xC0 | RW | 0 | min/start sentinel of range pair 4 |
| this | 0xC4 | RW | 18446744073709551615 | max/end sentinel of range pair 5 |

**Written-by note (persistence):**
- this 0x0: one-time init; external vtable poke would survive but is atypical
- this 0x44: one-time zero init; external writes survive
- this 0x48: one-time zero init; external writes survive
- this 0x4C: one-time zero init; external writes survive
- this 0x50: one-time zero init; external writes survive
- this 0x54: one-time zero init; external writes survive
- this 0x58: one-time zero init; external writes survive
- this 0x5C: one-time zero init; external writes survive
- this 0x60: one-time zero init; external writes survive
- this 0x70: one-time zero init; external writes survive
- this 0x74: one-time zero init; external writes survive
- this 0x78: one-time zero init; external writes survive
- this 0x7C: one-time zero init; external writes survive
- this 0xA0: one-time zero init; external writes survive
- this 0xA4: one-time sentinel init; external writes survive
- this 0xA8: one-time sentinel init; external writes survive
- this 0xAC: one-time sentinel init; external writes survive
- this 0xB0: one-time sentinel init; external writes survive
- this 0xB4: one-time sentinel init; external writes survive
- this 0xB8: one-time sentinel init; external writes survive
- this 0xBC: one-time sentinel init; external writes survive
- this 0xC0: one-time sentinel init; external writes survive
- this 0xC4: one-time sentinel init; external writes survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ab8c0 | off_5AB8C0 | R | VTable_5AB8C0 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486010 | sub_486010 | final init / post-field-setup routine for the component |
| 0049a930 | ConstructorWith1Sentinels | base-class constructor that sets up initial sentinel values |

**Guard conditions:** unconditional — no branches. All field writes and function calls execute every invocation.
