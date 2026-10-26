## RendererSceneNodeUpdate_004c97b0 — RendererSceneNodeUpdate

**Summary:** Scene node render update: resets field at this+0x1C, then dispatches vtable+4 on sub-object (this+0x20) with DSP transform parameter. Gated by virtual state check and race phase.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x20)+0x0) | 0x4 | R | — | VTable offset 4 method of sub-object (dispatch target) |
| *(this+0x20) | 0x0 | R | — | Sub-object pointer (dereferenced for vtable) |
| this | 0x1C | RW | 0 | State field (reset to 0 when virtual check passes) |
| this | 0x20 | R | — | Pointer to render sub-object with vtable |

**Written-by note (persistence):**
- this 0x1C: Set to 0 each call when virtual state check fails; persists between calls

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c56a8 | dword_7C56A8 | R | RacePhase [CONFIRMED] (also: ` — race phase (8 = ?) |
| 007cf2cc | flt_7CF2CC | R | DSPTransformParam [DERIVED] (also: ` — DSP transform parameter) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c9820 | VirtualStateCheckViaIndex | Returns 1 to suppress update, 0 to allow |

**Guard conditions:** Three guards: (1) VirtualStateCheckViaIndex must return 0 to enter body, else skip entirely. (2) this+0x20 must be non-null. (3) dword_7C56A8 (RacePhase) must not equal 2 to dispatch vtable+4 call.
