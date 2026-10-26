// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00564390
// Canonical corpus name: AudioMixerPollingUpdateLoop
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioMixerPollingUpdateLoop_00564390.c

void UnknownObject::AudioMixerPollingUpdateLoop()
{
    // Parses a settings-style string beginning at a2+1 into tokens separated by delimiter 92 using StringTokenizer. For each accepted token i, reads the following token (or falls back to the default string byte_5EA438 when absent) and, when sub_564410(i) accepts the token, resolves a singleton object for each of the two values through SingletonGlobalAccessorWithFallbackAlloc on a1 and dispatches a two-argument call through the function pointer stored at a1+12 via FunctionPointerCallWithErrorHandling.
    // CALL: Begin parsing: StringTokenizer(a2 + 1, 92) returns the first token of the stream after the leading byte. [callee:0x00564220, source:raw]
    // LOOP: Iterate while the tokenizer returns a non-null token i; each iteration re-reads the next token and repeats until the tokenizer returns null. [callee:0x00564220, source:raw]
    // CALL: Fetch the following token v5 with StringTokenizer(0, 92) using the continuation mode. [callee:0x00564220, source:raw]
    // GUARD: If the following token v5 is null, fall back to the default string byte_5EA438. [global:0x005EA438, source:raw]
    // GUARD: If sub_564410(i) is true for the current token, run the singleton-lookup and dispatch block. [callee:0x00564410, source:raw]
    // CALL: Resolve the first argument: SingletonGlobalAccessorWithFallbackAlloc(a1, i) stored into v8[0]. [callee:0x00564270, source:raw]
    // CALL: Resolve the second argument: SingletonGlobalAccessorWithFallbackAlloc(a1, v5) stored into v8[1]. [callee:0x00564270, source:raw]
    // CALCULATION: Read the dispatch function pointer v7 from (a1 + 12) on the owner object. [source:raw]
    // CALL: Invoke FunctionPointerCallWithErrorHandling(v7, v8) with the two resolved singleton values. [callee:0x00564780, source:raw]
    // LOOP: Advance the loop: result = StringTokenizer(0, 92); repeat while non-null. [callee:0x00564220, source:raw]
    // RETURN: Return the final tokenizer result (null at loop exit). [source:raw]
    // CALL: Shared helper invoked by sub_563AB0 and sub_564110 as a settings-style string parser. [caller:0x00563AB0, caller:0x00564110, source:raw]

    // Conservative worker pseudocode:
    //   _BYTE *sub_564390(a1, a2) {
    //     result = StringTokenizer((BYTE*)(a2 + 1), 92);
    //     for (i = result; result; i = result) {
    //       v5 = StringTokenizer(0, 92);
    //       if (!v5) v5 = byte_5EA438;
    //       if (sub_564410(i)) {
    //         v8[0] = SingletonGlobalAccessorWithFallbackAlloc(a1, i);
    //         v8[1] = SingletonGlobalAccessorWithFallbackAlloc(a1, (int)v5);
    //         FunctionPointerCallWithErrorHandling(*(DWORD*)(a1 + 12), v8);
    //       }
    //       result = StringTokenizer(0, 92);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Semantics of the parsed tokens and of sub_564410's acceptance test are unknown; the prelabel marks this as a structural twin of SettingsFileInit (004b0930), suggesting settings-style key handling.
    // UNRESOLVED: Role of byte_5EA438 as the default second value is known structurally; its content and meaning are unknown.
    // UNRESOLVED: Owner object a1 and the meaning of the function pointer at a1+12 are unknown.
    // UNRESOLVED: Character identity of delimiter 92 is not confirmed.
}
