// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F9420
// Canonical corpus name: sub_4F9420
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4F9420_004f9420.c

void UnknownObject::CoordinateSearchResultStore()
{
    // Searches coordinate tables via MultiTableCoordinateSearch(a1, a2, a3, a4); on success stores the input tuple and the returned index into five globals and returns 0; on search failure (negative result) returns 1 without storing. Called by VidMan_Enter.
    // CALL: Invoke MultiTableCoordinateSearch(a1, a2, a3, a4); result captured in local v4. [callee:0x004F9240]
    // GUARD: If search result v4 is negative, treat the coordinate lookup as failed. [source:raw]
    // RETURN: Return 1 when the coordinate search reports no match. [function:0x004F9420]
    // ASSIGNMENT: Store input a1 into dword_5D6D60 (first match coordinate). [global:0x005D6D60]
    // ASSIGNMENT: Store input a2 into dword_5D6D64 (second match coordinate). [global:0x005D6D64]
    // ASSIGNMENT: Store input a3 into dword_5D6D68 (third match coordinate). [global:0x005D6D68]
    // ASSIGNMENT: Store search result index v4 into dword_8AFE74. [global:0x008AFE74]
    // ASSIGNMENT: Store input a4 into dword_8AFE78 (fourth match coordinate). [global:0x008AFE78]
    // RETURN: Return 0 when the match was found and the globals were stored. [function:0x004F9420]

    // Conservative worker pseudocode:
    //   result = MultiTableCoordinateSearch(a1, a2, a3, a4);
    //   if (result < 0) return 1;
    //   dword_5D6D60 = a1; dword_5D6D64 = a2; dword_5D6D68 = a3;
    //   dword_8AFE74 = result; dword_8AFE78 = a4;
    //   return 0;
    // UNRESOLVED: Purpose of the five stored globals beyond caching a coordinate lookup is not established.
    // UNRESOLVED: Relationship of caller VidMan_Enter to the coordinate cache is outside this function's scope.
}
