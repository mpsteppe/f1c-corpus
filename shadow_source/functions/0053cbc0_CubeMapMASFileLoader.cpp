// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053CBC0
// Canonical corpus name: sub_53CBC0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_53CBC0_0053cbc0.c

void UnknownObject::CubeMapMASFileLoader()
{
    // Loads and validates a .MAS cube-map file: uppercases the given filename, opens it directly or by retrying across the registered path-prefix array (dword_8B8E30 entries at byte_8B5A3C, stride 132) with an "rb" mode string, reads the 12-byte header magic, and dispatches on it. A Cubemas410 magic allocates a 308-byte physics object, initializes it, parses the file, and links the object into a singly linked list rooted at dword_8B8F14 (next link at offset 304); other magics report an incorrect-file error. On any open failure it formats an "Error opening MAS file" message and reports -2. Widely called by cockpit/pit/UI setup paths.
    // GUARD: If a2 is null or its first character is NUL, return 0 immediately. [source:raw]
    // LOOP: Copy the input filename a2 into the local SrcStr buffer, including the terminating NUL. [source:raw]
    // CALL: Uppercase-normalize SrcStr via sub_589901 before opening. [callee:0x00589901]
    // CALL: Attempt to open the file: v5 = sub_587DB0(SrcStr, aRb), with aRb as the read-mode string. [callee:0x00587DB0, global:0x005BE828]
    // LOOP: If the direct open failed, retry across registered path prefixes: for each of dword_8B8E30 entries starting at byte_8B5A3C with stride 132, format "%s\\%s" (prefix + SrcStr) into v17 via StringFormatWithBufferOverflowCheck and retry sub_587DB0; stop on first success or when the counter reaches dword_8B8E30. [global:0x008B8E30, global:0x008B5A3C, callee:0x0058815F, callee:0x00587DB0]
    // CALL: If no prefix produced an open handle, format "Error opening MAS file %s" into v17 and call sub_53C590(-2, v17); return -2. [global:0x005DBC14, callee:0x0058815F, callee:0x0053C590]
    // CALL: Read 12 bytes of header into v15 with ThreadSafeReadWrapper_803f(v15, 1, 12, v5), then close the file with FileCloseWithLock(v5). [callee:0x0058803F, callee:0x00587D02]
    // GUARD: If the 12-byte header matches the Cubemas410 magic (strcmp(v15, aCubemas410) == 0), take the cube-map creation path. [global:0x005DBC08]
    // CALL: Allocate a 308-byte object: v9 = OperatorNewNhMallocWrapper(308); if non-null, initialize it via sub_55FBE0(v9) into v10, else v10 = 0. [callee:0x00587C03, callee:0x0055FBE0]
    // CALL: Parse the file by name: v11 = sub_55FC40(SrcStr); the returned code drives the dispatch below. [callee:0x0055FC40]
    // STATE_TRANSITION: On parse result -2 or -1: if the object v10 exists, run EmptyStub_7470(v10) then FreeWrapper_7bcf(v10); return -2 (resp. -1). [callee:0x00557470, callee:0x00587BCF]
    // ASSIGNMENT: On parse result 0 (success): append v10 to the object list. If dword_8B8F14 is non-null, walk the singly linked list (next pointers at offset 304) to the tail and store v10 as the tail's next, plus set v10's back-pointer at dword index 75 (offset 300); otherwise make v10 the new list head dword_8B8F14. [global:0x008B8F14]
    // ASSIGNMENT: Increment the global object count dword_8B6AC0 and set the local result to 0. [global:0x008B6AC0]
    // ASSIGNMENT: If a1 is non-null, write the created object pointer to *a1; return the local result. [field:this:0x00000000]
    // GUARD: If the header matched neither the Cubemas400 nor the Cubemas401 magic, return 0 without further action. [global:0x005DBBFC, global:0x005DBBF0]
    // CALL: For the remaining magics, report an incorrect-file error: sub_53C590(-2, aIncorrectMasFi) and return -1. [global:0x005DBBD4, callee:0x0053C590]

    // Conservative worker pseudocode:
    //   if (!a2 || !*a2) return 0;
    //   copy a2 into SrcStr; sub_589901(SrcStr);
    //   v5 = sub_587DB0(SrcStr, aRb);
    //   if (!v5) {
    //     for (i = 0; i < dword_8B8E30; ++i) {
    //       StringFormatWithBufferOverflowCheck(v17, "%s\\%s", byte_8B5A3C + i*132, SrcStr);
    //       if ((v5 = sub_587DB0(v17, aRb)) != 0) break;
    //     }
    //     if (i == dword_8B8E30) { StringFormatWithBufferOverflowCheck(v17, "Error opening MAS file %s", SrcStr); sub_53C590(-2, v17); return -2; }
    //   }
    //   ThreadSafeReadWrapper_803f(v15, 1, 12, v5); FileCloseWithLock(v5);
    //   if (strcmp(v15, aCubemas410) == 0) {
    //     v9 = OperatorNewNhMallocWrapper(308); v10 = v9 ? (_DWORD*)sub_55FBE0(v9) : 0;
    //     switch (sub_55FC40(SrcStr)) {
    //       case -2: if (v10) { EmptyStub_7470(v10); FreeWrapper_7bcf(v10); } return -2;
    //       case -1: if (v10) { EmptyStub_7470(v10); FreeWrapper_7bcf(v10); } return -1;
    //       case 0: link v10 at list tail rooted at dword_8B8F14; ++dword_8B6AC0; break;
    //     }
    //     if (a1) *a1 = v10;
    //     return 0;
    //   }
    //   if (strcmp(v15, aCubemas400) && strcmp(v15, aCubemas401)) return 0;
    //   sub_53C590(-2, aIncorrectMasFi); return -1;
    // UNRESOLVED: Global aSS_3 (0x005C2D64) is listed in the packet globals but is not referenced by the reconstructed source; it is likely a neighboring string constant whose exact consumer is not evidenced here.
    // UNRESOLVED: sub_55FBE0 and sub_55FC40 (object construction and MAS parse) are only evidenced by their call signatures here; their internal contract is unknown.
    // UNRESOLVED: sub_53C590 is treated as an error-reporting routine (called with message text and -2), matching the existing-analysis label ErrorHandlerSet, but its exact reporting channel is not evidenced by this packet.
}
