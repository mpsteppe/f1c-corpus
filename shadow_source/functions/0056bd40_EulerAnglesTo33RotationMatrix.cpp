// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0056BD40
// Canonical corpus name: EulerAnglesTo33RotationMatrix
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/EulerAnglesTo33RotationMatrix_0056bd40.c

void UnknownObject::EulerAnglesTo33RotationMatrix()
{
    // Builds a row-major 3x3 rotation matrix at `this` (nine consecutive doubles at offsets 0x0 through 0x40) from the three Euler angles in `a2` using the standard sin/cos composition. Purely mathematical, no branches, no callees. Used by vehicle physics orientation paths (suspension setup, vehicle physics init, rigid body constraint solve, rotation-tensor transform).
    // CALCULATION: Compute the six sine/cosine terms of the three input Euler angles a2, a2[1], a2[2] [source:raw]
    // CALCULATION: Precompute the two combined terms v10 = cos(z)*cos(y) and v9 = sin(z)*cos(y) used across matrix rows [source:raw]
    // ASSIGNMENT: Write matrix element at this+0x0 (row 0 col 0) = sin(y)*sin(x)*sin(z) + cos(z)*cos(y) [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write matrix element at this+0x8 (row 0 col 1) = sin(y)*sin(x)*cos(z) - sin(z)*cos(y) [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Write matrix element at this+0x10 (row 0 col 2) = sin(y)*cos(x) [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Write matrix element at this+0x18 (row 1 col 0) = sin(z)*cos(x) [field:this:0x00000018, source:raw]
    // ASSIGNMENT: Write matrix element at this+0x20 (row 1 col 1) = cos(z)*cos(x) [field:this:0x00000020, source:raw]
    // ASSIGNMENT: Write matrix element at this+0x28 (row 1 col 2) = -sin(x) [field:this:0x00000028, source:raw]
    // ASSIGNMENT: Write matrix element at this+0x30 (row 2 col 0) = sin(z)*cos(y)*sin(x) - cos(z)*sin(y) [field:this:0x00000030, source:raw]
    // ASSIGNMENT: Write matrix element at this+0x38 (row 2 col 1) = sin(z)*sin(y) + cos(z)*cos(y)*sin(x) [field:this:0x00000038, source:raw]
    // ASSIGNMENT: Write matrix element at this+0x40 (row 2 col 2) = cos(y)*cos(x) [field:this:0x00000040, source:raw]
    // RETURN: Return the input angle pointer a2 [source:raw]
    // CALL: Invoked by suspension and vehicle-physics callers (SuspensionSetupSectionReader 0x00435410, SuspensionDataCopyToPhysicsEngine 0x004389B0, VehiclePhysicsInitializer 0x00439210, RigidBodyConstraintSolve 0x0043E4B0, F_3x3RotationTensorMatrixTransform 0x005691D0, sub_56F100 0x0056F100) [caller:0x00435410, caller:0x004389B0, caller:0x00439210, caller:0x0043E4B0, caller:0x005691D0, caller:0x0056F100, source:raw]

    // Conservative worker pseudocode:
    //   sx = sin(a2[0]); cx = cos(a2[0]);
    //   sy = sin(a2[1]); cy = cos(a2[1]);
    //   sz = sin(a2[2]); cz = cos(a2[2]);
    //   this[0] = sy*sx*sz + cz*cy;   // 0x0
    //   this[1] = sy*sx*cz - sz*cy;   // 0x8
    //   this[2] = sy*cx;              // 0x10
    //   this[3] = sz*cx;              // 0x18
    //   this[4] = cz*cx;              // 0x20
    //   this[5] = -sx;                // 0x28
    //   this[6] = sz*cy*sx - cz*sy;   // 0x30
    //   this[7] = sz*sy + cz*cy*sx;   // 0x38
    //   this[8] = cy*cx;              // 0x40
    //   return a2;
    // UNRESOLVED: Euler angle order (which axis is first) and whether the convention is intrinsic or extrinsic cannot be established from this packet alone
    // UNRESOLVED: The object owning the output matrix is caller-supplied; the packet owner is unknown
}
