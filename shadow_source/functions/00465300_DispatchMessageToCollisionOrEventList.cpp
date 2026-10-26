// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00465300
// Canonical corpus name: sub_465300
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_465300_00465300.c

void UnknownObject::DispatchMessageToCollisionOrEventList()
{
    // Input command dispatch. Reads a 32-bit command word from a2. Commands in the collision class ((word >> 29) == 1 with subtype ((word >> 18) & 0x3F) == 0 or 7) are routed directly to FloatComputation when the low byte is < 0x68. All other commands are processed through a queued path: a 432-byte payload is heap-allocated, filled via ArithmeticComparison_3a90, and a 12-byte node linking to it is appended to one of two doubly-linked lists anchored in the container object (list 0 at obj+0x6C for flag patterns with bit 0x8000000 set or tag != 0x20000000, otherwise list 1 at obj+0x7C). Returns the list node pointer, or the low byte of the FloatComputation result on the direct path.
    // GUARD: Command classification: collision-class when (*a2 >> 29) == 1 and subtype ((*a2 >> 18) & 0x3F) is 0 or 7; otherwise the queued-alloc path is taken. [source:raw, function:0x00465300]
    // CALL: Direct path: FloatComputation invoked with the literal expression 560 * (unsigned __int8)*a2 + *this + 140 and the command pointer a2 when the low byte is below 0x68. [callee:0x00464B40, source:raw]
    // CALL: Queued path: allocate 432-byte command payload via OperatorNewNhMallocWrapper. [callee:0x00587C03, source:raw]
    // CALL: Fill the payload from the raw command via ArithmeticComparison_3a90(a2). [callee:0x004B3A90, source:raw]
    // GUARD: List selection from command flags: list 0 (obj+0x6C) when (*a2 & 0x8000000) != 0 or (*a2 & 0xE0000000) != 0x20000000, else list 1 (obj+0x7C). [source:raw]
    // ASSIGNMENT: Dereference container pointer at this+0x00 to obtain the object base holding the two list anchors. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Allocate 12-byte list node via OperatorNewNhMallocWrapper and initialize it: node[0] = payload pointer, node[4] = 0, node[8] = 1. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Append node to list 0: first node sets head obj+0x6C and the two tail slots obj+0x74/obj+0x70 and count obj+0x78; later nodes relink the tail slot obj+0x70 and increment the count. [field:obj:0x0000006C, field:obj:0x00000070, field:obj:0x00000074, field:obj:0x00000078, source:raw]
    // ASSIGNMENT: Append node to list 1: first node sets head obj+0x7C and the two tail slots obj+0x84/obj+0x80 and count obj+0x88; later nodes relink the tail slot obj+0x80 and increment the count. [field:obj:0x0000007C, field:obj:0x00000080, field:obj:0x00000084, field:obj:0x00000088, source:raw]
    // RETURN: Return the new list node pointer on the queued path, or the low byte of the FloatComputation result on the direct collision path. [source:raw, function:0x00465300]

    // Conservative worker pseudocode:
    //   if ((word = *a2, (word >> 29) == 1) && ((subtype = (word >> 18) & 0x3F) == 0 || subtype == 7)) {
    //       if ((unsigned __int8)word < 0x68)
    //           result = FloatComputation(560 * (unsigned __int8)word + *this + 140, a2);
    //   } else {
    //       payload = OperatorNewNhMallocWrapper(432);
    //       if (payload) {
    //           ArithmeticComparison_3a90(a2);
    //           if ((word & 0x8000000) != 0 || (word & 0xE0000000) != 0x20000000)
    //               appendToList(container, listOffset 0x6C, payload);
    //           else
    //               appendToList(container, listOffset 0x7C, payload);
    //       }
    //   }
    //   return result;
    // UNRESOLVED: The two linked lists (obj+0x6C group and obj+0x7C group) are appended to but never consumed within this function; consumers are outside this scope.
    // UNRESOLVED: The semantic distinction between list 0 (flags with 0x8000000 set or tag != 0x20000000) and list 1 is not established by the packet.
}
