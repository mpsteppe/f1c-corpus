// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E9CA0
// Canonical corpus name: AIRacingLinePathFollowing
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AIRacingLinePathFollowing_004e9ca0.c

void UnknownObject::AIRacingLinePathFollowing()
{
    // AI racing-line path traversal for a vehicle: after an AI-context validity check, performs 3D transform and render-guarded lookups to resolve the current and target racing-line nodes, walks the doubly-linked node chain to the node matching the target id in obj+0x4040, copies node position and orientation into the vehicle state (this+0x34D4/0x34E0 blocks), runs suspension, wheel-contact and matrix update steps each iteration (flagging obj+0x4094), toggles scene-node visibility for up to three track-follow display nodes, and clears render buffers around the traversal.
    // GUARD: AI context validity check: sub_4BC340 on the object pointed to by base field this+0x0 (+0x4034) gates the whole traversal. [callee:0x004BC340, field:this:0x00000000]
    // CALL: Build a 3D transform via F_3DTransformWithMatrixMultiplication into scratch transform v31. [callee:0x004EFB20]
    // CALL: Render-guarded transform call RenderCallWithGuard on the base object (this+0x0 deref). [callee:0x004D1140, field:this:0x00000000]
    // CALCULATION: Traversal iteration budget set to 2 * dword_5EA3F0. [global:0x005EA3F0]
    // CALL: Look up the path node for the current position block starting at this+0x34D4 via sub_403640(dword_5EA2C0, ..., 0) and cache the result at this+0x3A9C. [callee:0x00403640, global:0x005EA2C0, field:this:0x000034D4, field:this:0x00003A9C]
    // LOOP: Walk the +67 (offset 268) sibling chain from the cached node until a node whose +17 field matches the target node id at obj+0x4040, bounded by the iteration budget. [field:obj:0x00004040, global:0x005EA3F0, source:raw]
    // CALL: Render-guarded call RenderCallWithGuard on the base object with the current transform scratch. [callee:0x004D1140, field:this:0x00000000]
    // CALL: Transform the node position with offset via CoordinateTransformWithOffset into scratch v28. [callee:0x004EF6C0]
    // CALL: Look up the path node for the transformed target position via sub_403640(dword_5EA2C0, ...). [callee:0x00403640, global:0x005EA2C0]
    // LOOP: Advance along the +67 sibling chain from the target node until the orientation test flags clear, bounded by the iteration budget. [global:0x005EA3F0, source:raw]
    // GUARD: Path traversal mode byte this+0x3440 non-zero enables forward interleaving between current and target nodes. [field:this:0x00003440]
    // LOOP: Iterate between the current and target nodes following the +68 (offset 272) next-node chain while node branch entries are set, bounded by the budget. [source:raw]
    // ASSIGNMENT: Copy the transform orientation into this+0x34E0, this+0x34E4 and this+0x34E8. [field:this:0x000034E0, field:this:0x000034E4, field:this:0x000034E8]
    // CALL: Convert the Euler orientation at this+0x34E0 into a rotation matrix via EulerToRotationMatrix. [callee:0x00566E40, field:this:0x000034E0]
    // ASSIGNMENT: Copy the current node position into this+0x34D4, this+0x34D8 and this+0x34DC. [field:this:0x000034D4, field:this:0x000034D8, field:this:0x000034DC]
    // CALL: Update suspension state for the vehicle via SuspensionStateUpdate(this). [callee:0x004E9600, field:this:0x00000000]
    // ASSIGNMENT: Set the per-iteration step flag obj+0x4094 to 1 on the base object. [field:obj:0x00004094]
    // CALL: Compute body-to-wheel contact distances via VehicleBodyToWheelContactDistanceComputation(this, 0). [callee:0x004E9A40, field:this:0x00000000]
    // CALL: Apply the 3x3 matrix transform with translation via F_3x3MatrixTransformWithTranslation(this). [callee:0x004E9BD0, field:this:0x00000000]
    // CALL: Clear the render buffer (flag 0x8000000) via BufferEntryClear before scene-node toggling. [callee:0x0054FAE0]
    // GUARD: Scene-node pointer dword_8AD07C non-zero selects the first track-follow display node. [global:0x008AD07C]
    // CALL: Toggle scene-node visibility on, focus the node via UIFocusChange(dword_8AD07C, 1), then toggle visibility off. [callee:0x0054FB40, callee:0x0054F7A0, global:0x008AD07C]
    // GUARD: Scene-node pointer dword_8AD080 non-zero selects the second track-follow display node. [global:0x008AD080]
    // CALL: Toggle scene-node visibility on, focus the node via UIFocusChange(dword_8AD080, 1), then toggle visibility off. [callee:0x0054FB40, callee:0x0054F7A0, global:0x008AD080]
    // GUARD: Scene-node pointer dword_8AD084 non-zero selects the third track-follow display node. [global:0x008AD084]
    // CALL: Toggle scene-node visibility on, focus the node via UIFocusChange(dword_8AD084, 1), then toggle visibility off. [callee:0x0054FB40, callee:0x0054F7A0, global:0x008AD084]
    // LOOP: Traversal phase loop: advance the node (via +69 child chain when valid, else +68 next chain) until the target node or the iteration budget is reached; the first phase ends when current equals target. [global:0x005EA3F0, source:raw]
    // CALL: Clear the render buffer (flag 0x8000000) via BufferEntryClear on the early or final exit. [callee:0x0054FAE0]
    // RETURN: Void return once traversal completes or the budget is exceeded. [function:0x004E9CA0, source:raw]
    // UNRESOLVED: Owner object unknown; vehicle state this+0x34D4 block is written from node data but owning class not identified.
    // UNRESOLVED: Globals 0x0059E440, 0x0059E7F8 and 0x008ACEE0 are packet evidence but do not appear in the rendered raw source.
    // UNRESOLVED: Scratch addresses this+0x4034 and this+0x34B0 used in raw source have no packet field entries.
}
