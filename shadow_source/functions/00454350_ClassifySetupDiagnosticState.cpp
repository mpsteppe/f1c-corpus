// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00454350
// Canonical corpus name: sub_454350
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_454350_00454350.c

void UnknownObject::ClassifySetupDiagnosticState()
{
    // Classifies the current vehicle setup/damage state into a numeric state ID written to a3, then copies a human-readable label from the aEmpty string table (stride 9) into a2. When a4 is non-zero it first fills two float scratch buffers at globals unk_7CD168 and unk_7CCA8C from per-wheel physics values. It then runs ordered ConstraintForceEval and SweptAABBOverlapDetection passes (indices 0-7) against those scratch buffers to assign state IDs 1-12/102-105 and 30-41/106-109, checks 16 byte-flag fields at this+0x1160..0x116F (states 13-28) and this+0x155C..0x156B (states 42-57), and evaluates two compound sign+value-match blocks gated on the sign of this+0x1180 (states 70-85) and this+0x157C (states 86-101). Returns 1 and copies the label when any state matched, 0 when the default -1 persisted.
    // GUARD: Guard on a4: the two float scratch-buffer fill loops run only when a4 is non-zero. [source:raw]
    // LOOP: Float fill loop 1: for i=96; i<128; i+=4, write (value at this+4288+i minus value at this+3460+i) times value at this+3428+i into the global scratch region indexed as unk_7CD168 + i - 100. [global:0x007CD168, source:raw]
    // LOOP: Float fill loop 2: for j=96; j<128; j+=4, write (value at this+5308+j minus value at this+4480+j) times value at this+4448+j into the global scratch region indexed as unk_7CCA8C + j - 100; this+4448 and this+4480 are read here as floats. [global:0x007CCA8C, field:this:0x00001160, field:this:0x00001180, source:raw]
    // ASSIGNMENT: Default the state output: *a3 = -1 before any classification runs. [source:raw]
    // CALL: First ordered evaluation block against scratch unk_7CD168: ConstraintForceEval(this, 0..7, 0, &unk_7CD168) assigns states 1,3,5,7,9,11,102,104 and SweptAABBOverlapDetection(this, 0..7, 0, &unk_7CD168) assigns 2,4,6,8,10,12,103,105 on truth. [callee:0x00454250, callee:0x004542D0, global:0x007CD168, source:raw]
    // ASSIGNMENT: Byte-flag fan-out 1: each non-zero byte at this+0x1160..0x116F assigns state 13..28 respectively. [field:this:0x00001160, field:this:0x00001161, field:this:0x00001162, field:this:0x00001163, field:this:0x00001164, field:this:0x00001165, field:this:0x00001166, field:this:0x00001167, field:this:0x00001168, field:this:0x00001169, field:this:0x0000116A, field:this:0x0000116B, field:this:0x0000116C, field:this:0x0000116D, field:this:0x0000116E, field:this:0x0000116F, source:raw]
    // GUARD: Sign guard on this+0x1180 < 0 gates the first compound value-match block (states 70-85). [guard:0, field:this:0x00001180, source:raw]
    // ASSIGNMENT: this+0x1170 compared equal to dword_7CD1BC, dword_7CD1D4, dword_7CCF5C, dword_7CD1EC assigns states 70, 71, 72, 73 respectively. [field:this:0x00001170, global:0x007CD1BC, global:0x007CD1D4, global:0x007CCF5C, global:0x007CD1EC, source:raw]
    // GUARD: Bit test (dword at this+0x1180 & 0x100) gates the next four value matches. [field:this:0x00001180, source:raw]
    // ASSIGNMENT: this+0x1174 compared equal to dword_7CD0AC, dword_7CD0C4, dword_7CD12C, dword_7CD144 assigns states 74, 75, 76, 77 respectively. [field:this:0x00001174, global:0x007CD0AC, global:0x007CD0C4, global:0x007CD12C, global:0x007CD144, source:raw]
    // GUARD: Bit test (dword at this+0x1180 & 0x200) gates the next four value matches. [field:this:0x00001180, source:raw]
    // ASSIGNMENT: this+0x1178 compared equal to dword_7CD018, dword_7CD048, dword_7CD0DC, dword_7CD0F4 assigns states 78, 79, 80, 81 respectively. [field:this:0x00001178, global:0x007CD018, global:0x007CD048, global:0x007CD0DC, global:0x007CD0F4, source:raw]
    // GUARD: Bit test (dword at this+0x1180 & 0x400) gates the final four value matches of this block. [field:this:0x00001180, source:raw]
    // ASSIGNMENT: this+0x117C compared equal to dword_7CCA10, dword_7CCA40, dword_7CD060, dword_7CD078 assigns states 82, 83, 84, 85 respectively. [field:this:0x0000117C, global:0x007CCA10, global:0x007CCA40, global:0x007CD060, global:0x007CD078, source:raw]
    // CALL: Second ordered evaluation block against scratch unk_7CCA8C: ConstraintForceEval(this, 0..7, 1, &unk_7CCA8C) assigns states 30,32,34,36,38,40,106,108 and SweptAABBOverlapDetection(this, 0..7, 1, &unk_7CCA8C) assigns 31,33,35,37,39,41,107,109 on truth. [callee:0x00454250, callee:0x004542D0, global:0x007CCA8C, source:raw]
    // ASSIGNMENT: Byte-flag fan-out 2: each non-zero byte at this+0x155C..0x156B assigns state 42..57 respectively. [field:this:0x0000155C, field:this:0x0000155D, field:this:0x0000155E, field:this:0x0000155F, field:this:0x00001560, field:this:0x00001561, field:this:0x00001562, field:this:0x00001563, field:this:0x00001564, field:this:0x00001565, field:this:0x00001566, field:this:0x00001567, field:this:0x00001568, field:this:0x00001569, field:this:0x0000156A, field:this:0x0000156B, source:raw]
    // GUARD: Sign guard on this+0x157C < 0 gates the second compound value-match block (states 86-101). [guard:1, field:this:0x0000157C, source:raw]
    // ASSIGNMENT: this+0x156C compared equal to dword_7CCFD8, dword_7CD000, dword_7CD094, dword_7CD030 assigns states 86, 87, 88, 89 respectively. [field:this:0x0000156C, global:0x007CCFD8, global:0x007CD000, global:0x007CD094, global:0x007CD030, source:raw]
    // GUARD: Bit test (dword at this+0x157C & 0x100) gates the next four value matches. [field:this:0x0000157C, source:raw]
    // ASSIGNMENT: this+0x1570 compared equal to dword_7CA548, dword_7CA578, dword_7CCA28, dword_7CCA68 assigns states 90, 91, 92, 93 respectively. [field:this:0x00001570, global:0x007CA548, global:0x007CA578, global:0x007CCA28, global:0x007CCA68, source:raw]
    // GUARD: Bit test (dword at this+0x157C & 0x200) gates the next four value matches. [field:this:0x0000157C, source:raw]
    // ASSIGNMENT: this+0x1574 compared equal to dword_7CA4CC, dword_7CA4F4, dword_7CA560, dword_7CA530 assigns states 94, 95, 96, 97 respectively. [field:this:0x00001574, global:0x007CA4CC, global:0x007CA4F4, global:0x007CA560, global:0x007CA530, source:raw]
    // GUARD: Bit test (dword at this+0x157C & 0x400) gates the final four value matches of this block. [field:this:0x0000157C, source:raw]
    // ASSIGNMENT: this+0x1578 compared equal to dword_7CA434, dword_7CA40C, dword_7CA4B4, dword_7CA46C assigns states 98, 99, 100, 101 respectively; the 101 branch is the path that guarantees a label copy. [field:this:0x00001578, global:0x007CA434, global:0x007CA40C, global:0x007CA4B4, global:0x007CA46C, source:raw]
    // CALL: Label copy (LABEL_207): when *a3 != -1, strcpy(a2, &aEmpty[9 * *a3]) writes the 9-byte-stride label selected by the final state ID. [global:0x005C44B0, source:raw]
    // RETURN: Return 1 when a state was matched (label copied), 0 when the default -1 persisted; sole caller is ParameterLookupWithFallback (0x00454D30). [caller:0x00454D30, source:raw]

    // Conservative worker pseudocode:
    //   char sub_454350(int this, char *a2, int *a3, int a4) {
    //     if (a4) {
    //       for (i = 96; i < 128; i += 4) scratch1[i-100] = (f(this+4288+i) - f(this+3460+i)) * f(this+3428+i);
    //       for (j = 96; j < 128; j += 4) scratch2[j-100] = (f(this+5308+j) - f(this+4480+j)) * f(this+4448+j);
    //     }
    //     *a3 = -1;
    //     for (k = 0..7) { if (ConstraintForceEval(this, k, 0, &scratch1)) *a3 = state; if (SweptAABBOverlapDetection(this, k, 0, &scratch1)) *a3 = state; }
    //     if (byte[0x1160..0x116F]) *a3 = 13..28;
    //     if (this+0x1180 < 0) { if (dword[0x1170] == T1..T4) *a3 = 70..73; if (dword[0x1180] & 0x100) { 74..77 } if (& 0x200) { 78..81 } if (& 0x400) { 82..85 } }
    //     for (k = 0..7) { if (ConstraintForceEval(this, k, 1, &scratch2)) *a3 = state; if (SweptAABBOverlapDetection(this, k, 1, &scratch2)) *a3 = state; }
    //     if (byte[0x155C..0x156B]) *a3 = 42..57;
    //     if (this+0x157C < 0) { if (dword[0x156C] == T1..T4) *a3 = 86..89; if (& 0x100) { 90..93 } if (& 0x200) { 94..97 } if (& 0x400) { 98..101 } }
    //     if (*a3 != -1) { strcpy(a2, &aEmpty[9 * *a3]); return 1; }
    //     return 0;
    //   }
    // UNRESOLVED: Semantic meaning of each numeric state ID (1-109) and of the aEmpty label table is not derivable from this packet.
    // UNRESOLVED: The float scratch fills read offsets this+3428/3460/4288/5308 which are not listed as named fields in the packet; their role as per-wheel physics inputs is inferred from position only.
    // UNRESOLVED: The 'a2 output buffer' label table relationship assumes aEmpty has 9-byte entries; the string table content is not in this packet.
}
