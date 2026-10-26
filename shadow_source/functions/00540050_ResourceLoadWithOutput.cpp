// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00540050
// Canonical corpus name: ResourceLoadWithOutput
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ResourceLoadWithOutput_00540050.c

void UnknownObject::ResourceLoadWithOutput()
{
    // Resource load helper. Calls LockUnlockWrapper(a2, a3, &v9), stores the returned status into the this field, and returns -1 immediately if the status is non-zero. On success, optionally copies result words v9[0] and v9[1] into the output parameters a4 and a5, and when a6 is non-null calls sub_55C450(v9[4], 0, a6). Returns 0 on success. Structural twin of ConditionalSingleStoreWithIteration (0049a1c0) per prelabel.
    // CALL: Call LockUnlockWrapper(a2, a3, &v9) and store its return value as v7. [callee:0x005006D5, source:raw]
    // ASSIGNMENT: Store the wrapper status v7 into the this field. [field:this:0x00000000, source:raw]
    // GUARD: Guard on v7 being non-zero; failure returns -1 without touching the output fields. [source:raw]
    // ASSIGNMENT: When a4 is non-null, write result word v9[0] to *a4. [source:raw]
    // ASSIGNMENT: When a5 is non-null, write result word v9[1] to *a5. [source:raw]
    // CALL: When a6 is non-null, call sub_55C450(v9[4], 0, a6). [callee:0x0055C450, source:raw]
    // RETURN: Return 0 after a successful load. [function:0x00540050, source:raw]

    // Conservative worker pseudocode:
    //   int __thiscall sub_540050(int *this, int a2, int a3, _DWORD *a4, _DWORD *a5, int a6) {
    //     _DWORD v9[7];
    //     int v7 = LockUnlockWrapper(a2, a3, (int)v9);
    //     *this = v7;
    //     if (v7)
    //       return -1;
    //     if (a4)
    //       *a4 = v9[0];
    //     if (a5)
    //       *a5 = v9[1];
    //     if (a6)
    //       sub_55C450(v9[4], 0, a6);
    //     return 0;
    //   }
    // UNRESOLVED: Layout and meaning of the v9 result words filled by LockUnlockWrapper are unknown.
    // UNRESOLVED: Role of the this field (status holder) and the object owning it are not visible here.
    // UNRESOLVED: What sub_55C450 does with v9[4], 0, a6 is external to this function.
}
