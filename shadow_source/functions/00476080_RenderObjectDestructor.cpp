// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00476080
// Canonical corpus name: RenderObjectDestructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RenderObjectDestructor_00476080.c

void UnknownObject::RenderObjectDestructor()
{
    // __thiscall destructor for a render/HUD node: switches the vtable at this[0] to the child type off_5A4450, frees the child node at offset 0x30 (this[12]) via FreeWrapper_7bcf if non-null, switches the vtable back to the base type off_5A443C, frees the owned resource at offset 0x4 (this[1]) if non-null, then frees the object itself via FreeWrapper_7bcf when destructor flag bit 0 of a2 is set. Returns this.
    // STATE_TRANSITION: Write child-type vtable pointer off_5A4450 into this[0]. [field:this:0x00000000, global:0x005A4450, source:raw]
    // GUARD: Guard on this[12] (offset 0x30) being non-null before freeing the child node. [field:this:0x00000030, source:raw]
    // CALL: Free child node pointer this[12] (offset 0x30) via FreeWrapper_7bcf. [field:this:0x00000030, callee:0x00587BCF, source:raw]
    // STATE_TRANSITION: Write base-type vtable pointer off_5A443C into this[0]. [field:this:0x00000000, global:0x005A443C, source:raw]
    // GUARD: Guard on this[1] (offset 0x4) being non-null before freeing the owned resource. [field:this:0x00000004, source:raw]
    // CALL: Free owned resource pointer this[1] (offset 0x4) via FreeWrapper_7bcf. [field:this:0x00000004, callee:0x00587BCF, source:raw]
    // GUARD: Guard on (a2 & 1) != 0, the destructor-flag bit 0 that enables self-deallocation. [source:raw]
    // CALL: Free the object itself via FreeWrapper_7bcf when the destructor flag bit 0 is set. [callee:0x00587BCF, source:raw]
    // RETURN: Return this. [source:raw]

    // Conservative worker pseudocode:
    //   void* RenderObjectDestructor(void* this, char flags) {
    //     this[0] = &off_5A4450;
    //     if (this[12]) FreeWrapper_7bcf(this[12]);
    //     this[0] = &off_5A443C;
    //     if (this[1]) FreeWrapper_7bcf(this[1]);
    //     if (flags & 1) FreeWrapper_7bcf(this);
    //     return this;
    //   }
    // UNRESOLVED: Concrete class identities behind the two vtable globals off_5A4450 and off_5A443C are not evidenced in this packet.
    // UNRESOLVED: Purpose of the owned resource at offset 0x4 and the child node at offset 0x30 is not evidenced here; caller context is absent.
}
