// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00596E40
// Canonical corpus name: sub_596E40
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_596E40_00596e40.c

void UnknownObject::InitCodePage()
{
    // Initializes the CRT code page character tables for the code page resolved from a1. If the code page is already cached, returns immediately. Otherwise it first searches a built-in code page table and expands each matched entry's character-class ranges into the global bitmap; if no table entry matches it falls back to the system GetCPInfo and reconstructs single-byte or DBCS lead-byte flags. Returns 0 on success and -1 for an unknown code page when no auto flag is set. All paths run under a lazy-init critical section.
    // CALL: Enter the lazy-init critical section via CriticalSectionLazyInitEnter(25). [callee:0x0058DFEA, source:raw]
    // CALL: Resolve the requested code page from a1 through sub_596FED(a1). [callee:0x00596FED, source:raw]
    // GUARD: When the resolved code page equals the cached value dword_8D46BC the tables are already initialized; skip straight to the exit path returning 0. [global:0x008D46BC, source:raw]
    // GUARD: When the resolved code page is zero, run the zero-handler sub_59706A() followed by sub_597093() and return 0. [callee:0x0059706A, callee:0x00597093, source:raw]
    // LOOP: Search the built-in code page table starting at unk_5E9B48 for an entry whose id equals the resolved code page; entries are dword ids at stride 48 bytes and the scan stops once the address passes dword_5E9C38. [global:0x005E9B48, global:0x005E9C38, source:raw]
    // CALL: On a table match: clear the 256-byte character bitmap unk_8D47E0 with memset(0, 0x100) and reset the byte count field to 0. [global:0x008D47E0, source:raw]
    // LOOP: Walk the matched entry's four character-class groups located at unk_5E9B58 + 48 * entry; each group is up to 8 bytes holding inclusive [lo, hi] character ranges. [global:0x005E9B58, source:raw]
    // CALCULATION: For every [lo, hi] range, OR the group's class flag byte_5E9B40[group] into byte_8D47E1 for each character code in the range, building the class bitmap. [global:0x005E9B40, global:0x008D47E1, source:raw]
    // ASSIGNMENT: On a table match, cache the resolved code page into dword_8D46BC, set the DBCS init flag dword_8D46CC = 1, and copy the entry's data block from unk_5E9B4C + 48 * entry into the global data fields including unk_8D46C0. [global:0x008D46BC, global:0x008D46CC, global:0x005E9B4C, global:0x008D46C0, source:raw]
    // CALL: Map the resolved code page to a locale constant via ConstantMapper and store it into dword_8D48E4. [callee:0x00597037, global:0x008D48E4, source:raw]
    // GUARD: When no built-in table entry matched, fall back to the system code page query GetCPInfo(resolved, &CPInfo); a failed query branches to the error path. [global:0x0059E148, source:raw]
    // ASSIGNMENT: Fallback success setup: reset dword_8D48E4 = 0, clear the 256-byte bitmap, cache dword_8D46BC = resolved code page, reset the byte count field, and zero the three global data-block fields. [global:0x0059E148, global:0x008D48E4, global:0x008D46BC, source:raw]
    // STATE_TRANSITION: In the fallback, when CPInfo.MaxCharSize is 1 mark dword_8D46CC = 0 (single-byte); otherwise expand the DBCS lead-byte range pairs from CPInfo.LeadByte into byte_8D47E1 with flag 4. [global:0x0059E148, global:0x008D46CC, global:0x008D47E1, source:raw]
    // LOOP: In the multi-byte fallback, OR flag 8 into every single-byte character code below 0xFF of byte_8D47E1, remap the locale with ConstantMapper into dword_8D48E4, and set dword_8D46CC = 1. [callee:0x00597037, global:0x008D47E1, global:0x008D48E4, global:0x008D46CC, source:raw]
    // GUARD: When GetCPInfo fails and the auto-flag dword_8D41D4 is set, run the error handler sub_59706A(); otherwise return -1 for the unknown code page. [global:0x008D41D4, callee:0x0059706A, source:raw]
    // CALL: Leave the lazy-init critical section via CritSectLeave(25) on the exit path. [callee:0x0058E04B, source:raw]
    // RETURN: Return 0 when the tables were already initialized or successfully built, and -1 for an unknown code page when no auto flag was set. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_596E40(int locale) {
    //     CriticalSectionLazyInitEnter(25);
    //     UINT cp = sub_596FED(locale);
    //     if (cp == dword_8D46BC) { leave(); return 0; }
    //     if (!cp) { sub_59706A(); sub_597093(); leave(); return 0; }
    //     for (i = 0; &unk_5E9B48 + 48*i < dword_5E9C38; ++i) {
    //       if (*(UINT*)(&unk_5E9B48 + 48*i) == cp) {
    //         memset(&unk_8D47E0, 0, 0x100);
    //         for (g = 0; g < 4; ++g) {
    //           unsigned char *r = &unk_5E9B58 + 48*i + 8*g;
    //           for (unsigned char *p = r; *p; p += 2) {
    //             if (p[0] <= p[1])
    //               for (unsigned c = p[0]; c <= p[1]; ++c) byte_8D47E1[c] |= byte_5E9B40[g];
    //           }
    //         }
    //         dword_8D46CC = 1;
    //         dword_8D46BC = cp;
    //         dword_8D48E4 = ConstantMapper(cp);
    //         unk_8D46C0 = *(UINT*)(&unk_5E9B4C + 48*i);
    //         sub_597093(); leave(); return 0;
    //       }
    //     }
    //     _cpinfo CPInfo;
    //     if (GetCPInfo(cp, &CPInfo)) {
    //       dword_8D48E4 = 0;
    //       memset(&unk_8D47E0, 0, 0x100);
    //       dword_8D46BC = cp;
    //       if (CPInfo.MaxCharSize <= 1) dword_8D46CC = 0;
    //       else {
    //         for (unsigned char *p = &CPInfo.LeadByte[0]; *p && p[1]; p += 2)
    //           for (unsigned c = p[0]; c <= p[1]; ++c) byte_8D47E1[c] |= 4;
    //         for (unsigned c = 1; c < 0xFF; ++c) byte_8D47E1[c] |= 8;
    //         dword_8D48E4 = ConstantMapper(cp);
    //         dword_8D46CC = 1;
    //       }
    //       sub_597093(); leave(); return 0;
    //     }
    //     if (dword_8D41D4) { sub_59706A(); sub_597093(); leave(); return 0; }
    //     leave();
    //     return -1;
    //   }
    // UNRESOLVED: The exact meaning of the per-entry data block fields copied from unk_5E9B4C (first, second and third dwords) and of the locale constant in dword_8D48E4 is not derivable from this function alone.
    // UNRESOLVED: The two packet globals byte_FF0000000000547A and byte_FF0000000000547C are 64-bit-address artifacts that do not appear in the raw source; left unresolved.
    // UNRESOLVED: The zero-handler sub_59706A and finalizer sub_597093 semantics are not established here.
}
