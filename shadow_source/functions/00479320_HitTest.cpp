// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00479320
// Canonical corpus name: HitTest
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HitTest_00479320.c

void UnknownObject::HitTest()
{
    // UI hit test over a linked list of coordinate nodes. Reads cursor reference coordinates via DualFieldRead from the object at this+0x40, walks the node list headed at this+0x164 (current cursor at this+0x16C), and for each node compares the reference position against node coordinates offset by this+0xC and this+0x4 within a +/-20 window. On a hit the list is re-walked to compute the node index, which is written to this+0x158 (-1 on a miss).
    // CALL: DualFieldRead(*(this+0x40), &v12, &v11) reads two values from the source object at this+0x40 into v12 and v11. [callee:0x00498880, field:this:0x00000040]
    // ASSIGNMENT: result = *(this+0x164) (list head); the current working pointer this+0x16C is initialized from it. [field:this:0x00000164, field:this:0x0000016C]
    // GUARD: Traversal proceeds only when the head pointer at this+0x164 is non-zero and its node data pointer at +0 is non-zero. [field:this:0x00000164, field:*(this+0x164):0x00000000]
    // LOOP: Linked-list traversal: each list node carries a data pointer at +0 and a next pointer at +4; the head node view is *(this+0x164)+0/+4 and the current node view is *(this+0x16C)+0/+4. [field:*(this+0x164):0x00000000, field:*(*(this+0x164)+0x4):0x00000000, field:*(*(this+0x164)+0x4):0x00000004, field:*(this+0x16C):0x00000000, field:*(this+0x16C):0x00000004, field:this:0x0000016C]
    // CALCULATION: Candidate center v6 = *(this+0xC) + nodeX and v7 = *(this+0x4) + nodeY, where nodeX/nodeY are the first node's coordinate pair at *(*(this+0x164)+0x0)+0 and +4. [field:this:0x0000000C, field:this:0x00000004, field:*(*(this+0x164)+0x0):0x00000000, field:*(*(this+0x164)+0x0):0x00000004]
    // GUARD: Hit test: the reference coordinate (v5 from v12, v4 from v11) must lie within the +/-20 window on both axes (v5 < v6+20 && v5 > v6-20 and v4 < v7+20 && v4 > v7-20); on success the traversal breaks. [field:this:0x0000000C, field:this:0x00000004, source:raw]
    // ASSIGNMENT: On a miss the current pointer this+0x16C advances to the next node through the node's +4 next pointer; the loop repeats until the list ends. [field:this:0x0000016C, field:*(this+0x16C):0x00000004, field:*(this+0x164):0x00000000]
    // CALCULATION: After a hit, the list headed at this+0x164 is walked from the start, counting nodes until the node pointer equals the hit node at this+0x16C, producing the node index i. [field:this:0x00000164, field:this:0x0000016C]
    // ASSIGNMENT: The computed index i is written to this+0x158 as the hit index (-1 when no hit node was found). [field:this:0x00000158]
    // RETURN: Return the traversal result (the hit node pointer, or null on a miss); the function is called by sub_478ED0 (0x00478ED0). [function:0x00479320, caller:0x00478ED0, source:raw]

    // Conservative worker pseudocode:
    //   DualFieldRead(*(this + 0x40), &refX, &refY);
    //   cur = this->head;
    //   this->cur = cur;
    //   if (cur && *cur) {
    //     while (1) {
    //       cx = *(this + 0xC) + (*cur)[0];
    //       cy = *(this + 0x4) + (*cur)[1];
    //       if (refX < cx + 20 && refX > cx - 20 &&
    //           refY < cy + 20 && refY > cy - 20) break;
    //       nxt = *(cur + 4);
    //       this->cur = nxt;
    //       if (!nxt || !*nxt) return nxt;
    //       cur = nxt;
    //     }
    //     idx = -1;
    //     if (this->cur) {
    //       for (p = this->head, i = 0; p; ++i) {
    //         if (p == this->cur) { idx = i; break; }
    //         p = *(p + 4);
    //       }
    //     }
    //     this->hitIndex = idx;
    //   }
    //   return result;
    // UNRESOLVED: The semantic meaning of the +/-20 window (cursor hit tolerance) is inferred from the literal comparisons, not confirmed by a named field.
    // UNRESOLVED: The list node layout (data pointer at +0, next pointer at +4) is inferred from the decompiler field notation.
    // UNRESOLVED: The exact roles of v12/v11 from DualFieldRead and the identity of the object at this+0x40 are caller-context dependent.
}
