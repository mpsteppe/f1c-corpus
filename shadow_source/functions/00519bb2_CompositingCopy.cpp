// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00519BB2
// Canonical corpus name: CompositingCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CompositingCopy_00519bb2.c

void UnknownObject::CompositingCopy()
{
    // Copies composited sprite pixel data into destination buffers through per-object sprite descriptors, advancing the animation frame when the current copy line reaches the buffer limit.
    // ASSIGNMENT: Load v2 = a1[97] (this+0x184), the frame copy state that holds the sprite line buffer and copy position counters. [field:this:0x00000184]
    // GUARD: If this+0x120 (a1[72], sprite object count) is zero, skip per-object processing. [guard:1]
    // GUARD: If this+0x120 (a1[72]) is greater than zero, enter the per-object allocation loop. [guard:2]
    // LOOP: Iterate v23 over the descriptor-pointer array at this+0x124 (a1+73) for a1[72] objects; for each, call the vtable function at a1[1]+32 (this+0x4) with the object buffer v2[*(*v23+4)+18], the descriptor width *( *v23+12 ) scaled by a1[32] (this+0x80), the raw width, and 1; store each result in v14. [field:this:0x00000124, field:this:0x00000004, field:*(this+0x124):0x00000004, field:*(this+0x124):0x0000000C, field:this:0x00000080, field:this:0x00000120]
    // CALL: Indirect call through the vtable pointer at this+0x4 (offset 32) dispatches per-object sprite buffer setup. [field:this:0x00000004]
    // LOOP: Walk the line pointer i from v2[6] (this+0x19C) up to v2[7] (this+0x1A0), advancing one dword per iteration. [field:this:0x0000019C, field:this:0x000001A0]
    // GUARD: If the line pointer reaches the end bound (v2[7], this+0x1A0), increment a1[32] (this+0x80) and check it against a1[70] (this+0x118). [field:this:0x00000080, field:this:0x00000118]
    // CALL: If the incremented frame index reaches the frame limit, call the frame-complete callback through the vtable at a1[99]+12 (this+0x18C) and return 4. [field:this:0x0000018C]
    // CALL: Otherwise call SpriteFrameSelector(a1) to advance to the next sprite frame and return 3. [callee:0x00519986]
    // GUARD: If the copy position v2[5] (this+0x198) is below the scan-line limit a1[77] (this+0x134), keep copying; otherwise reset v2[5] to 0 and continue. [field:this:0x00000198, field:this:0x00000134]
    // GUARD: Per descriptor, only copy rows when the descriptor field at +56 (this+0x124 object row count) is greater than zero. [guard:0, field:*(this+0x124):0x00000038]
    // CALCULATION: Compute the starting row offset v16 = (v17 * descriptor+52) << 7 where descriptor+52 is the row stride (this+0x124+0x34). [field:*(this+0x124):0x00000034]
    // LOOP: For each descriptor in the this+0x124 array, copy v9=descriptor+52 elements per row into the v2 line buffer (starting at &v2[v22+8]), writing v10 and advancing it by 128 each element; repeat for descriptor+56 rows. [field:this:0x00000124, field:*(this+0x124):0x00000034, field:this:0x00000184]
    // CALL: Indirect call through the vtable at a1[101]+4 (this+0x194) checks whether the buffer is ready; if it returns false the copy loop exits. [field:this:0x00000194]
    // STATE_TRANSITION: After a full line, increment the copy position v5; when it reaches a1[77] (this+0x134) the copy position is zeroed and the next line pointer is taken from the loop state. [field:this:0x00000198, field:this:0x00000134]
    // ASSIGNMENT: On normal completion store the final line pointer into v2[6] (this+0x19C) and the copy position into v2[5] (this+0x198), then return 0. [field:this:0x0000019C, field:this:0x00000198]
    // RETURN: Return 0 on normal completion, 3 after advancing to the next sprite frame, or 4 when the frame animation limit is reached. [source:raw]

    // Conservative worker pseudocode:
    //   if (a1[72] > 0) for each descriptor pointer in a1+73: v14[n] = vtable(a1[1]+32)(a1, v2[*(*d+4)+18], *(*d+12)*a1[32], *(*d+12), 1);
    //   for (i = v2[6]; i < v2[7]; ) { if (v2[5] >= a1[77]) v2[5] = 0; copy rows; if (!vtable(a1[101]+4)(a1, v2+8)) break; ++v5; }
    //   if line complete: ++a1[32]; if (a1[32] >= a1[70]) return vtable(a1[99]+12)(a1) ? 4 : 3 via SpriteFrameSelector.
    // UNRESOLVED: this+0x24 (a1[9]) is listed as a read field but is not directly referenced in the raw source; it may be a decompiler artifact or indirect alias.
    // UNRESOLVED: The return value 4 from the frame-complete callback path is inferred as 'frame animation complete' from the frame-limit comparison; the callback return is not used.
}
