## VirtualDispatchConditionalAudio_0040d090 — CameraEffectReset

**Summary:** Calls virtual method at vtable+16 on a stored effect object (this+0x8), then zeros two collision geometry state fields at offsets 420 and 424 if the collision handle is non-null.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameStateDispatchChain (0040d240), sub_4A00A0 (004a00a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x8) | 0x10 | R | — | virtual method at vtable+16 on stored effect object |
| this | 0x8 | R | — | pointer to camera effect object to reset |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008afe88 | dword_8AFE88 | R | CollisionGeometryHandle [DERIVED] — fields at +420 and +424 zeroed if non-null |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** if this+0x8 is non-null, virtual method called. If dword_8AFE88 is non-null, its collision state fields at +420 and +424 are zeroed.
