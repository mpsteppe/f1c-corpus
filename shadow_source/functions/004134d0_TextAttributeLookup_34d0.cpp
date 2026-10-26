// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004134D0
// Canonical corpus name: TextAttributeLookup_34d0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextAttributeLookup_34d0_004134d0.c

void UnknownObject::TextAttributeLookup_34d0()
{
    // Resolves a text attribute from a list node and copies it into the caller's output struct (a1). Uses LinkedListIndexedAccessor_5680(a3) to fetch the indexed node, dispatches on the attribute mode a2 (0 selects node+52 or node+72, 1 selects node+132 or node+152, the a4 flag selecting the alternate slot), copies the selected string through StringCopyWithBufferRealloc with an empty-sentinel fallback (byte_5EA438), then copies the node attribute dword/byte components into a1+8/a1+12/a1+16. Ends by re-copying the empty sentinel and returning -1 when the output struct is still the all-empty sentinel, else 1. Called by SessionStringNameLookup (004122C0).
    // CALL: LinkedListIndexedAccessor_5680(a3) resolves the indexed list node; when it returns null the attribute-copy block is skipped entirely [callee:0x00415680, source:raw]
    // GUARD: Attribute-mode dispatch on a2: a2==0 selects node+52 (or node+72 when a4 is clear), a2==1 selects node+132 (or node+152 when a4 is clear), and any other a2 value falls through to the default empty path [source:raw]
    // CALL: The selected attribute string is copied via StringCopyWithBufferRealloc, substituting the empty sentinel byte_5EA438 when the node string pointer is null [callee:0x00566650, global:0x005EA438, source:raw]
    // ASSIGNMENT: Copies the attribute components from the selected node slot (dword at +8, dword at +12, byte at +16) into the output struct at a1+8, a1+12 and a1+16 [field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, source:raw]
    // CALL: Unconditionally re-copies the empty sentinel byte_5EA438 through StringCopyWithBufferRealloc to reset the working string buffer [callee:0x00566650, global:0x005EA438, source:raw]
    // GUARD: Empty-result check: the output string (a1+0, falling back to the empty sentinel when null) equals byte_5EA438 AND a1+8 equals -1 AND a1+12 equals -1 AND the byte at a1+16 is zero [guard:0, guard:1, field:this:0x00000000, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, source:raw]
    // RETURN: Returns -1 when the all-empty sentinel is detected, otherwise 1 [source:raw]
    // CALL: Invoked by SessionStringNameLookup (004122C0) while resolving a session string name [caller:0x004122C0, source:raw]

    // Conservative worker pseudocode:
    //   node = LinkedListIndexedAccessor_5680(a3);
    //   if (node) {
    //     if (a2 == 0) slot = node + (a4 ? 52 : 72);
    //     else if (a2 == 1) slot = node + (a4 ? 132 : 152);
    //     else goto default_path;
    //     str = *(slot) ? *(slot) : &byte_5EA438;
    //     StringCopyWithBufferRealloc(str);
    //     a1+8 = *(slot + 8); a1+12 = *(slot + 12); a1+16 = *(slot + 16);
    //   }
    //   default_path:
    //   StringCopyWithBufferRealloc(&byte_5EA438);
    //   str = *(a1) ? *(a1) : &byte_5EA438;
    //   if (strcmp(str, &byte_5EA438) == 0 && a1+8 == -1 && a1+12 == -1 && *(a1+16) == 0)
    //     return -1;
    //   return 1;
    // UNRESOLVED: FreeWrapper_7bcf (callee:0x00587BCF) is listed as a callee by the fact table but never appears in the raw decompiled source; likely reachable only through StringCopyWithBufferRealloc's internal allocation/free path
    // UNRESOLVED: Global dword_5EA5E8 is flagged as read by the fact table but is absent from the raw decompiled source
    // UNRESOLVED: The slot offsets (52/72/132/152) and their dword/byte component layout are evidenced only from the raw source text; the owning list-node type is not defined here
}
