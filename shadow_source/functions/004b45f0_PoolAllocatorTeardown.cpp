// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B45F0
// Canonical corpus name: sub_4B45F0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B45F0_004b45f0.c

void UnknownObject::PoolAllocatorTeardown()
{
    // Tears down a fixed-block memory pool guarded by cleanup flag byte_8AB6E0 bit 0 (set on entry to prevent double-free). Walks the free list headed by dword_8AB700 and the active list headed by dword_8AB6F0, freeing each node's buffer pointer when the in-use flag byte at node+8 is set, then freeing the node struct itself via FreeWrapper_7bcf. Resets all free-list (dword_8AB700/dword_8AB704/dword_8AB708/dword_8AB70C) and active-list (dword_8AB6F0/dword_8AB6F4/dword_8AB6F8/dword_8AB6FC) pointers to zero. Returns 1 regardless of whether the guard skipped the teardown.
    // GUARD: Re-entry guard on byte_8AB6E0 bit 0: when already set, skip the entire teardown; otherwise set bit 0 and proceed (prevents double-free). [global:0x008AB6E0, source:raw]
    // LOOP: Walk the free list from head dword_8AB700 following the next link at node+4; when the in-use flag byte at node+8 is non-zero, free the node's buffer pointer (*v2) with FreeWrapper_7bcf, and the loop's update frees the node itself (v2) each iteration. [global:0x008AB700, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Reset the free-list globals to zero: head dword_8AB700, dword_8AB704, dword_8AB708, and count dword_8AB70C. [global:0x008AB700, global:0x008AB704, global:0x008AB708, global:0x008AB70C, source:raw]
    // LOOP: Walk the active list from head dword_8AB6F0 following the next link at node+4; for nodes with the in-use flag byte at +8 non-zero and a non-null buffer pointer at +0, free the buffer pointed to by the node's buffer pointer and then the buffer pointer struct itself with FreeWrapper_7bcf; the loop's update frees the node itself (v5) each iteration. [global:0x008AB6F0, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Reset the active-list globals to zero: head dword_8AB6F0, dword_8AB6F4, dword_8AB6F8, and count dword_8AB6FC. [global:0x008AB6F0, global:0x008AB6F4, global:0x008AB6F8, global:0x008AB6FC, source:raw]
    // RETURN: Return 1 both on the guarded early path and after the full teardown. [source:raw]

    // Conservative worker pseudocode:
    //   if ((byte_8AB6E0 & 1) == 0) {
    //     byte_8AB6E0 |= 1;
    //     for (v1 = dword_8AB700; v1; v1 = *(DWORD*)(v1 + 4)) {
    //       v2 = v1;
    //       if (*(BYTE*)(v1 + 8) != 0) FreeWrapper_7bcf(*(LPVOID*)v2);
    //     }
    //     dword_8AB700 = 0; dword_8AB704 = 0; dword_8AB708 = 0; dword_8AB70C = 0;
    //     for (v4 = dword_8AB6F0; v4; v4 = *(DWORD*)(v4 + 4)) {
    //       v5 = v4;
    //       if (*(BYTE*)(v4 + 8) != 0 && *(LPVOID*)v5) {
    //         v6 = *(LPVOID**)*v5;
    //         FreeWrapper_7bcf(*v6);
    //         FreeWrapper_7bcf(v6);
    //       }
    //     }
    //     dword_8AB6F0 = 0; dword_8AB6F4 = 0; dword_8AB6F8 = 0; dword_8AB6FC = 0;
    //   }
    //   return 1;
    // UNRESOLVED: Linked node layout (+0 buffer pointer, +4 next link, +8 in-use flag byte) is DERIVED from the decompilation; the packet carries no field table for this type.
    // UNRESOLVED: The exact meaning of byte_8AB6E0 as a one-shot cleanup guard and the roles of the individual head/tail/count globals come from the skeleton prose (DERIVED), not from an independent source.
}
