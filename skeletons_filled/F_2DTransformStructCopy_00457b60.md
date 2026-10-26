## F_2DTransformStructCopy_00457b60 — 2D Transform / Viewport Struct Copy

**Summary:** Copies a source 2D transform/viewport structure (position, scale, rotation, clip rectangle, string data) into a destination struct field-by-field using multiple getter subroutines. Handles null-safe string copy with buffer reallocation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StaticCameraSceneLoader (0040b030)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x30 | RW | — | 3-vector position X (copied from source via F_3VectorCopyToStruct) |
| this | 0x34 | RW | — | 3-vector position Y |
| this | 0x38 | RW | — | 3-vector position Z |
| this | 0x3C | RW | — | 3-vector field: rotation or direction X (from VectorCopy at source+144) |
| this | 0x40 | RW | — | 3-vector field: rotation or direction Y |
| this | 0x44 | RW | — | 3-vector field: rotation or direction Z |
| this | 0x48 | RW | — | pair field from source+0x30: viewport/screen dimension X |
| this | 0x4C | RW | — | pair field from source+0x34: viewport/screen dimension Y |
| this | 0x50 | RW | — | pair field from source+0x38: scale or anchor X |
| this | 0x54 | RW | — | pair field from source+0x3C: scale or anchor Y |
| this | 0x58 | RW | — | pair field from source+0x40: offset or clip X |
| this | 0x5C | RW | — | pair field from source+0x44: offset or clip Y |
| this | 0x60 | RW | — | direct field copy from source+0x48 (single float) |
| this | 0x64 | RW | — | pair field from source+0x4C: transform parameter A |
| this | 0x68 | RW | — | pair field from source+0x50: transform parameter B |
| this | 0x6C | RW | — | pair field from source+0x54: viewport rect X |
| this | 0x70 | RW | — | pair field from source+0x58: viewport rect Y |
| this | 0x74 | RW | — | direct field copy from source+0x5C (single float) |
| this | 0x78 | RW | — | byte field copy from source+0x60 (single byte: flag/enum) |
| this | 0x7C | RW | — | multi-field getter result: float A |
| this | 0x80 | RW | — | multi-field getter result: float B |
| this | 0x84 | RW | — | multi-field getter result: int C |
| this | 0x88 | RW | — | direct copy from source+0x70 |
| this | 0x8C | RW | — | direct copy from source+0x74 |
| this | 0x90 | RW | — | direct copy from source+0x78 |
| this | 0x94 | RW | — | direct copy from source+0x7C |
| this | 0x98 | RW | — | direct copy from source+0x80 |

**Written-by note (persistence):**
- this 0x30: written once during struct copy — external poke does NOT survive (overwritten on next copy call)
- this 0x34: written once during struct copy — external poke does NOT survive
- this 0x38: written once during struct copy — external poke does NOT survive
- this 0x3C: written once during struct copy — external poke does NOT survive
- this 0x40: written once during struct copy — external poke does NOT survive
- this 0x44: written once during struct copy — external poke does NOT survive
- this 0x48: written once during struct copy — external poke does NOT survive
- this 0x4C: written once during struct copy — external poke does NOT survive
- this 0x50: written once during struct copy — external poke does NOT survive
- this 0x54: written once during struct copy — external poke does NOT survive
- this 0x58: written once during struct copy — external poke does NOT survive
- this 0x5C: written once during struct copy — external poke does NOT survive
- this 0x60: written once during struct copy — external poke does NOT survive
- this 0x64: written once during struct copy — external poke does NOT survive
- this 0x68: written once during struct copy — external poke does NOT survive
- this 0x6C: written once during struct copy — external poke does NOT survive
- this 0x70: written once during struct copy — external poke does NOT survive
- this 0x74: written once during struct copy — external poke does NOT survive
- this 0x78: written once during struct copy — external poke does NOT survive
- this 0x7C: written once during struct copy — external poke does NOT survive
- this 0x80: written once during struct copy — external poke does NOT survive
- this 0x84: written once during struct copy — external poke does NOT survive
- this 0x88: written once during struct copy — external poke does NOT survive
- this 0x8C: written once during struct copy — external poke does NOT survive
- this 0x90: written once during struct copy — external poke does NOT survive
- this 0x94: written once during struct copy — external poke does NOT survive
- this 0x98: written once during struct copy — external poke does NOT survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00415c30 | NullSafePointerDereference | dereferences pointer safely, returns null on failure (used for string field access) |
| 00456040 | DoubleFieldGetterAt0x300x34 | reads two float fields from source at offsets 0x30 and 0x34 |
| 00456060 | DualFieldGetter | reads two float fields from source at offsets 0x38 and 0x3C |
| 00456080 | ShortComputation_6080 | reads two float fields from source at offsets 0x40 and 0x44 |
| 004560a0 | DualFieldGetter_60a0 | reads two float fields from source at offsets 0x4C and 0x50 |
| 004560c0 | RectViewportDimensionGetter | reads two float viewport rect fields from source at offsets 0x54 and 0x58 |
| 004560e0 | MultiFieldGetter | reads three fields (two floats, one int) from source |
| 00456110 | F_3VectorCopyToStruct | copies a 3-float vector (position) from source+12 to destination |
| 00456130 | VectorCopy | copies a 3-float vector (direction/rotation) from source+144 to destination |
| 00566650 | StringCopyWithBufferRealloc | copies string with buffer reallocation (handles null-safe string dup) |

**Guard conditions:** No early-return guard conditions — the function always performs the full copy. The NullSafePointerDereference at source+4 provides null safety for the string field.