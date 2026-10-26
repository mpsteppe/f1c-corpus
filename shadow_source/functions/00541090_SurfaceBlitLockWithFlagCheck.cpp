// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00541090
// Canonical corpus name: SurfaceBlitLockWithFlagCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SurfaceBlitLockWithFlagCheck_00541090.c

void UnknownObject::SurfaceBlitLockWithFlagCheck()
{
    // Surface lock helper: takes a surface/object a2 and, when present, reads its lock sub-object at a2+24 and invokes that sub-object's __stdcall vtable method at offset +44 with doubled dimensions (2*a4, 2*a5), a status out-slot v10 and a flags word that is 2064 (0x810) when bit 0 of a2's first byte is set, otherwise 2048 (0x800). The call result is stored into this+0; on a nonzero (failed) result it returns 0, otherwise it increments a lock/ref counter at a2+12 and returns the out-slot v10. Doubling of a4/a5 suggests the lock covers a scaled blit region.
    // ASSIGNMENT: Initialize the out-slot v10 = 0 and the default lock flags v6 = 2048 (0x800). [source:raw]
    // GUARD: Guard: when a2 is null, skip the entire lock path and fall through to return v10. [source:raw]
    // CALCULATION: Read the lock sub-object pointer v7 = *(DWORD*)(a2 + 24). [source:raw]
    // GUARD: Guard: when v7 is null, skip the lock call and fall through to return v10. [source:raw]
    // GUARD: Flag check: when bit 0 of *(BYTE*)a2 is set, use lock flags 2064 (0x810) instead of 2048 (0x800). [source:raw]
    // CALL: Call the __stdcall method at vtable offset +44 of sub-object v7: v8 = (*(...**)(*v7 + 44))(v7, 2*a4, 2*a5, &v10, v6). The locked status/region is written through the out-slot v10. [source:raw]
    // ASSIGNMENT: Store the call result into the this field: *this = v8. [field:this:0x00000000, source:raw]
    // GUARD: Guard: when the call returned nonzero (lock failed), return 0 immediately. [function:0x00541090, source:raw]
    // CALCULATION: Increment the lock/ref counter: ++*(DWORD*)(a2 + 12). [source:raw]
    // RETURN: Return v10 (the lock status/out-slot value, zero on the early-fail path). [function:0x00541090, source:raw]

    // Conservative worker pseudocode:
    //   int sub_541090(int *this, int a2, int a3, int a4, int a5) {
    //     int flags = 2048;
    //     int v10 = 0;
    //     if (a2) {
    //       int v7 = *(DWORD*)(a2 + 24);
    //       if (v7) {
    //         if ((*(BYTE*)a2 & 1) != 0) flags = 2064;
    //         int v8 = (*(int (__stdcall **)(int,int,int,int*,int))(*v7 + 44))(v7, 2*a4, 2*a5, &v10, flags);
    //         *this = v8;
    //         if (v8) return 0;
    //         ++*(DWORD*)(a2 + 12);
    //       }
    //     }
    //     return v10;
    //   }
    // UNRESOLVED: The vtable method at sub-object offset +44 is an indirect __stdcall call; no static callee is recorded in the packet, so its identity and the lock contract are unresolved.
    // UNRESOLVED: The meaning of the value written to this+0 and of the returned v10 (locked region vs status word) is unestablished.
    // UNRESOLVED: The a2 object layout (byte 0 flag bit, +12 counter, +24 lock sub-object) and the reason dimensions a4/a5 are doubled are DERIVED from the packet body only; no field evidence exists for the a2 dereferences.
}
