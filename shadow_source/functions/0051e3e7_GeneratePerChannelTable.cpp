// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051E3E7
// Canonical corpus name: sub_51E3E7
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_51E3E7_0051e3e7.c

void UnknownObject::GeneratePerChannelTable()
{
    // Builds per-channel lookup tables in an allocated output buffer. Selects normal mode (offset 0) or extended mode (offset 510 with a mirror of entries across the index 255 boundary) from this+0x4C (a1[19]), allocates the output table through an indirect vtable call on this+0x4, then fills 256 entries per channel using a per-channel stride array and a stepped base value. Returns a value that is a compiler artifact of the channel loop rather than a meaningful result. ABI lead names this Audio_Waveform_Table_Generator (LEGACY). Static callers are CodecModeSelect and ObjectSetupWithBoundsCheck.
    // ASSIGNMENT: Load context pointer v1 = a1[105] (this+0x1A4); the subsequent writes target that context object's own fields at +20, +24, +28 and +32. [field:this:0x000001A4, source:raw]
    // GUARD: Branch on a1[19] (this+0x4C) == 1: extended mode selects v14 = 510 and writes context byte +28 = 1; otherwise v14 = 0 and context byte +28 = 0. [field:this:0x0000004C, guard:0, source:raw]
    // CALL: Allocate/initialize the output table: indirect call through the vtable slot at this+0x4 (function pointer at offset +8) with arguments (a1, 1, v14 + 256, a1[25]); the result is stored to context +24. [field:this:0x00000004, field:this:0x00000064, function:0x0051E3E7, source:raw]
    // GUARD: Per-channel table generation runs only when the channel count a1[25] (this+0x64) is greater than 0. [field:this:0x00000064, guard:1, source:raw]
    // LOOP: Iterate over channels: walk a stride array starting at context +32 (per-channel stride values), advancing the channel index v2/v11 until v11 >= a1[25]. [field:this:0x000001C4, field:this:0x00000064, source:raw]
    // CALCULATION: Per channel: read stride v4 from the stride array, compute v12 = base / stride (base from context +20); in extended mode add 255 to the table entry pointer slot at (context+24 table)[4 * channel]. [field:this:0x0000004C, source:raw]
    // LOOP: Fill 256 entries of the channel table: write v5[v16] = v12 * v15, incrementing the step counter v15 when v16 exceeds the adaptive threshold v6 = (stride + 254) / (2 * stride - 2), which is recomputed in 510-unit jumps. [source:raw]
    // GUARD: In extended mode mirror the table across the 255 boundary: write the first entry into 255 slots before the table start and the entry at index 255 into 255 slots after the table, producing the 510-wide extended table. [field:this:0x0000004C, source:raw]
    // RETURN: Return the loop-carried value (the last computed step or the object pointer depending on loop exit); the raw source gives it no stable meaning, so it is treated as a compiler artifact. [source:raw]

    // Conservative worker pseudocode:
    //   // this = a1; ctx = this[105] (+0x1A4)
    //   int GeneratePerChannelTable(DWORD* this) {
    //     int ctx = this[105];
    //     int v14;
    //     if (this[19] == 1) { v14 = 510; *(BYTE*)(ctx + 28) = 1; }
    //     else              { v14 = 0;   *(BYTE*)(ctx + 28) = 0; }
    //     *(DWORD*)(ctx + 24) = ((call_t)this[1][2])(this, 1, v14 + 256, this[25]);
    //     int result = *(DWORD*)(ctx + 20);
    //     if ((int)this[25] > 0) {
    //       int* stride = (int*)(ctx + 32);
    //       for (int ch = 0; ; ) {
    //         int s = *stride;
    //         int step = result / s;
    //         if (v14) *(DWORD*)(*(DWORD*)(ctx + 24) + 4 * ch) += 255;
    //         BYTE* tab = *(BYTE**)(*(DWORD*)(ctx + 24) + 4 * ch);
    //         int v15 = 0, v16 = 0;
    //         int lim = (s + 254) / (2 * s - 2);
    //         do {
    //           if (v16 > lim) {
    //             for (int i = 510 * v15; ; i += 510) {
    //               i += 510; ++v15;
    //               lim = (i + 510 + s + 254) / (2 * s - 2);
    //               if (v16 <= lim) break;
    //             }
    //           }
    //           tab[v16] = (BYTE)(step * v15);
    //           ++v16;
    //         } while (v16 <= 255);
    //         if (v14) {
    //           int j = 1;
    //           BYTE* p = tab - 1;
    //           do {
    //             *p = *tab;
    //             tab[j + 255] = tab[255];
    //             --p; ++j;
    //           } while (j <= 255);
    //         }
    //         result = step;
    //         ++stride; ++ch;
    //         if (ch >= this[25]) break;
    //         result = step;
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Packet fields this+0xC, this+0x1B8, this+0x1BC and this+0x1C0 do not appear verbatim in the raw source; the packet field mapping (this+0x1BC output-table pointer, this+0x1C0 initialized to 0) comes from prior analysis, while the raw source writes the equivalent fields on the context object at +20/+24/+28/+32.
    // UNRESOLVED: Per-channel stride array location: raw source walks context +32; packet field this+0x1C4 is the prior-analysis name for that array and is not an explicit access in the raw source.
    // UNRESOLVED: Callers CodecModeSelect (0x0051EA90) and ObjectSetupWithBoundsCheck (0x0051EB6E) identify the call sites, but the exact role of the generated tables there is not determined here.
}
