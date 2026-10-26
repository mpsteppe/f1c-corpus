// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B0770
// Canonical corpus name: sub_4B0770
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B0770_004b0770.c

void UnknownObject::SettingsFileWriteWithBackup()
{
    // Persists the settings file by writing a temporary version and then swapping it into place. It builds a temp path by stripping the extension from the default directory string byte_5EA438 and appending the 'tmp' suffix, clears read-only attributes on both the temp and destination names, logs the attempt, initializes a small struct, loads the directory list and dispatches vtable callbacks over it, closes the file handle, then initializes the settings file, parses the config into the global dword_7C73E8, deletes the old destination and renames the temp file over it, logs the result, and frees the small struct before returning 0.
    // CALL: Call sub_568620 with size 256 to prepare the fixed-size file-name buffer. [callee:0x00568620]
    // CALL: Call StringCopyWithBufferRealloc to copy a path string into the local FileName buffer. [callee:0x00566650]
    // CALCULATION: Compute a cursor at the end of the default directory string byte_5EA438 using strlen, then scan backwards for the dot (byte 46) and truncate the string there so the file extension is stripped. [global:0x005EA438]
    // CALL: Call sub_5665B0 with the 'tmp' suffix string aTmp to build the temporary file name. [callee:0x005665B0, global:0x005D2308]
    // CALL: Call ToggleFileReadOnlyAttributeViaWin32API on the temp name FileName with attribute value 128 to clear read-only. [callee:0x0058BA36]
    // CALL: Call ToggleFileReadOnlyAttributeViaWin32API on the destination string byte_5EA438 with attribute value 128 to clear read-only. [callee:0x0058BA36, global:0x005EA438]
    // GUARD: If StringSplitLoop(2, aDDevF119992002_20, 1766) is non-zero, write the 'attempting to save' message aAttemptingToSa to the debug buffer dword_8AD25C via DebugLogWrite. [callee:0x004D7A50, global:0x005D22E0, callee:0x004D7AA0, global:0x008AD25C, global:0x005D22C4]
    // CALL: Call ZeroInitSmallStruct to zero-initialize the local 7-dword stack struct v5. [callee:0x005668B0]
    // CALL: Call sub_566940 with the directory string byte_5EA438 and arguments 0, 1, 1 to enumerate the file list into the small struct. [callee:0x00566940, global:0x005EA438]
    // GUARD: If the first dword of the small struct v5 is non-zero, call LinkedListDispatchWithVTableCalls on this receiver with the struct and the constant string asc_5D2018. [callee:0x004A1D50, global:0x005D2018]
    // CALL: Call ConditionalFileHandleCloseWithFlagDispatch to close the file handle managed by the small struct. [callee:0x00566B90]
    // CALL: Call SettingsFileInit on this receiver to (re)initialize the settings object. [callee:0x004B0930]
    // CALL: Call ConfigFileParser with a pointer to the settings global dword_7C73E8 and this receiver as the parse target. [callee:0x004330D0, global:0x007C73E8]
    // CALL: Call FileDeleteWithErrorHandling on the previous destination FileName to remove the old settings file. [callee:0x0058986E]
    // CALL: Call MoveFileAWrapperWithErrorHandling to rename the temporary file byte_5EA438 over the destination FileName. [callee:0x005898D3, global:0x005EA438]
    // GUARD: If StringSplitLoop(2, aDDevF119992002_20, 1789) is non-zero, write the rename-result message aRetcodeDForRen to the debug buffer dword_8AD25C via DebugLogWrite. [callee:0x004D7A50, global:0x005D22E0, callee:0x004D7AA0, global:0x008AD25C, global:0x005D1FF4]
    // CALL: Call SubCallWithConditionalFieldFree to release the small struct v5 and any owned fields. [callee:0x005668D0]
    // RETURN: Return 0 to signal success. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4B0770(int *this) {
    //     char FileName[256];
    //     int v5[7];
    //     sub_568620(256);
    //     StringCopyWithBufferRealloc(FileName);
    //     v3 = &byte_5EA438[strlen(byte_5EA438)];
    //     if (v3 > byte_5EA438) { while (*v3 != 46) { if (--v3 <= byte_5EA438) goto trunc; } *v3 = 0; }
    //   trunc:
    //     sub_5665B0(aTmp);
    //     ToggleFileReadOnlyAttributeViaWin32API(FileName, 128);
    //     ToggleFileReadOnlyAttributeViaWin32API(byte_5EA438, 128);
    //     if (StringSplitLoop(2, aDDevF119992002_20, 1766))
    //       DebugLogWrite(&dword_8AD25C, aAttemptingToSa);
    //     ZeroInitSmallStruct(v5);
    //     sub_566940(byte_5EA438, 0, 1, 1);
    //     if (v5[0]) LinkedListDispatchWithVTableCalls(this, (int)v5, (int)asc_5D2018);
    //     ConditionalFileHandleCloseWithFlagDispatch(v5);
    //     SettingsFileInit(this);
    //     ConfigFileParser(&dword_7C73E8, (int)this);
    //     FileDeleteWithErrorHandling(FileName);
    //     MoveFileAWrapperWithErrorHandling(byte_5EA438, FileName);
    //     if (StringSplitLoop(2, aDDevF119992002_20, 1789))
    //       DebugLogWrite(&dword_8AD25C, aRetcodeDForRen);
    //     SubCallWithConditionalFieldFree(v5);
    //     return 0;
    //   }
    // UNRESOLVED: The exact interpretation of the attribute value 128 and the semantics of sub_5665B0 / sub_566940 are not established here.
    // UNRESOLVED: Callee FreeWrapper_7bcf is listed in the packet but is not called in the raw source text; its involvement is unknown.
}
