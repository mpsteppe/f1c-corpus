// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B2DD0
// Canonical corpus name: VehicleOrientationFromEulerAngles
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleOrientationFromEulerAngles_004b2dd0.c

void UnknownObject::VehicleOrientationFromEulerAngles()
{
    // Converts packed Euler/orientation data from the fixed-point struct `this` into a float triple written at a2+8/+12/+16 plus two bitfield-packed values, storing a3 at a2+4 and returning it. Reads int16 components at this+9/+11/+13 scaled by 0.015625, round-trips the output vector through fixed-point and clamped-short conversions, and when the direction vector is non-zero builds an orthonormal orientation basis: unpacks this+0/+2/+4/+8 into a second triple scaled by 0.000030517578, derives a normal with CollisionNormalFromFeature (falling back to a default axis on failure), forms cross-product axes, normalizes, extracts Euler angles via atan2 with a gimbal-singularity case, and packs the result to saturated int16. Finally writes the unpacked float triple and packs the two bitfield parameters. Called by FloatComputation (00464B40) and CollisionStateUpdate (00500010).
    // CALCULATION: Read the three packed int16 orientation components at this+9, this+11 and this+13 and scale each by 0.015625 into v21/v22/v23. [field:this:0x00000009, field:this:0x0000000B, field:this:0x0000000D, source:raw]
    // CALL: Call UtilityFunction_2480(a2+8, &v21) to load the scaled components into the output float vector at a2+8. [callee:0x004B2480, source:raw]
    // CALL: Round-trip the output vector through FloatToFixedConversionWithClamp(a2+8, zeroed buffer) and FloatToShortClampedConversion(a2+8, zeroed buffer). [callee:0x004B25D0, callee:0x004B2750, source:raw]
    // GUARD: Skip the entire orientation-basis computation and Euler extraction when all three scaled components v21, v22 and v23 are zero. [source:raw]
    // CALCULATION: Unpack the packed dwords: v20 = this+0 << 8, v6 = (this+4 << 16) + (word at this+2 & 0xFF00), v7 = (this+4 >> 8) & 0xFFFF00. [field:this:0x00000000, field:this:0x00000002, field:this:0x00000004, source:raw]
    // CALCULATION: Normalize the direction vector: compute 1/sqrt of the squared sum of v21/v22/v23, scale each component by it, then negate all three. [source:raw]
    // CALCULATION: Build the second input triple: v9 = (byte at this+8 << 24) + v7, then scale v20/v6/v9 by 0.000030517578 into v35[0..2]. [field:this:0x00000008, source:raw]
    // CALL: Call CollisionNormalFromFeature(dbl_7C9360, v35, &v24) to derive a collision normal; when it returns 0, fall back to a default axis (v24 = 0.0, v25 = 1.0, v26 = 0.0). [callee:0x0044C550, global:0x007C9360, source:raw]
    // CALCULATION: Build the orthonormal basis: compute cross-product axes from the normalized direction and the normal components, then normalize the resulting axis again. [source:raw]
    // CALL: Call FloatConvertWrapper() to convert an intermediate value with sign handling, then store its negation into v32. [callee:0x00588570, source:raw]
    // CALCULATION: Extract Euler angles: when fabs of the pivot component equals 1.0 use atan2(-v23, v21) with v34 = 0.0, otherwise use atan2(v27, v29) and atan2(v22, v25). [source:raw]
    // CALL: Call FloatToInt16SaturationPack(&v32) to pack the extracted angle component into a saturated int16. [callee:0x004B31A0, source:raw]
    // ASSIGNMENT: Unpack this+0/+4/+8 again (shifted and scaled by 0.000030517578) into the final float triple v13/v14/v31 and write it to a2+8, a2+12 and a2+16. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // CALL: Call TernarySelectByBitfield(this) to select a value from the bitfield and pass it into BitfieldInsert on the output vector at a2+8. [callee:0x004B2BF0, callee:0x004B29B0, source:raw]
    // CALL: Call sub_4B2C50(this) to decode an additional parameter and pack it into the output bitfield with FloatToBitfieldPack. [callee:0x004B2C50, callee:0x004B2930, source:raw]
    // ASSIGNMENT: Write a3 to a2+4 and return a3 as the result. [source:raw]

    // Conservative worker pseudocode:
    //   int VehicleOrientationFromEulerAngles(char* this, char* out, int a3) {
    //     float v21 = (double)*(short*)(this + 9)  * 0.015625;
    //     float v22 = (double)*(short*)(this + 11) * 0.015625;
    //     float v23 = (double)*(short*)(this + 13) * 0.015625;
    //     float* dst = (float*)(out + 8);
    //     UtilityFunction_2480((word*)(out + 8), &v21);
    //     float zero[3] = {0.0, 0.0, 0.0};
    //     FloatToFixedConversionWithClamp(out + 8, zero);
    //     FloatToShortClampedConversion((word*)(out + 8), zero);
    //     if (v21 != 0.0 || v22 != 0.0 || v23 != 0.0) {
    //       int a = *(dword*)this << 8;
    //       int b = (*(dword*)(this + 4) << 16) + (*(word*)(this + 2) & 0xFF00);
    //       int c = (*(dword*)(this + 4) >> 8) & 0xFFFF00;
    //       double inv = 1.0 / sqrt(v22*v22 + v23*v23 + v21*v21);
    //       v22 *= inv; v23 *= inv; v21 *= -inv; v22 *= -1.0; v23 *= -1.0;
    //       int d = ((unsigned char)this[8] << 24) + c;
    //       double v35[3] = { (double)a * 0.000030517578,
    //                         (double)b * 0.000030517578,
    //                         (double)d * 0.000030517578 };
    //       float nx, ny, nz;
    //       if (!CollisionNormalFromFeature(dbl_7C9360, v35, &nx)) { nx = 0.0; ny = 1.0; nz = 0.0; }
    //       float ux = v23*ny - v22*nz, uy = v21*nz - v23*nx, uz = v22*nx - v21*ny;
    //       inv = 1.0 / sqrt(uz*uz + uy*uy + ux*ux);
    //       v21 = ux*inv; v22 = uy*inv; v23 = inv*uz;
    //       float tx = nz*v22 - v23*ny, ty = v23*nx - nz*v21, tz = ny*v21 - v22*nx;
    //       float py = ty;
    //       FloatConvertWrapper();
    //       int packed = -(int)py;
    //       float e1, e2;
    //       if (fabs(ty) == 1.0) { e2 = 0.0; e1 = atan2(-v23, v21); }
    //       else { e1 = atan2(tx, tz); e2 = atan2(v22, ny); }
    //       FloatToInt16SaturationPack(&packed);
    //     }
    //     int w = *(dword*)(this + 4);
    //     float x = (double)(int)(*(dword*)this << 8) * 0.000030517578;
    //     float y = (double)(int)((w << 16) + (*(word*)(this + 2) & 0xFF00)) * 0.000030517578;
    //     float z = (double)(int)(((unsigned char)this[8] << 24) + ((w >> 8) & 0xFFFF00)) * 0.000030517578;
    //     dst[0] = x; dst[2] = z; dst[1] = y;
    //     float sel = TernarySelectByBitfield((int)this);
    //     BitfieldInsert(dst, sel);
    //     float extra = sub_4B2C50((int)this);
    //     int result = FloatToBitfieldPack(dst, extra);
    //     *(dword*)(out + 4) = a3;
    //     return result;
    //   }
    // UNRESOLVED: Globals dbl_59E420, flt_59E43C, flt_59E440, flt_59E670, flt_59E778 and flt_59E780 are recorded as read by this function but do not appear by name in the decompiled text; they are most likely constant operands (for example the 0.000030517578 scale or threshold/zero constants) that Hex-Rays folded, so their exact role here cannot be confirmed from this packet.
    // UNRESOLVED: The concrete types of the packed struct `this` and of the output object at a2 are unknown; offset meanings (Euler angles, orientation basis, bitfield parameters) are inferred from the access pattern.
    // UNRESOLVED: The sign/negation sequence around FloatConvertWrapper and the exact meaning of the two bitfield parameters selected by TernarySelectByBitfield and sub_4B2C50 are not established.
}
