// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045E5B0
// Canonical corpus name: ArraySearchFor1Sentinel
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArraySearchFor1Sentinel_0045e5b0.c

void UnknownObject::ArraySentinelSearch()
{
    // Walks a DWORD array starting at this+0x1D4 (this + 117 dwords) and returns the 0-based index of the first element equal to the -1 sentinel (0xFFFFFFFF). If no sentinel is found within 104 elements it returns -1. Called by NetComm session-messaging paths (NetCommSessionMessageDispatcher 0x0045D890, NetComm_SetSelfAsReady 0x00460520), consistent with locating a free or unset entry in a 104-entry network-session table.
    // ASSIGNMENT: Seed result to 0 and start the iterator at this + 117 dwords, byte offset this+0x1D4, the head of the sentinel-terminated array. [field:this:0x000001D4, source:raw]
    // LOOP: Forward walk over the DWORD array beginning at this+0x1D4, one element per iteration. [field:this:0x000001D4, source:raw]
    // GUARD: guard:0 — iteration continues while the current element is not equal to 0xFFFFFFFF; an element equal to the sentinel stops the walk. [guard:0, field:this:0x000001D4, source:raw]
    // GUARD: If 104 elements are scanned without hitting the sentinel, return -1 (not found) instead of an index. [source:raw]
    // RETURN: Return the index of the first element equal to 0xFFFFFFFF, or -1 when the 104-element window contains no sentinel. [source:raw]
    // CALL: Called from NetComm session messaging and ready-state paths (0x0045D890, 0x00460520), supporting a free/unset slot search over a 104-entry table. [caller:0x0045D890, caller:0x00460520]

    // Conservative worker pseudocode:
    //   int sub_45E5B0(void) {
    //     int result = 0;
    //     DWORD* i = (DWORD*)((char*)this + 0x1D4);
    //     for (; *i != -1; ++i) {
    //       if (++result >= 104) return -1;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The 104-element window suggests a per-session slot table, but what a non-sentinel element encodes (occupancy, state, handle) is not evidenced here.
    // UNRESOLVED: Element size is 4 bytes per the _DWORD* typing in the raw source; the slot meaning and the identity of the containing object are unknown.
    // UNRESOLVED: Why the sentinel is -1 versus any other marker is a property of the caller's table initialization, not determinable from this packet.
}
