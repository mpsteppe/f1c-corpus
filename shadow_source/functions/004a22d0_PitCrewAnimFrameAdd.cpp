// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A22D0
// Canonical corpus name: sub_4A22D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4A22D0_004a22d0.c

void UnknownObject::PitCrewAnimFrameAdd()
{
    // Adds one animation frame entry to the owning object's array of 28-byte pit-crew animation elements. Allocates a grown array (4-byte count header plus (this[28]+1) elements of 28 bytes), constructs each new slot with FunctionCallWrapper_1fb0, copies the existing elements from this+0x74 into it, zeroes each old element's scratch slot, destroys the old elements with ShortComputation_d4d0 and frees the old array with its header via FreeWrapper_7bcf. Then stores the grown pointer at this+0x74, allocates the new last element's scratch buffer (4 * this[26] bytes), and populates it per entry: sub_5518A0 converts a3 to a string handle, sub_551560 checks its validity, and WideStringComparisonWalkingLinkedList(a2) walks the wide-string linked list whose result is stored into the scratch slot. On the first entry only it also stores a5, a float read from the string handle at +8, and the PitCrewAnimationStringMapper(a4) animation ID (or literal 24 when a4 is null). When the population loop breaks early it logs a cube loading error via StringRelocationCopy + StringSplitLoop + DebugLogWrite. The element count this+0x70 is only incremented when every entry was populated.
    // ASSIGNMENT: Load the global dword_8AFE88 (0x008AFE88) into the local v27; the raw source never reads v27 afterward, so this is a dead store. [global:0x008AFE88, source:raw]
    // GUARD: Outer guard on this+0x64 (dword this[25]): when zero the entire function body is skipped and 0 is returned; non-zero means the owning object is initialized. [field:this:0x00000064, source:raw]
    // ASSIGNMENT: Compute the grown element count v6 = this[28] + 1, where this[28] is the dword at this+0x70 (current number of 28-byte animation elements). [field:this:0x00000070, source:raw]
    // CALL: Allocate the grown element array: OperatorNewNhMallocWrapper(28 * v6 + 4) reserves a 4-byte count header plus v6 elements of 28 bytes each. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Store v6 into the new array's header (*v7 = v6) so the element pointer v8 = v7 + 1 points at the first element; on allocation failure v8 is null. [source:raw]
    // LOOP: Call FunctionCallWrapper_1fb0 once per new element to default-construct the 28-byte slot, advancing the element pointer by 28 bytes per iteration. [callee:0x004A1FB0, source:raw]
    // GUARD: Copy-loop guard: when this+0x70 (this[28], the existing element count) is greater than 0 the old elements are copied into the grown array. [guard:1, field:this:0x00000070, source:raw]
    // LOOP: For each existing element (28 bytes, seven dwords) copy it with qmemcpy from the old array at this+0x74 (this[29]) into the new array, and zero the old element's +20 scratch-pointer slot before the old elements are destroyed. [field:this:0x00000074, source:raw]
    // GUARD: Old-array guard: when this[29] (this+0x74) is non-null the previous element array exists and must be destroyed and freed. [field:this:0x00000074, source:raw]
    // LOOP: Destroy the old elements in reverse order: ShortComputation_d4d0 runs on each 28-byte element while the cursor walks back from the array end to the start. [callee:0x004DD4D0, source:raw]
    // CALL: Free the old array including its count header via FreeWrapper_7bcf(old_ptr - 4). [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Compute the scratch-buffer byte size v24 = 4 * this[26] (this+0x68, entries per frame, one dword per entry) and store the new element pointer v8 into this+0x74 (this[29]). [field:this:0x00000068, field:this:0x00000074, source:raw]
    // CALL: Allocate the new last element's scratch buffer with OperatorNewNhMallocWrapper(v24) and store it into the +20 slot of the appended element at 28 * this[28] bytes into the array at this+0x74. [callee:0x00587C03, field:this:0x00000070, field:this:0x00000074, source:raw]
    // GUARD: Population-loop guard: when this+0x68 (this[26], entries per frame) is greater than 0 the per-entry data-population loop runs. [guard:0, field:this:0x00000068, source:raw]
    // LOOP: For each entry index v18 in [0, this[26]) populate the new element's scratch buffer: the current dword slot is zeroed first, then filled as described in the following operations. [field:this:0x00000068, source:raw]
    // CALL: sub_5518A0(&v25, a3, 0) converts the frame argument a3 into a string-handle object v25; returning -1 aborts the population loop. [callee:0x005518A0, source:raw]
    // GUARD: Abort guard: break out of the population loop when sub_5518A0 returns -1 or sub_551560(v25) reports the converted string handle as invalid. [callee:0x005518A0, callee:0x00551560, source:raw]
    // CALL: WideStringComparisonWalkingLinkedList(a2) walks the wide-string linked list identified by a2 and the returned value is stored into the current scratch slot (scratch + 4 * v18). [callee:0x00551830, source:raw]
    // ASSIGNMENT: On the first entry only (v18 == 0) initialize the new element: element +12 = a5, element +16 (float) = *(float*)(v25 + 8), and element +24 = PitCrewAnimationStringMapper(a4) when a4 is non-null, else the literal 24. [callee:0x004A24D0, source:raw]
    // CALL: PitCrewAnimationStringMapper(a4) maps the animation-name string a4 to its animation type ID for storage at element +24. [callee:0x004A24D0, source:raw]
    // STATE_TRANSITION: Advance v18; when v18 reaches this[26] the element is fully populated and control jumps to LABEL_27; an early break lands on the loading-error path below. [field:this:0x00000068, source:raw]
    // CALL: Error path: StringRelocationCopy(0, v28) prepares a 256-byte message buffer for the loading-error report. [callee:0x0053C5B0, source:raw]
    // GUARD: Error-path guard: when StringSplitLoop(1, aDDevF119992002_2, 327) succeeds in formatting the device-path string, the debug-log write follows. [callee:0x004D7A50, global:0x005CD174, source:raw]
    // CALL: DebugLogWrite(&dword_8AD25C, aCubeErrorLoadi_0) logs the cube loading error message using the debug message buffer. [callee:0x004D7AA0, global:0x008AD25C, global:0x005CD19C, source:raw]
    // STATE_TRANSITION: LABEL_27: only when v18 == this[26] (every entry populated) is the element count this+0x70 (this[28]) incremented; a partial fill does not count as a new element. [field:this:0x00000070, source:raw]
    // RETURN: Return 0 on every path. [source:raw]

    // Conservative worker pseudocode:
    //   int PitCrewAnimFrameAdd(_DWORD* this, int a2, int a3, const CHAR* a4, int a5) {
    //     if (!this[25]) return 0;
    //     int count = this[28] + 1;
    //     int* arr = OperatorNewNhMallocWrapper(28 * count + 4);
    //     if (arr) {
    //       arr[0] = count;
    //       for (int i = 0; i < count; i++) FunctionCallWrapper_1fb0(arr + 1 + 7 * i);
    //     }
    //     if (this[28] > 0)
    //       for (int i = 0; i < this[28]; i++) { memcpy(arr + 1 + 7 * i, (int*)this[29] + 7 * i, 28); ((int*)this[29])[7 * i + 5] = 0; }
    //     if (this[29]) {
    //       for (int i = ((int*)this[29])[-1] - 1; i >= 0; i--) ShortComputation_d4d0((int*)this[29] + 7 * i);
    //       FreeWrapper_7bcf((int*)this[29] - 1);
    //     }
    //     this[29] = arr;
    //     ((int*)arr)[1 + 7 * this[28] + 5] = OperatorNewNhMallocWrapper(4 * this[26]);
    //     int v18 = 0;
    //     if (this[26] > 0) {
    //       while (1) {
    //         int scratch = ((int*)this[29])[1 + 7 * this[28] + 5];
    //         scratch[v18] = 0;
    //         if (sub_5518A0(&v25, a3, 0) == -1 || sub_551560(v25)) break;
    //         scratch[v18] = WideStringComparisonWalkingLinkedList(a2);
    //         if (v18 == 0) {
    //           ((int*)this[29])[1 + 7 * this[28] + 3] = a5;
    //           *(float*)((char*)this[29] + 28 * this[28] + 16) = *(float*)(v25 + 8);
    //           ((int*)this[29])[1 + 7 * this[28] + 6] = a4 ? PitCrewAnimationStringMapper(a4) : 24;
    //         }
    //         if (++v18 >= this[26]) goto LABEL_27;
    //       }
    //       StringRelocationCopy(0, v28);
    //       if (StringSplitLoop(1, aDDevF119992002_2, 327))
    //         DebugLogWrite(&dword_8AD25C, aCubeErrorLoadi_0);
    //     }
    //   LABEL_27:
    //     if (v18 == this[26]) this[28]++;
    //     return 0;
    //   }
    // UNRESOLVED: The global dword_8AFE64 (0x008AFE64) is recorded as read by the packet but never appears in the raw source body; its role is unknown.
    // UNRESOLVED: The global dword_8AFE88 (0x008AFE88) is loaded into v27 which the raw source never uses (dead store); the existing analysis labels it CollisionGeometryHandle at DERIVED trust, not adopted here.
    // UNRESOLVED: The exact roles of the arguments a2 (wide-string linked list), a3 (frame string), a4 (animation name) and a5 come from the existing analysis fill at DERIVED trust; the raw source alone does not name them.
    // UNRESOLVED: The field this+0x64 is described in the existing analysis as an initialized/3D-sound-source-pointer flag (DERIVED); only its non-zero guard role is evidenced by the raw source.
    // UNRESOLVED: The packet classifies field this+0x70 as read-only, but the raw source also increments it at LABEL_27 (element count + 1), so the write is grounded in source:raw rather than the packet's rw flag.
    // UNRESOLVED: The semantics of sub_5518A0 (string-handle construction), sub_551560 (handle validity), WideStringComparisonWalkingLinkedList (linked-list walk) and sub_551560's return interpretation are established only from the existing analysis names, not independently.
}
