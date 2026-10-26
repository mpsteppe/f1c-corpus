// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00566C00
// Canonical corpus name: FileWriteWithBackendDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileWriteWithBackendDispatch_00566c00.c

void UnknownObject::FileWriteWithBackendDispatch()
{
    // Backend-dispatch wrapper on a stream/file object: when the dword at this+0x10 is non-zero it forwards (*this, a2, a3) to BufferedFileReader; otherwise it forwards (a2, 1, a3, *this) to ThreadSafeReadWrapper_803f. Both paths return the selected backend's result.
    // GUARD: Dispatch selector: check the dword this[4] at this+0x10 to choose the buffered path. [source:raw, field:this:0x00000010]
    // CALL: Buffered path: call BufferedFileReader(*this, a2, a3) and return its result. [source:raw, callee:0x00534F90, field:this:0x00000000]
    // CALL: Thread-safe path: call ThreadSafeReadWrapper_803f(a2, 1, a3, *this) and return its result. [source:raw, callee:0x0058803F, field:this:0x00000000]
    // RETURN: Return the result of whichever backend was selected. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_566C00(int *this, int a2, int a3) {
    //     if (this[4])
    //       return BufferedFileReader(*this, a2, a3);
    //     else
    //       return ThreadSafeReadWrapper_803f(a2, 1, a3, *this);
    //   }
    // UNRESOLVED: Canonical name implies a write operation, but both callees are reader/stream consumers; exact backend semantics unresolved.
    // UNRESOLVED: Meaning of the literal 1 argument passed to ThreadSafeReadWrapper_803f and of the this+0x10 selector flag unknown.
    // UNRESOLVED: Field table uses this+0x10 for this[4]; the second field this+0x0 is the file handle/base pointer.
}
