// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00587F90
// Canonical corpus name: FileTellSeekPositionQuery
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileTellSeekPositionQuery_00587f90.c

void UnknownObject::tellSeekFilePosition()
{
    // CRT-style file seek/tell. Validates that the state flags at a1+0xC have bits 0x83 set (open/writeable) and the seek mode a3 is <= 2; on the valid path it clears bit 0x10 of the flags, adds the current position (sub_58AD08) to the offset when a3 == 1 (seek relative to current), flushes buffered writes via BufferFlushWrite, and after a write-state check either sets the internal buffer size at a1+0x18 to 512 or clears the low two flag bits. The OS seek sub_58C724 on the handle at a1+0x10 returns the final position, mapped to 0 on success and -1 on failure. The invalid path sets errno via TLSOffsetGetter to 22 (EINVAL) and returns -1.
    // ASSIGNMENT: Read the file state flags v3 from a1+0xC as the first condition input. [field:this:0x0000000C]
    // GUARD: Guard on the file state and seek mode: (v3 & 0x83) != 0 and a3 <= 2 must both hold to enter the seek path. [field:this:0x0000000C]
    // ASSIGNMENT: Clear bit 0x10 of the state flags: LOBYTE(v3) = v3 & 0xEF, written back to a1+0xC. [field:this:0x0000000C]
    // GUARD: Guard on the seek mode a3 == 1: when relative-to-current, add the current file position to the offset. [source:raw]
    // CALL: sub_58AD08(a1) reads the current file position (tell) and adds it to a2; v4 is set to 0 for this case. [callee:0x0058AD08]
    // CALL: BufferFlushWrite(a1) flushes buffered data before the OS seek executes. [callee:0x0058A05A]
    // GUARD: Re-read v5 from a1+0xC; when (v5 & 0x80) == 0, and bits 0x1 and 0x8 are set while bit 0x400 is clear, set the internal buffer size at a1+0x18 to 512. [field:this:0x0000000C, field:this:0x00000018]
    // ASSIGNMENT: When (v5 & 0x80) != 0, clear the low two flag bits: LOBYTE(v5) = v5 & 0xFC, written back to a1+0xC. [field:this:0x0000000C]
    // CALL: sub_58C724(handle at a1+0x10, a2, v4) performs the OS seek; the comparison (result != -1) - 1 yields 0 on success and -1 on failure. [callee:0x0058C724, field:this:0x00000010]
    // RETURN: Return the seek result: 0 on success, -1 on OS failure. [function:0x00587F90, source:raw]
    // ASSIGNMENT: On the invalid path (file not open or a3 > 2), set errno to 22 via the TLS offset getter. [callee:0x0058AFCF]
    // RETURN: Return -1 on the invalid path. [source:raw, function:0x00587F90]
    // CALL: Invoked by the locked position-query wrapper sub_587F64. [caller:0x00587F64]

    // Conservative worker pseudocode:
    //   int tellSeekFilePosition(dword* a1, LONG a2, uint a3) {
    //     int v3 = a1[3];
    //     if ((v3 & 0x83) != 0 && a3 <= 2) {
    //       a1[3] = v3 & 0xEF;
    //       if (a3 == 1) { a2 += sub_58AD08(a1); }
    //       BufferFlushWrite(a1);
    //       int v5 = a1[3];
    //       if ((v5 & 0x80) == 0) {
    //         if ((v5 & 1) != 0 && (v5 & 8) != 0 && (v5 & 0x400) == 0)
    //           a1[6] = 512;
    //       } else {
    //         a1[3] = v5 & 0xFC;
    //       }
    //       return (sub_58C724(a1[4], a2, v4) != -1) - 1;
    //     }
    //     *(dword*)TLSOffsetGetter() = 22;
    //     return -1;
    //   }
    // UNRESOLVED: The purpose of clearing bit 0x10 of the state flags and of the low-two-bit clear in the write-state branch is not established beyond this function's behavior.
    // UNRESOLVED: The condition setting a1+0x18 to 512 (bits 0x1, 0x8 set, 0x400 clear) is only observed; its semantic meaning is unknown.
    // UNRESOLVED: The object type of the file stream is unknown; offsets 0xC, 0x10 and 0x18 are treated as state, OS handle and buffer size respectively.
}
