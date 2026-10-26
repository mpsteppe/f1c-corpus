// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045BE50
// Canonical corpus name: GlobalStateInitializer_be50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalStateInitializer_be50_0045be50.c

void UnknownObject::GlobalStateInitializer()
{
    // Initializes two adjacent dword globals at 0x007CD208 (zeroing dword_7CD208 and setting dword_7CD20C to -1), then zero-initializes the structure beginning at dword_7CD208 via WideStructZeroInit and returns that call's integer result.
    // ASSIGNMENT: Write 0 to the dword global dword_7CD208. [global:0x007CD208, source:raw]
    // ASSIGNMENT: Write -1 to the adjacent dword global dword_7CD20C. [global:0x007CD20C, source:raw]
    // CALL: Call WideStructZeroInit with the address of dword_7CD208 to zero-initialize the struct at that location. [source:raw]
    // RETURN: Return the integer result of the WideStructZeroInit call. [source:raw]

    // Conservative worker pseudocode:
    //   int GlobalStateInitializer() {
    //     dword_7CD208 = 0;
    //     dword_7CD20C = -1;
    //     return WideStructZeroInit(&dword_7CD208);
    //   }
    // UNRESOLVED: WideStructZeroInit does not appear in the packet callee list, so its address and full behavior are unknown; the call is evidenced only by the raw source.
    // UNRESOLVED: The dword_7CD20C = -1 value likely marks a sentinel or uninitialized index; its exact meaning is unknown.
}
