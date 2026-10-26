// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040FDD0
// Canonical corpus name: ArrayOfObjectsDestructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArrayOfObjectsDestructor_0040fdd0.c

void UnknownObject::ArrayOfObjectsDestructor()
{
    // Destructor for an array of 198-dword objects, or a single such object, selected by flag bits in a2. Bit 2 selects the array path: reads the element count from the header dword at this-1, walks the array backward overwriting each vtable pointer with off_59E720 and calling MultiFieldCleanupDestructor on the sub-object at +53 dwords, then returns the header pointer. The single-object path applies the same vtable/sub-object cleanup to this itself. Bit 1 in a2 additionally frees the backing block via FreeWrapper_7bcf.
    // GUARD: Branch on flag bit 2 of a2: if (a2 & 2) != 0 take the array path, otherwise the single-object path. [source:raw]
    // CALCULATION: Array path: read the element count v3 from the header dword at this-1 and set v4 to the header pointer (this-1). [source:raw]
    // CALCULATION: Array path: compute v5 = this + 198*v3 (pointer one element past the last 198-dword element). [source:raw]
    // GUARD: Array path: guard on (v3 - 1) >= 0; when the count is zero the walk is skipped entirely. [source:raw]
    // LOOP: Array path: do-while loop walking the elements backward (v5 -= 198 dwords each iteration) for v3 iterations. [source:raw]
    // ASSIGNMENT: Array path, per element: overwrite the element vtable pointer (field this 0x0 relative to element base) with &off_59E720. [source:raw, field:this:0x00000000, global:0x0059E720]
    // CALL: Array path, per element: call MultiFieldCleanupDestructor on the sub-object at element base + 53 dwords (0xD4). [source:raw, callee:0x00568E60]
    // GUARD: Array path: guard on flag bit 1 of a2: if (a2 & 1) != 0 free the block. [source:raw]
    // CALL: Array path: call FreeWrapper_7bcf on the header pointer v4 (this-1) when the free flag is set. [source:raw, callee:0x00587BCF]
    // RETURN: Array path: return the header pointer v4 (this-1). [source:raw, function:0x0040FDD0]
    // ASSIGNMENT: Single-object path: overwrite this's own vtable pointer (field this 0x0) with &off_59E720. [source:raw, field:this:0x00000000, global:0x0059E720]
    // CALL: Single-object path: call MultiFieldCleanupDestructor on the sub-object at this + 53 dwords (0xD4). [source:raw, callee:0x00568E60]
    // GUARD: Single-object path: guard on flag bit 1 of a2: if (a2 & 1) != 0 free the block. [source:raw]
    // CALL: Single-object path: call FreeWrapper_7bcf on this when the free flag is set. [source:raw, callee:0x00587BCF]
    // RETURN: Single-object path: return this. [source:raw, function:0x0040FDD0]

    // Conservative worker pseudocode:
    //   DWORD* sub_40FDD0(DWORD* this, char a2) {
    //     if (a2 & 2) {
    //       DWORD count = *(this - 1);
    //       DWORD* head = this - 1;
    //       DWORD* p = &this[198 * count];
    //       for (int i = count - 1; i >= 0; --i) {
    //         p -= 198;
    //         p[0] = (DWORD)&off_59E720;
    //         MultiFieldCleanupDestructor(p + 53);
    //       }
    //       if (a2 & 1) FreeWrapper_7bcf(head);
    //       return head;
    //     }
    //     this[0] = (DWORD)&off_59E720;
    //     MultiFieldCleanupDestructor(this + 53);
    //     if (a2 & 1) FreeWrapper_7bcf(this);
    //     return this;
    //   }
    // UNRESOLVED: The element count header at this-1 is outside the packet's listed field evidence (only field this 0x0 is tracked).
    // UNRESOLVED: Layout and ownership of the 53-dword sub-object destroyed by MultiFieldCleanupDestructor is unknown.
    // UNRESOLVED: Meaning of the two flag bits in a2 (bit 2 = array/single mode, bit 1 = free) is inferred from control flow, not confirmed by an external contract.
    // UNRESOLVED: Caller GraphicsResourceDestructor (0x0040FB30) usage that selects these flags is unexamined.
}
