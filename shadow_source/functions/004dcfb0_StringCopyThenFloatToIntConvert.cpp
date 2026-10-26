// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DCFB0
// Canonical corpus name: UtilityFunction_cfb0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_cfb0_004dcfb0.c

void UnknownObject::StringCopyThenFloatToIntConvert()
{
    // Thin __thiscall forwarder on an unknown object. First calls StringCopyWithBufferRealloc (0x00566650) with argument a2, then returns the result of FloatToIntConversionDelegation (0x004DCC90) invoked on this with arguments a3..a11 forwarded unchanged. The decompiler-derived callee names indicate a string-copy operation followed by a float-to-int conversion delegation. Called from sub_45B950 (0x0045B950).
    // CALL: Call StringCopyWithBufferRealloc (0x00566650) with a2 as its argument. [callee:0x00566650]
    // CALL: Call FloatToIntConversionDelegation (0x004DCC90) with this as the __thiscall receiver and a3..a11 forwarded unchanged. [callee:0x004DCC90]
    // RETURN: Return the result of FloatToIntConversionDelegation as this function's result. [callee:0x004DCC90, function:0x004DCFB0]

    // Conservative worker pseudocode:
    //   int StringCopyThenFloatToIntConvert(void* this, int a2, int a3, int a4, float a5, float a6, float a7, float a8, float a9, int a10, int a11) {
    //     StringCopyWithBufferRealloc(a2);
    //     return FloatToIntConversionDelegation(this, a3, a4, a5, a6, a7, a8, a9, a10, a11);
    //   }
    // UNRESOLVED: The object class owning this __thiscall is unknown; the packet owner is UnknownObject with no evidence.
    // UNRESOLVED: Whether StringCopyWithBufferRealloc mutates a2 in place or returns a new buffer is not evidenced; the return value is discarded.
    // UNRESOLVED: The exact conversion semantics of FloatToIntConversionDelegation for the float arguments a5..a9 are outside this packet.
}
