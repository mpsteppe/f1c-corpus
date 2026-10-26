// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00452780
// Canonical corpus name: StructInitWithFixedValues
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructInitWithFixedValues_00452780.c

void UnknownObject::StructInitWithFixedValues()
{
    // Constructor/initializer (thiscall) that fills an 11-field region with fixed values and returns this. Sets this+0x4 to 89 and this+0x0 and this+0x8..this+0x18 to 0, calls SwapAndReinit(this+0x4, 89, 0), then zeroes this+0x1C..this+0x28. Invoked by MemoryAllocation_31a0 (0x004531A0) as part of an allocation+init sequence.
    // ASSIGNMENT: Write the fixed seed value 89 into this+0x4 (the start of the v2 = this+1 sub-region). [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Zero the sub-region fields this+0x8, this+0xC, this+0x10, this+0x14 and this+0x18 (v2[1..5]). [field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, source:raw]
    // ASSIGNMENT: Zero the head field this+0x0. [field:this:0x00000000, source:raw]
    // CALL: Call SwapAndReinit(this+0x4, 89, 0) to re-seed the sub-region with the same fixed value. [callee:0x00452740, field:this:0x00000004, source:raw]
    // ASSIGNMENT: Zero the remaining fields this+0x1C, this+0x20, this+0x24 and this+0x28. [field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, source:raw]
    // RETURN: Return this as the result of the initializer. [function:0x00452780, source:raw]
    // CALL: Invoked by MemoryAllocation_31a0 (0x004531A0) as the init step after allocation. [caller:0x004531A0, source:raw]

    // Conservative worker pseudocode:
    //   int* StructInitWithFixedValues(int* this) {
    //     int* v2 = this + 1;
    //     v2[0] = 89; v2[1] = 0; v2[2] = 0; v2[3] = 0; v2[4] = 0; v2[5] = 0;
    //     this[0] = 0;
    //     SwapAndReinit(v2, 89, 0);
    //     this[7] = 0; this[8] = 0; this[9] = 0; this[10] = 0;
    //     return this;
    //   }
    // UNRESOLVED: The object type owning this 11-field region is unknown; caller MemoryAllocation_31a0 (0x004531A0) allocates and then invokes this initializer but its object identity is not established here.
    // UNRESOLVED: The meaning of the fixed value 89 and the contract of SwapAndReinit(this+0x4, 89, 0) are unresolved.
}
