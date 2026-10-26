// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053CFE0
// Canonical corpus name: sub_53CFE0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_53CFE0_0053cfe0.c

void UnknownObject::ResourceCacheLookupOrAllocInit()
{
    // String-keyed resource registry lookup-or-create. Copies the filename argument into a stack buffer, transforms it with sub_589901, and strips the file extension by scanning backward for a '.' and null-terminating there. Walks the global registry linked list headed at dword_8B8E20, comparing the stored name (node+20) with the stripped string; the next-node pointer lives at node+2160. On a match it writes the node into *a1 (when a1 is non-null) and returns 0. On no match it allocates a 2164-byte entry via OperatorNewNhMallocWrapper and initializes it with HashTable; if sub_552470(a2, a3) reports registration failure (non-zero) the entry is cleaned up with EmptyStub_7470 and FreeWrapper_7bcf and -1 is returned; otherwise the entry is appended via LinkedListAppend_d340, written to *a1, and 0 is returned.
    // CALL: strcpy(SrcStr, a2) copies the input filename into the 256-byte stack buffer. [source:raw]
    // CALL: sub_589901(SrcStr) transforms the buffer before comparison. [callee:0x00589901, source:raw]
    // CALCULATION: Extension strip: scan backward from strlen(SrcStr)-1 while the byte is not '.' (0x2E); when found, truncate at that position; scan only while the index stays above 0. [source:raw]
    // LOOP: Walk the registry from the global head dword_8B8E20 while strcmp(node+20, SrcStr) is non-zero, advancing through the next-node pointer at node+2160; loop guard requires a non-null head. [global:0x008B8E20, source:raw]
    // ASSIGNMENT: On a name match, write the found node into *a1 when a1 is non-null. [field:this:0x00000000, source:raw]
    // CALL: On no match, OperatorNewNhMallocWrapper(2164) allocates a new registry entry. [callee:0x00587C03, source:raw]
    // CALL: HashTable(v5) initializes the new entry's internal table when allocation succeeded. [callee:0x005523E0, source:raw]
    // GUARD: sub_552470(a2, a3) == 0 selects the registration-success path; a non-zero result selects the failure/cleanup path. [callee:0x00552470, source:raw]
    // CALL: On registration success, LinkedListAppend_d340(entry) appends it to the registry and the entry is written into *a1 when a1 is non-null. [callee:0x0053D340, field:this:0x00000000, source:raw]
    // CALL: On registration failure, EmptyStub_7470(entry) then FreeWrapper_7bcf(entry) clean up the allocated entry. [callee:0x00557470, callee:0x00587BCF, source:raw]
    // RETURN: Return 0 on found or appended entries, -1 when registration failed. Used by collision node allocation, cockpit gauge setup and scene-file parsing paths. [caller:0x00494DE0, caller:0x0049CA00, caller:0x004D8AB0, caller:0x004F8D70, caller:0x0055B200, function:0x0053CFE0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_53CFE0(int* out, const char* filename, int regArg) {
    //     char key[256];
    //     strcpy(key, filename);
    //     sub_589901(key);
    //     for (int i = strlen(key) - 1; i > 0 && key[i] != '.'; --i) {}
    //     if (key[i] == '.') key[i] = 0;
    //     for (Entry* e = dword_8B8E20; e; e = *(Entry**)(e + 2160)) {
    //       if (strcmp(e->name, key) == 0) { if (out) *out = e; return 0; }
    //     }
    //     Entry* n = OperatorNewNhMallocWrapper(2164);
    //     if (n) HashTable(n);
    //     if (sub_552470(filename, regArg) == 0) {
    //       LinkedListAppend_d340(n);
    //       if (out) *out = n;
    //       return 0;
    //     }
    //     if (n) { EmptyStub_7470(n); FreeWrapper_7bcf(n); }
    //     return -1;
    //   }
    // UNRESOLVED: Node layout is only partially evidenced: name at +20, next pointer at +2160, total size 2164 bytes.
    // UNRESOLVED: Purpose of the sub_589901 string transform and the semantics of sub_552470's registration check are unconfirmed.
    // UNRESOLVED: The ABI lead name suggests extension fallback behavior but the raw source strips the extension before matching, which is not fully reconciled.
}
