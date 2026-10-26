// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00560B30
// Canonical corpus name: ConditionalFreeOfStructField
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalFreeOfStructField_00560b30.c

void UnknownObject::ConditionalFreeOfStructField()
{
    // __thiscall teardown helper: reads this[107] (offset 0x1AC), and only when it is non-null frees the allocation through FreeWrapper_7bcf (0x00587BCF) and zeroes the field. Returns the previous pointer value. Used by ResourceCleanupDestructionForDirectXObjects during DirectX object cleanup.
    // ASSIGNMENT: Read this[107] (offset 0x1AC) into result as the existing pointer value. [field:this:0x000001AC, source:raw]
    // GUARD: Guard on this[107] (offset 0x1AC): when null, skip the free and return null. [field:this:0x000001AC, source:raw]
    // CALL: Free the allocation via FreeWrapper_7bcf (0x00587BCF) with this[107] as the memory pointer. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero this[107] (offset 0x1AC) after freeing so the field is cleared. [field:this:0x000001AC, source:raw]
    // RETURN: Return the prior pointer value (result), which is non-null only when a free occurred. [source:raw]
    // CALL: Called by ResourceCleanupDestructionForDirectXObjects (0x00543BF0) as part of DirectX resource teardown. [caller:0x00543BF0, source:raw]

    // Conservative worker pseudocode:
    //   LPVOID ConditionalFreeOfStructField(LPVOID *this) {
    //     LPVOID result = this[107];
    //     if (result) {
    //       result = (LPVOID)FreeWrapper_7bcf(this[107]);
    //       this[107] = 0;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The owning class of `this` is unknown; offset 0x1AC is only proven to hold a heap pointer freed here.
    // UNRESOLVED: The return value is the freed pointer; whether callers use it (e.g. as a stale-pointer guard) is caller-dependent.
}
