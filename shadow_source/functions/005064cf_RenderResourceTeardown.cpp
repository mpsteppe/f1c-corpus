// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005064CF
// Canonical corpus name: RenderResourceTeardown
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RenderResourceTeardown_005064cf.c

void UnknownObject::RenderResourceTeardown()
{
    // Tears down render resources: optionally runs a vtable+112 copy operation when this[1], this[2], this[3] are all valid and flag bit 0 of this[0] is clear, then releases this[2] and this[3] through their vtable+8 methods, clears this[1]/this[2]/this[3] to 0, and returns 0. Called by D3DTextureSurfaceLockCopy (0x00506559).
    // ASSIGNMENT: Load this[2] (offset 0x8) into v2 [field:this:0x00000008, source:raw]
    // GUARD: If v2 is null, fall back to this[1] (offset 0x4); continue only if the selected pointer is non-null [field:this:0x00000008, field:this:0x00000004, source:raw]
    // CALL: Invoke vtable+40 (offset 0x28) method on the selected interface [field:*(this+0x8):0x00000028, source:raw]
    // GUARD: If this[1] (0x4), this[2] (0x8) and this[3] (0xC) are all non-null [field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // GUARD: If flag bit 0 of this[0] is not set [field:this:0x00000000, source:raw]
    // CALL: Invoke vtable+112 (offset 0x70) copy method on this[3] with arguments (this[3], this[2], 0, 0, this[1], 0) [field:*(this+0xC):0x00000070, source:raw]
    // CALL: Release this[2] via its vtable+8 method [field:*(this+0x8):0x00000008, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Clear this[2] (offset 0x8) to 0 [field:this:0x00000008, source:raw]
    // CALL: Release this[3] via its vtable+8 method [field:*(this+0xC):0x00000008, field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Clear this[3] (offset 0xC) to 0 [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Clear this[1] (offset 0x4) to 0 [field:this:0x00000004, source:raw]
    // RETURN: Return 0 [source:raw]

    // Conservative worker pseudocode:
    //   if (this[2] || (v2 = this[1])) (*this[2]->vtbl[10])(v2);
    //   if (this[1] && this[2] && this[3] && !(this[0] & 1)) (*this[3]->vtbl[28])(this[3], this[2], 0, 0, this[1], 0);
    //   if (this[2]) { (*this[2]->vtbl[2])(this[2]); this[2] = 0; }
    //   if (this[3]) { (*this[3]->vtbl[2])(this[3]); this[3] = 0; }
    //   this[1] = 0;
    //   return 0;
    // UNRESOLVED: Identities of the vtable+40 and vtable+112 methods (likely copy/surface-transfer) are not grounded in packet evidence.
    // UNRESOLVED: Ownership class of the render resource container not established.
    // UNRESOLVED: Meaning of the other flag bits in this[0] not grounded.
}
