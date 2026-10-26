// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00470960
// Canonical corpus name: SessionSetupScreenSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SessionSetupScreenSetup_00470960.c

void UnknownObject::InitializeSessionSetupDisplay()
{
    // Session-setup screen parameter initializer: stores the current RaceMode (dword_7D0410) into this at offset 0x324 and a pointer to the UI index global (dword_7CEAA4) into this at offset 0x320, formats the indexed UI list item text into a local buffer via StringFormatWithBufferOverflowCheck, pushes it into the edit buffer via EditBufferStringUpdate, and finally resolves an object of type 19 through the dispatch interface at dword_7CD8C0 and compares its name against this when it exists. Always returns 0.
    // ASSIGNMENT: Store the RaceMode value dword_7D0410 into this at offset 0x324 (dword index 201). [global:0x007D0410, field:this:0x00000324]
    // ASSIGNMENT: Store the address of the UI index global dword_7CEAA4 into this at offset 0x320 (dword index 200). [global:0x007CEAA4, field:this:0x00000320]
    // CALL: Fetch the UI list item indexed by dword_7CEAA4 via UIListIndexedAccessor. [callee:0x00487010]
    // CALL: Format the fetched item into the local buffer v5 via StringFormatWithBufferOverflowCheck. [callee:0x0058815F]
    // CALL: Push the formatted text into the edit buffer via EditBufferStringUpdate. [callee:0x0048B810]
    // CALL: Resolve an object of type 19 through the dispatch interface at dword_7CD8C0 (vtable slot 28). [global:0x007CD8C0]
    // GUARD: When the resolved object is non-null, compare its name against this via ObjectNameComparison. [callee:0x00477280]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int setup(_DWORD *this) {
    //       this[201] = dword_7D0410;             // offset 0x324: RaceMode
    //       this[200] = &dword_7CEAA4;            // offset 0x320: UI index source
    //       char *item = UIListIndexedAccessor(this, dword_7CEAA4);
    //       char buf[32];
    //       StringFormatWithBufferOverflowCheck(buf, item);
    //       EditBufferStringUpdate(this, buf);
    //       _DWORD *obj = dispatch_resolve(dword_7CD8C0, 19);   // vtable slot 28
    //       if (obj) ObjectNameComparison(obj, this);
    //       return 0;
    //   }
    // UNRESOLVED: Semantics of the object resolved by the dispatch interface (type 19) and why its name is compared against this.
    // UNRESOLVED: Whether the this fields at offsets 0x320/0x324 are consumed elsewhere after this setup step.
}
