// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00588C7A
// Canonical corpus name: sub_588C7A
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_588C7A_00588c7a.c

void UnknownObject::SessionParameterSetter()
{
    // Sets a network session parameter at index a1 from the string value lpMem. Parses the input into components, allocates a copy, swaps the session table slot (dword_5E64F4 + 3 * a1) and an associated 6-byte config entry, then dispatches a per-index validation callback. On validation failure the previous slot value, config entry and CodePage are restored and the copy is freed. Special index 2 updates the global CodePage and index 1 updates dword_8D3F4C. Returns the new session table slot on success, 0 on parse/allocation/validation failure.
    // GUARD: Guard on sub_588E4E(lpMem, v5, v9, &v7): if the parse returns 0 the function returns 0 immediately. [callee:0x00588E4E, source:raw]
    // CALCULATION: Compute v3 = Strlen(v5), the byte length of the parsed string component. [callee:0x0058E1B0, source:raw]
    // CALL: Allocate the value copy: lpMema = MallocWrapperForNhMalloc(v3 + 1). [callee:0x0058A935, source:raw]
    // GUARD: Guard on the allocation result: a NULL lpMema makes the function return 0. [source:raw]
    // ASSIGNMENT: Save the current session table entry v12 = *(&dword_5E64F4 + 3 * a1) for rollback. [global:0x005E64F4, source:raw]
    // ASSIGNMENT: Save v8 = dword_8D3F30[a1], the previous code-page table value for this index. [source:raw]
    // CALCULATION: Compute v10 = 6 * a1 + 9256820, the address of the 6-byte config entry for index a1. [source:raw]
    // CALL: Back up the old 6-byte config entry with MemoryCopy_cc00(v6, v10, 6). [callee:0x0058CC00, source:raw]
    // ASSIGNMENT: Save v11 = CodePage so it can be restored if validation fails. [global:0x008D3F48, source:raw]
    // CALL: Normalize the allocated string with sub_58FCA0(lpMema) and store it into the session table slot *(&dword_5E64F4 + 3 * a1). [callee:0x0058FCA0, global:0x005E64F4, source:raw]
    // ASSIGNMENT: Store dword_8D3F30[a1] = v9[0] from the parsed config component. [source:raw]
    // CALL: Write the new 6-byte config entry with MemoryCopy_cc00(v10, v9, 6). [callee:0x0058CC00, source:raw]
    // GUARD: Guard a1 == 2: update the global CodePage = v7. [global:0x008D3F48, source:raw]
    // GUARD: Guard a1 == 1: update dword_8D3F4C = v7. [global:0x008D3F4C, source:raw]
    // CALL: Dispatch the per-index validation callback (*(&funcs_588D4B + 3 * a1))(); a non-zero result triggers rollback. [global:0x005E64F8, source:raw]
    // STATE_TRANSITION: Rollback on validation failure: restore v12 into the session table slot, free lpMema via sub_58AA6F, restore dword_8D3F30[a1] = v8 and CodePage = v11, then return 0. [callee:0x0058AA6F, global:0x005E64F4, global:0x008D3F48, source:raw]
    // GUARD: Free the previously stored session table pointer: if v12 != &unk_5E63E0 then sub_58AA6F(v12). [global:0x005E63E0, callee:0x0058AA6F, source:raw]
    // RETURN: Return the new session table entry *(&dword_5E64F4 + 3 * a1) on success. [global:0x005E64F4, source:raw]

    // Conservative worker pseudocode:
    //   int sub_588C7A(int idx, char* text) {
    //     if (!sub_588E4E(text, v5, v9, &v7)) return 0;
    //     len = Strlen(v5);
    //     buf = MallocWrapperForNhMalloc(len + 1);
    //     if (!buf) return 0;
    //     slot = &dword_5E64F4 + 3 * idx;
    //     old = *slot; old_code = dword_8D3F30[idx]; base = 6 * idx + 9256820;
    //     MemoryCopy_cc00(backup, base, 6); old_cp = CodePage;
    //     *slot = sub_58FCA0(buf); dword_8D3F30[idx] = v9[0]; MemoryCopy_cc00(base, v9, 6);
    //     if (idx == 2) CodePage = v7;
    //     if (idx == 1) dword_8D3F4C = v7;
    //     if (validate[idx]()) { *slot = old; sub_58AA6F(buf); dword_8D3F30[idx] = old_code; CodePage = old_cp; return 0; }
    //     if (old != &unk_5E63E0) sub_58AA6F(old);
    //     return *slot;
    //   }
    // UNRESOLVED: StubReturning0 (0x0058FB7E) is listed as a callee but never appears in the raw source; its connection to this path is unknown.
    // UNRESOLVED: The parallel arrays dword_8D3F30 and the 6-byte config region at 9256820 are named only in the raw source; their structure and role are not independently evidenced.
    // UNRESOLVED: The semantics of the parsed components v9[0] and v7 (index-specific code-page data) are not established.
    // UNRESOLVED: The meaning of the sentinel unk_5E63E0 compared against the old slot pointer is not evidenced.
}
