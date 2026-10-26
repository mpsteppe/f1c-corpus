// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00594F3E
// Canonical corpus name: sub_594F3E
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_594F3E_00594f3e.c

void UnknownObject::PoolBufferResize()
{
    // Resizes a byte buffer a3 (whose current size is stored at *a3) to a4 while maintaining a per-region free-size counter in an entry table owned by a1. v5 selects the 8-byte-stride entry at a1+24 whose index is ((a2 - *(a1+16)) >> 12). On shrink (v4 > a4) it clamps the size, adds the freed delta to *v5, marks v5[1] = 241 and returns 1. On grow (v4 < a4) it verifies the region from the old end to the new end v6 is all zeroes, then commits the new size and updates the descriptor a2 (data pointer at +0, length at +4, struct extends 248 bytes): if the data pointer *a2 lies inside [a3, v6) the descriptor pointer is advanced to v6 (or reset to a2+2 when v6 reaches the struct end) and the entry counter is adjusted by v4 - a4. Returns 0 on the fallthrough paths.
    // ASSIGNMENT: Read the current size v4 = *a3 from the leading byte of the buffer. [source:raw]
    // ASSIGNMENT: Initialize v11 = 0 as the default return value for the fallthrough paths. [source:raw]
    // CALCULATION: Select the region entry v5 = a1 + 24 + 8 * ((a2 - *(a1+16)) >> 12): an 8-byte-stride table in a1 whose base pointer is read at a1+16 and whose entries start at a1+24. [field:this:0x00000010, source:raw]
    // GUARD: Shrink path: taken when v4 > a4, i.e. the current size exceeds the requested size. [source:raw]
    // ASSIGNMENT: Clamp the buffer size *a3 = a4, return the freed amount to the entry counter *v5 += v4 - a4, and mark the entry v5[1] = 241. [source:raw]
    // RETURN: Return 1 as the success result of the shrink path. [function:0x00594F3E, source:raw]
    // GUARD: Grow path: taken when v4 < a4, i.e. the current size is below the requested size. [source:raw]
    // CALCULATION: Compute the end of the newly requested region v6 = &a3[a4]. [source:raw]
    // GUARD: Proceed only when the descriptor a2 (whose extent ends at a2 + 62 dwords, i.e. a2 + 248 bytes) still covers the new region end v6 (a2 + 62 >= v6). [source:raw]
    // LOOP: Scan i from the old region end &a3[v4] upward to v6 looking for the first non-zero byte; v8 records whether the cursor reached v6 (i == v6) without finding one. [source:raw]
    // GUARD: The grow commits only when v8 is true (the growth region contains only zero bytes). [source:raw]
    // ASSIGNMENT: Commit the new size *a3 = a4. [source:raw]
    // GUARD: Descriptor update applies only when the active data pointer *a2 lies inside the resized region: a3 <= *a2 && v6 > *a2. [source:raw]
    // GUARD: When the new region end reaches past the descriptor struct (v6 >= a2 + 248 bytes), reset the descriptor to empty: a2[1] = 0 and *a2 = a2 + 2. [source:raw]
    // ASSIGNMENT: Otherwise advance the descriptor pointer to the region end: *a2 = v6, and set a2[1] to the index of the first non-zero byte following v6 (v9 counts zero bytes starting at *v6 when it is zero). [source:raw]
    // ASSIGNMENT: In both descriptor branches, adjust the entry counter by the delta *v5 += v4 - a4 (negative when growing), then return 1. [source:raw]
    // RETURN: Return 1 as the success result of the grow path. [function:0x00594F3E, source:raw]
    // RETURN: Fallthrough returns v11 (0) when neither the shrink path nor a successful grow path ran. [function:0x00594F3E, source:raw]
    // CALL: Invoked by sub_58B5D4 (0x0058B5D4). [caller:0x0058B5D4, source:raw]

    // Conservative worker pseudocode:
    //   int PoolBufferResize(int a1, DWORD *a2, BYTE *a3, unsigned int a4) {
    //       unsigned int v4 = *a3;
    //       int v11 = 0;
    //       DWORD *v5 = (DWORD *)(a1 + 8 * (((int)a2 - *(DWORD *)(a1 + 16)) >> 12) + 24);
    //       if (v4 > a4) {
    //           *a3 = a4;
    //           *v5 += v4 - a4;
    //           v5[1] = 241;
    //           return 1;
    //       }
    //       if (v4 < a4) {
    //           BYTE *v6 = &a3[a4];
    //           if (a2 + 62 >= (DWORD *)&a3[a4]) {
    //               BYTE *i = &a3[v4];
    //               bool v8 = false;
    //               while (i < v6 && !*i) ++i;
    //               v8 = (i == v6);
    //               if (v8) {
    //                   *a3 = a4;
    //                   if ((unsigned int)a3 <= *a2 && (unsigned int)v6 > *a2) {
    //                       if (v6 >= (BYTE *)a2 + 248) {
    //                           a2[1] = 0;
    //                           *a2 = a2 + 2;
    //                       } else {
    //                           int v9 = 0;
    //                           *a2 = v6;
    //                           while (*v6 == 0 && v6[v9] == 0) ++v9;
    //                           a2[1] = v9;
    //                       }
    //                   }
    //                   *v5 += v4 - a4;
    //                   return 1;
    //               }
    //           }
    //       }
    //       return v11;
    //   }
    // UNRESOLVED: The owner object a1 and the meaning of the 8-byte entry table (base at +16, entries at +24, marker value 241 at entry+4) are not evidenced; the free-size-counter interpretation is inferred from the += v4 - a4 arithmetic.
    // UNRESOLVED: The descriptor layout of a2 (data pointer at +0, length at +4, 248-byte extent) is inferred from pointer arithmetic and is not a named type.
    // UNRESOLVED: The prelabel auto-template claims a field getter at 0x10, but the raw source reads a1+16 as an array base; the raw source outranks that template, and the two readings were not reconciled.
    // UNRESOLVED: Whether the a3 buffer is a string, a pool block, or a generic byte region is unevidenced.
}
