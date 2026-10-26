// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00477640
// Canonical corpus name: SeasonSceneNameAccessor
// Owner: SeasonSceneNameAccessor [DERIVED]
// Raw source: functions/SeasonSceneNameAccessor_00477640.c

void SeasonSceneNameAccessor::copySeasonSceneNameStrings()
{
    // Copies season scene name strings from a global linked-list element's embedded string table into managed buffers. Calls LinkedListIndexedAccessor_f590 to fetch the indexed element, reads its string table at offset 60, copies the first table entry (falling back to byte_5EA438 when NULL), then copies the entry at index 47 and returns the second copy's result. Returns the raw linked-list result unchanged when either guard fails.
    // CALL: Call LinkedListIndexedAccessor_f590() to retrieve the indexed element from the global linked list; store the returned pointer as result. [callee:0x0048F590, function:0x00477640, source:raw]
    // GUARD: If result is NULL, skip the copy body and fall through to return result. [source:raw]
    // ASSIGNMENT: Read the string table pointer stored at offset 60 of the list element into v1. [source:raw]
    // GUARD: If v1 (the string table) is NULL, skip the copy body and fall through to return result. [source:raw]
    // ASSIGNMENT: Load v2 = *v1, the first string pointer of the table. [source:raw]
    // GUARD: If the first string pointer is NULL, set v2 = byte_5EA438 as a default/fallback string. [global:0x005EA438, source:raw]
    // CALL: Copy the first table string v2 into a managed buffer via StringCopyWithBufferRealloc; this call's return value is discarded. [callee:0x00566650, source:raw]
    // CALL: Copy the string at table element index 47 (pointer v1 advanced by 47 elements) via StringCopyWithBufferRealloc; return its result. [callee:0x00566650, source:raw]
    // RETURN: Return result (the LinkedListIndexedAccessor result) when either guard fails; otherwise return the second StringCopyWithBufferRealloc result. [source:raw]

    // Conservative worker pseudocode:
    //   result = LinkedListIndexedAccessor_f590();
    //   if (result) {
    //       table = *(char***)(result + 60);
    //       if (table) {
    //           src = *table;
    //           if (!src) src = byte_5EA438;
    //           StringCopyWithBufferRealloc(src);
    //           return StringCopyWithBufferRealloc(table + 47);
    //       }
    //   }
    //   return result;
    // UNRESOLVED: dword_7CE64C appears in the existing_analysis globals table but is not referenced anywhere in this function's raw source; no operation can be tied to it.
    // UNRESOLVED: dword_7CE668 appears in the existing_analysis globals table but is not referenced anywhere in this function's raw source; no operation can be tied to it.
    // UNRESOLVED: First StringCopyWithBufferRealloc call's return value is discarded while the second call's return value becomes the function result; the intended use of the discarded copy is unknown.
}
