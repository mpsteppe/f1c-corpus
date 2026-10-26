## MeshBoundingBoxComputation_0054d9f0 — Mesh Bounding Box Computation

**Summary:** Computes axis-aligned bounding box (min/max XYZ) and bounding sphere radius for a mesh by iterating vertex data through D3D transform pipeline. Stores 8 corner positions, 3 center points, and the bounding sphere radius in the mesh node struct.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneNodeStateUpdateWithTransform (005569f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x144)+0xC) | 0x11C | R | — | animation/blend vertex data pointer (vertex count and vertex array) |
| *(this+0x13C) | 0x4 | RW | — | mesh node flags (bit 16 = 0x10000, set to mark node as processed) |
| *(this+0x13C) | 0x18 | R | — | mesh vertex stride / format info (offset for D3D vertex buffer access) |
| *(this+0x13C) | 0x24 | R | — | mesh vertex buffer pointer (D3D vertex buffer for rendering) |
| *(this+0x144) | 0x0 | R | — | animation mode (0/1/2: 0=static, 1=forward, 2=reverse animation) |
| *(this+0x144) | 0x4 | R | — | animation duration / total time (float, used for progress calc) |
| *(this+0x144) | 0x8 | RW | 0 | animation progress clock (float, clamped to [0, duration]) |
| *(this+0x144) | 0xC | R | — | animation data pointer (contains vertex offset/blend data) |
| this | 0x14 | RW | — | bounding box corner 0 X (BBox[0].x, min X) |
| this | 0x18 | RW | — | bounding box corner 0 Y (BBox[0].y, min Y), also bounding sphere radius (written last) |
| this | 0x1C | RW | — | bounding box corner 0 Z (BBox[0].z, min Z) |
| this | 0x20 | RW | — | bounding box corner 1 X |
| this | 0x24 | RW | — | bounding box corner 1 Y |
| this | 0x28 | RW | — | bounding box corner 1 Z (max X) |
| this | 0x2C | RW | — | bounding box corner 2 X |
| this | 0x30 | RW | — | bounding box corner 2 Y (min Y after init) |
| this | 0x34 | RW | — | bounding box corner 2 Z |
| this | 0x38 | RW | — | bounding box corner 3 X |
| this | 0x3C | RW | — | bounding box corner 3 Y |
| this | 0x40 | RW | — | bounding box corner 3 Z (max Y) |
| this | 0x44 | RW | — | bounding box corner 4 X |
| this | 0x48 | RW | — | bounding box corner 4 Y |
| this | 0x4C | RW | — | bounding box corner 4 Z |
| this | 0x50 | RW | — | bounding box corner 5 X |
| this | 0x54 | RW | — | bounding box corner 5 Y |
| this | 0x58 | RW | — | bounding box corner 5 Z (max Z) |
| this | 0x5C | RW | — | bounding box corner 6 X |
| this | 0x60 | RW | — | bounding box corner 6 Y |
| this | 0x64 | RW | — | bounding box corner 6 Z |
| this | 0x68 | RW | — | bounding box corner 7 X |
| this | 0x6C | RW | — | bounding box corner 7 Y |
| this | 0x70 | RW | — | bounding box corner 7 Z |
| this | 0x74 | RW | — | (padding/alignment after 8 corners) |
| this | 0x78 | RW | — | (padding/alignment after 8 corners) |
| this | 0xDC | RW | — | bounding box center X = (minX + maxX) * 0.5 |
| this | 0xE0 | RW | — | bounding box center Y = (minY + maxY) * 0.5 |
| this | 0xE4 | RW | — | bounding box center Z = (minZ + maxZ) * 0.5 |
| this | 0x118 | R | — | vertex count (number of vertices to process, > 0 guard) |
| this | 0x11C | R | — | vertex data pointer (array of vertex descriptors) |
| this | 0x13C | R | — | mesh data pointer (LOD/mesh node with vertex buffer refs) |
| this | 0x144 | R | — | animation/transform data pointer (controls vertex morph/blend) |

**Written-by note (persistence):**
- *(this+0x13C) 0x4: recomputed when mesh is updated — external poke persists until next recomputation
- *(this+0x144) 0x8: recomputed when animation advances — external poke persists until next recomputation
- this 0x14: recomputed when mesh is updated — external poke persists until next recomputation
- this 0x18: recomputed when mesh is updated — external poke persists until next recomputation
- this 0x1C: recomputed when mesh is updated — external poke persists until next recomputation
- this 0x20: recomputed when mesh is updated — external poke persists until next recomputation
- this 0x24: recomputed when mesh is updated — external poke persists until next recomputation
- this 0x28: recomputed when mesh is updated — external poke persists until next recomputation
- this 0x2C: recomputed when mesh is updated — external poke persists until next recomputation
- this 0x30: recomputed when mesh is updated — external poke persists until next recomputation
- this 0x34: recomputed when mesh is updated — external poke persists until next recomputation
- this 0x38: recomputed when mesh is updated — external poke persists until next recomputation
- this 0x3C: recomputed when mesh is updated — external poke persists until next recomputation
- this 0x40: recomputed when mesh is updated — external poke persists until next recomputation
- this 0x44: recomputed when mesh is updated — external poke persists until next recomputation
- this 0x48: recomputed when mesh is updated — external poke persists until next recomputation
- this 0x4C: recomputed when mesh is updated — external poke persists until next recomputation
- this 0x50: recomputed when mesh is updated — external poke persists until next recomputation
- this 0x54: recomputed when mesh is updated — external poke persists until next recomputation
- this 0x58: recomputed when mesh is updated — external poke persists until next recomputation
- this 0x5C: recomputed when mesh is updated — external poke persists until next recomputation
- this 0x60: recomputed when mesh is updated — external poke persists until next recomputation
- this 0x64: recomputed when mesh is updated — external poke persists until next recomputation
- this 0x68: recomputed when mesh is updated — external poke persists until next recomputation
- this 0x6C: recomputed when mesh is updated — external poke persists until next recomputation
- this 0x70: recomputed when mesh is updated — external poke persists until next recomputation
- this 0x74: recomputed when mesh is updated — external poke persists until next recomputation
- this 0x78: recomputed when mesh is updated — external poke persists until next recomputation
- this 0xDC: recomputed when mesh is updated — external poke persists until next recomputation
- this 0xE0: recomputed when mesh is updated — external poke persists until next recomputation
- this 0xE4: recomputed when mesh is updated — external poke persists until next recomputation

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 00800000 | unk_800000 | R | MMXFlag [DERIVED] |
| 008b8f24 | dword_8B8F24 | R | D3DDeviceWrapperPtr [DERIVED] (also: ` — D3D device wrapper / scene manager singleton vtable (docs/22) |
| 008b8f28 | dword_8B8F28 | R | UIRootContextPtr [DERIVED] (also: ` — unknown context/state pointer) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054e0e0 | SingleCallWrapper_e0e0 | wraps a single D3D transform/vertex processing call (begin batch) |
| 0054e0f0 | Wrapper_e0f0 | wraps a single D3D transform/vertex processing call (end batch) |
| 0055d900 | sub_55D900 | applies static (non-animated) vertex transform |
| 0055da50 | sub_55DA50 | applies forward animation vertex transform |
| 0055e320 | sub_55E320 | applies reverse animation vertex transform |
| 0055eb30 | sub_55EB30 | renders/projects vertex data with wireframe/debug overlay |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x144) | 0x0 | != | 1 | animation mode: if mode != 1 (forward), check mode == 2 for reverse animation |
| *(this+0x144) | 0x0 | == | 2 | animation mode: if mode == 2, use reverse animation vertex blending |
| this | 0x118 | > | 0 | vertex count: PASSES if there are vertices to process; zero vertices BLOCKED (skip loop) |

**Guard interpretation:** 
- The outer guard `*(this+0x13C) != NULL` (mesh data pointer valid) must PASS for any processing. NULL → early return.
- `(v4[1] & 0x18000) == 0` (mesh node flags): If BOTH bits 15 and 16 are clear, skip to LABEL_73 (mark node as processed) without recomputing bounds. Both bits must be PASS (non-zero) to enter computation.
- `((unsigned int)&unk_800000 & v5) == 0`: MMX/CPU feature check. If the MMX flag bit is clear in the render flags (this+0x14/this+20), use the fast path (direct vertex read via D3D device wrapper). If set, use the slow path with software vertex processing.
- `(v5 & 0x80010000) != 0`: If bit 31 and bit 16 are set in render flags, use the animation/blend path with interpolation (lerp between source and target vertex positions via `v37` progress factor). Otherwise fall through to the non-blended path at LABEL_43.
- `(v5 & 0x10000) != 0`: Animation direction check: if bit 16 set, subtract UIRootContext offset from animation progress; otherwise add it.
- Animation mode guard at *(this+0x144)+0x0: 1 → forward animation (sub_55DA50), 2 → reverse animation (sub_55E320), else → static (sub_55D900). Controls which vertex transform function is called.
- `*(float *)(v14 + 8) <= *(float *)(v14 + 4)`: Animation progress <= animation duration → continue normally. If progress exceeds duration: mode 1 → clamp to 0 (reset), mode 2 → clamp to duration and set bit 31 flag. If progress < 0, clamp to 0 and clear bit 31.
