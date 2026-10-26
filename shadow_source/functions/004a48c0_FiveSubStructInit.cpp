// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A48C0
// Canonical corpus name: F_5LoopInitCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_5LoopInitCall_004a48c0.c

void UnknownObject::FiveSubStructInit()
{
    // __thiscall initializer that runs StructInitializer on five consecutive 0x40-byte sub-structures starting at this[6] and advancing by 16 dwords, then zeroes the three DWORD fields at byte offsets 0xC, 0x10 and 0x14, then calls UIComponentCleanup(this) and returns this. Called during physics tire system construction.
    // LOOP: Five-iteration loop: start the element pointer at this[6] (dword index) and advance it by 16 dwords (0x40 bytes) per iteration, seeded with a count of 5. [source:raw]
    // CALL: Call StructInitializer on each sub-structure pointer v2 inside the loop body. [callee:0x0042E1C0, source:raw]
    // ASSIGNMENT: Zero the field at this[3] (byte offset 0xC). [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Zero the field at this[4] (byte offset 0x10). [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Zero the field at this[5] (byte offset 0x14). [field:this:0x00000014, source:raw]
    // CALL: Call UIComponentCleanup(this) after the sub-structure and field initialization. [callee:0x004A4DB0, source:raw]
    // RETURN: Return the initialized this pointer. [source:raw]
    // CALL: Invoked by PhysicsTireSystemConstructor (0x004E4500) as part of physics tire system construction. [caller:0x004E4500, source:raw]

    // Conservative worker pseudocode:
    //   void* FiveSubStructInit(void* this_) {
    //     void* v2 = this_ + 6;
    //     int v3 = 5;
    //     do { StructInitializer(v2); v2 += 16; --v3; } while (v3);
    //     this_[3] = 0;
    //     this_[4] = 0;
    //     this_[5] = 0;
    //     UIComponentCleanup(this_);
    //     return this_;
    //   }
    // UNRESOLVED: Object/class identity is unknown; caller relationship places it in the physics tire system.
    // UNRESOLVED: Meaning of the three zeroed DWORD fields (0xC, 0x10, 0x14) is unknown.
    // UNRESOLVED: Whether UIComponentCleanup here is a true destructor hook or a generic teardown helper is unknown.
}
