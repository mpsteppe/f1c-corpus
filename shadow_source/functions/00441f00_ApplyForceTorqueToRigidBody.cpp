// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00441F00
// Canonical corpus name: ForceTorqueApplicationToRigidBodyWithInertiaTens
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ForceTorqueApplicationToRigidBodyWithInertiaTens_00441f00.c

void UnknownObject::ApplyForceTorqueToRigidBody()
{
    // Rigid-body force/torque application. If all four float inputs a2..a5 are 0.0, clears the active byte at this+0x1724. Otherwise sets this+0x1724 to 1 and, for each of 4 wheel slots (index 0..3, stride 24 bytes), transforms the slot's velocity components (v7[716], v7[717], v7[718]) through a 3x4 double inertia-tensor matrix pointed to by this+0x15F0, adds the tensor translation offsets, subtracts a per-index velocity term (this + 8*index + 5872), and composes the output vector with the per-index input (a2/a3/a4/a5), a damping term (this+0x15F4 * 0.000015328125) and a term at this + 8*(index+1) + 5920; the 24-byte (0x18) result is copied to the slot's output region at v7 + 745.
    // GUARD: If all four float inputs a2, a3, a4, a5 are 0.0, clear the active byte at this+0x1724 and skip the computation. [source:raw, field:this:0x00001724]
    // ASSIGNMENT: Set the active byte at this+0x1724 to 1. [field:this:0x00001724]
    // LOOP: Iterate indices 0..3 (4 wheel slots), each slot base at this + 24*index. [source:raw]
    // CALCULATION: Per slot, load the inertia-tensor pointer at this+0x15F0 and dot each of its three rows (offsets 0x1C/0x24/0x2C, 0x34/0x3C/0x44, 0x4C/0x54/0x5C) with the slot's three velocity components at v7[716], v7[717], v7[718]. [field:this:0x000015F0, field:*(this+0x15F0):0x0000001C, field:*(this+0x15F0):0x00000024, field:*(this+0x15F0):0x0000002C, field:*(this+0x15F0):0x00000034, field:*(this+0x15F0):0x0000003C, field:*(this+0x15F0):0x00000044, field:*(this+0x15F0):0x0000004C, field:*(this+0x15F0):0x00000054, field:*(this+0x15F0):0x0000005C, source:raw]
    // CALCULATION: Add the tensor translation offsets at v8+0x4, v8+0xC, v8+0x14 to the transformed components, then subtract the per-slot velocity at this + 8*index + 5872. [field:*(this+0x15F0):0x00000004, field:*(this+0x15F0):0x0000000C, field:*(this+0x15F0):0x00000014, source:raw]
    // CALCULATION: Select the per-index input (a2 for index 0, a3 for 1, a4 for 2, a5 for 3), add the intermediate result, add the term at this + 8*(index+1) + 5920, and add the damping term this+0x15F4 * 0.000015328125 to form the output component. [source:raw, field:this:0x000015F4, global:0x0059ED58]
    // ASSIGNMENT: Copy the 24-byte (0x18) result vector into the slot's output region at v7 + 745. [source:raw]

    // Conservative worker pseudocode:
    //   if (a2==0.0 && a3==0.0 && a4==0.0 && a5==0.0) { this[0x1724] = 0; return; }
    //   this[0x1724] = 1;
    //   tensor = *(this + 0x15F0);
    //   for (i = 0; i < 4; i++) {
    //     slot = (double*)(this + 24*i);
    //     out.x = dot(tensor_rows[0x1C/0x24/0x2C], {slot[716],slot[717],slot[718]}) + tensor[0x4];
    //     tmp   = dot(tensor_rows[0x34/0x3C/0x44], {slot[716],slot[717],slot[718]}) + tensor[0xC] - *(this + 8*i + 5872);
    //     out.z = dot(tensor_rows[0x4C/0x54/0x5C], {slot[716],slot[717],slot[718]}) + tensor[0x14];
    //     out.y = input(i) + tmp + *(this + 8*(i+1) + 5920) + *(this + 0x15F4) * 0.000015328125;
    //     memcpy(slot + 745, &out, 0x18);
    //   }
    // UNRESOLVED: Meaning of the per-slot velocity sources at v7[716..718] and the term at this + 8*(index+1) + 5920 is unproven; these offsets have no dedicated evidence refs and are grounded in raw source only.
    // UNRESOLVED: Precise layout of the 3x4 double inertia-tensor matrix and how its transform/translation halves map to physical quantities is unconfirmed.
    // UNRESOLVED: Role of the damping multiplier this+0x15F4 * 0.000015328125 is unclear; dbl_59ED58 is referenced as the double constant candidate, while the float constant global flt_59E440 has no visible use in the raw source body.
    // UNRESOLVED: Function has no static callers and no callees; invocation context is unknown.
}
