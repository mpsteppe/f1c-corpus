// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053AB80
// Canonical corpus name: CurveSplinePointGenerator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CurveSplinePointGenerator_0053ab80.c

void UnknownObject::CurveSplinePointGenerator()
{
    // Generates a normalized spline-curve lookup table. Stores the parameter a2 at this+0x8, then, if the buffer pointer at this+0xC is non-null, zeroes its first two words and fills entries 1..size with pairs {t, delta} where t = step/size is evaluated by the curve function sub_5881F0 and delta is the difference from the previous t value. The final entry (size) is set to t=1.0 with its delta and a trailing pair of copied/zero words.
    // ASSIGNMENT: Store the parameter a2 into this+0x8 (this[2]). [field:this:0x00000008, source:raw]
    // GUARD: Guard on the buffer pointer at this+0xC (this[3]); the entire table generation is skipped when it is null. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Initialize the first word of the buffer at this[3] to 0 and the following word at this[3]+4 to 0 (covering this+0x10). [field:this:0x0000000C, field:this:0x00000010, source:raw]
    // LOOP: Loop over steps v4 from 1 while v4 < this[0], reading the entry count from this+0x0 (this[0]). [field:this:0x00000000, source:raw]
    // CALCULATION: Compute the normalized position t = (double)v10 / (double)i, where i is the entry count this[0] and v10 is the current step counter. [field:this:0x00000000, source:raw]
    // CALL: Call the curve/spline evaluation function sub_5881F0 with t, consuming the normalized position each step. [callee:0x005881F0, source:raw]
    // ASSIGNMENT: Store t as a float into the buffer slot at this[3] + 8*v4. [field:this:0x0000000C, source:raw]
    // CALCULATION: Compute the delta between the current slot's float and the previous slot's float and store it at this[3] + 8*v4 + 4. [field:this:0x0000000C, source:raw]
    // CALL: Call sub_5881F0 once more with 1.0 after the loop to evaluate the curve endpoint. [callee:0x005881F0, global:0x0059E420, source:raw]
    // ASSIGNMENT: Set the final entry: float value 1.0 at this[3] + 8*size, its delta at +4, and trailing words (a copy and a 0) at +8 and +12. [field:this:0x00000000, field:this:0x0000000C, global:0x0059E420, source:raw]
    // RETURN: Return the entry count this[0] (or the buffer pointer state) as the result. [field:this:0x00000000, source:raw]

    // Conservative worker pseudocode:
    //   int sub_53AB80(int* this, int a2) {
    //     this[2] = a2;
    //     if (!this[3]) return *this;
    //     *(int*)this[3] = 0;
    //     *(int*)(this[3] + 4) = 0;
    //     for (int step = 1; step < *this; ++step) {
    //       double t = (double)step / (double)*this;
    //       sub_5881F0(t);
    //       *(float*)(this[3] + 8*step) = (float)t;
    //       *(float*)(this[3] + 8*step + 4) = *(float*)(this[3] + 8*step) - *(float*)(this[3] + 8*step - 8);
    //     }
    //     sub_5881F0(1.0);
    //     *(float*)(this[3] + 8**this) = 1.0;
    //     *(float*)(this[3] + 8**this + 4) = *(float*)(this[3] + 8**this) - *(float*)(this[3] + 8**this - 8);
    //     *(int*)(this[3] + 8**this + 8) = *(int*)(this[3] + 8**this);
    //     *(int*)(this[3] + 8**this + 12) = 0;
    //     return *this;
    //   }
    // UNRESOLVED: Purpose of the parameter a2 stored at this+0x8 and of the curve data layout (value/delta pairs) is not established by this function alone.
    // UNRESOLVED: The semantics of the endpoint words copied at this[3]+8*size+8/+12 are unclear.
    // UNRESOLVED: Owner identity is unknown; the buffer and count fields only imply a generator-style container.
}
