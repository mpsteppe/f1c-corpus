// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004389B0
// Canonical corpus name: SuspensionDataCopyToPhysicsEngine
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SuspensionDataCopyToPhysicsEngine_004389b0.c

void UnknownObject::SuspensionDataCopyToPhysicsEngine()
{
    // Copies suspension geometry data (Euler-derived rotation matrix and inertia tensor) into one or two physics engine body structs. In the active path it builds the rotation matrix from stored Euler angles, transforms the inertia tensor to body and world space, and copies the buffers into the body pointed to by this+348; it repeats into the optional second body at this+352 when that pointer is non-null. In the inactive path it copies a reference matrix from the source argument and rebuilds the rotation around the X axis. On the vehicle physics frame path.
    // GUARD: Reads the byte flag at this+452 (active suspension path selector) and branches into the active copy path when non-zero, otherwise the inactive reference-copy path [field:this:0x000001C4, source:raw]
    // ASSIGNMENT: Active path: zero-initializes the four local buffers v11, v12, v13 and v9 via memset before they are filled [source:raw]
    // CALL: Calls EulerAnglesTo33RotationMatrix(v13) to build the 3x3 rotation matrix from the Euler angle stored at this+172 [callee:0x0056BD40, field:this:0x000000AC, source:raw]
    // ASSIGNMENT: Copies v11 into the first physics body (pointed to by this+348) at offset 4 (24 bytes) and v12 at offset 100 (24 bytes) [field:this:0x0000015C, source:raw]
    // CALL: Calls F_3x3InertiaTensorTransform on the first physics body to transform its inertia tensor into the body frame [callee:0x005692A0, source:raw]
    // ASSIGNMENT: Copies the 72-byte inertia tensor buffer v14 into the first physics body at offset 28, then the displacement vector v9 at offset 124 [field:this:0x0000015C, source:raw]
    // CALL: Calls InertiaTensorWorldSpaceTransform on the first physics body to bring the inertia tensor into world space [callee:0x00569410, source:raw]
    // GUARD: Reads the optional second physics body pointer at this+352 and copies into it only when it is non-null [field:this:0x00000160, source:raw]
    // ASSIGNMENT: Copies v11 into the second physics body at offset 4 and v12 at offset 100, then selects that body pointer as the working body [field:this:0x00000160, source:raw]
    // CALL: Inactive path: copies the 72-byte reference matrix from the source argument a2 at offset 28 into v14, then calls sub_56BDE0(this+456, 0) when the byte flag at this+453 is set [callee:0x0056BDE0, field:this:0x000001C5, source:raw]
    // CALL: Calls F_33RotationMatrixAroundXAxis with the double value at this+188 as the angle to build the rotation matrix around the X axis [callee:0x0056C2D0, field:this:0x000000BC, source:raw]
    // CALCULATION: Computes the displacement vector v9 as the v14 matrix columns scaled by the factor at this+188, summed with the source position components read from a2 at offsets 124, 132 and 140 [field:this:0x000000BC, source:raw]
    // ASSIGNMENT: Common tail: copies v14 into the working physics body at offset 28 (72 bytes), calls F_3x3InertiaTensorTransform, copies v9 at offset 124, and returns the result of InertiaTensorWorldSpaceTransform on that body [callee:0x005692A0, callee:0x00569410, field:this:0x0000015C, field:this:0x00000160, source:raw]

    // Conservative worker pseudocode:
    //   if (*(this + 452)) {
    //       memset(v11, 0, 24); memset(v12, 0, 24); memset(v13, 0, 24); memset(v9, 0, 24);
    //       EulerAnglesTo33RotationMatrix(v13);
    //       memcpy(*(this + 348) + 4, v11, 24); memcpy(*(this + 348) + 100, v12, 24);
    //       memcpy(*(this + 348) + 28, v14, 72); F_3x3InertiaTensorTransform(*(this + 348));
    //       memcpy(*(this + 348) + 124, v9, 24); InertiaTensorWorldSpaceTransform(*(this + 348));
    //       if (*(this + 352)) {
    //           memcpy(*(this + 352) + 4, v11, 24); memcpy(*(this + 352) + 100, v12, 24);
    //           body = *(this + 352);
    //       }
    //   } else {
    //       memcpy(v14, a2 + 28, 72);
    //       if (*(this + 453)) sub_56BDE0(this + 456, 0);
    //       F_33RotationMatrixAroundXAxis(*(this + 188), 0);
    //       body = *(this + 348);
    //       v9[0] = v14[0] * *(this + 188) + *(a2 + 124);
    //       v9[1] = v14[3] * *(this + 188) + *(a2 + 132);
    //       v9[2] = v14[6] * *(this + 188) + *(a2 + 140);
    //   }
    //   memcpy(body + 28, v14, 72); F_3x3InertiaTensorTransform(body);
    //   memcpy(body + 124, v9, 24);
    //   return InertiaTensorWorldSpaceTransform(body);
    // UNRESOLVED: The internal math of F_3x3InertiaTensorTransform and InertiaTensorWorldSpaceTransform is defined elsewhere; only their call order and the buffers they operate on are known from this packet
    // UNRESOLVED: The second body pointer at this+352 is only written when non-null; the tail copy applies to whichever body pointer (this+348 or this+352) was selected
    // UNRESOLVED: sub_56BDE0 is called with the derived address this+456, which has no packet field entry and whose semantics are not defined here
    // UNRESOLVED: The source argument a2 layout (matrix at offset 28, position at offsets 124/132/140) is read but its defining structure is not present in this packet
    // UNRESOLVED: The inactive path reads the angle at this+188 as a double and the active path's rotation input at this+172; their units are not stated
}
