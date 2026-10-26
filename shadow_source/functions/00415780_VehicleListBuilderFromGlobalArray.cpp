// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00415780
// Canonical corpus name: VehicleListBuilderFromGlobalArray
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleListBuilderFromGlobalArray_00415780.c

void UnknownObject::VehicleListBuilderFromGlobalArray()
{
    // Clears the existing vehicle list held in this[0..3] by destroying and freeing each node, then rebuilds it from the global vehicle array (dword_8AC390 count, dword_8AC394 base, stride 1060): one 176-byte entry per vehicle, sub-struct arrays initialized with SmallEntryStructInit, text-format reset via TextFormatStructInitializer, driver path copied via StringCopyWithBufferRealloc, setup via sub_414600, and each entry appended as a 12-byte list node to the output list.
    // LOOP: Walk the existing list from *this, reading each node's next pointer at +4; if the node flag byte at +8 and its data pointer at +0 are both set, destroy the payload via StructDestructor(1), then free the node via FreeWrapper_7bcf. [field:*(obj+0x4):0x00000004, field:obj:0x00000000, field:obj:0x00000008, callee:0x00415900, callee:0x00587BCF, field:this:0x00000000]
    // ASSIGNMENT: Zero this[0..3] (list head, tail, secondary pointer, count) after cleanup. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C]
    // GUARD: Read dword_8AC390 (vehicle entry count); if it is <= 0, return 1 with an empty rebuilt list. [global:0x008AC390, source:raw]
    // LOOP: For each vehicle entry over dword_8AC390, allocate a 176-byte entry via OperatorNewNhMallocWrapper and initialize its sub-struct arrays with SmallEntryStructInit (direct calls and via sub_401000 array initializer). [callee:0x00587C03, callee:0x00415520, callee:0x00401000, global:0x00415520, global:0x008AC390, global:0x008AC394]
    // CALL: Reset the text-format block of each new entry via TextFormatStructInitializer. [callee:0x004149A0]
    // ASSIGNMENT: Copy the driver file path from vehicle+188 in the array via StringCopyWithBufferRealloc, store the current index into entry+8, and run entry setup via sub_414600(entry, 0). [callee:0x00566650, global:0x008AC394, callee:0x00414600]
    // ASSIGNMENT: Allocate a 12-byte list node via OperatorNewNhMallocWrapper wrapping the entry, and append it to the output list updating head, tail, secondary pointer and count. [callee:0x00587C03, field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C]
    // RETURN: Return 0 after a full rebuild, or 1 when the vehicle array was empty. [function:0x00415780, source:raw]

    // Conservative worker pseudocode:
    //   destroy and free every node in the existing list at *this
    //   zero this[0..3]
    //   if dword_8AC390 <= 0: return 1
    //   for each of dword_8AC390 entries: allocate 176-byte entry, init sub-struct arrays, reset text format, copy driver path (vehicle+188), run sub_414600, append as 12-byte list node
    //   return 0
    // UNRESOLVED: Exact layout of the 176-byte entry beyond sub-struct arrays, text-format block, driver path and the index field at +8.
    // UNRESOLVED: Semantics of sub_414600(entry, 0) setup and the constant 0 argument.
    // UNRESOLVED: The return value 1 on the empty-array path versus 0 on success suggests a status code whose callers (ShortComputation_5090, 0x00415090) are outside this packet.
}
