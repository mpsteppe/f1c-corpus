// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058F939
// Canonical corpus name: sub_58F939
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58F939_0058f939.c

void UnknownObject::CodePageCharTypeTableInit()
{
    // Initializes the code page character type and case-mapping tables used by the runtime. When dword_8D3F38 is nonzero, it resolves the code page (querying it via sub_5968F6 with LOCALE_IDEFAULTCODEPAGE when CodePage is 0), allocates four buffers through MallocWrapperForNhMalloc, builds a 256-entry SBCS byte map (zeroing DBCS lead-byte ranges), converts it with sub_595DC8, builds a wide char map converted by sub_596A2E, marks DBCS lead-byte ranges with flag 0x8000, installs the new tables in off_5E69C8/off_5E69CC, and frees/replaces the previous tables (dword_8D3F6C/dword_8D3F70). On any failure it frees partial allocations and returns 1. When dword_8D3F38 is zero it installs the static table word_5E69D2 in both slots, frees and clears the dynamic pointers, and returns 0.
    // GUARD: Branch on dword_8D3F38: nonzero selects dynamic table initialization, zero selects the static table path. [global:0x008D3F38, source:raw]
    // CALL: When CodePage is 0, call sub_5968F6(0, word_8D3F80, 0x1004, &CodePage) to resolve the default code page from locale info (LCTYPE 0x1004 = LOCALE_IDEFAULTCODEPAGE); failure jumps to cleanup. [callee:0x005968F6, global:0x008D3F80, global:0x008D3F48]
    // CALL: Allocate the four working buffers with MallocWrapperForNhMalloc: 514-byte lpMem, 514-byte v16, 257-byte lpSrcStr, 514-byte v17. [callee:0x0058A935]
    // GUARD: If any of the four allocations is null, jump to the cleanup label. [callee:0x0058A935, source:raw]
    // LOOP: Fill lpSrcStr[0..255] with the byte values 0..255. [source:raw]
    // CALL: Call GetCPInfo(CodePage, &CPInfo) to obtain max char size and lead-byte ranges. [global:0x0059E148, global:0x008D3F48]
    // GUARD: If GetCPInfo fails or CPInfo.MaxCharSize > 2, jump to cleanup (unsupported code page). [source:raw]
    // ASSIGNMENT: Store LOWORD(CPInfo.MaxCharSize) into cbMultiByte (1 = SBCS, 2 = DBCS). [global:0x005E6BD4, source:raw]
    // LOOP: For a DBCS code page, zero the lpSrcStr entries in each lead-byte range given by CPInfo.LeadByte. [source:raw]
    // CALL: Call sub_595DC8(1u, lpSrcStr, 256, v1 + 1, 0, 0, 0) to convert the SBCS byte map into the character type table; a 0 return jumps to cleanup. [callee:0x00595DC8]
    // LOOP: Fill the wide buffer v17[0..255] with 0..255. [source:raw]
    // CALL: Call sub_596A2E(1u, v17, 256, (LPWORD)v16 + 1, 0, 0) to build the upper/lowercase mapping table; a 0 return jumps to cleanup. [callee:0x00596A2E]
    // LOOP: For a DBCS code page, write flag 0x8000 into each lead-byte range entry of the character type table. [source:raw]
    // ASSIGNMENT: Install off_5E69CC = v16 + 2 as the case-mapping table pointer. [global:0x005E69CC, source:raw]
    // ASSIGNMENT: Install off_5E69C8[0] = lpMem + 2 as the character type table pointer. [global:0x005E69C8, source:raw]
    // STATE_TRANSITION: Free the previous tables: if dword_8D3F6C is set call sub_58AA6F(dword_8D3F6C), then store lpMem into dword_8D3F6C; if dword_8D3F70 is set call sub_58AA6F(dword_8D3F70), then store v16 into dword_8D3F70. [callee:0x0058AA6F, global:0x008D3F6C, global:0x008D3F70]
    // CALL: Cleanup path: sub_58AA6F(lpMem) and sub_58AA6F(v16) free the partial allocations and set the failure flag v0 = 1. [callee:0x0058AA6F]
    // CALL: Always free the two secondary buffers sub_58AA6F(lpSrcStr) and sub_58AA6F(v17) before returning. [callee:0x0058AA6F]
    // RETURN: Return v0: 1 on dynamic-path failure, 0 on success. [function:0x0058F939, source:raw]
    // ASSIGNMENT: Static path: set off_5E69C8[0] = &word_5E69D2 and off_5E69CC = &word_5E69D2 so both tables point at the static default table. [global:0x005E69C8, global:0x005E69CC, global:0x005E69D2, source:raw]
    // STATE_TRANSITION: Static path: free any existing dynamic tables (sub_58AA6F on dword_8D3F6C and dword_8D3F70) and zero both pointers. [callee:0x0058AA6F, global:0x008D3F6C, global:0x008D3F70, source:raw]
    // RETURN: Static path returns 0. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_58F939() {
    //     int fail = 0;
    //     LPVOID lpMem = 0, v16 = 0;
    //     LPCSTR lpSrcStr = 0;
    //     LPCWCH v17 = 0;
    //     if (g_useDynamicTables) {
    //       if (!g_codePage && !sub_5968F6(0, g_langId, 0x1004, &g_codePage)) goto cleanup;
    //       lpMem = MallocWrapperForNhMalloc(514); v16 = MallocWrapperForNhMalloc(514);
    //       lpSrcStr = MallocWrapperForNhMalloc(257); v17 = MallocWrapperForNhMalloc(514);
    //       if (!lpMem || !v16 || !lpSrcStr || !v17) goto cleanup;
    //       for (i = 0; i < 256; ++i) lpSrcStr[i] = i;
    //       if (!GetCPInfo(g_codePage, &cp) || cp.MaxCharSize > 2) goto cleanup;
    //       g_cbMultiByte = LOWORD(cp.MaxCharSize);
    //       if (cp.MaxCharSize > 1 && cp.LeadByte[0]) { /* zero lead byte ranges * / }
    //       if (!sub_595DC8(1, lpSrcStr, 256, (WORD*)lpMem + 1, 0, 0, 0)) goto cleanup;
    //       for (k = 0; k < 256; ++k) ((WCHAR*)v17)[k] = k;
    //       if (sub_596A2E(1, v17, 256, (LPWORD)v16 + 1, 0, 0)) {
    //         if (g_cbMultiByte > 1 && cp.LeadByte[0]) { /* mark lead bytes with 0x8000 * / }
    //         g_caseMap = v16 + 2;
    //         g_typeTable = (WORD*)lpMem + 2;
    //         if (g_oldType) sub_58AA6F(g_oldType); g_oldType = lpMem;
    //         if (g_oldCase) sub_58AA6F(g_oldCase); g_oldCase = v16;
    //       } else {
    //     cleanup:
    //         sub_58AA6F(lpMem); sub_58AA6F(v16); fail = 1;
    //       }
    //       sub_58AA6F(lpSrcStr); sub_58AA6F(v17);
    //       return fail;
    //     } else {
    //       g_typeTable = &g_staticTable;
    //       g_caseMap = &g_staticTable;
    //       sub_58AA6F(g_oldType); sub_58AA6F(g_oldCase);
    //       g_oldType = 0; g_oldCase = 0;
    //       return 0;
    //     }
    //   }
    // UNRESOLVED: byte_FF0000000000547A and byte_FF0000000000547C appear in the packet globals but are not visible in the raw decompiled body; their usage location (likely TLS guard/state bytes) is unresolved.
    // UNRESOLVED: Semantics of sub_595DC8 and sub_596A2E (SBCS/Wide conversion routines) are assumed from call shape only.
    // UNRESOLVED: Whether off_5E69C8 holds the type table and off_5E69CC the case-mapping table (or vice versa) is not proven.
}
