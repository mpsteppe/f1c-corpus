## DirectXVertexBufferTextureCoordinateSetup_005416a0 — Setup texture coordinates in DX vertex buffer

**Summary:** Computes scaled texture coordinate values from a descriptor struct (a2) and calls vtable functions to configure a DirectX vertex buffer with those coordinates. Returns -1 on failure, 0 on success.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** BitFlagSetterWithDXUpdate (0055d2f0), sub_55D320 (0055d320), UIPropertyValueSetter (0055d410), sub_55D460 (0055d460), SetUIPropertyGroupWithChainUpdate (0055d4f0), StateFieldSetterWithGlobalDirtyFlag (0055d530)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1100) | 0xB0 | R | — | vtable offset 176 (0xB0) — main vertex buffer setup method |
| *(this+0x1100) | 0xB8 | R | — | vtable offset 184 (0xB8) — secondary update (bit 0 flag) |
| this | 0x0 | RW | — | stores result of vtable call(s) |
| this | 0x1100 | R | — | pointer to vtable-bearing DX object |
| this | 0x13D8 | R | — | guard flag; must be non-zero to proceed |

**Written-by note (persistence):**
- this 0x0: written on successful vtable dispatch; overwritten each invocation.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** this[0x13D8] (guard flag) must be non‑zero AND a4 must NOT equal 1. If either condition fails, function returns 0 immediately — texture coordinate update skipped.
