// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00432A70
// Canonical corpus name: TrackSessionClassesReader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TrackSessionClassesReader_00432a70.c

void UnknownObject::TrackSessionClassesReader()
{
    // Iterates over a track session-class entry list, matching each entry against four known vtable types (off_5C3F8C, off_5C3F90, off_5C3F94, off_5C3F98). A match on off_5C3F94 (the UI-widget vtable) stores the wrapped string handle into this[4] (offset 0x10). Loop continuation is gated by ConditionalDispatchBasedOnFlag on a 384-byte scratch buffer. Returns 1 immediately when a2 or *a2 is null; otherwise returns 0 on normal end.
    // ASSIGNMENT: result = 1: the default return used when the a2 guard fails. [source:raw]
    // GUARD: Guard on a2 and *a2 being non-null; otherwise return result (1) without processing. The function is invoked by AutoLoadEntryListLoader during list processing. [source:raw, caller:0x00432E70]
    // ASSIGNMENT: memset(v12, 0, 384): zeroes the 384-byte scratch buffer used for the dispatch flag state. [source:raw]
    // ASSIGNMENT: Local initialization: v7, v11, v9, v10 = 0 and v8 = 1 before entering the dispatch gate. [source:raw]
    // CALL: ConditionalDispatchBasedOnFlag(v12, 384): gates whether the entry-processing loop runs; when it returns false the function returns 0. [callee:0x00566CC0]
    // LOOP: while(1) entry-processing loop, terminated by the vtable-match breaks or by a false ConditionalDispatchBasedOnFlag check at the loop tail. [source:raw]
    // CALL: sub_5651B0(v6): reads the next entry into v6; return 0 means a valid entry, 1 means end of list (return 0), and any other value skips to the loop-tail check. [callee:0x005651B0]
    // GUARD: Guard on the sub_5651B0 result: v4 == 1 ends processing with return 0. [source:raw]
    // CALL: sub_5654A0(off_5C3F8C[0], v5) or sub_5654A0(off_5C3F90[0], v5): matches the entry v5 against the first two vtable types; a match breaks the loop. [callee:0x005654A0, global:0x005C3F8C, global:0x005C3F90]
    // CALL: sub_565520(off_5C3F94[0], v5, 0): matches the entry v5 against the UI-widget vtable type. [callee:0x00565520, global:0x005C3F94]
    // ASSIGNMENT: this[4] (offset 0x10) = SingleFunctionCallWrapper_7f59(v5): wraps the matched UI-widget string into a handle stored in the object when the UI-widget vtable matches. [field:this:0x00000010, callee:0x00587F59]
    // CALL: sub_5654A0(off_5C3F98[0], v5): matches the entry v5 against the fourth vtable type (message-box vtable); a match breaks the loop. [callee:0x005654A0, global:0x005C3F98]
    // GUARD: Loop-tail guard: if ConditionalDispatchBasedOnFlag(v12, 384) is false the loop exits with return 0. [callee:0x00566CC0]
    // CALL: StringCopyWithBufferRealloc(v5): copies the matched entry string with automatic buffer reallocation after the loop breaks. [callee:0x00566650]
    // RETURN: Return result (1) when the a2 guard fails, or 0 on all processing exit paths. [source:raw]

    // Conservative worker pseudocode:
    //   int TrackSessionClassesReader(_DWORD* this, _DWORD* a2) {
    //     if (!a2 || !*a2) return 1;
    //     BYTE v12[384]; memset(v12, 0, sizeof(v12));
    //     v7 = 0; v11 = 0; v9 = 0; v10 = 0; v8 = 1;
    //     if (!ConditionalDispatchBasedOnFlag(v12, 384)) return 0;
    //     while (1) {
    //       int v4 = sub_5651B0(v6);
    //       if (v4) { if (v4 == 1) return 0; goto check; }
    //       if (sub_5654A0(off_5C3F8C[0], v5) || sub_5654A0(off_5C3F90[0], v5)) break;
    //       if (sub_565520(off_5C3F94[0], v5, 0)) { this[4] = SingleFunctionCallWrapper_7f59(v5); }
    //       else if (sub_5654A0(off_5C3F98[0], v5)) { break; }
    //   check:
    //       if (!ConditionalDispatchBasedOnFlag(v12, 384)) return 0;
    //     }
    //     StringCopyWithBufferRealloc(v5);
    //     goto check;
    //   }
    // UNRESOLVED: The four vtable globals off_5C3F8C/5C3F90/5C3F94/5C3F98 are only compared, never dereferenced here; their exact object types are not evidenced by this packet.
    // UNRESOLVED: The stack layout of v5/v6 scratch buffers and the identity of sub_5651B0's entry format are unresolved.
    // UNRESOLVED: The post-break path (StringCopyWithBufferRealloc followed by the loop-tail check) does not store a second result, so the fall-through flow after a vtable match is not fully resolved.
}
