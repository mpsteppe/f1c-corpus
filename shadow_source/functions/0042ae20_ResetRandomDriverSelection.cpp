// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042AE20
// Canonical corpus name: AIDriverRandomSelector
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AIDriverRandomSelector_0042ae20.c

void UnknownObject::ResetRandomDriverSelection()
{
    // Conditionally resets AI driver random-selection targets. If the incoming index matches the stored primary target at this+0x45FC, the target is cleared, lateral force/torque is recalculated with index 100, and this+0x4420 is zeroed. If the incoming index matches the secondary target at this+0x45F8, that target is cleared. Matches nothing otherwise.
    // GUARD: Compare a2 against stored primary random target at this+0x45FC [field:this:0x000045FC]
    // ASSIGNMENT: Clear primary random target: *(this+0x45FC) = 0 [field:this:0x000045FC]
    // CALL: Recalculate lateral force and torque: LateralForceTorqueCalculation(this, 100) [callee:0x0042AD00]
    // ASSIGNMENT: Zero lateral force/torque control field: *(this+0x4420) = 0 [field:this:0x00004420]
    // GUARD: Compare a2 against stored secondary random target at this+0x45F8 [field:this:0x000045F8]
    // ASSIGNMENT: Clear secondary random target: *(this+0x45F8) = 0 [field:this:0x000045F8]

    // Conservative worker pseudocode:
    //   if (a2 == this->randomTargetPrimary) {
    //       this->randomTargetPrimary = 0;
    //       LateralForceTorqueCalculation(this, 100);
    //       this->lateralForceTorqueControl = 0;
    //   }
    //   if (a2 == this->randomTargetSecondary) {
    //       this->randomTargetSecondary = 0;
    //   }
    // UNRESOLVED: Meaning of the constant 100 passed to LateralForceTorqueCalculation
    // UNRESOLVED: Semantic role of the cleared this+0x4420 field beyond being a reset target
}
