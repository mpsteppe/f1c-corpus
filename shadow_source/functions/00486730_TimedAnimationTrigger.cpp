// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00486730
// Canonical corpus name: TimedAnimationTrigger
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TimedAnimationTrigger_00486730.c

void UnknownObject::TimedAnimationTrigger()
{
    // Advances a timed UI animation. Resolves an animation configuration block through ConditionalDelegation_6460 using the selector at this+0x84; aborts when the block is missing or when its frame-count field at +0x40 is empty (resetting this+0x88 to zero). Otherwise accumulates time delta (FloatFieldAccessor over the field at this+0x40) into the progress float at this+0x80; when the accumulator exceeds the threshold at block+0x18, decrements the repeat count at this+0xDC and, when it reaches zero, resolves the UI string via UIStringAccessor_6280, looks up its renderer with sub_497E80 and applies RendererAlphaBlendSetter. Resets the accumulator, then advances the frame index at this+0x88 either clamped to or wrapped by the frame count at block+0x10 depending on the mode at block+0x1C, returning 1 on a trigger and 0 otherwise.
    // CALL: Resolve the animation configuration block: ConditionalDelegation_6460(this, *(this + 0x84)) using the config selector field [callee:0x00486460, field:this:0x00000084, source:raw]
    // GUARD: If the resolved configuration block is null, return 0 (no trigger) [source:raw]
    // GUARD: If the configuration block's frame-count field at +0x40 is empty, reset this+0x88 to 0 and return 0 [field:this:0x00000088, source:raw]
    // CALCULATION: Accumulate progress: v6 = FloatFieldAccessor(field at this+0x40) + *(float*)(this + 0x80); store v6 back into this+0x80 [callee:0x00498730, field:this:0x00000040, field:this:0x00000080, source:raw]
    // GUARD: If the accumulated progress v6 exceeds the threshold float at block+0x18, enter the trigger path [source:raw]
    // ASSIGNMENT: Decrement the remaining repeat count at this+0xDC by 1; when it reaches zero, run the renderer-refresh path [field:this:0x000000DC, source:raw]
    // CALL: Renderer refresh: fetch the UI string via UIStringAccessor_6280(this); when non-empty, look it up with sub_497E80 and, if found, set the alpha-blend mode via RendererAlphaBlendSetter [callee:0x00486280, callee:0x00497E80, callee:0x00498030, source:raw]
    // ASSIGNMENT: Reset the progress accumulator this+0x80 back to 0 after a trigger [field:this:0x00000080, source:raw]
    // CALCULATION: Advance the frame index this+0x88 by 1; mode 0 at block+0x1C clamps to the frame count at block+0x10, mode 1 wraps with modulo [field:this:0x00000088, source:raw]
    // RETURN: Return 1 when the animation triggered, 0 otherwise [function:0x00486730, source:raw]
    // CALL: Invoked by sub_486830 as part of the Timed_Animation_Trigger ABI path [caller:0x00486830, abi:lead, function:0x00486730]

    // Conservative worker pseudocode:
    //   cfg = ConditionalDelegation_6460(this, *(this + 0x84));
    //   if (!cfg) return 0;
    //   if (!*(cfg + 0x40)) { *(this + 0x88) = 0; return 0; }
    //   *(float*)(this + 0x80) += FloatFieldAccessor(*(this + 0x40));
    //   if (*(float*)(this + 0x80) > *(float*)(cfg + 0x18)) {
    //       if (--*(this + 0xDC) <= 0) {
    //           s = UIStringAccessor_6280(this);
    //           if (s && *s && RendererAlphaBlendSetter(sub_497E80(s))) ;
    //       }
    //       *(this + 0x80) = 0;
    //       frame = *(this + 0x88) + 1;
    //       if (*(cfg + 0x1C) == 1) frame %= *(cfg + 0x10);
    //       else if (*(cfg + 0x1C) == 0 && frame >= *(cfg + 0x10)) frame = *(cfg + 0x10);
    //       *(this + 0x88) = frame;
    //       return 1;
    //   }
    //   return 0;
    // UNRESOLVED: The advance-mode field at block+0x1C (0 = clamp, 1 = wrap) is inferred from the two branches; no enum evidence is present.
    // UNRESOLVED: The initial meaning of the repeat count at this+0xDC and how it is seeded are not established.
    // UNRESOLVED: The renderer lookup and alpha-blend semantics on the zero-repeat path are inferred; sub_497E80 returns a renderer handle whose exact type is unknown.
}
