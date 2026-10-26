// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D9030
// Canonical corpus name: AudioResourceReleaseByType
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioResourceReleaseByType_004d9030.c

void UnknownObject::AudioResourceReleaseByType()
{
    // Releases a render/audio resource selected by type index a1 from a global handle array. A switch on a1 (jump table jpt_4D903E) maps 1-5 to the handle slots dword_8AD398, dword_8AD39C, dword_8AD3A0, dword_8AD3A4 and flt_8AD3A8; a non-null handle is released via ResourceCascadeCleanup and then nulled. Type 3 additionally releases the associated struct dword_8AD3AC through DestructorWithConditionalFreeFlagClear, EmptyStub_7470 and FreeWrapper_7bcf, then nulls it. Values of a1 outside 1-5 are a no-op. Returns the last operated handle value or a1 - 1.
    // CALCULATION: Initialize the default result to a1 - 1, used when a1 selects no case. [source:raw]
    // STATE_TRANSITION: Switch on a1 (jump table jpt_4D903E): case 1 selects &dword_8AD398, case 2 &dword_8AD39C, case 3 &dword_8AD3A0, case 4 &dword_8AD3A4, case 5 &flt_8AD3A8; default is a no-op. [source:raw, global:0x004D90BC, global:0x008AD398, global:0x008AD39C, global:0x008AD3A0, global:0x008AD3A4, global:0x008AD3A8]
    // GUARD: For the selected handle slot, release only if the stored handle *v2 is non-null. [source:raw]
    // CALL: Call ResourceCascadeCleanup(*v2) to run the cascading resource cleanup on the selected handle. [source:raw, callee:0x005539F0]
    // ASSIGNMENT: Null the selected handle slot after cleanup: *v2 = 0. [source:raw]
    // GUARD: Type 3 only: additionally release the extra struct dword_8AD3AC when it is non-null. [source:raw, global:0x008AD3AC]
    // CALL: Call DestructorWithConditionalFreeFlagClear(dword_8AD3AC) to run the struct destructor. [source:raw, callee:0x005502C0, global:0x008AD3AC]
    // GUARD: If dword_8AD3AC is still non-null after the destructor, proceed with the stub and free steps. [source:raw, global:0x008AD3AC]
    // CALL: Call EmptyStub_7470(dword_8AD3AC) then FreeWrapper_7bcf(v3) to deallocate the type-3 extra struct. [source:raw, callee:0x00557470, callee:0x00587BCF, global:0x008AD3AC]
    // ASSIGNMENT: Null the type-3 extra struct global: dword_8AD3AC = 0. [source:raw, global:0x008AD3AC]
    // RETURN: Return result: the last released handle value, or a1 - 1 when no case matched. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4D9030(int type) {
    //     int result = type - 1;
    //     int *slot = 0;
    //     switch (type) {
    //       case 1: slot = &dword_8AD398; break;
    //       case 2: slot = &dword_8AD39C; break;
    //       case 3: slot = &dword_8AD3A0; break;
    //       case 4: slot = &dword_8AD3A4; break;
    //       case 5: slot = (int *)&flt_8AD3A8; break;
    //       default: return result;
    //     }
    //     if (*slot) { result = ResourceCascadeCleanup(*slot); *slot = 0; }
    //     if (type == 3 && dword_8AD3AC) {
    //       result = DestructorWithConditionalFreeFlagClear(dword_8AD3AC);
    //       if (dword_8AD3AC) { EmptyStub_7470(dword_8AD3AC); result = FreeWrapper_7bcf((void *)dword_8AD3AC); }
    //       dword_8AD3AC = 0;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: dword_8AFE64 is listed as a read global of this function but never appears in its raw source; it is likely accessed inside one of the callees (ResourceCascadeCleanup / destructor path).
    // UNRESOLVED: The concrete resource types behind slots 1-5 and the extra struct for type 3 are not established from this packet alone.
}
