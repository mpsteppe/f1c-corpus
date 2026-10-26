// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046AD50
// Canonical corpus name: MessageNameBufferUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MessageNameBufferUpdate_0046ad50.c

void UnknownObject::MessageNameBufferUpdate()
{
    // Builds a display string for a menu entry from an action index: retrieves the module pointer from the ppvOut array and the action name from the dword_7D1B08 table (stride 7), copies the module name into the shared display buffer byte_5EC4CC when present in the string table, concatenates the module and action path into the caller's output buffer, and optionally creates a UI menu item when the a3 flag is set.
    // CALL: Retrieve the module pointer for index a1 from the ppvOut array via ArrayIndexedAccessor. [callee:0x00455560, global:0x007CA590, source:raw]
    // CALL: Retrieve the action name string from the dword_7D1B08 table entry at index 7 * a1 via sub_455260. [callee:0x00455260, global:0x007D1B08, source:raw]
    // GUARD: Guard that both the module pointer and the caller's output buffer a2 are non-null; if either is null the build path is skipped and only the flag is returned. [source:raw]
    // CALL: When the module name is found in the string table by BinarySearchInStringTable, copy it into the shared display buffer byte_5EC4CC. [callee:0x00423A00, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // CALL: Copy byte_5EC4CC into the output buffer a2 and normalise it with StrlenOverwrite. [callee:0x004894D0, global:0x005EC4CC, source:raw]
    // CALL: When an action name exists, look it up in the string table via BinarySearchInStringTable and copy it into byte_5EC4CC; otherwise fall back to the default path byte_5EA438. [callee:0x00423A00, global:0x005EC4CC, global:0x005EA438, source:raw]
    // ASSIGNMENT: Append the action path to the output buffer with strcat and prepare the return value as the a3 flag. [source:raw]
    // CALL: When the a3 flag is set, create the UI menu item from the built string via UIMenuItemCreator. [callee:0x00489600, source:raw]
    // RETURN: Return the a3 flag (as a char) indicating whether a UI menu item was created. [source:raw]
    // CALL: Called by SessionEntryListCleanup (0x0046AE60) to build menu item display strings for session entries. [caller:0x0046AE60, source:raw]

    // Conservative worker pseudocode:
    //   char MessageNameBufferUpdate(int index, char *out, char createItem) {
    //     module = ArrayIndexedAccessor(&ppvOut, index);
    //     action = sub_455260(&dword_7D1B08[7 * index]);
    //     if (module && out) {
    //       if (BinarySearchInStringTable(byte_5EC4C0, module, byte_5EC4CC)) strcpy(byte_5EC4CC, module);
    //       strcpy(out, byte_5EC4CC);
    //       StrlenOverwrite(out);
    //       if (action) {
    //         if (BinarySearchInStringTable(byte_5EC4C0, action, byte_5EC4CC)) strcpy(byte_5EC4CC, action);
    //         path = byte_5EC4CC;
    //       } else {
    //         path = byte_5EA438;
    //       }
    //       strcat(out, path);
    //       if (createItem) UIMenuItemCreator(out, 0, 0, 0, 0);
    //     }
    //     return createItem;
    //   }
    // UNRESOLVED: The element type of ppvOut and the layout of the dword_7D1B08 table (stride 7) are taken from the indexing arithmetic; neither container is named.
    // UNRESOLVED: The string table semantics of BinarySearchInStringTable (search/insert behaviour) are inferred from the copy guards.
    // UNRESOLVED: byte_5EA438 is used as a fallback path but its content is not visible from this function.
}
