// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044EAE0
// Canonical corpus name: GlobalStateInitializer_eae0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalStateInitializer_eae0_0044eae0.c

void UnknownObject::GlobalStateBlockInitializer()
{
    // Unconditional one-shot initializer of a contiguous block of six global state words at 0x7CA54C-0x7CA560: writes tag value 96 to 0x7CA54C, zeroes 0x7CA550/0x7CA554/0x7CA558/0x7CA55C, writes 18000 to 0x7CA560, then returns 0. No guards, no calls, and no static callers.
    // ASSIGNMENT: Seed result to 0 before the global writes. [source:raw]
    // ASSIGNMENT: Write the block tag literal 96 to global dword_7CA54C. [global:0x007CA54C, source:raw]
    // ASSIGNMENT: Zero global dword_7CA550. [global:0x007CA550, source:raw]
    // ASSIGNMENT: Zero global dword_7CA554. [global:0x007CA554, source:raw]
    // ASSIGNMENT: Zero global dword_7CA558. [global:0x007CA558, source:raw]
    // ASSIGNMENT: Zero global dword_7CA55C. [global:0x007CA55C, source:raw]
    // ASSIGNMENT: Write the range literal 18000 to global dword_7CA560. [global:0x007CA560, source:raw]
    // RETURN: Return result, which stays 0. [function:0x0044EAE0, source:raw]

    // Conservative worker pseudocode:
    //   int GlobalStateBlockInitializer() {
    //     result = 0;
    //     dword_7CA54C = 96;
    //     dword_7CA550 = 0;
    //     dword_7CA554 = 0;
    //     dword_7CA558 = 0;
    //     dword_7CA55C = 0;
    //     dword_7CA560 = 18000;
    //     return result;
    //   }
    // UNRESOLVED: Semantic roles of the six globals (collision config tag 96, zeroed state fields, and a throttle pedal range 18000) come from the DERIVED skeleton fill and are not independently verifiable from this packet.
    // UNRESOLVED: The function has no known callers or callees; it is a top-level (or indirect-only) one-shot initializer.
}
