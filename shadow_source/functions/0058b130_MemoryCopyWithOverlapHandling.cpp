// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058B130
// Canonical corpus name: sub_58B130
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58B130_0058b130.c

void UnknownObject::MemoryCopyWithOverlapHandling()
{
    // Custom memory copy (memmove-like): copies a3 bytes from source a2 to destination a1 and returns the destination address a1. When the destination overlaps the source range (a1 > a2 && a1 < a2 + a3) the function copies backward from the end to avoid clobbering source data; otherwise it copies forward. The forward path performs DWORD-aligned bulk copies (a qmemcpy for large sizes plus an unrolled 0..7 DWORD switch) and finishes with byte-granular remainder copies; an unaligned destination is first brought to alignment through jump-table-dispatched loops (jpt_58B18C / jpt_58B165). All loc_/byte_ globals are jump-table data and case targets of the Duff's-device-style dispatch.
    // GUARD: Detect source/destination overlap: when a1 > (unsigned)a2 and a1 < (unsigned)(a2 + a3) the destination lies inside the source range and the backward-copy path is taken. [function:0x0058B130, source:raw]
    // CALCULATION: Backward path setup: seed end-of-range pointers v7 = (int)&a2[a3 - 4] and v8 = a3 + a1 - 4. [source:raw]
    // LOOP: Backward bulk copy: while v9 = a3 >> 2 is non-zero, copy DWORDs from v7 to v8 and step both pointers back by 4, entering the loop only when a3 >> 2 >= 8. [source:raw]
    // ASSIGNMENT: Backward tail copy: dispatch through the jpt_58B314 / jpt_58B2F2 jump tables (entry data byte_58B318, case targets loc_58B3C4..loc_58B407 and loc_58B420..loc_58B44C) and copy the remaining 0..3 bytes at v8+3, v8+2, v8+1 from the matching source tail bytes. [global:0x0058B410, global:0x0058B318, global:0x0058B3C0, global:0x0058B3C4, global:0x0058B3CC, global:0x0058B3D4, global:0x0058B3DC, global:0x0058B3E4, global:0x0058B3EC, global:0x0058B3F4, global:0x0058B407, global:0x0058B420, global:0x0058B428, global:0x0058B438, global:0x0058B44C, source:raw]
    // GUARD: Forward path destination-alignment check: when (a1 & 3) != 0 dispatch through the jpt_58B18C table (entry byte_58B190, small-size entry loc_58B288 / jpt_58B165) to align the destination before bulk copying. [global:0x0058B20C, global:0x0058B278, global:0x0058B288, global:0x0058B190, source:raw]
    // LOOP: Unaligned-destination alignment loop: copy leading bytes until the destination is DWORD-aligned, dispatched through the jpt_58B18C aligned-copy case targets (loc_58B1A0, loc_58B1CC, loc_58B1F0 and continuation targets loc_58B290, loc_58B29C, loc_58B2B0). [global:0x0058B1A0, global:0x0058B1CC, global:0x0058B1F0, global:0x0058B290, global:0x0058B29C, global:0x0058B2B0, source:raw]
    // CALCULATION: Forward bulk copy: for 4 * v5 >= 8 bytes use qmemcpy(a1, a2, 4 * v5); otherwise dispatch through the unrolled 0..7 DWORD switch (case targets loc_58B22C..loc_58B26F). [global:0x0058B22C, global:0x0058B234, global:0x0058B23C, global:0x0058B244, global:0x0058B24C, global:0x0058B254, global:0x0058B25C, global:0x0058B26F, source:raw]
    // ASSIGNMENT: Forward tail copy: switch on a3 & 3 and copy the 0..3 remainder bytes from v3 to v4 (bytes v4[0], v4[1], v4[2] at destination offsets 0x0, 0x1, 0x2). [field:this:0x00000000, field:this:0x00000001, field:this:0x00000002, source:raw]
    // RETURN: Return the destination address a1 in all copy paths. [source:raw]

    // Conservative worker pseudocode:
    //   unsigned int MemoryCopyWithOverlapHandling(unsigned int dst, _BYTE *src, unsigned int n) {
    //     if (dst > (unsigned)src && dst < (unsigned)(src + n)) {
    //       int d = n + dst - 4, s = (int)(src + n - 4);
    //       unsigned int q = n >> 2;
    //       if (q >= 8) { while (q) { *(DWORD*)d = *(DWORD*)s; s -= 4; d -= 4; --q; } }
    //       /* jpt_58B314 / jpt_58B2F2 dispatch: copy 0..3 backward tail bytes * /
    //     } else {
    //       if (dst & 3) { /* jpt_58B18C / jpt_58B165 alignment dispatch * / }
    //       if ((n >> 2) >= 8) qmemcpy((void*)dst, src, 4 * (n >> 2)); /* else unrolled 0..7 DWORD switch * /
    //       /* switch (n & 3): copy 0..3 forward remainder bytes * /
    //     }
    //     return dst;
    //   }
    // UNRESOLVED: Exact per-case target mapping inside jump tables jpt_58B18C / jpt_58B165 / jpt_58B314 / jpt_58B2F2 is assembly-level and not recoverable from the C listing; the listed loc_/byte_ globals are jump-table data and case targets.
    // UNRESOLVED: The body matches another memory-copy routine in the corpus, suggesting distinct copies of the same routine, but that equivalence is not runtime-proven here.
}
