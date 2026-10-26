// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00423890
// Canonical corpus name: sub_423890
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_423890_00423890.c

void UnknownObject::LoadGameDictionaryFile()
{
    // Loads a game dictionary file: builds the file path from the caller-supplied name (or the game-dictionary global when a3 is null), opens a stream, parses each line into quoted key/value tokens, inserts accepted pairs into the sorted string table owned by 'this', closes the stream, sorts the table entries with a comparator, and finally checks whether the locale string is present, reporting it to a diagnostic routine when it is not found. Returns the count of successfully inserted pairs.
    // ASSIGNMENT: Initialize the inserted-pair counter v4 to 0. [source:raw]
    // GUARD: Guard on a3: when a3 is non-null the path is built from a2 and a3; otherwise from a2 and the aGameDic string. [source:raw, global:0x005C30D0]
    // CALL: Format the path string into v7 with StringFormatWithBufferOverflowCheck using format "%s%s" and components a2 and a3. [callee:0x0058815F, source:raw]
    // CALL: Format the path string into v7 with StringFormatWithBufferOverflowCheck using format "%s%s" and components a2 and the aGameDic string. [callee:0x0058815F, global:0x005C30D0, source:raw]
    // CALL: Open a stream for the built path by calling sub_534B00, returning a stream handle in v5. [callee:0x00534B00, source:raw]
    // GUARD: Guard on the opened stream: when v5 is null the function returns -1 immediately. [source:raw]
    // RETURN: Early return -1 when the stream could not be opened. [source:raw]
    // ASSIGNMENT: Seed the line buffer: v8[0] is set from byte_5EA438 and the remaining 0x1FC bytes of the buffer are zeroed. [global:0x005EA438, source:raw]
    // LOOP: Iterate over every line of the stream while LineInputReader(256) returns true. [callee:0x005351D0, source:raw]
    // CALL: Parse the current line buffer into key and value quoted tokens with StringHashTokenParsing(v8, v12, v11). [callee:0x004236F0, source:raw]
    // GUARD: Guard combining the parse result and insert result: the pair is counted only when parsing succeeds (returns not -1) and SortedStringTableBuilder does not reject it. [source:raw]
    // CALL: Insert the parsed key/value pair into the sorted string table 'this' with SortedStringTableBuilder(this, v12, v11). [callee:0x00423530, source:raw]
    // CALCULATION: Increment the inserted-pair counter v4 when the line yields a successful insert. [source:raw]
    // CALL: Close/dispatch the stream after the read loop with StreamFileTypeCheckWithDispatch(v5). [callee:0x005355A0, source:raw]
    // CALL: Sort the string table via sub_5890AA(this[2], this[1], 16, sub_423830), passing the table's entry-count field (this[1]) and entries-pointer field (this[2]) with a fixed count of 16 and the comparator sub_423830. [callee:0x005890AA, global:0x00423830, field:this:0x00000004, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Clear the search key buffer v7 by setting its first byte to 0. [source:raw]
    // CALL: Search the sorted string table for the OscLocaleString key with BinarySearchInStringTable(aOscLocaleStrin, v7). [callee:0x00423A00, global:0x005C30BC, source:raw]
    // GUARD: Guard on the locale search: when the key is not found and the assembled key string v7 is non-empty, report it. [source:raw]
    // CALL: Report the non-empty, not-found locale key through sub_588A34(2, v7). [callee:0x00588A34, source:raw]
    // RETURN: Return the total count of successfully inserted dictionary pairs. [source:raw]

    // Conservative worker pseudocode:
    //   int LoadGameDictionaryFile(StringTable* table, const char* base, const char* name) {
    //     int count = 0;
    //     char path[128];
    //     if (name) StringFormatWithBufferOverflowCheck(path, "%s%s", base, name);
    //     else     StringFormatWithBufferOverflowCheck(path, "%s%s", base, aGameDic);
    //     void* stream = OpenStream(path);
    //     if (!stream) return -1;
    //     char key[256], value[256], buf[509];
    //     buf[0] = byte_5EA438; memset(buf + 1, 0, 0x1FC);
    //     while (LineInputReader(256)) {
    //       if (StringHashTokenParsing(buf, key, value) != -1 && !SortedStringTableBuilder(table, key, value))
    //         ++count;
    //     }
    //     CloseStream(stream);
    //     SortStringTable(table->entries, table->count, 16, sub_423830);
    //     char search[128]; search[0] = 0;
    //     if (!BinarySearchInStringTable(aOscLocaleStrin, search))
    //       if (strlen(search)) ReportLocaleMissing(2, search);
    //     return count;
    //   }
    // UNRESOLVED: The exact role of globals aRb and aSS is unresolved: neither is named in the raw decompilation, so they are likely constants (file-open mode and path format string) consumed inside the callee chain rather than directly here.
    // UNRESOLVED: Meaning of the fixed count 16 passed to sub_5890AA is unknown; it may be a bucket/section count of the string table.
    // UNRESOLVED: Semantics of the byte_5EA438 seed and the not-found locale-string report path depend on the caller GameFileLoader context.
}
