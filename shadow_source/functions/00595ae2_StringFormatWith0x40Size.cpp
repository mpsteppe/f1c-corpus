// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00595AE2
// Canonical corpus name: StringFormatWith0x40Size
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringFormatWith0x40Size_00595ae2.c

void UnknownObject::StringFormatWith0x40Size()
{
    // Forwarding wrapper (cdecl): calls sub_595AF9 (0x00595AF9) with lpFileName, a2, the fixed size argument 64, and a3, then returns its result. The third argument is pinned to 64, matching a 0x40-byte format-buffer size. Used by ShortComputation_5050 (0x00405050), sub_4069F0 (0x004069F0) and RegistryKeyQuery (0x00449A20).
    // CALL: Call sub_595AF9 (0x00595AF9) with lpFileName, a2, 64, a3, fixing the format-buffer size argument to 64. [callee:0x00595AF9, source:raw]
    // RETURN: Return the result of sub_595AF9(lpFileName, a2, 64, a3). [source:raw]
    // CALL: Called by ShortComputation_5050 (0x00405050), sub_4069F0 (0x004069F0) and RegistryKeyQuery (0x00449A20) to format into a fixed 0x40-size buffer. [caller:0x00405050, caller:0x004069F0, caller:0x00449A20, source:raw]

    // Conservative worker pseudocode:
    //   int sub_595AE2(LPCSTR lpFileName, int a2, int a3) {
    //     return sub_595AF9(lpFileName, a2, 64, a3);
    //   }
    // UNRESOLVED: Meaning of a2 and a3 depends on sub_595AF9's contract; the only fixed argument evidenced here is the size 64.
}
