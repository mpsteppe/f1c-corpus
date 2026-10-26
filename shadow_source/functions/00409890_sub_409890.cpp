// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00409890
// Canonical corpus name: sub_409890
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_409890_00409890.c

void UnknownObject::sub_409890()
{
    // Mirror-view render setup invoked from the main camera/director update. Guards on a global handle via ValueGetter, searches the linked list for the mirror bitmap, chooses rear-view vs main-view rendering based on a 0x40000 capability flag on the mirror object, caches the mirror object pointer in this+0xC, arms the physics parameter set and a follow-up dispatch, and finally issues a clipped draw using the mirror object's stored width/height and the unk_686B75 render payload. Always returns 0.
    // GUARD: Guard the whole body on ValueGetter(dword_8AFE88) being nonzero; otherwise return 0 without doing anything. [callee:0x00545F40, global:0x008AFE88]
    // CALL: Search the linked list for the mirror bitmap by name aMirrorBmp via StringSearchInLinkedList and keep the resulting object pointer in a local. [callee:0x00547920, global:0x005BE91C]
    // GUARD: Test the mirror object's capability flag at (object+84)+24 for bit 0x40000 to decide between rear-view and main-view. [source:raw]
    // ASSIGNMENT: Set the rear-view search result field this+0x8 either to the result of TwoLevelWideStringSearch(aRearview) when the 0x40000 flag is set, or to 0 when it is clear. [callee:0x00544F50, global:0x005BE8EC, field:this:0x00000008]
    // GUARD: Only proceed with the view configuration when the rear-view search result stored in this+0x8 is nonzero. [field:this:0x00000008]
    // ASSIGNMENT: Store the mirror object's +84 pointer into this+0xC (view parameter block). [field:this:0x0000000C]
    // CALL: Push the view parameter block from this+0xC into the physics parameter set via SuspensionPhysicsParameterSet. [callee:0x00542560, field:this:0x0000000C]
    // CALL: When TwoLevelWideStringSearch(aMainview) succeeds, register a follow-up pointer pair through PointerStorePair2 targeting sub_409950. [callee:0x00544F50, global:0x005BE8E0, callee:0x00542540, global:0x00409950]
    // CALL: Dispatch the conditional render pipeline for this object via ConditionalRenderPipelineDispatch(this). [callee:0x00409970]
    // CALL: Issue a clipped draw with RenderDrawOperationWithClipping using width/height read at +28 and +32 of the view parameter block stored in this+0xC, and the unk_686B75 payload. [callee:0x00543440, field:this:0x00000028, field:this:0x0000002C, global:0x00686B75]
    // RETURN: Always return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_409890(void *this, int arg) {
    //     if (!ValueGetter(dword_8AFE88)) return 0;
    //     mirror = StringSearchInLinkedList(aMirrorBmp);
    //     if (mirror) {
    //       if ((*(mirror + 84) + 24) & 0x40000)
    //         this->view_result = TwoLevelWideStringSearch(aRearview);
    //       else
    //         this->view_result = 0;
    //       if (this->view_result) {
    //         this->view_params = *(mirror + 84);
    //         SuspensionPhysicsParameterSet(this->view_params);
    //         if (TwoLevelWideStringSearch(aMainview))
    //           PointerStorePair2(sub_409950, 0);
    //         ConditionalRenderPipelineDispatch(this);
    //       }
    //       RenderDrawOperationWithClipping(0, 0,
    //           *(this->view_params + 28), *(this->view_params + 32), &unk_686B75);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The object type and exact structure of the mirror object returned by StringSearchInLinkedList are not recoverable from this packet.
    // UNRESOLVED: The identity and layout of the unk_686B75 render payload passed to RenderDrawOperationWithClipping are unknown.
    // UNRESOLVED: What dword_8AFE88 actually gates (render enable vs geometry availability) is unresolved; it is only known to be tested via ValueGetter.
    // UNRESOLVED: Meaning of the unused argument a2 is unknown.
}
