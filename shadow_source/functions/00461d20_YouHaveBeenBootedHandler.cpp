// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00461D20
// Canonical corpus name: YouHaveBeenBootedHandler
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/YouHaveBeenBootedHandler_00461d20.c

void UnknownObject::YouHaveBeenBootedHandler()
{
    // Frame-path handler that drives the "You have been booted" disconnect notice. Gate 1: SessionStateCheck(this) must return a value in (0,3]. Inside the gate it decrements the float countdown at obj+0x380 by the global frame step dbl_8AFE90, then calls SingleDelegationCall_a900 with the object pointer stored at obj+0x3FB8; a zero result (disconnected/booted) and the not-yet-shown flag byte at obj+0x30 let it fill byte_5EC4CC from the message string aYouHaveBeenBoo and render it via TextLineWrappingAndRendering(&dword_7CD204, byte_5EC4CC, 3, 16909060), then sets obj+0x30 to 1. The last evaluated status (v2) is returned. Called from ShortComputation_f070 (0x0049F070).
    // CALL: Call SessionStateCheck(this) and capture the returned status v2 as the frame gate. [callee:0x00461CD0, function:0x00461D20]
    // GUARD: Only run the body when the session state v2 is greater than 0 and less than or equal to 3. [callee:0x00461CD0, source:raw]
    // CALCULATION: Dereference this+0 to reach the object; read the float at obj+0x380, subtract dbl_8AFE90, and store it back (countdown decrement). [field:obj:0x00000380, field:this:0x00000000, global:0x008AFE90]
    // CALL: Call SingleDelegationCall_a900 with the object member at obj+0x3FB8 as its argument; store the result back into v2. [callee:0x0057A900, field:obj:0x00003FB8, field:this:0x00000000]
    // GUARD: Only proceed when the delegation call returned zero (interpreted as disconnected/booted status). [callee:0x0057A900, source:raw]
    // GUARD: Only render when the byte at obj+0x30 is zero, i.e. the boot message has not already been shown this session. [field:obj:0x00000030, field:this:0x00000000]
    // CALL: Call BinarySearchInStringTable(byte_5EC4C0, aYouHaveBeenBoo, byte_5EC4CC); if it returns nonzero, the message is staged into the display buffer. [callee:0x00423A00, global:0x005C5D54, global:0x005EC4C0, global:0x005EC4CC]
    // LOOP: Copy the characters of aYouHaveBeenBoo into byte_5EC4CC one byte at a time until the copied byte is the terminating NUL. [global:0x005C5D54, global:0x005EC4CC]
    // CALL: Call TextLineWrappingAndRendering with &dword_7CD204 as the resource dispatch target, byte_5EC4CC as the text, and literal arguments 3 and 16909060. [callee:0x0045BD10, global:0x005EC4CC, global:0x007CD204]
    // ASSIGNMENT: Set the byte at obj+0x30 to 1, marking the boot message as already displayed. [field:obj:0x00000030, field:this:0x00000000]
    // RETURN: Return v2, the last evaluated status (session state or delegation result), propagating it to the caller. [function:0x00461D20, source:raw]

    // Conservative worker pseudocode:
    //   char YouHaveBeenBootedHandler(void *this) {
    //       int status = SessionStateCheck(this);
    //       if (status > 0 && status <= 3) {
    //           *(float *)(*(int *)this + 0x380) -= dbl_8AFE90;
    //           status = SingleDelegationCall_a900(*(int *)(*(int *)this + 0x3FB8));
    //           if (status == 0 && *(char *)(*(int *)this + 0x30) == 0) {
    //               if (BinarySearchInStringTable(byte_5EC4C0, aYouHaveBeenBoo, byte_5EC4CC)) {
    //                   int i = 0;
    //                   char c;
    //                   do { c = aYouHaveBeenBoo[i]; byte_5EC4CC[i++] = c; } while (c);
    //               }
    //               TextLineWrappingAndRendering(&dword_7CD204, (int)byte_5EC4CC, 3, 16909060);
    //               *(char *)(*(int *)this + 0x30) = 1;
    //           }
    //       }
    //       return status;
    //   }
    // UNRESOLVED: Semantic labels (boot countdown timer for obj+0x380, message-shown flag for obj+0x30, disconnected/booted status for the SingleDelegationCall_a900 result) come from existing_analysis prose, not from the packet's raw source; treat as DERIVED.
    // UNRESOLVED: obj+0x3FB8 is passed to SingleDelegationCall_a900; what object it points to and that function's contract are not evidenced in this packet.
    // UNRESOLVED: dbl_8AFE90 is treated as a per-frame decrement step by existing_analysis; its stored value is not in the packet.
    // UNRESOLVED: Literal 16909060 passed to TextLineWrappingAndRendering is not explained by the packet.
    // UNRESOLVED: Owner is unknown: the raw source dereferences this+0 to a sub-object but no owning class is evidenced.
}
