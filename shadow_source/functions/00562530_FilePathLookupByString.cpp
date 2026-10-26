// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00562530
// Canonical corpus name: sub_562530
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_562530_00562530.c

void UnknownObject::FilePathLookupByString()
{
    // Search for a file path matching the input string. Prepends the backslash character to the search string, toggles a global buffer selector, calls sub_587C20 to locate the path, and on success extracts the filename portion (characters after the last backslash) from the located string into one of two alternating file-path buffers.
    // ASSIGNMENT: Read backslash character word_5C2AAC into local v2 and store it as the first word of the local search buffer v9. [source:raw, global:0x005C2AAC, function:0x00562530]
    // CALCULATION: Zero the remainder of the search buffer: memset(&v9[1], 0, 254). [source:raw]
    // ASSIGNMENT: Toggle the file-path buffer selector: dword_8CF080 ^= 1. [source:raw, global:0x008CF080]
    // CALL: Append the input string a2 to the search buffer with strcat((char*)v9, a2). [source:raw]
    // CALCULATION: Write the backslash word v2 over the terminating null of the search string: *(_WORD*)((char*)v9 + strlen(v9)) = v2, so the search string ends with a backslash. [source:raw, global:0x005C2AAC]
    // CALL: Call sub_587C20(a1, v9) to look up the path for the built search string; result v4 is a pointer into located data. [source:raw, callee:0x00587C20]
    // GUARD: If sub_587C20 returned zero (not found), skip extraction and return null. [source:raw, callee:0x00587C20]
    // CALCULATION: Position the filename source: v6 = (char*)(strlen(v9) + v4), past the search string length into the located result. [source:raw]
    // ASSIGNMENT: Select the output buffer: result = (char*)&unk_8CF088 + 256 * dword_8CF080, alternating between the two file-path buffers by the toggled selector. [source:raw, global:0x008CF088, global:0x008CF080]
    // LOOP: Copy characters from the filename source into the output buffer until a null terminator or a backslash (0x5C, 92) is encountered. [source:raw]
    // ASSIGNMENT: Null-terminate the copied filename in the output buffer. [source:raw]
    // RETURN: Return the output buffer pointer (null when the location lookup failed). [source:raw]

    // Conservative worker pseudocode:
    //   char* FilePathLookupByString(int a1, const char* a2) {
    //       WORD backslash = word_5C2AAC;
    //       char search[128];
    //       search[0] = backslash;
    //       memset(search + 1, 0, 254);
    //       dword_8CF080 ^= 1;
    //       strcat(search, a2);
    //       *(WORD*)(search + strlen(search)) = backslash;
    //       char* located = sub_587C20(a1, search);
    //       if (located) {
    //           char* filename = located + strlen(search);
    //           char* out = (char*)&unk_8CF088 + 256 * dword_8CF080;
    //           char* dst = out;
    //           for (char c = *filename; c; ++filename) {
    //               if (c == '\\') break;
    //               *dst = c;
    //               c = filename[1];
    //               ++dst;
    //           }
    //           *dst = 0;
    //           return out;
    //       }
    //       return 0;
    //   }
    // UNRESOLVED: Purpose and full semantics of the dword_8CF080 toggle and the two alternating output buffers at unk_8CF088 are not established.
    // UNRESOLVED: The exact meaning of the sub_587C20 return value (pointer into located path data) and its buffer lifetime are unverified.
    // UNRESOLVED: Writing a 16-bit word (backslash + whatever follows) at the end of the search string suggests the search terminator contract of sub_587C20; the trailing byte's role is unclear.
    // UNRESOLVED: Whether the search string's leading backslash and trailing backslash together encode a directory-style search pattern is unconfirmed.
}
