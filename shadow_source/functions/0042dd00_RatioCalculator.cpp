// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042DD00
// Canonical corpus name: RatioCalculator
// Owner: UnknownObject [DERIVED]
// Raw source: functions/RatioCalculator_0042dd00.c

void UnknownObject::RatioCalculator()
{
    // Computes a weighted ratio from a two-dimensional lookup table. Takes a row index a2 and a column index a3, bounds-checks them against the row count this[0] and column count this[2], reads an 8-byte table entry per axis from the row array this[1] and column array this[3] (base value at offset +0, weight at offset +4), and returns (scaleFactor * rowWeight * colWeight) / (rowBase * colBase * divisor) when the divisor this[4] is positive. Returns 0.0 on any failed bounds check or non-positive base/divisor value. Name carried by the legacy ABI symbol (RatioCalculator); existing analysis describes it as a 2D table ratio calculator used by session-state indexed lookup and vehicle setup value formatting.
    // GUARD: Row index lower bound: if a2 < 0, return 0.0 (zero sentinel from the read-only double global dbl_59E430). [source:raw, global:0x0059E430]
    // GUARD: Row index upper bound: if a2 >= this[0] row count, return 0.0. [field:this:0x00000000, source:raw]
    // GUARD: Column index lower bound: if a3 < 0, return 0.0. [source:raw]
    // GUARD: Column index upper bound: if a3 >= this[2] column count, return 0.0. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Resolve the row entry: row array base = this[1], entry at base + 8*a2, and read its base value v4 (offset +0). [field:this:0x00000004, source:raw]
    // GUARD: If the row entry base value v4 is <= 0, return 0.0. [source:raw]
    // ASSIGNMENT: Resolve the column entry: column array base = this[3], entry at base + 8*a3, and read its base value v7 (offset +0). [field:this:0x0000000C, source:raw]
    // GUARD: If the column entry base value v7 is <= 0, return 0.0. [source:raw]
    // GUARD: If the divisor this[4] is <= 0, return 0.0. [field:this:0x00000010, source:raw]
    // CALCULATION: Compute the weighted ratio: (this[5] scale * rowWeight(+4) * colWeight(+4)) / (rowBase * colBase * this[4] divisor). [field:this:0x00000014, source:raw]
    // RETURN: Return the computed ratio, or 0.0 when any of the guards fails. [source:raw]

    // Conservative worker pseudocode:
    //   double RatioCalculator(Table2D *t, int row, int col) {
    //     if (row < 0 || row >= t->rowCount) return 0.0;
    //     if (col < 0 || col >= t->colCount) return 0.0;
    //     int rowBase = *(int *)(t->rowArray + 8 * row);
    //     int colBase = *(int *)(t->colArray + 8 * col);
    //     if (rowBase <= 0 || colBase <= 0) return 0.0;
    //     if (t->divisor <= 0) return 0.0;
    //     int rowWeight = *(int *)(t->rowArray + 8 * row + 4);
    //     int colWeight = *(int *)(t->colArray + 8 * col + 4);
    //     return (double)(t->scale * rowWeight * colWeight) / (double)(rowBase * colBase * t->divisor);
    //   }
    // UNRESOLVED: The exact meaning of the +0 base and +4 weight fields of each 8-byte table entry (which quantity is a base, which a weight) is inferred from the ratio formula and not independently evidenced.
    // UNRESOLVED: dbl_59E430 is read by the function; its precise role (zero constant backing the early-return guards) is inferred, and its exact position in the guard sequence is unknown.
    // UNRESOLVED: The class owning this table and the table's population path are not evidenced in this packet.
}
