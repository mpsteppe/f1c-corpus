// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C9FB0
// Canonical corpus name: ParticleCollisionSpawn
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ParticleCollisionSpawn_004c9fb0.c

void UnknownObject::ParticleCollisionSpawn()
{
    // Particle collision spawn handler. When a collision source a2 and a live render-state list exist, stores the source into this+0x0, computes the bounding box at the collision point via BoundingBoxComputation, re-centers this+0x4/+0x8/+0xC onto the box midpoint, stores the half-extent into this+0x10, and (when the vertical extent is positive) seeds spread direction and magnitude from the noise table flt_8AB274 using the byte-wrapped index dword_8AAE70, writes scale/lifetime/angular-rate/direction components into this+0x18..this+0x30, counts elements above the collision height into this+0x34, and allocates a 20-byte-per-record buffer at this+0x38 that is filled with the filtered element pointers, their position floats and squared vertical deltas.
    // GUARD: Handler only proceeds when the collision source a2 is non-zero and LinkedListIndexedAccessor_c230(0) returns a live list v3 [callee:0x0054C230, source:raw]
    // ASSIGNMENT: Store the collision source pointer into this+0x0 [field:this:0x00000000, source:raw]
    // CALL: BoundingBoxComputation(&v30) fills the box extent locals (v27..v32) at the collision point [callee:0x004DD550, source:raw]
    // CALL: TripleFieldQuery(this+1, this+2, this+3) pulls the stored center components this+0x4 / this+0x8 / this+0xC into the query path [callee:0x0054B420, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // CALCULATION: Combine the bounding-box extent locals into center offsets: v34 = v29 + v32, v35 = (v27 + v30) * 0.5, v4 = (v31 + v28) * 0.5, v5 = v34 * 0.5 [source:raw]
    // ASSIGNMENT: Offset the stored collision center this+0x4 / this+0x8 / this+0xC by the computed box-center deltas [field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // CALCULATION: this+0x10 = 0.5 * sqrt(sum of squared box-extent differences): the collision bounding-sphere half-extent (radius) [field:this:0x00000010, source:raw]
    // GUARD: Vertical spread branch: only when the box vertical extent v6 = v31 - v28 is positive do the particle-scatter, counting, allocation and fill steps run [source:raw]
    // CALCULATION: Sample the noise table flt_8AB274 with the byte-wrapped post-increment index dword_8AAE70: write this+0x18 = noise * 0.15000001 + 1.0 and this+0x1C = 0.00094 (scale and lifetime constants) [global:0x008AB274, global:0x008AAE70, field:this:0x00000018, field:this:0x0000001C, source:raw]
    // CALCULATION: this+0x20 = (noise * 0.40000001 + 2.8) * 6.283185307179586 / (v6 + 3.0): angular spread rate from the noise sample and the vertical extent [global:0x008AB274, global:0x008AAE70, field:this:0x00000020, source:raw]
    // CALCULATION: Noise-derived direction angle v9 = flt_8AB274[...] * 0.5 + 0.69999999: the cosine is stored to this+0x24 and the sine to this+0x28, then the sign quadrant is chosen from the next noise sample (>= 0.2 negates the sine, else the cosine), and v16 = noise * 0.2 + 0.5 weights the components written to this+0x2C and this+0x30 [global:0x008AB274, global:0x008AAE70, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, source:raw]
    // CALCULATION: Counting pass: reset this+0x34 to 0, then for each of PackedArrayTotalSize(v3) elements from PackedArrayIndexLookup increment this+0x34 when the element float at +4 exceeds the vertical extent v28 [callee:0x0054E100, callee:0x0054E120, field:this:0x00000034, source:raw]
    // CALL: Allocate the filtered record buffer: this+0x38 = OperatorNewNhMallocWrapper(20 * this+0x34) — 20-byte records for the counted elements [callee:0x00587C03, field:this:0x00000034, field:this:0x00000038, source:raw]
    // LOOP: Fill pass: for each PackedArrayIndexLookup element whose float at +1 exceeds v28, write the element pointer into buffer record offset 0, copy its three floats (+0/+1/+2) into record offsets 4/8/12, and write the squared vertical delta (float+1 - v28)^2 into record offset 16; records advance 20 bytes [callee:0x0054E120, field:this:0x00000038, source:raw]
    // RETURN: Void handler for collision-driven secondary particle spawn; invoked from SpecialFX_Init (004CF070) [caller:0x004CF070, source:raw]

    // Conservative worker pseudocode:
    //   if (a2 && (list = LinkedListIndexedAccessor_c230(0))) {
    //     this[0] = a2;
    //     BoundingBoxComputation(&box);  /* box extents in v27..v32 * /
    //     TripleFieldQuery(&this[1], &this[2], &this[3]);
    //     cx = (v27 + v30) * 0.5; cy = (v31 + v28) * 0.5; cz = (v29 + v32) * 0.5;
    //     this[1] += cx; this[2] += cy; this[3] += cz;
    //     this[4] = 0.5 * sqrt((v32-v29)^2 + (v31-v28)^2 + (v30-v27)^2);
    //     if ((v6 = v31 - v28) > 0.0) {
    //       this[7]  = 0.00094;
    //       this[6]  = noise(++) * 0.15000001 + 1.0;
    //       this[8]  = (noise(++) * 0.40000001 + 2.8) * 6.283185307179586 / (v6 + 3.0);
    //       ang = noise(++) * 0.5 + 0.69999999;
    //       this[9]  = cos(ang); this[10] = sin(ang);
    //       s = (noise(++) >= 0.2) ? -sin(ang) : sin(ang);
    //       c = (noise(++) >= 0.2) ?  cos(ang) : -cos(ang);
    //       w = noise() * 0.2 + 0.5;
    //       this[11] = w * s; this[12] = w * c;
    //       this[13] = 0;
    //       n = PackedArrayTotalSize(list);
    //       for (i = 0; i < n; ++i) if (*(float*)(PackedArrayIndexLookup(i)+4) > v28) ++this[13];
    //       this[14] = OperatorNewNhMallocWrapper(20 * this[13]);
    //       k = 0;
    //       for (i = 0; i < n; ++i) {
    //         e = (float*)PackedArrayIndexLookup(i);
    //         if (e[1] > v28) {
    //           rec = this[14] + k; k += 20;
    //           *(dword*)rec        = e;
    //           *(float*)(rec+4)    = e[0];
    //           *(float*)(rec+8)    = e[1];
    //           *(float*)(rec+12)   = e[2];
    //           *(float*)(rec+16)   = (e[1] - v28) * (e[1] - v28);
    //         }
    //       }
    //     }
    //   }
    // UNRESOLVED: Ten read-only globals flagged by packet facts (flt_59E43C, flt_59E440, flt_59E450, flt_59E478, flt_59E6E8, flt_59E7E8, flt_59E868, flt_59E8C8, dbl_59ED28, flt_5ACE94) appear nowhere in the raw decompiled source; they may be reached through the called helpers but cannot be located in this function body
    // UNRESOLVED: The noise table indexing wraps through the low byte of dword_8AAE70; the table length and the post-increment aliasing between the v10 snapshot and the final index write are not resolvable from this packet
    // UNRESOLVED: The axis correspondence of the bounding-box locals v27..v32 to world X/Y/Z is not resolvable from this function alone
    // UNRESOLVED: The sine/cosine helper calls (cos, sin, sqrt) are not present in the packet callee set, so their exact linkage is unresolved
}
