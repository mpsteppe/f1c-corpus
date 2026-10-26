// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0056A150
// Canonical corpus name: VehiclePhysicsStateCopyTransform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehiclePhysicsStateCopyTransform_0056a150.c

void UnknownObject::VehiclePhysicsStateCopyTransform()
{
    // Copies physics state blocks from an internal prediction buffer region (offsets this+0x164 onward) into the working state region (this+0x4 onward), calls F_3x3InertiaTensorTransform to update the world-space inverse inertia tensor, then computes angular velocity (this+0x7C/0x84/0x8C) as world-space inverse inertia times angular momentum (this+0x94/0x9C/0xA4). Straight-line rigid-body integration step invoked by BatchIterationWithCounter (0x0056F060).
    // CALL: Copy a 24-byte block from this+0x164 to this+0x4, matching the layout of a 3-element vector (e.g. position). [source:raw, caller:0x0056F060]
    // CALL: Copy a 72-byte block from this+0x17C to this+0x1C, matching the layout of a 3x3 matrix (e.g. rotation/orientation). [source:raw]
    // CALL: Copy a 24-byte block from this+0x1C4 to this+0x64. [source:raw]
    // CALL: Copy a 24-byte block from this+0x1DC to this+0x94; this destination is later consumed as the angular momentum vector. [source:raw, field:this:0x00000094]
    // CALL: Copy a 24-byte block from this+0x1F4 to this+0x134. [source:raw]
    // CALL: Copy a 24-byte block from this+0x20C to this+0x14C. [source:raw]
    // CALL: Run F_3x3InertiaTensorTransform on this to update the world-space inverse inertia tensor; its return value is the function result. [callee:0x005692A0, field:this:0x000000EC, field:this:0x000000F4, field:this:0x000000FC, field:this:0x00000104, field:this:0x0000010C, field:this:0x00000114, field:this:0x0000011C, field:this:0x00000124, field:this:0x0000012C]
    // CALCULATION: Compute angular velocity x (this+0x7C) as row 0 of the world inverse inertia (this+0xFC, this+0xF4, this+0xEC) dotted with angular momentum (this+0xA4, this+0x9C, this+0x94). [field:this:0x0000007C, field:this:0x000000FC, field:this:0x000000F4, field:this:0x000000EC, field:this:0x000000A4, field:this:0x0000009C, field:this:0x00000094]
    // CALCULATION: Compute angular velocity y (this+0x84) as row 1 of the world inverse inertia (this+0x114, this+0x10C, this+0x104) dotted with angular momentum. [field:this:0x00000084, field:this:0x00000114, field:this:0x0000010C, field:this:0x00000104, field:this:0x000000A4, field:this:0x0000009C, field:this:0x00000094]
    // CALCULATION: Compute angular velocity z (this+0x8C) as row 2 of the world inverse inertia (this+0x12C, this+0x124, this+0x11C) dotted with angular momentum. [field:this:0x0000008C, field:this:0x0000012C, field:this:0x00000124, field:this:0x0000011C, field:this:0x000000A4, field:this:0x0000009C, field:this:0x00000094]
    // RETURN: Return the result of F_3x3InertiaTensorTransform. [source:raw, callee:0x005692A0]

    // Conservative worker pseudocode:
    //   copy16(this+0x164, this+0x4, 0x18);
    //   copy16(this+0x17C, this+0x1C, 0x48);
    //   copy16(this+0x1C4, this+0x64, 0x18);
    //   copy16(this+0x1DC, this+0x94, 0x18);
    //   copy16(this+0x1F4, this+0x134, 0x18);
    //   copy16(this+0x20C, this+0x14C, 0x18);
    //   result = F_3x3InertiaTensorTransform(this);
    //   this+0x7C = this+0xFC * this+0xA4 + this+0xF4 * this+0x9C + this+0xEC * this+0x94;
    //   this+0x84 = this+0x114 * this+0xA4 + this+0x10C * this+0x9C + this+0x104 * this+0x94;
    //   this+0x8C = this+0x12C * this+0xA4 + this+0x124 * this+0x9C + this+0x11C * this+0x94;
    //   return result;
    // UNRESOLVED: Copy source/destination offsets (this+0x164, this+0x17C, this+0x1C4, this+0x1DC, this+0x1F4, this+0x20C and destinations this+0x4, this+0x1C, this+0x64, this+0x134, this+0x14C) have no per-field evidence refs in the packet; their semantic roles (position, orientation, momentum buffers) are inferred from block sizes only.
    // UNRESOLVED: Semantics of the copied vector/matrix blocks (which buffer is the prediction state vs working state) is unverified.
    // UNRESOLVED: Where the world-space inverse inertia tensor produced by F_3x3InertiaTensorTransform is stored is not established by this packet.
}
