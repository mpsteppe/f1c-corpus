// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054C1B0
// Canonical corpus name: UIWidgetRecursiveStateUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIWidgetRecursiveStateUpdate_0054c1b0.c

void UnknownObject::UIWidgetRecursiveStateUpdate()
{
    // Recursively propagates a widget state update to linked child widgets, then sets or clears a global state flag based on argument a2. If the first child pointer this[17] (offset +0x44) is non-null and a3 is non-zero, recurses as UIWidgetRecursiveStateUpdate(a2, a3, 1). If the second child pointer this[19] (offset +0x4C) is non-null and (a3 & a4) is non-zero, recurses the same way. If the flag-state object this[140] (offset +0x230) is non-null, returns Bit1FlagSet() when a2 is non-zero, otherwise StateFlagBitClear(). Otherwise returns the value left in result by the previous branch (or the initial value if none ran).
    // GUARD: If this[17] (offset +0x44) is non-null and a3 is non-zero, take the first recursion branch. [field:this:0x00000044, source:raw]
    // CALL: Recurse into the first child: UIWidgetRecursiveStateUpdate(a2, a3, 1). [callee:0x0054C1B0, source:raw]
    // GUARD: If this[19] (offset +0x4C) is non-null and (a3 & a4) is non-zero, take the second recursion branch. [field:this:0x0000004C, source:raw]
    // CALL: Recurse into the second child: UIWidgetRecursiveStateUpdate(a2, a3, 1). [callee:0x0054C1B0, source:raw]
    // GUARD: If the flag-state object this[140] (offset +0x230) is non-null, enter the flag set/clear branch. [field:this:0x00000230, source:raw]
    // GUARD: When a2 is non-zero, return Bit1FlagSet() to set the global bit-1 flag. [callee:0x00560FC0, source:raw]
    // GUARD: When a2 is zero, return StateFlagBitClear() to clear the state flag. [callee:0x00560FD0, source:raw]
    // RETURN: Return the value left in result when neither recursion branch nor the flag branch executed (result is uninitialized if the function entered with no branch taken). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_54C1B0(Widget* this, int a2, int a3, int a4) {
    //     if (this->childA && a3)          // this[17] / +0x44
    //       result = UIWidgetRecursiveStateUpdate(a2, a3, 1);
    //     if (this->childB && (a3 & a4))  // this[19] / +0x4C
    //       result = UIWidgetRecursiveStateUpdate(a2, a3, 1);
    //     if (this->flagState) {          // this[140] / +0x230
    //       if (a2) return Bit1FlagSet();
    //       else    return StateFlagBitClear();
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Ownership class is unidentified (abi is LEGACY UI_Widget_Recursive_State_Update); the widget structure containing child pointers at +0x44/+0x4C and the flag-state object at +0x230 is not otherwise evidenced.
    // UNRESOLVED: Return value `result` may be used uninitialized when neither child branch runs and the flag-state object is null.
    // UNRESOLVED: The mapping between a3/a4 flags and the two child-recursion conditions (a3 alone vs (a3 & a4)) is not defined by this function alone.
    // UNRESOLVED: Which specific global flag the Bit1FlagSet / StateFlagBitClear pair (0x00560FC0 / 0x00560FD0) operates on is not visible here.
}
