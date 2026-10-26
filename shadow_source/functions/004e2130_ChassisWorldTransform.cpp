// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E2130
// Canonical corpus name: ChassisWorldTransform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ChassisWorldTransform_004e2130.c

void UnknownObject::ChassisWorldTransform()
{
    // Transforms a 3D point by the chassis rotation/scale stored at this+0x14..0x40 combined with per-component scale factors at this+0x918..0x920, then adds a translation read from the three floats preceding the matrix origin (v4[-3..-1], this+0x8..0x10). Result written to output vector a2. Also copies three floats at this+0x14..0x1C as DWORDs into output a3 (quaternion/row copy) and returns a3. No guards; transform always applied.
    // CALCULATION: Compute v3 = this[10] * this[584] (field this+0x28 scaled by component at this+0x920); basis term for the X result. [field:this:0x00000028, field:this:0x00000920, source:raw]
    // CALCULATION: a2[0] = v3 + v4[4]*v4[578] + v4[577]*v4[3] where v4 = this+5; multiplies fields this+0x24/0x20 by scale fields this+0x91C/0x918 plus the v3 term. [field:this:0x00000024, field:this:0x00000020, field:this:0x0000091C, field:this:0x00000918, source:raw]
    // CALCULATION: a2[1] = v4[8]*v4[579] + v4[7]*v4[578] + v4[6]*v4[577]; Y result from fields this+0x34/0x30/0x2C scaled by this+0x920/0x91C/0x918. [field:this:0x00000034, field:this:0x00000030, field:this:0x0000002C, field:this:0x00000920, field:this:0x0000091C, field:this:0x00000918, source:raw]
    // CALCULATION: a2[2] = v4[11]*v4[579] + v4[10]*v4[578] + v4[9]*v4[577]; Z result from fields this+0x40/0x3C/0x38 scaled by this+0x920/0x91C/0x918. [field:this:0x00000040, field:this:0x0000003C, field:this:0x00000038, field:this:0x00000920, field:this:0x0000091C, field:this:0x00000918, source:raw]
    // CALCULATION: Add translation to a2: a2[0] += v4[-3], a2[1] += v4[-2], a2[2] += v4[-1] (three floats immediately preceding the matrix origin, i.e. this+0x8..0x10, not present as packet field evidence). [source:raw]
    // ASSIGNMENT: Copy three DWORDs into a3 from v4[0..2] (fields this+0x14..0x1C): a3[0]=*(DWORD*)v4, a3[1]=*((DWORD*)v4+1), a3[2]=*((DWORD*)v4+2). [field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, source:raw]
    // RETURN: Return a3 (pointer to the copied DWORD triple). [source:raw]

    // Conservative worker pseudocode:
    //   DWORD* ChassisWorldTransform(float* this, float* a2, DWORD* a3) {
    //     double v3 = this[10] * this[584];
    //     float* v4 = this + 5;
    //     a2[0] = (float)(v3 + v4[4]*v4[578] + v4[577]*v4[3]);
    //     a2[1] = v4[8]*v4[579] + v4[7]*v4[578] + v4[6]*v4[577];
    //     a2[2] = v4[11]*v4[579] + v4[10]*v4[578] + v4[9]*v4[577];
    //     a2[0] += v4[-3];
    //     a2[1] += v4[-2];
    //     a2[2] += v4[-1];
    //     a3[0] = *(DWORD*)v4;
    //     a3[1] = *((DWORD*)v4 + 1);
    //     a3[2] = *((DWORD*)v4 + 2);
    //     return a3;
    //   }
    // UNRESOLVED: The translation terms v4[-3..-1] (this+0x8..0x10) used by the a2 += step are not represented in the packet field list; only source:raw evidences them.
    // UNRESOLVED: Whether fields this+0x918..0x920 are per-component scale factors or stored rotation basis vectors.
    // UNRESOLVED: Whether the copied DWORD triple into a3 is semantically a quaternion or the first row of the rotation matrix.
    // UNRESOLVED: Interpretation of the this[10]*this[584] double product folded into the X result.
}
