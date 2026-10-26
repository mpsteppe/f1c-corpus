// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057D8D0
// Canonical corpus name: NetworkPacketSendWithQueryMatching
// Owner: NetworkConnectionManager [DERIVED]
// Raw source: functions/NetworkPacketSendWithQueryMatching_0057d8d0.c

void NetworkConnectionManager::NetworkPacketSendWithQueryMatching()
{
    // Builds a structured packet for a2 via StructuredMemoryCopyWithHeaderPrepend into a 770-word buffer, computing packet length from the buffer header words. When a3 is non-null, acquires the mutex-protected connection list, locates the node matching a3's query (exact field match or sub_57DB80 fallback), and send()s the packet to that node's socket. When a3 is null, walks all connection nodes and send()s to each node whose event fields match any entry of the query list at a2+0x48.
    // CALL: StructuredMemoryCopyWithHeaderPrepend(a2, buf): build the structured packet (header + payload) into buf. [callee:0x0057D5D0, source:raw]
    // CALCULATION: len = buf[1] + buf[0] + 4: total packet length derived from the buffer header words. [source:raw]
    // GUARD: If a3 is null select the broadcast path, otherwise the directed-send path. [source:raw]
    // GUARD: Acquire the connection-list mutex (this+0xABC) via WaitForSingleObject with timeout this+0xAC0; on timeout or error skip the list walk. [global:0x0059E1A0, field:this:0x00000ABC, field:this:0x00000AC0]
    // GUARD: If the list head *(this+0xAAC) is 0 there are no connection nodes; skip the send. [guard:0, field:*(this+0xAAC):0x00000000]
    // LOOP: Walk the connection list via iterator this+0xAB4, matching node ID fields (*(node+4)==a3[1] and *(node+2)==HIWORD(a3)) or falling back to sub_57DB80(a3 fields) for the connection query. [field:*(*(this+0xAAC)+0x0):0x00000004, field:*(*(this+0xAAC)+0x0):0x00000002, callee:0x0057DB80, field:this:0x00000AB4]
    // CALL: OffsetGetter(node) resolves the node's socket handle; send(handle, buf, len, 0) transmits the packet; success when the return equals len. [callee:0x0057B6B0, global:0x0059E300]
    // STATE_TRANSITION: ReleaseMutex(this+0xABC) after the directed-send list walk. [global:0x0059E1A4, field:this:0x00000ABC]
    // LOOP: Broadcast path: iterate the query list at a2+0x48 via IndexedLinkedListNodeGetter; for each query entry compare the connection node's field pairs (offset +4/+2 and +20/+18) against the entry. [callee:0x0057B0D0, field:*(*(this+0xAAC)+0x0):0x00000004, field:*(*(this+0xAAC)+0x0):0x00000002, field:*(*(this+0xAAC)+0x0):0x00000012, field:*(*(this+0xAAC)+0x0):0x00000014]
    // CALL: Broadcast filter: StructFieldGetter_b2e0(node) and ReadFieldAtOffset0x14(node) feed a callback via the query node vtable at +16; on acceptance send(handle, buf, len, 0). [callee:0x0057B2E0, callee:0x005871F0, global:0x0059E300]
    // STATE_TRANSITION: ReleaseMutex(this+0xABC) after the broadcast list walk. [global:0x0059E1A4, field:this:0x00000ABC]
    // RETURN: Directed path returns the send success flag; broadcast path returns 1. [source:raw]

    // Conservative worker pseudocode:
    //   StructuredMemoryCopyWithHeaderPrepend(a2, buf);
    //   len = buf[1] + buf[0] + 4;
    //   if (a3) {
    //     if (WaitForSingleObject(this[687], this[688]) fails) skip;
    //     list = this + 683; list[2] = list[0];
    //     node = *list;
    //     while (node && !(*(node+4)==a3[1] && *(node+2)==HIWORD(a3)) && !sub_57DB80(a3[0..3]))
    //       node = advance iterator;
    //     if (node) send(*(OffsetGetter(node)), buf, len, 0);
    //     if (list[4]) ReleaseMutex(list[4]);
    //     return matched?;
    //   } else {
    //     if (WaitForSingleObject(this[687], this[688]) fails) skip;
    //     list = this + 683; list[2] = list[0];
    //     for (node = *list; node; node = advance) {
    //       matched = 0;
    //       for (q = IndexedLinkedListNodeGetter(*(a2+72), i); q; q = next)
    //         if (node match q fields) matched = 1;
    //       if (matched || callback(StructFieldGetter_b2e0(node), ...))
    //         send(*(OffsetGetter(node)), buf, len, 0);
    //     }
    //     if (list[4]) ReleaseMutex(list[4]);
    //     return 1;
    //   }
    // UNRESOLVED: Connection node internal layout (next/tail pointers and the socket field located via OffsetGetter) is inferred from the list walk, not packet-confirmed.
    // UNRESOLVED: List control block auxiliary field at *(this+0xAB8) offsets +2/+4 is reported by deterministic facts but not visible in the decompiled body.
    // UNRESOLVED: sub_57DB80 exact match criteria not examined.
    // UNRESOLVED: Query-list dereference at a2+0x48 (offset 72) is outside the declared field evidence set.
}
