// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DF110
// Canonical corpus name: sub_4DF110
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4DF110_004df110.c

void UnknownObject::sub_4DF110()
{
    // Updates a wheel-ground contact database after inserting a new contact depth. Maintains a sorted entry list keyed on this[0] (0x0), mutates vertex contact groups (descriptor array at 0xC, count at 0x8), applies soft-sphere deformation, vertex relaxation and secondary sphere-contact resolution, recomputes face normals via linked triangles and sets dirty flags on the groups. Returns whether any contact data changed.
    // GUARD: Group descriptor processing is gated on the count at this+0x8 (iteration skipped when the count is not positive). [guard:0, guard:1]
    // GUARD: Secondary contact entry processing is gated on the count at this+0x10 being positive. [guard:2]
    // CALCULATION: Read the current depth key at this[0] (0x0) and compare it with the incoming value a2 to select the sorted-entry insertion path. [field:this:0x00000000]
    // LOOP: Scan the sorted contact-entry array (base this+0x8, 9 floats per entry, count at this+0x18) to find the insertion slot for the incoming depth relative to the current this[0] key. [field:this:0x00000008, field:this:0x00000018, field:this:0x00000000]
    // ASSIGNMENT: Store the incoming depth value a2 into this[0] (0x0) so it becomes the new current contact key. [field:this:0x00000000]
    // RETURN: When no sorted slot matches, commit this[0] = a2 and return immediately without mutating any contact groups. [field:this:0x00000000, source:raw]
    // LOOP: Iterate group descriptors (count at this+0x8, descriptor array base at this+0xC); each descriptor carries a sub-entry count and a sub-entry array. [field:this:0x00000008, field:this:0x0000000C]
    // ASSIGNMENT: Snapshot pass: for each 64-byte-strided sub-entry, copy 3 float values from the sub-entry into its target pointer (used to restore or mirror contact vertex state). [field:this:0x0000000C]
    // STATE_TRANSITION: Set the change flag (v112) once any mutation path runs; it drives the final dirty-flag and normal recompute pass. [function:0x004DF110, source:raw]
    // CALCULATION: Dispatch per sorted entry on an entry type tag (0, 1, 2): soft deformation, vertex relaxation, or a restore copy. [field:this:0x00000008]
    // CALCULATION: Soft sphere deformation (type 0): pull each sub-entry target vertex toward a sphere center offset by 0.12 using reciprocal-distance scaling when inside the squared radius, then clamp the displaced vertex to the stored maximum distance. [field:this:0x00000008, field:this:0x0000000C]
    // CALCULATION: Vertex relaxation (type 1): move each target vertex toward its anchor position by the factor 0.075/sqrt(distance^2) when the squared distance exceeds the threshold 0.0056250002. [field:this:0x00000008, field:this:0x0000000C]
    // ASSIGNMENT: Restore path (type 2): copy 3 float values from each sub-entry back into its target pointer. [field:this:0x0000000C]
    // LOOP: Iterate secondary contact entries (count at this+0x10, base at this+0x14); each secondary entry defines a sphere center, a radius and a list of target vertices. [field:this:0x00000010, field:this:0x00000014]
    // CALCULATION: Secondary resolution: for each target vertex whose stored position differs from its current value, solve the sphere-line quadratic against the secondary sphere and slide the vertex along the closest-approach direction, keeping the squared distance inside the radius. [field:this:0x00000014]
    // STATE_TRANSITION: Dirty pass: when the change flag is set, mark every group's target by clearing flags with 0xFEFFFFDF and setting 0x400000. [field:this:0x00000008, field:this:0x0000000C]
    // CALL: Fetch triangle vertex coordinates via sub_4DE5D0(link, index), reading 3 floats per vertex. [callee:0x004DE5D0]
    // CALL: Accumulate a face normal with TriangleNormalComputation over the fetched triangle vertices. [callee:0x004DD9F0]
    // CALCULATION: Normal recompute: for each sub-entry, if the vertex still equals its anchor copy restore the stored normal fields; otherwise accumulate normals across up to 7 linked triangles, normalize by 1/sqrt(length^2) and write the result to the vertex. [field:this:0x0000000C, callee:0x004DD9F0, callee:0x004DE5D0]
    // RETURN: Return the change flag (nonzero when any contact data was mutated in this call). [function:0x004DF110, source:raw]

    // Conservative worker pseudocode:
    //   // this[0] is the current contact depth key; a2 is the new candidate depth.
    //   // find insertion slot in the sorted entry list (this+0x8, 9 floats/entry, count this+0x18).
    //   // if none: this[0] = a2 and return unchanged.
    //   // else: commit this[0] = a2; apply per-type vertex mutation; process secondary spheres.
    //   // if anything changed: set dirty flags on all groups and recompute vertex normals.
    // UNRESOLVED: The sorted entry layout (offsets of the type tag, sphere center, displacement and limit fields inside each 9-float entry) is not directly represented by the packet top-level fields.
    // UNRESOLVED: Globals 0x59E430, 0x59E43C, 0x59E440, 0x59E46C, 0x59E670, 0x59EF78, 0x5AD144, 0x5AD148 are read-only physics constants (thresholds/limits), but the raw text does not show where each is consumed, so none is bound to a specific comparison.
    // UNRESOLVED: The purpose of the this+0x20 field could not be pinned to a specific instruction in the raw text; it lies inside the sorted-entry region and is treated as per-entry contact data.
    // UNRESOLVED: The exact meaning of the flag bits 0xFEFFFFDF/0x400000 written to the group target is unknown (dirty/active mask).
    // UNRESOLVED: The 0.0056250002 and 0.075000003 literals are thresholds/scale factors for the vertex relaxation step.
}
