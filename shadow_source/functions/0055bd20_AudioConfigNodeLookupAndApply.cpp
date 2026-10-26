// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055BD20
// Canonical corpus name: sub_55BD20
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_55BD20_0055bd20.c

void UnknownObject::AudioConfigNodeLookupAndApply()
{
    // Walks a singly-linked node list rooted at this[72] to find the first node whose [2], [3], [5] (and optionally [6]) dword fields equal the audio-config parameters a2, a3, a4, a6, recording the matched node index into this[70]. On a match it copies the parameters into four screen/audio globals, calls the audio subsystem setup routine sub_53E070, then a stub. Returns -1 on null list, end-of-list without match, or a nonzero return from sub_53E070; otherwise returns 0.
    // GUARD: Load list head pointer from this[72] (offset 0x120); when null return -1 immediately. [field:this:0x00000120, source:raw]
    // LOOP: Traverse the list starting at the head: continue while node field [2] (offset 0x148) != a2, [3] (offset 0x14C) != a3, [5] (offset 0x154) != a4, or (when a6 nonzero) [6] (offset 0x158) != a6, advancing via the next pointer stored at node [8] (offset 0x160). [field:this:0x00000148, field:this:0x0000014C, field:this:0x00000154, field:this:0x00000158, field:this:0x00000160, source:raw]
    // GUARD: Increment the match index v7 each hop; when the next pointer at node [8] (offset 0x160) is null before a match, return -1. [field:this:0x00000160, source:raw]
    // ASSIGNMENT: Store the matched node index v7 into this[70] (offset 0x118). [field:this:0x00000118, source:raw]
    // ASSIGNMENT: Write a2 into global dword_8B8DD4. [global:0x008B8DD4, source:raw]
    // ASSIGNMENT: Write a3 into global dword_8B8DD8. [global:0x008B8DD8, source:raw]
    // ASSIGNMENT: Write a4 into global dword_8B8DE4. [global:0x008B8DE4, source:raw]
    // ASSIGNMENT: Write (a5 & 1) into global dword_8B8DEC. [global:0x008B8DEC, source:raw]
    // CALL: Call sub_53E070 with dword_8B78A0, this, dword_8B8F0C and parameters a2, a3, a4, a5, a6; a nonzero return causes -1. [callee:0x0053E070, global:0x008B78A0, global:0x008B8F0C, source:raw]
    // CALL: Call EmptyStub_c440(1), a no-op stub invoked after the audio subsystem setup succeeds. [callee:0x0055C440, source:raw]
    // RETURN: Return 0 on success; return -1 on null head, end-of-list without match, or sub_53E070 failure. [function:0x0055BD20, source:raw]

    // Conservative worker pseudocode:
    //   int sub_55BD20(void *this, int a2, int a3, int a4, int a5, int a6) {
    //     Node *node = this->listHead;              // this[72], offset 0x120
    //     if (!node) return -1;
    //     int index = 0;
    //     while (node->field2 != a2 || node->field3 != a3 || node->field5 != a4 || (a6 && node->field6 != a6)) {
    //       node = node->next;
    //       ++index;
    //       if (!node) return -1;
    //     }
    //     this->selectedIndex = index;              // this[70], offset 0x118
    //     dword_8B8DD4 = a2;
    //     dword_8B8DD8 = a3;
    //     dword_8B8DE4 = a4;
    //     dword_8B8DEC = a5 & 1;
    //     if (sub_53E070((int)dword_8B78A0, this, dword_8B8F0C, a2, a3, a4, a5, a6)) return -1;
    //     EmptyStub_c440(1);
    //     return 0;
    //   }
    // UNRESOLVED: Node element type and the meaning of each matched dword (reported as width/height/format/loop in the skeleton) are not independently evidenced here.
    // UNRESOLVED: Semantics of the four written globals beyond 'selected audio/screen parameters' is DERIVED from the skeleton, not raw evidence.
    // UNRESOLVED: Single known caller is ArraySlotCheckConditionalCall (0x0055BFF0); the invocation context that supplies a2..a6 is not examined in this packet.
}
