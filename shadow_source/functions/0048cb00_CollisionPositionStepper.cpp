// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048CB00
// Canonical corpus name: CollisionPositionStepper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionPositionStepper_0048cb00.c

void UnknownObject::CollisionPositionStepper()
{
    // Steps a collision/animation position toward a target over time. Computes the total range as step x range-multiplier, accumulates a2 into a float accumulator at this+0x340, converts the accumulator into a number of steps via CRTFtol(accumulator * 14.999999), then for each step recomputes the target offset, advances the position at a distance-proportional rate (0.444 scaling with a minimum step of 1), wraps the position modulo the total range in both directions, and invokes an update callback through vtable entry 11 (offset 44) with argument 1. Returns early when the range is non-positive or the computed step count is zero.
    // ASSIGNMENT: Compute total range v3 = field203 (step, this+0x32C) * field202 (multiplier, this+0x328). [field:this:0x00000328, field:this:0x0000032C, source:raw]
    // GUARD: Guard on v3 > 0: when the total range is non-positive the whole stepping body is skipped and the function returns. [source:raw]
    // ASSIGNMENT: Accumulate the time delta into the accumulator: this[208] += a2. [field:this:0x00000340, source:raw]
    // CALCULATION: Convert the accumulator into a step count: v5 = CRTFtol(accumulator * 14.999999). [callee:0x00587BDC, field:this:0x00000340, source:raw]
    // GUARD: Guard on v5 > 0: the loop only runs when the converted step count is positive. [source:raw]
    // LOOP: Down-counting loop over v6 steps; each iteration decrements v6 and returns once it reaches zero. [source:raw]
    // CALCULATION: Recompute target offset v8 = field203/2 + field203 * field206 (this+0x338) - field205 (current position this+0x334). [field:this:0x0000032C, field:this:0x00000334, field:this:0x00000338, source:raw]
    // GUARD: Read the direction byte v7 at this+0x33C; when zero the loop breaks into the wrap-around path instead of the stepping path. [field:this:0x0000033C, source:raw]
    // CALCULATION: Wrap v8 into [0, v3): when v8 < 0 add v3 once; when v8 > 0 subtract v8 from v3; then negate if still negative; v9 records whether v8 became zero. [field:this:0x00000334, source:raw]
    // CALCULATION: When not already at target, derive direction sign v11 = 2*(field207 != 0) - 1 from the direction byte, step magnitude v12 = max(1, CRTFtol(v15 * 0.44400001)), and new position = v11 * v12 + current position (this+0x334). [callee:0x00587BDC, field:this:0x0000033C, field:this:0x00000334, source:raw]
    // CALCULATION: Wrap the new position modulo v3: repeatedly subtract v3 while >= v3, then repeatedly add v3 while < 0, writing back to this+0x334. [field:this:0x00000334, source:raw]
    // CALL: Invoke the update callback through the vtable: (vtable entry at this+0x0 + 0x2C, i.e. vtable slot 11)(this, 1). [field:obj:0x0000002C, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Decrement the accumulator by the per-step constant 0.06666667 (1/15) sourced from flt_5AC108. [field:this:0x00000340, global:0x005AC108, source:raw]
    // RETURN: Return once the step counter v6 reaches zero, or immediately when the initial range or step count is non-positive. [source:raw]

    // Conservative worker pseudocode:
    //   void CollisionPositionStepper(float *this, float dt) {
    //     int total = this[203] * this[202];
    //     if (total <= 0) return;
    //     this[208] += dt;
    //     int steps = CRTFtol(this[208] * 14.999999);
    //     if (steps > 0) {
    //       int n = steps;
    //       while (1) {
    //         char dir = *(char*)&this[207];
    //         int v8 = this[203] / 2 + this[203] * this[206] - this[205];
    //         int ref = v8;
    //         if (!dir) break;
    //         int eq = (this[203] / 2 + this[203] * this[206] == this[205]);
    //         if (v8 < 0) { v8 += total; goto wrap; }
    //       step:
    //         if (!eq) {
    //           int sign = 2 * (dir != 0) - 1;
    //           int mag = CRTFtol(ref * 0.44400001);
    //           if (mag < 1) mag = 1;
    //           int pos = sign * mag + this[205];
    //           this[205] = pos;
    //           while (pos >= total) { pos -= total; }
    //           this[205] = pos;
    //           if (this[205] < 0) { do { this[205] += total; } while (this[205] < 0); }
    //           (vtable_call(this, 1));
    //         }
    //         --n;
    //         this[208] -= 0.06666667;
    //         if (!n) return;
    //         continue;
    //       wrap:
    //         if (v8 > 0) v8 = total - v8;
    //         if (v8 < 0) v8 = -v8;
    //         eq = (v8 == 0);
    //         goto step;
    //       }
    //     }
    //   }
    // UNRESOLVED: Read-only globals flt_5AC10C (AudioPanningStep) and flt_5AC110 (TrackMapScrollSpeed) are listed in the packet facts but not directly referenced by the raw decompiled source; their role in this function is not verifiable here.
}
