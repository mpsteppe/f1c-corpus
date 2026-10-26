// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00592AF4
// Canonical corpus name: sub_592AF4
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_592AF4_00592af4.c

void UnknownObject::CRTEnvironmentParseInit()
{
    // Parses the CRT environment string block (dword_8D3EB4) into an array of pointers to individually allocated environment strings, stores the array in dword_8D3E90, frees the original block, and sets the parsed flag dword_8D5A48. Entries whose first byte is an equals sign are skipped. Lazy-initializes a CRT singleton first if the init guard dword_8D5A4C is unset, and aborts via CRTAmsgExit on any allocation failure.
    // GUARD: If init guard dword_8D5A4C is zero, call the lazy-init singleton routine LazyInitSingletonWithFlagGuard_7218 before parsing. [global:0x008D5A4C, callee:0x00597218]
    // LOOP: Walk the environment block dword_8D3EB4 string by string using Strlen, advancing past each string plus its terminator, and count the entries whose first byte is not the equals sign. [global:0x008D3EB4, callee:0x0058E1B0]
    // ASSIGNMENT: Allocate the pointer array via MallocWrapperForNhMalloc sized for the counted entries plus a terminator and store the pointer into dword_8D3E90. [global:0x008D3E90, callee:0x0058A935]
    // GUARD: If the array allocation failed, terminate via CRTAmsgExit with the out-of-memory code. [callee:0x0058A2A6]
    // LOOP: Second pass over the block: for each entry whose first byte is not an equals sign, allocate a per-string buffer with MallocWrapperForNhMalloc, store it into the array, copy the string via sub_58FCA0, and advance the array slot. [global:0x008D3EB4, callee:0x0058A935, callee:0x0058FCA0, callee:0x0058E1B0]
    // GUARD: If a per-string allocation failed, terminate via CRTAmsgExit with the out-of-memory code. [callee:0x0058A2A6]
    // CALL: Call sub_58AA6F with the original block dword_8D3EB4 to free it. [callee:0x0058AA6F, global:0x008D3EB4]
    // ASSIGNMENT: Clear dword_8D3EB4, write a null terminator after the last array slot, and set the parsed flag dword_8D5A48. [global:0x008D3EB4, global:0x008D5A48]

    // Conservative worker pseudocode:
    //   void CRTEnvironmentParseInit(void) {
    //     int count = 0; char *p; int *out;
    //     if (!dword_8D5A4C) LazyInitSingletonWithFlagGuard_7218();
    //     for (p = dword_8D3EB4; *p; p += Strlen(p) + 1) if (*p != '=') ++count;
    //     out = MallocWrapperForNhMalloc(4 * count + 4);
    //     dword_8D3E90 = out;
    //     if (!out) CRTAmsgExit(9);
    //     for (p = dword_8D3EB4; *p; p += Strlen(p) + 1) {
    //       if (*p != '=') {
    //         *out = MallocWrapperForNhMalloc(Strlen(p) + 1);
    //         if (!*out) CRTAmsgExit(9);
    //         sub_58FCA0();
    //         ++out;
    //       }
    //     }
    //     sub_58AA6F(dword_8D3EB4);
    //     dword_8D3EB4 = 0; *out = 0; dword_8D5A48 = 1;
    //   }
    // UNRESOLVED: sub_58FCA0 has no explicit source argument in the pseudocode; its copy source is assumed to be the current block entry.
    // UNRESOLVED: Whether entries prefixed with an equals sign are hidden environment variables follows CRT convention but is not evidenced by the packet alone.
    // UNRESOLVED: Caller sub_58A19E's exact role in the parse lifecycle is not established.
}
