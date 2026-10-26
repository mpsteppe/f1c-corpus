// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00569670
// Canonical corpus name: F_3DVectorCrossProductRotationAccumulation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3DVectorCrossProductRotationAccumulation_00569670.c

void UnknownObject::AccumulateContactImpulse()
{
    // Accumulates a contact impulse into rigid-body state. Scales the impulse vector a2 by the factor at this+0xB4 and adds it into the linear momentum accumulator (this+0x64/0x6C/0x74). Computes the cross products of the impulse a2 and the contact offset a3 and accumulates the three components into the angular momentum accumulator (this+0x94/0x9C/0xA4). Then recomputes torque as world inertia (3x3 at this+0xEC..0x12C) times the angular momentum, writing this+0x7C/0x84/0x8C. Returns the a2 impulse pointer. Invoked by CollisionContactImpulse (0x004599C0).
    // CALCULATION: Read the impulse scale factor v3 = this[0xB4] used to weight the linear accumulation [field:this:0x000000B4, source:raw]
    // ASSIGNMENT: Accumulate scaled linear momentum: this+0x64 += v3*a2[0], this+0x6C += v3*a2[1], this+0x74 += v3*a2[2] [field:this:0x00000064, field:this:0x0000006C, field:this:0x00000074, field:this:0x000000B4, source:raw]
    // CALCULATION: Compute the three cross-product terms of impulse a2 with contact offset a3: v6 = a2[0]*a3[2] - a3[0]*a2[2], v9 = a3[1]*a2[0] - a2[1]*a3[0], and a2[1]*a3[2] - a3[1]*a2[2] [source:raw]
    // ASSIGNMENT: Accumulate angular momentum: this+0x94 += a2[1]*a3[2] - a3[1]*a2[2], this+0x9C += v6, this+0xA4 += v9 [field:this:0x00000094, field:this:0x0000009C, field:this:0x000000A4, source:raw]
    // CALCULATION: Recompute torque X: this+0x7C = this+0xFC * this+0xA4 + this+0xF4 * this+0x9C + this+0x94 * this+0xEC (world-inertia row 0 times angular momentum) [field:this:0x0000007C, field:this:0x00000094, field:this:0x0000009C, field:this:0x000000A4, field:this:0x000000EC, field:this:0x000000F4, field:this:0x000000FC, source:raw]
    // CALCULATION: Recompute torque Y: this+0x84 = this+0x104 * this+0x94 + this+0x114 * this+0xA4 + this+0x10C * this+0x9C (world-inertia row 1 times angular momentum) [field:this:0x00000084, field:this:0x00000094, field:this:0x0000009C, field:this:0x000000A4, field:this:0x00000104, field:this:0x0000010C, field:this:0x00000114, source:raw]
    // CALCULATION: Recompute torque Z: this+0x8C = this+0x11C * this+0x94 + this+0x12C * this+0xA4 + this+0x124 * this+0x9C (world-inertia row 2 times angular momentum) [field:this:0x0000008C, field:this:0x00000094, field:this:0x0000009C, field:this:0x000000A4, field:this:0x0000011C, field:this:0x00000124, field:this:0x0000012C, source:raw]
    // RETURN: Return the a2 impulse pointer; the function is invoked per contact by CollisionContactImpulse (0x004599C0) [function:0x00569670, caller:0x004599C0, source:raw]

    // Conservative worker pseudocode:
    //   scale = this[0xB4];
    //   this[0x64] += scale * a2[0]; this[0x6C] += scale * a2[1]; this[0x74] += scale * a2[2];
    //   crossZ = a2[1]*a3[2] - a3[1]*a2[2];
    //   crossX = a2[0]*a3[2] - a3[0]*a2[2];
    //   crossY = a3[1]*a2[0] - a2[1]*a3[0];
    //   this[0x94] += crossZ; this[0x9C] += crossX; this[0xA4] += crossY;
    //   this[0x7C] = this[0xFC]*this[0xA4] + this[0xF4]*this[0x9C] + this[0x94]*this[0xEC];
    //   this[0x84] = this[0x104]*this[0x94] + this[0x114]*this[0xA4] + this[0x10C]*this[0x9C];
    //   this[0x8C] = this[0x11C]*this[0x94] + this[0x12C]*this[0xA4] + this[0x124]*this[0x9C];
    //   return a2;
    // UNRESOLVED: The exact ordering convention of the cross product (right-hand vs left-hand) relative to the game's world frame is not resolvable from this packet alone
    // UNRESOLVED: Whether a3 is the contact point position or a per-wheel offset vector is not established; the skeleton fill's 'contact offset' reading is DERIVED
    // UNRESOLVED: The units of the scale factor at this+0xB4 (inverse mass, 1/dt, or another weighting) are not determined by this packet
}
