// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055C330
// Canonical corpus name: sub_55C330
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_55C330_0055c330.c

void UnknownObject::DirectXDisplayModeGetCurrent()
{
    // Queries the current display mode from a DirectX device object. Calls the device vtable method at offset 0x20 on the device pointer stored at this+0x10FC (this[1087]) and stores the returned code in this+0x0. On failure (non-zero code) it logs the 'Could not get current display mode' error string via sub_53C590 and returns -1. On success it copies the two returned mode fields out to the optional a2 and a3 outputs, and, when a4 is provided, sets the display mode via sub_55C450 using the local format value v8 (with a special case that substitutes format 21 when v8 equals 22). Returns 0 on success.
    // CALL: Invoke the DirectX device method at vtable offset 0x20 on the device object read from this+0x10FC (this[1087]), passing (device, 0, &v7); the stdcall result is stored in v5. [field:*(this+0x10FC):0x00000020, field:this:0x000010FC, source:raw]
    // ASSIGNMENT: *this = v5: store the vtable method return code into this+0x0. [field:this:0x00000000, source:raw]
    // GUARD: When v5 is non-zero (the call failed), take the error path that logs and returns -1. [field:this:0x00000000, source:raw]
    // CALL: Log the failure via sub_53C590(-1, aCouldNotGetCur), passing the 'Could not get current display mode' string global. [callee:0x0053C590, global:0x005DBCAC, source:raw]
    // RETURN: Return -1 on the failure path. [function:0x0055C330, source:raw]
    // ASSIGNMENT: When a2 is non-null, write v7[0] (mode field 0 returned by the vtable method) to *a2. [source:raw]
    // ASSIGNMENT: When a3 is non-null, write v7[1] (mode field 1 returned by the vtable method) to *a3. [source:raw]
    // GUARD: When a4 is non-null, enter the set-display-mode path. [source:raw]
    // GUARD: When the local format value v8 equals 22, take the special-case format path instead of the general one. [source:raw]
    // CALL: Special case: sub_55C450(21, 0, a4) sets the display mode with format 21 when the read format v8 is 22. [callee:0x0055C450, source:raw]
    // RETURN: Return 0 immediately after the special-case set-display-mode call. [function:0x0055C330, source:raw]
    // CALL: General case: sub_55C450(v8, 0, a4) sets the display mode with the read format v8 for every other format. [callee:0x0055C450, source:raw]
    // RETURN: Return 0 on the success path. [function:0x0055C330, source:raw]
    // CALL: Invoked from VidMan_Enter (0x004FA000) during video-manager enter/initialization. [caller:0x004FA000]

    // Conservative worker pseudocode:
    //   int DirectXDisplayModeGetCurrent(int *this, _DWORD *a2, _DWORD *a3, int a4) {
    //     _DWORD v7[3];
    //     int v5 = (*(int (__stdcall **)(int, _DWORD, _DWORD *))(*(_DWORD *)this[1087] + 0x20))(this[1087], 0, v7);
    //     *this = v5;
    //     if (v5 != 0) {
    //       sub_53C590(-1, aCouldNotGetCur);
    //       return -1;
    //     }
    //     if (a2) *a2 = v7[0];
    //     if (a3) *a3 = v7[1];
    //     if (a4) {
    //       if (v8 == 22)
    //         sub_55C450(21, 0, a4);
    //       else
    //         sub_55C450(v8, 0, a4);
    //       return 0;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: v8 is read in the set-display-mode path but never assigned in the decompiled body; it is likely a decompiler artifact of the display-mode format field returned through the v7 output struct, but its exact source is not established by the raw source.
    // UNRESOLVED: The identity of the vtable+0x20 method as GetDisplayMode and the roles of v7[0]/v7[1] as width/height come from the existing analysis prose, not from the raw source alone.
    // UNRESOLVED: The special-case interpretation of format 22 (and the swap to 21) as an A8R8G8B8 pixel-format rule is existing-analysis prose and is not independently proven.
    // UNRESOLVED: The owner type of this and the device object at this+0x10FC remain unknown; caller VidMan_Enter (0x004FA000) does not identify the class.
}
