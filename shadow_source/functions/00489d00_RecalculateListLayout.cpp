// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00489D00
// Canonical corpus name: sub_489D00
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_489D00_00489d00.c

void UnknownObject::RecalculateListLayout()
{
    // Recalculates a scrollable list layout after content changes: measures the item text width by rendering it to a surface via TextRenderToSurface, computes column and row counts from the layout boundary box, derives the per-page item count and the scroll span, then clamps the scroll offset and the position index. Uses vtable dimension getters (slots 28 and 36) and a ConditionalDelegation_6460 delegate to compute the available height. Skipped entirely when the measured text width is non-positive.
    // ASSIGNMENT: Zero the scratch width v20 and the text-width slot this[86] before measuring. [source:raw, field:this:0x00000158]
    // CALL: When this[50] is non-null, call sub_498560 with the prefix string stored at this[50]+64, defaulting to byte_5EA438 when that pointer is null. [callee:0x00498560, field:this:0x000000C8, global:0x005EA438]
    // CALL: Render the aTtgjz string to a surface via TextRenderToSurface, writing the measured text width into v20/this[86]. [callee:0x004983B0, global:0x005C71CC, field:this:0x00000158]
    // GUARD: If the measured width this[86] <= 0, skip the whole layout recalculation and return early. [guard:0, field:this:0x00000158]
    // ASSIGNMENT: Zero the recomputed layout fields before filling them: this[91], this[89], this[88], this[87], this[85]. [source:raw, field:this:0x0000016C, field:this:0x00000164, field:this:0x00000160, field:this:0x0000015C, field:this:0x00000154]
    // CALCULATION: Compute column count this[77] = (this[2] - this[1]) / 40 + 2 and row count this[78] = (this[4] - this[3]) / 40 + 2 from the layout boundary box. [field:this:0x00000008, field:this:0x00000004, field:this:0x00000134, field:this:0x00000010, field:this:0x0000000C, field:this:0x00000138]
    // CALCULATION: Derive the vertical pixel span this[91] = (this[2] - this[1]) - 2 * columns, the items per page this[89] = this[91] / width, and the scroll span this[88] = this[37] - itemsPerPage clamped to >= 0. [field:this:0x0000016C, field:this:0x00000164, field:this:0x00000160, field:this:0x00000094]
    // CALL: Call ConditionalDelegation_6460(this, 3); if a delegate is returned, set this[87] = delegate[12] - delegate[8]. [callee:0x00486460, field:this:0x0000015C]
    // CALL: Dispatch vtable slot 36 (obj+0x24) to get a dimension, subtract this[87], then subtract the result of vtable slot 28 (obj+0x1C); store the available extent in this[85] clamped to >= 0. [field:obj:0x00000024, field:this:0x0000015C, field:obj:0x0000001C, field:this:0x00000154, field:this:0x00000000]
    // GUARD: Clamp the scroll offset this[83] into [0, this[88]]: if negative set to 0, if above the scroll span set to the span. [field:this:0x0000014C, field:this:0x00000160]
    // CALL: Call FloatToIntConversion(this) after the scroll-offset clamp. [callee:0x00489E90]
    // GUARD: Clamp the position index this[84] into [0, this[85]]; when a clamp fires, set the field and return ShortComputation_9ee0(this). [field:this:0x00000150, field:this:0x00000154, callee:0x00489EE0]
    // RETURN: Return the last computed result (the measured width when the layout was skipped, otherwise the position-index value). [source:raw]

    // Conservative worker pseudocode:
    //   int RecalculateListLayout(int *this) {
    //     int width = 0;
    //     this[86] = 0;
    //     if (this[50]) sub_498560(this[50][64] ? this[50][64] : byte_5EA438);
    //     TextRenderToSurface(aTtgjz, &width, this + 86, 1);
    //     this[91] = 0; this[89] = 0; this[88] = 0; this[87] = 0; this[85] = 0;
    //     if (this[86] <= 0) return width;
    //     this[78] = (this[4] - this[3]) / 40 + 2;
    //     this[91] = (this[2] - this[1]) - 2 * ((this[2] - this[1]) / 40 + 2);
    //     this[77] = (this[2] - this[1]) / 40 + 2;
    //     this[89] = this[91] / this[86];
    //     this[88] = this[37] - this[89];
    //     if (this[88] < 0) this[88] = 0;
    //     if (ConditionalDelegation_6460(this, 3)) this[87] = (*delegate)[12] - (*delegate)[8];
    //     this[85] = vtable[36](this) - this[87] - vtable[28](this);
    //     if (this[85] < 0) this[85] = 0;
    //     if (this[83] > this[88]) this[83] = this[88];
    //     else if (this[83] < 0) this[83] = 0;
    //     FloatToIntConversion(this);
    //     if (this[84] > this[85]) { this[84] = this[85]; return ShortComputation_9ee0(this); }
    //     if (this[84] < 0) { this[84] = 0; return ShortComputation_9ee0(this); }
    //     return result;
    //   }
    // UNRESOLVED: Field this+0x108 (this[66]) is listed as read in the packet but has no reference in the raw source body; its role is unknown.
    // UNRESOLVED: The exact meaning of vtable slots 28 and 36 (dimension getters) and of the this[87] delegate-derived value is DERIVED from layout semantics, not directly evidenced.
}
