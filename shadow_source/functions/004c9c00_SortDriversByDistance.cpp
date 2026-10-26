// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C9C00
// Canonical corpus name: SortDriversByDistance
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SortDriversByDistance_004c9c00.c

void UnknownObject::SortDriversByDistance()
{
    // Copies the live vehicle pointer array (offsetting each entry by 12), sorts the resulting pointer list with a speed-sum comparator via the generic sort routine sub_5890AA, then writes each vehicle's summed speed (two floats at +1848 and +1856) into an output buffer starting at this[103]. Called by WeatherParticleUpdate (0x004CFCC0) to prioritize effects by combined vehicle speed.
    // ASSIGNMENT: Read the vehicle count from global dword_5C329C into v1. [global:0x005C329C, source:raw]
    // GUARD: Proceed with the pointer copy only when dword_5C329C (vehicle count) is greater than 0; otherwise skip straight to the sort. [global:0x005C329C, source:raw]
    // LOOP: do-while countdown loop over v1 entries: fill this[0..v1) by reading each pointer from the global vehicle pointer array (dword_7C54F0) at the matching offset and adding 12 to it. [field:this:0x00000000, global:0x007C54F0, source:raw]
    // CALCULATION: Each copied entry is the raw pointer plus the constant 12 (per-entry offset used by the caller's vehicle representation). [global:0x007C54F0, source:raw]
    // CALL: Sort the buffer with sub_5890AA(this, v1, 4, SortComparatorSpeedSum): count v1, element size 4, comparator at 0x004C9BA0. [callee:0x005890AA, global:0x004C9BA0, source:raw]
    // LOOP: for loop over the first v1 sorted pointers: for each pointer v7, write the sum of the floats at v7+1848 and v7+1856 into this[result + 103] as a float. [field:this:0x00000000, source:raw]
    // RETURN: Return the final loop counter value (equals the vehicle count v1). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4C9C00(int *out) {
    //     int count = dword_5C329C;
    //     if (count > 0) {
    //       int delta = (char*)dword_7C54F0 - (char*)out;
    //       int n = count;
    //       int *p = out;
    //       do { *p = *(int*)((char*)p + delta) + 12; ++p; --n; } while (n);
    //     }
    //     sub_5890AA(out, count, 4, SortComparatorSpeedSum);
    //     int i = 0;
    //     for (; i < count; ++i) {
    //       int *v = (int*)out[i];
    //       *(float*)&out[i + 103] = *(float*)((char*)v + 1848) + *(float*)((char*)v + 1856);
    //     }
    //     return i;
    //   }
    // UNRESOLVED: Meaning of the constant 12 added to each copied pointer is not stated in this function.
    // UNRESOLVED: The results buffer at this[103..103+count] and the vehicle speed offsets +1848/+1856 are caller-defined; exact types unproven.
    // UNRESOLVED: Comparator SortComparatorSpeedSum (0x004C9BA0) compares the same +1848/+1856 speed fields, but its internals are not visible here.
}
