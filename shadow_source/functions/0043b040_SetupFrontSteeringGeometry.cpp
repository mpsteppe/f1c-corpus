// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0043B040
// Canonical corpus name: FrontSteeringGeometrySetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FrontSteeringGeometrySetup_0043b040.c

void UnknownObject::SetupFrontSteeringGeometry()
{
    // Sets up front steering geometry for the left and right wheels. Searches the suspension component arrays for a matching pair by geometry identifier and component name, applies a 3D transform, then finds the closest geometry pair per side, applies the steering angle via a tan-based formula, and updates the rotation matrices for both wheels. Logs an error when the required eight components are not found.
    // LOOP: Outer loop over the two sides (v3 = 0, 1); selects per-side steering name: aFrSteering with count 12 for v3 != 0, aFlSteering with count 11 otherwise. [global:0x005C41BC, global:0x005C41C8, source:raw]
    // GUARD: If this[1393] (suspension component element count at this+0x15C4) is <= 0, skip the component search and jump to the not-found error path. [field:this:0x000015C4, guard:0, source:raw]
    // LOOP: Iterate the suspension component array at this[1394] (this+0x15C8) with a 72-byte (dword-index 18) stride. [field:this:0x000015C8, source:raw]
    // GUARD: Match a component pair whose ids equal the geometry identifier this[1404] (this+0x15F0) in either order, and whose name is empty or matches the steering name via sub_588410. [field:this:0x000015F0, callee:0x00588410, source:raw]
    // CALL: Call TransformApply3D to apply the component transform and record the matched pair into the local v62 array; accumulate the matched count v4 by two per match. [callee:0x0043AEE0, source:raw]
    // CALCULATION: For each matched component compute its world position from the dot products of the component axes and store the three offsets into the pair record. [source:raw]
    // GUARD: If the matched count v4 is not 8, and dword_7C569C != 5 and StringSplitLoop returns a printable frame, call DebugLogWrite with the aSorryOnlySuppo message. [global:0x007C569C, global:0x005C421C, global:0x005C4270, global:0x008AD25C, callee:0x004D7A50, callee:0x004D7AA0, source:raw]
    // LOOP: For each side find the closest geometry pair from the matched records using a squared-distance search, copy the best pair, and store the midpoint between them. [source:raw]
    // CALCULATION: Swap the two side records if the second side's ordering index is lower, so the primary pair is on the expected side. [source:raw]
    // CALCULATION: Apply the steering angle via v31 = (tan(a2 per-side steering angle) * (primary - secondary distance) - (primary - secondary offset)) * 0.5; add v31 to the primary pair and subtract it from the secondary pair. [source:raw]
    // LOOP: For both wheels, rebuild the 3x3 rotation matrix rows for each of the two records from the parent component axis dot products. [source:raw]
    // RETURN: Increment the side counter and repeat until both sides are processed; return when the counter exceeds one. [source:raw]

    // Conservative worker pseudocode:
    //   for (side = 0; side < 2; side++) {
    //       steeringName = side ? aFrSteering : aFlSteering;
    //       if (this->suspensionCount <= 0) goto not_found;
    //       for (i = 0; i < this->suspensionCount; i += stride) {
    //           comp = &this->suspensionArray[i];
    //           if (matchIds(comp, this->geometryId) && matchName(comp, steeringName)) {
    //               recordPair(pair, comp);  TransformApply3D(...);
    //           }
    //       }
    //       if (matched != 8) not_found: if (dword_7C569C != 5 && StringSplitLoop(...)) DebugLogWrite(...);
    //       closestPair(v58/v59);  orderByIndex();
    //       v31 = (tan(steerAngle) * (v59[11] - v58[11]) - (v59[12] - v58[12])) * 0.5;
    //       v59 += v31; v58 -= v31;
    //       rebuildRotationMatrices(v59); rebuildRotationMatrices(v58);
    //   }
    // UNRESOLVED: dbl_59E880 is listed in the packet's globals table but does not appear in the raw source; its role here is unclear.
    // UNRESOLVED: The steering constants and per-side counts (11/12) come from a2-relative indexed reads whose enclosing structure is unknown.
    // UNRESOLVED: The local pair/matrix records v58/v59 and the component name matching contract of sub_588410 are only partially understood.
    // UNRESOLVED: This is called once by VehiclePhysicsInitializer (0x00439210); the surrounding vehicle init context is not described here.
}
