// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048EA20
// Canonical corpus name: sub_48EA20
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_48EA20_0048ea20.c

void UnknownObject::IntPairFieldSetter()
{
    // Trivial pair setter: stores integer arguments a2 and a3 into struct fields this[5] (offset 0x14) and this[6] (offset 0x18), then returns a2 unchanged. No branches and no callees.
    // ASSIGNMENT: Store the first argument a2 into this[5] (byte offset 0x14). [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Store the second argument a3 into this[6] (byte offset 0x18). [field:this:0x00000018, source:raw]
    // RETURN: Return the first argument a2 unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   int IntPairFieldSetter(void *this, int a2, int a3) {
    //     this[5] = a2;
    //     this[6] = a3;
    //     return a2;
    //   }
    // UNRESOLVED: Semantic meaning of the two stored values (x/y position or size pair) is inferred from the caller UITileGrid (0x0048F870) and is not established by evidence in this function.
    // UNRESOLVED: Why the first argument is returned while the second is not is unresolved.
}
