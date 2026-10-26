// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00543130
// Canonical corpus name: sub_543130
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_543130_00543130.c

void UnknownObject::BitmapFileResourceLoader()
{
    // Structural twin of BitmapFileLoader: loads a file into an allocated buffer and hands it to ResourceLoadWithOutput(dword_8B78A0, buffer, size, a2, a3, a4) where a2/a3/a4 are output parameters rather than returning a composition. Returns 0 on success, -1 when the resource load fails (buffer already freed/closed), and -2 with a logged "Error opening bitmap file %s" message when the file cannot be opened.
    // CALL: Open the file with mode aRb ("rb") via sub_587DB0(a1, aRb); a null result is the failure signal. [callee:0x00587DB0, global:0x005BE828, source:raw]
    // GUARD: Guard on the open result v4/v5: if zero, fall through to the error-reporting branch. [source:raw]
    // CALL: Seek to the end (sub_587F64(v4, 0, 2)) and query the file size via FileSizeQueryWrapper(v5). [callee:0x00587F64, callee:0x0058ACE6, source:raw]
    // CALL: Rewind the file to the start via sub_587F64(v5, 0, 0). [callee:0x00587F64, source:raw]
    // CALL: Allocate a v7-byte buffer via OperatorNewNhMallocWrapper(v7) and read the entire file into it with ThreadSafeReadWrapper_803f(v8, 1, v7, v5). [callee:0x00587C03, callee:0x0058803F, source:raw]
    // CALL: Close the file handle via FileCloseWithLock(v5). [callee:0x00587D02, source:raw]
    // CALL: Load the resource from the raw buffer via ResourceLoadWithOutput(dword_8B78A0, v8, v7, a2, a3, a4); a nonzero result means load failure. [callee:0x00540050, global:0x008B78A0, source:raw]
    // GUARD: Guard on the load result: nonzero leads to return -1 without freeing the buffer; zero frees the buffer and returns 0. [source:raw]
    // CALL: Free the loaded buffer via FreeWrapper_7bcf(v8) on the success path. [callee:0x00587BCF, source:raw]
    // RETURN: Return -1 on load failure, 0 on success. [source:raw]
    // CALCULATION: On file-open failure, format the message buffer v9 with "Error opening bitmap file %s" via StringFormatWithBufferOverflowCheck. [callee:0x0058815F, global:0x005DBDEC, source:raw]
    // CALL: Log the formatted error via sub_53C590(-2, v9). [callee:0x0053C590, source:raw]
    // RETURN: Return -2 on file-open failure. [source:raw]
    // CALL: Called by sub_5427D0 (0x005427D0) to load a bitmap file resource into caller-supplied outputs. [caller:0x005427D0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_543130(const char *filename, int *a2, int *a3, int a4) {
    //     int f = sub_587DB0(filename, "rb");
    //     if (f) {
    //       sub_587F64(f, 0, 2);
    //       int size = FileSizeQueryWrapper(f);
    //       sub_587F64(f, 0, 0);
    //       void *buf = OperatorNewNhMallocWrapper(size);
    //       ThreadSafeReadWrapper_803f(buf, 1, size, f);
    //       FileCloseWithLock(f);
    //       if (ResourceLoadWithOutput(dword_8B78A0, (int)buf, size, a2, a3, a4)) return -1;
    //       FreeWrapper_7bcf(buf);
    //       return 0;
    //     }
    //     char msg[256];
    //     StringFormatWithBufferOverflowCheck(msg, "Error opening bitmap file %s", filename);
    //     sub_53C590(-2, msg);
    //     return -2;
    //   }
    // UNRESOLVED: Semantics of output parameters a2/a3/a4 consumed by ResourceLoadWithOutput are unknown.
    // UNRESOLVED: Identity of the global dword_8B78A0 (0x008B78A0) is unknown; only observed as the first argument (resource context) to ResourceLoadWithOutput.
    // UNRESOLVED: Relation to the structural twin BitmapFileLoader is confirmed only structurally (per the packet prelabel); the two call different consumer functions (RenderingCompositionSetup vs ResourceLoadWithOutput).
}
