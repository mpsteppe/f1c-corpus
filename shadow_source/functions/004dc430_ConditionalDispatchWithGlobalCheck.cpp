// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DC430
// Canonical corpus name: ConditionalDispatchWithGlobalCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalDispatchWithGlobalCheck_004dc430.c

void UnknownObject::ConditionalDispatchWithGlobalCheck()
{
    // Dispatch helper: returns ValueGetter(arg) when the argument is nonzero; otherwise reloads the pointer from global dword_8AFE88 and returns ValueGetter(global) when that global is nonzero, else returns 0. Called from TextureAdjuster (0x004DC770).
    // ASSIGNMENT: result is initialized to 0 as the default return value [function:0x004DC430, source:raw]
    // GUARD: if (a1): a nonzero first argument selects the argument-backed path [function:0x004DC430, source:raw]
    // CALL: ValueGetter(a1) is invoked on the provided pointer and its value returned directly [function:0x004DC430, source:raw]
    // ASSIGNMENT: a1 is reloaded from global dword_8AFE88 as the fallback pointer [global:0x008AFE88]
    // GUARD: if (dword_8AFE88): a nonzero global selects the fallback path [global:0x008AFE88, source:raw]
    // CALL: ValueGetter(a1) is invoked on the fallback global value and its value returned [function:0x004DC430, source:raw]
    // RETURN: returns 0 when both the argument and the global are zero [function:0x004DC430, source:raw]

    // Conservative worker pseudocode:
    //   result = 0;
    //   if (a1) return ValueGetter(a1);
    //   a1 = dword_8AFE88;
    //   if (dword_8AFE88) return ValueGetter(a1);
    //   return result;
    // UNRESOLVED: ValueGetter is named in the raw source but has no callee entry in this packet, so its target address and signature are not evidenced.
    // UNRESOLVED: Whether the argument and the global hold the same object type is unproven; only the read of dword_8AFE88 is evidenced.
}
