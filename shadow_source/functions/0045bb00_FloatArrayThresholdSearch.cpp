// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045BB00
// Canonical corpus name: FloatArrayThresholdSearch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatArrayThresholdSearch_0045bb00.c

void UnknownObject::FloatArrayThresholdSearch()
{
    // Scans a strided float array rooted at this+0x90 and returns how many of its first 8 elements are greater than 0.0, capped at 4. The walk advances by 23 dwords (92 bytes) per element, so the function reads one float from every 92-byte slice of a larger caller-owned structure; once 4 positive values are seen the scan stops early. Structural twin of FindActivePhysicsChannelByIndex (0045b580).
    // ASSIGNMENT: Seed the positive counter (v1) and the iteration counter (v2) to 0 and point v3 at the first element, this + 36 dwords which is byte offset this+0x90. [field:this:0x00000090, source:raw]
    // LOOP: do-while walk over 8 elements of the strided float array starting at this+0x90. [field:this:0x00000090, source:raw]
    // GUARD: When the current element is greater than 0.0, increment the positive counter; break out of the walk as soon as it reaches 4. [source:raw]
    // CALCULATION: Advance to the next element by adding 23 dwords (92 bytes) to the element pointer and increment the iteration counter each pass, stopping after 8 iterations. [source:raw]
    // RETURN: Return the number of positive values found, between 0 and 4. [source:raw]
    // CALL: Called from UI cursor selection rendering (0x0045B660), collision damage decay (0x0045B840), collision penalty scaling (0x0045BE00) and sub_45B5C0, all consistent with reading per-slice state values on caller-owned structures. [caller:0x0045B5C0, caller:0x0045B660, caller:0x0045B840, caller:0x0045BE00]

    // Conservative worker pseudocode:
    //   int sub_45BB00(void) {
    //     int positive = 0;
    //     float* p = (float*)((char*)this + 0x90);
    //     for (int i = 0; i < 8; ++i) {
    //       if (*p > 0.0f && ++positive >= 4) break;
    //       p += 23;
    //     }
    //     return positive;
    //   }
    // UNRESOLVED: Read-only global flt_59E440 is flagged by packet facts but appears nowhere in the raw decompiled source; its role in this scan is unknown.
    // UNRESOLVED: The 92-byte stride and 8-element count describe a slice layout of the caller's structure that is not established here.
    // UNRESOLVED: The meaning of the > 0.0 threshold and the 4-count cap depends on the caller state (UI selection, collision decay, penalty scaling) and is not evidenced in this packet.
}
