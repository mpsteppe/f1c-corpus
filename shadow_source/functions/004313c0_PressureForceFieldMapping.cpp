// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004313C0
// Canonical corpus name: PressureForceFieldMapping
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PressureForceFieldMapping_004313c0.c

void UnknownObject::PressureForceFieldMapping()
{
    // Maps per-session pressure/force values onto a fixed 44-to-50 element table. Builds blend factors from tire surface-contact floats (this+0x1CA8/0x1CAC, 0x1CB0, 0x1CB4), clamps grid index fields through PositionIndexClamp, copies element headers (0x16C8 into 0x16C4) and fills a local double table via SessionStateIndexedLookup, then runs a minimum-deviation search over this+0x1640 entries to select an index written to this+0x1644, and a final per-element nearest-index loop over this+0x16C0 slots (stride 0x40) writing this+0x16C4. Called by PhysicsStateInitIndexed (00431390).
    // CALCULATION: Builds blend factors: v25 = (this+0x1CAC - 0.5) * 0.5 + this+0x1CA8 and the mirrored (0.5 - this+0x1CAC) * 0.5 + this+0x1CA8 [field:this:0x00001CA8, field:this:0x00001CAC, source:raw]
    // CALL: PositionIndexClamp applied to grid index fields this+0x1270/0xDF0/0xE30/0x12B0 with the two blend factors, and to this+0x1370 with this+0x1CAC directly [callee:0x0042E290, source:raw]
    // CALL: PositionIndexClamp applied to this+0xCF0 with (1.0 - this+0x1CAC + this+0x1CB0) * 0.5 and to this+0xD30 with (this+0x1CB0 + this+0x1CAC) * 0.5 [callee:0x0042E290, field:this:0x00001CB0, source:raw]
    // LOOP: Four-iteration loop over five index slots at base this+0x1F0 with byte stride 0xB0, clamping each of the five slots with PositionIndexClamp using this+0x1CB0 [callee:0x0042E290, field:this:0x00001CB0, source:raw]
    // ASSIGNMENT: Copies the element header: this+0x1644 = this+0x1648 before the element loop [field:this:0x00001644, field:this:0x00001648, source:raw]
    // LOOP: Seven-iteration loop (44..50) over elements at this+0x16C4, stride 0x40: writes this+0x16C4 = this+0x16C8, stores SessionStateIndexedLookup(this, index) into the local v34 table, and records the index when the flag byte this+0x16CC is set [field:this:0x000016C4, field:this:0x000016C8, field:this:0x000016CC, callee:0x0042ED00, source:raw]
    // ASSIGNMENT: Resets this+0x1644 and this+0x16C4 to 0, then sets this+0x1644 = this+0x1640 - 1 and writes the selected element slot (this+0xBC4 + selected*64) to the value at (this + (selected+47)*64) minus 1 [field:this:0x00001644, field:this:0x00001640, field:this:0x000016C4, source:raw]
    // GUARD: Branches on the surface contact float: if this+0x1CB4 < 0.5 use branch A, otherwise branch B [field:this:0x00001CB4, source:raw]
    // CALCULATION: Both branches blend SessionStateIndexedLookup results against the local v34 table (branch A mixes 2*this+0x1CB4 with v34[55]; branch B mixes 2*this+0x1CB4-1 with the element value), then a 7-iteration loop computes v33[i+43] = blend * v34[i+54] [field:this:0x00001CB4, callee:0x0042ED00, source:raw]
    // GUARD: Minimum-deviation search is gated on the entry count this+0x1640 being greater than 0 [guard:0, field:this:0x00001640, source:raw]
    // LOOP: Search loop over candidates v7 = 0..this+0x1640-1: writes this+0x1644 = v7, computes deviation v31 from SessionStateIndexedLookup values against v34[0] and v33 thresholds, tracks the minimal deviation and the best index v13 [field:this:0x00001640, field:this:0x00001644, callee:0x0042ED00, source:raw]
    // ASSIGNMENT: Commits the selected index: this+0x1644 = v13 [field:this:0x00001644, source:raw]
    // GUARD: Final per-element loop is gated on the sub-entry count this+0x16C0 being greater than 0 [guard:1, field:this:0x000016C0, source:raw]
    // LOOP: Final loop over indexes 44..50 at base this+0x16C0, stride 0x40: for each element finds the reference index minimizing fabs(SessionStateIndexedLookup(this, idx) - v34 entry) and writes it to this+0x16C4, with neighbor smoothing for idx > 44 [field:this:0x000016C0, field:this:0x000016C4, callee:0x0042ED00, source:raw]
    // RETURN: Returns the last computed nearest-index result [source:raw]
    // CALL: Invoked by PhysicsStateInitIndexed (00431390), placing this on the physics-state initialisation path [caller:0x00431390, source:raw]

    // Conservative worker pseudocode:
    //   blendA = (this[0x1CAC] - 0.5) * 0.5 + this[0x1CA8];
    //   blendB = (0.5 - this[0x1CAC]) * 0.5 + this[0x1CA8];
    //   PositionIndexClamp(&this[0x1270], blendA); ... (several grid index clamps)
    //   for (g = 0; g < 4; ++g) for each of 5 slots: PositionIndexClamp(&slot, this[0x1CB0]);
    //   this[0x1644] = this[0x1648];
    //   for (idx = 44; idx <= 50; ++idx) {
    //     this[0x16C4] = this[0x16C8];
    //     v34[idx + 11] = SessionStateIndexedLookup(this, idx);
    //     if (flag at 0x16CC) keep idx;
    //   }
    //   this[0x1644] = 0; this[0x16C4] = 0;
    //   this[0x1644] = this[0x1640] - 1;
    //   if (this[0x1CB4] < 0.5) blend using 2*this[0x1CB4]; else blend using 2*this[0x1CB4] - 1;
    //   for (i = 0; i <= 6; ++i) v33[i + 43] = blend * v34[i + 54];
    //   if (this[0x1640] > 0) {
    //     best = 1.797693134862316e308;
    //     for (v7 = 0; v7 < this[0x1640]; ++v7) {
    //       this[0x1644] = v7;
    //       dev = max(floor deviation, upper deviation);
    //       if (dev < best) { best = dev; v13 = v7; }
    //     }
    //     this[0x1644] = v13;
    //   }
    //   for (idx = 44; idx <= 50; ++idx) {
    //     if (this[0x16C0] > 0) {
    //       best = 1.797693134862316e308;
    //       for (c = 0; c < this[0x16C0]; ++c) {
    //         d = fabs(SessionStateIndexedLookup(this, idx) - v34[c]);
    //         if (d < best) { best = d; nearest = c; }
    //       }
    //       this[0x16C4] = nearest;
    //       if (idx > 44) neighbor smoothing on this[0x16C4];
    //     }
    //   }
    //   return result;
    // UNRESOLVED: Read-only globals dbl_59E420 and dbl_59E880 are flagged by packet facts but do not appear in the raw decompiled source; they likely back the double literals (0.5 / 1.0 / 1.797693134862316e308) used here
    // UNRESOLVED: Many grid-index clamp targets (this+0x1270/0xDF0/0xE30/0x12B0/0x1370/0xCF0/0xD30 and the 0x1F0 grid) appear only in raw source and are not named fields
    // UNRESOLVED: The element stride (0x40) and the 44..50 fixed window are structural assumptions from the raw source only
    // UNRESOLVED: The distinction between the entry count (0x1640), the sub-entry count (0x16C0) and the two tables (0x16C4, 0x16C8 headers) is not fully resolvable from this packet
}
