// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00426330
// Canonical corpus name: PhysicsGearShiftLogicWithThresholds
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsGearShiftLogicWithThresholds_00426330.c

void UnknownObject::PhysicsGearShiftLogicWithThresholds()
{
    // Per-frame AI gear-shift logic. Blocks all shifts while the shift timer (this+0x3A10) is positive; forces reverse gear (request -1) when driverStatus (this+0x4510) is 6 and pit-mode neutral (request 0) when carConditions (this+0x3D6C) is 2; otherwise upshifts when the shift-RPM threshold (this+0x3A18) is below current engine RPM (this+0x39A0) and both traction components (this+0x37CC, this+0x38C4) exceed 0.8, capped at max gear (this+0x3A04). A tail jump at JUMPOUT(0x4F62E6) handles the downshift path outside this function.
    // GUARD: Early-return guard: when shift-timer field this+0x3A10 exceeds 0.0 (zero threshold flt_59E440), all gear changes are blocked for this frame. [field:this:0x00003A10, global:0x0059E440, source:raw]
    // ASSIGNMENT: Load current gear v1 from field this+0x39FC under the thiscall ABI lead. [abi:lead, field:this:0x000039FC, source:raw]
    // GUARD: Guard: driverStatus field this+0x4510 equals 6 (reverse-gear state). [guard:1, field:this:0x00004510, source:raw]
    // CALL: In reverse-gear state, when current gear v1 != -1, request gear -1 via RaceStartCountdownStateUpdate(-1). [callee:0x004EF930, field:this:0x000039FC, source:raw]
    // GUARD: Guard: carConditions field this+0x3D6C equals 2 (pit mode). [guard:0, field:this:0x00003D6C, source:raw]
    // CALL: In pit mode, request gear 0 via RaceStartCountdownStateUpdate(0). [callee:0x004EF930, source:raw]
    // GUARD: Guard: when v1 is 0 or -1 (neutral/reverse), skip straight to the upshift path. [field:this:0x000039FC, source:raw]
    // GUARD: Upshift condition: shift-RPM threshold field this+0x3A18 is below current engine-RPM field this+0x39A0. [field:this:0x00003A18, field:this:0x000039A0, source:raw]
    // GUARD: Traction guard: upshift requires traction-X field this+0x37CC and traction-Y field this+0x38C4 both above 0.8 (threshold constant flt_59E8CC). [field:this:0x000037CC, field:this:0x000038C4, global:0x0059E8CC, source:raw]
    // GUARD: Upshift bound: only when current gear v2 (reloaded from this+0x39FC) is below max-gear field this+0x3A04. [field:this:0x000039FC, field:this:0x00003A04, source:raw]
    // CALL: Perform the upshift by requesting gear v2 + 1 via RaceStartCountdownStateUpdate(v2 + 1). [callee:0x004EF930, source:raw]
    // UNKNOWN: Tail branch: when v1 > 1, control jumps out to JUMPOUT(0x4F62E6) - a downshift path or shared block not contained in this function. [source:raw]

    // Conservative worker pseudocode:
    //   void sub_426330(int this) {
    //     if (*(float*)(this + 0x3A10) > 0.0) return;
    //     int v1 = *(int*)(this + 0x39FC);
    //     if (*(int*)(this + 0x4510) == 6) {
    //       if (v1 != -1) RaceStartCountdownStateUpdate(-1);
    //       return;
    //     }
    //     if (*(int*)(this + 0x3D6C) == 2) {
    //       RaceStartCountdownStateUpdate(0);
    //       return;
    //     }
    //     if (!v1 || v1 == -1) goto upshift;
    //     if (*(float*)(this + 0x3A18) < *(float*)(this + 0x39A0)) {
    //       if (*(float*)(this + 0x37CC) <= 0.8f || *(float*)(this + 0x38C4) <= 0.8f) return;
    //     upshift:
    //       if (*(int*)(this + 0x39FC) < *(int*)(this + 0x3A04))
    //         RaceStartCountdownStateUpdate(*(int*)(this + 0x39FC) + 1);
    //       return;
    //     }
    //     if (v1 > 1) JUMPOUT(0x4F62E6);
    //   }
    // UNRESOLVED: Exact float values behind globals flt_59E440 / flt_59E8CC (assumed 0.0 zero threshold and 0.8 traction threshold) are not proven.
    // UNRESOLVED: The JUMPOUT(0x4F62E6) tail target's logic (downshift) is outside this function and unknown.
    // UNRESOLVED: Literal meanings of gear requests -1 (reverse) and 0 (neutral) are inferred from surrounding state guards, not proven.
}
