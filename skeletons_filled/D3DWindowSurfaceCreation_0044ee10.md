## D3DWindowSurfaceCreation_0044ee10 — D3DWindowSurfaceCreate

**Summary:** Creates a D3D window surface: initializes a 256-byte buffer with 1s/0s, sets surface constants (two DWORDs at offsets 0xC7C/0xC80), registers via ppvOut callback with sub_44ED10, creates vertex buffer through COM interface, and configures surface properties.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** HWInput_Setup (00455c60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x4)+0x0) | 0xC | R | — | vtable entry for vertex buffer creation |
| *(*(this+0x4)+0x0) | 0x18 | R | — | vtable entry for SetSurfaceDesc |
| *(*(this+0x4)+0x0) | 0x1C | R | — | vtable entry for surface Release |
| *(*(this+0x4)+0x0) | 0x2C | R | — | vtable entry for surface Lock |
| *(*(this+0x4)+0x0) | 0x34 | R | — | vtable entry for surface Unlock |
| *(this+0x4) | 0x0 | R | — | vtable pointer of the DirectDraw surface |
| this | 0x0 | RW | — | Parent window handle (HWND) stored from a4 |
| this | 0x4 | RW | 0 | DirectDrawSurface pointer (initially NULL, set on success) |
| this | 0x24C | RW | 44 | Surface description/pitch (stored at this[147]) |
| this | 0x278 | R | — | Surface type ID field (read but not written here, 19 expected) |
| this | 0x37C | RW | 0 | D3D device struct result buffer (a4, set to 0 on success) |
| this | 0xC7C | RW | 18446744072619032576 → -0.5f | Surface constant: negated absolute value half-step |
| this | 0xC80 | RW | 18446744072598899917 → -0.1f | Surface constant: negated absolute value tenth-step |

**Written-by note (persistence):**
- this 0x0: Once, set from a4 param (HWND). External poke would break window association.
- this 0x4: Once, set on successful surface creation. External poke loses D3D surface.
- this 0x24C: Once, hardcoded 44. External poke changes surface description.
- this 0x37C: Once, set to 0 on success path. External poke breaks device state.
- this 0xC7C: Once, hardcoded -0.5f. Later modified by StoreNegatedAbsoluteValues.
- this 0xC80: Once, hardcoded -0.1f. Later modified by StoreNegatedAbsoluteValues.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0044ed10 | sub_44ED10 | R | Callback for registering collision data setup |
| 005ad3f0 | unk_5AD3F0 | R | RenderSetupDataPtr [DERIVED] |
| 005ad490 | unk_5AD490 | R | D3D_VertexBufferDesc [DERIVED] |
| 005b0e84 | unk_5B0E84 | R | VTable_44ee10 [DERIVED] |
| 007ca590 | ppvOut | R | ModulePtrArray [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | != | 1 | Passes when HWND != 1 (not a pure integer handle). If == 1, returns error -1. |
| this | 0x278 | == | 19 | Surface type must be 19 (window surface). If not, registration callback sub_44ED10 path is skipped. |

**Guard interpretation:** If *this (HWND) == 1, function returns -1 early (blocked). If this[158] (surface type at 0x278) != 19, the ppvOut registration callback path is skipped. Both checks must pass for surface creation to proceed.
