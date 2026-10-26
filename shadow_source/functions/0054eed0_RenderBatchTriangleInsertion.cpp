// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054EED0
// Canonical corpus name: sub_54EED0
// Owner: SceneRenderBatch [DERIVED]
// Raw source: functions/sub_54EED0_0054eed0.c

void SceneRenderBatch::RenderBatchTriangleInsertion()
{
    // Inserts a triangle into the scene render-batch slot array: iterates the source triangle list, transforms vertex indices to world-space positions through the global dword_8B8F24 service vtable, rejects far triangles with a distance/sphere test, scans batch slots (29-dword stride) for a free one, classifies the dominant axis of the contact normal, runs a 2D/3D point-in-triangle test, and fills the winning slot with the interpolated position, contact normal, material, parent pointers and a computed distance. Called on the frame path from SceneBatchRenderCheck (0x0054F5C0).
    // ASSIGNMENT: Seed result=0, inserted counter v29=0, triangle loop counter v32=0; capture v33=a3[75] and the triangle data pointer v6=a3[73]. [source:raw]
    // GUARD: Return 0 when the triangle count (int)a3[72] is not greater than zero; otherwise enter the triangle loop. [source:raw]
    // LOOP: Iterate the triangle array v6, nine floats per triangle (v6 += 9), incrementing v32 each pass and stopping once v32 >= a3[72]; the early-return path returns the inserted count v29. [source:raw]
    // CALL: Dispatch through the global dword_8B8F24 service vtable slot +4 (cdecl) to convert the triangle's two u16 vertex indices at v6+8 into a world float position written to v34..v36, using the a2+276 output context. [global:0x008B8F24, source:raw]
    // CALCULATION: Build the offset vector v40 = world position of this (floats v7[58..60] read from this+0x204, i.e. this[129]) minus v34..v36; also form v27 = v6[7] + *v8 where v8 = this[120] (this+0x1E0). [field:this:0x00000204, field:this:0x000001E0, source:raw]
    // GUARD: Reject the triangle when v27*v27 is greater than or equal to the squared distance returned by the dword_8B8F24 vtable slot +32 (thiscall) over v40; on rejection advance to the next triangle. [global:0x008B8F24, field:this:0x000001E0, source:raw]
    // CALL: Perform three dword_8B8F24 vtable slot +4 dispatches to read the three vertex positions (v42, v43, v44) from the mesh vertex array at *(v9+12) offset by 48 bytes per u16 vertex index. [global:0x008B8F24, source:raw]
    // ASSIGNMENT: Point v41[0..2] at the three decoded vertex position buffers v42, v43, v44. [source:raw]
    // GUARD: Enter the slot scan only when the slot count v11 = *(this[120]+4) is greater than zero; otherwise advance to the next triangle. [field:this:0x000001E0, source:raw]
    // LOOP: Scan the batch slot array v12/v13 (base resolved through this[120]+8; packet field base *(this+0x1E8)), slot stride 29 dwords per slot, index v28, until v28+1 is no longer below the slot count. [field:this:0x000001E0, field:this:0x000001E8, source:raw]
    // GUARD: Skip a slot whose state word (slot base +0x00) equals 6 (occupied/disabled), matching the packet guard value. [field:*(this+0x1E8):0x00000000, guard:0]
    // CALL: Dispatch dword_8B8F24 vtable slot +0 (cdecl) with v33 + 16*index to read additional triangle data into v34..v36. [global:0x008B8F24, source:raw]
    // CALCULATION: Run distance/plane tests through dword_8B8F24 vtable slot +32 against the slot transform data at slot+0x18, +0x28, +0x2C and +0x30, then compute interpolation factor v16 = (v6[8] - v30) / (v15 - v30) and interpolate v37..v39 from the slot vertices. [global:0x008B8F24, field:*(this+0x1E8):0x00000018, field:*(this+0x1E8):0x00000028, field:*(this+0x1E8):0x0000002C, field:*(this+0x1E8):0x00000030, source:raw]
    // STATE_TRANSITION: Classify the dominant contact axis from |v34|, |v35|, |v36| into side code v18 = 0..5 (0/1 for x-dominant, 2/3 for y-dominant, 4/5 for z-dominant) and store it into u16 slot of the source triangle v6. [source:raw]
    // CALL: Run F_2D3DTrianglePointTest(v18, v41, &v37); when it passes, fill the current slot. [callee:0x0054EB40, source:raw]
    // ASSIGNMENT: On a passing point test, populate the slot: mark state *v12 = 1 (slot base +0x00), write the op-context pointer a2 at slot+0x3C, the triangle-list pointer a3 at slot+0x40, this (parent scene) at slot+0x34, the material float from source-triangle mesh +4 at slot+0x44, slot index v28 at slot+0x48, source triangle pointer v6 at slot+0x4C, zero at slot+0x38 and slot+0x50, contact data v34..v36 at slot+0x58..0x60, interpolated position v37..v39 at slot+0x64..0x6C, and increment the inserted counter v29. [field:*(this+0x1E8):0x00000000, field:*(this+0x1E8):0x00000034, field:*(this+0x1E8):0x00000038, field:*(this+0x1E8):0x0000003C, field:*(this+0x1E8):0x00000040, field:*(this+0x1E8):0x00000044, field:*(this+0x1E8):0x00000048, field:*(this+0x1E8):0x0000004C, field:*(this+0x1E8):0x00000050, field:*(this+0x1E8):0x00000058, field:*(this+0x1E8):0x0000005C, field:*(this+0x1E8):0x00000060, field:*(this+0x1E8):0x00000064, field:*(this+0x1E8):0x00000068, field:*(this+0x1E8):0x0000006C, source:raw]
    // CALCULATION: Store the Euclidean distance v13[22] = sqrt(dx*dx + dy*dy + dz*dz) at slot+0x70 from the interpolated point to the slot vertex data. [field:*(this+0x1E8):0x00000070, source:raw]
    // CALL: Invoke SingleFunctionCallWrapper_9a30 on the slot base pointer at slot+0x34 to notify consumers of the freshly inserted slot. [callee:0x00559A30, field:*(this+0x1E8):0x00000034, source:raw]
    // RETURN: Return the number of triangles inserted (v29), or 0 when the triangle count was not positive. [source:raw]
    // CALL: Invoked on the frame path from SceneBatchRenderCheck (0x0054F5C0) to insert triangles into the render batch. [caller:0x0054F5C0, source:raw]
    // UNRESOLVED: Field read at this+0x1E4 is not visible in the Hex-Rays raw source; likely part of the slot-table structure alongside this+0x1E0 and this+0x1E8.
    // UNRESOLVED: Fields at this+0x2EC, +0x2F0, +0x2F4 are not visible in the Hex-Rays raw source; possibly a scene camera-position triplet used by the slot sphere/frustum tests.
    // UNRESOLVED: Global flt_59E440 is read but folded out of the raw source; likely a small float constant (bias/epsilon) used in the distance comparisons.
    // UNRESOLVED: The identity and exact contract of the global dword_8B8F24 service object (vtable slots +0, +4, +32) is not resolved here.
}
