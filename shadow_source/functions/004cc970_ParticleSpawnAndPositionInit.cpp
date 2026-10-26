// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CC970
// Canonical corpus name: sub_4CC970
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4CC970_004cc970.c

void UnknownObject::ParticleSpawnAndPositionInit()
{
    // Rain/weather particle spawner. Guarded by the emission count at this+0x58 being positive, it adds wind noise from the table flt_8AB274 (indexed by the wrapping counter dword_8AAE70) onto the caller's x/z position vector a2. It reads a magnitude through Delegation or the constant dbl_8AFEA0 based on the scoring gate dword_8AB6E4, refreshes state via sub_4CC840, computes sqrt(a3) as the fall speed, and derives a per-frame spawn count v9 = (int)(count * scale * sqrt(a3) * 2.5263157) >> shift(this+0x8). For each spawn it allocates a circular-buffer slot via CircularBufferSlotAlloc, initializes the slot's position (noise-table x/z via flt_8ACAA0/flt_8ACAA4 and the wrapping counter dword_8ACEDC), speed/scale fields, a per-type id dereferenced from a table at 9095200 + 40*(slot+84), encodes a packed color/alpha word into slot+96 and renders the slot's bounding box via F_3DBoundingBoxRender. Called once from WeatherParticleUpdate (0x004CFCC0).
    // GUARD: Emit only while the emission count at this+0x58 is greater than 0; otherwise the function does nothing. [field:this:0x00000058, guard:0, source:raw]
    // CALCULATION: Add wind noise to the position vector a2: *a2 += 2*flt_8AB274[(byte)dword_8AAE70++] and a2[2] += 2*flt_8AB274[(byte)dword_8AAE70++], advancing the wrapping noise counter. [global:0x008AB274, global:0x008AAE70, source:raw]
    // CALCULATION: Resolve a scalar magnitude v18: when the scoring gate dword_8AB6E4 equals 2, call Delegation(&dword_8AB6EC), otherwise use the constant dbl_8AFEA0. [global:0x008AB6E4, global:0x008AB6EC, global:0x008AFEA0, callee:0x004B9CE0, source:raw]
    // CALL: Refresh particle-system state for this emitter via sub_4CC840 before spawning. [callee:0x004CC840, source:raw]
    // CALCULATION: Compute the fall factor v19 = sqrt(a3). When dword_8AB6E4 == 2, resolve a difference v8 via VehicleDataAccessor (returning 0.0 when the accessor value is 5) or FloatDifference on dword_8AB6EC; otherwise v8 is the constant dbl_8AFE98. [global:0x008AB6E4, global:0x008AB6EC, global:0x008AFE98, callee:0x004B9E30, callee:0x004B9CF0, source:raw]
    // CALCULATION: Derive the spawn count v9 = (int)((double)*(this+0x58) * v8 * v19 * 2.5263157) >> *(this+0x8); also precompute v20 = v19 * 0.8 as the slot scale factor. Loop while v9 > 0. [field:this:0x00000058, field:this:0x00000008, source:raw]
    // LOOP: Spawn loop: allocate a circular-buffer slot via CircularBufferSlotAlloc(this); initialize slot+8 = v18 and slot+12 = v18 + 0.39583334; advance the wrapping particle counter dword_8ACEDC ((byte)+1 & 0x7F). [callee:0x004CB540, global:0x008ACEDC, source:raw]
    // ASSIGNMENT: Position the slot: slot+44 = flt_8ACAA0[2*idx] + *a2 (x), slot+48 = a2[1] + 8.0 (y), slot+52 = flt_8ACAA4[2*dword_8ACEDC] + a2[2] (z), using the noise tables and counter; also zero slot+56 and slot+64. [global:0x008ACAA0, global:0x008ACAA4, global:0x008ACEDC, source:raw]
    // CALCULATION: Resolve a per-type/per-instance id: v12 = 40 * *(slot+84) + 9095200, then slot+60 = *(v12+12); compute the scale v16 = v20 * *(slot+40) and pack the color/alpha word slot+96 = ((int)v16 << 24) + 0xFFFFFF. [source:raw]
    // CALL: Render the slot's bounding box via F_3DBoundingBoxRender(slot, v12+16, v12+28); decrement the spawn counter and repeat until v9 reaches 0. [callee:0x004CC700, source:raw]
    // CALL: Single call site from WeatherParticleUpdate (0x004CFCC0), consistent with the per-frame weather particle emission path. [caller:0x004CFCC0]

    // Conservative worker pseudocode:
    //   void sub_4CC970(int this, float *a2, float a3) {
    //     if (*(int*)(this+88) <= 0) return;
    //     *a2   += 2.0f * flt_8AB274[(byte)dword_8AAE70++];
    //     a2[2] += 2.0f * flt_8AB274[(byte)dword_8AAE70++];
    //     float m = (dword_8AB6E4 == 2) ? Delegation(&dword_8AB6EC) : (float)dbl_8AFEA0;
    //     sub_4CC840((float*)this);
    //     float sp = sqrtf(a3);
    //     float d = (dword_8AB6E4 == 2)
    //           ? (VehicleDataAccessor(&dword_8AB6EC) == 5 ? 0.0f : FloatDifference(&dword_8AB6EC))
    //           : (float)dbl_8AFE98;
    //     int n = (int)((double)*(int*)(this+88) * d * sp * 2.5263157f) >> *(int*)(this+8);
    //     float sc = sp * 0.8f;
    //     while (n > 0) {
    //       int slot = CircularBufferSlotAlloc((_DWORD*)this);
    //       *(float*)(slot+8)  = m;
    //       *(float*)(slot+12) = m + 0.39583334f;
    //       int idx = ((byte)dword_8ACEDC + 1) & 0x7F; dword_8ACEDC = idx;
    //       int tid = 40 * *(int*)(slot+84) + 9095200;
    //       *(float*)(slot+44) = flt_8ACAA0[2*idx] + a2[0];
    //       *(float*)(slot+48) = a2[1] + 8.0f;
    //       *(float*)(slot+52) = flt_8ACAA4[2*dword_8ACEDC] + a2[2];
    //       *(int*)(slot+56)  = 0;
    //       *(int*)(slot+60)  = *(int*)(tid+12);
    //       *(int*)(slot+64)  = 0;
    //       float v16 = sc * *(float*)(slot+40);
    //       *(int*)(slot+96)  = ((int)v16 << 24) + 0xFFFFFF;
    //       F_3DBoundingBoxRender((float*)slot, (float*)(tid+16), (float*)(tid+28));
    //       --n;
    //     }
    //   }
    // UNRESOLVED: flt_59E440, flt_59E4DC, flt_59E8CC, flt_5ACEB0 and flt_5ACEB4 are packet read references but do not appear literally in the decompiled body; they likely feed constants folded into sub_4CC840 or the literal scales, and their exact use is unresolved here.
    // UNRESOLVED: The table base 9095200 and its 40-byte per-entry layout (offsets +12/+16/+28) are inferred only from this function's single dereference pattern.
    // UNRESOLVED: Meaning of slot+96's packed ((int)v16 << 24) + 0xFFFFFF word (color/alpha vs size/emissive) is not established.
    // UNRESOLVED: The role of dword_8AB6EC as a shared scoring/delegation object and why VehicleDataAccessor()==5 yields a zero difference are inferred, not proven.
}
