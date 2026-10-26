// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051E512
// Canonical corpus name: PerIndexTableGenerationWithDivision
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PerIndexTableGenerationWithDivision_0051e512.c

void UnknownObject::PerIndexTableGenerationWithDivision()
{
    // Builds a per-entry division lookup table array. For each of the (this+0x64) entries, reads the entry descriptor from the descriptor array at *(this+0x1A4)+0x20, checks whether a table slot already exists for a previously seen equal descriptor, and otherwise allocates a 1024-byte table through the allocator vtable at this+0x4, filling it with (65025 - 510 * byte) / ((descriptor << 9) - 512) results for every source pair in the global table dbl_5B05C8 up to dword_5B06C8. Called by CodecModeSelect (0x0051EA90).
    // GUARD: Entry count guard: when *(this + 0x64) > 0 proceed with per-entry table construction; otherwise return immediately with no tables built. [field:this:0x00000064, guard:0, source:raw]
    // ASSIGNMENT: Load the context pointer v1 = *(this + 0x1A4); it carries the entry-descriptor array (at +0x20) and the per-entry table-slot storage (at +0x34). [field:this:0x000001A4, source:raw]
    // LOOP: Outer do-while loop over entry index v15 from 0 up to *(this + 0x64), one iteration per entry descriptor. [field:this:0x00000064, source:raw]
    // CALCULATION: Read the entry descriptor v3 = *(*(this + 0x1A4) + 0x20 + 4*v15) from the descriptor array field *(this+0x1A4)+0x20. [field:*(this+0x1A4):0x00000020, source:raw]
    // LOOP: Uniqueness scan: walk the already-seen descriptors starting at *(this + 0x1A4) + 0x20 while v3 != descriptor, bounded by v15; a match yields the index of the previously built table. [field:*(this+0x1A4):0x00000020, source:raw]
    // GUARD: Reuse guard: when a non-zero table pointer already exists for the matched index (*(context + 0x34 + 4*v4) != 0), skip allocation and reuse the existing table. [source:raw]
    // CALL: Allocate a 1024-byte table through the allocator vtable: v12 = (**(this + 0x4))(this, 1, 1024), where *(this+0x4) is the allocator object and *(*(this+0x4))+0x0 is its allocate entry. [field:this:0x00000004, field:*(this+0x4):0x00000000, source:raw]
    // CALCULATION: Compute the scaled divisor v7 = (v3 << 9) - 512 from the entry descriptor; the division result set depends on this value. [source:raw]
    // LOOP: Outer fill loop: walk the double source table from dbl_5B05C8 (start) up to dword_5B06C8 (end), advancing 16 bytes (two doubles) per pass. [global:0x005B05C8, global:0x005B06C8, source:raw]
    // LOOP: Inner fill loop: for i in 0..15 compute v10 = (65025 - 510 * byte(source + i)) / v7 and store each result consecutively in the newly allocated table. [source:raw]
    // ASSIGNMENT: Store the table pointer into the per-entry slot at context + 0x34 + 4*v15, advance v15, and continue until all *(this + 0x64) entries are processed. [field:this:0x00000064, source:raw]
    // CALL: Invoked by CodecModeSelect (0x0051EA90) as part of codec/mode setup, supplying the context whose +0x64 entries get division tables. [caller:0x0051EA90, source:raw]

    // Conservative worker pseudocode:
    //   // this = context; dbl_5B05C8/dword_5B06C8 = global source table bounds
    //   v1 = *(int*)(this + 0x1A4);
    //   v15 = 0;
    //   if (*(int*)(this + 0x64) > 0) {
    //     v2 = v1 + 0x34;
    //     do {
    //       v3 = *(int*)(v2 - 5); // descriptor at v1 + 0x20 + 4*v15
    //       v4 = 0;
    //       if (v15 > 0) {
    //         v5 = v1 + 0x20;
    //         while (v3 != *v5) { ++v4; ++v5; if (v4 >= v15) break; }
    //       }
    //       v6 = *(int*)(v1 + 4*v4 + 0x34);
    //       if (!v6) {
    //         v12 = alloc(this, 1, 1024);
    //         v7 = (v3 << 9) - 512;
    //         v14 = dbl_5B05C8;
    //         v8 = v12;
    //         do {
    //           for (i = 0; i < 16; ++i)
    //             *v8++ = (65025 - 510 * *(byte*)v14) / v7;
    //           v14 += 2;
    //         } while (v14 < dword_5B06C8);
    //         v6 = v12;
    //       }
    //       *v2++ = v6;
    //       ++v15;
    //     } while (v15 < *(int*)(this + 0x64));
    //   }
    // UNRESOLVED: Semantic roles of dbl_5B05C8 and dword_5B06C8 (source-value table and its end bound) are DERIVED from existing analysis, not verified independently here
    // UNRESOLVED: Exact meaning of the division result (65025 - 510*byte) / ((desc<<9)-512) and the consumer of the built tables is caller-side (CodecModeSelect 0x0051EA90) and unverified
    // UNRESOLVED: The allocator at this+0x4 has no caller-proven type; it is only evidenced as a vtable with an allocate entry at offset 0
}
