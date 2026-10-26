// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00447780
// Canonical corpus name: sub_447780
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_447780_00447780.c

void UnknownObject::SuspensionForceUpdate()
{
    // Vehicle suspension force update step: copies the 24-byte input state into every physics sub-object block, computes a per-wheel suspension force from the input vector and the mode selected at this+0x1E14 (7700), applies a clamped damper scaling and wheel-weight minimum selection, records the force into the duplicated output slots, feeds SuspensionVibration, then propagates the shared transform and inertia-tensor blocks into each active sub-object.
    // LOOP: If the sub-object count at this+0x15AC is positive, iterate the sub-object array at this+0x15B0, copying the 24-byte input vector a2 into each sub-object block at offset +100 (stride 580) and calling Copy6DwordsToStructCall on a zeroed scratch for each entry. [field:this:0x000015AC, field:this:0x000015B0, callee:0x00569280, source:raw]
    // CALCULATION: Compute the raw suspension force scalar from the shared state at this+0x15F0: multiply the weight at +0x5C by input component a2[2], add the weight row at +40 times a2[1] and the weight row at +16 times a2[0], and negate the sum into a candidate. [field:this:0x000015F0, field:*(this+0x15F0):0x0000005C, source:raw]
    // LOOP: Four-iteration unrolled loop starting at this+0x348 (840): for each wheel pair advance the cursor by 1124, divide the negated candidate by the geometry weight at cursor minus 788, and write the quotient into both members of the pair (this+840/848, this+1964/1972, this+3088/3096, this+4212/4220). [field:this:0x00000348, field:this:0x000007AC, field:this:0x00000C10, field:this:0x00001074, source:raw]
    // CALCULATION: Select the averaging mode at this+0x1E14 (7700): mode 0 averages wheel pairs at this+0x1074 and this+0xC10, mode 1 averages this+0x1074, this+0xC10, this+0x7AC and this+0x348, and mode 2 averages this+0x7AC and this+0x348. [field:this:0x00001E14, field:this:0x00001074, field:this:0x00000C10, field:this:0x000007AC, field:this:0x00000348, source:raw]
    // CALCULATION: Derive a clamped damper scaling factor: v16 = fabs(candidate) * 0.018 + 0.2, clamped to the range 0.0..0.8. [source:raw]
    // CALCULATION: Write the mode-selected force into the suspension output at this+0x1C5C as the product of -v12 and the wheel-weight array entry at this + 8*selector + 7856; when the selector at this+0x1EAC is positive, walk the wheel weights backward and replace the output whenever a per-wheel magnitude is below the clamped threshold scaled by this+0x1CDC. [field:this:0x00001C5C, field:this:0x00001EAC, field:this:0x00001CDC, field:this:0x00001C84, source:raw]
    // GUARD: Clamp against the lower bound at this+0x1C84: if the computed force at this+0x1C5C is below it, copy the bound and its high dword from this+0x1C88 into the output and report via PositionLapStateUpdate(0, 4); otherwise report via PositionLapStateUpdate(selector, 4). Then propagate the force dwords into the duplicated slots at this+0x1C64/0x1C68 and this+0x1E38/0x1E3C/0x1E40/0x1E44. [field:this:0x00001C84, field:this:0x00001C88, field:this:0x00001C5C, field:this:0x00001C60, field:this:0x00001C64, field:this:0x00001C68, field:this:0x00001E38, field:this:0x00001E3C, field:this:0x00001E40, field:this:0x00001E44, callee:0x00447E00, source:raw]
    // CALL: Feed the finalized suspension force into SuspensionVibration(this, 1). [callee:0x004471F0, source:raw]
    // ASSIGNMENT: Reset the sub-object active flag at this+0xD0 to 0 before the sub-object integration pass. [field:this:0x000000D0, source:raw]
    // LOOP: Two-pass loop over sub-objects at this+0x3EC (stride 1124): skip inactive nodes and nodes whose +100 flag is set; otherwise read the 0x48-byte transform block (covering +0x2C and +0x44 within the shared block at this+0x15F0) and the 24-byte inertia block, zero the sub-object via sub_56BDE0, copy the transform into the node at +28, run F_3x3InertiaTensorTransform, copy the inertia block into the node at +124, run InertiaTensorWorldSpaceTransform, then release the sub-object via PhysicsSubObjectFree. [field:this:0x000003EC, field:this:0x000015F0, field:*(this+0x15F0):0x0000002C, field:*(this+0x15F0):0x00000044, callee:0x0056BDE0, callee:0x005692A0, callee:0x00569410, callee:0x00441450, source:raw]
    // RETURN: Return the loop decrement result (v32 - 1, i.e. 1 after the two-pass loop). [source:raw]
    // CALL: Called by SessionStateTransition (0x004EF5A0) as part of the session-state vehicle physics update. [caller:0x004EF5A0, source:raw]

    // Conservative worker pseudocode:
    //   int SuspensionForceUpdate(this, double* input) {
    //     for (i = 0; i < *(int*)(this + 5548); ++i)
    //       memcpy(*(int*)(this + 5552) + 580*i + 100, input, 24),
    //       Copy6DwordsToStructCall(&zeroed);
    //     s = *(double**)(this + 5616);
    //     cand = -(s[92] * input[2] + (s+28)[40] * input[1] + (s+28)[16] * input[0]);
    //     for (k = 0, p = this + 840; k < 4; ++k, p += 1124) {
    //       q = -(cand / *(double*)(p + 336));
    //       *(double*)(p) = q; *(double*)(p + 8) = q;
    //     }
    //     switch (*(int*)(this + 7700)) {
    //       case 0: avg = (*(double*)(this+4212) + *(double*)(this+3088)) * 0.5; break;
    //       case 1: avg = (*(double*)(this+4212) + *(double*)(this+3088) + *(double*)(this+1964) + *(double*)(this+840)) * 0.25; break;
    //       default: avg = (*(double*)(this+1964) + *(double*)(this+840)) * 0.5; break;
    //     }
    //     scale = clamp(fabs(cand) * 0.018 + 0.2, 0.0, 0.8);
    //     force = -avg * *(double*)(this + 7856 + 8**(int*)(this+7852));
    //     // wheel-weight minimum selection with clamp at this+7300
    //     // report via PositionLapStateUpdate, propagate to duplicated slots
    //     SuspensionVibration(this, 1);
    //     *(int*)(this + 208) = 0;
    //     for (obj = this + 1004; ...; obj += 1124)
    //       if (*(int*)obj && !*(byte*)(obj + 100)) {
    //         sub_56BDE0(obj - 204, 0);
    //         memcpy(obj_alloc + 28, *(void**)(this + 5616) + 28, 72);
    //         F_3x3InertiaTensorTransform(obj_alloc);
    //         memcpy(obj_alloc + 124, *(void**)(this + 5616) + 124, 24);
    //         InertiaTensorWorldSpaceTransform(obj_alloc);
    //         PhysicsSubObjectFree(this);
    //       }
    //     return 1;
    //   }
    // UNRESOLVED: Six double globals (0x0059E430, 0x0059E880, 0x0059EB28, 0x0059EB50, 0x0059EC70, 0x0059EEF0) are flagged as read but appear nowhere as named symbols in the decompiled body; they are presumably consumed inside inlined arithmetic or one of the callees and their exact read site is unresolved.
    // UNRESOLVED: Field this+0x450 (1104) is flagged read but no visible access appears in the decompiled body.
    // UNRESOLVED: The wheel-weight array base at this+7856 is read but is not present in the packet field list.
}
