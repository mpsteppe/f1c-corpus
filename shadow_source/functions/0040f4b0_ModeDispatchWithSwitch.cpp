// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040F4B0
// Canonical corpus name: ModeDispatchWithSwitch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ModeDispatchWithSwitch_0040f4b0.c

void UnknownObject::ModeDispatchWithSwitch()
{
    // Collision-processing mode dispatcher. Reads a mode selector at this+0x1C and switches on it: modes 0-5 run a guarded computation on this and then compute a collision contact impulse from a2 and a3; mode 6 accumulates vehicle contact force from a2 with the constant 1; any other value returns the mode unchanged. Dispatches through a jump table global. Called per frame by ParticleEffectUpdateDispatch.
    // ASSIGNMENT: Read the mode selector into result from this+0x1C (this[7]). [field:this:0x0000001C, source:raw]
    // GUARD: Switch on the mode value, dispatching through the jump table global at 0x0040F52C. Modes 0-5 take the collision-impulse path, mode 6 the vehicle-contact path, and the default path returns immediately. [global:0x0040F52C, source:raw]
    // CALL: For modes 0-5, run the guarded computation ShortComputation_f0d0 on this. [callee:0x0040F0D0]
    // CALL: For modes 0-5, compute the collision contact impulse from a2 and a3 and store its result. [callee:0x004599C0]
    // CALL: For mode 6, accumulate vehicle contact force from a2 with the constant argument 1 and store its result. [callee:0x004EBC60]
    // RETURN: Return the computed result; the default case returns the unmodified mode value. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_40F4B0(this, a2, a3) {
    //     result = this[7];  // mode at +0x1C
    //     switch (result) {
    //       case 0..5: ShortComputation_f0d0(this); result = CollisionContactImpulse(a2, a3); break;
    //       case 6:    result = VehicleContactForceAccumulation(a2, 1); break;
    //       default:   return result;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Semantic meaning of the mode values 0-6 is not established by this packet.
    // UNRESOLVED: Role of arguments a2 (likely contact/impulse descriptor) and a3 is caller-defined.
    // UNRESOLVED: Meaning of the mode selector field at this+0x1C beyond acting as a dispatch key.
}
