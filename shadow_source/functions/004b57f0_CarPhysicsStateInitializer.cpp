// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B57F0
// Canonical corpus name: CarPhysicsStateInitializer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CarPhysicsStateInitializer_004b57f0.c

void UnknownObject::CarPhysicsStateInitializer()
{
    // Constructor/initializer for a large per-car physics state object (DWORD array up to this[998]). Zeroes the leading physics words (this[0..15]), allocates and appends a sub-list via OperatorNewNhMallocWrapper/ConditionalArrayAlloc/ListAppendWithSubListGeneration, zeroes the 416-DWORD middle array (this[16..431]) in a 104x4 loop, sets sentinel and default blocks (this[432..460], this[977..998]), forwards to sub-initializers (QuadZeroInit, ZeroInitSmallStruct, PassthroughWrapper_f670, StructZeroInit_8ba0), configures a QPC timer (QPCTimerInitialization + TimerResetUsingQueryPerformanceCounter), zeroes the timer block with a 0x1A0-byte memset, and sets byte flags plus tuning constants including 900.0f and 1.0/8.0. Called by ArithmeticComparison_9780 (004B9780).
    // ASSIGNMENT: Zero the leading physics state words this[0..3] (offsets 0x0..0xC) [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // CALL: QuadZeroInit(this + 4) zeroes the 16-byte quad at offset 0x10 [callee:0x004BA820, source:raw]
    // ASSIGNMENT: Zero this[8..11] (offsets 0x20..0x2C) [field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, source:raw]
    // CALL: QuadZeroInit(this + 12) zeroes the 16-byte quad at offset 0x30 [callee:0x004BA820, source:raw]
    // GUARD: Allocation guard: OperatorNewNhMallocWrapper(4) decides whether the sub-list is allocated at all [callee:0x00587C03, source:raw]
    // CALL: v2 = ConditionalArrayAlloc(1) when the allocation wrapper returns non-null, else v2 = 0 [callee:0x004BAAC0, source:raw]
    // CALL: ListAppendWithSubListGeneration(v2, 1) appends the allocated element to the sub-list [callee:0x004BB150, source:raw]
    // LOOP: Zero loop from this[16]: 104 iterations writing 4 DWORDs each (416 DWORDs total); the recorded field samples are 0x40..0x4C [field:this:0x00000040, field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, source:raw]
    // ASSIGNMENT: Zero this[432..435] (offsets 0x6C0..0x6CC) [field:this:0x000006C0, field:this:0x000006C4, field:this:0x000006C8, field:this:0x000006CC, source:raw]
    // ASSIGNMENT: Zero this[437..440] (offsets 0x6D4..0x6E0) [field:this:0x000006D4, field:this:0x000006D8, field:this:0x000006DC, field:this:0x000006E0, source:raw]
    // CALL: ZeroInitSmallStruct(this + 441) zeroes the small struct at offset 0x6E4 [callee:0x005668B0, source:raw]
    // ASSIGNMENT: Sentinel block this[449..460] (offsets 0x704..0x730): zeros at 0x704/0x70C/0x714/0x718/0x71C/0x720/0x724/0x72C and -1 at 0x708/0x710/0x728/0x730 [field:this:0x00000704, field:this:0x00000708, field:this:0x0000070C, field:this:0x00000710, field:this:0x00000714, field:this:0x00000718, field:this:0x0000071C, field:this:0x00000720, field:this:0x00000724, field:this:0x00000728, field:this:0x0000072C, field:this:0x00000730, source:raw]
    // CALL: PassthroughWrapper_f670(this + 624) forwards to the initializer of the struct at offset 0x9C0 [callee:0x004FF670, source:raw]
    // CALL: StructZeroInit_8ba0(this + 843) zeroes the struct at offset 0xD2C [callee:0x00568BA0, source:raw]
    // ASSIGNMENT: Zero this[977..980] (offsets 0xF44..0xF50) [field:this:0x00000F44, field:this:0x00000F48, field:this:0x00000F4C, field:this:0x00000F50, source:raw]
    // CALL: QuadZeroInit(this + 981) zeroes the 16-byte quad at offset 0xF54 [callee:0x004BA820, source:raw]
    // ASSIGNMENT: Zero this[985..988] (offsets 0xF64..0xF70) [field:this:0x00000F64, field:this:0x00000F68, field:this:0x00000F6C, field:this:0x00000F70, source:raw]
    // ASSIGNMENT: this[989] = -51331646 (offset 0xF74) [field:this:0x00000F74, source:raw]
    // ASSIGNMENT: this[997] = 0 and this[998] = -1 (offsets 0xF94..0xF98) [field:this:0x00000F94, field:this:0x00000F98, source:raw]
    // ASSIGNMENT: this[448] = 0 (offset 0x700) [field:this:0x00000700, source:raw]
    // ASSIGNMENT: Configuration block this[617..623] (offsets 0x9A4..0x9BC) = 4, 2, 2, 0, 0, 0, 0 [field:this:0x000009A4, field:this:0x000009A8, field:this:0x000009AC, field:this:0x000009B0, field:this:0x000009B4, field:this:0x000009B8, field:this:0x000009BC, source:raw]
    // ASSIGNMENT: this[842] = 0 (offset 0xD28) [field:this:0x00000D28, source:raw]
    // CALL: QPCTimerInitialization(1) initializes the timer subsystem [callee:0x00568BE0, source:raw]
    // CALL: TimerResetUsingQueryPerformanceCounter(this + 843) resets the timer struct at offset 0xD2C [callee:0x00568C60, source:raw]
    // ASSIGNMENT: this[862] = -23693671 (offset 0xD78) [field:this:0x00000D78, source:raw]
    // ASSIGNMENT: memset(this + 863, 0, 0x1A0u) zeroes the 416-byte timer block at offset 0xD7C [source:raw]
    // ASSIGNMENT: Zero this[969..973] (offsets 0xF24..0xF34) [field:this:0x00000F24, field:this:0x00000F28, field:this:0x00000F2C, field:this:0x00000F30, field:this:0x00000F34, source:raw]
    // ASSIGNMENT: Byte flag slots: byte at +3960 (0xF78) = 0, +3961 (0xF79) = 1, +3962 (0xF7A) = 1, +3969 (0xF81) = 0 [field:this:0x00000F78, field:this:0x00000F79, field:this:0x00000F7A, field:this:0x00000F81, source:raw]
    // ASSIGNMENT: this[995] = 5 (offset 0xF8C) and this[996] = 1147207680 (offset 0xF90, bit pattern of 900.0f) [field:this:0x00000F8C, field:this:0x00000F90, source:raw]
    // ASSIGNMENT: this[974] = 0 (0xF38), this[975] = 0 (0xF3C), this[976] = -1 (0xF40) [field:this:0x00000F38, field:this:0x00000F3C, field:this:0x00000F40, source:raw]
    // ASSIGNMENT: Float slot at offset 0xF7C (this byte 3964) = 1.0 / 8.0 (computed, 0.125f) [field:this:0x00000F7C, source:raw]
    // RETURN: Returns the object pointer in EAX; called once by ArithmeticComparison_9780 (004B9780) [function:0x004B57F0, caller:0x004B9780, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   this[0..3] = 0;
    //   QuadZeroInit(this + 4);
    //   this[8..11] = 0;
    //   QuadZeroInit(this + 12);
    //   if (OperatorNewNhMallocWrapper(4)) v2 = ConditionalArrayAlloc(1); else v2 = 0;
    //   ListAppendWithSubListGeneration(v2, 1);
    //   v3 = this + 16; v4 = 104; do { v3[0..3] = 0; v3 += 4; } while (--v4);
    //   this[432..435] = 0;
    //   this[437..440] = 0;
    //   ZeroInitSmallStruct(this + 441);
    //   this[449] = 0; this[450] = -1; this[451] = 0; this[452] = -1; this[453..457] = 0; this[458] = -1; this[459] = 0; this[460] = -1;
    //   PassthroughWrapper_f670(this + 624);
    //   StructZeroInit_8ba0(this + 843);
    //   this[977..980] = 0;
    //   QuadZeroInit(this + 981);
    //   this[985..988] = 0;
    //   this[989] = -51331646;
    //   this[997] = 0; this[998] = -1;
    //   this[448] = 0;
    //   this[617] = 4; this[618] = 2; this[619] = 2; this[620..623] = 0;
    //   this[842] = 0;
    //   QPCTimerInitialization(1);
    //   TimerResetUsingQueryPerformanceCounter(this + 843);
    //   this[862] = -23693671;
    //   memset(this + 863, 0, 0x1A0);
    //   this[969..973] = 0;
    //   byte(+3960) = 0; byte(+3961) = 1; byte(+3962) = 1; byte(+3969) = 0;
    //   this[995] = 5; this[996] = 1147207680;
    //   this[974] = 0; this[975] = 0; this[976] = -1;
    //   float(+3964) = 1.0 / 8.0;
    //   return this;
    // UNRESOLVED: Three read-only globals (flt_59E43C, flt_5ACD08, dword_5ACD24) are flagged by packet facts but appear nowhere in the raw decompiled source; their role in this initializer is unverifiable from this packet
    // UNRESOLVED: The object type and the semantic purpose of the sentinel 0/-1 blocks and the config block this[617..623] = 4/2/2/0/0/0/0 are not established by this packet
    // UNRESOLVED: The sub-list allocated via ConditionalArrayAlloc/ListAppendWithSubListGeneration is not referenced again in this function; its disposition is unknown
}
