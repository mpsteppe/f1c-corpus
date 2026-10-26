// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005159F5
// Canonical corpus name: TextureSurfaceValidator
// Owner: TextureSurfaceValidator [DERIVED]
// Raw source: functions/TextureSurfaceValidator_005159f5.c

void TextureSurfaceValidator::validateSurfaceDescriptors()
{
    // Validates texture surface parameters against fixed limits (dimensions <= 65500, sub-surface count <= 10, pixel format == 8, per-descriptor factor pair within [1,4]), reporting each failure through the object's vtable callback while continuing execution. Then runs two passes over the sub-surface descriptor array at this+0xC4 (84-byte stride): the first accumulates maximum width/height factors into this+0x10C/0x110, the second computes each descriptor's aligned dimensions and strides via CeilingDivision against those maxima. Finally refreshes the output surface active flag at *(this+0x18C)+0x10 when the output surface count is stale or the this+0xC8 flag is set.
    // GUARD: If texture total width (this+0x18) or total height (this+0x1C) exceeds 65500, proceed to report the oversized dimension. [guard:2, guard:3, field:this:0x00000018, field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Set error code slot obj+0x14 (obj = *(this+0)) to 40 for an oversized texture dimension. [field:obj:0x00000014, field:this:0x00000000]
    // ASSIGNMENT: Set error detail slot obj+0x18 to 65500 (the dimension clamp limit). [field:obj:0x00000018]
    // CALL: Invoke the object's vtable callback through the pointer at this+0 to report the dimension failure; execution continues after the call. [field:this:0x00000000, field:obj:0x00000000]
    // GUARD: If expected pixel format (this+0xC0) is not 8, proceed to report the format mismatch. [guard:6, field:this:0x000000C0, source:raw]
    // ASSIGNMENT: Set error code slot obj+0x14 to 13 for the pixel format mismatch. [field:obj:0x00000014]
    // ASSIGNMENT: Set error detail slot obj+0x18 to the offending pixel format value (this+0xC0). [field:obj:0x00000018, field:this:0x000000C0]
    // CALL: Invoke the object's vtable callback through the pointer at this+0 to report the format failure. [field:this:0x00000000, field:obj:0x00000000]
    // GUARD: If sub-surface count (this+0x20) exceeds 10, proceed to report the oversized count. [guard:5, field:this:0x00000020, source:raw]
    // ASSIGNMENT: Set error code slot obj+0x14 to 24 for the oversized sub-surface count. [field:obj:0x00000014]
    // ASSIGNMENT: Set error detail slot obj+0x18 to the offending count (this+0x20). [field:obj:0x00000018, field:this:0x00000020]
    // ASSIGNMENT: Set error detail slot obj+0x1C to 10 (the accepted count limit). [field:obj:0x0000001C]
    // CALL: Invoke the object's vtable callback through the pointer at this+0 to report the count failure. [field:this:0x00000000, field:obj:0x00000000]
    // ASSIGNMENT: Initialize maximum width factor accumulator this+0x10C to 1. [field:this:0x0000010C]
    // ASSIGNMENT: Initialize maximum height factor accumulator this+0x110 to 1. [field:this:0x00000110]
    // LOOP: First pass: loop over the first this+0x20 descriptors of the array at this+0xC4 (84-byte stride), skipping entirely when the count is <= 0. [guard:4, field:this:0x00000020, field:this:0x000000C4]
    // GUARD: If the sub-surface height factor (*(this+0xC4)+0xC; the width factor at +8 is checked the same way) is not within [1,4], proceed to report a factor validation failure. [guard:0, guard:1, field:*(this+0xC4):0x0000000C]
    // ASSIGNMENT: Set error code slot obj+0x14 to 16 for an out-of-range factor. [field:obj:0x00000014]
    // CALL: Invoke the object's vtable callback through the pointer at this+0 to report the factor failure; the loop continues. [field:this:0x00000000, field:obj:0x00000000]
    // CALCULATION: Accumulate this+0x10C as the maximum width factor seen across descriptors. [field:this:0x0000010C]
    // CALCULATION: Accumulate this+0x110 as the maximum height factor seen across descriptors. [field:this:0x00000110]
    // ASSIGNMENT: Set shared output pixel format this+0x114 to 8. [field:this:0x00000114]
    // LOOP: Second pass: loop over the first this+0x20 descriptors of the array at this+0xC4 (84-byte stride), skipping entirely when the count is <= 0, computing per-descriptor aligned dimensions, strides and flags. [guard:4, field:this:0x00000020, field:this:0x000000C4, callee:0x00515917]
    // ASSIGNMENT: Set each sub-surface descriptor pixel format (*(this+0xC4)+0x24) to 8. [field:*(this+0xC4):0x00000024]
    // CALCULATION: Compute aligned width *(this+0xC4)+0x1C = CeilingDivision(total width * width factor, 8 * max width factor). [callee:0x00515917, field:*(this+0xC4):0x0000001C, field:this:0x00000018, field:this:0x0000010C]
    // CALCULATION: Compute aligned height *(this+0xC4)+0x20 = CeilingDivision(total height * height factor, 8 * max height factor). [callee:0x00515917, field:*(this+0xC4):0x00000020, field:this:0x0000001C, field:this:0x00000110]
    // CALCULATION: Compute padded stride width *(this+0xC4)+0x28 = CeilingDivision(total width * width factor, max width factor). [callee:0x00515917, field:*(this+0xC4):0x00000028, field:this:0x00000018, field:this:0x0000010C]
    // CALCULATION: Compute padded stride height *(this+0xC4)+0x2C = CeilingDivision(total height * height factor, max height factor). [callee:0x00515917, field:*(this+0xC4):0x0000002C, field:this:0x0000001C, field:this:0x00000110]
    // ASSIGNMENT: Clear the descriptor dirty/modified flag *(this+0xC4)+0x4C to 0. [field:*(this+0xC4):0x0000004C]
    // ASSIGNMENT: Set the descriptor stride-valid flag byte *(this+0xC4)+0x30 to 1. [field:*(this+0xC4):0x00000030]
    // CALCULATION: Compute this+0x118 = CeilingDivision(total height, 8 * max height factor). [callee:0x00515917, field:this:0x00000118, field:this:0x0000001C, field:this:0x00000110]
    // GUARD: If tracked output surface count (this+0x120) is less than the sub-surface count (this+0x20), or the byte flag at this+0xC8 is non-zero, mark the output surface state for refresh. [field:this:0x00000120, field:this:0x00000020, field:this:0x000000C8]
    // ASSIGNMENT: Set the output surface active flag byte *(this+0x18C)+0x10 to 1 (needs refresh). [field:*(this+0x18C):0x00000010, field:this:0x0000018C]
    // ASSIGNMENT: Else, clear the output surface active flag byte *(this+0x18C)+0x10 to 0. [field:*(this+0x18C):0x00000010, field:this:0x0000018C]
    // RETURN: Return the output surface state pointer (this+0x18C). [source:raw, field:this:0x0000018C]

    // Conservative worker pseudocode:
    //   // Report failure via *(this+0) vtable callback, then continue.
    //   if (this->width > 65500 || this->height > 65500) reportError(40, 65500);
    //   if (this->format != 8) reportError(13, this->format);
    //   if (this->surfaceCount > 10) reportError(24, this->surfaceCount, 10);
    //   
    //   // Pass 1: validate factor pairs, accumulate maxima.
    //   this->maxWidthFactor = 1; this->maxHeightFactor = 1;
    //   for (i = 0; i < this->surfaceCount; i++) {
    //     desc = &this->descriptors[i];
    //     if (desc->wFactor < 1 || desc->wFactor > 4 || desc->hFactor < 1 || desc->hFactor > 4) reportError(16, 0);
    //     this->maxWidthFactor = max(this->maxWidthFactor, desc->wFactor);
    //     this->maxHeightFactor = max(this->maxHeightFactor, desc->hFactor);
    //   }
    //   
    //   // Pass 2: compute aligned dimensions and strides.
    //   this->pixelFormat = 8;
    //   for (i = 0; i < this->surfaceCount; i++) {
    //     desc = &this->descriptors[i];
    //     desc->format = 8;
    //     desc->alignedWidth = CeilingDivision(this->width * desc->wFactor, 8 * this->maxWidthFactor);
    //     desc->alignedHeight = CeilingDivision(this->height * desc->hFactor, 8 * this->maxHeightFactor);
    //     desc->strideWidth = CeilingDivision(this->width * desc->wFactor, this->maxWidthFactor);
    //     desc->strideHeight = CeilingDivision(this->height * desc->hFactor, this->maxHeightFactor);
    //     desc->dirty = 0; desc->valid = 1;
    //   }
    //   this->totalAlignedHeight = CeilingDivision(this->height, 8 * this->maxHeightFactor);
    //   
    //   // Refresh output surface state.
    //   out = this->outputSurfaceState;
    //   out->active = (this->trackedCount < this->surfaceCount || this->flagC8) ? 1 : 0;
    //   return out;
    // UNRESOLVED: Semantics of the obj+0x14 / obj+0x18 / obj+0x1C slots (error code vs error detail) are DERIVED from literal usage, not named in any evidence.
    // UNRESOLVED: The indirect vtable call through the pointer at this+0 has no callee evidence; whether it aborts or merely reports is unknown.
    // UNRESOLVED: Meaning of the this+0xC8 byte flag in the final refresh condition is unknown.
    // UNRESOLVED: Meaning of this+0x120 (compared against sub-surface count) is unknown.
    // UNRESOLVED: Whether the descriptor stride fields at +0x28/+0x2C are byte or pixel strides is unknown.
    // UNRESOLVED: The per-descriptor width factor at *(this+0xC4)+0x8 is range-checked in the source loop but has no dedicated packet field/guard evidence reference (only the height factor +0xC is captured).
}
