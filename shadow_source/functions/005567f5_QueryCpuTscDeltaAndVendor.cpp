// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005567F5
// Canonical corpus name: sub_5567F5
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5567F5_005567f5.c

void UnknownObject::QueryCpuTscDeltaAndVendor()
{
    // CPU feature/probing helper. Toggles the EFLAGS ID bit (0x200000) via __writeeflags/__readeflags to detect CPUID support; if the bit flips, CPUID is available. When RDTSC support is present (CPUID leaf 1 EDX bit 0x10), computes the elapsed TSC since the 64-bit base stored in *a1 (high dword) and *a2 (low dword), writing the delta back into those same two dwords. If a3 is non-null, fills a3 with the CPU vendor string from CPUID leaf 0 (EBX/EDX/ECX, 12 bytes, NUL-terminated at +12). Always returns 0.
    // GUARD: CPUID-support probe: toggle EFLAGS bit 0x200000 (ID flag) with __writeeflags and read it back; if v4 != v3 the bit flipped and CPUID is present, otherwise the function skips all CPUID work. [source:raw]
    // CALCULATION: Issue CPUID leaf 1 (EAX=1) and test EDX bit 0x10 (0x10) to check RDTSC support. [source:raw]
    // CALCULATION: Compute elapsed TSC as v11 = __rdtsc() - __PAIR64__(*a1, *a2), i.e. current counter minus the 64-bit base formed from the two stored dwords. [source:raw]
    // ASSIGNMENT: Store the elapsed TSC delta back into the caller's dword pair: *a1 = high dword (HIDWORD), *a2 = low dword (v11). [field:this:0x00000000, source:raw]
    // GUARD: Guard on a3 being non-null; the vendor-string write happens only when a buffer is supplied. [source:raw]
    // ASSIGNMENT: Issue CPUID leaf 0 (EAX=0) and write the vendor string: *(a3) = EBX, *(a3+4) = EDX, *(a3+8) = ECX, then NUL-terminate the 12-byte string at *(a3+12). [source:raw]
    // CALCULATION: Issue CPUID leaf 1 (EAX=1) a second time (final flush of the CPUID sequence). [source:raw]
    // RETURN: Return 0 as the function result. [function:0x005567F5, source:raw]
    // CALL: Called by sub_55F0D0 (0x0055F0D0). [caller:0x0055F0D0]

    // Conservative worker pseudocode:
    //   int QueryCpuTscDeltaAndVendor(unsigned int *a1, unsigned int *a2, void *a3) {
    //     unsigned int before = __readeflags();
    //     __writeeflags(before ^ 0x200000);
    //     unsigned int after = __readeflags();
    //     if (after != before) {
    //       cpuid(1, EDX bit 0x10 must be set for RDTSC);
    //       if (EDX & 0x10) {
    //         __int64 delta = __rdtsc() - ((__int64)*a1 << 32 | *a2);
    //         *a1 = (unsigned int)(delta >> 32);
    //         *a2 = (unsigned int)delta;
    //       }
    //       if (a3) {
    //         cpuid(0);
    //         *(unsigned int*)(a3 + 0) = EBX;
    //         *(unsigned int*)(a3 + 4) = EDX;
    //         *(unsigned int*)(a3 + 8) = ECX;
    //         *(char*)(a3 + 12) = 0;
    //       }
    //       cpuid(1);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The meaning of the 64-bit TSC base in *a1/*a2 (where it is seeded and how the caller consumes the delta) is not established by this packet.
    // UNRESOLVED: The a3 vendor-string buffer role is inferred from the CPUID leaf 0 register writes; caller semantics are unknown.
    // UNRESOLVED: The packet's prelabel (cluster_copy to 004646c0, DERIVED, 'structural twin of FloatClamp') is not corroborated by the raw source, which is a CPUID/RDTSC probe rather than a clamping routine.
    // UNRESOLVED: The packet field this:0x0 RW appears to abstract the *a1/*a2 dword writes; the enclosing object/pointer semantics are unknown.
}
