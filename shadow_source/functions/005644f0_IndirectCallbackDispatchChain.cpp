// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005644F0
// Canonical corpus name: DoubleCallWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoubleCallWrapper_005644f0.c

void UnknownObject::IndirectCallbackDispatchChain()
{
    // Fastcall dispatcher that runs an indirect callback stored at a1+16, passing a pointer to a local copy of a2; if that callback returns a non-null pointer, it copies the dereferenced result into a local and runs a second callback stored at a1+12, returning its result. Otherwise returns the null result of the first call.
    // ASSIGNMENT: Copy the second argument a2 into the local parameter slot v5. [source:raw]
    // CALL: Invoke CallbackCheck with the callback pointer stored at a1+16 and the address of the local slot v5; the returned pointer is stored as result. [callee:0x005647D0, source:raw]
    // GUARD: Proceed only when the first CallbackCheck returned a non-null result pointer; otherwise return it as-is. [source:raw]
    // ASSIGNMENT: Read the second callback pointer from a1+12 into v4. [source:raw]
    // ASSIGNMENT: Dereference the first callback's result pointer and store the pointed-to word into the local slot v6. [source:raw]
    // CALL: Invoke CallbackCheck a second time with the second callback pointer (a1+12) and the address of local slot v6, returning its result. [callee:0x005647D0, source:raw]
    // RETURN: Return the null result of the first callback when the guard failed. [source:raw]
    // CALL: Called from sub_5644B0 (0x005644B0), StringComparisonWithConstantDispatch (0x00564530) and AudioMixerSampleGetWithFallback (0x00564580), spanning string-dispatch and audio-mixer fallback paths. [caller:0x005644B0, caller:0x00564530, caller:0x00564580]

    // Conservative worker pseudocode:
    //   v5 = a2;
    //   result = CallbackCheck(*(void**)(a1 + 16), &v5);
    //   if (result) {
    //     v4 = *(_DWORD*)(a1 + 12);
    //     v6 = *result;
    //     return CallbackCheck(v4, &v6);
    //   }
    //   return result;
    // UNRESOLVED: The offsets +12 and +16 on a1 are dereferenced directly but are not declared fields in the packet, so the callback-pointer interpretation is DERIVED from the CallbackCheck call shape
    // UNRESOLVED: Why the first callback's dereferenced result is fed back as the second callback's parameter is not determinable
    // UNRESOLVED: The owner class is unknown
}
