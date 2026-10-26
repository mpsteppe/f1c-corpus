// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BDFE0
// Canonical corpus name: MatrixClear
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MatrixClear_004bdfe0.c

void UnknownObject::MatrixClear()
{
    // Clears an 8x8 grid matrix stored inside the owner object. Each cell is a dword at a stride of 9 dwords (first cell at this + 0x4), so the clear covers 64 cells; afterwards the cell counter at this[577] (byte offset 0x904) is reset to 0. Runs per-frame on the frame path via caller LoopWithConditionalSkipFunction (0x00410980).
    // ASSIGNMENT: Initialize the matrix walk pointer to this + 1 (byte offset 0x4), the first grid cell entry. [source:raw, field:this:0x00000004]
    // LOOP: Outer loop over 8 rows using a countdown counter seeded from 8. [source:raw]
    // LOOP: Inner loop over 8 columns per row using a countdown counter seeded from 8. [source:raw]
    // ASSIGNMENT: Write 0 to the current grid cell (the strided entry beginning at this + 0x4). [source:raw, field:this:0x00000004]
    // CALCULATION: Advance the cell pointer by 9 dwords (stride 9) to reach the next column cell. [source:raw]
    // ASSIGNMENT: Reset the cell count at this[577] (byte offset 0x904) to 0. [source:raw, field:this:0x00000904]
    // RETURN: Return the one-past-last cell pointer. [source:raw]
    // CALL: Invoked per-frame by LoopWithConditionalSkipFunction (0x00410980) to clear the matrix on the frame path. [caller:0x00410980, source:raw]

    // Conservative worker pseudocode:
    //   void MatrixClear(_DWORD *this) {
    //     _DWORD *p = this + 1;                // this + 0x4, first cell
    //     for (int row = 0; row < 8; ++row)
    //       for (int col = 0; col < 8; ++col) { *p = 0; p += 9; }
    //     this[577] = 0;                       // this + 0x904, cell counter
    //     // returns the one-past-last cell pointer
    //   }
    // UNRESOLVED: Why the 8x8 grid uses a stride of 9 dwords (one extra dword per row) is unresolved from this packet.
    // UNRESOLVED: Owner class is unknown; the caller LoopWithConditionalSkipFunction (0x00410980) supplies the this pointer on the frame path.
}
