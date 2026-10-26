// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048FC50
// Canonical corpus name: UIObjectConstructor_fc50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIObjectConstructor_fc50_0048fc50.c

void UnknownObject::UIObjectConstructor()
{
    // Constructor for a UI control object. Calls UIStructInit_e9e0 to initialize the base UI struct, then zeroes the fields at 0x30 and 0x38, stores a 18446744073709551615 (i.e. -1) sentinel at 0x34, and installs the vtable pointer off_5A4450 at offset 0. Used by UI-options, generic UI-object, and profile-bitmap-browser construction paths.
    // CALL: UIStructInit_e9e0(this): initializes the base UI control struct [callee:0x0048E9E0, source:raw]
    // ASSIGNMENT: Sets field at offset 0x30 to 0: this[12] = 0 [field:this:0x00000030]
    // ASSIGNMENT: Sets field at offset 0x34 to the sentinel literal 18446744073709551615 (an invalid/unselected index, -1): this[13] = -1 [field:this:0x00000034]
    // ASSIGNMENT: Sets field at offset 0x38 to 0: this[14] = 0 [field:this:0x00000038]
    // ASSIGNMENT: Installs the vtable pointer: *this = &off_5A4450 [field:this:0x00000000, global:0x005A4450]
    // RETURN: Returns this (the constructed object) [function:0x0048FC50, source:raw]
    // CALL: Invoked as a constructor from UIOptionsConstructor_6030 (00476030), sub_4760D0 (004760D0), UIObjectInit (004761C0), and ProfileBitmapBrowser (00477CB0) [caller:0x00476030, caller:0x004760D0, caller:0x004761C0, caller:0x00477CB0]

    // Conservative worker pseudocode:
    //   UIStructInit_e9e0(this);
    //   this[12] = 0;
    //   this[13] = -1;
    //   this[14] = 0;
    //   *this = &off_5A4450;
    //   return this;
    // UNRESOLVED: The concrete UI class is unknown; the vtable off_5A4450 is only evidenced as a global R reference, not as a named vtable
    // UNRESOLVED: The role of the 18446744073709551615 (-1) sentinel field at 0x34 and the zeroed fields at 0x30/0x38 is not documented in the packet
}
