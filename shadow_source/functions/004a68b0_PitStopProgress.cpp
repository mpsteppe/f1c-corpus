// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A68B0
// Canonical corpus name: PitStopProgress
// Owner: F1CPitMachine [CONFIRMED]
// Raw source: functions/PitStopProgress_004a68b0.c

void F1CPitMachine::PitStopProgress()
{
    // Per-frame pit stop progress tick on the pit machine: while session_time is below the pit completion threshold (this+0x1A4), applies timed wheel-force ramps for repair phases and ramps the pit speed limiter; once the threshold is passed, deactivates the speed limiter, clears the AI reason code, notifies the pit state machine of exit, computes pit-stop elapsed time, dispatches post-pit cleanup and AI commands for the player vehicle, resets wheel forces and camera mode, and triggers pit-crew element actions plus audio.
    // GUARD: Session time below the pit completion threshold (this+0x1A4) selects the active servicing path; the else branch runs the pit-exit sequence. [field:this:0x000001A4, source:raw]
    // GUARD: Pit-mid flag (this+0x1AC) is set and session time is inside the last 2.0 seconds before completion (this+0x1A4 - 2.0 <= session_time). [field:this:0x000001AC, field:this:0x000001A4, source:raw]
    // ASSIGNMENT: Clear the pit-mid flag at this+0x1AC to 0 once the mid-pit event fires. [field:this:0x000001AC]
    // CALL: Run a short computation (ShortComputation_d410) on the session manager dword_5EA510. [callee:0x0040D410, global:0x005EA510]
    // GUARD: Speed limiter engaged (this+0x1C0 non-zero) and session time beyond the phase-one timestamp this+0x1B4. [field:this:0x000001C0, field:this:0x000001B4]
    // CALCULATION: Compute limiter speed as (session_time - this+0x1B4) * 12.0 + this+0x1B0, clamped to the ceiling this+0x1B8. [field:this:0x000001B0, field:this:0x000001B4, field:this:0x000001B8]
    // CALL: Apply the computed limiter speed via SpeedValueSetterWithGlobalMirror. [callee:0x004F1890]
    // GUARD: Wheel-force parameter block present (this+0x1C4 non-zero) gates the repair force ramps. [field:this:0x000001C4]
    // GUARD: Session time within the wheel-force window (session_time <= this+0x1D4). [field:this:0x000001D4]
    // CALCULATION: Ramp front and rear wheel-force parameters from window base this+0x1D0 with 0.16 slope within 0.2/1.4 second sub-windows and 0.096000001 caps. [field:this:0x000001D0, source:raw]
    // CALL: Apply wheel-force parameters (front, front, rear, rear) via WheelForceParameterSet. [callee:0x004F1BA0]
    // CALL: When session time exceeds the window end this+0x1D4, zero all wheel-force parameters. [callee:0x004F1BA0, field:this:0x000001D4]
    // GUARD: Else branch: speed limiter engaged (this+0x1C0 non-zero) triggers limiter deactivation. [field:this:0x000001C0]
    // CALL: Write final limiter speed this+0x1B8 through SpeedValueSetterWithGlobalMirror. [callee:0x004F1890, field:this:0x000001B8]
    // GUARD: AI enable flag (obj+0x32C8) set, limiter speed positive, and AI reason code obj+0x4068 equal to 9, so the stale reason code must be cleared. [field:obj:0x000032C8, field:obj:0x00004068, guard:0, guard:2]
    // ASSIGNMENT: Clear the AI reason code obj+0x4068 to 0 when the limiter deactivates with the code still at 9. [field:obj:0x00004068]
    // STATE_TRANSITION: Notify the pit state machine of state 4 via StateChangeNotify to leave the pit stop. [callee:0x004A5C80]
    // CALCULATION: Compute pit stop elapsed (this+0x1A8) as current reference time dbl_8AFEA0 minus pit entry time this+0x1A0. [field:this:0x000001A8, field:this:0x000001A0, global:0x008AFEA0]
    // GUARD: Current player vehicle (dword_7C54F0 indexed by dword_7C54DC, +18580) matches this vehicle index this+0x4 and finish state obj+0x4064 is not 1, allowing pit-exit audio. [global:0x007C54F0, global:0x007C54DC, field:this:0x00000004, field:obj:0x00004064, guard:1]
    // CALL: Dispatch pit-exit audio event sub_4D8760(6, 0). [callee:0x004D8760]
    // GUARD: AI enable flag obj+0x32C8 set to 1 gates post-pit AI cleanup. [field:obj:0x000032C8, guard:0]
    // CALL: Run PostPitCleanup on the base vehicle (this+0x0 deref). [callee:0x0042A6F0, field:this:0x00000000]
    // CALL: Dispatch AI command message 15 with argument 0 via AICommandMessageQueueDispatcher on the base vehicle. [callee:0x00424CD0, field:this:0x00000000]
    // CALL: Zero all wheel-force parameters via WheelForceParameterSet after pit exit. [callee:0x004F1BA0]
    // CALL: Reset the camera mode to 0 via CameraModeSetter on pit exit. [callee:0x004F1B50]
    // GUARD: Pit crew object present at this+0x8 gates per-element action dispatch. [field:this:0x00000008]
    // CALL: Dispatch conditional action 0 to the pit crew object via PerElementConditionalActionDispatcher. [callee:0x004A34A0, field:this:0x00000008]
    // GUARD: Global counter dword_7CF884 positive and vehicle pit-crew-mesh flag obj+0x105C not already 1, so the mesh load should be triggered. [global:0x007CF884, field:obj:0x0000105C]
    // ASSIGNMENT: Set the pit-crew-mesh flag obj+0x105C to 1 to trigger crew mesh loading. [field:obj:0x0000105C]
    // UNKNOWN: Vehicle detail-level value obj+0x1054 read as a sound-effect dispatch parameter; the audio routine invoked is absent from the packet callee evidence. [field:obj:0x00001054]
    // RETURN: Return the accumulated status byte. [function:0x004A68B0, source:raw]
    // UNRESOLVED: Audio dispatch routine seen in raw source (obj+0x1054 -> sound controller) has no callee entry in packet evidence.
    // UNRESOLVED: Globals 0x0059E440, 0x0059E7E8, 0x0059E800, 0x0059E8CC, 0x0059E96C, 0x005ACB60, 0x005ACB64, 0x008AD298 are packet evidence but do not appear in the rendered raw source.
    // UNRESOLVED: Return byte semantics (status vs error flag) not resolved.
}
