// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005171D0
// Canonical corpus name: sub_5171D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5171D0_005171d0.c

void UnknownObject::DetectCpuCapabilities()
{
    // Free function that detects x86 CPU features via the CPUID instruction and returns a feature-flag bitmask. Runs CPUID leaf 0 to obtain the vendor string (EBX/EDX/ECX), leaf 1 to test the EDX MMX bit (0x800000), then the extended leaves 0x80000000/-2147483647 to probe extended-function availability and the EDX sign bit (3DNow-class). When the vendor string matches 'AuthenticAMD', sets two additional AMD-specific EDX bits (0x40000000 and 0x400000). Called by sub_5172A5.
    // ASSIGNMENT: Initialize the two local string buffers via strcpy: v27 = 'UnknownVendr' (from aUnknownvendr at 0x005AFA10) and v26 = 'AuthenticAMD' (from aAuthenticamd at 0x005AFA00). [global:0x005AFA10, global:0x005AFA00, source:raw]
    // CALL: Execute CPUID leaf 0 (EAX=0); initialize result flag v28 to 1, then store the returned vendor string into v27: v27[0]=EBX, v27[1]=EDX, v27[2]=ECX. [source:raw]
    // GUARD: Proceed only if the value returned in EAX from CPUID leaf 0 is non-zero (maximum supported leaf). [source:raw]
    // CALL: Execute CPUID leaf 1 (EAX=1); store EAX into v27[4] and accumulate feature flags into v28: v28 |= 2, and v28 |= 0x20 when EDX bit 23 (0x800000, MMX-class) is set. [global:0x00800000, source:raw]
    // CALL: Execute CPUID leaf 0x80000000 (EAX=0x80000000) to query the maximum extended function number. [source:raw]
    // GUARD: Proceed if the extended maximum leaf exceeds 0x80000000; then set v28 |= 4, execute CPUID with EAX=-2147483647, and set v28 |= 0x80 when the returned EDX is negative (bit 31, 3DNow-class). [source:raw]
    // GUARD: If memcmp(v26, v27, 0xC) == 0 (the CPUID vendor string equals 'AuthenticAMD'), set v28 |= 0x100 when EDX bit 30 (0x40000000) is set and return v28 | (EDX bit 22 (0x400000) ? 0x200 : 0). [source:raw]
    // RETURN: Return the accumulated feature-flag bitmask v28. [caller:0x005172A5, function:0x005171D0, source:raw]

    // Conservative worker pseudocode:
    //   int DetectCpuCapabilities() {
    //     char vendor[16] = "UnknownVendr";
    //     char expectedAmd[16] = "AuthenticAMD";
    //     int flags = 1;
    //     cpuid(0, &eax, &ebx, &ecx, &edx);
    //     vendor[0] = ebx; vendor[4] = edx; vendor[8] = ecx;
    //     if (eax) {
    //       cpuid(1, &eax, &ebx, &ecx, &edx);
    //       flags |= 2 | ((edx & 0x800000) ? 0x20 : 0);
    //       cpuid(0x80000000, &eax, &ebx, &ecx, &edx);
    //       if (eax > 0x80000000) {
    //         flags |= 4;
    //         cpuid(-2147483647, &eax, &ebx, &ecx, &edx);
    //         flags |= (edx & 0x80000000) ? 0x80 : 0;
    //         if (memcmp(expectedAmd, vendor, 12) == 0) {
    //           flags |= (edx & 0x40000000) ? 0x100 : 0;
    //           return flags | ((edx & 0x400000) ? 0x200 : 0);
    //         }
    //       }
    //     }
    //     return flags;
    //   }
    // UNRESOLVED: Precise meaning of each returned flag bit (0x02, 0x20, 0x04, 0x80, 0x100, 0x200) is inferred from standard CPUID feature semantics, not confirmed by runtime evidence.
    // UNRESOLVED: The literal 0x800000 was resolved by the decompiler as the address unk_800000; semantically it is an EDX bitmask test (bit 23), not a real memory reference.
    // UNRESOLVED: The vendor-string buffer v27 and AMD-detection string v26 relationship is clear, but why non-AMD CPUs return before setting the 0x100/0x200 bits is only inferred.
}
