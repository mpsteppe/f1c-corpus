// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045C000
// Canonical corpus name: sub_45C000
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_45C000_0045c000.c

void UnknownObject::closeHandleIfOpen()
{
    // Guarded handle-close helper: when the byte_7CD26C flag is non-zero, closes the cached handle in dword_7CD264 via CloseHandle and clears it to 0 on success. Returns the flag byte when the flag was clear, otherwise the CloseHandle result.
    // GUARD: Tests the byte_7CD26C flag; the close path only runs while it is non-zero. [global:0x007CD26C, source:raw]
    // CALL: Calls CloseHandle with dword_7CD264 as the handle argument. [global:0x0059E1A8, global:0x007CD264, source:raw]
    // ASSIGNMENT: Clears dword_7CD264 to 0 when CloseHandle returns non-zero. [global:0x007CD264, source:raw]
    // RETURN: Returns the byte flag value when the flag was clear, or the CloseHandle result when the handle was closed. [source:raw]

    // Conservative worker pseudocode:
    //   char result = byte_7CD26C;
    //   if (byte_7CD26C)
    //   {
    //       result = CloseHandle(dword_7CD264);
    //       if (result) dword_7CD264 = 0;
    //   }
    //   return result;
    // UNRESOLVED: The resource protected by the handle dword_7CD264 (and the meaning of the byte_7CD26C flag) is not established by this function alone.
}
