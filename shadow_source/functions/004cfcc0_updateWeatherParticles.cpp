// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CFCC0
// Canonical corpus name: WeatherParticleUpdate
// Owner: WeatherParticleSystem [DERIVED]
// Raw source: functions/WeatherParticleUpdate_004cfcc0.c

void WeatherParticleSystem::updateWeatherParticles()
{
    // Main weather particle system update. Sorts drivers by distance, then either spawns wind-affected weather particles (when the enable flag is clear or the packed flag reads active) or only refreshes low-type subsystems. Computes a wind offset vector and visibility distance from the camera/session data obtained through VirtualDispatchHelper, then updates every emitter child with rotation and scaling. Called from GamePostMainLoop and StateTriggerCheck.
    // CALL: SortDriversByDistance is invoked with the global at 0x8AC4E0 so weather spawn/update distance ranking is fresh. [callee:0x004C9C00, global:0x008AC4E0, source:raw]
    // GUARD: Branch on (!byte_7C56AC || PackedFlagRead_9a00(&dword_8AB6EC)): the enable flag at 0x7C56AC clear, or the packed flag at 0x8AB6EC read as active, selects the wind-spawner path; otherwise the subsystem-only refresh path runs. [global:0x007C56AC, callee:0x004B9A00, global:0x008AB6EC, source:raw]
    // GUARD: If flt_8AFEE4 > 0.0 and the spawner pointer at this+0x1C is non-null, the wind-based particle spawn is performed. [global:0x008AFEE4, field:this:0x0000001C, source:raw]
    // CALCULATION: VirtualDispatchHelper(&dword_5EA510) returns a camera/session vector; compute the wind offset as (v[9]*0.25 - v[3], v[10]*0.25 - v[4], v[11]*0.25 - v[5]). [global:0x005EA510, callee:0x0040C870, source:raw]
    // CALL: sub_4CC970 is called with the spawner pointer this+0x1C, the computed wind offset vector, and flt_8AFEE4 as arguments. [callee:0x004CC970, field:this:0x0000001C, global:0x008AFEE4, source:raw]
    // LOOP: Iterate the particle subsystem array guarded by this+0x10 > 0: for each of this+0x10 subsystems, walking the array at this+0x14 in 108-byte strides, call sub_4CDB20(element, flt_8AFEE4). [guard:1, field:this:0x00000010, field:this:0x00000014, callee:0x004CDB20, global:0x008AFEE4, source:raw]
    // LOOP: Else branch: iterate the same this+0x10 subsystem array (base this+0x14, 108-byte stride) and call sub_4CDB20(element, a2) only for elements whose DWORD at +4 is <= 5. [guard:1, field:this:0x00000010, field:this:0x00000014, callee:0x004CDB20, source:raw]
    // GUARD: If dword_8AB6E4 == 2, derive the emitter fade value from the scoring/session data; otherwise use the default dbl_8AFE98. [global:0x008AB6E4, source:raw]
    // CALL: When dword_8AB6E4 == 2, VehicleDataAccessor(&dword_8AB6EC) is queried; a return of 5 resets the fade value v22 to 0.0. [global:0x008AB6EC, callee:0x004B9E30, source:raw]
    // CALL: Otherwise FloatDifference(&dword_8AB6EC) produces the fade value v22. [global:0x008AB6EC, callee:0x004B9CF0, source:raw]
    // ASSIGNMENT: When dword_8AB6E4 != 2, the fade value v22 is taken from the double global dbl_8AFE98. [global:0x008AFE98, source:raw]
    // CALCULATION: Second VirtualDispatchHelper(&dword_5EA510) call builds the camera direction vector as the negation of v[3], v[4], v[5], and computes the visibility value as max(0, 430.0 - 4.0 * length(v[9], v[10], v[11])). [global:0x005EA510, callee:0x0040C870, source:raw]
    // LOOP: Iterate the emitter children guarded by this+0x0 > 0: for each of this+0x0 children, walking the child array at this+0x4 in 60-byte strides, call ParticleEmitterChildUpdateWithRotationAndScaling(child, v22, &cameraVector, visibility). [guard:0, field:this:0x00000000, field:this:0x00000004, callee:0x004CA2D0, source:raw]
    // RETURN: Return the emitter child count read from this+0x0. [field:this:0x00000000, source:raw]

    // Conservative worker pseudocode:
    //   int WeatherParticleSystem::updateWeatherParticles(double a2) {
    //     SortDriversByDistance(scenePool);
    //     if (!enableFlag || PackedFlagRead(&packedFlags)) {
    //       if (rainFade > 0.0 && spawner) {
    //         vec3 wind = (cam[9]*0.25 - cam[3], cam[10]*0.25 - cam[4], cam[11]*0.25 - cam[5]);
    //         spawnWindParticle(spawner, wind, rainFade);
    //       }
    //       for (i = 0; i < subsystemCount; ++i) updateSubsystem(&subsystems[i*108], rainFade);
    //     } else {
    //       for (i = 0; i < subsystemCount; ++i)
    //         if (subsystems[i*108].type <= 5) updateSubsystem(&subsystems[i*108], a2);
    //     }
    //     if (scoringGate == 2)
    //       fade = (VehicleDataAccessor(&scoring) == 5) ? 0.0 : FloatDifference(&scoring);
    //     else
    //       fade = defaultFade;
    //     vec3 dir = (-cam[3], -cam[4], -cam[5]);
    //     float vis = max(0.0, 430.0 - 4.0 * length(cam[9], cam[10], cam[11]));
    //     for (i = 0; i < childCount; ++i)
    //       updateEmitterChild(&children[i*60], fade, dir, vis);
    //     return childCount;
    //   }
    // UNRESOLVED: Globals flt_59E440, flt_59E46C, flt_59E7F8 and flt_5ACED4 appear in the deterministic field evidence but have no reference in the raw decompiled source text; their role in this function is unknown.
    // UNRESOLVED: The a2 register argument and the exact meaning of the type guard (element DWORD at +4 <= 5) are DERIVED from the else-branch loop; the subsystem element layout is not otherwise evidenced.
    // UNRESOLVED: Names for globals (scene pool, packed flags, scoring gate, rain fade, default fade, camera/session manager) come from prior DERIVED analysis and are not runtime-confirmed.
}
