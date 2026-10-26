// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042E1F0
// Canonical corpus name: CRTMathHelper_e1f0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CRTMathHelper_e1f0_0042e1f0.c

void UnknownObject::scaledValueIndexParser()
{
    // Parses configuration tokens into a scaled pair of doubles and a clamped index. When trigger a3 is non-zero, extracts a value triplet, scales this+0x0 and this+0x8 by factor a5, stores an int truncation at this+0x10, then parses a final index at this+0x14 clamped to [0, this+0x10-1]. Shared setup-value helper used by per-wheel, fender, engine-map and vehicle-file sections.
    // GUARD: If a3 is non-zero, the token-triplet parse/scale path executes. [source:raw]
    // CALL: Parse token triplet: sub_565AA0(a3, this, this+8, &v12, 0) extracts two double values and a temporary int. [callee:0x00565AA0, field:this:0x00000000, field:this:0x00000008]
    // CALL: Convert the parsed temporary double v12 to int via CRTFtol (float-to-int truncation). [callee:0x00587BDC]
    // CALCULATION: Scale first double at this+0x0 by a5 and store back; store converted int at this+0x10; scale second double at this+0x8 by a5. [field:this:0x00000000, field:this:0x00000008, field:this:0x00000010]
    // CALL: Parse final index token: sub_565760(a4, this+0x14, 0, 0, 0) writes an int into this+0x14. [callee:0x00565760, field:this:0x00000014]
    // GUARD: When parsed count v11 at this+0x10 > 0 and index at this+0x14 >= 0, clamp index into [0, v11-1]; otherwise force index to 0. [guard:0, field:this:0x00000010, field:this:0x00000014]
    // ASSIGNMENT: Write clamped or zeroed index back to this+0x14. [field:this:0x00000014]
    // RETURN: Return the final clamped index value. [function:0x0042E1F0]
    // UNKNOWN: Caller context: setup-value parser shared by PerWheelBrakeSuspensionDataLoader, FenderAeroSetupSectionReader, EngineMapSetupFieldDefinitions and TheSvmHdvVehicleFileParser. [caller:0x004F2C60, caller:0x004F3090, caller:0x004F3C10, caller:0x004F4270]

    // Conservative worker pseudocode:
    //   if (a3) {
    //     if (parseTriplet(a3, this, this+8, &v12, 0)) {
    //       this->intAt0x10 = CRTFtol(v12);
    //       this->doubleAt0x0 *= a5;
    //       this->doubleAt0x8 *= a5;
    //     }
    //   }
    //   result = parseIndex(a4, this+0x14, 0, 0, 0);
    //   if (result) {
    //     count = this->intAt0x10;
    //     if (count <= 0) this->intAt0x14 = 0;
    //     else if (this->intAt0x14 < 0) this->intAt0x14 = 0;
    //     else if (this->intAt0x14 >= count) this->intAt0x14 = count - 1;
    //   }
    //   return this->intAt0x14;
    // UNRESOLVED: Exact semantics of the a3/a4 token arguments and of the a5 scale factor.
    // UNRESOLVED: Object identity and layout beyond the four listed fields.
}
