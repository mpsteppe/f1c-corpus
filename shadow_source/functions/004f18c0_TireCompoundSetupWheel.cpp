// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F18C0
// Canonical corpus name: sub_4F18C0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4F18C0_004f18c0.c

void UnknownObject::TireCompoundSetupWheel()
{
    // Sets up tire compound parameters for one wheel index. Looks up the compound entry by index through CompoundIndexLookup, resolves its name (defaulting to byte_5EA438 when empty) to a numeric ID via TireCompoundNameIDMapping and pushes it to MultiplayerSessionType, selects compound data (front wheels use a different data stride), then computes per-wheel force, spring, load and grip values into the wheel physics slot at this+13840..this+13880, optionally runs TireBrushModelForceSolver, and when no rigid body is attached records the compound index globally and applies it through TireCompoundPerWheelPhysicsApplication.
    // ASSIGNMENT: Store the compound index a3 at this+14704 (field 0x3970) and load the compound table pointer from this+14700 (field 0x396C). [field:this:0x00003970, field:this:0x0000396C, source:raw]
    // CALL: Resolve the compound entry pointer via CompoundIndexLookup(compoundTable, a3). [callee:0x004D7570, source:raw]
    // ASSIGNMENT: Take the compound name from the entry; when the name pointer is null use the default byte_5EA438. [global:0x005EA438, source:raw]
    // CALL: Convert the name to a numeric compound ID via TireCompoundNameIDMapping and record it through MultiplayerSessionType at this+1764. [callee:0x004A4830, callee:0x004E2370, source:raw]
    // ASSIGNMENT: Select the compound data pointer: entry + 88 doubles for normal wheels, entry + 6 doubles for wheel index <= 1. [source:raw]
    // CALCULATION: Evaluate VehicleSuspensionForceHelper(data, 190.0); when the result is <= 0.0 store 0 in the wheel slot at this+13880 (plus 248 * a2), otherwise store data[22] / result. [callee:0x004D6AE0, source:raw]
    // CALCULATION: Compute the per-wheel physics values at this+13840..this+13880 (plus 248 * a2): pressure-scaled term at 13840, combined load term at 13856, half-load torque at 13860, the constant 1065353216 at 13872, the load-scaled value at 13852 as the value at 13856 times this+15348 (field 0x3BF4), and the grip constant at 13876. [field:this:0x00003BF4, source:raw]
    // GUARD: If data[33] is <= 0.0 store the constant 1099694080 at 13844 (plus 248 * a2), otherwise store 1.0 / data[33]. [source:raw]
    // CALL: Compute the remaining slot value at 13864 (plus 248 * a2) via DivisionWithThreshold from data[30] and data[31]. [callee:0x004D5EA0, source:raw]
    // GUARD: When the solve flag a4 is set, run TireBrushModelForceSolver(this, 0). [callee:0x004E8010, source:raw]
    // GUARD: When this+12988 (field 0x32BC, the rigid-body constraint guard) is zero, write a3 to global dword_7C8884 and apply the compound to the wheel through TireCompoundPerWheelPhysicsApplication(&dbl_7C7428, a2). [field:this:0x000032BC, global:0x007C8884, global:0x007C7428, callee:0x0043DA10, source:raw]

    // Conservative worker pseudocode:
    //   void TireCompoundSetupWheel(int this, unsigned int wheel, int compound, char solve) {
    //       *(int*)(this+14704) = compound;
    //       char **entry = (char**)CompoundIndexLookup(*(int**)(this+14700), compound);
    //       char *name = entry[0] ? entry[0] : (char*)byte_5EA438;
    //       MultiplayerSessionType((char*)(this+1764), TireCompoundNameIDMapping(name));
    //       double *data = (double*)((wheel <= 1) ? (entry + 6) : (entry + 88));
    //       double f = VehicleSuspensionForceHelper(data, 190.0);
    //       int slot = 248 * wheel + this;
    //       if (f <= 0.0) *(int*)(slot+13880) = 0;
    //       else *(float*)(slot+13880) = data[22] / f;
    //       *(float*)(slot+13840) = (50.0 / data[4] * data[5] + data[4]) * 0.9800000190734863;
    //       double half = data[32] * 0.5;
    //       *(float*)(slot+13856) = (data[1] + data[0]) * half;
    //       *(int*)(slot+13872) = 1065353216;
    //       *(float*)(slot+13860) = half * (data[3] + data[2]);
    //       *(float*)(slot+13852) = *(float*)(slot+13856) * *(float*)(this+15348);
    //       *(float*)(slot+13876) = data[34];
    //       if (data[33] <= 0.0) *(int*)(slot+13844) = 1099694080;
    //       else *(float*)(slot+13844) = 1.0 / data[33];
    //       DivisionWithThreshold((float*)(slot+13864), data[30], data[31]);
    //       if (solve) TireBrushModelForceSolver(this, 0);
    //       if (!*(int*)(this+12988)) {
    //           dword_7C8884 = compound;
    //           TireCompoundPerWheelPhysicsApplication(&dbl_7C7428, wheel);
    //       }
    //   }
    // UNRESOLVED: Read-only globals dbl_59E420, dbl_59E430, flt_59E450, dbl_59ECD8 and dbl_5AD250 are listed in the packet but absent from the raw source text; their role is unplaced.
    // UNRESOLVED: The 248-byte stride layout of the per-wheel tire slot (offsets this+13840..this+13880) is not documented beyond this function.
    // UNRESOLVED: Compound data element meaning (indices 0..34) is inferred from the consuming formulas only; no external compound-file contract is available here.
}
