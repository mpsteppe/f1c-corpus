// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00414140
// Canonical corpus name: DecrementCounterWithFloorAtZero
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DecrementCounterWithFloorAtZero_00414140.c

void UnknownObject::DecrementCounterWithFloorAtZero()
{
    // Decrements the int counter stored at this+8, flooring at 0: reads the current value, and only when it is > 0 writes back value-1 and returns it. Used by the font rendering path (FontRenderingPrep, FontCharacterRenderDispatcher), consistent with a reference count or outstanding-work counter on a font object.
    // ASSIGNMENT: result = *(int*)(a1 + 8): load current counter value [source:raw, field:this:0x00000008]
    // GUARD: if (result > 0): store (result - 1) back to a1+8 and decrement the local copy [source:raw, field:this:0x00000008]
    // RETURN: return the (possibly decremented) counter value [source:raw]

    // Conservative worker pseudocode:
    //   int DecrementCounterWithFloorAtZero(int obj) {
    //     int n = *(int*)(obj + 8);
    //     if (n > 0) *(int*)(obj + 8) = --n;
    //     return n;
    //   }
    // UNRESOLVED: Counter at obj+8 is not named; field owner object type is UNKNOWN
    // UNRESOLVED: Callers are font-related but the counter's exact purpose (refcount vs pending-work) is not evidenced
}
