// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D7940
// Canonical corpus name: sub_4D7940
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4D7940_004d7940.c

void UnknownObject::CloseFileHandleIfPresent()
{
    // Conditional file-handle close callback. Reads the second dword element dword_8AD25C[1] of the global array; when that value is non-zero it is treated as a file handle and passed to FileCloseWithLock (0x00587D02), whose result is returned. When the value is zero the function returns 0 without calling FileCloseWithLock.
    // ASSIGNMENT: result = dword_8AD25C[1] — read the second dword element of the global array. [global:0x008AD25C, source:raw]
    // GUARD: Only proceed to close when the loaded value is non-zero. [global:0x008AD25C, source:raw]
    // CALL: Invoke FileCloseWithLock (0x00587D02) passing dword_8AD25C[1] as the file handle argument. [callee:0x00587D02, global:0x008AD25C, source:raw]
    // RETURN: Return FileCloseWithLock's result on the non-zero path; return 0 when the handle value was zero. [callee:0x00587D02, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4D7940()
    //   {
    //       int result = dword_8AD25C[1];
    //       if (result) {
    //           return FileCloseWithLock(dword_8AD25C[1]);
    //       }
    //       return result;
    //   }
    // UNRESOLVED: dword_8AD25C is used elsewhere as the base of a debug-log object; its second dword element is treated here as a file handle, but the array element type and the meaning of index [1] are not confirmed from this packet alone.
    // UNRESOLVED: FileCloseWithLock's signature and whether it frees or merely locks/closes the handle are not established.
}
