// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005159C3
// Canonical corpus name: EFLAGSRegisterCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/EFLAGSRegisterCheck_005159c3.c

void UnknownObject::CheckCPUIDAndMMXSupport()
{
    // Detects CPUID support by toggling the EFLAGS ID bit (0x200000) and reading EFLAGS back. If the write sticks (v0 != v1), CPUID is supported: runs CPUID with EAX=1 and returns bit 23 of EDX (mask 0x800000), the MMX feature flag. Otherwise returns the XOR of the two EFLAGS snapshots (0 when unchanged).
    // ASSIGNMENT: Read current EFLAGS into v0 via __readeflags(). [source:raw]
    // CALCULATION: Write EFLAGS with the ID bit toggled: __writeeflags(v0 ^ 0x200000). [source:raw]
    // ASSIGNMENT: Read EFLAGS again into v1 and compute v2 = v0 ^ v1. [source:raw]
    // GUARD: If v0 != v1 the ID bit is writable, so CPUID is supported; otherwise return v2 (0). [source:raw]
    // CALL: Set EAX = 1 and execute the CPUID instruction. [source:raw]
    // RETURN: Return (EDX & 0x800000) >> 23: bit 23 of CPUID.1:EDX, the MMX feature flag. [global:0x00800000, source:raw]
    // RETURN: Return v2 (= 0) when the EFLAGS ID bit is not writable. [caller:0x0050F632, source:raw]

    // Conservative worker pseudocode:
    //   unsigned int CheckCPUIDAndMMXSupport() {
    //     unsigned int v0 = __readeflags();
    //     __writeeflags(v0 ^ 0x200000);
    //     unsigned int v1 = __readeflags();
    //     unsigned int v2 = v0 ^ v1;
    //     if (v0 != v1) {
    //       _EAX = 1;
    //       __asm { cpuid }
    //       return ((unsigned int)&unk_800000 & _EDX) >> 23;
    //     }
    //     return v2;
    //   }
    // UNRESOLVED: The literal 0x800000 is rendered by the decompiler as the address unk_800000 (0x00800000); semantically it is a bitmask on EDX bit 23 (MMX), not a real memory dereference.
    // UNRESOLVED: The MMX labeling of bit 23 is standard CPUID interpretation and DERIVED, not confirmed by the packet alone.
    // UNRESOLVED: The owner and the CPU feature consumer at caller sub_50F632 are unknown.
}
