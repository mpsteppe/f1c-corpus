## sub_54EED0_0054eed0 — RenderBatchTriangleInsertion

**Summary:** Inserts a 3D triangle into the scene render batch system by transforming vertex indices to world-space positions, testing each batch slot for frustum/sphere intersection, and populating the first available slot with the triangle's position, normal, and material data.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SceneBatchRenderCheck (0054f5c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1E8) | 0x0 | RW | 1 | batch slot state flag (1=free; checked against 6=occupied/disabled) |
| *(this+0x1E8) | 0x18 | R | — | camera position X (or transform component) for sphere/frustum test |
| *(this+0x1E8) | 0x28 | R | — | camera position Y (or transform component) |
| *(this+0x1E8) | 0x2C | R | — | camera position Z (or transform component) |
| *(this+0x1E8) | 0x30 | R | — | additional transform/bounds data for distance check |
| *(this+0x1E8) | 0x34 | RW | — | slot output: world-space X position of inserted vertex |
| *(this+0x1E8) | 0x38 | RW | — | slot output: world-space Y position |
| *(this+0x1E8) | 0x3C | RW | — | slot output: world-space Z position |
| *(this+0x1E8) | 0x40 | RW | — | slot output: velocity/offset X component |
| *(this+0x1E8) | 0x44 | RW | — | slot output: velocity/offset Y component |
| *(this+0x1E8) | 0x48 | RW | — | slot output: velocity/offset Z component |
| *(this+0x1E8) | 0x4C | RW | — | slot output: parent scene pointer (this) |
| *(this+0x1E8) | 0x50 | RW | — | slot output: friction/material coefficient from source |
| *(this+0x1E8) | 0x58 | RW | — | slot output: contact normal X |
| *(this+0x1E8) | 0x5C | RW | — | slot output: contact normal Y |
| *(this+0x1E8) | 0x60 | RW | — | slot output: contact normal Z |
| *(this+0x1E8) | 0x64 | RW | — | slot output: source vertex pointer back-reference |
| *(this+0x1E8) | 0x68 | RW | — | slot output: camera-relative position X |
| *(this+0x1E8) | 0x6C | RW | — | slot output: camera-relative position Y |
| *(this+0x1E8) | 0x70 | RW | — | slot output: camera-relative position Z |
| this | 0x1E0 | R | — | camera/world transform data (read for view space calc) |
| this | 0x1E4 | R | — | camera/world transform data |
| this | 0x1E8 | R | — | pointer to render batch slot array |
| this | 0x204 | R | — | batch array metadata (count or capacity) |
| this | 0x2EC | R | — | additional batch context (e.g. current frame index) |
| this | 0x2F0 | R | — | additional batch context |
| this | 0x2F4 | R | — | additional batch context |

**Written-by note (persistence):**
- *(this+0x1E8) 0x0: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x34: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x38: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x3C: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x40: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x44: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x48: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x4C: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x50: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x58: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x5C: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x60: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x64: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x68: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x6C: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x70: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 008b8f24 | dword_8B8F24 | R | D3DDeviceWrapperPtr [DERIVED] (also: ` — D3D device wrapper / scene manager singleton vtable (docs/22) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054eb40 | F_2D3DTrianglePointTest | 2D point-in-triangle test — determines if projected vertex falls within a batch slot's triangle region |
| 00559a30 | SingleFunctionCallWrapper_9a30 | post-insertion notification callback — notifies dependent systems that a batch slot was populated |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x1E8) | 0x0 | == | 6 | batch slot state — slot is occupied/disabled |

**Guard interpretation:** When slot state equals 6, the slot is occupied or disabled and is skipped (goto LABEL_18, continues to next slot). Slots with state != 6 pass the guard and are candidates for insertion. The function writes state=1 on creation and later tests against 6 to find free slots.
