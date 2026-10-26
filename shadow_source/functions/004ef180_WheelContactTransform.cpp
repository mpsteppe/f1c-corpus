// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004EF180
// Canonical corpus name: WheelContactTransform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WheelContactTransform_004ef180.c

void UnknownObject::WheelContactTransform()
{
    // Transforms each of four wheel-contact corner vectors by a 3x3 rotation matrix stored on the object, adds the world-origin offset, queries the collision normal from feature data, stores it into the per-corner contact-normal pointer array, and updates wheel-surface friction for the contact. Runs once per frame tick as part of the wheel contact/collision system.
    // LOOP: Iterate over the four wheel contacts: the corner-vector base advances by 74 floats and the contact-normal pointer array by 62 pointer slots each step, until the corner index reaches 296 floats. [source:raw]
    // CALCULATION: Rotate the per-corner offset vector (this[523..525]) by the 3x3 rotation matrix stored at fields 0x704 through 0x724 to produce the local-space contact vector components. [field:this:0x00000704, field:this:0x00000708, field:this:0x0000070C, field:this:0x00000710, field:this:0x00000714, field:this:0x00000718, field:this:0x0000071C, field:this:0x00000720, field:this:0x00000724, source:raw]
    // CALL: Add the world-origin offset vector this[443] to the transformed contact point via F_3DVectorAddition. [callee:0x004EC020, source:raw]
    // ASSIGNMENT: Pack the transformed contact coordinates and the constant dword payload (v12..v15, preserved verbatim) into the query structure passed to the collision query. [source:raw]
    // CALL: Query the collision normal for the contact point from the feature-data global dbl_7C9360 via CollisionNormalFromFeature, writing the resulting vector into the out parameter. [callee:0x0044C550, global:0x007C9360, source:raw]
    // GUARD: When a valid collision normal is returned, apply the 0.050000001 contact-depth adjustment and store the normal into the corner's contact-normal pointer slot (array rooted at field 0x3668). [field:this:0x00003668, source:raw]
    // CALL: Update the wheel-surface friction for the contact via WheelSurfaceContactFriction, passing the feature data and the transformed contact point. [callee:0x004CE110, source:raw]

    // Conservative worker pseudocode:
    //   // Transform per-corner contact vectors, query collision normal, apply friction.
    //   void sub_4EF180(float* this) {
    //     for (int c = 0; c < 4; ++c) {
    //       vec3 local = Rotate3x3(&this[449], &this[523]);
    //       AddVector(local, &this[443]);
    //       double* normal = CollisionNormalFromFeature(&dbl_7C9360, local, out);
    //       if (normal) {
    //         this_contact_normal_ptr[c] = normal;
    //         WheelSurfaceContactFriction(*(int**)normal + 21, contact, &local, out);
    //       }
    //     }
    //   }
    // UNRESOLVED: The structure at dbl_7C9360 (collision feature data) is unnamed; only that it is read by CollisionNormalFromFeature is known.
    // UNRESOLVED: The meaning of the four constant dwords (v12..v15) packed alongside the transformed vector in the query structure is unresolved; they are preserved verbatim.
    // UNRESOLVED: The rotation matrix at offsets 0x704..0x724 and the contact origin this[443] are consumed but their higher-level frame naming (track frame versus local frame) is unverified.
    // UNRESOLVED: global:0x0059E448 (flt_59E448) is listed as referenced by the existing analysis but has no visible use in the recovered body.
}
