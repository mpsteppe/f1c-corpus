// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042F140
// Canonical corpus name: StringCopyWithReturn
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringCopyWithReturn_0042f140.c

void UnknownObject::ValidatedStringCopy()
{
    // Looks up string a2 in the owner's string table via BinarySearchInStringTable. On a successful lookup, copies a2 into the this+0xC buffer (or clears the buffer to an empty string when a2 is null). Returns the destination buffer pointer in all paths.
    // ASSIGNMENT: Take the destination buffer pointer as this+0xC. [field:this:0x0000000C, source:raw]
    // CALL: Call BinarySearchInStringTable with the owner, the source string a2, and the destination buffer to validate a2 against the string table. [callee:0x00423A00, source:raw]
    // GUARD: Proceed only when BinarySearchInStringTable returns non-zero (string found); otherwise leave the buffer untouched. [callee:0x00423A00, source:raw]
    // GUARD: When the source string a2 is non-null, copy it into the destination buffer; when a2 is null, write a terminating zero to clear the buffer. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Copy a2 into the this+0xC buffer with strcpy (non-null a2 path), or store an empty string at the buffer start (null a2 path). [field:this:0x0000000C, source:raw]
    // RETURN: Return the destination buffer pointer regardless of lookup outcome. [field:this:0x0000000C, function:0x0042F140, source:raw]

    // Conservative worker pseudocode:
    //   char *ValidatedStringCopy(this, source) {
    //     dest = (char *)(this + 12);
    //     if (BinarySearchInStringTable(this, source, dest)) {
    //       if (source) {
    //         strcpy(dest, source);
    //         return dest;
    //       }
    //       *dest = 0;
    //     }
    //     return dest;
    //   }
    // UNRESOLVED: Semantics of the string table and which caller strings are expected to pass validation are not derivable from this function alone.
}
