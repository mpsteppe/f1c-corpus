// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00568B00
// Canonical corpus name: sub_568B00
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_568B00_00568b00.c

void UnknownObject::FileCopyViaReadWrite()
{
    // Copies the content of the file at path a1 to the file at path a2 through a 2048-byte local buffer. Opens the source with mode string aRb (0x005BE828) and the destination with the config-directory path unk_5C2AB0 (0x005C2AB0), then loops reading up to 2048 bytes from the source via ThreadSafeReadWrapper_803f and writing each chunk via FileReadWrapperWithLock until the read returns zero. Closes both handles through FileCloseWithLock and returns 1 on success, 0 when either open fails. Called from SettingsCopySetupFileCopy (0x00432220), LoadAIDriverNamesFromConfig (0x004336F0) and ValidateVehicleConfigurationFile (0x00433ED0).
    // CALL: v3 = sub_587DB0(a1, aRb) opens the source file with the 'rb' mode string; if the handle is null the function returns 0 immediately [callee:0x00587DB0, global:0x005BE828, source:raw]
    // CALL: v4 = sub_587DB0(a2, &unk_5C2AB0) opens the destination with the config-directory path; on failure FileCloseWithLock(v3) closes the source and the function returns 0 [callee:0x00587DB0, global:0x005C2AB0, callee:0x00587D02]
    // LOOP: Copy loop: i = ThreadSafeReadWrapper_803f(v7, 1, 2048, v3) reads up to 2048 bytes from the source; while i > 0 the chunk is written to the destination with FileReadWrapperWithLock(v7, 1, i, v4) and the next chunk is read [callee:0x0058803F, callee:0x00588678]
    // CALL: After the copy loop, FileCloseWithLock(v3) and FileCloseWithLock(v4) close both handles and the function returns 1 [callee:0x00587D02, source:raw]

    // Conservative worker pseudocode:
    //   v3 = sub_587DB0(a1, aRb);
    //   if (!v3) return 0;
    //   v4 = sub_587DB0(a2, &unk_5C2AB0);
    //   if (!v4) { FileCloseWithLock(v3); return 0; }
    //   for (i = ThreadSafeReadWrapper_803f(v7, 1, 2048, v3); i > 0; i = ThreadSafeReadWrapper_803f(v7, 1, 2048, v3))
    //     FileReadWrapperWithLock(v7, 1, i, v4);
    //   FileCloseWithLock(v3); FileCloseWithLock(v4);
    //   return 1;
    // UNRESOLVED: The exact open semantics of sub_587DB0 (path assembly against unk_5C2AB0, creation flags) are not established by this packet.
    // UNRESOLVED: The 2048-byte buffer is a plain transfer scratch; no buffering or atomicity contract is evidenced.
}
