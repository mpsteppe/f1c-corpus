// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047BE00
// Canonical corpus name: sub_47BE00
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_47BE00_0047be00.c

void UnknownObject::UIComponentScrollPositionClamp()
{
    // Computes and clamps the scroll position of a cursor-based UI component. Reads the total cursor item count via MenuCursorCount_bc90 and the scroll range at this+0x114; writes this+0xEC as ((count-1) * step + range/2) / range, or 0 when the range is zero (division guard). The result is clamped into [0, count-1]. When count-1 is below the range (content fits the viewport), an auxiliary utility at 0047bd90 is invoked instead. Called by UIComponentScrollUpdate (0047b1e0) and sub_47BB40 (0047bb40).
    // CALL: MenuCursorCount_bc90 returns the total cursor item count used as the scroll index upper bound [callee:0x0047BC90, source:raw]
    // GUARD: Division guard on the scroll range this+0x114: when zero, write scroll position 0 to this+0xEC instead of evaluating the weighted formula [field:this:0x00000114, field:this:0x000000EC, source:raw]
    // CALCULATION: Scroll formula: this+0xEC = ((count-1) * this+0x110 + this+0x114/2) / this+0x114, rounding by half-range before the division [field:this:0x00000110, field:this:0x00000114, field:this:0x000000EC, source:raw]
    // ASSIGNMENT: Clamp this+0xEC into [0, count-1]: negative values are forced to 0 and values above count-1 are forced to count-1 [field:this:0x000000EC, source:raw]
    // GUARD: If count-1 is less than the range this+0x114, return the result of the auxiliary adjustment utility at 0047bd90 instead of the scroll value [field:this:0x00000114, source:raw]
    // RETURN: Otherwise return the clamped scroll position [field:this:0x000000EC, source:raw]
    // CALL: Invoked by UIComponentScrollUpdate (0047b1e0) and sub_47BB40 (0047bb40) during cursor-scroll updates [caller:0x0047B1E0, caller:0x0047BB40, source:raw]

    // Conservative worker pseudocode:
    //   count = MenuCursorCount_bc90(this);
    //   range = *(this + 0x114);
    //   maxIdx = count - 1;
    //   if (range)
    //     *(this + 0xEC) = (maxIdx * *(this + 0x110) + range/2) / range;
    //   else
    //     *(this + 0xEC) = 0;
    //   scroll = *(this + 0xEC);
    //   if (scroll < 0) *(this + 0xEC) = 0;
    //   else if (scroll > maxIdx) *(this + 0xEC) = maxIdx;
    //   if (maxIdx < range) return UtilityFunction_bd90(this);
    //   return *(this + 0xEC);
    // UNRESOLVED: The raw source calls the helper UtilityFunction_bd90 (0047bd90), but that target is absent from the packet callee facts and therefore has no allowed evidence reference
    // UNRESOLVED: The field roles this+0x110 (step size) and this+0x114 (scroll range) are DERIVED from the existing analysis naming; only the offset arithmetic is packet evidence
    // UNRESOLVED: The weighted formula semantics and the meaning of the utility adjustment when content fits the viewport are not proven by packet evidence
}
