## SceneBatchRenderCheck_0054f5c0 — BatchRenderVisibilityAndCollisionCheck

**Summary:** Checks whether a scene entity is visible and within collision distance; if so, increments an audio collision counter. Part of the scene rendering / audio collision system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** UIFocusChange (0054f7a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1E0) | 0x0 | R | — | pointer to render state/count structure |
| *(this+0x1E0) | 0x4 | R | — | maximum audio collision count threshold |
| *(this+0x204) | 0xE8 | R | — | camera/view Z position component |
| *(this+0x204) | 0xEC | R | — | camera/view Y position component |
| *(this+0x204) | 0xF0 | R | — | camera/view X position component |
| this | 0x1E0 | R | — | pointer to scene render state descriptor |
| this | 0x204 | R | — | pointer to camera/view position float array |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8f24 | dword_8B8F24 | R | D3DDeviceWrapperPtr [DERIVED] (also: ` — D3D device wrapper / scene manager singleton vtable (docs/22) |
| 008c5f40 | dword_8C5F40 | RW | AudioOutputHandle [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054b570 | sub_54B570 | prepares render batch for drawing (enables transform pipeline) |
| 0054eed0 | sub_54EEDO | collision contact detection variant for flagged entities |
| 0054f2f0 | CollisionContactDetection | standard collision contact detection between entity and scene |

**Guard conditions:** Entity flags at a2+60: if bit 1 set → return 0 (BLOCKED). Audio collision counter dword_8C5F40 >= *(*(this+0x1E0)+4) → return 1 (BLOCKED: counter saturated). Node visibility flag *(v6+20) & 0x40 == 0 → skip collision (BLOCKED). Distance check (v13 < v14*v14) AND (a3 & 1) required for collision call to proceed. PASSES: entity flag bit 1=0, counter below threshold, node visible, distance within threshold, a3 bit 0 set.
