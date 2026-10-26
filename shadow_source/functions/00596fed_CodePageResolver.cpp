// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00596FED
// Canonical corpus name: sub_596FED
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_596FED_00596fed.c

void UnknownObject::CodePageResolver()
{
    // Resolves a code-page identifier to an actual Windows code page. Identifier 0xFFFFFFFE maps to the OEM code page via GetOEMCP, 0xFFFFFFFD maps to the ANSI code page via GetACP, and 0xFFFFFFFC maps to the stored default CodePage global. The global auto-flag dword_8D41D4 is cleared first and set to 1 whenever a special identifier is resolved; any other identifier passes through unchanged with the flag left at 0. Invoked from sub_596E40.
    // ASSIGNMENT: Initialize result = a1 so a non-matching identifier passes through unchanged. [source:raw]
    // ASSIGNMENT: Clear the global auto-flag dword_8D41D4 = 0 before dispatching on the identifier. [global:0x008D41D4, source:raw]
    // GUARD: Case 0xFFFFFFFE (OEM): set dword_8D41D4 = 1 and return the result of GetOEMCP(). [global:0x008D41D4, global:0x0059E088, source:raw]
    // GUARD: Case 0xFFFFFFFD (ANSI): set dword_8D41D4 = 1 and return the result of GetACP(). [global:0x008D41D4, global:0x0059E08C, source:raw]
    // GUARD: Case 0xFFFFFFFC (default): read result = CodePage (the stored default code page) and set dword_8D41D4 = 1. [global:0x008D3F48, global:0x008D41D4, source:raw]
    // RETURN: Return result: the resolved code page for a special identifier, otherwise the unchanged input. [source:raw]

    // Conservative worker pseudocode:
    //   UINT CodePageResolver(UINT a1) {
    //     UINT result = a1;
    //     dword_8D41D4 = 0;
    //     switch (a1) {
    //       case 0xFFFFFFFE: dword_8D41D4 = 1; return GetOEMCP();
    //       case 0xFFFFFFFD: dword_8D41D4 = 1; return GetACP();
    //       case 0xFFFFFFFC: result = CodePage; dword_8D41D4 = 1; break;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The semantic meaning of dword_8D41D4 (a caller-visible auto-select flag) is inferred from it being set on every special identifier; the consumer that reads it is outside this packet.
    // UNRESOLVED: The source of the stored default CodePage value is not determinable from this packet.
    // UNRESOLVED: GetOEMCP and GetACP are called at fixed addresses (0x0059E088 / 0x0059E08C); the packet does not identify whether these are import thunks or function pointers.
}
