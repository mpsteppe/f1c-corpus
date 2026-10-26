// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D5840
// Canonical corpus name: ResourceDestroy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ResourceDestroy_004d5840.c

void UnknownObject::ResourceDestroy()
{
    // File/resource handle destructor. If the handle slot *this is non-zero, clears the handle's state through the state-writer sub_587F64, performs a locked read-back on the handle's owned buffer, closes the underlying file handle with FileCloseWithLock, and resets *this to 0. Returns the result of the file close (or the previous *this when the guard failed).
    // GUARD: If the handle at this+0x0 is non-zero the object is open; the whole cleanup sequence is skipped when it is 0. [field:this:0x00000000, source:raw]
    // CALL: sub_587F64(handle, 0, 0) writes zeroed state data associated with the open handle before the file is closed. [callee:0x00587F64, source:raw]
    // CALL: FileReadWrapperWithLock reads 4 bytes from the handle's owned buffer (this + 6 dwords), confirming or syncing state under lock before close. [callee:0x00588678, source:raw]
    // CALL: FileCloseWithLock closes the underlying file handle with locking; its result becomes the function's return value. [callee:0x00587D02, source:raw]
    // ASSIGNMENT: Reset the open-handle flag: *this = 0, marking the resource as closed. [field:this:0x00000000, source:raw]
    // RETURN: Return the file-close result (or the stale handle value when the object was already closed). [source:raw]
    // CALL: Invoked as teardown by WheelDynamicsInit (0043E230), sub_4A0250 (004A0250) and TelemetryDataDump (004D4A80). [caller:0x0043E230, caller:0x004A0250, caller:0x004D4A80, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4D5840(_DWORD *this) {
    //     int result = *this;
    //     if (*this) {
    //       sub_587F64(*this, 0, 0);
    //       FileReadWrapperWithLock(this + 6, 4, 1, *this);
    //       result = FileCloseWithLock(*this);
    //       *this = 0;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The exact state sub_587F64 zeroes and why 4 bytes are read back after the 8 zero bytes are written is not recoverable from this packet.
    // UNRESOLVED: The owned buffer referenced as this + 6 (dword index) has no separate field entry in the packet evidence.
}
