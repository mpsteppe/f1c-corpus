// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E3940
// Canonical corpus name: RepeatedPositionOffsetTransform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RepeatedPositionOffsetTransform_004e3940.c

void UnknownObject::RepeatedPositionOffsetTransform()
{
    // Computes a 3-component position offset vector by subtracting the object's reference position (this+0x48/0x4C/0x50) from the input vector a3, then dispatches that offset to sub_4DEF70 for each element of an array of 748-byte entries beginning at this+2988. The element count is read from this+0xBA8 (2984); if the count is not positive the loop is skipped. Returns the element count.
    // CALCULATION: Compute offset X as a3[0] minus the reference X at this+0x48. [field:this:0x00000048, source:raw]
    // CALCULATION: Compute offset Y as a3[1] minus the reference Y at this+0x4C. [field:this:0x0000004C, source:raw]
    // CALCULATION: Compute offset Z as a3[2] minus the reference Z at this+0x50. [field:this:0x00000050, source:raw]
    // ASSIGNMENT: Assemble the three computed components into a local offset vector. [source:raw]
    // ASSIGNMENT: Read the element count from this+0xBA8. [field:this:0x00000BA8]
    // GUARD: Proceed into the element loop only when the count at this+0xBA8 is greater than 0; otherwise skip it. [field:this:0x00000BA8, source:raw]
    // LOOP: Iterate over elements starting at this+2988, advancing 748 bytes per element, bounded by the count at this+0xBA8. [field:this:0x00000BA8, source:raw]
    // CALL: Dispatch the offset vector to sub_4DEF70 for each element pointer, passing the scalar a2 and output vector a4. [callee:0x004DEF70]
    // RETURN: Return the element count read from this+0xBA8. [function:0x004E3940, field:this:0x00000BA8]

    // Conservative worker pseudocode:
    //   off[0] = a3[0] - this->ref_x;
    //   off[1] = a3[1] - this->ref_y;
    //   off[2] = a3[2] - this->ref_z;
    //   count = this->count;
    //   if (count > 0) {
    //     for (e = this + 2988, k = 0; k < count; ++k, e += 748)
    //       sub_4DEF70(e, a2, off, a4);
    //   }
    //   return count;
    // UNRESOLVED: Purpose and internals of sub_4DEF70, and what the per-element records at stride 748 represent, are not established by this packet.
    // UNRESOLVED: Meaning of the scalar parameter a2 and the output vector a4 depends on sub_4DEF70's contract.
}
