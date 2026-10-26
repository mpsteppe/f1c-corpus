// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00408290
// Canonical corpus name: StateInitWithGlobalConstants
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateInitWithGlobalConstants_00408290.c

void UnknownObject::StateInitWithGlobalConstants()
{
    // Initializes struct state from two global DWORD constants plus a fixed flag: calls StructInitWithConditionalNotify first and captures its result, writes dword_5D6D60 cast to float into this+0xC, writes dword_5D6D64 (loaded via a double) cast to float into this+0x10, sets the byte at this+0x14 to 1, and returns the StructInitWithConditionalNotify result. Called by CamMan_Restart to re-initialize state; the globals are proposed as screen width/height only in the skeleton fill (DERIVED).
    // CALL: Calls StructInitWithConditionalNotify and stores its return value as this function's result. [callee:0x004083E0, source:raw]
    // ASSIGNMENT: Writes dword_5D6D60 cast to float into this+0xC. [field:this:0x0000000C, global:0x005D6D60, source:raw]
    // CALCULATION: Loads dword_5D6D64 into a double register in preparation for the float store. [global:0x005D6D64, source:raw]
    // ASSIGNMENT: Writes dword_5D6D64 (via the double load) cast to float into this+0x10. [field:this:0x00000010, global:0x005D6D64, source:raw]
    // ASSIGNMENT: Sets the byte at this+0x14 to 1 (active/enabled flag). [field:this:0x00000014, source:raw]
    // RETURN: Returns the result captured from StructInitWithConditionalNotify. [function:0x00408290, callee:0x004083E0, source:raw]

    // Conservative worker pseudocode:
    //   int StateInitWithGlobalConstants(int this) {
    //     int result = StructInitWithConditionalNotify();
    //     *(float *)(this + 12) = (float)dword_5D6D60;
    //     double v3 = (double)dword_5D6D64;
    //     *(_BYTE *)(this + 20) = 1;
    //     *(float *)(this + 16) = v3;
    //     return result;
    //   }
    // UNRESOLVED: dword_5D6D60 and dword_5D6D64 are proposed as ScreenWidth/ScreenHeight only in the skeleton fill (DERIVED); the packet itself does not evidence their semantic role.
    // UNRESOLVED: StructInitWithConditionalNotify's behavior and what the this+0x14 flag (set to 1) enables are not evidenced.
}
