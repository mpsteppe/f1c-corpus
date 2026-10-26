// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00434D60
// Canonical corpus name: SteeringInterpolationCameraFollow
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SteeringInterpolationCameraFollow_00434d60.c

void UnknownObject::SteeringInterpolationCameraFollow()
{
    // Per-frame camera-follow routine that computes an interpolated steering/look angle and camera position for a target object. Guards on a non-null target pointer (this+0xC) whose active flag is set, then branches between a special fixed-camera path (camera mode 5, invalid vehicle index, or index out of range) and a normal vehicle-follow path that queries track node positions, blends them with an interpolation factor, eases the steering angle toward a target with frame-delta steps, and issues final follow calls through the target's vtable.
    // GUARD: Load the target object pointer from this+0xC; proceed only when it is non-null and its active flag (field *(*(this+0xC)+0x0)+0x18, raw offset +176) is non-zero. [field:*(this+0xC):0x00000000, field:*(*(this+0xC)+0x0):0x00000018, field:*(this+0xC):0x000000B0, source:raw]
    // ASSIGNMENT: Compute the previous element index as this+0x2C - 1 and obtain previous, current and next stride-array element pointers via StridedArrayElementPointer; capture v36 from the target float at +0xBC and default interpolation factor v33 to -1.0; when previous and current exist, compute v33 = (current+24 - target+0xBC) / (current+24 - previous+24) and scale it by this+0x30 into v34. [callee:0x004582A0, field:this:0x0000002C, field:this:0x00000030, field:*(this+0xC):0x000000BC, source:raw]
    // GUARD: Select the path: if vehicle index this+0x18 is below 0 (guard:1), or secondary index this+0x1C is below 0, or this+0x18 is at/above the global vehicle count dword_5C329C, or camera mode this+0x4 equals 5 (guard:0), take the fixed-camera fallback branch instead of the vehicle-interpolation branch. [guard:0, guard:1, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000004, global:0x005C329C, source:raw]
    // ASSIGNMENT: Fixed-camera fallback: negate the first three floats of stride element 4 into the view vector v37/v38/v39; when element 4 is absent, build the vector through sub_403CD0(dword_5EA2C0, 0, &v37, v46). [callee:0x00403CD0, global:0x005EA2C0, source:raw]
    // CALL: Normal path setup: transform a point via F_3DTransformPointByMatrixAndTranslation(&v40, v46), then query the track node position via sub_403CD0(dword_5EA2C0, this+0x1C, &v43, v46). [callee:0x004E1FD0, callee:0x00403CD0, global:0x005EA2C0, field:this:0x0000001C, source:raw]
    // GUARD: If the per-vehicle camera-enable flag dword_5EB978[this+0x18] is set, run the interpolated-follow branch; otherwise take the next-stride-element steering path. [global:0x005EB978, field:this:0x00000018, source:raw]
    // CALCULATION: Interpolated-follow branch: blend the two query points with factor v33 clamped to [0,1]; read back steering targets via DualFieldGetter(&v33, &v35); if v33 exceeds threshold this+0x14, ease it down by dbl_8AFE98*5.0 per step (clamped to the threshold); write v33 to target+0x38 and v35 to target+0x3C. [callee:0x00456060, callee:0x004E1FD0, field:this:0x00000014, field:*(this+0xC):0x00000038, field:*(this+0xC):0x0000003C, global:0x008AFE98, source:raw]
    // CALCULATION: Next-element steering path: negate the next stride element's components when present; read steering targets via DualFieldGetter(&v35, &v33); if v35 is below threshold this+0x10, ease it up by dbl_8AFE98*20.0 per step (clamped to the threshold); write the results to target+0x38 and target+0x3C. [callee:0x00456060, field:this:0x00000010, field:*(this+0xC):0x00000038, field:*(this+0xC):0x0000003C, global:0x008AFE98, source:raw]
    // CALL: Invoke GuardedFunctionWithFlagSet(v36) using the value captured from the target field +0xBC. [callee:0x004582C0, field:*(this+0xC):0x000000BC, source:raw]
    // ASSIGNMENT: One-shot branch: if byte flag this+0x1 is set, save target+0xA8, clear it to 0, call the target vtable method at offset +24 with (&v37, v46, v50, 1148846080, 1148846080), restore target+0xA8, then clear this+0x1. [field:this:0x00000001, field:this:0x0000000C, field:*(this+0xC):0x000000A8, source:raw]
    // CALL: Final follow call when the a2 argument is zero: invoke the target vtable method at offset +24 with the computed vector &v37, passing dbl_8AFE90 and dbl_8AFE98 (via v32) as the last two arguments, and return its result. [global:0x008AFE90, global:0x008AFE98, field:this:0x0000000C, source:raw]
    // CALCULATION: Steering easing when a2 is non-zero: read the current steering value from target+0xA8, ease it toward v34 (the factor v33 scaled by this+0x30) using dbl_8AFE98 steps, clamp it to the range [0, this+0x30], write it back to target+0xA8, then fall through to the final follow call. [field:*(this+0xC):0x000000A8, field:this:0x00000030, global:0x008AFE98, source:raw]
    // CALL: Invoked from CarSelectionStateMachine (0x00434460) and sub_4348B0 (0x004348B0). [caller:0x00434460, caller:0x004348B0, source:raw]

    // Conservative worker pseudocode:
    //   int SteeringInterpolationCameraFollow(int this, char a2) {
    //     int target = *(int*)(this + 0xC);
    //     if (!target || !*(int*)(target + 176)) return target;
    //     float factor = -1.0f;
    //     int prevIdx = *(int*)(this + 0x2C) - 1;
    //     float followArg = *(float*)(target + 0xBC);
    //     void* prev = StridedArrayElementPointer(prevIdx);
    //     void* cur  = StridedArrayElementPointer(*(int*)(this + 0x2C));
    //     void* next = StridedArrayElementPointer(*(int*)(this + 0x2C) + 1);
    //     if (prev && cur) {
    //       factor = (*(float*)(cur + 24) - *(float*)(target + 0xBC))
    //              / (*(float*)(cur + 24) - *(float*)(prev + 24));
    //       float scale = factor * *(float*)(this + 0x30);
    //     }
    //     if (*(int*)(this + 0x18) < 0 || *(int*)(this + 0x1C) < 0
    //         || *(int*)(this + 0x18) >= dword_5C329C || *(int*)(this + 0x4) == 5) {
    //       /* fixed-camera fallback: negate element-4 vector or build via sub_403CD0 * /
    //     } else {
    //       F_3DTransformPointByMatrixAndTranslation(&posA, tmp);
    //       sub_403CD0(dword_5EA2C0, *(int*)(this + 0x1C), &posB, tmp);
    //       if (dword_5EB978[*(int*)(this + 0x18)]) {
    //         /* blend posA/posB by clamped factor, ease steering toward this+0x14 * /
    //         DualFieldGetter(&factor, &angle2);
    //         *(float*)(target + 0x38) = eased;
    //         *(float*)(target + 0x3C) = angle2;
    //       } else {
    //         /* negate next element, ease steering toward this+0x10 * /
    //         DualFieldGetter(&angle2, &factor);
    //         *(float*)(target + 0x38) = eased;
    //         *(float*)(target + 0x3C) = angle2;
    //       }
    //     }
    //     GuardedFunctionWithFlagSet(followArg);
    //     if (*(char*)(this + 0x1)) {
    //       int saved = *(int*)(target + 0xA8);
    //       *(int*)(target + 0xA8) = 0;
    //       (vtable(target, 24))(target, &vec, tmp, buf, 1148846080, 1148846080);
    //       *(int*)(target + 0xA8) = saved;
    //       *(char*)(this + 0x1) = 0;
    //     }
    //     if (!a2) return (vtable(target, 24))(target, &vec, tmp, buf, dbl_8AFE90, 0.0f);
    //     float steer = *(float*)(target + 0xA8);
    //     /* ease steer toward scale, clamp to [0, this+0x30] * /
    //     *(float*)(target + 0xA8) = clamped;
    //     return (vtable(target, 24))(target, &vec, tmp, buf, dbl_8AFE90, dbl_8AFE98);
    //   }
    // UNRESOLVED: The stride-array element layout (position fields at +24, camera anchor at +0xBC) and the track-node layout consumed by sub_403CD0 are DERIVED from the caller/analysis; only the offsets present in the packet are evidence.
    // UNRESOLVED: The target field at +0xA8 (168) is used both as a one-shot gate flag (saved/restored around the vtable call) and as the eased steering-angle accumulator; the packet's existing analysis names it only as a gate flag (DERIVED).
    // UNRESOLVED: The two integer literals 1148846080 passed to the vtable follow call are read as float bit patterns only in analysis prose; the packet does not decode them.
    // UNRESOLVED: The globals flt_59E43C, flt_59E440, flt_59E7EC, flt_59E8A4, flt_59E8EC and dword_7C54F0 are listed in the packet as reads but do not appear in the raw body; their role here is unknown (dword_7C54F0 is the corpus-wide active-vehicle pointer array, but that cannot be locked from this packet alone).
}
