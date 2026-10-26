// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A58B0
// Canonical corpus name: PitRepairStatusDisplay
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PitRepairStatusDisplay_004a58b0.c

void UnknownObject::PitRepairStatusDisplay()
{
    // Formats and refreshes a pit-repair HUD widget: computes a fuel/time basis value, writes a fuel quantity string, resolves the current part name through the string table, formats repair progress counters, and selects Repair/Do-Not-Repair and part-label strings based on internal mode flags and a vtable-provided part count.
    // CALCULATION: Compute v18 = (double)this[0x6C] * (double)this[0x60] + (double)this[0x58]; the fuel/time basis used by later formatting branches. [field:this:0x00000058, field:this:0x00000060, field:this:0x0000006C, source:raw]
    // GUARD: If this[0x17C] == 0.0, blank local buffer v19; otherwise format v19 via CRTFtol(this[0x17C]*v18) and StringFormatWithBufferOverflowCheck with format data off_5CCEA4. [field:this:0x0000017C, callee:0x00587BDC, callee:0x0058815F, global:0x005CCEA4, source:raw]
    // GUARD: Branch on dword_7D0450: if ==1 format the fuel string at this+0x76 as '%4.1f%s' using v18 * 0.2641720372841846; otherwise use CRTFtol(v18 + 0.5) formatted '%d%s'. [global:0x007D0450, callee:0x00587BDC, callee:0x0058815F, source:raw]
    // CALL: NthValidPartLookup(this, this[0xAC]) returns a part-name pointer v4, or NULL when no valid part matches the current index. [callee:0x004A5820, field:this:0x000000AC, source:raw]
    // CALL: Select part name v7 = *v4 (fallback byte_5EA438 when the pointer is empty); if BinarySearchInStringTable(byte_5EC4C0, v7, byte_5EC4CC) succeeds, copy v7 into byte_5EC4CC (or blank it when NULL). When v4 is NULL, search aNoChange instead and copy it byte-by-byte into byte_5EC4CC. [callee:0x00423A00, global:0x005CD664, global:0x005EA438, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(this+0xB6, '%s', byte_5EC4CC) writes the part label string into the widget struct. [callee:0x0058815F, global:0x005EC4CC, source:raw]
    // CALCULATION: Read progress counters this[0xEC] and this[0xF0]; format this+0xF6 as '%d' when equal, '%d (-%d)' when this[0xEC] <= this[0xF0], else '%d (+%d)'. [field:this:0x000000EC, field:this:0x000000F0, callee:0x0058815F, source:raw]
    // GUARD: When this[0x128] == 1, copy the off_5C3810 content into byte_5EC4CC via the string table; otherwise select aRepair or aDoNotRepair based on this[0x12C] and copy the chosen label into byte_5EC4CC. [guard:1, field:this:0x00000128, field:this:0x0000012C, callee:0x00423A00, global:0x005C3810, global:0x005CD634, global:0x005CD644, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(this+0x136, '%s', byte_5EC4CC) writes the repair-action status label. [callee:0x0058815F, global:0x005EC4CC, source:raw]
    // GUARD: When this[0x28] == 1, format this+0x36 with the off_5C3810 content; otherwise fetch total part count v16 from the vtable (*(*(DWORD*)this + 0x4074)), pick the label source off_5C6E14 or unk_5C6E18 by this[0x2C], copy it into byte_5EC4CC and format this+0x36 as '%s/%d'. [guard:0, field:this:0x00000000, field:this:0x00000028, field:this:0x0000002C, field:obj:0x00004074, callee:0x00423A00, callee:0x0058815F, global:0x005C3810, global:0x005C6E14, global:0x005C6E18, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // RETURN: Return the result of the final StringFormatWithBufferOverflowCheck call on this+0x36. [source:raw]

    // Conservative worker pseudocode:
    //   double basis = this->f[0x6C] * this->d[0x60] + this->d[0x58];
    //   char suffix[64]; suffix[0] = 0;
    //   if (this->f[0x17C] != 0.0f) CRTFtolInto(suffix, &off_5CCEA4, this->f[0x17C] * basis);
    //   if (dword_7D0450 == 1) Format(this+0x76, "%4.1f%s", basis * 0.2641720372841846, suffix);
    //   else Format(this+0x76, "%d%s", CRTFtol(basis + 0.5), suffix);
    //   const char** pp = NthValidPartLookup(this, this->i[0xAC]);
    //   const char* part = pp ? *pp : 0; if (pp && !part) part = byte_5EA438;
    //   const char* src = pp ? part : aNoChange;
    //   if (BinarySearchInStringTable(byte_5EC4C0, src, byte_5EC4CC)) CopyOrBlank(byte_5EC4CC, src);
    //   Format(this+0xB6, "%s", byte_5EC4CC);
    //   if (this->i[0xEC] == this->i[0xF0]) Format(this+0xF6, "%d", this->i[0xEC] + 1);
    //   else if (this->i[0xEC] <= this->i[0xF0]) Format(this+0xF6, "%d (-%d)", this->i[0xEC]+1, this->i[0xF0]-this->i[0xEC]);
    //   else Format(this+0xF6, "%d (+%d)", this->i[0xEC]+1, this->i[0xEC]-this->i[0xF0]);
    //   if (this->i[0x128] == 1) { if (BinarySearchInStringTable(byte_5EC4C0, (const char*)&off_5C3810, byte_5EC4CC)) CopyBytes(byte_5EC4CC, &off_5C3810); }
    //   else { const char* act = this->i[0x12C] ? aRepair : aDoNotRepair; if (BinarySearchInStringTable(byte_5EC4C0, act, byte_5EC4CC)) CopyOrBlank(byte_5EC4CC, act); }
    //   Format(this+0x136, "%s", byte_5EC4CC);
    //   if (this->i[0x28] == 1) { if (BinarySearchInStringTable(byte_5EC4C0, (const char*)&off_5C3810, byte_5EC4CC)) CopyBytes(byte_5EC4CC, &off_5C3810); return Format(this+0x36, "%s", byte_5EC4CC); }
    //   int count = (*(int**)(this+0))[0x4074/4]; const char* label = this->i[0x2C] ? off_5C6E14 : unk_5C6E18;
    //   if (BinarySearchInStringTable(byte_5EC4C0, label, byte_5EC4CC)) CopyOrBlank(byte_5EC4CC, label);
    //   return Format(this+0x36, "%s/%d", byte_5EC4CC, count);
    // UNRESOLVED: The packet global table lists string/data constants aS_4, aD_1, aSD_0, aDD_3, aDD_2, aDS_6, a41fS and float/double constants flt_59E440, dbl_59E880, dbl_59EA40 that the visible source does not reference; they are presumed format strings and fuel-unit conversion constants from the fuller decompile, but the exact usage is not evidenced, so no operation is attributed to them.
    // UNRESOLVED: The fuel double 0.2641720372841846 and the +0.5 rounding term are literals in the visible source; a mapping onto dbl_59E880 / dbl_59EA40 is not evidenced.
    // UNRESOLVED: String destination offsets (this+0x36, +0x76, +0xB6, +0xF6, +0x136) are written but absent from the packet field list, so they carry only source:raw evidence.
    // UNRESOLVED: The two named guards (guard:0 this[0x28]==1, guard:1 this[0x128]==1) are the only guard evidence refs; the remaining numeric comparisons (this[0x17C]==0.0, dword_7D0450==1, counter comparisons, this[0x12C]) are described under source:raw only.
}
