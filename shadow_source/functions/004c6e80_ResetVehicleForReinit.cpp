// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C6E80
// Canonical corpus name: sub_4C6E80
// Owner: VehicleObject [DERIVED]
// Raw source: functions/sub_4C6E80_004c6e80.c

void VehicleObject::ResetVehicleForReinit()
{
    // Resets a vehicle struct for reinitialisation: dispatches a global instance call, clears physics/AI sub-structures (via sub_4E4790, VehicleResetClear, UIComponentCleanup, DoubleBufferFree, StructResetReinitializer), reassigns each AI driver in the live vehicle array to a random driver, sets the two slot fields at +0x48A4/+0x48A8 to -1 (invalid), clears driver info, and returns the result of a final reset call on the force-feedback base (dword_8ACEE0).
    // CALL: Dispatch a call on the global instance dword_5EA560 with this+3 via FunctionCallWrapper_0b40. [callee:0x00410B40, global:0x005EA560, source:raw]
    // CALL: Reset the this+3 sub-struct via sub_4E4790. [callee:0x004E4790, source:raw]
    // CALL: Reset vehicle physics/simulation state at this+444 via VehicleResetClear. [callee:0x004E09E0, source:raw]
    // CALL: Clean up the UI/HUD component sub-struct at this+3251 via UIComponentCleanup. [callee:0x004A4DB0, source:raw]
    // CALL: Free the double-buffer sub-struct at this+5 via DoubleBufferFree. [callee:0x004F83B0, source:raw]
    // CALL: Reinitialize the sub-struct at this+4109 to defaults via StructResetReinitializer. [callee:0x004BB950, source:raw]
    // LOOP: For i in 0 .. dword_5C329C: reassign the AI driver for vehicle dword_7C54F0[i] to a random driver via AIDriverRandomSelector(dword_7C54F0[i], this). [global:0x005C329C, global:0x007C54F0, callee:0x0042AE20, source:raw]
    // ASSIGNMENT: Set this[4649] (+0x48A4) and this[4650] (+0x48A8) to -1 (18446744073709551615, invalid/uninitialised slot marker). [field:this:0x000048A4, field:this:0x000048A8, source:raw]
    // CALL: Clear the vehicle driver-info substructure via VehicleDriverInfoClear(this). [callee:0x004C79E0, source:raw]
    // RETURN: Return the result of a final reinitialization/reset call on the force-feedback base (dword_8ACEE0). Invoked from DynMan_Post, NetCommPlayerSlotSync and ProcessDriverEntries. [global:0x008ACEE0, caller:0x0042C9F0, caller:0x0045FC50, caller:0x004B8DA0, function:0x004C6E80, source:raw]

    // Conservative worker pseudocode:
    //   FunctionCallWrapper_0b40(dword_5EA560, this + 3);
    //   sub_4E4790(this + 3);
    //   VehicleResetClear(this + 444);
    //   UIComponentCleanup(this + 3251);
    //   DoubleBufferFree(this + 5);
    //   StructResetReinitializer(this + 4109);
    //   for (i = 0; i < dword_5C329C; i++) AIDriverRandomSelector(dword_7C54F0[i], this);
    //   this[4649] = -1; this[4650] = -1;
    //   VehicleDriverInfoClear(this);
    //   return reset_ffb(dword_8ACEE0);
    // UNRESOLVED: The final call on dword_8ACEE0 targets an address (sub_4D1670) not present in the packet's callee list, so it is described without naming the call target to avoid introducing an absent address.
    // UNRESOLVED: The +0x48A4/+0x48A8 markers and the -1 sentinel semantics (invalid/uninitialised) are DERIVED from the unconditional reset context; the field names are not confirmed by the packet.
}
