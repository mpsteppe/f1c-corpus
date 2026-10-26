// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059416F
// Canonical corpus name: sub_59416F
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59416F_0059416f.c

void UnknownObject::SlabHeapAllocateBlock()
{
    // Slab/buddy heap block allocation. Rounds the requested size a1 up to a 16-byte boundary, selects a buddy size class, and walks the slab descriptor array from the global cursor dword_8D48F0 testing each slab's two-level free bitmap for a free block of the required class; wraps the scan, and when no existing slab fits allocates a fresh slab via sub_594478 and initializes its bitmap/free-list descriptor via sub_594529, returning 0 if either fails. Unlinks and optionally splits the chosen block, maintains the free-list, refcount and bitmap bookkeeping, and returns a pointer just past the 16-byte-rounded size header.
    // CALCULATION: Round the requested size a1 up to the 16-byte boundary: v27 = (a1 + 23) & 0xFFFFFFF0; the buddy size-class index is v1 = (v27 >> 4) - 1 [source:raw]
    // GUARD: Choose the two-level free-bitmap masks: when the class index is 32 or above only a high-order mask (v30 = 0xFFFFFFFF >> ((v27 >> 4) - 33)) is set and v28 is 0, otherwise the low mask v2 and the stored v28 both equal 0xFFFFFFFF >> v1; the masks later index each slab's two bitmap words [source:raw]
    // ASSIGNMENT: v32 = lpMem + 20 * dword_8D48F8 computes the end of the slab descriptor array (arena base plus 20-byte descriptor stride times slab count) [global:0x008D48FC, global:0x008D48F8, source:raw]
    // LOOP: Walk descriptors forward from the cursor dword_8D48F0 (stride 20) testing (v2 & first word) | (v30 & second word) until a slab with a free block of the requested class is found or the array end is reached [global:0x008D48F0, source:raw]
    // LOOP: When the forward scan hits the array end (i == v32), rescan from lpMem up to the old cursor dword_8D48F0 for the same bitmap match (wraparound scan) [global:0x008D48F0, source:raw]
    // LOOP: If the bitmap scan still finds nothing, scan for a descriptor whose free-list pointer *(i + 2) is zero, again wrapping at dword_8D48F0 [global:0x008D48F0, source:raw]
    // CALL: When no existing slab can satisfy the request, sub_594478() allocates a fresh slab; a null return makes the whole allocation fail (return 0) [callee:0x00594478, source:raw]
    // CALL: sub_594529(i) initializes the new slab's bitmap and free-list descriptor array; a -1 return makes the allocation fail (return 0) [callee:0x00594529, source:raw]
    // ASSIGNMENT: Persist the winning descriptor as the new allocation cursor: dword_8D48F0 = i [global:0x008D48F0, source:raw]
    // ASSIGNMENT: v8 = *(i + 4) reads the slab's block bitmap/free-list descriptor; find the free-list index (v9/v33) whose bitmap words still hold a set bit for the selected masks [source:raw]
    // CALCULATION: Derive the buddy size class v12 by shifting the candidate bitmap mask until its leading set bit falls out (v12 counts the bit position) [source:raw]
    // ASSIGNMENT: v14 = v29[2 * v12 + 1] follows the free-list head for the size class; v31 = *v14 - v27 is the leftover size after the block is removed [source:raw]
    // STATE_TRANSITION: When the leftover is large enough for a smaller size class, unlink the block from its free list (pointer fixups at +4/+8), adjust the size-class refcount, and when a refcount drops to zero clear the corresponding bitmap bit and advance the descriptor bitmap pointer [source:raw]
    // CALCULATION: Write the allocation header and footer: *v24 = v27 + 1 and *(v24 + v27 - 4) = v27 + 1; the usable pointer returned is v24 + 1 (just past the header) [source:raw]
    // STATE_TRANSITION: If the slab was empty before this allocation (count went 0 to 1) and the current descriptor matches the active one (i == dword_8D48F4 and v33 == dword_8D48EC), reset dword_8D48F4 to 0 [global:0x008D48F4, global:0x008D48EC, source:raw]
    // RETURN: Return the allocated pointer (v24 + 1), or 0 when slab allocation or bitmap initialization failed [source:raw]
    // CALL: Invoked by the per-frame allocator users sub_58A973, sub_58AB58 and sub_58B5D4 [caller:0x0058A973, caller:0x0058AB58, caller:0x0058B5D4, source:raw]

    // Conservative worker pseudocode:
    //   v27 = (a1 + 23) & 0xFFFFFFF0;   /* round request up to 16 bytes * /
    //   v32 = lpMem + 20 * dword_8D48F8;
    //   i = dword_8D48F0;
    //   while (i < v32 && !(v2 & *(DWORD*)i | v30 & *((DWORD*)i + 1))) i += 20;
    //   if (i == v32) { wrap scan to dword_8D48F0; then scan for empty free-list descriptor; }
    //   if (no descriptor) { i = sub_594478(); if (!i) return 0; if (sub_594529(i) == -1) return 0; }
    //   dword_8D48F0 = i;
    //   pick free-list index v9 and buddy size class v12 from the bitmap;
    //   unlink/split block at v14; maintain free lists, refcounts and bitmap bits;
    //   *v24 = v27 + 1; *(v24 + v27 - 4) = v27 + 1;
    //   if ((*v29)++ == 0 && i == dword_8D48F4 && v33 == dword_8D48EC) dword_8D48F4 = 0;
    //   return v24 + 1;
    // UNRESOLVED: The meaning of the -1 sentinel in the descriptor bitmap word and the exact interaction of the low/high bitmap masks beyond free-list classification are inferred from context, not independently verified
    // UNRESOLVED: The layout of the 20-byte slab descriptors and the identities of lpMem / dword_8D48F8 (arena base and slab count) are read from the decompilation; no struct definition is recovered
    // UNRESOLVED: The dword_8D48F4 reset semantics (active-slab reset when a slab becomes empty) is inferred from the guard condition
}
