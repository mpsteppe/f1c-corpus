// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00554D70
// Canonical corpus name: UICleanupIterator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UICleanupIterator_00554d70.c

void UnknownObject::UICleanupIterator()
{
    // UI cleanup iterator. Loads a resource-set pointer v2 from (a2+84). When v2[5] is non-null, iterates the this slot array (count from this+0x13B0, device object at this+0x1100), releasing each slot through the device vtable method at vtable+240 and storing the dispatch result into this[0]; each returned non-null handle is released via its own vtable+8, and when the handle equals v2[5] the slot state is reset via StateParameterSetterWithVirtualDeviceNotify. After the loop the shared resource v2[5] itself is released via vtable+8 and cleared to 0. Finally clears flags in v2[6] with mask 0xFFFFFBF7, sets v2[14] to -1082130432 (float -1.0), and returns 0.
    // ASSIGNMENT: Load resource-set pointer v2 = *(DWORD*)(a2+84). [source:raw]
    // GUARD: Guard: v2[5] (shared resource pointer) non-null before entering the cleanup body. [source:raw]
    // GUARD: Guard: slot count this+0x13B0 must be > 0 for the per-slot release loop. [field:this:0x000013B0, guard:0, source:raw]
    // LOOP: do-while loop over this+0x13B0 slots, index v4 from 0 while v4 < slot count; slot-state pointer v5 starts at this+4472 and advances by 17 DWORDs per iteration. [field:this:0x000013B0, source:raw]
    // CALL: Release each slot by virtual dispatch: call the method at device-vtable+240 (device object at this+0x1100, vtable at *(*(this+0x1100)+0x0)) with (device, v4, &a2), storing the result into this[0]. [field:*(this+0x1100):0x00000000, field:*(*(this+0x1100)+0x0):0x000000F0, field:this:0x00001100, field:this:0x00000000, source:raw]
    // GUARD: Guard: returned handle a2 non-null before releasing it. [source:raw]
    // GUARD: Guard: returned handle equals v2[5] before resetting the slot state. [source:raw]
    // CALL: Reset slot state via StateParameterSetterWithVirtualDeviceNotify(v5, 0) when the returned handle matches v2[5]. [callee:0x00554610, source:raw]
    // CALL: Release the returned handle via its object vtable+8. [source:raw]
    // CALL: Release the shared resource v2[5] via its vtable+8 after the slot loop. [source:raw]
    // ASSIGNMENT: Clear the shared resource pointer v2[5] = 0. [source:raw]
    // CALCULATION: Clear flags in v2[6] by AND with mask 0xFFFFFBF7. [source:raw]
    // ASSIGNMENT: Set v2[14] = -1082130432 (bit pattern of float -1.0). [source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_554D70(char* this, int a2) {
    //     DWORD* v2 = *(DWORD**)(a2 + 84);
    //     if (v2[5]) {
    //       for (int i = 0; i < *(DWORD*)(this + 0x13B0); ++i) {
    //         DWORD* slot = (DWORD*)(this + 4472 + 17 * 4 * i);
    //         int h = (*(int(__stdcall**)(DWORD,int,int*))(**(DWORD**)(this + 0x1100) + 240))(*(DWORD*)(this + 0x1100), i, &a2);
    //         *(DWORD*)this = h;
    //         if (h) {
    //           if (v2[5] == h) StateParameterSetterWithVirtualDeviceNotify(slot, 0);
    //           (*(void(__stdcall**)(int))(*(DWORD*)h + 8))(h);
    //         }
    //       }
    //       *(DWORD*)this = (*(int(__stdcall**)(DWORD))(*(DWORD*)v2[5] + 8))(v2[5]);
    //       v2[5] = 0;
    //     }
    //     v2[6] &= 0xFFFFFBF7;
    //     v2[14] = -1082130432;
    //     return 0;
    //   }
    // UNRESOLVED: Type and layout of the resource-set object v2 (at a2+84) are unknown; only v2[5], v2[6] and v2[14] are touched.
    // UNRESOLVED: The two virtual release methods (device vtable+240 and handle vtable+8) have unknown identity and release semantics.
    // UNRESOLVED: Mask 0xFFFFFBF7 flag semantics and the float -1.0 meaning of v2[14] are unknown.
    // UNRESOLVED: Purpose of the slot-state pointer this+4472 with 17-DWORD stride is inferred, not covered by packet fields.
}
