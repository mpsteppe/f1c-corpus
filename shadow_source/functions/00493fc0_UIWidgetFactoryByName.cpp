// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00493FC0
// Canonical corpus name: sub_493FC0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_493FC0_00493fc0.c

void UnknownObject::UIWidgetFactoryByName()
{
    // Finds or creates a UI widget by name. First queries the child widget container at this+420 through a vtable method at +24 to reuse an existing instance. On a miss, scans the 23-entry keyword table off_5CC270 with sub_588410 and dispatches the matching index through the jump table jpt_49402E to a per-type construction path: each path allocates via OperatorNewNhMallocWrapper and calls a type-specific constructor (ConstructorWithByteParams, UIObjectInitWithByteParams, ConstructorInitVTable, ObjectInitWithFieldZeroing, ConstructorWithStringCopy, UITextDisplayConstructor, InitWithVTableFlags, and others), some installing dedicated vtables such as off_5AC8D8, off_5AC1D0 and off_5AC830 and post-field values. Index 14 has no handler and construction fails for it. On first successful creation, if the new widget's field at +140 is non-zero, a 'Prelinked Gizmo - %s' label is formatted into a buffer seeded from byte_5EA438 with StringFormatWithBufferOverflowCheck and applied via sub_493C80.
    // GUARD: Null name argument short-circuits to a 0 return. [source:raw]
    // CALL: Look up an existing widget by name: call the vtable method at offset 24 on the child container at this+420, reading the container vtable pointer from *(this+0x1A4). [field:this:0x000001A4, field:*(this+0x1A4):0x00000000, field:*(*(this+0x1A4)+0x0):0x00000018, source:raw]
    // LOOP: For index 0 to 22, compare the requested name against keyword entry off_5CC270[i] with sub_588410 until a match is found. [callee:0x00588410, global:0x005CC270, source:raw]
    // CALCULATION: Dispatch on the matched keyword index via the switch jump table jpt_49402E to the per-type construction path. [global:0x004943D0, source:raw]
    // CALL: Cases 0, 1, 2: allocate 228 bytes with OperatorNewNhMallocWrapper and construct via ConstructorWithByteParams(0,0), ConstructorWithByteParams(1,0) or UIObjectInitWithByteParams(0,0). [callee:0x00587C03, callee:0x00487220, callee:0x00487660, source:raw]
    // CALL: Case 3: allocate 236 bytes, run ConstructorWithByteParams(0,0), install the off_5AC8D8 vtable, and zero the fields at byte offsets 228 and 232. [callee:0x00587C03, callee:0x00487220, global:0x005AC8D8, source:raw]
    // CALL: Case 4: allocate 240 bytes, run ShortComputation_5e30, install the off_5AC1D0 vtable, then complete field setup with F_5FieldInit. [callee:0x00587C03, callee:0x00485E30, global:0x005AC1D0, callee:0x004883A0, source:raw]
    // CALL: Cases 5, 6, 7: allocate 236 bytes and construct via ConstructorInitVTable(1, -1), (2, -1) or (3, -1). [callee:0x00587C03, callee:0x00488B00, source:raw]
    // CALL: Case 8: allocate 272 bytes and zero-initialize via ObjectInitWithFieldZeroing. [callee:0x00587C03, callee:0x0048AA40, source:raw]
    // CALL: Case 9: allocate 772 bytes and construct via ConstructorWithStringCopy(0, 0, 0, 0, 0, 0). [callee:0x00587C03, callee:0x0048B420, source:raw]
    // CALL: Case 10: allocate 372 bytes and initialize via sub_4893C0. [callee:0x00587C03, callee:0x004893C0, source:raw]
    // CALL: Case 11: allocate 236 bytes, run ShortComputation_5e30, install the off_5AC830 vtable, then set byte offset 224 to &unk_7C7C7C and byte offsets 228 and 232 to 3289650 and 789516. [callee:0x00587C03, callee:0x00485E30, global:0x005AC830, global:0x007C7C7C, source:raw]
    // CALL: Case 12: allocate 280 bytes and construct via UITextDisplayConstructor. [callee:0x00587C03, callee:0x00488180, source:raw]
    // CALL: Case 13: allocate 228 bytes and initialize via InitWithVTableFlags(0, 0). [callee:0x00587C03, callee:0x00487ED0, source:raw]
    // CALL: Case 15: allocate 296 bytes and zero-initialize via LargeZeroInitConstructor. [callee:0x00587C03, callee:0x0048D740, source:raw]
    // CALL: Case 16: allocate 240 bytes and initialize via ConstructorDualSubInit. [callee:0x00587C03, callee:0x0048D660, source:raw]
    // CALL: Case 17: allocate 240 bytes and initialize via Constructor_e070. [callee:0x00587C03, callee:0x0048E070, source:raw]
    // CALL: Case 18: allocate 260 bytes and initialize via ShortComputation_e300. [callee:0x00587C03, callee:0x0048E300, source:raw]
    // CALL: Case 19: allocate 240 bytes and initialize via UIStructInit. [callee:0x00587C03, callee:0x0048E600, source:raw]
    // CALL: Case 20: allocate 384 bytes and construct via LargeConstructor. [callee:0x00587C03, callee:0x0048EAA0, source:raw]
    // CALL: Case 21: allocate 232 bytes and initialize via UIComponentInit5. [callee:0x00587C03, callee:0x0048FE60, source:raw]
    // CALL: Case 22: allocate 244 bytes and initialize via ObjectInitWithFieldZeroing_0250, then fall through to the shared result assignment. [callee:0x00587C03, callee:0x00490250, source:raw]
    // RETURN: When the keyword scan finds no match, return the still-zero lookup result. [source:raw]
    // GUARD: After creation, when the widget field at byte offset 140 is zero, return the widget directly without applying any label. [source:raw]
    // ASSIGNMENT: Build the label buffer: seed byte_5EA438[0] into the first byte and zero the remaining 124 bytes. [global:0x005EA438, source:raw]
    // CALL: Format the 'Prelinked Gizmo - %s' string (aPrelinkedGizmo) with the widget name via StringFormatWithBufferOverflowCheck, then apply the label by calling sub_493C80(this, 1, buffer). [callee:0x0058815F, global:0x005CC990, callee:0x00493C80, source:raw]
    // RETURN: Return 0 after applying the label to a newly created widget. [source:raw]

    // Conservative worker pseudocode:
    //   int UIWidgetFactoryByName(int this, const char* name) {
    //     if (!name) return 0;
    //     int w = (vtable_of(*(int*)(this + 420))[6])(*(int*)(this + 420), name);  // lookup existing
    //     if (w) {
    //       if (*(int*)(w + 140)) {
    //         char buf[125] = { byte_5EA438[0] };
    //         StringFormatWithBufferOverflowCheck(buf, "Prelinked Gizmo - %s", name);
    //         sub_493C80(this, 1, buf);
    //         return 0;
    //       }
    //       return w;
    //     }
    //     for (int i = 0; i < 23; ++i) {
    //       if (sub_588410(name, off_5CC270[i])) continue;
    //       switch (i) {                              // dispatch via jpt_49402E
    //         case 0:  w = ConstructorWithByteParams(OperatorNewNhMallocWrapper(228), 0, 0); break;
    //         case 1:  w = ConstructorWithByteParams(OperatorNewNhMallocWrapper(228), 1, 0); break;
    //         case 2:  w = UIObjectInitWithByteParams(OperatorNewNhMallocWrapper(228), 0, 0); break;
    //         case 3:  w = OperatorNewNhMallocWrapper(236); ConstructorWithByteParams(w, 0, 0); *(int*)w = &off_5AC8D8; *(char*)(w+228) = 0; *(int*)(w+232) = 0; break;
    //         case 4:  w = OperatorNewNhMallocWrapper(240); ShortComputation_5e30(w); *(int*)w = &off_5AC1D0; F_5FieldInit(w); break;
    //         case 5:  w = ConstructorInitVTable(OperatorNewNhMallocWrapper(236), 1, -1); break;
    //         case 6:  w = ConstructorInitVTable(OperatorNewNhMallocWrapper(236), 2, -1); break;
    //         case 7:  w = ConstructorInitVTable(OperatorNewNhMallocWrapper(236), 3, -1); break;
    //         case 8:  w = ObjectInitWithFieldZeroing(OperatorNewNhMallocWrapper(272)); break;
    //         case 9:  w = ConstructorWithStringCopy(OperatorNewNhMallocWrapper(772), 0,0,0,0,0,0); break;
    //         case 10: w = sub_4893C0(OperatorNewNhMallocWrapper(372)); break;
    //         case 11: w = OperatorNewNhMallocWrapper(236); ShortComputation_5e30(w); *(int*)w = &off_5AC830; *(int*)(w+224) = &unk_7C7C7C; *(int*)(w+228) = 3289650; *(int*)(w+232) = 789516; break;
    //         case 12: w = UITextDisplayConstructor(OperatorNewNhMallocWrapper(280)); break;
    //         case 13: w = InitWithVTableFlags(OperatorNewNhMallocWrapper(228), 0, 0); break;
    //         case 15: w = LargeZeroInitConstructor(OperatorNewNhMallocWrapper(296)); break;
    //         case 16: w = ConstructorDualSubInit(OperatorNewNhMallocWrapper(240)); break;
    //         case 17: w = Constructor_e070(OperatorNewNhMallocWrapper(240)); break;
    //         case 18: w = ShortComputation_e300(OperatorNewNhMallocWrapper(260)); break;
    //         case 19: w = UIStructInit(OperatorNewNhMallocWrapper(240)); break;
    //         case 20: w = LargeConstructor(OperatorNewNhMallocWrapper(384)); break;
    //         case 21: w = UIComponentInit5(OperatorNewNhMallocWrapper(232)); break;
    //         case 22: w = ObjectInitWithFieldZeroing_0250(OperatorNewNhMallocWrapper(244)); break;
    //         default: return 0;
    //       }
    //       if (w) {
    //         if (*(int*)(w + 140)) {
    //           char buf[125] = { byte_5EA438[0] };
    //           StringFormatWithBufferOverflowCheck(buf, "Prelinked Gizmo - %s", name);
    //           sub_493C80(this, 1, buf);
    //           return 0;
    //         }
    //         return w;
    //       }
    //       return 0;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Keyword index 14 has no switch case: a name matching off_5CC270[14] falls into the default path and returns 0 without construction.
    // UNRESOLVED: Semantics of the widget field at byte offset 140 (non-zero suppresses the prelink label) and of the 3289650 / 789516 color-like constants at byte offsets 228 and 232.
    // UNRESOLVED: The meaning of 'Prelinked Gizmo' and why labeling returns 0 while the caller discards the new widget handle.
    // UNRESOLVED: Widget concrete types behind each keyword index are not named by the evidence; only the construction call shape is known.
}
