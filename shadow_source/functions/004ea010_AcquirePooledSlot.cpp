// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004EA010
// Canonical corpus name: ArithmeticComparison_a010
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_a010_004ea010.c

void UnknownObject::AcquirePooledSlot()
{
    // Fixed-capacity pool slot allocator. Returns a pointer to one slot of a 32-entry static array (stride 56 bytes starting at unk_8AD3F8), using the global counter dword_8ADAF8 as the next free index and post-incrementing it. Once the counter reaches 32 the pool is exhausted and the function returns a fixed overflow buffer (unk_8ADAC0). Used by collision detection paths that need temporary per-call records.
    // GUARD: Guard on dword_8ADAF8 >= 32: when the pool counter has reached capacity, return the fixed overflow buffer &unk_8ADAC0 instead of a pooled slot. [global:0x008ADAF8, global:0x008ADAC0, source:raw]
    // RETURN: Pooled path: return &unk_8AD3F8 + 56 * dword_8ADAF8, then post-increment the pool counter dword_8ADAF8 so the next call takes the following slot. [global:0x008ADAF8, global:0x008AD3F8, source:raw]
    // CALL: Consumed by F_3DCollisionDetectionWithAABBTestAndContactResp (0x004EA040) and CollisionDetectionSystem (0x004EA970) to acquire temporary collision records. [caller:0x004EA040, caller:0x004EA970, source:raw]

    // Conservative worker pseudocode:
    //   char *sub_4EA010() {
    //     if (dword_8ADAF8 >= 32)
    //       return (char *)&unk_8ADAC0;
    //     return (char *)&unk_8AD3F8 + 56 * dword_8ADAF8++;
    //   }
    // UNRESOLVED: Element type of the 32-entry pool at unk_8AD3F8 is unknown; the 56-byte stride is derived from the source arithmetic, not from a named struct.
    // UNRESOLVED: Purpose of the shared overflow buffer unk_8ADAC0 is unknown; it is returned for every allocation after the pool is exhausted.
    // UNRESOLVED: No reset path is visible in this function; whoever resets dword_8ADAF8 is not shown here.
    // UNRESOLVED: Slots are not individually tracked as in-use; the counter alone selects the next slot.
}
