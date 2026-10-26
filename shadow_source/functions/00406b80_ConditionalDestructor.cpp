// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00406B80
// Canonical corpus name: ConditionalDestructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalDestructor_00406b80.c

void UnknownObject::ConditionalDestructor()
{
    // Scalar-deleting destructor for an unknown object with complex teardown. Calls the object's destructor body (callee 0x00406BA0, which releases four linked lists) on this, then frees the object memory through FreeWrapper (0x00587BCF) when the deleting flag a2 has bit 0 set. Returns this.
    // CALL: Call the destructor body at 0x00406BA0 (ComplexDestructorWith4LinkedLists) with this as the __thiscall receiver. [callee:0x00406BA0, abi:lead]
    // GUARD: Guard on the deleting flag a2: when (a2 & 1) != 0 the object memory is freed; otherwise this is returned without freeing. [source:raw]
    // CALL: Call FreeWrapper at 0x00587BCF with this to release the object allocation when the deleting flag is set. [callee:0x00587BCF]
    // RETURN: Return this, keeping the object pointer valid as required by the scalar-deleting destructor convention. [function:0x00406B80, source:raw]

    // Conservative worker pseudocode:
    //   void* ConditionalDestructor(void* this, char a2) {
    //     ComplexDestructorWith4LinkedLists(this);
    //     if (a2 & 1) FreeWrapper_7bcf(this);
    //     return this;
    //   }
    // UNRESOLVED: The object class that this destructor belongs to is not evidenced in this packet; the owner is UnknownObject.
    // UNRESOLVED: The exact content torn down by ComplexDestructorWith4LinkedLists (0x00406BA0) lives in that callee and is not evidenced here.
}
