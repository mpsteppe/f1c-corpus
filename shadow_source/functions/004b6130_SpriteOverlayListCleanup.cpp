// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B6130
// Canonical corpus name: SpriteOverlayListCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SpriteOverlayListCleanup_004b6130.c

void UnknownObject::SpriteOverlayListCleanup()
{
    // Frees a heap array of overlay/sprite entries stored at this + 0x9B0. If the pointer is non-null, reads the entry count from the header dword at (array - 4), walks the array backward calling QuadrupleListCleanup on each 44-dword (176-byte) entry, frees the header block via FreeWrapper_7bcf, then zeroes the pointer at this + 0x9B0 and the count at this + 0x9B4. Returns the freed pointer value (zero on the normal path).
    // ASSIGNMENT: Read the array pointer result from this + 0x9B0 (this[620]). [source:raw, field:this:0x000009B0]
    // GUARD: Guard on the array pointer being non-null: if it is zero, skip the whole cleanup and return. [source:raw, field:this:0x000009B0]
    // CALCULATION: Read the element count v3 from the header dword at (array - 4) and set v4 to the header pointer (array - 4). [source:raw]
    // CALCULATION: Compute v5 = array + 176*v3 (one entry past the last 176-byte entry). [source:raw]
    // GUARD: Guard on (v3 - 1) >= 0; when the count is zero the walk is skipped entirely. [source:raw]
    // LOOP: do-while loop walking the entries backward (v5 -= 44 dwords = 176 bytes each iteration) for v3 iterations. [source:raw]
    // CALL: Per entry: call QuadrupleListCleanup on the entry at v5. [source:raw, callee:0x004B46F0]
    // CALL: Call FreeWrapper_7bcf on the header pointer v4 (array - 4) to release the allocation. [source:raw, callee:0x00587BCF]
    // ASSIGNMENT: Write this + 0x9B0 (this[620]) to zero to clear the array pointer. [source:raw, field:this:0x000009B0]
    // ASSIGNMENT: Write this + 0x9B4 (this[621]) to zero to clear the count field. [source:raw, field:this:0x000009B4]
    // RETURN: Return the (zeroed) result. [source:raw, function:0x004B6130]

    // Conservative worker pseudocode:
    //   int sub_4B6130(DWORD* this) {
    //     DWORD* arr = this[620];
    //     if (arr) {
    //       DWORD count = *(arr - 4);
    //       DWORD* head = arr - 4;
    //       DWORD* p = arr + 176 * count;
    //       for (int i = count - 1; i >= 0; --i) {
    //         p -= 44;
    //         QuadrupleListCleanup(p);
    //       }
    //       FreeWrapper_7bcf(head);
    //       this[620] = 0;
    //       this[621] = 0;
    //     }
    //     return (int)arr;
    //   }
    // UNRESOLVED: The entry-count header at (array - 4) is outside the packet's listed field evidence (only fields this 0x9B0 and 0x9B4 are tracked).
    // UNRESOLVED: Entry layout and the resource semantics handled by QuadrupleListCleanup per 176-byte entry are unknown.
    // UNRESOLVED: Callers DestroyUIWidgetHierarchy (0x004B5A30) and BufferPoolAllocatorInitialization (0x004B71E0) that trigger this cleanup are unexamined.
}
