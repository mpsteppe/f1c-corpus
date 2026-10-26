// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059B260
// Canonical corpus name: sub_59B260
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59B260_0059b260.c

void UnknownObject::VersionedArgumentPackParser()
{
    // Packs four parameters into an argument array, validates/reorders the pack against a version string via ArgumentReorderWrapper, dispatches the pack with mode 4 to sub_5357E0, and on success writes the resulting output pointer to *a2. Cleans up the argument array on every exit path.
    // ASSIGNMENT: Fill the local argument array v8: v8[0]=a3, v8[1]=a4, v8[3]=a1, v8[4]=*a2, v8[8]=0, v8[9]=0. [source:raw]
    // CALL: Invoke ArgumentReorderWrapper(v8, a113_0, 56) to validate and reorder the packed arguments against the version string a113_0. [callee:0x005357C0, global:0x005DA7A0, source:raw]
    // GUARD: If ArgumentReorderWrapper returned non-zero, return that error value immediately without dispatching. [callee:0x005357C0, source:raw]
    // CALL: Dispatch the argument array v8 with mode parameter 4 through sub_5357E0. [callee:0x005357E0, source:raw]
    // GUARD: If sub_5357E0 returned 1 (success), store the parsed result v8[5] into *a2. [callee:0x005357E0, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write the success output: *a2 = v8[5]. [field:this:0x00000000, source:raw]
    // CALL: Success path: release the argument array via GuardedFunctionCallCleanup(v8). [callee:0x00535660, source:raw]
    // CALL: Failure path: release the argument array via GuardedFunctionCallCleanup(v8), then return -5 unless the sub-dispatch error v7 is non-zero, in which case return v7. [callee:0x00535660, source:raw]

    // Conservative worker pseudocode:
    //   v8[0]=a3; v8[1]=a4; v8[3]=a1; v8[4]=*a2; v8[8]=0; v8[9]=0;
    //   err = ArgumentReorderWrapper(v8, a113_0, 56);
    //   if (err) return err;
    //   v7 = sub_5357E0(v8, 4);
    //   if (v7 == 1) { *a2 = v8[5]; GuardedFunctionCallCleanup(v8); return 0; }
    //   GuardedFunctionCallCleanup(v8);
    //   return v7 ? v7 : -5;
    // UNRESOLVED: Semantics of the sub_5357E0 mode-4 dispatch and the format of v8[5] output are not established here.
    // UNRESOLVED: Meaning of the version string a113_0 (reported as "1.13" elsewhere) is not verified from raw evidence in this packet.
}
