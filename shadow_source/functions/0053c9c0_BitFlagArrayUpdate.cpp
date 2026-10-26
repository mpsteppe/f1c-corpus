// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053C9C0
// Canonical corpus name: BitFlagArrayUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitFlagArrayUpdate_0053c9c0.c

void UnknownObject::BitFlagArrayUpdate()
{
    // Iterates an array of flag dwords (base dword_8B5A38, count dword_8B8E30, stride 33 dwords); every element that has bit 0x4000 set is rewritten to clear 0x4000 (mask 0xFFFFBBFF) and set 0x400. Ends with a tail call to SearchPathPrune(this), whose result is returned.
    // GUARD: The array walk runs only when the element count dword_8B8E30 is greater than 0 [global:0x008B8E30, source:raw]
    // LOOP: Walk the array at dword_8B5A38 for dword_8B8E30 elements, advancing 33 dwords per element [global:0x008B5A38, global:0x008B8E30, source:raw]
    // GUARD: Per element, the flag rewrite applies only when bit 0x4000 is set [source:raw]
    // ASSIGNMENT: Rewrite the element: clear bit 0x4000 (AND with 0xFFFFBBFF) and set bit 0x400 (OR with 0x400) [source:raw]
    // CALL: Tail call SearchPathPrune(this) as the final step; the packet records no callee entry for SearchPathPrune so its address is not confirmed here [function:0x0053C9C0, caller:0x00543FA0, source:raw]
    // RETURN: Return the value produced by SearchPathPrune(this) [source:raw]

    // Conservative worker pseudocode:
    //   if (dword_8B8E30 > 0) {
    //     element = dword_8B5A38;
    //     for (count = dword_8B8E30; count > 0; --count, element += 33) {
    //       if (*element & 0x4000)
    //         *element = (*element & 0xFFFFBBFF) | 0x400;
    //     }
    //   }
    //   return SearchPathPrune(this);
    // UNRESOLVED: SearchPathPrune is called in the raw source but the packet's callee list is empty, so its target address and identity cannot be confirmed from this packet
    // UNRESOLVED: Purpose of the flag rewrite (clear 0x4000, set 0x400) is unknown; the 33-dword element stride implies an array of structs whose layout is not given
    // UNRESOLVED: Called by VertexBufferResourceAllocation (0x00543FA0); the connection between this flag update and that resource-allocation path is not explained by the packet
}
