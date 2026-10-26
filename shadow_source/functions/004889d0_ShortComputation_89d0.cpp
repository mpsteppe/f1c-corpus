// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004889D0
// Canonical corpus name: ShortComputation_89d0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_89d0_004889d0.c

void UnknownObject::ShortComputation_89d0()
{
    // Computes a normalized ratio: invokes two virtual methods on this (function pointers stored at vtable offsets +32 and +24), forms the range v3 = v2 - v1 as a double, returns 0.0 when the range is non-positive, otherwise returns (double)this[56] / v3 where this[56] is the dword at byte offset 0xE0. Interpreted as a normalized position or progress fraction.
    // CALL: Invoke the virtual method whose function pointer is stored at vtable offset +32 (field obj+0x20) on this; store the int result in v2. [field:this:0x00000000, field:obj:0x00000020, source:raw]
    // CALL: Invoke the virtual method whose function pointer is stored at vtable offset +24 (field obj+0x18) on this; its int result is the lower operand. [field:this:0x00000000, field:obj:0x00000018, source:raw]
    // CALCULATION: Form the range v3 = (double)(v2 - v1) between the two virtual-method results. [source:raw]
    // GUARD: When v3 <= 0.0 the range is non-positive and the function returns 0.0. [source:raw]
    // RETURN: Return 0.0 when the computed range is non-positive. [source:raw]
    // CALCULATION: Compute the fraction (double)this[56] / v3 using the dword at byte offset 0xE0 as the numerator. [field:this:0x000000E0, source:raw]
    // RETURN: Return the computed fraction. [source:raw]

    // Conservative worker pseudocode:
    //   double ShortComputation_89d0(int *this) {
    //     int v2 = (*(int (__thiscall **)(int *))(*this + 32))(this);
    //     double v3 = (double)(v2 - (*(int (__thiscall **)(int *))(*this + 24))(this));
    //     if (v3 <= 0.0)
    //       return 0.0;
    //     return (double)this[56] / v3;
    //   }
    // UNRESOLVED: Packet lists global 0x0059E440 (flt_59E440), but the raw source compares v3 against the immediate 0.0 and never reads that global; its role in this function is unknown.
    // UNRESOLVED: Semantics of the virtual methods at vtable offsets +24 and +32 and the owner object are unidentified.
}
