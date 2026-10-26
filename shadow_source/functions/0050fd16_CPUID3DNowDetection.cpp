// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050FD16
// Canonical corpus name: CPUID3DNowDetection
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CPUID3DNowDetection_0050fd16.c

void UnknownObject::CPUID3DNowDetection()
{
    // CPU 3DNow! capability detection. Queries the maximum extended CPUID function with EAX = 0x80000000; if extended leaf 0x80000001 exists, issues CPUID with that leaf and returns whether bit 31 of EDX (the 3DNow! support flag) is set. Returns 0 when the extended leaf is unsupported. Called by OSVersionDetection (0x0050FDF3).
    // ASSIGNMENT: Set EAX = 0x80000000 and execute CPUID to query the maximum extended function number. [source:raw]
    // CALL: Execute the CPUID instruction (inline asm) with EAX = 0x80000000. [source:raw]
    // GUARD: Guard on returned EAX >= 0x80000001: extended leaf 0x80000001 (feature flags) is available. [source:raw]
    // ASSIGNMENT: Set EAX = -2147483647 to select the extended feature-flags leaf 0x80000001. [source:raw]
    // CALL: Execute the CPUID instruction (inline asm) with EAX = -2147483647. [source:raw]
    // RETURN: Return (_EDX < 0): the sign bit (bit 31) of EDX is the 3DNow! support flag; the BOOL result is per the ABI lead. [source:raw, abi:lead]
    // RETURN: Fallback: return 0 (v11) when extended leaf 0x80000001 is unsupported. [source:raw]
    // CALL: Called by OSVersionDetection (0x0050FDF3) during OS/CPU capability detection. [caller:0x0050FDF3]

    // Conservative worker pseudocode:
    //   BOOL sub_50FD16(void) {
    //     int result = 0;
    //     _EAX = 0x80000000;
    //     cpuid;
    //     if (_EAX >= 0x80000001) {
    //       _EAX = -2147483647;
    //       cpuid;
    //       return _EDX < 0;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Only the 3DNow! bit (EDX bit 31) is tested; other extended feature flags are not consumed here.
    // UNRESOLVED: The ABI lead FAIL_50fd16 has no named prototype; the BOOL return type comes from the raw source.
}
