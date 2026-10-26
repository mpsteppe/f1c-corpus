// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00554700
// Canonical corpus name: PropertyValueSetterWithRefreshOnChange
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PropertyValueSetterWithRefreshOnChange_00554700.c

void UnknownObject::PropertyValueSetterWithRefreshOnChange()
{
    // Property setter with refresh-on-change. When a2 is non-null it applies a2[8] and a2[1] as property values: each value is stored into its cached slot (this+0x1398 / this+0x139C) only when it changed, and a change triggers a virtual call on the device object at this+0x1100 (vtable slot 0x14C for a2[8], slot 0x130 for a2[1], the latter only when a2[1] != -1). The dispatch result is stored at this+0x0. When a2 is null it resets this+0x1398 to zero and dispatches slot 0x14C with zeroed arguments.
    // GUARD: Branch on a2: the non-null path applies a2's property values with change notification; the null path resets the cached property to zero. [source:raw]
    // CALCULATION: Read the candidate value v3 = a2[8]. [source:raw]
    // GUARD: When this+0x1398 (this[1254]) differs from a2[8], store a2[8] into this+0x1398. [field:this:0x00001398, source:raw]
    // CALL: Dispatch vtable slot at offset 0x14C (332) on the device object at this+0x1100 with arguments (device, 0, a2[8], a2[2]); store the return value into this+0x0. [field:*(this+0x1100):0x0000014C, field:this:0x00001100, field:this:0x00000000, source:raw]
    // CALCULATION: Read the second candidate value result = a2[1]. [source:raw]
    // GUARD: When this+0x139C (this[1255]) differs from a2[1] AND a2[1] != -1, store a2[1] into this+0x139C. [field:this:0x0000139C, source:raw]
    // CALL: Dispatch vtable slot at offset 0x130 (304) on the device object at this+0x1100 with arguments (device, a2[1]); store the return value into this+0x0. [field:*(this+0x1100):0x00000130, field:this:0x00001100, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Null path: set this+0x1398 to 0, then dispatch vtable slot at offset 0x14C (332) on the device object with arguments (device, 0, 0, 0) and store the return into this+0x0. [field:this:0x00001398, field:*(this+0x1100):0x0000014C, field:this:0x00001100, field:this:0x00000000, source:raw]
    // RETURN: Return the last dispatch result. [source:raw]

    // Conservative worker pseudocode:
    //   int PropertyValueSetterWithRefreshOnChange(int *this, _DWORD *a2) {
    //     int result;
    //     if (a2) {
    //       if (this[1254] != a2[8]) {
    //         this[1254] = a2[8];
    //         this[0] = (*(int(__stdcall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)this[1088] + 332))(this[1088], 0, a2[8], a2[2]);
    //       }
    //       result = a2[1];
    //       if (this[1255] != result && result != -1) {
    //         this[1255] = result;
    //         this[0] = (*(int(__stdcall **)(int, _DWORD))(*(_DWORD *)this[1088] + 304))(this[1088], a2[1]);
    //       }
    //     } else {
    //       int v5 = this[1088];
    //       this[1254] = 0;
    //       this[0] = (*(int(__stdcall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v5 + 332))(v5, 0, 0, 0);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Identity and type of the device object at this+0x1100; the exact meaning of vtable slots 0x130 and 0x14C (property setter / notification handlers) is unconfirmed.
    // UNRESOLVED: Layout of a2: roles of a2[1], a2[2] and a2[8]; a2[2] is only forwarded to slot 0x14C when a2[8] changes.
    // UNRESOLVED: Why a2[1] == -1 is special-cased as a sentinel that suppresses the second update.
    // UNRESOLVED: Purpose of writing this+0x0 with dispatch return values (result/status accumulation).
}
