// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C69E0
// Canonical corpus name: PathFilenameExtractor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PathFilenameExtractor_004c69e0.c

void UnknownObject::PathFilenameExtractor()
{
    // Filename extractor: given an object a1 with an embedded C-string path buffer starting at byte offset 18196, returns a pointer to the filename component. It walks to the end of the string, scans backwards for the last backslash (ASCII 92), and returns the character just after it. A path with no backslash yields the buffer start; an empty buffer yields the buffer start (end == start). Called by NetCommPlayerSlotSync and ProcessDriverEntries path handling.
    // CALCULATION: v1 = a1 + 18196: base of the embedded path string buffer inside the object at a1. [function:0x004C69E0, source:raw]
    // CALCULATION: result = v1 + strlen(v1): advance the cursor to the NUL terminator at the end of the path string. [function:0x004C69E0, source:raw]
    // GUARD: If result > v1 the string is non-empty, so scan for the separator; otherwise skip the scan and return the buffer base. [function:0x004C69E0, source:raw]
    // LOOP: Walk the cursor backwards while *result != 92 (backslash), i.e. until the last path separator is found. [function:0x004C69E0, source:raw]
    // GUARD: If decrementing the cursor would pass the buffer base (--result <= v1), no backslash exists in the path: return the buffer base. [function:0x004C69E0, source:raw]
    // RETURN: return ++result: the character just past the last backslash, i.e. the start of the filename component. [function:0x004C69E0, source:raw]
    // RETURN: Fallthrough return of the cursor: an empty buffer (end == base) returns the buffer base. [function:0x004C69E0, source:raw]

    // Conservative worker pseudocode:
    //   const char* PathFilenameExtractor(void* obj) {
    //       const char* base = obj + 18196;
    //       const char* cursor = base + strlen(base);
    //       if (cursor > base) {
    //           while (*cursor != '\\') {
    //               if (--cursor <= base) return base;
    //           }
    //           return cursor + 1;
    //       }
    //       return cursor;
    //   }
    // UNRESOLVED: Constant 18196 is the byte offset of the embedded path buffer; the owning object type is not established by the packet, so owner stays UNKNOWN.
    // UNRESOLVED: Constant 92 is the ASCII backslash used as the path separator; no evidence states whether forward slashes are ever accepted.
}
