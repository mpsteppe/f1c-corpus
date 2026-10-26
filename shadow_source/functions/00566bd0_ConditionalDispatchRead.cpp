// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00566BD0
// Canonical corpus name: ConditionalDispatch_6bd0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalDispatch_6bd0_00566bd0.c

void UnknownObject::ConditionalDispatchRead()
{
    // Two-way read dispatcher on a mode flag. Reads dword this[4] (byte offset 0x10); when non-zero it reads from a memory buffer with a timeout via BufferFillWithTimeout(*this, a2, a3), and when zero it reads from a file under lock via FileReadWrapperWithLock(a2, 1, a3, *this). Either way the callee's return value is relayed unchanged to the caller. The dword at offset 0x0 is used as the first argument of both read paths (the resource/handle being read from). Called from a spread of file/stream/network and vehicle routines (SpatialHashKeyGeneration, FileStreamWriter, NetworkBufferRead, VehicleForceAerodynamicsComputation, and others), consistent with a shared read front-end for buffered or file-backed sources.
    // GUARD: Branch on mode flag this[4] (byte offset 0x10): non-zero selects the buffer read path, zero selects the file read path. [field:this:0x00000010, source:raw]
    // CALL: Buffer path: BufferFillWithTimeout(*this, a2, a3) reads into/from the resource identified by dword at offset 0x0, passing a2 and a3 through, with a timeout. [field:this:0x00000000, callee:0x00535220, source:raw]
    // CALL: File path: FileReadWrapperWithLock(a2, 1, a3, *this) reads from the resource identified by dword at offset 0x0 with the constant argument 1 (meaning unknown, possibly a lock/shared flag) and passes a2, a3 through. [field:this:0x00000000, callee:0x00588678, source:raw]
    // RETURN: Return the selected read path's result unchanged: BufferFillWithTimeout's return when this[4] is non-zero, FileReadWrapperWithLock's return when this[4] is zero. [function:0x00566BD0, source:raw]

    // Conservative worker pseudocode:
    //   if (this[4])
    //       return BufferFillWithTimeout(*this, a2, a3);
    //   return FileReadWrapperWithLock(a2, 1, a3, *this);
    // UNRESOLVED: Semantics of the mode flag at offset 0x10 are unknown beyond the evidenced zero/non-zero split; the field is read-only here.
    // UNRESOLVED: The dword at offset 0x0 is only evidenced as the first argument of both read calls; whether it is a handle, buffer pointer or object pointer is unproven.
    // UNRESOLVED: The constant argument 1 passed to FileReadWrapperWithLock is uninterpreted; it may be a lock/shared read flag but no evidence names it.
    // UNRESOLVED: Types and byte-level semantics of a2 and a3 are unverified; they are relayed verbatim to the selected callee.
    // UNRESOLVED: Return semantics (bytes read vs success flag) of BufferFillWithTimeout and FileReadWrapperWithLock are unknown; only that the selected call's return is relayed is evidenced.
}
