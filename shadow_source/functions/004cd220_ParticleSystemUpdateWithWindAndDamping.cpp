// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CD220
// Canonical corpus name: ParticleSystemUpdateWithWindAndDamping
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ParticleSystemUpdateWithWindAndDamping_004cd220.c

void UnknownObject::ParticleSystemUpdateWithWindAndDamping()
{
    // Full particle-system update. Reads the current wind vector through VirtualDispatchHelper(&dword_5EA510)+36. In vehicle mode (dword_8AB6E4 == 2) the time step comes from FloatDifference(&dword_8AB6EC) unless VehicleDataAccessor(&dword_8AB6EC) reports slot 5, in which case the step is 0; otherwise the step defaults to dbl_8AFE98. dword_8AB6EC is then delegated (Delegation) and the second constant v34 comes from dbl_8AFEA0. For each live particle in the array at this+0x68 (count at this+0x64), a particle whose lifetime falls outside v9[2]..v9[3] is removed with ArrayElementRemoval; surviving particles get velocity integrated with damping and gravity (v9[15] -= fabs(step) * 9.8100004), ground-plane clamping and reflection using the plane normal at v9[21..23] and height v9[25], then optional proximity collision. When (dword_7CFA4C & 3) != 0 the velocity is scaled by 0.03125 and, for mode 1, collides against the player vehicle (dword_7C54E0) AABB at +1776 when within +-4.0; otherwise FindDriversInRange(flt_8AC4E0, z, 5.6568542, &count) gathers nearby vehicles and collides against each whose AABB at +1764 is within +-4.0, skipping the current player slot (dword_7C54DC) unless flag bit 0 is set. Finally every particle is drawn with ParticleEffectBillboardQuadSetup using a velocity delta of (v9[14..16] - wind) * 0.03125. Returns the particle count.
    // CALL: Obtain the wind vector: v3 = VirtualDispatchHelper(&dword_5EA510) + 36, then read the three floats at v3, v3+4 and v3+8 into v39, v40 and v41. [callee:0x0040C870, global:0x005EA510, source:raw]
    // GUARD: Time-step selection: when dword_8AB6E4 == 2 (vehicle mode), VehicleDataAccessor(&dword_8AB6EC) returning 5 forces the step v31 to 0, otherwise v31 = FloatDifference(&dword_8AB6EC); in any other mode v31 defaults to dbl_8AFE98. [global:0x008AB6E4, callee:0x004B9E30, global:0x008AB6EC, callee:0x004B9CF0, global:0x008AFE98, source:raw]
    // CALL: Vehicle-mode delegation: when dword_8AB6E4 == 2, Delegation(&dword_8AB6EC) is invoked; otherwise v34 is initialized to dbl_8AFEA0. [global:0x008AB6E4, callee:0x004B9CE0, global:0x008AB6EC, global:0x008AFEA0, source:raw]
    // LOOP: Iterate every particle index i in 0..count (count = dword 25 of the system, field this+0x64), dereferencing the particle pointer v9 = (float*)system[26] + i (field this+0x68). A particle whose lifetime is outside the window (v34 > v9[3] or v34 < v9[2]) is removed via ArrayElementRemoval(system, particle) and the iteration index is backed up. [field:this:0x00000064, field:this:0x00000068, callee:0x004CB5A0, source:raw]
    // CALCULATION: Velocity integration: position components v9[11..13] are advanced by v31 times velocity v9[14..16], and the vertical velocity v9[15] is reduced by fabs(v31) * 9.8100004 (gravity damping). [source:raw]
    // CALCULATION: Ground-plane clamp: when the signed distance v9[11]*v9[21] + v9[12]*v9[22] + v9[13]*v9[23] falls below the plane height v9[25], the position is projected back onto the plane along the normal v9[21..23], the velocity is reflected about the normal (v9[14..16] -= 2 * dot(normal, velocity) * normal), and then the reflected velocity is either doubled or halved depending on the carry flag v19. [source:raw]
    // GUARD: Proximity collision gate: the collision block runs only when (dword_7CFA4C & 3) != 0, and it first scales the velocity components into v36..v38 by 0.03125. [global:0x007CFA4C, source:raw]
    // GUARD: Player-only collision (dword_7CFA4C == 1): when the player vehicle pointer dword_7C54E0 is non-null, read its position at +1860/+1864/+1868; if the lateral and vertical differences to the particle are both within +-4.0, build a candidate position v63 from the scaled velocity and run F_3DAABBOverlapTestWithSlidingResponse(v63, particle, player AABB at dword_7C54E0+1776). [global:0x007CFA4C, global:0x007C54E0, callee:0x004CBF50, source:raw]
    // LOOP: All-vehicle collision: v23 = FindDriversInRange(flt_8AC4E0, z, 5.6568542, &v35) collects nearby drivers; for each driver j < v35, read its position at +1848/+1852/+1856; when the lateral and vertical differences are within +-4.0 and (flag bit 0 of dword_7CFA4C is set or the driver slot at +4 differs from dword_7C54DC), build candidate v59 and run F_3DAABBOverlapTestWithSlidingResponse(v59, particle, vehicle AABB at +1764). The loop index v7 is restored afterwards. [callee:0x004C9C70, global:0x008AC4E0, global:0x007CFA4C, global:0x007C54DC, callee:0x004CBF50, source:raw]
    // CALL: Rendering: build v62 = (v9[14..16] - wind) * 0.03125 as the velocity-delta quad input and draw the particle with ParticleEffectBillboardQuadSetup(system, v9, v62). [callee:0x004CC500, source:raw]
    // RETURN: Return the particle count (dword 25 of the system) once the update loop has finished. [source:raw]

    // Conservative worker pseudocode:
    //   windBase = VirtualDispatchHelper(&dword_5EA510) + 36;
    //   windX = *(float*)(windBase); windY = *(float*)(windBase + 4); windZ = *(float*)(windBase + 8);
    //   if (dword_8AB6E4 == 2) {
    //     if (VehicleDataAccessor(&dword_8AB6EC) == 5) step = 0.0;
    //     else step = FloatDifference(&dword_8AB6EC);
    //   } else {
    //     step = dbl_8AFE98;
    //   }
    //   if (dword_8AB6E4 == 2) Delegation(&dword_8AB6EC);
    //   else v34 = dbl_8AFEA0;
    //   count = system[25];
    //   for (i = 0; i < count; ++i) {
    //     p = system[26][i];
    //     if (v34 > p[3] || v34 < p[2]) { ArrayElementRemoval(system, p); --i; continue; }
    //     p[11] += step * p[14]; p[12] += step * p[15]; p[13] += step * p[16];
    //     p[15] -= fabs(step) * 9.8100004;
    //     dist = p[11]*p[21] + p[12]*p[22] + p[13]*p[23];
    //     if (dist < p[25]) {
    //       push = p[25] - dist;
    //       p[11] += push * p[21]; p[12] += push * p[22]; p[13] += push * p[23];
    //       dot = 2 * (p[14]*p[21] + p[15]*p[22] + p[16]*p[23]);
    //       p[14] -= dot * p[21]; p[15] -= dot * p[22]; p[16] -= dot * p[23];
    //       if (carry) { p[14] *= 2; p[15] *= 2; p[16] *= 2; }
    //       else { p[14] *= 0.5; p[15] *= 0.5; p[16] *= 0.5; }
    //     }
    //     if ((dword_7CFA4C & 3) != 0) {
    //       sx = p[14] * 0.03125; sy = p[15] * 0.03125; sz = p[16] * 0.03125;
    //       if (dword_7CFA4C == 1) {
    //         if (dword_7C54E0 && fabs(p[11] - *(float*)(dword_7C54E0 + 1860)) < 4.0 && fabs(*(float*)(dword_7C54E0 + 1868) - p[13]) < 4.0)
    //           F_3DAABBOverlapTestWithSlidingResponse(pos(p[11]+sx, p[12]+sy, p[13]+sz), p + 11, dword_7C54E0 + 1776);
    //       } else {
    //         list = FindDriversInRange(flt_8AC4E0, p[11] + p[13], 5.6568542, &n);
    //         for (j = 0; j < n; ++j) {
    //           v = list[j];
    //           if (fabs(*(float*)(v + 1848) - p[11]) < 4.0 && fabs(*(float*)(v + 1856) - p[13]) < 4.0 &&
    //               ((dword_7CFA4C & 1) != 0 || *(v + 4) != dword_7C54DC))
    //             F_3DAABBOverlapTestWithSlidingResponse(pos(p[11]+sx, p[12]+sy, p[13]+sz), p + 11, v + 1764);
    //         }
    //         i = saved;
    //       }
    //     }
    //     v62 = (p[14] - windX) * 0.03125, (p[15] - windY) * 0.03125, (p[16] - windZ) * 0.03125;
    //     ParticleEffectBillboardQuadSetup(system, p, v62);
    //   }
    //   return count;
    // UNRESOLVED: Globals flt_59E440, flt_59E450, flt_59E46C, flt_59ED18 and flt_5ACEB8 are listed in the packet global table but are not referenced anywhere in the raw source text of this function.
    // UNRESOLVED: The carry-flag branch inside the ground-plane reflection (doubling versus halving the reflected velocity) is reproduced verbatim; the meaning of the source-level v19 flag is not established.
    // UNRESOLVED: The exact meaning of dword_8AB6E4 == 2 (vehicle mode) and VehicleDataAccessor returning 5 (the force-zero path) is DERIVED from the branch structure, not confirmed by this packet.
    // UNRESOLVED: The particle float layout at indices 2..3 (lifetime window), 11..16 (position/velocity), 21..23 (plane normal) and 25 (plane height) is inferred from arithmetic use in the raw text and remains a DERIVED layout.
}
