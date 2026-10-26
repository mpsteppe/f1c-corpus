// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045B580
// Canonical corpus name: FindActivePhysicsChannelByIndex
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FindActivePhysicsChannelByIndex_0045b580.c

void UnknownObject::FindNthActivePhysicsChannel()
{
    // Scans up to 8 physics channels (23-float / 0x5C-byte stride) starting at this+36 (0x90 bytes). A channel is active when its first float is greater than 0.0. Returns the flat channel index (0-7) of the (a2+1)-th active channel (a2 zero-based). Returns 0 if fewer than a2+1 active channels exist.
    // ASSIGNMENT: Initialize counters v2 (active-channel count) and v3 (flat channel index) to 0. [source:raw]
    // LOOP: Iterate the channel array: i starts at this+36 and advances by 23 floats per step, for at most 8 channels. [field:this:0x00000090, source:raw]
    // GUARD: While the channel's first float *i is <= 0.0 (inactive), advance to the next channel index; a channel with *i > 0.0 is active and stops the scan advance. [field:this:0x00000090, source:raw]
    // GUARD: Bound the scan at 8 channels: when the incremented index v3 reaches 8, return 0 (not found). [source:raw]
    // STATE_TRANSITION: When an active channel is found but it is not yet the a2-th, increment the active-channel count v2 and continue scanning. [source:raw]
    // RETURN: Return the flat channel index v3 when the a2-th active channel (a2 == v2) is located; otherwise return 0 after exhausting the 8-channel bound. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_45B580(float *this, int a2) {
    //     int active = 0;
    //     int idx = 0;
    //     for (float *i = this + 36; idx < 8; i += 23, ++idx) {
    //       if (i[0] > 0.0f) {
    //         if (a2 == active) return idx;
    //         ++active;
    //       }
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Global flt_59E440 (0x0059E440) is listed as a read by static facts, but the raw decompiled source compares each channel's first float against literal 0.0; the global's exact role (existing analysis suggests a zero threshold) is unclear.
    // UNRESOLVED: Object type owning the 8-channel array at this+0x90 and the meaning of a positive first float are unknown; stride 0x5C per channel is taken from the loop increment (DERIVED).
    // UNRESOLVED: This function is invoked by sub_45B5C0 (0x0045B5C0); caller identity does not affect behavior inside this function.
    // UNRESOLVED: Legacy ABI lead name (abi:lead) and the function identity ref carry no additional behavior.
}
