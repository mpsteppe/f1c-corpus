// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00494F00
// Canonical corpus name: ShortComputation_4f00
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_4f00_00494f00.c

void UnknownObject::CallConditionalFontSurface()
{
    // Thin forwarder with __stdcall ABI: takes four integer arguments and tail-calls ConditionalFontSurfaceCall(a1, a2, a3, a4), returning its result unchanged. Called from the media playback, bitmap drawing and text-rendering paths (MediaBufferPlaybackManager, BitmapDraw, BitmapDraw_81f0, BitmapDrawWithAlpha, TextRenderToSurface). A read of global dword_8AFE64 is recorded by the static facts but is not visible in the raw source body.
    // CALL: Forward all four arguments (a1..a4) unchanged to ConditionalFontSurfaceCall as a tail call. [source:raw, function:0x00494F00]
    // RETURN: Return the value produced by ConditionalFontSurfaceCall without modification. [source:raw, caller:0x0048D9D0, caller:0x004980D0, caller:0x004981F0, caller:0x004982C0, caller:0x004983B0]

    // Conservative worker pseudocode:
    //   int CallConditionalFontSurface(int a1, int a2, int a3, int a4) {
    //     return ConditionalFontSurfaceCall(a1, a2, a3, a4);
    //   }
    // UNRESOLVED: The packet records a read of global dword_8AFE64 (evidence global:0x008AFE64) that is not visible in the raw source body; its role in this forwarder is unresolved.
    // UNRESOLVED: Class/owner identity of ConditionalFontSurfaceCall and this forwarder is unknown (packet owner trust is UNKNOWN with no evidence).
}
