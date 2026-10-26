// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053CB20
// Canonical corpus name: MemoryAllocation_cb20
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MemoryAllocation_cb20_0053cb20.c

void UnknownObject::AudioEmitterAllocTryRegister()
{
    // Allocates a 60-byte object, creates an audio emitter from it and stores it at the caller-supplied output slot (this+0x0). Then attempts registration through sub_5429B0(a2, 0, 0, a3, a4); if that call returns 0 the newly created emitter is left intact and the function returns 0, otherwise the created emitter is discarded (EmptyStub_7470 then FreeWrapper_7bcf) and the function returns -1.
    // CALL: Allocates a 60-byte heap object through OperatorNewNhMallocWrapper(60) [callee:0x00587C03, source:raw]
    // GUARD: When the allocation is non-NULL the object is passed to AudioEmitterCreate; when NULL a zero emitter is used [callee:0x005426A0, source:raw]
    // CALL: AudioEmitterCreate initializes the freshly allocated object as an audio emitter [callee:0x005426A0, source:raw]
    // ASSIGNMENT: Stores the created emitter (or 0 on allocation failure) to the caller output slot this+0x0 [field:this:0x00000000, source:raw]
    // CALL: sub_5429B0(a2, 0, 0, a3, a4) attempts registration/validation of the audio emitter [callee:0x005429B0, source:raw]
    // GUARD: When sub_5429B0 returns 0 the function returns 0 immediately, leaving the created emitter intact at this+0x0 [callee:0x005429B0, source:raw]
    // RETURN: Return 0 on registration failure with the emitter object left allocated [function:0x0053CB20, source:raw]
    // GUARD: On successful registration the emitter stored at this+0x0 is non-NULL-checked before cleanup [field:this:0x00000000, source:raw]
    // CALL: EmptyStub_7470 invoked on the emitter before freeing (debug/logging hook) [callee:0x00557470, source:raw]
    // CALL: FreeWrapper_7bcf releases the created emitter heap object [callee:0x00587BCF, source:raw]
    // RETURN: Return -1 after successful registration and cleanup of the freshly created emitter [function:0x0053CB20, source:raw]
    // CALL: Invoked by ShortComputation_4fb0 (00494FB0), CockpitDashboardLEDGaugeSetup (0049CA00), sub_4F9480 (004F9480), sub_552470 (00552470) and sub_55A060 (0055A060) to create an audio emitter at a caller-supplied output slot [caller:0x00494FB0, caller:0x0049CA00, caller:0x004F9480, caller:0x00552470, caller:0x0055A060, source:raw]

    // Conservative worker pseudocode:
    //   obj = OperatorNewNhMallocWrapper(60);
    //   *a1 = obj ? AudioEmitterCreate(obj) : 0;
    //   if (!sub_5429B0(a2, 0, 0, a3, a4)) return 0;
    //   if (*a1) {
    //     EmptyStub_7470(*a1);
    //     FreeWrapper_7bcf(*a1);
    //   }
    //   return -1;
    // UNRESOLVED: The behavior of sub_5429B0 (registration vs validation) is inferred from the caller context only; its return semantics are not documented in this function
    // UNRESOLVED: The function frees the freshly created emitter on registration success and keeps it on failure, which is the inverse of a typical init-on-failure pattern; the intended lifecycle is not verifiable from this packet
    // UNRESOLVED: The meaning of the zero literals passed as sub_5429B0 arguments 2 and 3 is unknown
}
