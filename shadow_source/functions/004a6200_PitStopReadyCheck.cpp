// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A6200
// Canonical corpus name: PitStopReadyCheck
// Owner: F1CPitMachine [CONFIRMED]
// Raw source: functions/PitStopReadyCheck_004a6200.c

void F1CPitMachine::PitStopReadyCheck()
{
    // Pit stop readiness evaluation for the pit machine: defaults the ready flag this+0x190 to 1, clears it if the squared wheel-spin magnitude from obj+0x34F8/0x34FC/0x3500 exceeds a small threshold, forces camera mode 1, and in pit-stop mode recomputes readiness from the tire-compound decision (or forces not-ready when dword_7CE048 is set); when ready, records the pit timer (this+0x1A0 and completion this+0x1A4), runs a 3D transform on the secondary object, and for the player vehicle arms the pit-mid flag this+0x1AC and triggers a short computation on the session manager with a side-dependent argument.
    // ASSIGNMENT: Default the pit-ready flag this+0x190 to 1. [field:this:0x00000190]
    // CALCULATION: Square magnitude of wheel spin from obj+0x34F8, obj+0x34FC and obj+0x3500; if greater than 0.040000003 the vehicle is moving too fast for a pit stop. [field:obj:0x000034F8, field:obj:0x000034FC, field:obj:0x00003500]
    // ASSIGNMENT: Clear the pit-ready flag this+0x190 to 0 when the vehicle is moving too fast. [field:this:0x00000190]
    // CALL: Force the camera mode to 1 via CameraModeSetter. [callee:0x004F1B50]
    // GUARD: Pit stop mode active: the pit state flag obj+0x32C8 on the base vehicle equals 1. [field:obj:0x000032C8, guard:0]
    // CALL: Update the race-start countdown state via RaceStartCountdownStateUpdate(0). [callee:0x004EF930]
    // ASSIGNMENT: Recompute the pit-ready flag from the tire-compound decision PitStopDecisionTireCompound(base vehicle). [callee:0x0042A3D0, field:this:0x00000190, field:this:0x00000000]
    // GUARD: Alternative readiness override: global dword_7CE048 equals 1 forces not-ready. [global:0x007CE048]
    // ASSIGNMENT: Clear the pit-ready flag this+0x190 to 0 when dword_7CE048 is set. [field:this:0x00000190]
    // GUARD: Ready check: pit-ready flag this+0x190 set gates pit timer arming and player-vehicle pit-mid handling. [field:this:0x00000190]
    // ASSIGNMENT: Store the session-time argument into the pit timer target this+0x1A0. [field:this:0x000001A0]
    // CALL: Query the pit operation duration via PitStopOperationTimer(this). [callee:0x004A6340, field:this:0x00000000]
    // CALCULATION: Set the pit timer completion this+0x1A4 to the operation timer result plus the stored target this+0x1A0. [field:this:0x000001A4, field:this:0x000001A0]
    // GUARD: Secondary object present at this+0x8 gates the 3D transform dispatch. [field:this:0x00000008]
    // CALL: Build a 3D transform via F_3DTransformWithMatrixMultiplication and dispatch sub_4A3320 on the secondary object with the result. [callee:0x004EFB20, callee:0x004A3320, field:this:0x00000008]
    // GUARD: Player vehicle check: base vehicle equals the player pointer dword_7C54E8, pit-mid flag this+0x1AC clear, and global dword_7CE814 clear. [field:this:0x00000000, field:this:0x000001AC, global:0x007C54E8, global:0x007CE814]
    // ASSIGNMENT: Arm the pit-mid flag this+0x1AC to 1 for the player's pit entry. [field:this:0x000001AC]
    // CALL: Run a short computation on the session manager dword_5EA510 via ShortComputation_d3c0, argument 9 normally or 10 when the side flag byte_5EA3EC is set. [callee:0x0040D3C0, global:0x005EA510, global:0x005EA3EC]
    // RETURN: Void return. [function:0x004A6200, source:raw]
    // UNRESOLVED: Global 0x005ACB50 is packet evidence but does not appear in the rendered raw source.
    // UNRESOLVED: Threshold literal 0.040000003 purpose (pit-entry speed gate) inferred from surrounding float math; no explicit semantic evidence in packet.
}
