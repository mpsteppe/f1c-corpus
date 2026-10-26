// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BFA00
// Canonical corpus name: AIPathPerformanceFunction
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AIPathPerformanceFunction_004bfa00.c

void UnknownObject::AIPathPerformanceFunction()
{
    // Builds a performance-ranked opponent list for AI path assignment: reads a roster size from the vehicle-setup object (ReadFieldAtOffset0x14 on dword_8AC36C), finds the vehicle matching a3 by name in the global vehicle array, seeds a random index, then repeatedly selects candidate vehicles with RandomVehicleSelector, skips already-selected names, appends float-keyed (GuardedListAccessor, sub_4BF6A0) nodes to the output list this, merge-sorts by float key, and returns the count selected.
    // GUARD: Read the roster field at offset +0x14 of the vehicle-setup object via ReadFieldAtOffset0x14(&dword_8AC36C); if it is <= 0, return 0 immediately. [callee:0x005871F0, global:0x008AC36C, source:raw]
    // LOOP: Scan the vehicle array (dword_8AC394 base, stride 1060) over dword_8AC390 entries, comparing each entry name (byte_5EA438 as null fallback) against a3 via sub_588410 to locate the target vehicle index. [global:0x008AC390, global:0x008AC394, global:0x005EA438, callee:0x00588410]
    // ASSIGNMENT: Allocate an 8-byte name node via OperatorNewNhMallocWrapper, copy the matched vehicle's name (entry+124) with StringCopyWithBufferRealloc, wrap it in a 12-byte list node, and append it to the selected-names list v34/v35/v36. [callee:0x00587C03, callee:0x00566650]
    // CALCULATION: Seed a random index: v38 = (2 * RandLCGRandomNumberGenerator(v6)) % v32. [callee:0x005884ED]
    // LOOP: While a2 > 0, select a candidate vehicle via RandomVehicleSelector(v38) and skip it if its name (+124) already appears in the selected-names list (compared via sub_588410, byte_5EA438 fallback). [callee:0x004C5070, callee:0x00588410, global:0x005EA438]
    // ASSIGNMENT: Allocate an 8-byte float-pair node via OperatorNewNhMallocWrapper, set first field from GuardedListAccessor(v38) and second from sub_4BF6A0(vehicle+188), wrap in a 12-byte node and append it to the output list this, updating head, tail, secondary and count fields. [callee:0x00587C03, callee:0x004C50E0, callee:0x004BF6A0, field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C]
    // ASSIGNMENT: Allocate another 8-byte name node for the selected vehicle's name (+124) with StringCopyWithBufferRealloc, wrap it via ShortComputation_ac20(node, data, 1), and append it to the selected-names list. [callee:0x00587C03, callee:0x00566650, callee:0x004BAC20]
    // CALCULATION: Advance the random index v38 = (RandLCGRandomNumberGenerator(v16) % 2 + v38 + 1) % v32; continue the selection loop while the pass counter stays <= 200 and the selection count is below a2. [callee:0x005884ED]
    // CALL: Merge-sort the output list by float key via MergeSortLinkedListByFloat and set this head and tail to the sorted list. [callee:0x004C2E20, field:this:0x00000000, field:this:0x00000004]
    // CALL: Free the temporary selected-names list via LinkedListDestructorWithData. [callee:0x004C2F20]
    // RETURN: Return v30, the number of vehicles selected into the output list. [function:0x004BFA00, source:raw]

    // Conservative worker pseudocode:
    //   if ReadFieldAtOffset0x14(&dword_8AC36C) <= 0: return 0
    //   find target vehicle by name (a3) in dword_8AC394 over dword_8AC390 entries; append its name to the selected-names list
    //   v38 = (2 * rand) % roster_size
    //   while a2 > 0 and passes <= 200: select vehicle at v38 via RandomVehicleSelector; skip if name already selected; append float-pair node (GuardedListAccessor, sub_4BF6A0) to output list; record name; advance v38
    //   merge-sort output list by float key; fix head/tail
    //   LinkedListDestructorWithData on selected-names list
    //   return selection count
    // UNRESOLVED: Meaning of the two float values stored per node (GuardedListAccessor value and sub_4BF6A0 audio/skill parameter) and which one is the merge-sort key.
    // UNRESOLVED: Significance of the 200-pass cap and the exact division of the output list between head/tail/secondary fields.
    // UNRESOLVED: Called from AIOpponentSelection (0x004BF790); caller-side context not in this packet.
}
