// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00478140
// Canonical corpus name: FieldFreeCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FieldFreeCleanup_00478140.c

void UnknownObject::FieldFreeCleanup()
{
    // Object cleanup/destructor-style routine: frees the child pointer stored at this+0xE8 when non-null via FreeWrapper_7bcf, runs the sub-cleanup routine sub_485EB0 on this, and finally frees the this object itself via FreeWrapper_7bcf when the a2 bit-0 flag is set. Returns the this pointer.
    // GUARD: Guard on the child pointer at this+0xE8: it is only freed when it is non-null. [field:this:0x000000E8, source:raw]
    // CALL: Free the child pointer at this+0xE8 with FreeWrapper_7bcf when it is non-null. [callee:0x00587BCF, field:this:0x000000E8]
    // CALL: Run the object's sub-cleanup routine sub_485EB0 on this to release owned sub-resources. [callee:0x00485EB0, function:0x00478140]
    // GUARD: Guard on the a2 bit-0 flag: the this object is only freed when (a2 & 1) is set. [source:raw]
    // CALL: Free the this object itself with FreeWrapper_7bcf when the a2 bit-0 flag is set. [callee:0x00587BCF, function:0x00478140]
    // RETURN: Return the this pointer. [function:0x00478140, source:raw]

    // Conservative worker pseudocode:
    //   void FieldFreeCleanup(UnknownObject* this, char a2) {
    //     if (this->child) FreeWrapper_7bcf(this->child);
    //     sub_485EB0(this);
    //     if (a2 & 1) FreeWrapper_7bcf(this);
    //   }
    // UNRESOLVED: The type and meaning of the child pointer at this+0xE8 are not evidenced; it is only shown to be freed when non-null.
    // UNRESOLVED: The a2 bit-0 flag semantics (e.g. delete-with-flag versus keep-alive) are not documented by packet evidence.
    // UNRESOLVED: Whether this routine is a destructor called via vtable or a standalone cleanup is not evidenced (no static callers).
}
