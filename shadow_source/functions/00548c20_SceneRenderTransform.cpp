// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00548C20
// Canonical corpus name: SceneRenderTransform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SceneRenderTransform_00548c20.c

void UnknownObject::SceneRenderTransform()
{
    // Computes a scene node transform: reads the dual-matrix trigger at this+0x8 and, when non-null, resolves a dual matrix transform into local position/orientation vectors; negates those vectors (with a 1.5 Y-offset correction), updates the orientation rotation matrix and applies a pi/2 (1.5707964) Euler rotation about the computed axis. When the scene entry a2 reports a positive count at a2+372, runs the per-node update path: a pre-step, a wheel-force-to-chassis transform, a camera projection update with parameter 14, and a recursive child-state traversal loop, then delegates to sub_5550E0(a2, *this). Returns the count at a2+372 when it is not positive.
    // ASSIGNMENT: Zero-initialize the six dual matrix transform outputs (three float vectors and two integer components). [source:raw]
    // GUARD: When this+0x8 is non-null, compute the dual matrix transform into the local output variables via DualMatrixTransformMultiply. [field:this:0x00000008, callee:0x0054B530, source:raw]
    // CALCULATION: Negate the transform outputs and apply the 1.5 Y-offset: v8 = -v14, v9 = -v13 - 1.5, v11 = -v12, v10 = -v15. [source:raw]
    // CALL: Update the orientation rotation matrix on *this from the negated position vector (v8, v9, v11) via OrientationRotationMatrixUpdate. [field:this:0x00000000, callee:0x00541D10, source:raw]
    // CALL: Apply a pi/2 (1.5707964) rotation about the negated axis with RandomRotationMatrixFromEulerAngles(*this, 1.5707964, v10, 0.0). [field:this:0x00000000, callee:0x00541DB0, source:raw]
    // GUARD: Read the element count at a2+372; the node processing block runs only when it is positive. [source:raw]
    // CALL: sub_5572B0(a2) performs the pre-node processing step. [callee:0x005572B0, source:raw]
    // CALL: Transform the wheel force vectors into the chassis frame via TransformWheelForcesToChassis on the object at *this. [field:this:0x00000000, callee:0x00541A70, source:raw]
    // CALL: Update the camera projection on *this with the parameter value 14 via CameraProjectionUpdate. [field:this:0x00000000, callee:0x00541B70, source:raw]
    // LOOP: Iterate a2+372 times (accumulating a 24-byte stride), invoking RecursiveStateTraversalWithFlagCheck on *this each iteration. [field:this:0x00000000, callee:0x00556930, source:raw]
    // RETURN: Return sub_5550E0(a2, *this) as the final processing result when the count was positive. [field:this:0x00000000, callee:0x005550E0, source:raw]
    // RETURN: Return the unprocessed count at a2+372 when it was not positive. [source:raw]
    // CALL: Invoked by AudioNodeIterator (0x00548DD0). [caller:0x00548DD0, source:raw]

    // Conservative worker pseudocode:
    //   int SceneRenderTransform(TransformNode* this, SceneEntry* a2, int a3) {
    //     v14 = v13 = v12 = v15 = 0.0f; v17 = v16 = 0;
    //     if (this[2]) DualMatrixTransformMultiply(&v14, &v13, &v12, &v17, &v15, &v16);
    //     OrientationRotationMatrixUpdate(*this, -v14, -v13 - 1.5f, -v12);
    //     RandomRotationMatrixFromEulerAngles(*this, 1.5707964f, -v15, 0.0f);
    //     result = *(a2 + 372);
    //     if (result > 0) {
    //       sub_5572B0(a2);
    //       TransformWheelForcesToChassis((float*)*this);
    //       CameraProjectionUpdate(*this, 14);
    //       for (i = 0; i < *(a2 + 372); ++i) RecursiveStateTraversalWithFlagCheck(*this);
    //       return sub_5550E0(a2, *this);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Read-only globals flt_59E8A4 and dword_8B78A0 are flagged by packet facts but do not appear in the raw decompiled source.
    // UNRESOLVED: The count field at a2+372 and the 24-byte per-iteration stride imply an array on the scene entry a2 whose element type is not defined here.
    // UNRESOLVED: The object type of *this and the meaning of the CameraProjectionUpdate parameter 14 are unverified.
    // UNRESOLVED: The dual matrix transform output ordering is known only through the callee contract.
}
