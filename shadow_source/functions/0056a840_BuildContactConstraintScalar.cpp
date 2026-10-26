// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0056A840
// Canonical corpus name: sub_56A840
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_56A840_0056a840.c

void UnknownObject::BuildContactConstraintScalar()
{
    // Iterates over contact-constraint entries of the third array (base this+0x240, count this+0x23C, stride 88) and accumulates a scalar constraint value into the force buffer at this+0x224, indexed by each entry's +48 index. The scalar combines cross-product terms of the entry row vector with the body angular velocity (this+0x7C/+0x84/+0x8C), position (this+0x4/+0xC/+0x14), linear velocity (this+0x64/+0x6C/+0x74), a2/a3 dot products, the traction constants dbl_5E5238/dbl_5E5240 and entry-local +56/+64/+72/+80 factors. The entry's +52 byte flag selects subtract vs add into the buffer. Returns the number of entries processed.
    // ASSIGNMENT: Initialize result to 0 and local counter v13 to 0 before the count check. [source:raw]
    // GUARD: Guard on the contact-constraint count at this+0x23C being greater than 0; when zero the loop body is skipped entirely. [guard:0, field:this:0x0000023C]
    // LOOP: do-while loop over contact-constraint entries of the buffer at this+0x240, advancing the byte offset by 88 per entry until the counter reaches the count at this+0x23C. [field:this:0x00000240, field:this:0x0000023C, source:raw]
    // CALCULATION: Compute the three cross-product terms v7, v8, v14 from the entry row vector (entry+24, entry+32, entry+40) and the body angular velocity (this+0x7C, this+0x84, this+0x8C). [field:this:0x0000007C, field:this:0x00000084, field:this:0x0000008C, source:raw]
    // CALCULATION: Compute scalar constraint value v9 as a weighted sum of the body position (this+0x4, this+0xC, this+0x14), body linear velocity (this+0x64, this+0x6C, this+0x74), angular velocity, a2/a3 dot products with the entry vector, traction constants dbl_5E5238/dbl_5E5240 and entry-local +64/+72/+80 factors. [field:this:0x00000004, field:this:0x0000000C, field:this:0x00000014, field:this:0x00000064, field:this:0x0000006C, field:this:0x00000074, field:this:0x0000007C, field:this:0x00000084, field:this:0x0000008C, global:0x005E5238, global:0x005E5240]
    // ASSIGNMENT: Accumulate the scalar into the force buffer at this+0x224, indexed by the entry's +48 dword index: subtract (v9 - dbl_5E5238 * entry+56) when the entry's +52 byte flag is set, add v9 otherwise. [field:this:0x00000224, field:this:0x00000240, global:0x005E5238, source:raw]
    // RETURN: Return the final counter value (number of contact-constraint entries processed). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_56A840(this, a2, a3) {
    //     int result = 0; int i = 0;
    //     if (this->count[0x23C] > 0) {
    //       int off = 0;
    //       do {
    //         entry = this->entries[0x240] + off;
    //         v7  = this[0x84]*entry[+40] - this[0x8C]*entry[+32];
    //         v8  = this[0x8C]*entry[+24] - this[0x7C]*entry[+40];
    //         v14 = this[0x7C]*entry[+32] - this[0x84]*entry[+24];
    //         v9 =
    //           (dbl_5E5238*(this[0x14]+entry[+40]) + a2[0]*entry[+32] - entry[+24]*a2[1]
    //            + v8*this[0x7C] - v7*this[0x84] + (v14+this[0x74])*dbl_5E5240 + a3[2]) * entry[+80]
    //           + (dbl_5E5238*(this[0xC]+entry[+32]) + a3[1] + entry[+24]*a2[2] - a2[0]*entry[+40]
    //            + v7*this[0x8C] - v14*this[0x7C] + (v8+this[0x6C])*dbl_5E5240) * entry[+72]
    //           + (dbl_5E5238*(entry[+24]+this[0x4]) + a3[0] + a2[1]*entry[+40] - a2[2]*entry[+32]
    //            + v14*this[0x84] - v8*this[0x8C] + (v7+this[0x64])*dbl_5E5240) * entry[+64];
    //         buf = this->forceBuffer[0x224];
    //         idx = entry[+48];
    //         if (entry[+52]) buf[idx] -= v9 - dbl_5E5238*entry[+56];
    //         else buf[idx] += v9;
    //         result = ++i; off += 88;
    //       } while (i < this->count[0x23C]);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: byte_5E523C (JointStiffnessDouble per prior analysis) is not read in this function's raw source; its role is unresolved here.
    // UNRESOLVED: The byte flag at constraint-entry +52, the index at entry +48 and the entry-local +56/+64/+72/+80 factors depend on the contact-constraint array layout, which this packet does not define.
    // UNRESOLVED: Exact physical meaning of the a2/a3 input vectors is not confirmed from this packet.
    // UNRESOLVED: The relationship between this third-array contact pass and the first-array pass in sub_56A390 is not established here.
}
