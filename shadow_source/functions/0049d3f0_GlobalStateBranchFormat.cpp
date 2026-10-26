// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049D3F0
// Canonical corpus name: GlobalStateBranchFormat
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalStateBranchFormat_0049d3f0.c

void UnknownObject::GlobalStateBranchFormat()
{
    // HUD speed readout formatter. Selects one of two speed-magnitude accessors on the byte_7D0474 encoding flag, formats the returned magnitude as a zero-padded 3-digit integer via StringFormatWithBufferOverflowCheck("%.3d"), then renders the resulting buffer to the display resource at this+0x10 (+84) through sub_553070.
    // GUARD: Branch on the encoding flag byte_7D0474: when non-zero read the speed magnitude via SpeedMagnitude, otherwise via SpeedMagnitude_b950. [global:0x007D0474, callee:0x0049B900, callee:0x0049B950, source:raw]
    // CALL: Call SpeedMagnitude (0x0049B900) or SpeedMagnitude_b950 (0x0049B950) to obtain the current speed magnitude integer. [callee:0x0049B900, callee:0x0049B950, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck formats the magnitude into the stack buffer with the "%.3d" format literal at 0x005CCEC8 (a3d). [callee:0x0058815F, global:0x005CCEC8, source:raw]
    // CALL: Render the formatted buffer through sub_553070 with size 4, value 43, and the render target sub-object read from this+0x10 at offset +84. [callee:0x00553070, field:this:0x00000010, source:raw]
    // RETURN: Return the result of sub_553070. Invoked from SteeringWheelAnimation (0x0049D070) on the steering/HUD update path. [caller:0x0049D070, source:raw]

    // Conservative worker pseudocode:
    //   if (byte_7D0474) { v2 = SpeedMagnitude(); } else { v2 = SpeedMagnitude_b950(); }
    //   StringFormatWithBufferOverflowCheck(buf, "%.3d", v2);
    //   return sub_553070(buf, 4, 43, *(this[4] + 84));
    // UNRESOLVED: The field at this+0x64 is listed by packet facts as a steering-input sub-struct pointer but never appears in the raw decompiled source of this function.
    // UNRESOLVED: Global 0x007CE234 is listed by packet facts and the skeleton fill labels it DriverAppearanceFlag, but it is absent from the raw source; its relevance here is unverifiable from this packet.
}
