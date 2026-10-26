// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00494C20
// Canonical corpus name: FloatVectorWithConditionalTransform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatVectorWithConditionalTransform_00494c20.c

void UnknownObject::ClippedVectorConditionalIntConversion()
{
    // stdcall helper that packs four int arguments into a float vector, runs 2D line-rect clipping against it, and only when the clip reports a hit converts the clipped vector back to ints. Vector slots [0]=a1, [1]=a2, [2]=0, [3]=a3, [4]=a4, [5]=0 are filled, then F_2DLineRectClipping(a6, v7) runs; if its byte result is non-zero the function returns FloatToIntConversionChain(v7, a5), otherwise it returns the clip result unchanged. Called from several UI rectangle-drawing helpers.
    // ASSIGNMENT: Local float vector v7 initialized as v7[0]=(float)a1, v7[1]=(float)a2, v7[2]=0.0, v7[3]=(float)a3, v7[4]=(float)a4, v7[5]=0.0 [source:raw]
    // CALL: F_2DLineRectClipping invoked with a6 and the packed vector v7; its result is kept as the branch condition [callee:0x00494C80, source:raw]
    // GUARD: When the low byte of the clip result is non-zero the function takes the conversion branch, otherwise it falls through to return the clip result [source:raw]
    // CALL: FloatToIntConversionChain invoked with v7 and a5, converting the clipped vector back to integer coordinates; its return value is returned directly [callee:0x00553A20, source:raw]
    // RETURN: Returns the FloatToIntConversionChain result when the clip hit, otherwise returns the clip result itself [function:0x00494C20, source:raw]
    // CALL: Invoked by UI rectangle-drawing helpers UICursorSelectionRectangleRenderWithInterpolatio (0045B660), ConditionalDraw (00475C80), F_2DRectangleDrawingWithOutline (00475D90) and RectangleDrawingWithPattern (004972B0) [caller:0x0045B660, caller:0x00475C80, caller:0x00475D90, caller:0x004972B0, source:raw]

    // Conservative worker pseudocode:
    //   float v7[8];
    //   v7[0] = (float)a1; v7[1] = (float)a2; v7[2] = 0.0f; v7[3] = (float)a3; v7[4] = (float)a4; v7[5] = 0.0f;
    //   result = F_2DLineRectClipping(a6, v7);
    //   if ((unsigned char)result != 0)
    //       return FloatToIntConversionChain(v7, a5);
    //   return result;
    // UNRESOLVED: The roles of a5 and a6 (only forwarded, never consumed in this function) are unknown
    // UNRESOLVED: The 2D clipping rectangle layout and the exact coordinate mapping of the four packed ints are not documented here
}
