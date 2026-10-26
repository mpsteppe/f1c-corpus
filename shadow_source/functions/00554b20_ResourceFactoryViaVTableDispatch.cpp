// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00554B20
// Canonical corpus name: ResourceFactoryViaVTableDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ResourceFactoryViaVTableDispatch_00554b20.c

void UnknownObject::ResourceFactoryViaVTableDispatch()
{
    // Creates or reconfigures a resource through a virtual dispatch on a device object. Extracts render parameters from a2 via sub_5424E0, conditionally clips a render region via ClippedRenderRegion when a2+416 holds a pointer and a3 is zero, then dispatches to the device object's vtable+0x90 method with a mode selected by a byte flag at a2+128. Stores the returned handle at *this.
    // CALL: Call sub_5424E0(a2, &v8, &v9, &v10, &v11) to extract render parameters from a2 into the four out locals. [callee:0x005424E0, source:raw]
    // GUARD: if ( a3 ) skip the clipping branch entirely and proceed directly to the vtable dispatch. [source:raw]
    // ASSIGNMENT: v4 = pointer stored at a2+416; its null-ness selects between the clipping path and the fallback dispatch path. [source:raw]
    // GUARD: if ( v4 != NULL ) call ClippedRenderRegion with the extracted parameters and this[1354]. [source:raw]
    // CALL: Call ClippedRenderRegion(v4, v8, v9, this[1354], v8, v9, v10, v11, 0, 0) to clip the render region to the region base stored at this+0x1528. [callee:0x00543250, field:this:0x00001528, source:raw]
    // CALL: Dispatch to the virtual method at device vtable+0x90 (device = *(this+0x1100)) with mode argument 2 and literal 1065353216, writing the result to *this. [field:*(this+0x1100):0x00000090, field:this:0x00001100, field:this:0x00000000, source:raw]
    // GUARD: When the clip path was skipped, select the dispatch mode from the byte flag at a2+128: bit 1 set selects mode 3 with a2[124] as an argument, otherwise mode 2. [source:raw]
    // CALL: Fallback path: dispatch to the virtual method at device vtable+0x90 on the device object (this[1088]) with the mode selected by the a2+128 flag and literal 1065353216. [field:*(this+0x1100):0x00000090, field:this:0x00001100, source:raw]
    // ASSIGNMENT: *this = result of the vtable dispatch, storing the created/configured resource handle on this. [field:this:0x00000000, source:raw]
    // RETURN: return result (the dispatch return value). [source:raw]

    // Conservative worker pseudocode:
    //   int ResourceFactoryViaVTableDispatch(int *this, int a2, int a3) {
    //     int v8, v9, v10, v11;
    //     sub_5424E0((_DWORD*)a2, &v8, &v9, &v10, &v11);
    //     if ( !a3 ) {
    //       int *v4 = *(int**)(a2 + 416);
    //       if ( v4 )
    //         ClippedRenderRegion(v4, v8, v9, this[1354], v8, v9, v10, v11, 0, 0);
    //       else {
    //         int *v6 = (int*)this[1088];
    //         int v7 = *v6;
    //         if ( (*(_BYTE*)(a2 + 128) & 2) != 0 )
    //           result = vtableMethod(v6, 0, 0, 3, *(_DWORD*)(a2 + 124), 1065353216, 0);
    //         else
    //           result = vtableMethod(v6, 0, 0, 2, 0, 1065353216, 0);
    //         *this = result;
    //         return result;
    //       }
    //     }
    //     result = vtableMethod(this[1088], 0, 0, 2, 0, 1065353216, 0);
    //     *this = result;
    //     return result;
    //   }
    // UNRESOLVED: Semantic meaning of the dispatch mode arguments (2 vs 3) and of the literal 1065353216 is unknown.
    // UNRESOLVED: Purpose of the a2+128 bit-1 flag and the a2[124] argument in mode 3 is unknown.
    // UNRESOLVED: Exact signature and return contract of the vtable+0x90 device method is unknown.
    // UNRESOLVED: Offsets within a2 (416, 128, 124) are consumed only via the raw source; no packet field evidence refs them.
}
