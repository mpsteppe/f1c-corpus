// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E16F0
// Canonical corpus name: ParticleEffectWorldTransform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ParticleEffectWorldTransform_004e16f0.c

void UnknownObject::ParticleEffectWorldTransform()
{
    // Transforms up to 17 particle-emitter positions from local to world space and spawns particles. Guards on the global particle-system pointer dword_8ACEB8; when it is non-null, iterates an emitter array of 17 slots starting at this+0x998 (this + 614 floats), each slot 7 floats wide (28 bytes). For every slot whose active-flag byte is non-zero it reads the 3x3 rotation matrix a2 and translation a3, transforms the slot position into world space, and calls ParticleSpawnFunction with the global system, world position, slot data, and the a4 parameter.
    // ASSIGNMENT: Load the global particle-system pointer: v4 = dword_8ACEB8. [global:0x008ACEB8, source:raw]
    // GUARD: Return immediately when dword_8ACEB8 is null (no particle system active). [global:0x008ACEB8, source:raw]
    // ASSIGNMENT: Point v5 at the first emitter slot this + 614 floats (this+0x998) and seed the slot counter to 17. [field:this:0x00000998, source:raw]
    // LOOP: do-while loop over 17 emitter slots; v5 advances by 7 floats (28 bytes) each iteration and the counter decrements until zero. [source:raw]
    // GUARD: Read the active-flag byte at v5 - 8 (v6); when zero, skip this emitter slot. [source:raw]
    // CALCULATION: Rotate the slot position into world space using rows of the 3x3 matrix a2: X = a2[1]*v5[0] + a2[2]*v5[1] + a2[0]*(v5-1), Y = a2[4]*v5[0] + a2[5]*v5[1] + a2[3]*(v5-1), Z = a2[7]*v5[0] + a2[8]*v5[1] + a2[6]*(v5-1), consuming the position components at this+0x998 (v5[0]) and this+0x99C (v5[1]). [field:this:0x00000998, field:this:0x0000099C, source:raw]
    // CALCULATION: Add the translation vector a3: world.X += a3[0], world.Y += a3[1], world.Z += a3[2]. [source:raw]
    // CALL: Call ParticleSpawnFunction(v4, worldPosition, v6, v5 + 2, slotExtraByte, a4) to spawn a particle at the world-space position. [callee:0x004CCE90, source:raw]
    // CALL: Called by sub_4EE2D0 (004EE2D0) as the particle-emitter world transform stage. [caller:0x004EE2D0]

    // Conservative worker pseudocode:
    //   v4 = (float*)dword_8ACEB8;
    //   if (!v4) return;
    //   v5 = this + 614;
    //   for (i = 17; i; --i) {
    //     v6 = *((BYTE*)v5 - 8);
    //     if (v6) {
    //       world.x = a2[1]*v5[0] + a2[2]*v5[1] + a2[0]*(v5-1) + a3[0];
    //       world.y = a2[4]*v5[0] + a2[5]*v5[1] + a2[3]*(v5-1) + a3[1];
    //       world.z = a2[7]*v5[0] + a2[8]*v5[1] + a2[6]*(v5-1) + a3[2];
    //       ParticleSpawnFunction(v4, &world, v6, v5 + 2, *(BYTE*)v5 - 7, a4);
    //     }
    //     v5 += 7;
    //   }
    // UNRESOLVED: dword_8ACEB8 (particle-system pointer), the a2 rotation matrix and a3 translation vector are only named as data locations; their containing object types and purposes are not proven.
    // UNRESOLVED: The emitter slot stride of 7 floats and the exact meanings of the active-flag byte (v5-8), the extra byte (v5-7) and the trailing slot data passed as v5+2 are inferred from the raw layout, not from an independent struct definition.
}
