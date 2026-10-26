// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00556B10
// Canonical corpus name: sub_556B10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_556B10_00556b10.c

void UnknownObject::SceneNodeUpdateWithoutWorldTransform()
{
    // Updates a scene node's collision and visibility state without setting a full world transform: branches on a node flag bit at this+0x3C, performs transform/bone copies through the scene-manager vtable, runs collision contact detection and AABB visibility classification, then finalizes rendering/material state (mesh dirty flags) according to node state flag bits.
    // GUARD: Read the node flag byte at this+0x3C (this+60); if bit 0x10 is set take the transform path, otherwise take the simple path. [field:this:0x0000003C, source:raw]
    // CALL: Called by AnimationDispatchWithSkipFlag to update a scene node without a full world transform. [caller:0x00556980, function:0x00556B10, source:raw]
    // CALL: Transform path: if flag 0x20000000 is not yet set on node state a3+20, indirect-call the scene-manager vtable slot 1 behind dword_8B8F24 to copy a transform (source this+0x204 + 220, destination a3+232, matrix this+416), then set flag 0x20000000. [global:0x008B8F24, field:this:0x00000204, source:raw]
    // CALL: Transform path: run CollisionContactStateDetection on the node state with contact data at a3+232. [callee:0x0054D7A0, source:raw]
    // LOOP: Transform path: if state bit 4 is set and bit 8 is not set, set bit 8 and loop 8 times indirect-calling the scene-manager vtable slot 1 to copy eight bone transforms (stride 12 bytes) against the matrix at this+416. [global:0x008B8F24, source:raw]
    // CALL: Transform path: classify visibility via AABBFrustumVisibilityClassification using the AABB at a3+124. [callee:0x0054D910, source:raw]
    // CALL: Simple path: run CollisionContactStateDetection with contact data at a3+220; if state bit 4 is set, classify visibility with the AABB at a3+28. [callee:0x0054D7A0, callee:0x0054D910, source:raw]
    // GUARD: Read node state flags a3+20; if bit 5 (result & 5) is set, enter finalization: in the transform path, when bits 0x20 and 0x2000000 are clear, if the extra data at a3+284 has bit 0x100 set call sub_55ED10(this, a3, this+276), and if bit 0x100000 is set call sub_55D5C0(a2, 0) then return sub_556D60(a3, a2). [callee:0x0055ED10, callee:0x0055D5C0, callee:0x00556D60, source:raw]
    // LOOP: Simple path: if bit 0x10000000 is set, loop over the count at a3+280, setting bit 0x400 on each entry (stride 64 bytes) starting at a3+284+56 and calling sub_55D720(a2, 1) per entry; clear bit 0x10000000; then return sub_556D60(a3, a2). [callee:0x0055D720, callee:0x00556D60, source:raw]
    // RETURN: Return the node state flags read from a3+20 when the bit-5 branch is not taken. [source:raw]
    // UNRESOLVED: dword_8B8F28 is listed in packet globals but is not referenced in the raw source; its role is unknown.
    // UNRESOLVED: The a3 node state structure (flags at +20, contact data, AABBs, count at +280, entry list at +284) is not a packet-listed field set; all a3 offsets are inferred from usage.
    // UNRESOLVED: Exact meaning of the state flag bits 0x20000000, 0x4, 0x8, 0x20, 0x2000000, 0x100, 0x100000, 0x10000000 and 0x400 is inferred from branch context only.
    // UNRESOLVED: The scene-manager vtable slot 1 indirect call's exact operation (transform/matrix copy) is inferred from argument positions.
}
