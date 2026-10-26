// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00498650
// Canonical corpus name: StringLengthGuardedFieldSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringLengthGuardedFieldSetter_00498650.c

void UnknownObject::StringLengthGuardedFieldSetter()
{
    // If the input string a2 is non-NULL and non-empty, copy it into an internal buffer via StringCopyWithBufferRealloc and store the three integer parameters a3, a4, a5 into adjacent fields at this+0x1560, this+0x1564, this+0x1568, returning a3. If a2 is NULL or empty, the body is skipped and the function returns 0.
    // GUARD: If a2 == NULL, skip the body; result stays 0 and the function returns 0. [source:raw]
    // GUARD: If strlen(a2) == 0, skip the copy and the three field stores; result stays 0 and the function returns 0. [source:raw]
    // CALL: Call StringCopyWithBufferRealloc with the buffer at this+1366 (DWORD units, i.e. this+0x1558) and the input string a2; the buffer is reallocated if necessary. [callee:0x00566650, source:raw]
    // ASSIGNMENT: Store a3 into this+0x1560 (DWORD index 1368). [field:this:0x00001560, source:raw]
    // ASSIGNMENT: Store a4 into this+0x1564 (DWORD index 1369). [field:this:0x00001564, source:raw]
    // ASSIGNMENT: Store a5 into this+0x1568 (DWORD index 1370). [field:this:0x00001568, source:raw]
    // RETURN: Return a3 when the string was valid and copied; otherwise return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int result = 0;
    //   if (a2 != NULL && strlen(a2) > 0) {
    //     StringCopyWithBufferRealloc((int)(this + 1366), a2);
    //     this[1368] = a3;
    //     this[1369] = a4;
    //     this[1370] = a5;
    //     result = a3;
    //   }
    //   return result;
    // UNRESOLVED: Semantic meaning of the three integer fields 0x1560/0x1564/0x1568 is unknown; no packet evidence identifies them.
    // UNRESOLVED: The string buffer base this+0x1558 (from DWORD index 1366) is not represented in the packet field list, so its purpose is only derived from the callee call.
    // UNRESOLVED: No callers exist in the packet, so the lifetime and typical argument values of this setter are unknown.
}
