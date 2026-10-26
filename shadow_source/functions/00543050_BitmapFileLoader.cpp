// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00543050
// Canonical corpus name: sub_543050
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_543050_00543050.c

void UnknownObject::BitmapFileLoader()
{
    // Loads a bitmap file into a freshly allocated buffer and hands the raw bytes to RenderingCompositionSetup for surface/composition initialization. Opens the file with mode string aRb ("rb") via sub_587DB0, seeks to the end to query its size, rewinds, allocates v7 bytes, reads the whole file, and closes it. On setup success the buffer is freed and 0 is returned; on setup failure -1 is returned; when the file cannot be opened a formatted "Error opening bitmap file %s" message is logged through sub_53C590 and -2 is returned.
    // CALL: Open the file with mode aRb ("rb") via sub_587DB0(a2, aRb); a null result is the failure signal. [callee:0x00587DB0, global:0x005BE828, source:raw]
    // GUARD: Guard on the open result v4/v5: if zero, fall through to the error-reporting branch. [source:raw]
    // CALL: Seek to the end (sub_587F64(v4, 0, 2)) and query the file size via FileSizeQueryWrapper(v5). [callee:0x00587F64, callee:0x0058ACE6, source:raw]
    // CALL: Rewind the file to the start via sub_587F64(v5, 0, 0). [callee:0x00587F64, source:raw]
    // CALL: Allocate a v7-byte buffer via OperatorNewNhMallocWrapper(v7) and read the entire file into it with ThreadSafeReadWrapper_803f(v8, 1, v7, v5). [callee:0x00587C03, callee:0x0058803F, source:raw]
    // CALL: Close the file handle via FileCloseWithLock(v5). [callee:0x00587D02, source:raw]
    // CALL: Initialize the rendering composition from the raw buffer via RenderingCompositionSetup(dword_8B78A0, v8, v7, this, a3, 0); a nonzero result means setup failed. [callee:0x0053FED0, global:0x008B78A0, source:raw]
    // GUARD: Guard on the setup result: nonzero leads to return -1 without freeing the buffer; zero frees the buffer and returns 0. [source:raw]
    // CALL: Free the loaded buffer via FreeWrapper_7bcf(v8) on the success path. [callee:0x00587BCF, source:raw]
    // RETURN: Return -1 on setup failure, 0 on success. [source:raw]
    // CALCULATION: On file-open failure, format the message buffer v9 with "Error opening bitmap file %s" via StringFormatWithBufferOverflowCheck. [callee:0x0058815F, global:0x005DBDEC, source:raw]
    // CALL: Log the formatted error via sub_53C590(-2, v9). [callee:0x0053C590, source:raw]
    // RETURN: Return -2 on file-open failure. [source:raw]
    // CALL: Called by sub_542EC0 (0x00542EC0) to load a bitmap resource. [caller:0x00542EC0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_543050(void *this, const char *filename, int a3) {
    //     int f = sub_587DB0(filename, "rb");
    //     if (f) {
    //       sub_587F64(f, 0, 2);
    //       int size = FileSizeQueryWrapper(f);
    //       sub_587F64(f, 0, 0);
    //       void *buf = OperatorNewNhMallocWrapper(size);
    //       ThreadSafeReadWrapper_803f(buf, 1, size, f);
    //       FileCloseWithLock(f);
    //       if (RenderingCompositionSetup(dword_8B78A0, (int)buf, size, this, a3, 0)) return -1;
    //       FreeWrapper_7bcf(buf);
    //       return 0;
    //     }
    //     char msg[256];
    //     StringFormatWithBufferOverflowCheck(msg, "Error opening bitmap file %s", filename);
    //     sub_53C590(-2, msg);
    //     return -2;
    //   }
    // UNRESOLVED: Identity of the global dword_8B78A0 (0x008B78A0) is unknown; it is only observed as the first argument (rendering context) to RenderingCompositionSetup.
    // UNRESOLVED: Owner class of 'this' is unknown; it is passed through to RenderingCompositionSetup without field access in this function.
    // UNRESOLVED: Whether the caller owns or reuses the 'this' object for the resulting composition is not established.
}
