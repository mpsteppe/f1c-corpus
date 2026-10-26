// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042ED00
// Canonical corpus name: SessionStateIndexedLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SessionStateIndexedLookup_0042ed00.c

void UnknownObject::SessionStateIndexedLookup()
{
    // Computes a weighted ratio via RatioCalculator (0x0042DD00) using a table base at this+1628, a row index this[16*a2+753] and a column index this[1425] (offset 0x1644). When a2 equals 43 the result is negated before return. Called by brake, tire and suspension physics lookup code.
    // CALL: Call RatioCalculator(this + 1628, this[16 * a2 + 753], this[1425] / this[0x1644]) to compute the weighted ratio [callee:0x0042DD00, field:this:0x00001644, source:raw]
    // GUARD: If a2 == 43, negate the RatioCalculator result [source:raw]
    // RETURN: Return -result when a2 == 43, otherwise return result unchanged [source:raw]

    // Conservative worker pseudocode:
    //   double SessionStateIndexedLookup(int *this, int a2) {
    //     double result = RatioCalculator(this + 1628, this[16 * a2 + 753], this[1425]);
    //     if (a2 == 43) return -result;
    //     return result;
    //   }
    // UNRESOLVED: Semantics of the row-index array this[16*a2+753] and table base this+1628 are not evidenced by a field record.
    // UNRESOLVED: Meaning of the special index a2 == 43 (negation) is not established.
}
