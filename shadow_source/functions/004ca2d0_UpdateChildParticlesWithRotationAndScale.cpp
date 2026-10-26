// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CA2D0
// Canonical corpus name: ParticleEmitterChildUpdateWithRotationAndScaling
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ParticleEmitterChildUpdateWithRotationAndScaling_004ca2d0.c

void UnknownObject::UpdateChildParticlesWithRotationAndScale()
{
    // Updates child particle positions with a 2D rotation and scaling. Accumulates elapsed time a2 into the time field at +0x14, builds a scale from flt_8AFEE4 and the base/multiplier fields, and computes a rotation angle from accumulated time times the frequency field. Rotated offset components v20/v21 are formed from the sin/cos basis fields. When the child count at +0x34 is positive, loops over the child array at +0x38 (20-byte entries) writing each child target's X, Y, and Z position from the weighted rotated offsets. Finally fetches a display node via LinkedListIndexedAccessor_c230(0) and clears flag bits 0xFEFFFFDF on its +20 field.
    // GUARD: Skip the update when the floating-point condition codes v5/v6 indicate an unordered or failed comparison. [source:raw]
    // ASSIGNMENT: Accumulate time: the float at +0x14 becomes a2 plus its previous value. [source:raw, field:this:0x00000014]
    // CALCULATION: Compute scale v11 = (flt_8AFEE4 * 3.4 + float at +0x18) * float at +0x1C. [global:0x008AFEE4, field:this:0x00000018, field:this:0x0000001C]
    // CALCULATION: Compute rotation angle v12 = accumulated time * float at +0x20; derive sin(v12) and cos(v12). [source:raw, field:this:0x00000020]
    // CALCULATION: Form rotated, scaled offset components v20 and v21 from the rotation basis fields at +0x2C/+0x24 and +0x30/+0x28 multiplied by scale v11. [field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030]
    // LOOP: Loop v7 = int at +0x34 (child count) times over child entries stored at the pointer in +0x38; each 20-byte entry holds a target pointer, X/Y/Z offsets and a weight. [field:this:0x00000034, field:this:0x00000038]
    // CALCULATION: For each child, write the target position: X = v20 * weight + offsetX, Y = offsetY, Z = v21 * weight + offsetZ. [source:raw]
    // CALL: LinkedListIndexedAccessor_c230(0) fetches a display node; when non-null, clear flag bits 0xFEFFFFDF on its +20 field. [callee:0x0054C230]

    // Conservative worker pseudocode:
    //   void sub_4CA2D0(int this, float dt, int a3, float a4) {
    //     if (unordered_compare_result) return;
    //     int childCount = *(int *)(this + 52);
    //     float t = dt + *(float *)(this + 20);
    //     *(float *)(this + 20) = t;
    //     float scale = (flt_8AFEE4 * 3.4f + *(float *)(this + 24)) * *(float *)(this + 28);
    //     float ang = t * *(float *)(this + 32);
    //     float s = sin(ang), c = cos(ang);
    //     float ox = (c * *(float *)(this + 44) + s * *(float *)(this + 36)) * scale;
    //     float oz = (c * *(float *)(this + 48) + s * *(float *)(this + 40)) * scale;
    //     for (int i = 0; i < childCount; i++) {
    //       int *entry = (int *)(*(int *)(this + 56) + i * 20);
    //       float *target = (float *)*entry;
    //       target[0] = ox * ((float *)entry)[4] + ((float *)entry)[1];
    //       target[1] = ((float *)entry)[2];
    //       target[2] = oz * ((float *)entry)[4] + ((float *)entry)[3];
    //     }
    //     int node = LinkedListIndexedAccessor_c230(0);
    //     if (node) *(int *)(node + 20) &= 0xFEFFFFDF;
    //   }
    // UNRESOLVED: flt_59E440 and flt_5ACE98 are listed as referenced globals but do not appear in the visible raw source; their roles here are unknown.
    // UNRESOLVED: The exact geometry (object vs world space) of the rotated offset basis fields is not proven by this packet.
}
