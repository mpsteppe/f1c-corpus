// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047C860
// Canonical corpus name: UILoadingPercentDisplay
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UILoadingPercentDisplay_0047c860.c

void UnknownObject::UILoadingPercentDisplay()
{
    // Reads a loading-progress float via a vtable dispatch at offset 0xB4, converts it to a "%d%%" string in a stack buffer, and conditionally dispatches loading events based on the mode value at field 0xFC (230 = threshold-gated dispatch, 232 = global dispatch). The formatted buffer is finally copied through StringCopyWithBufferRealloc. Returns 0.
    // ASSIGNMENT: Initialize stack buffer v7: copy byte_5EA438[0] as prefix, zero the following 0x3C bytes, and clear trailing v8/v9 words. [global:0x005EA438, source:raw]
    // CALL: Read the vtable pointer at field 0x0 and invoke the virtual method at vtable offset 0xB4 to obtain a pointer to the loading progress float. [field:this:0x00000000, field:obj:0x000000B4]
    // GUARD: Proceed only if the returned progress float pointer is non-null. [field:obj:0x000000B4]
    // CALCULATION: Convert progress to a percentage integer: CRTFtol(progress * 100.0 + 0.5). [callee:0x00587BDC, source:raw]
    // CALL: Format the percentage into buffer v7 as "%d%%" via StringFormatWithBufferOverflowCheck. [callee:0x0058815F]
    // GUARD: If field 0xFC equals 230 (0xE6), take the threshold-gated dispatch branch. [guard:1, field:this:0x000000FC]
    // CALL: Dispatch the loading event with threshold gating: ThresholdGatedVirtualDispatch(flt_5EA618, progress). [callee:0x00418970, global:0x005EA618]
    // GUARD: Else if field 0xFC equals 232 (0xE8), take the global dispatch branch. [guard:0, field:this:0x000000FC]
    // CALL: Dispatch the loading event globally: GlobalDispatchWithGuard(progress as dword). [callee:0x004C8900]
    // CALL: Copy the formatted buffer via StringCopyWithBufferRealloc. [callee:0x00566650]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int UILoadingPercentDisplay(void *this) {
    //       char buf[61];
    //       buf[0] = byte_5EA438[0];
    //       memset(&buf[1], 0, 0x3C);
    //       int *vt = *this;
    //       float *progress = (float *)vt[0xB4 / 4](this);
    //       if (progress) {
    //           int percent = CRTFtol(*progress * 100.0f + 0.5f);
    //           StringFormatWithBufferOverflowCheck(buf, "%d%%", percent);
    //           if (this->field_FC == 230)
    //               ThresholdGatedVirtualDispatch(flt_5EA618, *progress);
    //           else if (this->field_FC == 232)
    //               GlobalDispatchWithGuard(*(int *)progress);
    //       }
    //       StringCopyWithBufferRealloc(buf);
    //       return 0;
    //   }
    // UNRESOLVED: Exact object type behind this pointer and the vtable+0xB4 accessor are unknown; progress pointer is interpreted as float* but stored/read as dword for GlobalDispatchWithGuard.
    // UNRESOLVED: Semantics of dispatch-mode constants 230 and 232 at field 0xFC are not further resolved.
    // UNRESOLVED: The per-compilation-unit globals flt_59E450, flt_59E6F8, aD, and byte_8AC494 have no direct role in this function.
}
