// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E39D0
// Canonical corpus name: UIElementMultiDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIElementMultiDispatch_004e39d0.c

void UnknownObject::UIElementMultiDispatch()
{
    // Iterates an array of sub-elements on the receiver, dispatching the float value a2 to each element via sub_4DF030. Element count is read from the field this+0xBA8; the element array starts at this[747] and advances by a stride of 748 bytes per element. Returns the element count. The loop is skipped entirely when the count is not positive.
    // ASSIGNMENT: Initialize the result and loop bound from the element count field this+0xBA8 (this[746]). [field:this:0x00000BA8, source:raw]
    // GUARD: Guard on the element count this+0xBA8 being greater than zero; when it is zero or negative the loop body never runs. [field:this:0x00000BA8, source:raw]
    // LOOP: do-while loop that walks the array exactly (count) times, re-reading the count from this+0xBA8 at each iteration as the loop condition. [field:this:0x00000BA8, source:raw]
    // CALL: Call sub_4DF030(element, a2) for the current element pointer, passing the float value a2 down to each sub-element. [callee:0x004DF030, source:raw]
    // CALCULATION: Advance the element pointer from this[747] forward by the 748-byte element stride after each dispatch. [source:raw]
    // RETURN: Return the element count (this+0xBA8) as the function result. [field:this:0x00000BA8, source:raw]
    // CALL: Invoked by sub_4B3400 (0x004B3400) as part of its element update dispatch. [caller:0x004B3400, source:raw]

    // Conservative worker pseudocode:
    //   count = this[0xBA8/4];
    //   idx = 0;
    //   if (count > 0) {
    //     element = &this[747];
    //     do {
    //       sub_4DF030(element, a2);
    //       count = this[0xBA8/4];
    //       ++idx;
    //       element += 748/4;
    //     } while (idx < count);
    //   }
    //   return count;
    // UNRESOLVED: Layout and type of the sub-element struct (748-byte stride) are unknown; the array base this[747] and stride come only from the raw source.
    // UNRESOLVED: The effect of sub_4DF030 on each element is unknown here; the skeleton fill labels it a typed LRU cache creation, which is unverifiable from this packet.
    // UNRESOLVED: The receiver object type and the meaning of the dispatched float a2 are unknown.
}
