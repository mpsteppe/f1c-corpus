// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005038C0
// Canonical corpus name: RenderFeatureDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RenderFeatureDispatch_005038c0.c

void UnknownObject::RenderFeatureDispatch()
{
    // Render feature dispatcher. Tests sub_50FC7D(); if non-zero it selects sub_503772 for both global dispatch slots, otherwise it selects ImageBlendingCompositing for off_5D76C0 and F_2DImageBoxFilter for the held local. The chosen handler is stored in off_5D76C4 and then invoked via indirect call; its result is returned.
    // GUARD: Branch on the result of sub_50FC7D(); non-zero selects the first handler set. [callee:0x0050FC7D, function:0x005038C0]
    // ASSIGNMENT: True branch: write sub_503772 into off_5D76C0. [global:0x005D76C0, global:0x00503772]
    // ASSIGNMENT: True branch: hold sub_503772 as the local handler v0. [global:0x00503772, source:raw]
    // ASSIGNMENT: False branch: write ImageBlendingCompositing into off_5D76C0. [global:0x005D76C0, global:0x00503533]
    // ASSIGNMENT: False branch: hold F_2DImageBoxFilter as the local handler v0. [global:0x0050368A, source:raw]
    // ASSIGNMENT: Write the selected handler v0 into off_5D76C4. [global:0x005D76C4, source:raw]
    // CALL: Invoke the selected handler through v0 and return its result. [function:0x005038C0, source:raw]

    // Conservative worker pseudocode:
    //   if (sub_50FC7D()) {
    //       off_5D76C0 = sub_503772;
    //       v0 = sub_503772;
    //   } else {
    //       off_5D76C0 = ImageBlendingCompositing;
    //       v0 = F_2DImageBoxFilter;
    //   }
    //   off_5D76C4 = v0;
    //   return v0();
    // UNRESOLVED: The role of off_5D76C0 versus off_5D76C4 (two dispatch slots storing the same handler) is unknown.
    // UNRESOLVED: The meaning of the sub_50FC7D() predicate is unknown.
    // UNRESOLVED: Whether F_2DImageBoxFilter and ImageBlendingCompositing are the true branch or fallback path is only structurally inferred from the prelabel cluster copy.
}
