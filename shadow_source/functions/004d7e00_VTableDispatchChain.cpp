// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D7E00
// Canonical corpus name: VTableDispatchChain_7e00
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VTableDispatchChain_7e00_004d7e00.c

void UnknownObject::VTableDispatchChain()
{
    // Two-stage vtable dispatch on a thiscall object. Calls the check method (vtable slot +0x18, i.e. vtable[6]) and, when it returns non-zero, invokes sub_4D7FE0. Independently, when the byte flag at this+0x8 is non-zero, invokes PhaseBasedAudioParticleEnvelope. Finally dispatches the method at vtable +0x4 (vtable[1]) and returns its result.
    // CALL: Dispatch the check/query method through the vtable pointer stored at this+0x0, at vtable offset +0x18 (slot 6); its non-zero result gates the next call. [field:this:0x00000000, field:obj:0x00000018, source:raw]
    // GUARD: If the check method returned non-zero, invoke sub_4D7FE0(this). [callee:0x004D7FE0, source:raw]
    // CALL: Call sub_4D7FE0(this) when the check method result was non-zero. [callee:0x004D7FE0, source:raw]
    // GUARD: If the flag byte at this+0x8 is non-zero, invoke PhaseBasedAudioParticleEnvelope(this). [field:this:0x00000008, source:raw]
    // CALL: Call PhaseBasedAudioParticleEnvelope(this) when the flag at this+0x8 is set. [callee:0x004D7FF0, source:raw]
    // CALL: Dispatch the final method through the vtable pointer at this+0x0, at vtable offset +0x4 (slot 1); this always executes. [field:this:0x00000000, field:obj:0x00000004, source:raw]
    // RETURN: Return the integer result produced by the final vtable dispatch. [source:raw]

    // Conservative worker pseudocode:
    //   // 0x004D7E00
    //   if (call_vtable_slot(this, 6)) sub_4D7FE0(this);
    //   if (this[8]) PhaseBasedAudioParticleEnvelope(this);
    //   return call_vtable_slot(this, 1);
    // UNRESOLVED: The concrete class behind this vtable is unknown; owner trust is UNKNOWN.
    // UNRESOLVED: The semantics of the check method (+0x18), the conditional sub_4D7FE0, and the final dispatched method (+0x4) are not established.
    // UNRESOLVED: The flag at this+0x8 is read only; who sets it and what PhaseBasedAudioParticleEnvelope does with it are outside this packet.
    // UNRESOLVED: The relative order of the two guards is fixed by the source but their logical relationship (dependent or independent) is not established.
}
