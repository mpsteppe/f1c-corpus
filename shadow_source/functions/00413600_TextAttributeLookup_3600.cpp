// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00413600
// Canonical corpus name: TextAttributeLookup_3600
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextAttributeLookup_3600_00413600.c

void UnknownObject::TextAttributeLookup_3600()
{
    // Resolves a text attribute from a list node and copies it into the caller's output struct (a1). Uses LinkedListIndexedAccessor_56c0(a3) to fetch the indexed node; when the node is non-null AND the attribute mode a2 equals 1, selects the node+12 slot (or node+32 when the a4 flag is clear), copies the selected string through StringCopyWithBufferRealloc with an empty-sentinel fallback (byte_5EA438), then copies the node attribute dword/byte components into a1+8/a1+12/a1+16. Ends by re-copying the empty sentinel and returning -1 when the output struct is still the all-empty sentinel, else 1. Called by SoundEventDispatcher (00411E90).
    // CALL: LinkedListIndexedAccessor_56c0(a3) resolves the indexed list node; the attribute-copy block runs only when the node is non-null [callee:0x004156C0, source:raw]
    // GUARD: Combined gate on the node being non-null AND the attribute mode a2 being exactly 1; when a2 is not 1 the function falls through to the default empty path [source:raw]
    // GUARD: Slot selection: a4 set selects node+12, a4 clear selects node+32 [source:raw]
    // CALL: The selected attribute string is copied via StringCopyWithBufferRealloc, substituting the empty sentinel byte_5EA438 when the node string pointer is null [callee:0x00566650, global:0x005EA438, source:raw]
    // ASSIGNMENT: Copies the attribute components from the selected node slot (dword at +8, dword at +12, byte at +16) into the output struct at a1+8, a1+12 and a1+16 [field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, source:raw]
    // CALL: Unconditionally re-copies the empty sentinel byte_5EA438 through StringCopyWithBufferRealloc to reset the working string buffer [callee:0x00566650, global:0x005EA438, source:raw]
    // GUARD: Empty-result check: the output string (a1+0, falling back to the empty sentinel when null) equals byte_5EA438 AND a1+8 equals -1 AND a1+12 equals -1 AND the byte at a1+16 is zero [guard:0, guard:1, field:this:0x00000000, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, source:raw]
    // RETURN: Returns -1 when the all-empty sentinel is detected, otherwise 1 [source:raw]
    // CALL: Invoked by SoundEventDispatcher (00411E90) while dispatching a sound event [caller:0x00411E90, source:raw]

    // Conservative worker pseudocode:
    //   node = LinkedListIndexedAccessor_56c0(a3);
    //   if (node && a2 == 1) {
    //     slot = node + (a4 ? 12 : 32);
    //     str = *(slot) ? *(slot) : &byte_5EA438;
    //     StringCopyWithBufferRealloc(str);
    //     a1+8 = *(slot + 8); a1+12 = *(slot + 12); a1+16 = *(slot + 16);
    //   }
    //   StringCopyWithBufferRealloc(&byte_5EA438);
    //   str = *(a1) ? *(a1) : &byte_5EA438;
    //   if (strcmp(str, &byte_5EA438) == 0 && a1+8 == -1 && a1+12 == -1 && *(a1+16) == 0)
    //     return -1;
    //   return 1;
    // UNRESOLVED: FreeWrapper_7bcf (callee:0x00587BCF) is listed as a callee by the fact table but never appears in the raw decompiled source; likely reachable only through StringCopyWithBufferRealloc's internal allocation/free path
    // UNRESOLVED: Global dword_5EA5E8 is flagged as read by the fact table but is absent from the raw decompiled source
    // UNRESOLVED: The slot offsets (12/32) and their dword/byte component layout are evidenced only from the raw source text; the owning list-node type is not defined here
}
