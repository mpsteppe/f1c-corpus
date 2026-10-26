// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A5FA0
// Canonical corpus name: VehicleProximityCollisionDetection
// Owner: F1CPitMachine [CONFIRMED]
// Raw source: functions/VehicleProximityCollisionDetection_004a5fa0.c

void F1CPitMachine::PitBoxAlignmentReady()
{
    // Pit-box alignment check on the pit machine: loads a target object from the indexed struct array, computes the relative vector between the machine's transform and the target, applies forward/perpendicular projection tests against the target rotation basis, clears the collision flag and fires a state-change notification when the vehicle is behind and cleared, and returns whether the vehicle is within contact thresholds.
    // CALL: ArrayOfStructIndexedFieldCopy(dword_5EA2C0, this->obj+0x48A4 used as index, out v25, out v26) copies the target object's fields for comparison. [function:0x004A5FA0, callee:0x00403F70, global:0x005EA2C0, field:obj:0x000048A4, source:raw]
    // CALL: F_3DTransformWithMatrixMultiplication computes this object's world transform into v24. [callee:0x004EFB20]
    // CALCULATION: Compute the relative vector between own transform v24 and target v25; squared distance compared against 25.0 selects the close/far branch. [source:raw]
    // CALL: EulerToRotationMatrix(v26, v28) builds the target rotation basis used by the projection tests. [callee:0x00566E40]
    // CALCULATION: Forward projection v7 = v33*relZ + v31*relY + v29*relX of the relative vector along the target basis. [source:raw]
    // GUARD: Return 0 when the forward projection v7 > 1.5 (target outside the forward window). [source:raw]
    // CALL: When v7 < -5.0, SessionCleanupFlagClear(this) clears the collision flag before falling through. [callee:0x0042ADB0, field:this:0x00000000]
    // GUARD: When the perpendicular projection magnitude > 1.5, return 0 unless v7 < 0. [source:raw]
    // CALCULATION: Relative-velocity dot v11 computed from obj velocity fields 0x34C4/0x34D0/0x34DC and compared against the ~0.85 alignment threshold. [field:obj:0x000034C4, field:obj:0x000034D0, field:obj:0x000034DC]
    // GUARD: On passing the alignment test, when obj 0x32C8 == 0 and dword_7CE7A8 is set, StateChangeNotify(this, 4) fires the collision notification; otherwise return 0. [guard:0, field:obj:0x000032C8, global:0x007CE7A8, callee:0x004A5C80, field:this:0x00000000]
    // CALCULATION: Slip-velocity magnitude v20 from obj fields 0x34F8/0x34FC/0x3500 must stay under 4.0 (or 0.04 in the far branch) or the function returns 0. [field:obj:0x000034F8, field:obj:0x000034FC, field:obj:0x00003500]
    // RETURN: Return 1 when all thresholds pass (contact state), otherwise 0. [function:0x004A5FA0]

    // Conservative worker pseudocode:
    //   ArrayOfStructIndexedFieldCopy(dword_5EA2C0, this->obj->targetIndex, &targetPos, &targetEuler);
    //   F_3DTransformWithMatrixMultiplication(&ownTransform, &tmp);
    //   rel = ownTransform - targetPos;
    //   if (dot(rel, rel) > 25.0) {
    //       EulerToRotationMatrix(targetEuler, &basis);
    //       // far branch: return 0 unless contact flag already cleared and state notify fires
    //   }
    //   EulerToRotationMatrix(targetEuler, &basis);
    //   forward = basis * rel;
    //   if (forward > 1.5) return 0;
    //   if (forward < -5.0) SessionCleanupFlagClear(this);
    //   if (fabs(perp(rel)) > 1.5 && !(forward < 0.0)) return 0;
    //   align = relativeVelocityDot(obj);
    //   if (alignPassed(obj, this) && dword_7CE7A8)
    //       StateChangeNotify(this, 4);
    //   return (slipMagnitudeSq(obj) <= 4.0) ? 1 : 0;
    // UNRESOLVED: Literal thresholds 25.0, 1.5, -5.0, 0.85, 4.0 and 0.04 appear inline in the raw source; the listed float globals (flt_59E440 etc.) are not referenced by the raw body.
    // UNRESOLVED: Decompiled float-index arithmetic on v2 (the vehicle base) does not map 1:1 onto the listed obj fields; exact per-field roles are inferred.
}
