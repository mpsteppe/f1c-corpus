// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059797B
// Canonical corpus name: sub_59797B
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59797B_0059797b.c

void UnknownObject::FileTruncateOrExtend()
{
    // File-size fix-up routine (ftruncate-style): saves the current file position, seeks to the end to obtain the file size, then either truncates the file to lDistanceToMove via SetEndOfFile (shrink path) or extends it to that size by writing zero-filled 4096-byte chunks (grow path). Restores the original file position before returning. Uses TLS errno slots for failure codes and a bitfield save/restore around the grow path.
    // ASSIGNMENT: Initialize return value v2 to 0. [source:raw]
    // CALL: FileSeekViaSetFilePointer(a1, 0, 1u): query and save the current file position into v12. [callee:0x0058C789]
    // GUARD: If the position query returned -1, return -1 immediately. [source:raw]
    // CALL: FileSeekViaSetFilePointer(a1, 0, 2u): seek to end-of-file to read the file size. [callee:0x0058C789]
    // GUARD: If the end seek returned -1, return -1 immediately. [source:raw]
    // CALCULATION: Compute the size delta v4 = lDistanceToMove - endFileSize. [source:raw]
    // GUARD: If delta is <= 0 the file is not growing; branch into the shrink/equal path. [source:raw]
    // GUARD: If delta is < 0 the file is strictly shrinking; seek to target and truncate. [source:raw]
    // CALL: FileSeekViaSetFilePointer(a1, lDistanceToMove, 0): seek to the target size position. [callee:0x0058C789]
    // CALL: sub_595A1F(a1): obtain the raw OS file handle for the descriptor. [callee:0x00595A1F]
    // CALL: SetEndOfFile(handle): truncate the file at the current position. [global:0x0059E078]
    // CALCULATION: Convert BOOL result v8 to v2 = v8 - 1 (0 on success, -1 on failure). [source:raw]
    // GUARD: If SetEndOfFile failed (v8 == 0), record the failure in TLS error slots. [source:raw]
    // CALL: TLSOffsetGetter(): store error code 13 into the primary TLS error slot. [callee:0x0058AFCF]
    // CALL: GetLastError(): retrieve the OS error code. [global:0x0059E188]
    // CALL: TLSOffsetGetter_afd8(): store the GetLastError result into the secondary TLS error slot. [callee:0x0058AFD8]
    // CALCULATION: __alloca_probe: compiler stack probe that reserves and validates the 4096-byte extension buffer on the stack. [callee:0x005881C0]
    // CALL: sub_58BB10(Buffer, 0, 0x1000): zero-fill the 4096-byte extension buffer. [callee:0x0058BB10]
    // CALL: BitfieldManager(a1, 0x8000): save the current bitfield flags (flag 0x8000) around the grow loop. [callee:0x0059801A]
    // LOOP: Loop until all v4 remaining bytes are written: emit 4096-byte (or fewer) zero chunks. [source:raw]
    // CALCULATION: Compute chunk size v5 = min(v4, 4096). [source:raw]
    // CALL: sub_58E290(a1, Buffer, v5): write one zero chunk to extend the file. [callee:0x0058E290]
    // GUARD: If a write returned -1, break out of the loop as a failure. [source:raw]
    // CALCULATION: Decrement the remaining delta: v4 -= bytesWritten. [source:raw]
    // GUARD: If the TLS secondary error slot equals 5 (access denied), promote to primary error code 13. [callee:0x0058AFD8]
    // CALL: TLSOffsetGetter(): store error code 13 into the primary TLS error slot. [callee:0x0058AFCF]
    // ASSIGNMENT: Mark failure: v2 = -1. [source:raw]
    // CALL: BitfieldManager(a1, savedFlags): restore the previously saved bitfield flags. [callee:0x0059801A]
    // CALL: FileSeekViaSetFilePointer(a1, v12, 0): restore the original file position. [callee:0x0058C789]
    // RETURN: Return v2: 0 on success, -1 on failure. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_59797B(int fd, LONG targetSize) {
    //     int ret = 0;
    //     LONG cur = FileSeekViaSetFilePointer(fd, 0, SEEK_CUR);
    //     if (cur == -1) return -1;
    //     LONG end = FileSeekViaSetFilePointer(fd, 0, SEEK_END);
    //     if (end == -1) return -1;
    //     int delta = targetSize - end;
    //     if (delta < 0) {
    //       FileSeekViaSetFilePointer(fd, targetSize, SEEK_SET);
    //       if (!SetEndOfFile((HANDLE)sub_595A1F(fd))) {
    //         *TLSOffsetGetter() = 13; *TLSOffsetGetter_afd8() = GetLastError(); ret = -1; }
    //     } else if (delta > 0) {
    //       sub_58BB10(buf, 0, 0x1000);
    //       LONG savedFlags = BitfieldManager(fd, 0x8000);
    //       while (delta > 0) {
    //         int n = delta < 4096 ? delta : 4096;
    //         int w = sub_58E290(fd, buf, n);
    //         if (w == -1) break;
    //         delta -= w;
    //       }
    //       if (delta > 0) { if (*TLSOffsetGetter_afd8() == 5) *TLSOffsetGetter() = 13; ret = -1; }
    //       BitfieldManager(fd, savedFlags);
    //     }
    //     FileSeekViaSetFilePointer(fd, cur, SEEK_SET);
    //     return ret;
    //   }
    // UNRESOLVED: BitfieldManager flag 0x8000 semantics and why the flag state is saved/restored around the grow path are unknown.
    // UNRESOLVED: The distinction between the two TLS error slots (TLSOffsetGetter vs TLSOffsetGetter_afd8) and the error-code-13 meaning are asserted by prior analysis only.
    // UNRESOLVED: sub_58E290's exact write semantics (raw WriteFile vs buffered) are not established here.
    // UNRESOLVED: sub_595A1F's handle derivation from the descriptor is not inspected.
}
