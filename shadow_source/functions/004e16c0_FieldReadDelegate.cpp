// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E16C0
// Canonical corpus name: FieldReadDelegate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FieldReadDelegate_004e16c0.c

void UnknownObject::FieldReadDelegate()
{
    // Reads three DWORDs (this+0x8, this+0xC, this+0x10) and three floats (this+0x14, this+0x18, this+0x1C) from a data-binding object and forwards all six to sub_54B4D0, returning its result. Called by VehicleTelemetryPositionAccumulator as a field-read delegate.
    // CALL: Forward six fields of `this` to sub_54B4D0: three DWORDs (this+0x8, this+0xC, this+0x10) and three floats (this+0x14, this+0x18, this+0x1C) [callee:0x0054B4D0, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, source:raw]
    // RETURN: Return the result of sub_54B4D0 [callee:0x0054B4D0, source:raw]

    // Conservative worker pseudocode:
    //   // Data-binding delegate: read six fields and forward them.
    //   return sub_54B4D0(
    //       this->dw0(0x8), this->dw1(0xC), this->dw2(0x10),
    //       this->f0(0x14), this->f1(0x18), this->f2(0x1C));
    // UNRESOLVED: The semantic role of the six forwarded values and of sub_54B4D0's return value is not established by this packet.
}
