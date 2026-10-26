// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004144F0
// Canonical corpus name: DriverDataTableLookupAndTimeConversion
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DriverDataTableLookupAndTimeConversion_004144f0.c

void UnknownObject::DriverDataLookupAndTimeCalc()
{
    // Populates a driver-context/time struct from the arguments a2..a6 and two optional float overrides a7/a8. Stores a2..a6 at this[0], this[4], this[5], this[6], this[7]. Applies sentinel replacement: a6 == -1 pulls this[7] from dword_5BF9A0[5*a2]; a7 == -2.0 pulls from flt_5BF9A8[5*a2]; a8 == -2.0 pulls from flt_5BF9A4[5*a2]. Computes this[2] = CRTFtol((dbl_8AFEA8 + a7) * 5.0) * 0.2, then this[3] = -1.0 when a8 == -1.0, else this[3] = this[2] + a8 + 0.2. On-frame-path lookup utility called by a large set of AI/commentary/display callers.
    // ASSIGNMENT: Store the incoming context arguments: this[0] = a2, this[4] = a3, this[5] = a4, this[6] = a5, this[7] = a6. [field:this:0x00000000, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C]
    // GUARD: If a6 == -1, replace this[7] with dword_5BF9A0[5 * a2] (table default). [field:this:0x0000001C, global:0x005BF9A0]
    // GUARD: If a7 == -2.0, replace a7 with flt_5BF9A8[5 * a2]. [global:0x005BF9A8]
    // GUARD: If a8 == -2.0, replace a8 with flt_5BF9A4[5 * a2]. [global:0x005BF9A4]
    // CALCULATION: v9 = (double)CRTFtol((dbl_8AFEA8 + a7) * 5.0) * 0.2. [callee:0x00587BDC, global:0x008AFEA8]
    // ASSIGNMENT: this[2] = v9 (computed base time at offset +0x8). [field:this:0x00000008]
    // GUARD: If a8 == -1.0, this[3] = -1.0; otherwise this[3] = v9 + a8 + 0.2. [field:this:0x0000000C]

    // Conservative worker pseudocode:
    //   this[0] = a2; this[4] = a3; this[5] = a4; this[6] = a5; this[7] = a6;
    //   if (a6 == -1) this[7] = dword_5BF9A0[5 * a2];
    //   if (a7 == -2.0) a7 = flt_5BF9A8[5 * a2];
    //   if (a8 == -2.0) a8 = flt_5BF9A4[5 * a2];
    //   this[2] = (double)CRTFtol((dbl_8AFEA8 + a7) * 5.0) * 0.2;
    //   this[3] = (a8 == -1.0) ? -1.0 : this[2] + a8 + 0.2;
    // UNRESOLVED: Globals flt_59E670, flt_59E7E8, flt_59E7EC, flt_59E7F0 are listed as read by the packet but never referenced in the raw source; placement is unknown (likely used by the many callers or an inlined path).
    // UNRESOLVED: The precise meaning of the stored context fields (this[4..7]) and the driver ID semantics of a2 are not provable from this packet.
    // UNRESOLVED: CRTFtol is the CRT float-to-integer truncation helper; its FPU choreography is out of scope here.
}
