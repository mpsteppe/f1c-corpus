// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DCDD0
// Canonical corpus name: PositionComputationWithAlignment
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PositionComputationWithAlignment_004dcdd0.c

void UnknownObject::PositionComputationWithAlignment()
{
    // Computes and stores a screen position under one of nine alignment modes. Stores a4 into the Z/size field at offset 0x10, then computes X (offset 0x8) and Y (offset 0xC) from the anchor (a2, a3) and the object's width (offset 0x14) and height (offset 0x18) according to the mode a5 (0-8) selected via the jump table at 0x004DCEBC, and finally renders through sub_4DCA80. Modes 0-5 anchor one corner exactly; modes 6-8 center vertically and/or horizontally.
    // ASSIGNMENT: Store a4 into this[4], the Z/size field at offset 0x10, unconditionally at entry. [field:this:0x00000010]
    // STATE_TRANSITION: Dispatch on alignment mode a5 (0-8) through the jump table jpt_4DCDE4 at 0x004DCEBC; any value outside 0-8 falls through to the default path. [global:0x004DCEBC, source:raw]
    // CALCULATION: Compute the X anchor offset from a2: unshifted for modes 0,3,6; a2 - width (offset 0x14) for modes 1,4,7; a2 - width/2 for modes 2,5,8. [field:this:0x00000014]
    // ASSIGNMENT: Write the computed X into this[2], the position field at offset 0x8. [field:this:0x00000008]
    // CALCULATION: Compute the Y anchor offset from a3: unshifted for modes 0,1,2; a3 - height (offset 0x18) for modes 3,4,5; a3 - height/2 for modes 6,7,8. [field:this:0x00000018]
    // ASSIGNMENT: Write the computed Y into this[3], the position field at offset 0xC. [field:this:0x0000000C]
    // CALL: Call sub_4DCA80(this) to render the element using the stored position fields; executed on every path, including the default case that leaves positions untouched. [callee:0x004DCA80]
    // RETURN: Return sub_4DCA80's result from each path. [callee:0x004DCA80, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4DCDD0(int* this, int a2, int a3, int a4, int a5) {
    //     this[4] = a4;
    //     switch (a5) {
    //       case 0: this[2] = a2;             this[3] = a3;             break;
    //       case 1: this[2] = a2 - this[5];   this[3] = a3;             break;
    //       case 2: this[2] = a2 - this[5]/2; this[3] = a3;             break;
    //       case 3: this[2] = a2;             this[3] = a3 - this[6];   break;
    //       case 4: this[2] = a2 - this[5];   this[3] = a3 - this[6];   break;
    //       case 5: this[2] = a2 - this[5]/2; this[3] = a3 - this[6];   break;
    //       case 6: this[2] = a2;             this[3] = a3 - this[6]/2; break;
    //       case 7: this[2] = a2 - this[5];   this[3] = a3 - this[6]/2; break;
    //       case 8: this[2] = a2 - this[5]/2; this[3] = a3 - this[6]/2; break;
    //     }
    //     return sub_4DCA80(this);
    //   }
    // UNRESOLVED: Semantic role of a4 stored at offset 0x10 (Z/size per prior analysis) is not verifiable from this function alone
    // UNRESOLVED: Default path invokes sub_4DCA80 without modifying the position fields, so an out-of-range mode renders at the previous position
    // UNRESOLVED: The exact UI object type owning offsets 0x8-0x18 is unknown; the 9-point alignment interpretation is inherited from the prior analysis
}
