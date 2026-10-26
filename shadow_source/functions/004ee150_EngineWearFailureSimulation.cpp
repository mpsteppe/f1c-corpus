// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004EE150
// Canonical corpus name: EngineWearFailureSimulation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/EngineWearFailureSimulation_004ee150.c

void UnknownObject::EngineWearFailureSimulation()
{
    // Initializes four consecutive float wear slots on 'this' (offsets 0x3D64, 0x3D68, 0x3D6C, 0x3D70) to the FLT_MAX bit pattern 2139095039. When dword_7CEA5C is in (0, 2] it re-computes the four slots each frame from a noise generator seeded on dword_8AAE70 combined with two double-scaled inputs read from a2+4912 and a2+4920, optionally dividing by flt_8ACF9C when dword_7C56A4 == 7 and dword_7CEA5C == 2, then clamping to FLT_MAX. Per-frame engine-wear computation invoked by SuspensionAndWheelPhysics (0x004E5F60).
    // ASSIGNMENT: Write 2139095039 (FLT_MAX bit pattern) into the four consecutive float fields at this+0x3D64, +0x3D68, +0x3D6C, +0x3D70, initializing the wear slots before any mode check. [field:this:0x00003D64, field:this:0x00003D68, field:this:0x00003D6C, field:this:0x00003D70, source:raw]
    // GUARD: Proceed with wear recomputation only when dword_7CEA5C > 0 and dword_7CEA5C <= 2; otherwise return dword_7CEA5C unchanged. [global:0x007CEA5C, source:raw]
    // CALL: Call EmptyStubWithFlagCheck(2, 0) at the start of the active wear mode. [callee:0x0053AC70, source:raw]
    // LOOP: Loop exactly 4 times, one pass per wear slot, advancing the write cursor through this+0x3D64..0x3D70. [field:this:0x00003D64, field:this:0x00003D68, field:this:0x00003D6C, field:this:0x00003D70, source:raw]
    // CALCULATION: Per iteration compute v6 = RandomNoiseValueGenerator(&dword_8AAE70) * (a2+4920 as double * 3.0) + (a2+4912 as double * 3.0). [callee:0x004B3CE0, global:0x008AAE70, source:raw]
    // GUARD: When dword_7C56A4 == 7 and dword_7CEA5C == 2, divide v6 by flt_8ACF9C. [global:0x007C56A4, global:0x007CEA5C, global:0x008ACF9C, source:raw]
    // ASSIGNMENT: Write v6 into the current wear slot when v6 <= 3.402823466385289e38, otherwise write 3.4028235e38 (FLT_MAX), clamping the stored float. [field:this:0x00003D64, field:this:0x00003D68, field:this:0x00003D6C, field:this:0x00003D70, source:raw]
    // CALL: Return EmptyStubWithFlagCheck(1, 0) at the end of the active wear mode. [callee:0x0053AC70, source:raw]
    // RETURN: When the mode guard fails, return dword_7CEA5C as the function result. [global:0x007CEA5C, source:raw]

    // Conservative worker pseudocode:
    //   this[0x3D64/4] = this[0x3D68/4] = this[0x3D6C/4] = this[0x3D70/4] = 2139095039;
    //   if (dword_7CEA5C > 0 && dword_7CEA5C <= 2) {
    //     EmptyStubWithFlagCheck(2, 0);
    //     for (i = 0; i < 4; i++) {
    //       wear = RandomNoiseValueGenerator(&dword_8AAE70) * (*(double*)(a2 + 4920) * 3.0) + (*(double*)(a2 + 4912) * 3.0);
    //       if (dword_7C56A4 == 7 && dword_7CEA5C == 2)
    //         wear /= flt_8ACF9C;
    //       this[0x3D64/4 + i] = (wear <= 3.402823466385289e38) ? wear : 3.4028235e38;
    //     }
    //     return EmptyStubWithFlagCheck(1, 0);
    //   }
    //   return dword_7CEA5C;
    // UNRESOLVED: The two double sources read from a2+4912 and a2+4920 (scaled by 3.0) are present in the raw source but have no packet field entries or evidence references, so their meaning is unknown.
    // UNRESOLVED: Globals dbl_59E7E0, dbl_5AD208 and dword_8B8F24 are listed as referenced but do not appear in the raw function body.
    // UNRESOLVED: The existing_analysis calls dword_7CEA5C the engine wear mode with stated value range 0/2/3, which conflicts with the raw source guard (0, 2]; raw source wins, exact mode semantics unverified.
}
