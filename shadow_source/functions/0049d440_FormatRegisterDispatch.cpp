// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049D440
// Canonical corpus name: FormatRegisterDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FormatRegisterDispatch_0049d440.c

void UnknownObject::FormatRegisterDispatch()
{
    // Formats a register/state value into a 16-byte local buffer via sub_49C6D0, reading the value from a display context pointer stored at this+0x10 (this[4]) dereferenced 84 bytes deep, then renders the text to the HUD at screen position (4, 0) via sub_553070, whose return value becomes this function's return. No guards; both calls always execute.
    // CALL: Call sub_49C6D0((int)v3, 15) to format the register/state value string into the 16-byte local buffer with length bound 15 [callee:0x0049C6D0, source:raw]
    // CALCULATION: Load the dword at this+0x10 (this[4]) as a base pointer, then read the dword 84 bytes into it; the extractor records this composite access as a this+0x64 read, and the loaded value becomes the text argument for the render call [field:this:0x00000010, field:this:0x00000064, source:raw]
    // CALL: Call sub_553070(v3, 4, 0, value) to render the formatted text to the HUD at screen position (4, 0) [callee:0x00553070, source:raw]
    // RETURN: Return the result of sub_553070 [source:raw]
    // CALL: Reached from SteeringWheelAnimation (0x0049D070) as the register/steering value text dispatch [caller:0x0049D070, source:raw]

    // Conservative worker pseudocode:
    //   int FormatRegisterDispatch(DWORD* this) {
    //     BYTE v3[16];
    //     sub_49C6D0((int)v3, 15);
    //     return sub_553070(v3, 4, 0, *(DWORD*)(this[4] + 84));
    //   }
    // UNRESOLVED: The deterministic extractor lists a global read at 0x007CE234 (unk_7CE234, labelled DriverAppearanceFlag in the fill) that is not visible in the raw source; its role here is unknown.
    // UNRESOLVED: The field extractor records a this+0x64 read while the raw source shows this[4]+84 (84 = 0x54 past the this+0x10 pointer value); the exact relationship between these two renderings is unclear.
    // UNRESOLVED: The meanings of the sub_553070 position arguments (4, 0), of the 15 length bound, and of the 84-byte value offset are unknown.
}
