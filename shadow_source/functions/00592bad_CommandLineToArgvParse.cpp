// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00592BAD
// Canonical corpus name: sub_592BAD
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_592BAD_00592bad.c

void UnknownObject::CommandLineToArgvParse()
{
    // Parses the command line into an argv array using a two-pass parser: after a guarded lazy CRT-singleton init, the module file name is fetched into the global Filename buffer (overridden by the byte-checked global dword_8D5A44 when set), sub_592C46 first counts arguments, the argv table plus string buffer is allocated via MallocWrapperForNhMalloc (terminating via CRTAmsgExit(8) on failure), the second pass fills the buffer, and the argv base and argc (v4 - 1) are stored into globals dword_8D3E88 / dword_8D3E84; argc is returned.
    // GUARD: If the init-guard global dword_8D5A4C is zero, lazy-initialize the CRT singleton first. [global:0x008D5A4C, callee:0x00597218, source:raw]
    // CALL: GetModuleFileNameA(0, Filename, 0x104) retrieves the executable module file name into the 0x104-byte global Filename buffer. [global:0x0059E0EC, global:0x008D40A4, source:raw]
    // ASSIGNMENT: Store the Filename buffer pointer into the global dword_8D3EA0. [global:0x008D3EA0, global:0x008D40A4, source:raw]
    // GUARD: When the byte at dword_8D5A44 is nonzero, use dword_8D5A44 as the command-line source string instead of Filename. [global:0x008D5A44, global:0x008D40A4, source:raw]
    // CALL: First pass: sub_592C46(source, 0, 0, &v4, &v3) counts arguments and required buffer size without writing output. [callee:0x00592C46, source:raw]
    // CALL: MallocWrapperForNhMalloc(v3 + 4 * v4) allocates the argv pointer table plus the string buffer. [callee:0x0058A935, source:raw]
    // GUARD: If the allocation returns null, CRTAmsgExit(8) terminates with the out-of-memory exit code. [callee:0x0058A935, callee:0x0058A2A6, source:raw]
    // CALL: Second pass: sub_592C46(source, v1, v1 + 4 * v4, &v4, &v3) writes the argv pointers and copied strings into the buffer. [callee:0x00592C46, source:raw]
    // ASSIGNMENT: Store the argv array base into dword_8D3E88 and the argument count (v4 - 1) into dword_8D3E84. [global:0x008D3E88, global:0x008D3E84, source:raw]
    // RETURN: Return the argument count (v4 - 1). [source:raw]

    // Conservative worker pseudocode:
    //   int CommandLineToArgvParse(void) {
    //     if (dword_8D5A4C == 0) LazyInitSingletonWithFlagGuard_7218();
    //     GetModuleFileNameA(NULL, Filename, 0x104);
    //     dword_8D3EA0 = (char*)Filename;
    //     char* src = Filename;
    //     if (*(BYTE*)dword_8D5A44) src = (char*)dword_8D5A44;
    //     int argc, size;
    //     sub_592C46(src, 0, 0, &argc, &size);
    //     char* buf = MallocWrapperForNhMalloc(size + 4 * argc);
    //     if (!buf) CRTAmsgExit(8);
    //     sub_592C46(src, buf, buf + 4 * argc, &argc, &size);
    //     dword_8D3E88 = (int)buf;
    //     dword_8D3E84 = argc - 1;
    //     return argc - 1;
    //   }
    // UNRESOLVED: The roles of globals dword_8D3E84 (argc), dword_8D3E88 (argv base) and dword_8D3EA0 (argv pointer) are DERIVED from context; the packet provides no independent proof.
    // UNRESOLVED: dword_8D5A44 is tested as a byte pointer but declared as an int; the meaning of the override source is not established by the packet alone.
    // UNRESOLVED: The relationship to the sole caller sub_58A19E is recorded but not analyzed here.
}
