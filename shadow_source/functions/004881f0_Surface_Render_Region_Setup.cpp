// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004881F0
// Canonical corpus name: sub_4881F0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4881F0_004881f0.c

void UnknownObject::Surface_Render_Region_Setup()
{
    // UI element render/position setup with a dual path: when the virtual call at this+0 obtains a non-null child structure, compute its width/height, fetch a rendering context from the unk_7CDE00 global, and forward ten parameters through F_10ParamForwarder plus PositionUpdate; otherwise compute dimensions from this[1..4] bounds and call DelegationWrapper. Both paths write the resulting rectangle into a2/a3/a4/a5, then always dispatch the virtual call at vtable offset 44 with argument 0 and return 0.
    // CALL: Dispatch virtual call through vtable offset 168 on this to obtain the child/region structure pointer; result kept in v6/v7. [source:raw, field:this:0x00000000]
    // GUARD: Branch on v6 non-null: non-null selects the structured child path, null selects the fallback bounds path. [source:raw]
    // CALCULATION: Compute child dimensions: width v13 = v6[1]-v6[0], height v14 = v6[3]-v6[2]. [source:raw]
    // GUARD: Guard on width v13 > 0, height v14 > 0, and callback pointer at (v6[8]+12) (obj+0x2C) being non-null. [source:raw, field:obj:0x0000002C]
    // CALL: GlobalAccessor_5150(&unk_7CDE00) fetches the rendering context global. [source:raw, callee:0x00495150, global:0x007CDE00]
    // CALL: F_10ParamForwarder(callback, v6[0], v6[2], context, this[3], this[1], width v13, height v14, 0, 0) forwards ten rendering parameters. [source:raw, callee:0x00494A30, field:this:0x0000000C, field:this:0x00000004, field:obj:0x0000002C]
    // CALL: PositionUpdate(width v13, height v14) records the rendered region size. [source:raw, callee:0x0049AA70]
    // ASSIGNMENT: Write output rectangle: *a2 = this[1], *a3 = this[1]+height v14, *a4 = this[3], *a5 = this[3]+width v13. [source:raw, field:this:0x00000004, field:this:0x0000000C]
    // CALCULATION: Fallback path: height v10 = this[4]-this[3], width v11 = this[2]-this[1]. [source:raw, field:this:0x00000010, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000004]
    // GUARD: Guard on fallback height v10 > 0 and width v11 > 0. [source:raw]
    // CALL: GlobalAccessor_5150(&unk_7CDE00) fetches the rendering context global. [source:raw, callee:0x00495150, global:0x007CDE00]
    // CALL: DelegationWrapper(context, this[3], this[1], height v10, width v11, 65793) renders via the fallback delegation path. [source:raw, callee:0x00494BF0, field:this:0x0000000C, field:this:0x00000004]
    // ASSIGNMENT: Write output rectangle: *a2 = this[1], *a3 = this[1]+width v11, *a4 = this[3], *a5 = this[3]+height v10. [source:raw, field:this:0x00000004, field:this:0x0000000C]
    // CALL: Dispatch virtual call through vtable offset 44 on this with argument 0 for finalization on both paths. [source:raw, field:this:0x00000000]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4881F0(void* this, int* x0, int* x1, int* y0, int* y1) {
    //     void* child = (*(void* (__thiscall**)(void*))(*(char**)this + 168))(this);
    //     if (child) {
    //       int w = child[1] - child[0], h = child[3] - child[2];
    //       if (w > 0 && h > 0 && *(void**)(child[8] + 12)) {
    //         void* ctx = GlobalAccessor_5150(&unk_7CDE00);
    //         F_10ParamForwarder(*(void**)(child[8] + 12), child[0], child[2], ctx, this[3], this[1], w, h, 0, 0);
    //         PositionUpdate(w, h);
    //         *x0 = this[1]; *x1 = this[1] + h; *y0 = this[3]; *y1 = this[3] + w;
    //       }
    //     } else {
    //       int h = this[4] - this[3], w = this[2] - this[1];
    //       if (h > 0 && w > 0) {
    //         void* ctx = GlobalAccessor_5150(&unk_7CDE00);
    //         DelegationWrapper(ctx, this[3], this[1], h, w, 65793);
    //       }
    //       *x0 = this[1]; *x1 = this[1] + w; *y0 = this[3]; *y1 = this[3] + h;
    //     }
    //     (*(void (__thiscall**)(void*, int))(*(char**)this + 44))(this, 0);
    //     return 0;
    //   }
    // UNRESOLVED: Meaning of the obj+0xA8 field in the child structure returned by vtable+168 is not reachable from the shown raw source.
    // UNRESOLVED: Semantics of the 65793 constant passed to DelegationWrapper are unknown.
    // UNRESOLVED: Indirect vtable dispatch targets at offsets 44 and 168 are unresolved.
    // UNRESOLVED: The proposed name is the LEGACY abi lead 'Surface_Render_Region_Setup'; ownership stays UNKNOWN pending independent evidence.
}
