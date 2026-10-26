// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BF790
// Canonical corpus name: AIOpponentSelection
// Owner: AIOpponentSelection [DERIVED]
// Raw source: functions/AIOpponentSelection_004bf790.c

void AIOpponentSelection::BuildOpponentList()
{
    // Builds a linked list of AI opponent candidates. Logs a 'NotAI' debug line, optionally short-circuits through AIPathPerformanceFunction for a2 <= 10, then randomly walks the vehicle roster (modulo the roster count read from a global) selecting candidates. Each accepted candidate gets an 8-byte node (an accessor value plus a float parameter computed by sub_4BF6A0) wrapped in a 12-byte linked-list node that is appended to a head/tail/iter/count list stored on 'this'. After selection the list is counted, split at its midpoint, and the two halves are merge-sorted by the float value at node+4, then the sorted head is written back to 'this'. Returns the number of candidates appended.
    // ASSIGNMENT: Initialize the appended-candidate counter to 0. [source:raw]
    // CALL: Reset the list state on 'this' via sub_4BF730 before building. [callee:0x004BF730]
    // CALL: Format a debug line into the local buffer using the format string from global aSNotNotai ('%s NOT: NotAI') with argument a4. [global:0x005D266C, callee:0x0058815F]
    // CALL: Report the formatted 'NotAI' message via sub_4C4D50. [callee:0x004C4D50]
    // GUARD: When a2 <= 10 and AIPathPerformanceFunction(a2, a3) returns a2, return a2 immediately without building a list. [callee:0x004BFA00, source:raw]
    // ASSIGNMENT: Read the roster candidate count through ReadFieldAtOffset0x14 applied to global dword_8AC36C and remember it for later loops. [callee:0x005871F0, global:0x008AC36C]
    // CALCULATION: Compute a random starting roster index: 2 * RandLCGRandomNumberGenerator() modulo the roster count. [callee:0x005884ED]
    // GUARD: Only build when the roster count is positive and a2 is positive. [source:raw]
    // LOOP: Iterate selecting candidates until the appended count reaches a2, advancing the roster index cyclically by 1 modulo the count each iteration. [source:raw]
    // CALL: Pick a candidate vehicle via RandomVehicleSelector at the current roster index. [callee:0x004C5070]
    // ASSIGNMENT: Fall back to the default name global byte_5EA438 when the candidate slot exposes no name pointer. [global:0x005EA438]
    // CALL: Accept the candidate when sub_588410(vehicle name, a3) is true or the roster has fewer than 2 entries. [callee:0x00588410]
    // CALL: Allocate an 8-byte candidate node via OperatorNewNhMallocWrapper(8), initialized with a NaN float value and 0.0. [callee:0x00587C03]
    // ASSIGNMENT: Store GuardedListAccessor(roster index) as the candidate node's value field. [callee:0x004C50E0]
    // CALL: Compute the candidate's float parameter with sub_4BF6A0 on the candidate data at offset 188. [callee:0x004BF6A0]
    // CALL: Allocate a 12-byte linked-list node via OperatorNewNhMallocWrapper(12), holding the candidate node pointer plus next-pointer and active-flag fields. [callee:0x00587C03]
    // STATE_TRANSITION: Append the new list node: when the head at this+0x0 is empty set head and iter to it, otherwise link the current tail's next pointer; then update the tail pointer at this+0x4 and increment the count at this+0xC. The tail's own next pointer is the node-level next field. [field:this:0x00000000, field:this:0x00000004, field:this:0x0000000C, field:obj:0x00000004, field:*(obj+0x4):0x00000004]
    // CALCULATION: Count the list length by walking the node-level next pointers from the head. [field:*(*(obj+0x4)+0x4):0x00000004]
    // GUARD: Only merge-sort when the counted list length is at least 2. [source:raw]
    // CALCULATION: Split the list into two halves at the midpoint node and sever the link between them. [source:raw]
    // CALL: Merge-sort each half with MergeSortLinkedListByFloat, then merge the two sorted runs by comparing the float value stored at the node pointer target's +4 field. [callee:0x004C2E20]
    // STATE_TRANSITION: Write the sorted head back to this+0x0, walk to the last node to set the tail at this+0x4, and reset the iter pointer at this+0x8 to the sorted head. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008]
    // RETURN: Return the number of candidates appended during selection. [source:raw]

    // Conservative worker pseudocode:
    //   int BuildOpponentList(AIOpponentSelection *this, int a2, int a3, const char *a4) {
    //     int appended = 0;
    //     ResetList(this);
    //     StringFormatWithBufferOverflowCheck(buf, "%s NOT: NotAI", a4);
    //     ReportMessage(buf);
    //     if (a2 <= 10 && AIPathPerformanceFunction(a2, a3) == a2) return a2;
    //     int count = ReadFieldAtOffset0x14(&rosterGlobal);
    //     int idx = 2 * RandLCGRandomNumberGenerator() % count;
    //     if (count > 0 && a2 > 0) {
    //       do {
    //         candidate = RandomVehicleSelector(idx);
    //         name = *candidate ? *(char**)candidate : defaultName;
    //         if (sub_588410(name, a3) || count < 2) {
    //           node8 = Alloc(8); node8[0] = GuardedListAccessor(idx); node8[1] = sub_4BF6A0(candidate + 188);
    //           node12 = Alloc(12); node12[0] = node8; node12[1] = 0; node12[2] = 1;
    //           AppendNode(this, node12);
    //           ++appended;
    //         }
    //         idx = (idx + 1) % count;
    //       } while (appended < a2);
    //       SortListByFloatValue(this);
    //     }
    //     return appended;
    //   }
    // UNRESOLVED: Subsystem relation between sub_4C4D50 (message reporting), sub_4BF730 (list reset) and the candidate float parameter produced by sub_4BF6A0.
    // UNRESOLVED: Whether AIPathPerformanceFunction early return represents an already-configured grid or an AI-performance short-circuit.
    // UNRESOLVED: Meaning of the byte/active flag at node+8 of the 12-byte list node.
}
