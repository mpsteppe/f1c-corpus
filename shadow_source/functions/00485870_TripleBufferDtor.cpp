// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00485870
// Canonical corpus name: DestructorWithTripleFree
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DestructorWithTripleFree_00485870.c

void UnknownObject::TripleBufferDtor()
{
    // Destructor-style teardown (proposed triple-buffer/owned-pointer cleanup): runs ConditionalDualCleanup on the embedded sub-objects at this+304 and this+224, frees the three owned buffer pointers read at this+296, this+288 and this+280 whenever each is non-null via FreeWrapper_7bcf, chains to the base-class destructor sub_485EB0(this), and when the flags byte a2 has its low bit set frees the this allocation itself (operator-delete pattern). Returns this.
    // CALL: ConditionalDualCleanup((_DWORD*)(this + 304)): clean up the embedded sub-object at offset 304. [callee:0x00499B50, source:raw]
    // GUARD: When the pointer at this + 296 (packet field 0x128) is non-null, free it. [field:this:0x00000128, source:raw]
    // CALL: FreeWrapper_7bcf(*(LPVOID*)(this + 296)): release the owned pointer at 0x128. [callee:0x00587BCF, field:this:0x00000128, source:raw]
    // GUARD: When the pointer at this + 288 (packet field 0x120) is non-null, free it. [field:this:0x00000120, source:raw]
    // CALL: FreeWrapper_7bcf(*(LPVOID*)(this + 288)): release the owned pointer at 0x120. [callee:0x00587BCF, field:this:0x00000120, source:raw]
    // GUARD: When the pointer at this + 280 (packet field 0x118) is non-null, free it. [field:this:0x00000118, source:raw]
    // CALL: FreeWrapper_7bcf(*(LPVOID*)(this + 280)): release the owned pointer at 0x118. [callee:0x00587BCF, field:this:0x00000118, source:raw]
    // CALL: ConditionalDualCleanup((_DWORD*)(this + 224)): clean up the embedded sub-object at offset 224. [callee:0x00499B50, source:raw]
    // CALL: sub_485EB0((LPVOID*)this): chain to the base-class destructor. [callee:0x00485EB0, source:raw]
    // GUARD: When (a2 & 1) != 0, free the this allocation itself. [source:raw]
    // CALL: FreeWrapper_7bcf((LPVOID)this): release the object allocation (operator-delete flag). [callee:0x00587BCF, source:raw]
    // RETURN: Return this. [source:raw]

    // Conservative worker pseudocode:
    //   ConditionalDualCleanup((_DWORD*)(this + 304));
    //   if (*(_DWORD*)(this + 296)) FreeWrapper_7bcf(*(LPVOID*)(this + 296));
    //   if (*(_DWORD*)(this + 288)) FreeWrapper_7bcf(*(LPVOID*)(this + 288));
    //   if (*(_DWORD*)(this + 280)) FreeWrapper_7bcf(*(LPVOID*)(this + 280));
    //   ConditionalDualCleanup((_DWORD*)(this + 224));
    //   sub_485EB0((LPVOID*)this);
    //   if ((a2 & 1) != 0) FreeWrapper_7bcf((LPVOID)this);
    //   return this;
    // UNRESOLVED: The sub-objects cleaned by ConditionalDualCleanup at this+304 and this+224 have no packet field evidence refs; their internal structure is unknown.
    // UNRESOLVED: Whether the freed pointers at 0x118, 0x120 and 0x128 form a triple buffer (proposed name) is not confirmed.
    // UNRESOLVED: The meaning of the a2 flags (the operator-delete low bit) is inferred from the free(this) pattern, not confirmed.
    // UNRESOLVED: The base-class destructor sub_485EB0 semantics are unknown.
    // UNRESOLVED: The owner class is unknown (UnknownObject).
}
