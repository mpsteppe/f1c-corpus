// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00593115
// Canonical corpus name: sub_593115
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_593115_00593115.c

void UnknownObject::CRTHeapSelect()
{
    // Selects the CRT heap implementation type at runtime. Fast path: returns 1 when GetVersionExA reports platform 2 with major version 5 or later. Otherwise reads the __MSVCRT_HEAP_SELECT environment variable into a 4240-byte buffer, uppercases it, and when it matches __GLOBAL_HEAP_SELECTED compares it against the executable module filename before choosing a heap-selection string. Splits the chosen value at the comma delimiter (0x2C), terminates at any semicolon, and dispatches through CallWrapperWith0, accepting results 1, 2 or 3. Any failed path falls back to PEImageBaseAddressDetection on a 4-byte buffer and returns 3 when the PE linker major version is below 6, else 1.
    // CALL: Sets VersionInformation.dwOSVersionInfoSize to 148 and calls GetVersionExA [global:0x0059E198, source:raw]
    // GUARD: Guard: returns 1 early when GetVersionExA succeeded, dwPlatformId equals 2 and dwMajorVersion is >= 5 [global:0x0059E198, source:raw]
    // CALL: Calls GetEnvironmentVariableA for __MSVCRT_HEAP_SELECT into Buffer with capacity 0x1090 (4240); a zero return skips to the fallback label [global:0x0059E0F4, global:0x005B963C, source:raw]
    // LOOP: Walks Buffer and uppercases any lowercase ASCII letters in place [source:raw]
    // CALL: Compares Buffer against __GLOBAL_HEAP_SELECTED via sub_588640 with length 22 [callee:0x00588640, global:0x005B9624, source:raw]
    // CALL: On a match, gets the module filename via GetModuleFileNameA (capacity 0x104, 260) and uppercases it [global:0x0059E0EC, source:raw]
    // CALL: When the module path matched, calls sub_587C20(Buffer, Filename) to obtain the effective heap-selection string; otherwise v3 stays Buffer [callee:0x00587C20, source:raw]
    // GUARD: Guard: a null v3 jumps to the fallback label [source:raw]
    // CALL: Calls sub_589DB0(v3, 0x2C) to locate the comma delimiter in the selection string; null result jumps to the fallback label [callee:0x00589DB0, source:raw]
    // LOOP: From the byte after the comma, walks forward replacing every semicolon (59) with a string terminator [source:raw]
    // CALL: Dispatches the parsed value through CallWrapperWith0(v7, 0, 10); accepted results are 1, 2 or 3 [callee:0x00589278, source:raw]
    // GUARD: Guard: result not equal to 2, 3 or 1 falls through to the fallback label [source:raw]
    // CALL: Fallback path: calls PEImageBaseAddressDetection on the 4-byte v12 buffer [callee:0x005930E8, source:raw]
    // CALCULATION: Computes the fallback result as 3 when the byte written to the PE-header globals (0xFF00000000005370 and friends, read at 0xFF00000000005371/0xFF00000000005374) is below 6, else 1, returned as 3 - (v12[0] < 6) [global:0xFF00000000005370, global:0xFF00000000005371, global:0xFF00000000005374, source:raw]
    // RETURN: Returns result when it is one of 1, 2 or 3; otherwise returns the computed fallback value [source:raw]
    // CALL: Compiler-generated stack probing (__alloca_probe) for the large local buffers; invoked by sub_59325D [callee:0x005881C0, caller:0x0059325D, source:raw]

    // Conservative worker pseudocode:
    //   VersionInformation.dwOSVersionInfoSize = 148;
    //   if (GetVersionExA(&VersionInformation) && VersionInformation.dwPlatformId == 2 && VersionInformation.dwMajorVersion >= 5)
    //     return 1;
    //   if (!GetEnvironmentVariableA("__MSVCRT_HEAP_SELECT", Buffer, 0x1090)) goto fallback;
    //   for (i in Buffer) *i = toupper(*i);
    //   if (sub_588640("__GLOBAL_HEAP_SELECTED", Buffer, 22)) {
    //     GetModuleFileNameA(0, Filename, 0x104);
    //     for (j in Filename) *j = toupper(*j);
    //     v3 = sub_587C20(Buffer, Filename);
    //   } else v3 = Buffer;
    //   if (!v3) goto fallback;
    //   v6 = sub_589DB0(v3, 0x2C);
    //   if (!v6) goto fallback;
    //   for (p = v6 + 1; *p; ++p) if (*p == ';') *p = 0;
    //   result = CallWrapperWith0(v6 + 1, 0, 10);
    //   if (result == 2 || result == 3 || result == 1) return result;
    //   fallback:
    //     PEImageBaseAddressDetection((int)v12);
    //     return 3 - (v12[0] < 6);
    // UNRESOLVED: The PE-header globals 0xFF00000000005370 (written), 0xFF00000000005371 and 0xFF00000000005374 (read) are recorded in packet facts but do not appear in the raw decompiled source; the byte-vs-major-version mapping is DERIVED and unproven
    // UNRESOLVED: CallWrapperWith0 semantics (which integer selects which heap implementation) are unknown
    // UNRESOLVED: sub_588640, sub_587C20, sub_589DB0 and PEImageBaseAddressDetection are unnamed callees
}
