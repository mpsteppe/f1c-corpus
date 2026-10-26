// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A6B80
// Canonical corpus name: CollisionAvoidanceCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionAvoidanceCheck_004a6b80.c

void UnknownObject::CollisionAvoidanceCheck()
{
    // Vehicle collision-avoidance state machine, called per frame. When the avoidance sub-object (this+0x14 / this[5]) is present, it reads the vehicle's movement-threshold flag, gets the position-change monitor, and computes the normalized movement delta between the monitor's predicted position and its current position. It then iterates every other active vehicle and tests the other vehicle's direction vector for an approaching path (approach-time ratio 0 < t < 5.5). If a collision is predicted it clears the collision flag; otherwise it transitions the avoidance state from 1 to 2 and optionally raises a flag-field bit, or, when a collision is detected while in state 2, invokes the utility handler. Returns the current state value.
    // GUARD: Proceed only when the avoidance sub-object pointer at this+0x14 (this[5]) is non-null; otherwise the function returns that null value immediately. [field:this:0x00000014, source:raw]
    // CALCULATION: Read the movement-threshold flag at obj+0x39A0 (14752) of the object struct pointed to by *this; a value > 0.0 means the vehicle is moving and the collision check is enabled. [field:obj:0x000039A0, field:this:0x00000000, source:raw]
    // CALL: Call PositionChangeMonitor on the object base + 12 to obtain the position-change monitor; read the predicted position (pointer stored at monitor+272) and the current position fields (monitor+0/+4/+8). [callee:0x004E9630, field:this:0x00000000, source:raw]
    // CALCULATION: Compute the movement delta vector between the monitor's predicted position and its current position (three components) and its squared length. [source:raw]
    // CALCULATION: If the squared length is > 0.0, normalize the delta by 1/sqrt(length) so the subsequent tests use a unit direction. [source:raw]
    // LOOP: Iterate vehicle index i over all vehicles, count taken from the global dword_5C329C (VehicleCount). [global:0x005C329C, source:raw]
    // GUARD: Skip the vehicle whose index equals this[1] (this+0x4, the own index). [field:this:0x00000004, source:raw]
    // GUARD: For each candidate, dereference the active-vehicle pointer array dword_7C54F0; only consider vehicles whose activity byte at +13388 is non-zero. [global:0x007C54F0, source:raw]
    // CALCULATION: Dot product of the normalized delta with the other vehicle's direction vector (offsets +13560/+13564/+13568); this is the denominator of the approach-time test. [source:raw]
    // GUARD: Only continue the approach test when the dot-product denominator is non-zero. [source:raw]
    // CALCULATION: Compute the approach-time ratio: dot product of the delta with the own vehicle's direction (obj+13536/13540/13544, i.e. obj+0x34E0/0x34E4/0x34E8) minus the other vehicle's position projection, divided by the denominator; if 0 < t < 5.5 the paths collide and the collision flag is cleared. [field:obj:0x000034E0, field:obj:0x000034E4, field:obj:0x000034E8, source:raw]
    // STATE_TRANSITION: Read the avoidance state from the sub-object and apply the state machine: when clear and state == 1, set the state to 2 and, if the sub-object flag (dword index [25]) is set, invoke FlagFieldBitManipulation(1, 1, 1, 0); when a collision is predicted and state == 2, invoke UtilityFunction_4000 on the sub-object. The deterministic field table reports the state at this+0x8C and a related sub-object field at this+0x78. [field:this:0x00000078, field:this:0x0000008C, source:raw]
    // RETURN: Return the avoidance state value read from the sub-object (or the null sub-object pointer when absent). [field:this:0x0000008C, source:raw]

    // Conservative worker pseudocode:
    //   int CollisionAvoidanceCheck(int *this) {
    //     if (!this[5]) return 0;
    //     bool moving = *(float *)(*this + 0x39A0) > 0.0f;
    //     char *monitor = (char *)PositionChangeMonitor(*this + 12);
    //     float *pred = *(float **)(monitor + 272);
    //     float vx = pred[0] - *(float *)monitor;
    //     float vy = pred[1] - *(float *)(monitor + 4);
    //     float vz = pred[2] - *(float *)(monitor + 8);
    //     float len2 = vx*vx + vy*vy + vz*vz;
    //     if (len2 > 0.0f) { float inv = 1.0f / sqrt(len2); vx *= inv; vy *= inv; vz *= inv; }
    //     for (int i = 0; i < dword_5C329C; ++i) {
    //       if (i == this[1]) continue;
    //       char *other = (char *)dword_7C54F0[i];
    //       if (!other[13388]) continue;
    //       float ox = *(float *)(other + 13560);
    //       float oy = *(float *)(other + 13564);
    //       float oz = *(float *)(other + 13568);
    //       float denom = vz*oz + vy*oy + vx*ox;
    //       if (denom == 0.0f) continue;
    //       float mx = *(float *)(*this + 13536);
    //       float my = *(float *)(*this + 13540);
    //       float mz = *(float *)(*this + 13544);
    //       float num = (vz*mz + vy*my + vx*mx) - (vz*oz + vy*oy + vx*ox);
    //       float t = num / denom;
    //       if (t > 0.0f && t < 5.5f) moving = false;
    //     }
    //     int *avoid = (int *)this[5];
    //     int state = avoid[30];
    //     if (moving) { if (state == 1) { avoid[30] = 2; if (avoid[25]) return FlagFieldBitManipulation(1, 1, 1, 0); } }
    //     else if (state == 2) return UtilityFunction_4000(avoid);
    //     return state;
    //   }
    // UNRESOLVED: Owner type and identity of the avoidance sub-object and of the enclosing object are unknown.
    // UNRESOLVED: The deterministic field table reports the state at this+0x8C and a related field at this+0x78, while the raw source reads the state as sub-object dword index [30] and a flag as index [25]; the exact base binding of the deterministic offsets is unresolved.
    // UNRESOLVED: Globals flt_59E43C, flt_59E440 and flt_59E918 are listed by the packet's global table but do not appear in the raw source text; their role here is unresolved.
    // UNRESOLVED: FlagFieldBitManipulation and UtilityFunction_4000 are invoked in the source but are absent from the packet callee list; their addresses and contracts are unknown.
    // UNRESOLVED: The collision-test window literal 5.5 and the other-vehicle direction offsets +13560/+13564/+13568 are taken verbatim from the raw source without independent confirmation.
}
