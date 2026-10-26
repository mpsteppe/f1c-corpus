// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00564110
// Canonical corpus name: sub_564110
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_564110_00564110.c

void UnknownObject::processTokenizedServerEntries()
{
    // Allocates a target struct via StructAllocInitWithSwitchBasedType(a4, a5), then tokenizes the path string a3 on a backslash delimiter (first token via StringTokenizer(a3+1, '\')). Iterates a2 entries against the lookup array a1: when the entry string equals aIp_0 ("ip") the token is parsed by NetworkAddressParser(v6, token); when a4 == 6 and the entry equals aOther ("other") the token's 0x01 bytes are rewritten to backslashes and AudioMixerPollingUpdateLoop(v6, token) runs; otherwise two singleton values are fetched via SingletonGlobalAccessorWithFallbackAlloc(v6) and dispatched through the function pointer at v6+12 via FunctionPointerCallWithErrorHandling. A null token falls back to the default path byte_5EA438. Returns the allocated struct v6.
    // CALL: Allocate and initialize the target struct via StructAllocInitWithSwitchBasedType(a4, a5); result stored in v6. [callee:0x005642F0]
    // CALL: StringTokenizer(a3+1, '\') splits the path string on a backslash delimiter; the first token is stored in v8. [callee:0x00564220, source:raw]
    // LOOP: Iterate while index < a2; each pass consumes one token, advancing via StringTokenizer(0, '\') until the count is reached. [source:raw]
    // ASSIGNMENT: When the tokenizer returns null for a slot, fall back to the default path byte_5EA438. [global:0x005EA438]
    // GUARD: If the entry at a1 + 4*index equals aIp_0 ("ip"), parse the token as a network address via NetworkAddressParser(v6, token). [global:0x005E5050, callee:0x005642B0]
    // GUARD: Else if a4 == 6 and the entry equals aOther ("other"), rewrite 0x01 bytes in the token to backslashes and run AudioMixerPollingUpdateLoop(v6, token). [global:0x005E5048, callee:0x00564390]
    // CALL: Otherwise fetch two singleton values via SingletonGlobalAccessorWithFallbackAlloc(v6) and dispatch through the function pointer at v6+12 with FunctionPointerCallWithErrorHandling. [callee:0x00564270, callee:0x00564780]
    // RETURN: Return the allocated target struct v6. [source:raw]

    // Conservative worker pseudocode:
    //   int processTokenizedServerEntries(char** entries, int count, char* path, int type, int unused) {
    //     void* target = StructAllocInitWithSwitchBasedType(type, unused);
    //     char* token = StringTokenizer(path + 1, '\\');
    //     for (int i = 0; i < count; i++) {
    //       if (!token) token = byte_5EA438;
    //       if (!strcmp(entries[i], aIp_0)) {
    //         NetworkAddressParser(target, token);
    //       } else if (type == 6 && !strcmp(entries[i], aOther)) {
    //         for (char* p = token; *p; p++) if (*p == 1) *p = '\\';
    //         AudioMixerPollingUpdateLoop(target, token);
    //       } else {
    //         void* args[2];
    //         args[0] = SingletonGlobalAccessorWithFallbackAlloc(target);
    //         args[1] = SingletonGlobalAccessorWithFallbackAlloc(target);
    //         FunctionPointerCallWithErrorHandling(*(void**)(target + 12), args);
    //       }
    //       token = StringTokenizer(0, '\\');
    //     }
    //     return (int)target;
    //   }
    // UNRESOLVED: Semantic meaning of the a4 type selector (especially the value 6) and the function-pointer contract at v6+12 are unknown.
    // UNRESOLVED: The exact content of the string literals aIp_0 and aOther ("ip" / "other") is inferred from symbol names, not verified.
    // UNRESOLVED: Why the 'other' branch rewrites 0x01 bytes to backslashes before AudioMixerPollingUpdateLoop is unknown.
}
