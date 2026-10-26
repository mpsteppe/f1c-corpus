// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C03C0
// Canonical corpus name: ArithmeticComparison_03c0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_03c0_004c03c0.c

void UnknownObject::InitializeLapSessionData()
{
    // Constructor-style initializer: writes alternating 0 and -1 literals into six DWORD fields at +0, +4, +8, +0xC, +0x10 and +0x14, delegates the backing array setup to LapSessionDataArrayInitializer, and returns the this pointer.
    // ASSIGNMENT: Write 0 to the DWORD field at +0. [field:this:0x00000000]
    // ASSIGNMENT: Write -1 to the DWORD field at +4. [field:this:0x00000004]
    // ASSIGNMENT: Write 0 to the DWORD field at +8. [field:this:0x00000008]
    // ASSIGNMENT: Write -1 to the DWORD field at +0xC. [field:this:0x0000000C]
    // ASSIGNMENT: Write 0 to the DWORD field at +0x10. [field:this:0x00000010]
    // ASSIGNMENT: Write -1 to the DWORD field at +0x14. [field:this:0x00000014]
    // CALL: Initialize the lap session data array via LapSessionDataArrayInitializer. [callee:0x004C07F0]
    // RETURN: Return the this pointer. [source:raw]

    // Conservative worker pseudocode:
    //   *this = 0; this[1] = -1; this[2] = 0; this[3] = -1; this[4] = 0; this[5] = -1;
    //   LapSessionDataArrayInitializer(this);
    //   return this;
    // UNRESOLVED: Object type and the meaning of the alternating 0/-1 DWORD pair pattern are unknown.
    // UNRESOLVED: The relationship between this initializer and its caller AudioSubsystemInitializer is not resolved.
}
