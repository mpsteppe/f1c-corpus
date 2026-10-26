// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00470F20
// Canonical corpus name: RaceSessionModeDataLoader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RaceSessionModeDataLoader_00470f20.c

void UnknownObject::RaceSessionModeDataLoader()
{
    // Computes a session-mode table address as 36 * dword_7D0410 + 8188032 and stores it at this[206] (+0x338), then stores the mode value dword_7D0410 at this[200] (+0x320). If the computed address is non-null, dereferences it, retrieves a UI list item via UIListIndexedAccessor, formats it into a stack buffer through StringFormatWithBufferOverflowCheck, and returns the result of EditBufferStringUpdate on that buffer. If the address is null, returns it immediately. Reads session-mode global dword_7D0410.
    // CALCULATION: result = 36 * dword_7D0410 + 8188032; compute the table entry address from the session-mode value (36-byte stride over a table anchored at 8188032). [global:0x007D0410, function:0x00470F20, source:raw]
    // ASSIGNMENT: this[206] = result; store the computed table address at this+0x338. [field:this:0x00000338, function:0x00470F20, source:raw]
    // GUARD: if (result) — proceed only when the computed table address is non-null; otherwise fall through to the return of result (0). [function:0x00470F20, source:raw]
    // ASSIGNMENT: this[200] = dword_7D0410; store the session-mode value at this+0x320. [field:this:0x00000320, global:0x007D0410, function:0x00470F20, source:raw]
    // CALL: v4 = UIListIndexedAccessor(*v3) where v3 is the stored table address this[206]; read the first dword of the table entry and fetch the indexed UI list item from it. [field:this:0x00000338, callee:0x00487010, function:0x00470F20, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(v5, v4); format the UI list item into the 32-byte stack buffer v5 with overflow checking. [callee:0x0058815F, function:0x00470F20, source:raw]
    // CALL: return EditBufferStringUpdate(v5); commit the formatted buffer to the edit buffer and return its result. [callee:0x0048B810, function:0x00470F20, source:raw]
    // RETURN: return result; when the computed address was null, return it (0) without touching the UI list. [function:0x00470F20, source:raw]

    // Conservative worker pseudocode:
    //   result = 36 * dword_7D0410 + 8188032;
    //   this[206] = result;
    //   if (result) {
    //     this[200] = dword_7D0410;
    //     v4 = UIListIndexedAccessor(*this[206]);
    //     StringFormatWithBufferOverflowCheck(v5, v4);
    //     return EditBufferStringUpdate(v5);
    //   }
    //   return result;
    // UNRESOLVED: The table base 8188032 and the 36-byte stride imply a session-mode record table, but the record layout is not evidenced.
    // UNRESOLVED: The owner object and the semantic roles of this+0x320 and this+0x338 beyond the mode/table storage are DERIVED from existing analysis, not packet-proven.
    // UNRESOLVED: The return of EditBufferStringUpdate is presumed a status code; its range is unknown.
}
