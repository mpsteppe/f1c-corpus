// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053F6E0
// Canonical corpus name: sub_53F6E0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_53F6E0_0053f6e0.c

void UnknownObject::ReleaseSubObjectViaVtable()
{
    // Sub-object release wrapper. Reads the sub-object pointer stored at a2+12; if non-null, invokes its vtable method at offset 8 (the third vtable slot) via __stdcall and stores the result into this+0. A non-zero result is treated as a failure: logs an error through sub_53C590 with the aInvalidParamet string and returns -1. On a zero result the pointer at a2+12 is nulled and the function returns 0. If a2+12 was already null it returns 0 immediately.
    // ASSIGNMENT: Read the sub-object pointer v2 from a2+12. [source:raw]
    // GUARD: Guard on v2 (a2+12) being non-null; the release call only happens when the sub-object exists. [source:raw]
    // CALL: Call the __stdcall vtable method at vtable offset 8 (third slot) on the sub-object at a2+12 and capture the return into v4. [source:raw]
    // ASSIGNMENT: Store the vtable call result v4 into this+0. [field:this:0x00000000, source:raw]
    // GUARD: Guard on v4 being non-zero, which indicates a failed release. [field:this:0x00000000, source:raw]
    // CALL: Call the error logger sub_53C590 with -1 and the aInvalidParamet string when the release failed. [callee:0x0053C590, global:0x005DBCD0, source:raw]
    // RETURN: Return -1 on release failure. [function:0x0053F6E0, source:raw]
    // ASSIGNMENT: Null out the sub-object pointer at a2+12 after a successful release. [source:raw]
    // RETURN: Return 0 on success, or immediately when a2+12 was already null. [function:0x0053F6E0, source:raw]

    // Conservative worker pseudocode:
    //   int ReleaseSubObjectViaVtable(int *this, void *a2) {
    //     void *sub = *(void **)(a2 + 12);
    //     if (sub) {
    //       int res = (*(int (__stdcall **)(void *))(*(int *)sub + 8))(sub);
    //       *this = res;
    //       if (res) {
    //         sub_53C590(-1, aInvalidParamet);
    //         return -1;
    //       }
    //       *(void **)(a2 + 12) = 0;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The identity of the object type at a2+12 and the exact contract of vtable slot offset 8 are unknown; callers include RendererResourceCleanup and D3DResourceRelease paths suggesting a rendering/D3D resource, unconfirmed here.
    // UNRESOLVED: Why the release result is also mirrored into this+0 is not explained by this packet.
}
