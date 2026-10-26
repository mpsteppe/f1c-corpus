// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B8010
// Canonical corpus name: FileSettingExistenceCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileSettingExistenceCheck_004b8010.c

void UnknownObject::FileSettingExistenceCheck()
{
    // Settings-file existence check and cleanup. Resolves the target file path into lpFileName via sub_4B9830, falling back to the default path byte_5EA438 when the resolver returns null. Opens the path with the read-mode string aRb through sub_587DB0; only when the open succeeds does it close the handle (FileCloseWithLock), clear the read-only attribute (ToggleFileReadOnlyAttributeViaWin32API with attribute constant 128), and delete the file (FileDeleteWithErrorHandling), recording success in v0. The returned bool is !v0, so the function reports true when no file existed (or deletion failed) and false when a file existed and was deleted. The heap-allocated path buffer lpFileName[0] is released via FreeWrapper_7bcf when non-null.
    // ASSIGNMENT: Initialize local state: v0 = false, lpFileName[0] = null, lpFileName[1] = -1 before the path is resolved. [source:raw]
    // CALL: sub_4B9830(lpFileName) resolves the settings-file path into the buffer; on success slot 0 receives the heap-allocated path string. [callee:0x004B9830, source:raw]
    // ASSIGNMENT: v1 = lpFileName[0]; when the resolved path is null, v1 falls back to the default path string byte_5EA438. [global:0x005EA438, source:raw]
    // CALL: v2 = sub_587DB0(v1, aRb) attempts to open the path using the read-mode string aRb; a non-zero v2 indicates the file exists and was opened. [callee:0x00587DB0, global:0x005BE828, source:raw]
    // GUARD: Deletion path runs only when v2 is non-zero (open succeeded); otherwise the function skips cleanup and reports that no file existed. [source:raw]
    // CALL: FileCloseWithLock(v2) closes the opened file handle. [callee:0x00587D02, source:raw]
    // CALL: ToggleFileReadOnlyAttributeViaWin32API(v1, 128) clears the read-only attribute (constant 128) on the path so deletion can succeed. [callee:0x0058BA36, source:raw]
    // CALL: v0 = (FileDeleteWithErrorHandling(v1) == 0); a zero return from the delete wrapper sets v0 to true, marking a successful delete. [callee:0x0058986E, source:raw]
    // CALCULATION: v3 = !v0 inverts the delete result: the function returns true when no file existed or deletion failed, false when a file existed and was deleted. [source:raw]
    // GUARD: When lpFileName[0] is non-null, the resolver allocated a path buffer that must be released. [source:raw]
    // CALL: FreeWrapper_7bcf(lpFileName[0]) frees the heap-allocated resolved path buffer. [callee:0x00587BCF, source:raw]
    // RETURN: return v3 (true = no existing file or deletion failed; false = file existed and was deleted). [source:raw]
    // CALL: Invoked by GameDataFileIO (004b7300) and sub_4B7500 (004b7500) as part of the file/settings cleanup flow. [caller:0x004B7300, caller:0x004B7500]

    // Conservative worker pseudocode:
    //   bool sub_4B8010() {
    //     bool v0 = false;
    //     LPCSTR lpFileName[2] = { 0, (LPCSTR)-1 };
    //     sub_4B9830(lpFileName);
    //     const CHAR* v1 = lpFileName[0] ? lpFileName[0] : byte_5EA438;
    //     int v2 = sub_587DB0(v1, aRb);
    //     if (v2) {
    //       FileCloseWithLock(v2);
    //       ToggleFileReadOnlyAttributeViaWin32API(v1, 128);
    //       v0 = (FileDeleteWithErrorHandling(v1) == 0);
    //     }
    //     bool v3 = !v0;
    //     if (lpFileName[0]) FreeWrapper_7bcf(lpFileName[0]);
    //     return v3;
    //   }
    // UNRESOLVED: The exact path-resolution behavior of sub_4B9830 and the identity of the default path byte_5EA438 are not established from this packet alone; existing analysis labels byte_5EA438 a default application directory (DERIVED).
    // UNRESOLVED: aRb is treated as the file-open mode string (existing analysis labels it FileModeRb, DERIVED); the raw source does not expose the string content.
    // UNRESOLVED: The caller-observed meaning of the inverted return value (true when no file present) is inferred from control flow, not yet runtime-verified.
    // UNRESOLVED: Frame-path membership is NOT_FOUND; call frequency from the tick root is UNKNOWN.
}
