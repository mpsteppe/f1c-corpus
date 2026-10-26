// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CCDC0
// Canonical corpus name: ParticlePositionAdd
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ParticlePositionAdd_004ccdc0.c

void UnknownObject::ParticlePositionAdd()
{
    // Adds a wind/delta offset to every particle position in a particle system. Computes the delta vector a3 - a2 per component, mixes in noise from the weather noise table flt_8AB274 (indexed by the ring-buffer counter dword_8AAE70), then iterates this[25] particles whose pointers live in the array at this[26], adding the offset to each particle's position fields. Finally calls ParticleEffectPhysics(this, accumulated) and returns its result.
    // CALCULATION: Compute the delta vector per component: v12 = a3[0]-a2[0], v13 = a3[1]-a2[1], v14 = a3[2]-a2[2]. [source:raw]
    // CALCULATION: Read noise from flt_8AB274 indexed by (unsigned byte)dword_8AAE70, post-increment the counter; v10 = noise + noise + v12 gives the x-offset with noise. [source:raw, global:0x008AB274, global:0x008AAE70]
    // CALCULATION: Second noise read from flt_8AB274 with another dword_8AAE70 increment; v6 = noise + noise + v14 gives the z-offset with noise (y uses the plain delta v13). [source:raw, global:0x008AB274, global:0x008AAE70]
    // LOOP: Iterate over this[25] (offset 0x64) particles with counter v5. [source:raw, field:this:0x00000064]
    // ASSIGNMENT: Resolve each particle pointer from the array at this[26] (offset 0x68) as this[26] + 4*v5. [source:raw, field:this:0x00000068]
    // CALCULATION: Apply offsets to the particle position: v7[11] += v10 (x), v7[12] += v13 (y), v7[13] += v6 (z). [source:raw]
    // CALL: Call ParticleEffectPhysics(this, accumulated z value v6) after the position pass. [source:raw, callee:0x004CCB30]
    // RETURN: Return the result of ParticleEffectPhysics. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4CCDC0(unsigned *sys, float *from, float *to) {
    //     float dx = to[0] - from[0];
    //     float dy = to[1] - from[1];
    //     float dz = to[2] - from[2];
    //     float ox = flt_8AB274[(unsigned char)dword_8AAE70++] * 2.0f + dx;
    //     float oz = flt_8AB274[(unsigned char)dword_8AAE70++] * 2.0f + dz;
    //     float zacc = 0.0f;
    //     for (int i = 0; i < sys[25]; ++i) {
    //       float *p = *(float **)(sys[26] + 4 * i);
    //       p[11] += ox;
    //       p[12] += dy;
    //       zacc += p[13];
    //     }
    //     return ParticleEffectPhysics((int)sys, zacc);
    //   }
    // UNRESOLVED: The y-offset receives the plain delta v13 while x and z receive doubled noise; whether that asymmetry is intentional is unknown.
    // UNRESOLVED: Meaning of the particle position fields at float offsets 11, 12 and 13 is not stated in the packet.
    // UNRESOLVED: The ring-buffer counter dword_8AAE70 is truncated to unsigned byte before indexing flt_8AB274, implying a 256-entry table with wrap-around.
    // UNRESOLVED: The caller MainCameraDirectorUpdate (0x0040CA30) drives this, but the particle system owner type is unknown.
    // UNRESOLVED: Whether a2/a3 are wind origin/destination points or arbitrary vectors is inferred, not evidenced.
}
