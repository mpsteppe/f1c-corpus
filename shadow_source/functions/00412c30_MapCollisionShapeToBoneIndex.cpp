// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00412C30
// Canonical corpus name: MapCollisionShapeToBoneIndex
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MapCollisionShapeToBoneIndex_00412c30.c

void UnknownObject::MapCollisionShapeToBoneIndex()
{
    // Maps a collision shape identifier (one of 1-12, 15, 20, 25, 30, 35, 40, 50) to a bone index (153-189) by subtracting a boolean flag from a shape-specific base value. On success writes the bone index to output this+0x8 and the result of sub_414180(0) to this+0xC, then returns 1. Returns -1 when a2 is non-zero, when the shape identifier is unrecognized, or when the computed index is negative.
    // ASSIGNMENT: Initialize result to -1 as the default failure value. [source:raw]
    // GUARD: When a2 is non-zero, skip mapping and return the default -1. [source:raw]
    // CALCULATION: Dispatch on shape identifier a3 via the jump table jpt_412C54 and case table byte_412E18; for each recognized case compute v5 = base - (a4 != 0), with bases 189 down to 153 for shapes 1 through 50. [global:0x00412DC8, global:0x00412E18, source:raw]
    // GUARD: Proceed to the write only when the computed bone index v5 is >= 0. [source:raw]
    // ASSIGNMENT: Write the mapped bone index v5 to the output dword at this+0x8. [field:this:0x00000008, source:raw]
    // CALL: Write the result of sub_414180(0) to the output dword at this+0xC. [callee:0x00414180, field:this:0x0000000C, source:raw]
    // STATE_TRANSITION: Set result to 1 after a successful mapping. [source:raw]
    // RETURN: Return 1 on success, or -1 when a2 is non-zero or the shape identifier is unrecognized. [source:raw]

    // Conservative worker pseudocode:
    //   int MapCollisionShapeToBoneIndex(int out, int a2, int shape, char flag) {
    //     int result = -1;
    //     if (!a2) {
    //       int v5;
    //       switch (shape) {
    //         case 1: v5 = 189 - (flag != 0); break;
    //         case 2: v5 = 187 - (flag != 0); break;
    //         case 3: v5 = 185 - (flag != 0); break;
    //         case 4: v5 = 183 - (flag != 0); break;
    //         case 5: v5 = 181 - (flag != 0); break;
    //         case 6: v5 = 179 - (flag != 0); break;
    //         case 7: v5 = 177 - (flag != 0); break;
    //         case 8: v5 = 175 - (flag != 0); break;
    //         case 9: v5 = 173 - (flag != 0); break;
    //         case 10: v5 = 171 - (flag != 0); break;
    //         case 11: v5 = 169 - (flag != 0); break;
    //         case 12: v5 = 167 - (flag != 0); break;
    //         case 15: v5 = 165 - (flag != 0); break;
    //         case 20: v5 = 163 - (flag != 0); break;
    //         case 25: v5 = 161 - (flag != 0); break;
    //         case 30: v5 = 159 - (flag != 0); break;
    //         case 35: v5 = 157 - (flag != 0); break;
    //         case 40: v5 = 155 - (flag != 0); break;
    //         case 50: v5 = 153 - (flag != 0); break;
    //         default: return result;
    //       }
    //       if (v5 >= 0) {
    //         *(int *)(out + 8) = v5;
    //         *(int *)(out + 12) = sub_414180(0);
    //         result = 1;
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Semantics of sub_414180(0) and the meaning of the secondary value written to this+0xC.
    // UNRESOLVED: Meaning of a2 (which must be zero) and of the boolean flag a4.
    // UNRESOLVED: The receiver layout: this+0x8 and this+0xC are the only two dwords touched.
}
