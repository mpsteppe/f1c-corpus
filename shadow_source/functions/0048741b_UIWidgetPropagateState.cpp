// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048741B
// Canonical corpus name: UIWidgetPropagateState
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIWidgetPropagateState_0048741b.c

void UnknownObject::UIWidgetPropagateState()
{
    // Propagates a boolean state a2 through a UI widget. Notifies the state change via StateChangeNotification on a1. When a2 is set, directly invokes the virtual method at offset 64 on a3 with argument 4; otherwise reads the current state via RangeCheck and routes through StateDependentVTableDispatch (00487330). Then walks a linked list rooted at a3[36] (offset 144): for each node it invokes the virtual method at offset 56 with a2 and advances to the next node via StructFieldAccessor. Returns the last call result.
    // CALL: Notify the state change on a1 via StateChangeNotification; the second argument v8 is an uninitialized stack slot in the decompilation. [callee:0x00486660, source:raw]
    // GUARD: Branch on a2: when non-zero take the direct vtable dispatch path, otherwise the RangeCheck/StateDependentVTableDispatch path. [source:raw]
    // CALL: When a2 is set, invoke the virtual method at offset 64 on a3 with argument 4. [source:raw]
    // CALL: When a2 is clear, read the current state byte via RangeCheck on a3. [callee:0x00487740, source:raw]
    // CALL: When a2 is clear, dispatch the state through StateDependentVTableDispatch (00487330) using the RangeCheck result as the boolean input. [callee:0x00487330, source:raw]
    // ASSIGNMENT: Load the head of the linked list stored at a3[36] (byte offset 144) into v6. [source:raw]
    // LOOP: While the current node v6 is non-null: invoke the virtual method at offset 56 on it with a2, then advance v6 to the next node via StructFieldAccessor; repeat until a null node is returned. [callee:0x00486320, source:raw]
    // RETURN: Return the last result v4, which is the terminating (null) StructFieldAccessor value when the list was walked. [function:0x0048741B, source:raw]

    // Conservative worker pseudocode:
    //   char UIWidgetPropagateState(void* a1, char a2, void* a3) {
    //     StateChangeNotification(a1, /* v8: uninitialized in decompilation * /);
    //     int result;
    //     if (a2) {
    //       result = vtable_call_64(a3, 4);
    //     } else {
    //       char state = RangeCheck(a3);
    //       result = StateDependentVTableDispatch(a3, state);
    //     }
    //     void* node = a3[36];
    //     while (node) {
    //       vtable_call_56(node, a2);
    //       result = StructFieldAccessor(node);
    //       node = result;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The second argument v8 of StateChangeNotification is an uninitialized stack slot in the decompilation; its intended value is unknown.
    // UNRESOLVED: Whether a1 (StateChangeNotification receiver) and a3 (vtable dispatch receiver) are the same object is not proven.
    // UNRESOLVED: The linked-list node type and the identity of the virtual methods at offsets 56 and 64 are unknown.
    // UNRESOLVED: The unused parameter a4 has no evidenced role.
}
