// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00486830
// Canonical corpus name: sub_486830
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_486830_00486830.c

void UnknownObject::AnimatedElementRenderDispatch()
{
    // Render dispatch for an animated UI element. Calls a vtable method at offset 8 (on the vtable pointed to by this+0) to retrieve element bounds, computes width and height from the returned coordinates, and chooses between an animated and a static render path based on TimedAnimationTrigger. Returns 1 while animating, 2 when the static render ran, or 0 when neither path rendered.
    // CALL: Indirect __thiscall through the vtable at this+0, invoking the method at vtable offset 8 to retrieve element bounds into the local out-parameters. [field:this:0x00000000, field:obj:0x00000008, source:raw]
    // CALCULATION: Compute width as bounds_right - bounds_left and height as bounds_bottom - bounds_top from the returned coordinates. [source:raw]
    // GUARD: Branch on TimedAnimationTrigger(this): a non-zero result takes the animated render path. [callee:0x00486730, source:raw]
    // CALL: Call Accessor() at the start of the animated path. [callee:0x00490920]
    // CALL: Call ShortComputation_1c70(x, y, width, height) as the animated render; a zero return short-circuits to return 1. [callee:0x00491C70, source:raw]
    // RETURN: Return 1 when the animated path is active and ShortComputation_1c70 returned zero. [source:raw]
    // CALL: Call Accessor() again for the static (non-animated) path. [callee:0x00490920]
    // CALL: Call ShortComputation_1cb0(x, y, width, height) as the static render; a non-zero return maps to 2, zero maps to 0. [callee:0x00491CB0, source:raw]
    // RETURN: Return 2 when the static render returned non-zero, otherwise 0. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_486830(this) {
    //     int left, top, right, bottom;
    //     (*(vtable(this) + 8))(this, &left, &bottom, &right, &top);
    //     int x = left, y = right;
    //     int width = top - right;
    //     int height = bottom - left;
    //     if (TimedAnimationTrigger(this)) {
    //       Accessor();
    //       if (!ShortComputation_1c70(x, y, width, height))
    //         return 1;
    //     }
    //     Accessor();
    //     return ShortComputation_1cb0(x, y, width, height) ? 2 : 0;
    //   }
    // UNRESOLVED: Identity and semantics of ShortComputation_1c70 and ShortComputation_1cb0 (believed render helpers) are unknown.
    // UNRESOLVED: Purpose of the Accessor() call, invoked on both paths, is unknown.
    // UNRESOLVED: Object type behind `this` and the bounds method at vtable offset 8 are unknown.
}
