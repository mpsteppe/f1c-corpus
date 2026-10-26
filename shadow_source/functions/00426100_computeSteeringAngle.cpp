// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00426100
// Canonical corpus name: sub_426100
// Owner: AIDriver [DERIVED]
// Raw source: functions/sub_426100_00426100.c

void AIDriver::computeSteeringAngle()
{
    // Computes the AI steering angle toward the current target waypoint. Reads car and target positions, computes the distance to target, projects the direction onto the heading frame, applies a speed-dependent scale, optionally inverts the sign when driverStatus equals 6 (reversing), rate-limits the steering output (max change 0.1 per frame), and clamps the stored output at this+0x442C to the closed range [-1.0, 1.0]. Invoked every frame from AIMainUpdate.
    // CALCULATION: Derives the address of the current waypoint entry: v2 = this + 4 * waypointIndex(this+0x4468) + 17236. [field:this:0x00004468, source:raw]
    // CALCULATION: Computes the signed position delta to the target: v7 = carX(this+0x34E0) - targetX(this+0x4498) and v8 = carY(this+0x34E8) - targetY(this+0x44A0). [field:this:0x000034E0, field:this:0x000034E8, field:this:0x00004498, field:this:0x000044A0]
    // CALCULATION: Computes sqrt(v8*v8 + v7*v7) and stores it as the distance to target at this+0x44A4. [field:this:0x000044A4]
    // CALCULATION: Predicts the target position components v10 and v11 from the waypoint entry values scaled by the input at this+0x4408, minus the car position. [field:this:0x00004408, field:this:0x000034E0, field:this:0x000034E8, source:raw]
    // CALCULATION: Normalizes the projection onto the heading frame: v4 = (v11 * sin(this+0x4494) + v10 * cos(this+0x448C)) / sqrt(v11*v11 + v10*v10) — cosine of the angle between heading and target direction. [field:this:0x0000448C, field:this:0x00004494]
    // GUARD: If the normalized projection v4 is < 1.0, the signed steering magnitude is computed: FloatFunctionPassThrough is invoked, the sign is flipped when the cross product v11*cos - v10*sin > 0, the result is scaled by the speed divisor at this+0x44B4, and the steering sign is inverted again when driverStatus (this+0x4510) equals 6. Otherwise the raw steering magnitude is 0.0. [callee:0x005894A0, field:this:0x000044B4, guard:0, field:this:0x00004510]
    // CALCULATION: Rate-limits the steering output: the new value at this+0x442C may move at most 0.1 per frame toward the computed target (clamped to previous +- 0.1). [field:this:0x0000442C]
    // GUARD: Clamps the stored steering at this+0x442C: if above 1.0f the raw dword 1065353216 is written and the function returns; if below -1.0f the raw dword -1082130432 is written and the function returns. [field:this:0x0000442C, source:raw]
    // RETURN: Returns after storing the steering output; fall-through path clears this+0x442C to 0. [field:this:0x0000442C, function:0x00426100]

    // Conservative worker pseudocode:
    //   wp = &this->waypoints[this->waypointIndex];
    //   dx = this->carX - this->targetX;
    //   dy = this->carY - this->targetY;
    //   this->distToTarget = sqrt(dx*dx + dy*dy);
    //   pred = predictTarget(wp, this->input, this->carX, this->carY);
    //   cosA = (pred.y * this->headingSin + pred.x * this->headingCos) / length(pred);
    //   steer = (cosA < 1.0) ? (signAdjusted / this->speedDivisor) : 0.0;
    //   if (this->driverStatus == 6) steer = -steer;
    //   steer = clampToPrev(steer, this->steering, 0.1);
    //   this->steering = clamp(steer, -1.0f, 1.0f);
    // UNRESOLVED: Role of the four read-only float globals flt_59E43C, flt_59E440, flt_59E670, flt_59E84C is not attributable to any source operation; they are likely folded clamp/scale constants but the mapping is not evidenced.
}
