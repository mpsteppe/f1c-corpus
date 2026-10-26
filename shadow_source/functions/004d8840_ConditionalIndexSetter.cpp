// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D8840
// Canonical corpus name: ConditionalIndexSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalIndexSetter_004d8840.c

void UnknownObject::ConditionalIndexSetter()
{
    // Conditional index setter. Copies the argument a2 into the result, then writes it into the dword at this+0x4 (this[1]) only when a2 is -1 or the entry tested at this[a2+29] is nonzero; otherwise this[1] is left unchanged. Always returns the original argument a2. Packet prelabel flags it as a structural twin of IntegerSetter (00406b30).
    // ASSIGNMENT: Copy the argument a2 into the result value that will be returned. [source:raw]
    // GUARD: Proceed with the store only when a2 is -1 (short-circuit) or the dword read at this[a2+29] is nonzero; otherwise leave this[1] untouched. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Write the argument a2 into the dword field at this+0x4 (this[1]). [field:this:0x00000004, source:raw]
    // RETURN: Return the original argument a2 to the callers ConditionalSoundRenderDispatchOnParamCheck, PitStateUpdateMachine and LoadingPhase1. [caller:0x00404970, caller:0x004A6E50, caller:0x004B87C0, source:raw]

    // Conservative worker pseudocode:
    //   int ConditionalIndexSetter(_DWORD* this, int a2) {
    //     int result = a2;
    //     if (a2 == -1 || this[a2 + 29])
    //       this[1] = a2;
    //     return result;
    //   }
    // UNRESOLVED: The meaning of the stored index at this+0x4 and of the guard array element this[a2+29] is unknown; the owning class is not established by the packet.
    // UNRESOLVED: The condition semantics (why a2 == -1 bypasses the entry check) are not explained by the packet.
}
