// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00424B20
// Canonical corpus name: CameraViewportFrustumInitialization
// Owner: F1CVehicle [CONFIRMED]
// Raw source: functions/CameraViewportFrustumInitialization_00424b20.c

void F1CVehicle::CameraViewportFrustumInitialization()
{
    // Per-frame reset/initialization of the AI driver camera viewport and frustum state on an F1CVehicle. Writes a batch of fixed sentinel constants (max-float 2139095039, 999999.0, 999.0, 1.0, 6.0, 50) into viewport/projection/AI fields, zeroes the 5 proximity and 5 team-recognition slot arrays, computes the initial distance from the negated vehicle index at +0x4 scaled by 7.0, clears AI state flags, flushes the AI command-message queue, initializes the ring-buffer fields and calls sub_426430.
    // ASSIGNMENT: this+0x413C = 2139095039 (max-float sentinel). [field:this:0x0000413C, function:0x00424B20, source:raw]
    // ASSIGNMENT: this+0x4404 = -1082130432 (-1.0f) and this+0x4464 = 1065353216 (1.0f); viewport/frustum scalar sentinels. [field:this:0x00004404, field:this:0x00004464, function:0x00424B20, source:raw]
    // LOOP: 5-iteration reset loop over the proximity/team slot arrays: per iteration set the slot id field at +0x41B4 to -1, clear the team flag field at +0x42CC to 0, and reset the per-slot distance value (999999.0f) and the active flag to their defaults through the same advancing pointers (stride 17 dwords for the proximity array, stride 7 dwords for the team array). [field:this:0x000041B4, field:this:0x000042CC, function:0x00424B20, source:raw]
    // ASSIGNMENT: Zero driver-state fields: +0x43F8, +0x442C, +0x4430, +0x443C, +0x444C, +0x446C, +0x4470, +0x4478, +0x4524. [field:this:0x000043F8, field:this:0x0000442C, field:this:0x00004430, field:this:0x0000443C, field:this:0x0000444C, field:this:0x0000446C, field:this:0x00004470, field:this:0x00004478, field:this:0x00004524, function:0x00424B20, source:raw]
    // ASSIGNMENT: this+0x4474 = 1148829696 (999.0f) near-plane distance; this+0x4460 = -1082130432 (-1.0f) far-plane sentinel; this+0x4458 = -1; this+0x44B0 = -1. [field:this:0x00004474, field:this:0x00004460, field:this:0x00004458, field:this:0x000044B0, function:0x00424B20, source:raw]
    // CALL: AIClearStateFlags(this): clear AI state flag fields before per-frame recomputation. [callee:0x0042AE00, function:0x00424B20, source:raw]
    // CALCULATION: v6 = -(this+0x4) (negated vehicle index); this+0x4454 = (float)(v6 * 7.0) initializes the distance accumulator as a multiple of the vehicle index. [field:this:0x00000004, field:this:0x00004454, function:0x00424B20, source:raw]
    // ASSIGNMENT: this+0x4484 = 1232348144 (999999.0f) and this+0x4538 = 1232348144 (999999.0f, maxSpeed sentinel); +0x4540 = 1086324736 (6.0f); +0x4544 = 1; +0x4554 = 1065353216 (1.0f); +0x4558 = 50. [field:this:0x00004484, field:this:0x00004538, field:this:0x00004540, field:this:0x00004544, field:this:0x00004554, field:this:0x00004558, function:0x00424B20, source:raw]
    // ASSIGNMENT: Zero command/flag fields: +0x4548 (PitLaneRouteFlag), +0x454C (CallToBox), +0x4550 (WaypointSetSelector), +0x4560, +0x4564, +0x4584; +0x45F4 (AIControlFlag) as byte 0. [field:this:0x00004548, field:this:0x0000454C, field:this:0x00004550, field:this:0x00004560, field:this:0x00004564, field:this:0x00004584, field:this:0x000045F4, function:0x00424B20, source:raw]
    // ASSIGNMENT: this+0x461C = 1232348144 (999999.0f) and this+0x4510 (driverStatus) = 0. [field:this:0x0000461C, field:this:0x00004510, function:0x00424B20, source:raw]
    // CALL: AICommandMessageQueueDispatcher(0, 0): flush/initialize the AI command-message queue. [callee:0x00424CD0, function:0x00424B20, source:raw]
    // ASSIGNMENT: this+0x444C = 0 (viewport dimension/offset cleared). [field:this:0x0000444C, function:0x00424B20, source:raw]
    // CALL: AIRingBufferFieldInit(this): initialize ring-buffer fields of the vehicle. [callee:0x00424C80, function:0x00424B20, source:raw]
    // CALL: result = sub_426430(this): further AI per-frame state setup; return value forwarded as this function's result. [callee:0x00426430, function:0x00424B20, source:raw]
    // ASSIGNMENT: this+0x4584 as byte = 0 (final state clear before return). [field:this:0x00004584, function:0x00424B20, source:raw]
    // RETURN: Return the result of sub_426430. [callee:0x00426430, function:0x00424B20, source:raw]

    // Conservative worker pseudocode:
    //   this->frustumMaxSentinel = 2139095039;
    //   this->nearPlane = 999.0f; this->farPlane = -1.0f; this->aspect = 1.0f;
    //   for (k = 0; k < 5; k++) {
    //       slot[k].distance = 999999.0f; slot[k].teamFlag = 0;
    //       slot[k].id = -1; slot[k].active = 0;
    //   }
    //   AIClearStateFlags(this);
    //   this->distanceInit = (float)(-(this->vehicleIndex) * 7.0);
    //   this->maxSpeed = 999999.0f; this->speedFactor = 6.0f;
    //   this->driverStatus = 0; this->AIControlFlag = 0;
    //   AICommandMessageQueueDispatcher(0, 0);
    //   AIRingBufferFieldInit(this);
    //   result = sub_426430(this);
    //   return result;
    // UNRESOLVED: Global flt_59E864 is listed as read in the packet but does not appear in the raw source text; its role here is unknown (possibly consumed by a callee).
    // UNRESOLVED: The caller sub_4C6B60 invokes this each frame; the exact projection/frustum usage of the sentinel fields is not visible in this function.
}
