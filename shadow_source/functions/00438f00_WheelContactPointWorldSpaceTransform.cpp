// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00438F00
// Canonical corpus name: sub_438F00
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_438F00_00438f00.c

void UnknownObject::WheelContactPointWorldSpaceTransform()
{
    // Reads a 3-element suspension geometry offset vector from this+0x1614..0x1624, adds a caller-supplied delta (a3), and when the body pointer at this+0x1E8 is non-null transforms the vector into world space via the 3x3 rotation matrix and translation stored in the geometry struct (base this+0x15F0), writes the resulting 0x18-byte point into body+4, and derives euler angles from geometry elements (with a pole branch when an element equals 1.0, the dbl_59E420 constant). Ends by calling SuspensionSetupSectionReader (0x00435410) and returning its result.
    // ASSIGNMENT: Copy the 3-element suspension geometry offset vector from this+0x1614, this+0x161C, this+0x1624 into local v15 (qmemcpy, 0x18 bytes), then add the caller's a3 delta into each component. [field:this:0x00001614, field:this:0x0000161C, field:this:0x00001624, source:raw]
    // ASSIGNMENT: Zero the 6-dword local buffer v19 (memset), later passed to SuspensionSetupSectionReader. [source:raw]
    // GUARD: Guard on the body pointer stored at this+0x1E8: when non-null, run the world-space position transform and euler-angle derivation. [field:this:0x000001E8]
    // CALCULATION: Transform the offset vector by the 3x3 rotation matrix read from the geometry struct at this+0x15F0: rows at +0x160C/+0x1614/+0x161C, +0x1624/+0x162C/+0x1634 and +0x163C/+0x1644/+0x164C. [field:this:0x000015F0, field:this:0x0000160C, field:this:0x00001614, field:this:0x0000161C, field:this:0x00001624, field:this:0x0000162C, field:this:0x00001634, field:this:0x0000163C, field:this:0x00001644, field:this:0x0000164C]
    // CALCULATION: Add the geometry translation vector at this+0x15F4, this+0x15FC, this+0x1604 to the rotated offset to form the world-space point v20. [field:this:0x000015F4, field:this:0x000015FC, field:this:0x00001604]
    // ASSIGNMENT: Copy the 0x18-byte world-space point into body+4, the attached body position (qmemcpy from v20). [field:this:0x000001E8, source:raw]
    // CALL: Read the geometry double at this+0x1634, negate it into v16, then call FloatConvertWrapper (0x00588570) before the euler-angle computation. [field:this:0x00001634, callee:0x00588570]
    // GUARD: Guard on fabs of the element at this+0x1634 equal to 1.0 (constant dbl_59E420): selects the pole euler-angle branch instead of the general atan2 branch. [field:this:0x00001634, global:0x0059E420]
    // CALCULATION: Derive euler angles via atan2 from geometry elements at this+0x160C, this+0x161C, this+0x1624, this+0x162C, this+0x163C, this+0x164C (pole branch uses negated elements at this+0x163C and this+0x160C). [field:this:0x0000160C, field:this:0x0000161C, field:this:0x00001624, field:this:0x0000162C, field:this:0x0000163C, field:this:0x0000164C]
    // CALL: Call F_3x3RotationTensorMatrixTransform (0x005691D0) on the local euler/tensor value v16. [callee:0x005691D0]
    // RETURN: Call SuspensionSetupSectionReader (0x00435410) with this+123, the body pointer from this+0x1E8, a2, the updated v15 offset vector and the zeroed v19 buffer, and return its result. [callee:0x00435410, field:this:0x000001E8]

    // Conservative worker pseudocode:
    //   // copy geometry offset and apply caller delta
    //   v15[0..2] = this->offset[0x1614..0x1624];
    //   v15[0]+=a3[0]; v15[1]+=a3[1]; v15[2]+=a3[2];
    //   memset(v19, 0, sizeof(v19));
    //   body = this->bodyPtr[0x1E8];
    //   if (body) {
    //     geo = this->geoPtr[0x15F0];
    //     world = geo->rot[3x3] * v15 + geo->trans[0x15F4..0x1604];
    //     memcpy(body+4, world, 0x18);
    //     v16 = -geo->[0x1634]; FloatConvertWrapper();
    //     if (fabs(geo->[0x1634]) == dbl_59E420 /* 1.0 * /) {
    //       v17 = atan2(-geo->[0x163C], geo->[0x160C]); v18 = 0.0;
    //     } else {
    //       v17 = atan2(geo->[0x161C], geo->[0x164C]);
    //       v18 = atan2(geo->[0x1624], geo->[0x162C]);
    //     }
    //     F_3x3RotationTensorMatrixTransform(&v16);
    //   }
    //   return SuspensionSetupSectionReader(this+123, body, a2, v15, v19);
    // UNRESOLVED: proposed_name derives from the legacy ABI label Wheel_Contact_Point_World_Space_Transform; semantic name requires confirmation.
    // UNRESOLVED: Exact meaning of the FloatConvertWrapper call and the euler/tensor value v16 is not determinable from this packet.
    // UNRESOLVED: The attachment semantics of writing the 0x18-byte point into body+4 (this+0x1E8) depend on the body layout, not defined here.
    // UNRESOLVED: Semantics of a2 passed to SuspensionSetupSectionReader are caller-specific and unknown from this packet.
}
