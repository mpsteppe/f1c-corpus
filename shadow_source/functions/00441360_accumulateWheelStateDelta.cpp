// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00441360
// Canonical corpus name: StateAccumulateDelta
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateAccumulateDelta_00441360.c

void UnknownObject::accumulateWheelStateDelta()
{
    // Shifts wheel state history buffers, then for each wheel (count from field +0x162C) computes the delta between the current wheel state (48-byte stride array) and the previous wheel state (580-byte stride array) for three position components (+308/+316/+324) and three velocity components (+332/+340/+348), accumulating each delta back into the previous-state buffer so the per-frame change is stored for later interpolation.
    // CALL: Call WheelStateHistoryShift(this) to shift wheel state history buffers forward. [callee:0x004412F0, source:raw]
    // CALL: Call BatchIterationWithCounter(this + 1387 words) to obtain the iteration count for the wheel processing loop. [callee:0x0056F060, source:raw]
    // ASSIGNMENT: Load wheel state count from field +0x162C into v3. [field:this:0x0000162C, source:raw]
    // GUARD: If wheel count (v3) is greater than 0, process each wheel; otherwise skip the loop. [field:this:0x0000162C, source:raw]
    // LOOP: Loop over wheels while v3 is non-zero; advance current-state offset by 48 bytes and previous-state offset by 580 bytes each iteration. [field:this:0x000015AC, field:this:0x000015B0, source:raw]
    // CALCULATION: Compute position deltas: current state value minus previous state value for components at previous offsets +308, +316, +324. [field:this:0x000015AC, field:this:0x000015B0, source:raw]
    // CALCULATION: Compute velocity deltas: current state value minus previous state value for components at previous offsets +332, +340, +348. [field:this:0x000015AC, field:this:0x000015B0, source:raw]
    // ASSIGNMENT: Accumulate each computed delta back into the previous wheel state buffer (+308, +316, +324, +332, +340, +348). [field:this:0x000015B0, source:raw]
    // RETURN: Return the last computed result value. [source:raw]

    // Conservative worker pseudocode:
    //   WheelStateHistoryShift(this);
    //   count = BatchIterationWithCounter(this + 1387);
    //   for (off = 0, prevOff = 0; count > 0; --count, off += 48, prevOff += 580) {
    //     prev = prevOff + this->prevState;
    //     cur = off + this->curState;
    //     prev[308] += cur[0] - prev[308];
    //     prev[316] += cur[8] - prev[316];
    //     prev[324] += cur[16] - prev[324];
    //     prev[332] += cur[24] - prev[332];
    //     prev[340] += cur[32] - prev[340];
    //     prev[348] += cur[40] - prev[348];
    //   }
    // UNRESOLVED: Absolute indices this[1387], this[1388], this[1419] map to byte offsets +0x15AC, +0x15B0, +0x162C respectively; the pairing of the current-state array at +0x15AC with the loop's 48-byte stride and previous-state array at +0x15B0 with the 580-byte stride is inferred from the loop increments.
}
