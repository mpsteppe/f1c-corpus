// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00499AE0
// Canonical corpus name: FreeIfNonNull
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FreeIfNonNull_00499ae0.c

void UnknownObject::FreeIfNonNull()
{
    // Conditional free of a single pointer member. Reads the pointer stored at this[0]. If it is non-null the pointer is passed to FreeWrapper_7bcf and that call's result is returned; otherwise the function returns the NULL result value unchanged.
    // ASSIGNMENT: Read the pointer at this[0] into result. [source:raw, field:this:0x00000000]
    // GUARD: Guard on the pointer at this[0] being non-null; only then is the free performed. [source:raw, field:this:0x00000000]
    // CALL: Call FreeWrapper_7bcf(*this) to release the pointed-to allocation. [source:raw, callee:0x00587BCF]
    // RETURN: Return the FreeWrapper_7bcf result when the pointer was non-null, otherwise return the NULL value read from this[0]. [source:raw]

    // Conservative worker pseudocode:
    //   LPVOID sub_499AE0(LPVOID* this_) {
    //     LPVOID result = *this_;
    //     if (*this_) return (LPVOID)FreeWrapper_7bcf(*this_);
    //     return result;
    //   }
    // UNRESOLVED: FreeWrapper_7bcf wraps a free operation but its exact behavior (heap free vs reference-count decrement) is not established by this packet.
    // UNRESOLVED: The pointer at this[0] is read but not cleared; whether the caller zeroes it afterwards is outside this function.
    // UNRESOLVED: Owner object identity and the type of allocation released are unknown.
}
