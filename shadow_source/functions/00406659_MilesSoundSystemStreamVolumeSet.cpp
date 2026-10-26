// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00406659
// Canonical corpus name: MilesSoundSystemStreamVolumeSet
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MilesSoundSystemStreamVolumeSet_00406659.c

void UnknownObject::MilesSoundSystemStreamVolumeSet()
{
    // Miles audio stream volume-control entry. Calls CorruptedThunk, then dispatches through a vtable-style object in ecx (v2): invokes the method at vtable slot +8 with a1, and only on a non-zero result reads a stream pointer at v2+12. If the stream pointer is non-zero and the volume argument a2 is 0.0, calls the method at vtable slot +12 on the object (stream control path); otherwise calls the AIL_set_stream_volume_levels import with the stream and the volume float read at v2+4, returning the import's result.
    // CALL: CorruptedThunk() invoked at entry [callee:0x00405013, source:raw]
    // ASSIGNMENT: Read the vtable pointer at v2+0 and store the saved return address into v2+4 (decompiler __userpurge frame artifact) [source:raw]
    // CALL: Indirect stdcall call of the method at vtable slot +8 (*(*(v2)+8)) with a1; the result gates the rest of the function [source:raw]
    // GUARD: Only when the slot +8 call result is non-zero is the stream path evaluated; otherwise the function returns that result [source:raw]
    // ASSIGNMENT: Read the stream pointer v6 at v3+12 [source:raw]
    // GUARD: Stream path proceeds only while the stream pointer v6 is non-zero [source:raw]
    // GUARD: When a2 == 0.0 the vtable slot +12 method is dispatched instead of the volume-levels import [source:raw]
    // CALL: Indirect thiscall of the method at vtable slot +12 (*(*(v3)+12)) on v3, returned directly (stream control / mute path) [source:raw]
    // CALL: AIL_set_stream_volume_levels(v6, v3[1], v3[1]) applies the volume float read at v3+4 to both channels of the stream; result returned [global:0x0059E378, source:raw]
    // RETURN: Return the slot +8 result when the stream pointer guard fails [source:raw]
    // CALL: Invoked by sub_5421F6 (005421f6) and sub_563410 (00563410) [caller:0x005421F6, caller:0x00563410, source:raw]

    // Conservative worker pseudocode:
    //   CorruptedThunk();
    //   v3 = v2;
    //   v4 = *(DWORD*)v2;
    //   *(DWORD*)v2 + 1 = retaddr;   /* __userpurge frame artifact * /
    //   result = (*(v4 + 8))(a1);
    //   if (result) {
    //     v6 = *(DWORD*)v3 + 3;
    //     if (v6) {
    //       if (a2 == 0.0)
    //         return (*(*(DWORD*)v3 + 12))(v3);
    //       else
    //         return AIL_set_stream_volume_levels(v6, v3[1], v3[1]);
    //     }
    //   }
    //   return result;
    // UNRESOLVED: The write of the saved return address into v2+4 and the provenance of v2 (ecx-passed __userpurge object) are decompiler artifacts; because v3[1] reads that same slot, the exact volume value passed to AIL_set_stream_volume_levels cannot be trusted
    // UNRESOLVED: The purpose of the vtable slot +12 call versus the AIL import path (mute vs level-set) is inferred, not documented
}
