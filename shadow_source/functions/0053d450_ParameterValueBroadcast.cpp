// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053D450
// Canonical corpus name: ShortComputation_d450
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_d450_0053d450.c

void UnknownObject::ParameterValueBroadcast()
{
    // Guarded broadcast of an integer argument to a list of per-receiver float state slots. If the global dword_8B89A0 is nonzero, the argument is staged at dword_8B8C50[13]; a loop then walks entries of a float table starting at unk_8B8A58 with a 17-dword stride, count bounded by dword_8B8C50[0]. For each entry that differs from the staged value, the entry is updated and a virtual-style method at offset 252 of the object pointed to by dword_8B89A0 is called with (object, entry index, 19, staged value), the result being stored into dword_8B78A0 (0x008B78A0). The function returns dword_8B8C50[0] (the loop bound) after the loop, or 0 when dword_8B89A0 is zero. Called from MainCameraDirectorUpdate.
    // GUARD: Read the global dword_8B89A0; if it is zero, skip the whole body and return it. [source:raw]
    // ASSIGNMENT: Stage the integer argument into element 13 of the global array dword_8B8C50. [source:raw]
    // LOOP: Iterate entry index v2 from 0 while v2 < dword_8B8C50[0], advancing a pointer v3 through the float table starting at unk_8B8A58 with a stride of 17 dwords per entry. [source:raw]
    // GUARD: Inside the loop, test whether the current float table entry (*v3) differs from the staged value reinterpreted as float (dword_8B8C50[13]); only on a difference is the entry updated and the method call made. [source:raw]
    // ASSIGNMENT: Update the current float table entry *v3 to the staged value (float reinterpretation of dword_8B8C50[13]). [source:raw]
    // CALL: Invoke the method located at offset 252 in the object referenced by dword_8B89A0 (a stdcall-style indirect call), passing (dword_8B89A0, entry index v2, 19, staged value dword_8B8C50[13]); store the returned int into the global dword_8B78A0 (0x008B78A0). [global:0x008B78A0, source:raw]
    // RETURN: Return dword_8B8C50[0] (the loop bound, re-read each iteration), or the value of dword_8B89A0 (zero) when the entry guard was false. [function:0x0053D450, source:raw]

    // Conservative worker pseudocode:
    //   int ParameterValueBroadcast(int a1) {
    //     if (!dword_8B89A0)
    //       return dword_8B89A0;
    //     dword_8B8C50[13] = a1;
    //     for (int i = 0; i < dword_8B8C50[0]; ++i) {
    //       float *entry = ((float *)&unk_8B8A58) + i * 17;
    //       if (*entry != (float)dword_8B8C50[13]) {
    //         *entry = (float)dword_8B8C50[13];
    //         dword_8B78A0 = (*(int(__stdcall **)(int,int,int,int))(*(int *)dword_8B89A0 + 252))(dword_8B89A0, i, 19, dword_8B8C50[13]);
    //       }
    //     }
    //     return dword_8B8C50[0];
    //   }
    // UNRESOLVED: The indirect call at offset 252 of the dword_8B89A0 object is a vtable-like dispatch; the callee address, class and method semantics are not recoverable from this packet because no direct callee is recorded.
    // UNRESOLVED: The stride of 17 dwords between float entries and the count at dword_8B8C50[0] imply a fixed-size table, but the element structure and the role of the constant 19 argument to the method call are unknown.
    // UNRESOLVED: The relationship between the broadcast value, the per-entry float slots at unk_8B8A58 and the camera-director caller (MainCameraDirectorUpdate) is speculative without evidence of who reads dword_8B78A0 or dword_8B8C50.
    // UNRESOLVED: dword_8B8C50 and dword_8B89A0 have no packet evidence reference of their own; they appear only inside the raw source text.
}
