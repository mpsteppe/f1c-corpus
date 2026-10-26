// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F8AB0
// Canonical corpus name: ConditionedFloatRead
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionedFloatRead_004f8ab0.c

void UnknownObject::FlaggedFloatAccessor()
{
    // Element-parameterized float accessor with an enable flag. Treats this as a byte buffer and computes an element base at byte offset 32 * a2. If the flag byte at element + 180 is nonzero it returns the float at element + 188 (v2[47]); otherwise it returns 0.0. A short conditional getter.
    // CALCULATION: Element base pointer v2 computed as this + 32 * a2 (byte stride 32 per element) [function:0x004F8AB0, source:raw]
    // GUARD: Enable flag byte at element + 180 decides which value is returned [source:raw]
    // RETURN: When the flag is nonzero, returns the float at element + 188 (v2[47]) [function:0x004F8AB0, source:raw]
    // RETURN: Otherwise returns 0.0 [source:raw]
    // CALL: Used on the frame path by ParticleEffectUpdateDispatch [abi:lead, caller:0x004EB430]

    // Conservative worker pseudocode:
    //   v2 = (float*)&this[32 * a2];
    //   if (*(byte*)((char*)v2 + 180)) return v2[47];
    //   return 0.0;
    // UNRESOLVED: The role of the read-only float global flt_59E440: the packet lists it as read by this function but it does not appear in the decompiled body
    // UNRESOLVED: The exact semantics of the enable flag at element + 180 (enabled state vs. cached/invalid marker) are not defined
}
