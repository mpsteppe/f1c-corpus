// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00543440
// Canonical corpus name: RenderDrawOperationWithClipping
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RenderDrawOperationWithClipping_00543440.c

void UnknownObject::RenderDrawOperationWithClipping()
{
    // Clipped 2D surface draw: first calls sub_543540 to clip the draw parameters (coordinates a2/a3, dimensions a4/a5, source pointer a5) in place, then calls F_2DSurfaceBlitFill with the surface handle dword_8B78A0 and the clipped parameters when both clipped dimensions are positive. On success clears status bit 0x400 of this[6] (field 0x18). Returns the result of the last operation, or the clipped height value when the blit is skipped.
    // CALL: sub_543540(&a2, &a3, &a4, &a5): clips the draw position, dimensions and source pointer in place against surface bounds. [callee:0x00543540, function:0x00543440, source:raw]
    // GUARD: Guard on clipped width a4 > 0; skip the blit when the clipped region has no positive width. [function:0x00543440, source:raw]
    // GUARD: Guard on clipped height a5 > 0; skip the blit when the clipped region has no positive height. [function:0x00543440, source:raw]
    // CALL: F_2DSurfaceBlitFill(dword_8B78A0, this, a2, a3, a4, a5, a6): perform the 2D surface blit/fill with the clipped parameters. [callee:0x005404D0, global:0x008B78A0, function:0x00543440, source:raw]
    // ASSIGNMENT: this[6] &= ~0x400u: clear status bit 0x400 in field this+0x18 after a successful blit. [field:this:0x00000018, source:raw]
    // RETURN: Return the result of the blit when performed, otherwise the clipped height value a5. [function:0x00543440, source:raw]
    // CALL: On the per-frame path, invoked by ConditionalSubsystemCallWithParameter (00408DE0), sub_409890 (00409890), DelegationWrapper (00494BF0), SteeringWheelAnimation (0049D070), sub_49DE40 (0049DE40), SuspensionCornerCheck (0049E570), sub_49E7B0 (0049E7B0) and sub_4F9480 (004F9480). [caller:0x00408DE0, caller:0x00409890, caller:0x00494BF0, caller:0x0049D070, caller:0x0049DE40, caller:0x0049E570, caller:0x0049E7B0, caller:0x004F9480, source:raw]

    // Conservative worker pseudocode:
    //   int RenderDrawOperationWithClipping(this, int x, int y, int w, int h, int extra) {
    //     int result = sub_543540(&x, &y, &w, &h);
    //     if (w > 0) {
    //       result = h;
    //       if (h > 0) {
    //         result = F_2DSurfaceBlitFill(dword_8B78A0, this, x, y, w, h, extra);
    //         this[6] &= ~0x400u;
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Meaning of status bit 0x400 in this+0x18 is not documented here; cleared only on the success path
    // UNRESOLVED: dword_8B78A0 is passed as the surface handle to F_2DSurfaceBlitFill but its concrete object type is not established
    // UNRESOLVED: The exact post-clip layout of a2..a5 produced by sub_543540 is not verifiable from this function alone
}
