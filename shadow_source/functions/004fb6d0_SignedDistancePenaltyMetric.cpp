// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FB6D0
// Canonical corpus name: sub_4FB6D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4FB6D0_004fb6d0.c

void UnknownObject::SignedDistancePenaltyMetric()
{
    // Signed-distance collision/penalty metric. Given a target position a2, computes the delta against the owner position (this+0x0/0x4/0x8), takes a signed dot product against a direction vector at this+0x20/0x24/0x28, and applies directional bias thresholds at this+0x58 (negative side) and this+0x5C (positive side). It then projects a2 onto the line segments from the owner position to two reference sub-struct positions (via pointers *(this+0x110) and *(this+0x10C)), returning 10.0 when either reference has zero length, and finally returns the maximum of the biased signed distance, both line-projection margins, and abs(Y-delta) minus 3.0.
    // CALCULATION: Compute delta vector v15/v16/v17 = a2 - owner position (this+0x0, this+0x4, this+0x8). [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // CALCULATION: Compute signed dot product v3 = delta . direction, where the direction vector components are read from this+0x20, this+0x24, this+0x28. [field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, source:raw]
    // GUARD: When v3 >= 0.0, base result = v3 - this+0x5C; otherwise base result = -(v3 + this+0x58); the two bias thresholds select the sign-side offset. [field:this:0x00000058, field:this:0x0000005C, source:raw]
    // CALCULATION: Dereference pointer at this+0x110 to obtain sub-struct A position (offsets +0x0/+0x4/+0x8), compute its delta to the owner position, and take its length via sqrt of the squared components. [field:this:0x00000110, field:*(this+0x110):0x00000000, field:*(this+0x110):0x00000004, field:*(this+0x110):0x00000008, source:raw]
    // GUARD: When the sub-struct A length is 0.0, return 10.0. [source:raw]
    // CALCULATION: Compute v18 = (unit vector to sub-struct A) . delta - length; when it exceeds the current result, adopt it as the new result. [field:this:0x00000110, field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // CALCULATION: Dereference pointer at this+0x10C to obtain sub-struct B position (offsets +0x0/+0x4/+0x8), compute its delta and sqrt length. [field:this:0x0000010C, field:*(this+0x10C):0x00000000, field:*(this+0x10C):0x00000004, field:*(this+0x10C):0x00000008, source:raw]
    // GUARD: When the sub-struct B length is 0.0, return 10.0. [source:raw]
    // CALCULATION: Compute v19 = (unit vector to sub-struct B) . delta - length; adopt it as the result when it is larger. [field:this:0x0000010C, field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // CALCULATION: Compute v20 = fabs(Y-delta v16) - 3.0; when it exceeds the current result, return it. [field:this:0x00000004, source:raw]
    // RETURN: Return the running maximum of all distance/penalty terms computed above. [caller:0x00403640, source:raw]

    // Conservative worker pseudocode:
    //   double SignedDistancePenaltyMetric(void* this, float* target) {
    //     dx = target[0] - this[0]; dy = target[1] - this[1]; dz = target[2] - this[2];
    //     dot = dx*this[8] + dy*this[9] + dz*this[10];            // direction +0x20/0x24/0x28
    //     result = (dot >= 0.0) ? dot - this[23] : -(dot + this[22]);  // bias +0x5C / +0x58
    //     for each ref in { *(this+0x110), *(this+0x10C) } {
    //       rx = ref[0]-this[0]; ry = ref[1]-this[1]; rz = ref[2]-this[2];
    //       len = sqrt(rx*rx + ry*ry + rz*rz);
    //       if (len == 0.0) return 10.0;
    //       m = (rx/len)*dx + (ry/len)*dy + (rz/len)*dz - len;
    //       if (result < m) result = m;
    //     }
    //     yterm = fabs(dy) - 3.0;
    //     if (result < yterm) return yterm;
    //     return result;
    //   }
    // UNRESOLVED: Packet ABI lead is Unidentified_Logic_Collision_Impulse_Response_Co (LEGACY) and was not usable for naming.
    // UNRESOLVED: Four globals (flt_59E43C, flt_59E440, flt_59E478, flt_59E5FC) are listed by extraction as read here but never appear in the raw source text; their role in the distance computation is unknown.
    // UNRESOLVED: The two sub-struct pointers at this+0x110 and this+0x10C are unnamed; which geometry (strut endpoints) each represents is unknown.
    // UNRESOLVED: The 10.0 sentinel and the 3.0 Y-axis margin are unexplained constants.
    // UNRESOLVED: Direction vector and bias thresholds at this+0x20..0x28, this+0x58, this+0x5C are read-only here; their writers are external.
}
