// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F2320
// Canonical corpus name: VehicleDynamicsStateReset
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleDynamicsStateReset_004f2320.c

void UnknownObject::VehicleDynamicsStateReset()
{
    // Vehicle dynamics state reset. Clears a run of nine adjacent DWORD state fields on 'this' (offsets 0x34EC..0x350C) to zero, then zeroes a four-entry per-wheel data array beginning at this[3436] (offset 0x35B0), advancing a 62-DWORD stride per entry. If the enable flag this[3247] (offset 0x32BC) is zero, it conditionally invokes the suspension physics state-zeroing routine on global dbl_7C7428 and returns that call's result; otherwise it returns the pointer this+3436. Per-frame reset called by AISteeringRacingLineCorrection (0x42B0E0) and VehicleYawRotationRecoveryController (0x4F1C40).
    // ASSIGNMENT: Zero the run of nine state fields this[3387]..this[3395] (offsets 0x34EC, 0x34F0, 0x34F4, 0x34F8, 0x34FC, 0x3500, 0x3504, 0x3508, 0x350C). [field:this:0x000034EC, field:this:0x000034F0, field:this:0x000034F4, field:this:0x000034F8, field:this:0x000034FC, field:this:0x00003500, field:this:0x00003504, field:this:0x00003508, field:this:0x0000350C, source:raw]
    // LOOP: Per-wheel data array clear: four iterations starting at this[3436] (offset 0x35B0), advancing the pointer by 62 DWORDs after each entry. [field:this:0x000035B0, source:raw]
    // ASSIGNMENT: Store zero into the current per-wheel entry on each iteration of the clear loop. [field:this:0x000035B0, source:raw]
    // GUARD: Reads enable flag this[3247] (offset 0x32BC); when it is zero the additional suspension reset path is taken, otherwise the loop result pointer is returned. [field:this:0x000032BC, source:raw]
    // CALL: Conditionally call the suspension physics state-zeroing routine (named PhysicsStateZeroingResetForSuspension in raw source, absent from packet callees) with a pointer to global dbl_7C7428. [global:0x007C7428, source:raw]
    // RETURN: Return the conditional call's result when the guard fired, otherwise return this+3436. [source:raw]
    // CALL: Invoked as a per-frame reset by AISteeringRacingLineCorrection (0042B0E0) and VehicleYawRotationRecoveryController (004F1C40). [caller:0x0042B0E0, caller:0x004F1C40]

    // Conservative worker pseudocode:
    //   this[3387..3395] = 0;
    //   p = &this[3436];
    //   for (i = 4; i != 0; --i) { *p = 0; p += 62; }
    //   if (this[3247] == 0) return PhysicsStateZeroingResetForSuspension(&dbl_7C7428);
    //   return this + 3436;
    // UNRESOLVED: The suspension reset callee named in raw source is not in the packet callees list; its identity and behavior are unverified.
    // UNRESOLVED: The per-wheel array entries use a 62-DWORD (0xF8-byte) stride; the sub-fields cleared beyond the first DWORD of each entry are not individually evidenced.
}
