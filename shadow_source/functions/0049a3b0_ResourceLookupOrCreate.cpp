// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049A3B0
// Canonical corpus name: ResourceLookupOrCreate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ResourceLookupOrCreate_0049a3b0.c

void UnknownObject::ResourceLookupOrCreate()
{
    // Normalizes the input string via sub_589901, rejects it when sub_49A520 validation fails (returns -1), converts it to an array index with CharToIndexConversion, allocates a 28-byte node through OperatorNewNhMallocWrapper, initializes it with PatternedFieldInit, processes the source string and parameter a3 through ThunkToFUN00566650 and FunctionCallWrapper_a2e0, then inserts the new node at this[index], appending to the existing list tail (walking the offset 24 next pointer) when the slot is already occupied. Returns the index, or -1 on failure.
    // CALL: Call sub_589901(lpSrcStr) to normalize or initialize the source string. [callee:0x00589901, source:raw]
    // GUARD: Guard on sub_49A520(lpSrcStr) being non-zero: validation failure path. [callee:0x0049A520, source:raw]
    // RETURN: When the validation guard is true, return -1 without allocating. [callee:0x0049A520, source:raw]
    // CALL: Call CharToIndexConversion(lpSrcStr); its return value becomes the index into the this array. [callee:0x0049A330, source:raw]
    // GUARD: Guard on the converted index being != -1; when it is -1 the function returns it directly. [callee:0x0049A330, source:raw]
    // ASSIGNMENT: Read v6 = this[index], the array slot content at the converted index. [source:raw]
    // CALL: Call OperatorNewNhMallocWrapper(28) to allocate a 28-byte node. [callee:0x00587C03, source:raw]
    // GUARD: Guard on the allocation result v7 being non-null; on success v8 = PatternedFieldInit(v7), on failure v8 = 0. [callee:0x0049A250, source:raw]
    // CALL: Call PatternedFieldInit(v7) to initialize the new 28-byte node. [callee:0x0049A250, source:raw]
    // CALL: Call ThunkToFUN00566650(lpSrcStr), processing the source string. [callee:0x0049A2C0, source:raw]
    // CALL: Call FunctionCallWrapper_a2e0(a3), processing parameter a3. [callee:0x0049A2E0, source:raw]
    // GUARD: Branch on v6 (the pre-existing slot content): non-null means a list already occupies the slot, null means the slot is free. [source:raw]
    // LOOP: When the slot holds a list, walk from v6 following the next pointer at offset 24 (i = *(v6+24); i; i = *(i+24)) to reach the list tail. [source:raw]
    // ASSIGNMENT: Append the new node: write v8 at the tail's next-pointer slot, *(v6+24) = v8. [source:raw]
    // ASSIGNMENT: When the slot was empty, store the node directly at the array slot: this[index] = v8. [source:raw]
    // RETURN: Return the converted index (v5) on both successful insertion paths. [source:raw]

    // Conservative worker pseudocode:
    //   unsigned int ResourceLookupOrCreate(_DWORD* this, LPCSTR key, int a3) {
    //     sub_589901(key);
    //     if (sub_49A520(key)) return -1;
    //     unsigned int index = CharToIndexConversion(key);
    //     if (index != -1) {
    //       int slot = this[index];
    //       int node = OperatorNewNhMallocWrapper(28) ? PatternedFieldInit(v7) : 0;
    //       ThunkToFUN00566650((int)key);
    //       FunctionCallWrapper_a2e0(a3);
    //       if (slot) {
    //         for (int i = *(slot + 24); i; i = *(i + 24)) slot = i;
    //         *(slot + 24) = node;
    //       } else {
    //         this[index] = node;
    //       }
    //       return index;
    //     }
    //     return index;
    //   }
    // UNRESOLVED: The meaning of the sub_49A520 validation and why failure maps to -1 is unknown.
    // UNRESOLVED: The purpose of ThunkToFUN00566650(lpSrcStr) and FunctionCallWrapper_a2e0(a3) is not established beyond that they process the string and a3.
    // UNRESOLVED: The layout of the 28-byte node (PatternedFieldInit) and the list-next pointer at offset 24 are not further described by the packet.
    // UNRESOLVED: The owning object is unknown; slot-indexed insertion with per-slot linked lists suggests a hash or name-to-resource table, which is DERIVED and unproven.
    // UNRESOLVED: Caller StringReverseCopyLookup (0x0049A490) is recorded but its call context is not in the packet.
}
