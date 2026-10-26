// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00587BDC
// Canonical corpus name: CRTFtol
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CRTFtol_00587bdc.c

void UnknownObject::CRTFtol()
{
    // Minimal float-to-int64 conversion helper: returns (__int64)a1 via truncation of the FPU stack value, with the 64-bit result delivered in edx:eax. Matches the MSVC CRT __ftol helper (abi name CRT___ftol). Referenced from many callers across AI, physics, UI and rendering code.
    // CALCULATION: Truncate double a1 to __int64 (CRT ftol conversion). [source:raw]
    // RETURN: Return (__int64)a1 in edx:eax. [source:raw]

    // Conservative worker pseudocode:
    //   return (__int64)a1;
    // UNRESOLVED: Identification as the CRT float-to-int64 (ftol) helper is based on the LEGACY abi name CRT___ftol and the trivial source; the FPU rounding-mode choreography of the real helper is not recoverable from this packet.
    // UNRESOLVED: The function has many callers (per the packet caller list); no single owner or class can be assigned.
}
