// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00461F70
// Canonical corpus name: ConditionalFunctionCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalFunctionCall_00461f70.c

void UnknownObject::CallNetworkSystemIfPresent()
{
    // Conditional forwarding function. Reads this+0x0 to obtain a base object, dereferences the pointer stored at that object's 0x1B79C offset (a network system pointer), and if that pointer is non-null forwards it to sub_563410. Otherwise returns the value read from this+0x0 unchanged. Called by ConditionalChain (00475570).
    // ASSIGNMENT: Read the first field of this (this+0x0) as the base object pointer and keep it as the fallback result. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Dereference the base object at the previously read pointer and load the value stored at offset 0x1B79C (network system pointer). [field:obj:0x0001B79C, source:raw]
    // GUARD: If the network system pointer (obj+0x1B79C) is non-null, take the forwarding path. [field:obj:0x0001B79C, source:raw]
    // CALL: Call sub_563410 with the network system pointer as its argument when it is non-null. [source:raw]
    // RETURN: Return the forwarded call's result on the non-null path, or the value of this+0x0 on the null path. [function:0x00461F70, source:raw]
    // CALL: Invoked by ConditionalChain (00475570) as part of its conditional dispatch. [caller:0x00475570, source:raw]

    // Conservative worker pseudocode:
    //   int ConditionalFunctionCall(int* this) {
    //     int result = *this;
    //     int v2 = *(_DWORD*)(*this + 112540);
    //     if (v2)
    //       return sub_563410(v2);
    //     return result;
    //   }
    // UNRESOLVED: sub_563410 is not a listed callee of this function in the packet evidence; its identity and return contract are unknown.
    // UNRESOLVED: The object type at this+0x0 and the semantics of the network system pointer at obj+0x1B79C are unknown.
}
