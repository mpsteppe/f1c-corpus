// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00543A80
// Canonical corpus name: MemoryAllocationWithFallback
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MemoryAllocationWithFallback_00543a80.c

void UnknownObject::MemoryAllocationWithFallback()
{
    // Two-phase audio emitter allocation with fallback. If a2 is 0, returns 0 immediately. If the flag field this+0xEC has bit 0x4 clear, allocates two 60-byte emitter objects via OperatorNewNhMallocWrapper and constructs them with AudioEmitterCreate, storing the handles in globals dword_8B8DBC and dword_8B8DC0; each is registered via UtilityFunction_2950(dword_8B8DF4, dword_8B8DF4, dword_8B8DF8, 262152) and torn down (EmptyStub_7470 + FreeWrapper_7bcf, handle zeroed) if registration reports failure. Then sub_55B6B0(a2) runs primary stream initialization; if it returns 0, bit 0x10800 is OR'd into this+0xEC and the function returns 0, keeping the fallback emitters. On primary success, each live fallback handle is released via sub_542E50 then freed (EmptyStub_7470 + FreeWrapper_7bcf) and zeroed, and the function returns -1.
    // GUARD: If a2 == 0, return 0 immediately without allocating or initializing. [source:raw]
    // GUARD: If this+0xEC bit 0x4 is clear, enter the fallback allocation branch that creates both audio emitters. [field:this:0x000000EC, source:raw]
    // CALL: First fallback: OperatorNewNhMallocWrapper(60) allocates a 60-byte emitter object; result may be null. [callee:0x00587C03, source:raw]
    // CALL: AudioEmitterCreate(v3) constructs the first audio emitter when the allocation is non-null. [callee:0x005426A0, source:raw]
    // ASSIGNMENT: Store the first emitter handle into global dword_8B8DBC. [global:0x008B8DBC, source:raw]
    // CALL: UtilityFunction_2950(v4, dword_8B8DF4, dword_8B8DF4, dword_8B8DF8, 262152) registers/configures the first emitter; a non-zero return selects the failure cleanup. [callee:0x00542950, global:0x008B8DF4, global:0x008B8DF8, source:raw]
    // GUARD: On registration failure: if dword_8B8DBC is non-null, call EmptyStub_7470 then FreeWrapper_7bcf on it, then zero dword_8B8DBC. [callee:0x00557470, callee:0x00587BCF, global:0x008B8DBC, source:raw]
    // CALL: Second fallback: OperatorNewNhMallocWrapper(60) allocates another 60-byte emitter object; result may be null. [callee:0x00587C03, source:raw]
    // CALL: AudioEmitterCreate(v6) constructs the second audio emitter when the allocation is non-null. [callee:0x005426A0, source:raw]
    // ASSIGNMENT: Store the second emitter handle into global dword_8B8DC0. [global:0x008B8DC0, source:raw]
    // CALL: UtilityFunction_2950(v7, dword_8B8DF4, dword_8B8DF4, dword_8B8DF8, 262152) registers/configures the second emitter; a non-zero return selects the failure cleanup. [callee:0x00542950, global:0x008B8DF4, global:0x008B8DF8, source:raw]
    // GUARD: On registration failure: if dword_8B8DC0 is non-null, call EmptyStub_7470 then FreeWrapper_7bcf on it, then zero dword_8B8DC0. [callee:0x00557470, callee:0x00587BCF, global:0x008B8DC0, source:raw]
    // CALL: sub_55B6B0(a2) attempts primary stream initialization; a zero return selects the fallback retention path. [callee:0x0055B6B0, source:raw]
    // STATE_TRANSITION: If primary init returns 0: OR bit 0x10800 into this+0xEC and return 0, leaving both fallback emitters allocated. [field:this:0x000000EC, source:raw]
    // CALL: On primary success, if dword_8B8DBC is non-null: release it via sub_542E50, then EmptyStub_7470 + FreeWrapper_7bcf, then zero dword_8B8DBC. [callee:0x00542E50, callee:0x00557470, callee:0x00587BCF, global:0x008B8DBC, source:raw]
    // CALL: On primary success, if dword_8B8DC0 is non-null: release it via sub_542E50, then EmptyStub_7470 + FreeWrapper_7bcf, then zero dword_8B8DC0. [callee:0x00542E50, callee:0x00557470, callee:0x00587BCF, global:0x008B8DC0, source:raw]
    // RETURN: Returns 0 when a2 is 0 or when primary init fails; returns -1 on the primary-success path. [function:0x00543A80, source:raw]

    // Conservative worker pseudocode:
    //   if (a2 == 0) return 0;
    //   if ((this[236] & 4) == 0) {
    //       v4 = AudioEmitterCreate(OperatorNewNhMallocWrapper(60));
    //       dword_8B8DBC = (int)v4;
    //       if (UtilityFunction_2950(v4, dword_8B8DF4, dword_8B8DF4, dword_8B8DF8, 262152)) {
    //           EmptyStub_7470(dword_8B8DBC);
    //           FreeWrapper_7bcf((void *)dword_8B8DBC);
    //           dword_8B8DBC = 0;
    //       }
    //       v7 = AudioEmitterCreate(OperatorNewNhMallocWrapper(60));
    //       dword_8B8DC0 = (int)v7;
    //       if (UtilityFunction_2950(v7, dword_8B8DF4, dword_8B8DF4, dword_8B8DF8, 262152)) {
    //           EmptyStub_7470(dword_8B8DC0);
    //           FreeWrapper_7bcf((void *)dword_8B8DC0);
    //           dword_8B8DC0 = 0;
    //       }
    //   }
    //   if (!sub_55B6B0(a2)) {
    //       *((_DWORD *)this + 59) |= 0x10800u;
    //       return 0;
    //   }
    //   if (dword_8B8DBC) {
    //       sub_542E50((_DWORD *)dword_8B8DBC);
    //       EmptyStub_7470(dword_8B8DBC);
    //       FreeWrapper_7bcf((void *)dword_8B8DBC);
    //       dword_8B8DBC = 0;
    //   }
    //   if (dword_8B8DC0) {
    //       sub_542E50((_DWORD *)dword_8B8DC0);
    //       EmptyStub_7470(dword_8B8DC0);
    //       FreeWrapper_7bcf((void *)dword_8B8DC0);
    //       dword_8B8DC0 = 0;
    //   }
    //   return -1;
    // UNRESOLVED: Both fallback emitters are registered with the same parameter set (dword_8B8DF4 passed twice, then dword_8B8DF8) and the same mode constant 262152; their distinct stream roles are not distinguishable from this packet.
    // UNRESOLVED: The trigger for allocating the fallbacks (this+0xEC bit 0x4) is read but its writers are outside this function; the meaning of the two flag bits (0x4 and 0x10800) is not established here.
    // UNRESOLVED: EmptyStub_7470 is called with the same handle that sub_542E50 or FreeWrapper_7bcf consumes; the exact side effects and ordering requirements of the stub relative to release/free are unknown from this packet.
}
