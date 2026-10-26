// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004412F0
// Canonical corpus name: WheelStateHistoryShift
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WheelStateHistoryShift_004412f0.c

void UnknownObject::WheelStateHistoryShift()
{
    // Shifts wheel-state history buffers forward by one frame. Copies the current slot of the three scalar buffers (this+0x1C5C/0x1C64, this+0x1E38/0x1E40, this+0x1E3C/0x1E44) to the previous slot, then iterates 4 per-wheel history blocks starting at this + 206 dwords (byte offset 0x338), advancing each block by 281 dwords. Inside every block it shifts four dword pairs forward and copies a 32-byte (0x20) sub-record from result + 22 dwords to result + 14 dwords. Returns the pointer one past the last processed block.
    // ASSIGNMENT: Capture second wheel-state buffer slot source: v1 = this[1818] (offset 0x1C68). [field:this:0x00001C68, source:raw]
    // ASSIGNMENT: Shift slot 0 of the second wheel-state buffer: this[1815] = this[1817] (offset 0x1C5C written from 0x1C64). [field:this:0x00001C5C, field:this:0x00001C64, source:raw]
    // ASSIGNMENT: this[1816] = v1 (offset 0x1C60 written from the captured slot source). [field:this:0x00001C60, source:raw]
    // ASSIGNMENT: Capture third wheel-state buffer slot 0: v2 = this[1936] (offset 0x1E40). [field:this:0x00001E40, source:raw]
    // ASSIGNMENT: this[1934] = v2 (offset 0x1E38 written from the captured slot 0 source). [field:this:0x00001E38, source:raw]
    // ASSIGNMENT: Capture third wheel-state buffer slot 1: v3 = this[1937] (offset 0x1E44). [field:this:0x00001E44, source:raw]
    // ASSIGNMENT: this[1935] = v3 (offset 0x1E3C written from the captured slot 1 source). [field:this:0x00001E3C, source:raw]
    // ASSIGNMENT: result = this + 206 (dword pointer base of the per-wheel history block, byte offset 0x338). [field:this:0x00000338, source:raw]
    // LOOP: do-while loop over 4 wheel history blocks, advancing result by 281 dwords and decrementing the counter each pass. [source:raw]
    // ASSIGNMENT: Shift block slot 0: result[0] = result[2] (offset 0x338 written from 0x340). [field:this:0x00000338, field:this:0x00000340, source:raw]
    // ASSIGNMENT: Shift block slot 1: result[1] = result[3] (offset 0x33C written from 0x344). [field:this:0x0000033C, field:this:0x00000344, source:raw]
    // ASSIGNMENT: Shift block slot 2: result[4] = result[6] (offset 0x348 written from 0x350). [field:this:0x00000348, field:this:0x00000350, source:raw]
    // ASSIGNMENT: Shift block slot 3: result[5] = result[7] (offset 0x34C written from 0x354). [field:this:0x0000034C, field:this:0x00000354, source:raw]
    // CALL: qmemcpy copies 0x20 bytes from result + 22 dwords to result + 14 dwords, shifting a 32-byte sub-record forward within the block. [source:raw]
    // CALCULATION: Advance result by 281 dwords (per-wheel block stride) and decrement the iteration counter. [source:raw]
    // RETURN: Return result pointing one past the last processed wheel history block. [source:raw]

    // Conservative worker pseudocode:
    //   // One-frame forward shift of the wheel-state history.
    //   _DWORD* sub_4412F0(_DWORD* this_) {
    //     this_[1815] = this_[1817];
    //     this_[1816] = this_[1818];
    //     this_[1934] = this_[1936];
    //     this_[1935] = this_[1937];
    //     _DWORD* result = this_ + 206;
    //     int n = 4;
    //     do {
    //       result[0] = result[2];
    //       result[1] = result[3];
    //       result[4] = result[6];
    //       result[5] = result[7];
    //       qmemcpy(result + 14, result + 22, 0x20);
    //       result += 281;
    //       --n;
    //     } while (n);
    //     return result;
    //   }
    // UNRESOLVED: Owner type and the full stride layout of the wheel-state history buffer are unresolved; the per-block stride (281 dwords), slot topology, and the 32-byte sub-record copy semantics are inferred from the loop.
    // UNRESOLVED: Called from StateAccumulateDelta (0x00441360) and PhysicsStepFrame (0x00441600); caller expectations for the returned pointer are outside this packet.
}
