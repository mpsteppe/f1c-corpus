## DirectXTextureSurfaceFactoryDispatchingFourCCCod_0050b8a9 — FourCC-based texture/surface format factory dispatcher

**Summary:** Reads a FourCC format code from input data and dispatches to the appropriate Direct3D texture/surface object constructor via a large switch/if-else chain, allocating memory and invoking post-construction virtual init. Part of the D3D rendering pipeline initialization.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** D3DContextInit (005063a5)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x8) | 0x4 | R | — | FourCC format code (DWORD) read from input data structure to select constructor |
| this | 0x8 | RW | — | output pointer slot: receives the newly allocated/constructed render object (or NULL on failure) |

**Written-by note (persistence):**
- this 0x8: once (factory call); external poke survives (caller receives the constructed object pointer)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0050bfc9 | jpt_50B8EB | R | jump table for FourCC dispatch (indirect branch targets for the switch cases) |
| 0059c71a | loc_59C71A | R | code location referenced by the FourCC dispatch logic |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0050a7c5 | ObjectConstructorWithSizeCountInit | constructs format object type for FourCC=20 (size+count init variant) |
| 0050a8d9 | RenderFormatConstructor | constructs render format object for FourCC=21 |
| 0050a8f5 | VTableSetterWithSubInit | constructs object for FourCC=22 (vtable set + sub-init) |
| 0050a911 | sub_50A911 | constructs object for FourCC=23 |
| 0050ab19 | ShortComputation_ab19 | constructs object for FourCC=24 |
| 0050ab35 | sub_50AB35 | constructs object for FourCC=25 |
| 0050ae22 | ConstructorWithVTableSubInit | constructs object for FourCC=26 (vtable + sub-init variant) |
| 0050ae3e | InitWithClass8 | constructs object for FourCC=27 (class-8 init) |
| 0050ae5a | Constructor_ae5a | constructs object for FourCC=28 |
| 0050ae76 | ConstructorSize0x10 | constructs object for FourCC=29 (0x10-sized object) |
| 0050ae92 | RenderObjectConstructor | constructs render object for FourCC=30 |
| 0050af3b | ObjectInitWithVTable_af3b | constructs object for FourCC=31 (vtable-init variant) |
| 0050afc6 | sub_50AFC6 | constructs object for FourCC=34 |
| 0050b1d4 | InitVTableSet_b1d4 | constructs object for FourCC=40 (vtable-set init) |
| 0050b1f0 | ObjectInit_b1f0 | constructs object for FourCC=41 |
| 0050b20c | ConstructorWithInit | constructs object for FourCC=50 |
| 0050b228 | ShortComputation_b228 | constructs object for FourCC=51 |
| 0050b260 | sub_50B260 | constructs object for FourCC=52 |
| 0050b37d | ObjectConstructor_b37d | constructs object for FourCC=60 |
| 0050b399 | RenderObjectConstructor_b399 | constructs object for FourCC=61 |
| 0050b3b5 | RenderFormatConstructor2 | constructs object for FourCC=62 |
| 0050b3d1 | VTableSetterWithSubInit_b3d1 | constructs object for FourCC=63 |
| 0050b3ed | sub_50B3ED | constructs object for FourCC=64 |
| 0050b409 | ShortComputation_b409 | constructs object for FourCC=65 |
| 0050b42a | sub_50B42A | constructs object for FourCC=67 |
| 0050b446 | ConstructorWithVTableSubInit_b446 | constructs object for FourCC=69 |
| 0050b462 | InitWithClass0x10 | constructs object for FourCC=909200416 |
| 0050b727 | Constructor_b727 | constructs object for FourCC=909200449 |
| 0050b743 | ConstructorSize0x30 | constructs object for FourCC=909201952 |
| 0050b77b | ObjectInitWithVTable_b77b | constructs object for FourCC=909201985 |
| 0050b797 | sub_50B797 | constructs object for FourCC=827611204 |
| 0050b7cb | ObjectInit_b7cb | constructs object for FourCC=844388420 |
| 0050b7e3 | ConstructorWithInit_b7e3 | constructs object for FourCC=861165636 |
| 0050b7fb | ShortComputation_b7fb | constructs object for FourCC=877942852 |
| 0050b813 | ShortComputation_b813 | constructs object for FourCC=894720068 |
| 0050b879 | ObjectConstructorWithSingleInit | constructs object for FourCC=909202018 |
| 0050b891 | RenderObjectConstructor_b891 | constructs object for FourCC=844715353 |
| 00587c03 | OperatorNewNhMallocWrapper | heap allocation wrapper (operator new) for each format object |
| 0058a5d8 | SEHHandlerInit | initializes structured exception handling for the function scope |

**Guard conditions:** The FourCC format code `*(*(this+0x8)+0x4)` acts as the primary dispatch guard:
- If the value matches a known FourCC case (20-34, 40-69, or specific large constants like 827611204, 844388420, etc.), the corresponding constructor is invoked.
- If the value does not match any known case, the function returns NULL (unrecognized texture/surface format).
- Post-construction guard at LABEL_105: if the constructed object is non-null AND its field at offset 0x4 is non-null, a virtual method call `(*vtable+12)(this)` is invoked for post-init. If either condition fails, the object is returned without the virtual call.
