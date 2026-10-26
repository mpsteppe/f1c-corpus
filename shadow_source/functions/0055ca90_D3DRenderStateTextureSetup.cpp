// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055CA90
// Canonical corpus name: sub_55CA90
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_55CA90_0055ca90.c

void UnknownObject::D3DRenderStateTextureSetup()
{
    // Sets up a Direct3D texture/render-state binding for a surface. Selects between a default-texture path and a descriptor-driven path based on the flag dword a2[6] (bit 0x40000). The descriptor path loads either a file/stream-backed source a2[3] or locks a surface object a2[5] (via vtable slot 60), then binds it through the D3D device wrapper this[1088] (this+0x1100) using the device method at vtable offset 124; the flag 0x200000 selects a stream-handle variant. Stores the load result in this+0x0, and when a3 is non-null builds a 6-word vector from a2[7]/a2[8] and applies it through the device method at vtable offset 160. Returns a3 when present, otherwise the last result.
    // GUARD: Entry branch: when a2 is null, or a2 is non-null but its flag dword a2[6] has bit 0x40000 clear, take the default-texture path using this[1354]+12 and this[1355]+12; otherwise walk the descriptor a2. [field:this:0x00001528, field:this:0x0000152C, source:raw]
    // CALL: Default path: invoke the D3D device method at vtable offset 124 on the wrapper this[1088] (this+0x1100) with the two default parameters *(this[1354]+12) and *(this[1355]+12). [field:*(this+0x1100):0x0000007C, field:this:0x00001100, field:this:0x00001528, field:this:0x0000152C, source:raw]
    // GUARD: Descriptor path: when a2[3] is non-null the source is file/stream-backed and is loaded directly; when null, a2[5] is a surface object that must be locked first. [source:raw]
    // GUARD: Flag 0x200000 in a2[6] selects the stream-handle variant of the load in both the a2[3] and a2[5] branches. [source:raw]
    // CALL: File load, stream variant: call device vtable slot 124 (this[1088], a2[3], 0). [field:*(this+0x1100):0x0000007C, field:this:0x00001100, source:raw]
    // GUARD: File load, non-stream variant: when a2[1] is non-null and *(a2[1]+12) is non-zero use that identifier; otherwise fall back to *(this[1355]+12). [field:this:0x0000152C, source:raw]
    // CALL: File load: call device vtable slot 124 (this[1088], a2[3], identifier) where identifier is *(a2[1]+12) or *(this[1355]+12). [field:*(this+0x1100):0x0000007C, field:this:0x00001100, field:this:0x0000152C, source:raw]
    // GUARD: Surface path: when a2[5] is null, jump to LABEL_19 and skip the result write; otherwise proceed to lock and load the surface. [source:raw]
    // CALL: Surface lock, stream variant: call device vtable slot 124 (this[1088], 0, 0). [field:*(this+0x1100):0x0000007C, field:this:0x00001100, source:raw]
    // CALL: Surface lock, non-stream variant: write *this = (surface vtable slot 60)(a2[5], 0, &a2) to lock the surface object. [field:this:0x00000000, source:raw]
    // CALL: Surface data load: call device vtable slot 124 (this[1088], a2, identifier) with identifier *(a2[1]+12) or *(this[1355]+12), then release the surface through its vtable slot 8. [field:*(this+0x1100):0x0000007C, field:this:0x00001100, field:this:0x0000152C, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Store the load result into this+0x0: *this = v7 (the render handle returned by the D3D load). [field:this:0x00000000, source:raw]
    // GUARD: Transform step: when a3 is non-null, build a 6-word vector and apply it as the current transform. [source:raw]
    // CALCULATION: Build the transform vector v16: v16[0]=0, v16[1]=0, v16[2]=a2[7], v16[3]=a2[8], v16[4]=0, v16[5]=1065353216 (identity-scaled component). [source:raw]
    // CALL: Apply the transform: result = device vtable slot 160 (this[1088], v16) and store *this = result. [field:*(this+0x1100):0x000000A0, field:this:0x00001100, field:this:0x00000000, source:raw]
    // RETURN: Return result (a3 when non-null, otherwise the last load result); on the frame path, called by F_2DSurfaceBlitFill, sub_553700 and sub_55CC20. [caller:0x005404D0, caller:0x00553700, caller:0x0055CC20, function:0x0055CA90, source:raw]

    // Conservative worker pseudocode:
    //   if (a2 && (a2[6] & 0x40000)) {
    //       if (a2[3]) {
    //           if (a2[6] & 0x200000) v7 = device->vt[124](this[1088], a2[3], 0);
    //           else v7 = device->vt[124](this[1088], a2[3], id_or_default);
    //       } else if (a2[5]) {
    //           if (a2[6] & 0x200000) v7 = device->vt[124](this[1088], 0, 0);
    //           else { *this = surface->vt[60](a2[5], 0, &a2);
    //                  v7 = device->vt[124](this[1088], a2, id_or_default);
    //                  v7 = a2->vt[8](a2); }
    //       } else goto LABEL_19;
    //   } else {
    //       v7 = device->vt[124](this[1088], *(this[1354]+12), *(this[1355]+12));
    //   }
    //   *this = v7;
    //   LABEL_19:
    //   if (a3) {
    //       v16 = {0, 0, a2[7], a2[8], 0, 1065353216};
    //       result = device->vt[160](this[1088], v16);
    //       *this = result;
    //   }
    //   return result;
    // UNRESOLVED: The fields this+0x1534 and this+0x1538 are extracted as read-only by the IDB but do not appear in the raw source of this function; the fill labels them texture/surface parameters without grounding here.
    // UNRESOLVED: The exact roles of the vtable slots 124, 60 and 8 on the device and surface objects (load vs lock vs release) are inferred from call shape only.
    // UNRESOLVED: a2 is the descriptor object; its internal fields are not covered by packet evidence refs, so the meaning of the 0x40000 and 0x200000 flags and the a2[1]/a2[3]/a2[5] slots is derived, not confirmed.
}
