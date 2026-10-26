// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049E570
// Canonical corpus name: SuspensionCornerCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SuspensionCornerCheck_0049e570.c

void UnknownObject::SuspensionCornerCheck()
{
    // Renders one corner's suspension/temperature gauge into the draw surface a2. The per-corner state is read from the input-state object dword_7C54E0 at a 296-byte-per-corner stride (non-zero dword at +2100 and non-zero byte at +2164 gate the active branch). When the corner is inactive the gauge blinks red, gated on the parity CRTFtol(dbl_8AFEA0) % 2. When active and the per-car dword at +18580 of the car selected by dword_7C54DC equals that of the car selected by dword_7C54E4, it draws three color-encoded segments built from the corner temperature table at 8157696 (a double converted from Kelvin to Celsius by -273.16, then passed to FloatToColorEncoding); otherwise it draws the whole bar in the fixed green color.
    // GUARD: Enter the active-corner branch only when the corner entry at dword_7C54E0 + 296*a1 has a non-zero dword at +2100 and a non-zero byte at +2164; otherwise fall through to the blink path. [global:0x007C54E0, source:raw]
    // GUARD: Compare the per-car dword at +18580 of the car selected by dword_7C54DC (via dword_7C54F0) with the +18580 dword of the car selected by dword_7C54E4; equality selects the three-segment draw, inequality the plain green bar. [global:0x007C54E0, source:raw]
    // LOOP: Loop over three segments: for segment v6 in {0,1,2}, compute segment start v8 = a3 + v6*(a5/3) and end v9 (a3 + a5 for the first two segments, a3 + 2*(a5/3) + a5/3 for the last), read the corner temperature double at 1124*a1 + 8*v6 + 8157696, subtract 273.16 to convert Kelvin to Celsius, encode it with FloatToColorEncoding, and draw the segment via RenderDrawOperationWithClipping(a2, v8, a4, v9 - v8, color). [source:raw]
    // CALL: In the unequal-car branch, draw the full gauge bar with RenderDrawOperationWithClipping(a2, a3, a4, a5, -16711936), the fixed green color, and return its result. [source:raw]
    // CALCULATION: In the inactive-corner branch, compute the blink gate result = CRTFtol(dbl_8AFEA0) % 2; when the remainder is zero draw the whole bar with RenderDrawOperationWithClipping(a2, a3, a4, a5, -65536), the fixed red color, and return it. [source:raw]
    // RETURN: Return the last draw result from the active path (the final segment draw) or the blink remainder when the blink gate rejected the red draw. [source:raw]

    // Conservative worker pseudocode:
    //   int suspensionCornerCheck(int corner, int surface, int x, int w, int len) {
    //     void* inp = dword_7C54E0;
    //     if (!*(int*)(inp + 296*corner + 2100) || !*(byte*)(inp + 296*corner + 2164)) {
    //       int blink = CRTFtol(dbl_8AFEA0) % 2;
    //       if (!blink) return RenderDrawOperationWithClipping(surface, x, w, len, -65536);
    //       return blink;
    //     }
    //     if (*(int*)(dword_7C54F0[dword_7C54DC] + 18580) != *(int*)(dword_7C54F0[dword_7C54E4] + 18580))
    //       return RenderDrawOperationWithClipping(surface, x, w, len, -16711936);
    //     int result = 0;
    //     for (int i = 0; i < 3; i++) {
    //       int start = x + i*(len/3);
    //       int end = (i == 2) ? x + 2*(len/3) + len/3 : x + len;
    //       double celsius = *(double*)(1124*corner + 8*i + 8157696) - 273.16;
    //       int color = FloatToColorEncoding(celsius);
    //       result = RenderDrawOperationWithClipping(surface, start, w, end - start, color);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: dword_7C54F0, dword_7C54DC, dword_7C54E4, dbl_8AFEA0, the temperature table base 8157696, FloatToColorEncoding, RenderDrawOperationWithClipping and CRTFtol appear in the raw source but have no packet-level evidence entries; their roles are read from the source text only.
    // UNRESOLVED: The meaning of the +18580 comparison (one per-corner value on two cars) and the physical meaning of the temperature table are not evidenced; the gauge reading is a DERIVED label.
    // UNRESOLVED: Whether the green bar and the red blink bar represent distinct HUD states is inferred from the branch structure, not stated in evidence.
    // UNRESOLVED: The 296-byte corner stride and the +2100/+2164 gate offsets are read from the raw source arithmetic; their field names are unknown.
}
