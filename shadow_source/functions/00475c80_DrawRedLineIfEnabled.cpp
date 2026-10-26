// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00475C80
// Canonical corpus name: ConditionalDraw
// Owner: DebugRenderSystem [DERIVED]
// Raw source: functions/ConditionalDraw_00475c80.c

void DebugRenderSystem::DrawRedLineIfEnabled()
{
    // Queries the render-debug enable state via GlobalAccessor_5150 on global unk_7CDE00; when enabled, draws a red line (color literal 16711680) between the two 2D points given as a1 and a2 through FloatVectorWithConditionalTransform, passing the enable result as the final argument. Returns the enable result when disabled (no draw). Called by sub_475A90 (0x00475A90).
    // CALL: Query render-debug enable state via GlobalAccessor_5150 on global unk_7CDE00 [callee:0x00495150, global:0x007CDE00, source:raw]
    // GUARD: If the enable result is non-zero, proceed to draw [source:raw]
    // CALL: Draw a red line (color literal 16711680) from point a1 (x=a1[0], y=a1[1]) to point a2 via FloatVectorWithConditionalTransform, passing the enable result as the sixth argument [callee:0x00494C20, field:this:0x00000000, field:this:0x00000004, source:raw]
    // RETURN: Return the enable result (0 when disabled, otherwise the draw call result) [source:raw]

    // Conservative worker pseudocode:
    //   int enabled = GlobalAccessor_5150(&unk_7CDE00);
    //   if (enabled) {
    //     return FloatVectorWithConditionalTransform(a1[0], a1[1], a2[0], a2[1], 16711680, enabled);
    //   }
    //   return enabled;
    // UNRESOLVED: Exact interpretation of the sixth argument to FloatVectorWithConditionalTransform (the enable result) not established.
    // UNRESOLVED: Second point a2 has no field evidence; its role beyond source arithmetic is unverified.
}
