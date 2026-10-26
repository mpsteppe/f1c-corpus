// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B70B0
// Canonical corpus name: LoadVehicleEntries
// Owner: SessionVehicleGridLoader [GUESS]
// Raw source: functions/LoadVehicleEntries_004b70b0.c

void SessionVehicleGridLoader::LoadVehicleEntries()
{
    // Vehicle grid loader. Peeks the queue head via QueuePeek, then loops over 104 vehicle slots (18624-byte stride, cumulative limit 1936896) calling LinkedListTraversalWithFilter per slot. For a found entry it transitions session state to 3, delegates on v4+65 via TwoCallDelegation, copies the string at v4+97 via StringCopyWithBufferRealloc, and sets the driver name at v4+1 via SetDriverName; for a missing entry it transitions session state to -1. After the loop it stores dword_5C329C = count-1, rebuilds the active vehicle pointer array (BuildActiveVehiclePointerArray), clears the load-state globals dword_7CEC90/dword_7CED8C/dword_7CEE88, sets dword_7D0990 to the sign-masked count-1, parses the scene data (SceneDataParser) from field 0x724 (this[457]) or byte_5EA438 fallback, initializes AI via AIW(0), sets byte_7C5690 to 1, and returns MultiplayerVehiclePlacement(&dword_7C569C, field 0xF20 (this[968])).
    // CALL: Peek the queue head into the v8/v9 locals via QueuePeek. [callee:0x004B87A0, source:raw]
    // LOOP: do-while loop over the vehicle grid: 104 slots at a 18624-byte stride, cumulative pointer limit 1936896, slot counter v7 incremented each pass. [source:raw]
    // CALL: Look up the current slot's entry via LinkedListTraversalWithFilter(v7, v8). [callee:0x004B72A0, source:raw]
    // GUARD: When the lookup returns a valid entry: transition session state to 3, delegate on v4+65 via TwoCallDelegation, copy the string at v4+97 via StringCopyWithBufferRealloc, set the driver name at v4+1 via SetDriverName, and increment the found count v3. [callee:0x004EF5A0, callee:0x004C7B20, callee:0x00566650, callee:0x004C6980, source:raw]
    // GUARD: When the lookup finds nothing, transition session state to -1. [callee:0x004EF5A0, source:raw]
    // ASSIGNMENT: Store dword_5C329C = v3 - 1 (loaded vehicle count). [global:0x005C329C, source:raw]
    // CALL: Rebuild the active vehicle pointer array via BuildActiveVehiclePointerArray. [callee:0x0042BC80]
    // ASSIGNMENT: Clear the load-state globals dword_7CEC90, dword_7CED8C and dword_7CEE88 to 0, and set dword_7D0990 to (v3-1) masked by its own sign. [global:0x007CEC90, global:0x007CED8C, global:0x007CEE88, global:0x007D0990]
    // ASSIGNMENT: Resolve the scene-data path from field 0x724 (this[457]), falling back to byte_5EA438 when null. [field:this:0x00000724, global:0x005EA438]
    // CALL: Parse the resolved scene data via SceneDataParser. [callee:0x004C5690]
    // CALL: Initialize the AI layer via AIW(0). [callee:0x004C54F0]
    // ASSIGNMENT: Set the init-state flag byte_7C5690 to 1. [global:0x007C5690]
    // RETURN: Return MultiplayerVehiclePlacement(&dword_7C569C, field 0xF20 (this[968])). [callee:0x0042CF10, global:0x007C569C, field:this:0x00000F20]

    // Conservative worker pseudocode:
    //   int LoadVehicleEntries() {
    //     QueuePeek(&v8, v9);
    //     int i = 0, found = 0;
    //     for (int off = 0; off < 1936896; off += 18624, ++i) {
    //       if (LinkedListTraversalWithFilter(i, v8)) {
    //         SessionStateTransition(3, 0); TwoCallDelegation(v4+65);
    //         StringCopyWithBufferRealloc(v4+97); SetDriverName(v4+1); ++found;
    //       } else {
    //         SessionStateTransition(-1, 0);
    //       }
    //     }
    //     dword_5C329C = found - 1;
    //     BuildActiveVehiclePointerArray();
    //     dword_7CEC90 = 0; dword_7CED8C = 0; dword_7CEE88 = 0;
    //     dword_7D0990 = (found - 1) & ((found - 1 < 0) - 1);
    //     SceneDataParser(this[457] ? this[457] : byte_5EA438);
    //     AIW(0); byte_7C5690 = 1;
    //     return MultiplayerVehiclePlacement(&dword_7C569C, this[968]);
    //   }
    // UNRESOLVED: Globals unk_5EC6D0, dword_7D2E48 and unk_8AC368 are listed in the packet globals but are not referenced in the raw source body; purpose unconfirmed.
    // UNRESOLVED: v4 is the entry pointer returned by LinkedListTraversalWithFilter; the record layout (bytes at v4+65, v4+97, v4+1) and the meaning of the session-state values 3 and -1 are not established here.
    // UNRESOLVED: The stride 18624 and limit 1936896 imply 104 slots, but the slot-to-vehicle binding (whether slot equals the vehicle-grid index) is DERIVED.
}
