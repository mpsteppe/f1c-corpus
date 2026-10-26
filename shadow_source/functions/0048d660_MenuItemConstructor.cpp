// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048D660
// Canonical corpus name: ConstructorDualSubInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConstructorDualSubInit_0048d660.c

void UnknownObject::MenuItemConstructor()
{
    // Constructs a menu item. Calls the base initializer ConstructorInitVTable with literal type 1 and depth -1, installs the menu-item vtable pointer off_5AC280 into this+0x0, then calls SimpleSetter_8bc0(this, 2) to set a configuration value. Returns the initialized this pointer.
    // CALL: Call ConstructorInitVTable(this, 1, -1) for base initialization with literal type 1 and depth -1. [callee:0x00488B00, source:raw]
    // ASSIGNMENT: Install the menu-item vtable: write &off_5AC280 into this+0x0. [field:this:0x00000000, global:0x005AC280, source:raw]
    // CALL: Call SimpleSetter_8bc0(this, 2) to set a configuration field to the literal value 2. [callee:0x00488BC0, source:raw]
    // RETURN: Return the constructed this pointer; the legacy ABI label is Constructor_Dual_Sub_Init and the only known caller is sub_493FC0. [abi:lead, caller:0x00493FC0, function:0x0048D660, source:raw]

    // Conservative worker pseudocode:
    //   ConstructorInitVTable(this, 1, -1);
    //   this->vtable = &off_5AC280;
    //   SimpleSetter_8bc0(this, 2);
    //   return this;
    // UNRESOLVED: The meaning of the type 1 and depth -1 parameters passed to ConstructorInitVTable is not established by this packet.
    // UNRESOLVED: The exact configuration field written by SimpleSetter_8bc0(this, 2) is not established; the callee name is derived from its address only.
}
