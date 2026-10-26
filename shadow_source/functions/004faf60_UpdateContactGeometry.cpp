// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FAF60
// Canonical corpus name: sub_4FAF60
// Owner: PhysicsSuspensionNode [DERIVED]
// Raw source: functions/sub_4FAF60_004faf60.c

void PhysicsSuspensionNode::UpdateContactGeometry()
{
    // Suspension contact-geometry update for a vehicle physics node, gated by a distance threshold (this+0x12C must be below dword_5EA2CC). Computes the delta vector (this+0xA4/0xA8/0xAC) from the local reference position to a linked neighbor (primary this+0x110, falling back to alternative this+0x10C), derives lateral bounds (this+0x50/0x54), combined coordinates (this+0x68/0x6C) and the delta magnitude (this+0x3C), normalizes the delta, computes a secondary distance (this+0x40) from the tertiary pointer this+0x114, and sets an approach angle (this+0xB8) from atan2 with pi/2 and +pi special cases. Finally it propagates clamped cosine-similarity values into the this+0xBC array through a chain of up to 4 linked physics nodes.
    // GUARD: Distance threshold guard: the whole geometry update only runs when the node's distance state this+0x12C is below dword_5EA2CC. [field:this:0x0000012C, global:0x005EA2CC, source:raw]
    // ASSIGNMENT: Primary-source delta: when the linked-neighbor pointer this+0x110 is set, compute the delta vector (this+0xA4/0xA8/0xAC) as neighbor reference position (offsets 0x94/0x98/0x9C) minus the local reference position (this+0x94/0x98/0x9C). [field:this:0x00000110, field:this:0x000000A4, field:this:0x000000A8, field:this:0x000000AC, field:this:0x00000094, field:this:0x00000098, field:this:0x0000009C, field:*(this+0x110):0x00000094, field:*(this+0x110):0x00000098, field:*(this+0x110):0x0000009C, source:raw]
    // ASSIGNMENT: Fallback-source delta: when this+0x110 is null but the alternative pointer this+0x10C is set, copy the delta vector (this+0xA4/0xA8/0xAC) from the alternative object's offsets 0xA4/0xA8/0xAC. [field:this:0x0000010C, field:this:0x000000A4, field:this:0x000000A8, field:this:0x000000AC, field:*(this+0x10C):0x000000A4, field:*(this+0x10C):0x000000A8, field:*(this+0x10C):0x000000AC, source:raw]
    // CALCULATION: Bounds: compute the lower/upper bounds this+0x50 / this+0x54 from the base position this+0x2C / this+0x30 minus 1.5, plus/minus the half-width this+0xA0. [field:this:0x00000050, field:this:0x00000054, field:this:0x0000002C, field:this:0x00000030, field:this:0x000000A0, source:raw]
    // CALCULATION: Combined coordinates: this+0x68 / this+0x6C = offset this+0x60 / this+0x64 plus base position this+0x2C / this+0x30. [field:this:0x00000068, field:this:0x0000006C, field:this:0x00000060, field:this:0x00000064, field:this:0x0000002C, field:this:0x00000030, source:raw]
    // CALCULATION: Magnitude: this+0x3C = sqrt(delta_x^2 + delta_y^2 + delta_z^2) over the delta vector this+0xA4/0xA8/0xAC. [field:this:0x0000003C, field:this:0x000000A4, field:this:0x000000A8, field:this:0x000000AC, source:raw]
    // GUARD: Zero-delta guard: skip normalization when all three delta components (this+0xA4/0xA8/0xAC) are 0.0. [field:this:0x000000A4, field:this:0x000000A8, field:this:0x000000AC, source:raw]
    // CALCULATION: Normalize: divide each delta component by its magnitude, writing the unit vector back to this+0xA4/0xA8/0xAC. [field:this:0x000000A4, field:this:0x000000A8, field:this:0x000000AC, source:raw]
    // CALCULATION: Secondary distance: when the tertiary pointer this+0x114 is set, compute this+0x40 = sqrt of the summed squared deltas between the tertiary reference position (offsets 0x94/0x98/0x9C) and the local reference position (this+0x94/0x98/0x9C). [field:this:0x00000114, field:this:0x00000040, field:*(this+0x114):0x00000094, field:*(this+0x114):0x00000098, field:*(this+0x114):0x0000009C, field:this:0x00000094, field:this:0x00000098, field:this:0x0000009C, source:raw]
    // STATE_TRANSITION: Approach angle: when delta Z (this+0xAC) is 0.0 set the angle this+0xB8 to 1.5708 (pi/2); otherwise this+0xB8 = atan2(delta_x / delta_z, 1.0), adding 3.1415927 (pi) when delta Z is positive. [field:this:0x000000AC, field:this:0x000000B8, source:raw]
    // LOOP: Chain propagation: iterate up to 4 chained neighbors starting at the next pointer *(this+0x110)+0x110 and further *(*(this+0x110)+0x110)+0x110; for each, compute the cosine similarity between the unit delta and the neighbor relative vector (offsets 0x94/0x9C), pass it through FloatFunctionPassThrough, clamp to the minimum 0.024110001, and store into the this+0xBC array entries. [callee:0x005894A0, field:this:0x00000110, field:*(this+0x110):0x00000110, field:*(*(this+0x110)+0x110):0x00000094, field:*(*(this+0x110)+0x110):0x0000009C, field:*(*(*(this+0x110)+0x110)+0x110):0x00000110, field:this:0x000000BC, field:this:0x000000A4, field:this:0x000000AC, source:raw]
    // CALCULATION: Reads the five float constant globals that back the inline literals (1.5, 1.5708, 3.1415927, 0.024110001, 1.0) used across the geometry math; the exact constant-to-global mapping is not evidenced. [global:0x0059E43C, global:0x0059E440, global:0x0059E660, global:0x0059E8A4, global:0x005AD274, source:raw]

    // Conservative worker pseudocode:
    //   if (this[0x12C] >= dword_5EA2CC) return;
    //   if (p = this[0x110]) {
    //       this[0xA4] = p[0x94] - this[0x94];
    //       this[0xA8] = p[0x98] - this[0x98];
    //       this[0xAC] = p[0x9C] - this[0x9C];
    //   } else if (q = this[0x10C]) {
    //       this[0xA4] = q[0xA4]; this[0xA8] = q[0xA8]; this[0xAC] = q[0xAC];
    //   }
    //   this[0x50] = this[0x2C] - 1.5 + this[0xA0];
    //   this[0x54] = this[0x30] - 1.5 - this[0xA0];
    //   this[0x68] = this[0x60] + this[0x2C];
    //   this[0x6C] = this[0x64] + this[0x30];
    //   this[0x3C] = sqrt(x*x + y*y + z*z);
    //   if (x != 0 || y != 0 || z != 0) { len = sqrt(...); this[0xA4]/=len; this[0xA8]/=len; this[0xAC]/=len; }
    //   if (t = this[0x114]) this[0x40] = sqrt((t[0x94]-this[0x94])^2 + ...);
    //   if (this[0xAC] == 0) this[0xB8] = 1.5708;
    //   else { a = atan2(this[0xA4]/this[0xAC], 1.0); if (this[0xAC] > 0) a += 3.1415927; this[0xB8] = a; }
    //   i = 0; node = *(this[0x110] + 0x110);
    //   while (node && i < 4) {
    //       cos_sim = (dx*(node[0x94]-this[0x94]) + dz*(node[0x9C]-this[0x9C])) / (mag2d * dist);
    //       cos_sim = FloatFunctionPassThrough(cos_sim);
    //       this[0xBC + i] = (cos_sim < 0.024110001) ? 0.024110001 : cos_sim;
    //       node = *(node + 0x110); i++;
    //   }
    // UNRESOLVED: The meaning of the propagated cosine-similarity array this+0xBC (up to 4 entries) is DERIVED as approach-angle cosine to chained neighbors; its consumer is not evidenced by this packet.
    // UNRESOLVED: The identities of the primary (this+0x110), alternative (this+0x10C) and tertiary (this+0x114) linked objects are not named by the packet; their roles are inferred from usage.
    // UNRESOLVED: The exact mapping of the five float constant globals (0x0059E43C, 0x0059E440, 0x0059E660, 0x0059E8A4, 0x005AD274) to the inline math literals is not established.
    // UNRESOLVED: Owner identity is DERIVED from the chain-propagation/geometry evidence; the LEGACY ABI name AI_Opponent_Relative_Positioning is contradicted by the analysis.
}
