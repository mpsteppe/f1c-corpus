// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048E750
// Canonical corpus name: ViewportRectangleRenderSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ViewportRectangleRenderSetup_0048e750.c

void UnknownObject::ViewportRectangleRenderSetup()
{
    // Reads four rectangle bounds from this-object fields (offsets 0x4, 0x8, 0xC, 0x10). Guarded by a state check on a child object (pointer at this+0x40, dword at +0x38 equals 2). When enabled (this+0xE8 and this+0xEC both nonzero) it computes screen-scaled viewport offsets, configures the viewport via sub_542200, drives a conditional-init/compare/reset sequence over globals unk_8AFE18 and dword_8AFE64, restores the full viewport, and updates the camera projection, then writes the bounds to the four output pointers.
    // GUARD: Outer guard: proceeds only when the dword at (child pointer stored at this+0x40) + 0x38 equals 2; otherwise skips the body and returns 0. [guard:0, field:this:0x00000040, source:raw, function:0x0048E750]
    // ASSIGNMENT: Reads the rectangle bounds from this-object fields: v6 = this+0x4, v5 = this+0x8, v8 = this+0xC, v7 = this+0x10; saves v5 into v14. [field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, source:raw]
    // GUARD: Inner guard: viewport-offset computation runs only when both dword fields this+0xE8 and this+0xEC are nonzero. [field:this:0x000000E8, field:this:0x000000EC, source:raw]
    // CALCULATION: Computes scaled viewport offsets: v13 = (v5 - v6) * 0.0016666667, v12 = (v7 - v8) * 0.00125, v11 = this+0x4 * 0.0016666667, v10 = this+0xC * 0.00125. [field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, source:raw]
    // CALL: Calls sub_542200(v10, v11, v12, v13, 0) to configure the scaled viewport rectangle. [callee:0x00542200, source:raw]
    // CALL: Calls ConditionalInit(&unk_8AFE18) to initialize state tracking on global unk_8AFE18. [callee:0x004F9F00, global:0x008AFE18, source:raw]
    // CALL: Calls ArithmeticComparison_6200(dword_8AFE64) passing global dword_8AFE64. [callee:0x00546200, global:0x008AFE64, source:raw]
    // CALL: Calls ConditionalStateReset(&unk_8AFE18) to reset state tracking on global unk_8AFE18. [callee:0x004F9F30, global:0x008AFE18, source:raw]
    // CALL: Calls sub_542200(0.0, 0.0, 1.0, 1.0, 0) to restore the full unit viewport rectangle. [callee:0x00542200, source:raw]
    // CALL: Calls CameraProjectionUpdate(14) to update the camera projection matrix. [callee:0x00541B70, source:raw]
    // ASSIGNMENT: Writes the rectangle bounds to the output pointers: *a2 = v6, *a3 = v5, *a4 = v8, *a5 = v7. [source:raw, function:0x0048E750]
    // RETURN: Returns 0. [source:raw, function:0x0048E750]

    // Conservative worker pseudocode:
    //   int ViewportRectangleRenderSetup(_DWORD *this, _DWORD *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
    //   {
    //     if (*(_DWORD *)(this[16] + 56) == 2)
    //     {
    //       int v6 = this[1];
    //       int v5 = this[2];
    //       int v8 = this[3];
    //       int v7 = this[4];
    //       if (this[58] && this[59])
    //       {
    //         float v13 = (float)(v5 - v6) * 0.0016666667f;
    //         float v12 = (float)(v7 - v8) * 0.00125f;
    //         float v11 = (float)this[1] * 0.0016666667f;
    //         float v10 = (float)this[3] * 0.00125f;
    //         sub_542200(v10, v11, v12, v13, 0);
    //         ConditionalInit(&unk_8AFE18);
    //         ArithmeticComparison_6200(dword_8AFE64);
    //         ConditionalStateReset(&unk_8AFE18);
    //         sub_542200(0.0, 0.0, 1.0, 1.0, 0);
    //         CameraProjectionUpdate(14);
    //       }
    //       *a2 = v6;
    //       *a4 = v8;
    //       *a3 = v5;
    //       *a5 = v7;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The packet guard table lists the outer guard as this+0x78 == 2, but the raw source checks the dword at (child pointer this+0x40) + 0x38 == 2; the field at this+0x78 is not directly referenced in the raw source.
    // UNRESOLVED: Globals flt_5A68E8 and flt_5A68EC are listed as reads but do not appear in the raw decompiled text; the literals 0.0016666667 and 0.00125 may be their inlined values (screen scale factors), but this is not evidenced.
    // UNRESOLVED: Semantics of globals unk_8AFE18 and dword_8AFE64 in the init/compare/reset sequence are unknown.
}
