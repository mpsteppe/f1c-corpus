// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058C6F0
// Canonical corpus name: Allmul
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Allmul_0058c6f0.c

void UnknownObject::Allmul()
{
    // 64-bit unsigned multiply helper (MSVC compiler RTL _allmul): when either operand's high 32-bit word is non-zero, returns the full 64-bit product a1 * a2; otherwise returns the product of the two low 32-bit halves widened to 64 bits. No fields, globals, guards or callees were recovered in the packet.
    // GUARD: Branch on HIDWORD(a1) | HIDWORD(a2) being non-zero; the branch selects the full 64-bit multiply path. [source:raw]
    // RETURN: Return the full 64-bit product a1 * a2 (slow path, used when either high word is set). [source:raw]
    // RETURN: Return (unsigned int)a2 * (unsigned __int64)(unsigned int)a1 (fast path, 32x32 multiply widened to 64 bits). [source:raw, abi:lead]
    // CALL: Reached from GetSystemTimeAsFileTimeTo64BitTick (0x0058B59F) and sub_58E4D2 (0x0058E4D2) for 64-bit multiplication; consistent with the abi:lead label allmul. [caller:0x0058B59F, caller:0x0058E4D2, function:0x0058C6F0, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   unsigned __int64 __stdcall sub_58C6F0(__int64 a1, __int64 a2) {
    //     if (HIDWORD(a1) | HIDWORD(a2))
    //       return a1 * a2;
    //     return (unsigned int)a2 * (unsigned __int64)(unsigned int)a1;
    //   }
    // UNRESOLVED: Compiler RTL helper: call sites are compiler-generated, so the semantic meaning of the operands is application-dependent.
    // UNRESOLVED: No evidence distinguishes the two callers' intended operand types or signedness.
}
