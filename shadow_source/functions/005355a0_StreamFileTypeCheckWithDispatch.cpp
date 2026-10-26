// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005355A0
// Canonical corpus name: StreamFileTypeCheckWithDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StreamFileTypeCheckWithDispatch_005355a0.c

void UnknownObject::StreamFileTypeCheckWithDispatch()
{
    // File-stream close/cleanup with an optional write-flush path. Returns -2 when the stream pointer is NULL. When the mode byte at this+0x5C equals 119 ('w') and FileReadLoop returns 0, runs ArithmeticComparison_55f0 twice to sync the remaining-buffer state between the handle fields (this+0x40 with this+0x4C, and this+0x40 with this+0x8), then always hands the stream to FileHandleDestructorWithModeCheck for final cleanup. Called from file-loader call sites across the vehicle/HDV loader and scene writer paths.
    // GUARD: If this is NULL, return -2 immediately [function:0x005355A0, source:raw]
    // GUARD: Write-flush path is entered only when the mode byte at this+0x5C equals 119 ('w') AND FileReadLoop(this, 4) returns 0; any other mode bypasses the flush logic entirely [field:this:0x0000005C, guard:0]
    // CALL: FileReadLoop(this, 4) flushes the remaining buffered data of the stream; a zero result gates the state-sync block [callee:0x005352D0, source:raw]
    // CALL: ArithmeticComparison_55f0 runs twice, once with (this+0x40, this+0x4C) and once with (this+0x40, this+0x8), syncing the remaining-byte state between the read handle and the two buffer fields in write mode [callee:0x005355F0, field:this:0x00000040, field:this:0x0000004C, field:this:0x00000008]
    // RETURN: Always finishes by calling FileHandleDestructorWithModeCheck((LPVOID *)this) and returning its result; the destructor call target is absent from the packet callee list [function:0x005355A0, source:raw]

    // Conservative worker pseudocode:
    //   if (this == NULL) return -2;
    //   if (this[0x5C] == 119 /* 'w' * / && FileReadLoop(this, 4) == 0) {
    //     ArithmeticComparison_55f0(this[0x40], this[0x4C]);
    //     ArithmeticComparison_55f0(this[0x40], this[0x8]);
    //   }
    //   return FileHandleDestructorWithModeCheck(this);
    // UNRESOLVED: FileHandleDestructorWithModeCheck is called in the final return but its address is not present in the packet callees, so no evidence ref binds it; only its cleanup role is inferable
    // UNRESOLVED: The exact copy/sync semantics of ArithmeticComparison_55f0 (a legacy name) cannot be verified from this packet
    // UNRESOLVED: Meaning of the -2 return for a NULL stream and of the mode != 'w' bypass path is undocumented
    // UNRESOLVED: FileReadLoop is named as a read loop yet gates a write-mode flush; the relationship is ambiguous under the legacy name
}
