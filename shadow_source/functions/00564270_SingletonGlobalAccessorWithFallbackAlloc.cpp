// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00564270
// Canonical corpus name: SingletonGlobalAccessorWithFallbackAlloc
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SingletonGlobalAccessorWithFallbackAlloc_00564270.c

void UnknownObject::SingletonGlobalAccessorWithFallbackAlloc()
{
    // Singleton/global accessor with a heap-allocation fallback. Saves the incoming value a2 into a byref slot, then asks the callback stored at a1+16 (via CallbackCheck) whether a cached value already exists; if so returns *(v3). Otherwise heap-copies the string value with StringMallocCopy and invokes the same stored callback through FunctionPointerCallWithErrorHandling to install it, returning the resulting value.
    // ASSIGNMENT: v7 = a2 saves the incoming value into the byref stack slot used as both query key and output [source:raw]
    // CALL: CallbackCheck(*(a1 + 16), &v7) asks the callback stored at a1+16 whether a cached value for v7 already exists [callee:0x005647D0, source:raw]
    // GUARD: If CallbackCheck returns a non-null v3, take the early path [callee:0x005647D0, source:raw]
    // RETURN: Return the already-existing value stored at *(v3) without allocating [source:raw]
    // CALL: StringMallocCopy(v7) makes a heap copy of the string value into v5 [callee:0x00564690, source:raw]
    // ASSIGNMENT: Re-read the callback pointer v6 = *(a1 + 16) and stage v7 = v5 as the new candidate value [source:raw]
    // CALL: FunctionPointerCallWithErrorHandling(v6, &v7) invokes the stored callback to install the value, with error handling [callee:0x00564780, source:raw]
    // RETURN: Return v7 as the resulting stored value [function:0x00564270, source:raw]
    // CALL: Invoked by sub_564110 (00564110) and AudioMixerPollingUpdateLoop (00564390), placing this accessor in the audio mixer update path [caller:0x00564110, caller:0x00564390, source:raw]

    // Conservative worker pseudocode:
    //   v7 = a2;
    //   v3 = CallbackCheck(*(a1 + 16), &v7);
    //   if (v3) return *(v3);
    //   v5 = StringMallocCopy(v7);
    //   v6 = *(a1 + 16);
    //   v7 = v5;
    //   FunctionPointerCallWithErrorHandling(v6, &v7);
    //   return v7;
    // UNRESOLVED: a1 is an unknown object whose dword field at byte offset 16 holds a callback pointer; its concrete type is not identified
    // UNRESOLVED: Ownership of the returned pointer and the authority of the stored callback are unresolved
    // UNRESOLVED: The semantic relationship of this accessor to the audio mixer callers beyond being on their call path is not established
}
