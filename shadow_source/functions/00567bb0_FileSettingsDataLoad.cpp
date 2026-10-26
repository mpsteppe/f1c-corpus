// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00567BB0
// Canonical corpus name: FileSettingsDataLoad
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileSettingsDataLoad_00567bb0.c

void UnknownObject::FileSettingsDataLoad()
{
    // Line-oriented settings/config parser. Loops over input lines supplied by ConditionalDispatchBasedOnFlag(a1, buffer, 512), trimming each via sub_567B10. A leading '{' (0x7B) recurses into a nested section; a leading '}' (0x7D) exits the current section immediately. Otherwise the key string is split at the '.' delimiter found by sub_587C20 (search string asc_5C30AC), the key/value pair is dispatched to FileDataProcessor with the object's base directory at a1[1] (fallback byte_5EA438), and the processor result is carried as v2 into recursive sections. Returns a flag v8 that is 1 once at least one line was read.
    // LOOP: Loop: while ConditionalDispatchBasedOnFlag(a1, v10, 512) reads the next line into the 512-byte buffer v10. [callee:0x00566CC0, source:raw]
    // ASSIGNMENT: On each successful line read set v8 = 1 (line-was-read flag). [source:raw]
    // CALL: Trim/sanitize the line: sub_567B10(v10, v9); processing proceeds only when it returns non-zero. [callee:0x00567B10, source:raw]
    // GUARD: Guard on v9[0] == 123 ('{'): the line opens a nested section. [source:raw]
    // CALL: Nested section: recursive call FileSettingsDataLoad(a1, v2) with the current processor result v2. [callee:0x00567BB0, source:raw]
    // GUARD: Guard on v9[0] == 125 ('}'): the line closes the current section; return v8 immediately. [source:raw]
    // CALL: Find the '.' delimiter in the key: sub_587C20(v9, asc_5C30AC); a null result selects the no-delimiter path. [callee:0x00587C20, global:0x005C30AC, source:raw]
    // ASSIGNMENT: When a delimiter is found, *v3 = 0 truncates the key at it and v5 = v3 + 1 becomes the value pointer. [source:raw]
    // ASSIGNMENT: Load the base directory v4 = a1[1], substituting byte_5EA438 when a1[1] is null. [field:this:0x00000004, global:0x005EA438, source:raw]
    // CALL: Dispatch the parsed pair: FileDataProcessor(v9, key-value-part, base-dir, a2); result stored in v2. [callee:0x00567FB0, source:raw]
    // CALL: No-delimiter path: FileDataProcessor(v9, 0, v6-or-byte_5EA438, a2) dispatches the key with a null value part. [callee:0x00567FB0, source:raw]
    // RETURN: Return v8: 1 if at least one line was read (or a closing brace was reached), 0 if the read loop never ran. [source:raw]

    // Conservative worker pseudocode:
    //   int FileSettingsDataLoad(int* a1, int a2) {
    //     char v10[512]; char v9[512];
    //     int v2 = 0; int v8 = 0;
    //     while (ConditionalDispatchBasedOnFlag(a1, v10, 512)) {
    //       v8 = 1;
    //       if (sub_567B10(v10, v9)) {
    //         if (v9[0] == 123) FileSettingsDataLoad(a1, v2);
    //         else if (v9[0] == 125) return v8;
    //         else {
    //           char* d = sub_587C20(v9, asc_5C30AC);
    //           if (d) { *d = 0; v2 = FileDataProcessor(v9, d+1, a1[1] ? a1[1] : byte_5EA438, a2); }
    //           else v2 = FileDataProcessor(v9, 0, a1[1] ? a1[1] : byte_5EA438, a2);
    //         }
    //       }
    //     }
    //     return v8;
    //   }
    // UNRESOLVED: The meaning of the carried value v2 passed into recursive sections and its relation to the FileDataProcessor return contract is not established.
    // UNRESOLVED: The concrete meaning of the base-directory field a1[1] (this+0x4) and the fallback byte_5EA438 depends on the owner object, which is UnknownObject.
    // UNRESOLVED: The exact config token/format consumed by FileDataProcessor (FileDataProcessor is invoked with a key split at '.' and an optional value part) is not verified here.
}
