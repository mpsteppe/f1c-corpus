// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044CB14
// Canonical corpus name: GlobalInitializer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalInitializer_0044cb14.c

void UnknownObject::GlobalInitializer()
{
    // Trivial void global-initializer. Stores the constant -1082130432 into dword_7CCFE4 and 0.0 into flt_7CCFE8. No parameters, no guards, no calls, no return value.
    // ASSIGNMENT: Write the constant -1082130432 into global dword_7CCFE4 [global:0x007CCFE4, source:raw]
    // ASSIGNMENT: Write the constant 0.0 into global flt_7CCFE8 [global:0x007CCFE8, source:raw]
    // RETURN: Returns void immediately after the two stores [function:0x0044CB14, source:raw]

    // Conservative worker pseudocode:
    //   void GlobalInitializer() {
    //     dword_7CCFE4 = -1082130432;
    //     flt_7CCFE8 = 0.0;
    //   }
    // UNRESOLVED: The role of the two globals and the intended meaning of the -1082130432 constant are not evidenced by this packet
}
