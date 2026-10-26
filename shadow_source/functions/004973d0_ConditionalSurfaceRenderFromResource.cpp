// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004973D0
// Canonical corpus name: sub_4973D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4973D0_004973d0.c

void UnknownObject::ConditionalSurfaceRenderFromResource()
{
    // Gated surface-render helper: when the instance float at offset 0xC4 exceeds 0.2 and the resource pointer at offset 0x1568 is non-null, searches for a named surface resource via ObjectSearchWithDoubleIteration using the name pointer at 0x1558 (defaulting to byte_5EA438). If a matching object is found its vtable method at +128 confirms the name and the instance resource is reused; otherwise sub_497AD0 supplies the aNodropicon0000 fallback. With a resource in hand, reads the sub-resource dimensions and renders the region via F_10ParamForwarder, then copies it with RenderSurfaceFillCopy.
    // GUARD: Guard: instance float at this+0xC4 must exceed 0.2 (threshold backed by flt_5AC994) and the resource pointer at this+0x1568 must be non-null. [source:raw, field:this:0x000000C4, field:this:0x00001568, global:0x005AC994]
    // CALL: ObjectSearchWithDoubleIteration searches for a named surface object from the instance. [source:raw, callee:0x00495980]
    // ASSIGNMENT: Resolve the lookup name: the string pointer at this+0x1558, or the byte_5EA438 default directory string when null. [source:raw, field:this:0x00001558, global:0x005EA438]
    // CALL: Indirect __thiscall through the searched object's vtable entry at +128 compares its name against the resolved name; equality (result 1) keeps the instance resource at this+0x1568 as the active resource. [source:raw, field:this:0x00001568]
    // CALL: Fallback when no matching object is found: sub_497AD0 returns the aNodropicon0000 resource. [source:raw, callee:0x00497AD0, global:0x005CCA48]
    // GUARD: Guard: proceed only when the active resource pointer is non-null. [source:raw]
    // ASSIGNMENT: Read the sub-resource pointer at resource+0xC and the dimensions at sub-resource+0x1C and +0x20 (height, width). [source:raw, field:*(this+0x1568):0x0000000C, field:*(*(this+0x1568)+0xC):0x0000001C, field:*(*(this+0x1568)+0xC):0x00000020]
    // ASSIGNMENT: Compute render geometry from instance X at this+0x5C and Y at this+0x60 against the sub-resource height: x = X - height, y = Y. [source:raw, field:this:0x0000005C, field:this:0x00000060]
    // CALL: GlobalAccessor_5150 supplies a value passed into the render call. [source:raw, callee:0x00495150]
    // CALL: F_10ParamForwarder renders the surface region using the active resource's inner pointer and the computed geometry. [source:raw, callee:0x00494A30]
    // CALL: Accessor obtains the render destination and RenderSurfaceFillCopy copies the rendered region. [source:raw, callee:0x00490920, callee:0x004918D0]

    // Conservative worker pseudocode:
    //   void sub_4973D0(int this) {
    //     if (*(float*)(this + 0xC4) > 0.2 && *(void**)(this + 0x1568)) {
    //       void* obj = ObjectSearchWithDoubleIteration((void*)this);
    //       const char* name = *(char**)(this + 0x1558);
    //       if (!name) name = byte_5EA438;
    //       void* res;
    //       if (obj && (*(unsigned __int8 (__thiscall**)(void*, const char*))(*obj + 128))(obj, name) == 1)
    //         res = *(void**)(this + 0x1568);
    //       else
    //         res = (void*)sub_497AD0(aNodropicon0000, 0);
    //       if (res) {
    //         void* sub = *(void**)(res + 0xC);
    //         int h = *(int*)(sub + 0x1C);
    //         int w = *(int*)(sub + 0x20);
    //         int x = *(int*)(this + 0x5C) - h;
    //         int y = *(int*)(this + 0x60);
    //         int v = GlobalAccessor_5150();
    //         F_10ParamForwarder(*(void**)(res + 0xC), 0, 0, v, x, y, h, w, 0, 0);
    //         RenderSurfaceFillCopy(Accessor(), x, y, h, w);
    //       }
    //     }
    //   }
    // UNRESOLVED: unk_7CDE00 is reported as read by the facts but does not appear in the raw decompiled body; its role is unknown.
    // UNRESOLVED: The indirect vtable method at object+128 is unnamed; it is treated as a name-comparison method.
    // UNRESOLVED: The semantics of the F_10ParamForwarder arguments (including the trailing zeros) are inferred, not confirmed.
}
