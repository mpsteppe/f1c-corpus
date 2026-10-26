// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DB9A0
// Canonical corpus name: UtilityFunction_b9a0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_b9a0_004db9a0.c

void UnknownObject::SpeedValueRenderer()
{
    // HUD-style text renderer: converts a float value a1 to an integer via CRTFtol, formats it into a local buffer as a decimal string using the "%d" format literal at global 0x005C3280, then renders that text with UITextRenderWithScale at screen position (a2, a3) in yellow (16776960) with the passed alignment/scale parameters. Returns the render result. Called by UILayoutDispatchWithDataPrep (0x004DB550).
    // CALL: Convert the float a1 to an integer v3 with CRTFtol (0x00587BDC) [callee:0x00587BDC, source:raw]
    // CALL: Format v3 as a decimal string into the local buffer v5 via StringFormatWithBufferOverflowCheck (0x0058815F), using the "%d" format string stored at global 0x005C3280 [callee:0x0058815F, global:0x005C3280, source:raw]
    // CALL: Render the formatted buffer with UITextRenderWithScale (0x004D7E40) at coordinates (a2, a3) in color 16776960, alignment 2, with the trailing 1 / 1.0 / 1.0 layout and scale parameters [callee:0x004D7E40, source:raw]
    // RETURN: Return the result of UITextRenderWithScale [source:raw]
    // CALL: Invoked by UILayoutDispatchWithDataPrep (0x004DB550) as part of the HUD layout dispatch [caller:0x004DB550, source:raw]

    // Conservative worker pseudocode:
    //   int SpeedValueRenderer(float a1, int a2, int a3) {
    //     int v3 = CRTFtol(a1);
    //     char v5[8];
    //     StringFormatWithBufferOverflowCheck(v5, "%d", v3);
    //     return UITextRenderWithScale(v5, a2, a3, 16776960, 2, 1, 1.0, 1.0);
    //   }
    // UNRESOLVED: The source value behind a1 and the exact UI element rendered are caller-supplied and not resolvable from this function alone
}
