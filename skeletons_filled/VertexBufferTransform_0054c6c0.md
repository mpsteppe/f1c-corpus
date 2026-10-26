## VertexBufferTransform_0054c6c0 — Vertex transform with D3D device

**Summary:** Applies position and rotation transforms to vertex buffer data via the D3D device, then clears transform accumulators and allocates new empty vertex structures. Runs once (guarded by a 0x4000000 done flag). Part of the scene graph mesh rendering pipeline.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AudioNetworkTreeWalker (00544d30), sub_557670 (00557670)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x138) | 0x3C | R | — | Sub-object flag byte; bit 4 (0x10) selects whether transformed vertex data is written back |
| this | 0x14 | RW | — | Flags word; bit 26 (0x4000000) is done-guard, bit 23 (0x800000) selects 16-DWORD vs 12-DWORD vertex stride |
| this | 0x100 | RW | 0 | Position/translation X input for Euler-angle transform |
| this | 0x104 | RW | 0 | Position/translation Y input |
| this | 0x108 | RW | 0 | Position/translation Z input |
| this | 0x10C | RW | 0 | Euler angle X (pitch) input for rotation matrix |
| this | 0x110 | RW | 0 | Euler angle Y (yaw) input / later: pointer to allocated 8-struct block |
| this | 0x114 | RW | 0 | Euler angle Z (roll) input |
| this | 0x118 | R | — | Vertex element count (guard > 0 for processing loop) |
| this | 0x11C | R | — | Vertex element array pointer (64-byte stride per element) |
| this | 0x138 | R | — | Pointer to sub-object with per-instance render flags |

**Written-by note (persistence):**
- this 0x14: ORed with 0x4000000 at end (done flag), prevents re-execution
- this 0x100: set to 0 after transform applied
- this 0x104: set to 0 after transform applied
- this 0x108: set to 0 after transform applied
- this 0x10C: set to 0 after transform applied
- this 0x110: set to 0 then repurposed as pointer to new allocation
- this 0x114: set to 0 after transform applied

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00800000 | unk_800000 | R | Constant 0x800000 flag to select 16-DWORD vertex format path |
| 008b8f24 | dword_8B8F24 | R | D3DDeviceWrapperPtr [DERIVED] (also: ` — D3D device wrapper / scene manager singleton vtable (docs/22) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053b130 | F_10FloatStructInitializer | Initializes a 10-float structure for matrix computation |
| 0053b160 | EmptyStub_b160 | No-op stub called at end of transform |
| 0053b200 | MultiFieldSetter | Sets X/Y/Z position values into the transform struct |
| 0053b240 | EulerAngleToRotationMatrix | Computes rotation matrix from Euler angles |
| 0054b4d0 | sub_54B4D0 | Resets mesh sub-object transform state |
| 0054d080 | sub_54D080 | Post-transform processing step |
| 0054d520 | F_3DBoundingBoxExtentsComputation | Computes 3D bounding box extents |
| 0054e080 | FlagSetLoop | Iterates and sets mesh flags after transform |
| 0054e270 | BoundingBoxComputationFromVertexData | Computes bounding box from transformed vertex data |
| 0055d200 | StructZeroInitWithBaseCall | Initializes a newly allocated vertex struct block to zero |
| 00587c03 | OperatorNewNhMallocWrapper | Allocates 452 bytes for 8 new vertex structs (14 DWORDS each) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x118 | > | 0 | Vertex element count |

**Guard interpretation:** Primary guard at entry: if `this[20] & 0x4000000` is nonzero, BLOCKED entirely (transform already applied). If zero, PASSES. Inner guard: if this[280] (vertex element count at +0x118) > 0, PASSES: enters vertex transform loop. If <= 0, BLOCKED: skip all vertex processing but still clears accumulators and allocates new structs.
