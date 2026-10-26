// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B1780
// Canonical corpus name: InputClamp
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/InputClamp_004b1780.c

void UnknownObject::InputClamp()
{
    // Reads an input value from this+0x2988 (this[2658]) and clamps it to [-1, 1]. First calls StateCheckWrapper(dword_7CD25C); if the state check fails, the raw unclamped value is returned immediately. Otherwise the value is clamped: values below -1 become -1, values above 1 become 1, and values in [-1, 1] pass through unchanged. Called from sub_4A1830.
    // ASSIGNMENT: Load input value from this+0x2988 (this[2658]). [field:this:0x00002988, source:raw]
    // GUARD: Call StateCheckWrapper(dword_7CD25C); if it returns 0 (state check failed), return the raw unclamped input value immediately. [callee:0x00461DC0, global:0x007CD25C, source:raw]
    // GUARD: If the input value is below -1, return -1 (lower clamp boundary). [source:raw]
    // GUARD: If the input value is at or below 1, return it unchanged (pass-through); otherwise return 1 (upper clamp boundary). [source:raw]

    // Conservative worker pseudocode:
    //   v = this->value_0x2988;
    //   if (!StateCheckWrapper(g_dword_7CD25C))
    //       return v;
    //   if (v < -1)
    //       return -1;
    //   if (v <= 1)
    //       return v;
    //   return 1;
    // UNRESOLVED: Semantics of the dword_7CD25C state check performed by StateCheckWrapper are unknown; failure bypasses the clamp entirely.
    // UNRESOLVED: Class of this and the meaning of this+0x2988 (input axis source) are unconfirmed; the canonical InputClamp name and [-1, 1] range suggest an input axis but remain DERIVED-level.
    // UNRESOLVED: Whether the raw unclamped return on state-check failure is intended behavior or a caller-tolerated edge case is unresolved.
}
