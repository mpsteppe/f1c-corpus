// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005472D0
// Canonical corpus name: FloatToIntSwitch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatToIntSwitch_005472d0.c

void UnknownObject::FloatToIntSwitch()
{
    // Channel-indexed float-to-int conversion. Dispatches on a2 via a jump table (jpt_5472DB): for channel values 1-4, and only when the output pointer a3 is non-null, it multiplies the selected float field of this by the 255.0 scale constant (dbl_5ADB58) and writes the CRTFtol result to *a3. Channel 1 reads this+0x60, channel 2 reads this+0x50, channel 3 reads this+0x70, channel 4 reads this+0x80. Any other a2 returns a2-1 immediately without touching a3.
    // CALCULATION: Initialize the default result as a2 - 1. [source:raw]
    // GUARD: Dispatch on a2 through the switch jump table jpt_5472DB; only cases 1-4 have conversion bodies, everything else falls to the default return. [global:0x00547358, source:raw]
    // GUARD: Case 1: guard on the output pointer a3 being non-null before converting or writing. [source:raw]
    // CALL: Case 1: result = CRTFtol(this[24] * 255.0), converting the float at this+0x60 to an integer; the 255.0 scale factor is the double constant dbl_5ADB58. [field:this:0x00000060, callee:0x00587BDC, global:0x005ADB58, source:raw]
    // ASSIGNMENT: Case 1: write the converted value into the output: *a3 = result. [field:this:0x00000060, source:raw]
    // GUARD: Case 2: guard on the output pointer a3 being non-null before converting or writing. [source:raw]
    // CALL: Case 2: result = CRTFtol(this[20] * 255.0), converting the float at this+0x50 to an integer. [field:this:0x00000050, callee:0x00587BDC, global:0x005ADB58, source:raw]
    // ASSIGNMENT: Case 2: write the converted value into the output: *a3 = result. [field:this:0x00000050, source:raw]
    // GUARD: Case 3: guard on the output pointer a3 being non-null before converting or writing. [source:raw]
    // CALL: Case 3: result = CRTFtol(this[28] * 255.0), converting the float at this+0x70 to an integer. [field:this:0x00000070, callee:0x00587BDC, global:0x005ADB58, source:raw]
    // ASSIGNMENT: Case 3: write the converted value into the output: *a3 = result. [field:this:0x00000070, source:raw]
    // GUARD: Case 4: guard on the output pointer a3 being non-null before converting or writing. [source:raw]
    // CALL: Case 4: result = CRTFtol(this[32] * 255.0), converting the float at this+0x80 to an integer. [field:this:0x00000080, callee:0x00587BDC, global:0x005ADB58, source:raw]
    // ASSIGNMENT: Case 4: write the converted value into the output: *a3 = result. [field:this:0x00000080, source:raw]
    // RETURN: Return the converted result after a matched case, or a2 - 1 from the default case. [source:raw]

    // Conservative worker pseudocode:
    //   int FloatToIntSwitch(float* this, int channel, int* out) {
    //     switch (channel) {
    //       case 1: if (out) *out = CRTFtol(this[24] * 255.0); break;
    //       case 2: if (out) *out = CRTFtol(this[20] * 255.0); break;
    //       case 3: if (out) *out = CRTFtol(this[28] * 255.0); break;
    //       case 4: if (out) *out = CRTFtol(this[32] * 255.0); break;
    //       default: return channel - 1;
    //     }
    //     return *out;
    //   }
    // UNRESOLVED: The channel-to-field mapping is irregular (channel 1 at this+0x60, channel 2 at this+0x50, channel 3 at this+0x70, channel 4 at this+0x80); the reason for the non-monotonic order is unknown.
    // UNRESOLVED: Whether the four float fields are color channels (e.g. RGBA) or another 0..1 normalized quantity is not established; the 255.0 scale suggests byte normalization but that is DERIVED.
    // UNRESOLVED: The owning object is unknown; the existing analysis notes this is the inverse of a float setter (float = byte/255), which is unproven from this packet alone.
    // UNRESOLVED: Caller sub_54CA00 (0x0054CA00) is recorded but its call context is not in the packet.
}
