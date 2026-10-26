// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053C680
// Canonical corpus name: ThreeGlobalSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThreeGlobalSetter_0053c680.c

void UnknownObject::ThreeGlobalSetter()
{
    // Trivial setter that copies its three __stdcall arguments into three consecutive writable globals (dword_8B8F08, dword_8B8F0C, dword_8B8F10) and returns the first argument unchanged. No guards, no calls, no field access. Called by VidMan_Enter.
    // ASSIGNMENT: Seed result with the first argument a1. [source:raw]
    // ASSIGNMENT: Store a1 into global dword_8B8F08. [global:0x008B8F08, source:raw]
    // ASSIGNMENT: Store a2 into global dword_8B8F0C. [global:0x008B8F0C, source:raw]
    // ASSIGNMENT: Store a3 into global dword_8B8F10. [global:0x008B8F10, source:raw]
    // RETURN: Return the first argument a1. [function:0x0053C680, source:raw]

    // Conservative worker pseudocode:
    //   int __stdcall sub_53C680(int a1, int a2, int a3) {
    //     int result = a1;
    //     dword_8B8F08 = a1;
    //     dword_8B8F0C = a2;
    //     dword_8B8F10 = a3;
    //     return result;
    //   }
    // UNRESOLVED: Purpose and consumers of the three consecutive globals are not visible in this function.
    // UNRESOLVED: Semantics of the return value (first argument) are caller-defined.
}
