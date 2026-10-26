// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C1E20
// Canonical corpus name: sub_4C1E20
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4C1E20_004c1e20.c

void UnknownObject::PitStopCleanupConditionalFree()
{
    // Pit-stop destructor-style method: runs PitStopMemoryCleanup on the object, then conditionally frees the wrapper when the low bit of the flag argument a2 is set; always returns the object pointer.
    // CALL: Call PitStopMemoryCleanup(this) to release the object's pit-stop memory resources. [callee:0x004C0B10, source:raw]
    // GUARD: Test the flag argument a2: the free path runs only when bit 0 of a2 is set. [source:raw]
    // CALL: Call FreeWrapper_7bcf(this) to release the wrapper allocation when the low-bit flag is set. [callee:0x00587BCF, source:raw]
    // RETURN: Return the this pointer unchanged as the result of the method. [source:raw]

    // Conservative worker pseudocode:
    //   void* PitStopCleanupConditionalFree(void* this, char a2) {
    //     PitStopMemoryCleanup(this);
    //     if (a2 & 1) FreeWrapper_7bcf(this);
    //     return this;
    //   }
}
