// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00485960
// Canonical corpus name: UIListObjectDestructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIListObjectDestructor_00485960.c

void UnknownObject::UIListObjectDestructor()
{
    // Destructor for a UI list object: frees three buffer pointers at this+0x150, +0x158 and +0x160 if non-null, runs ConditionalDualCleanup on the sub-objects at this+224 and this+280, chains to the base-class destructor sub_485EB0, and frees the object itself when flag bit a2&1 is set.
    // ASSIGNMENT: Destructor entry for the UI list object (ABI tag UI_List_Object_Destructor); this is the instance being destroyed. [function:0x00485960, abi:lead]
    // GUARD: If the buffer pointer at this+0x160 is non-null, free it with FreeWrapper_7bcf. [field:this:0x00000160, callee:0x00587BCF, source:raw]
    // GUARD: If the buffer pointer at this+0x158 is non-null, free it with FreeWrapper_7bcf. [field:this:0x00000158, callee:0x00587BCF, source:raw]
    // GUARD: If the buffer pointer at this+0x150 is non-null, free it with FreeWrapper_7bcf. [field:this:0x00000150, callee:0x00587BCF, source:raw]
    // CALL: ConditionalDualCleanup on the two-field sub-object at this+280 (0x118). [callee:0x00499B50, source:raw]
    // CALL: ConditionalDualCleanup on the two-field sub-object at this+224 (0xE0). [callee:0x00499B50, source:raw]
    // CALL: Chain to the base-class destructor sub_485EB0(this). [callee:0x00485EB0, source:raw]
    // GUARD: If (a2 & 1) != 0, free the object itself with FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // RETURN: Return the object pointer this. [source:raw]

    // Conservative worker pseudocode:
    //   int UIListObjectDestructor(int this, char flags) {
    //     if (*(void**)(this + 0x160)) FreeWrapper_7bcf(*(void**)(this + 0x160));
    //     if (*(void**)(this + 0x158)) FreeWrapper_7bcf(*(void**)(this + 0x158));
    //     if (*(void**)(this + 0x150)) FreeWrapper_7bcf(*(void**)(this + 0x150));
    //     ConditionalDualCleanup(this + 0x118);
    //     ConditionalDualCleanup(this + 0xE0);
    //     sub_485EB0(this);
    //     if (flags & 1) FreeWrapper_7bcf(this);
    //     return this;
    //   }
    // UNRESOLVED: Purpose of the three freed buffers (0x150/0x158/0x160) is not evidenced; likely per-column data arrays of the list.
    // UNRESOLVED: Sub-object layout cleaned by ConditionalDualCleanup at this+224 and this+280 is unknown.
}
