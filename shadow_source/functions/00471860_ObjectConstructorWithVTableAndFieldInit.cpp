// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00471860
// Canonical corpus name: ObjectConstructorWithVTableAndFieldInit
// Owner: UIComponent [DERIVED]
// Raw source: functions/ObjectConstructorWithVTableAndFieldInit_00471860.c

void UIComponent::ObjectConstructorWithVTableAndFieldInit()
{
    // UI component constructor (component ID 242). Initializes the base subobject, installs the vtable, binds a data-source pointer, sets single-state configuration, inserts text and "On" string handles into a linked list, then dispatches post-init via the action ID virtual call.
    // CALL: Invoke ShortComputation_6d60(this, 1) to initialize the base subobject with flag 1 before any derived fields are set. [callee:0x00466D60, abi:lead, source:raw]
    // ASSIGNMENT: Install the class vtable by writing the address of the off_5A12C0 vtable table into the object's vtable pointer at offset 0x0. [field:this:0x00000000, global:0x005A12C0, source:raw]
    // ASSIGNMENT: Bind the data source by storing the address of dword_7CE7CC into the data-source field at offset 0x31C. [field:this:0x0000031C, global:0x007CE7CC, source:raw]
    // ASSIGNMENT: Set value count at offset 0x324 to 1 (single-state component). [field:this:0x00000324, source:raw]
    // ASSIGNMENT: Set current state value at offset 0x328 to 0 (initial/off state). [field:this:0x00000328, source:raw]
    // ASSIGNMENT: Set minimum state value / enabled flag at offset 0x32C to 1. [field:this:0x0000032C, source:raw]
    // ASSIGNMENT: Set maximum state value / visibility flag at offset 0x330 to 1. [field:this:0x00000330, source:raw]
    // ASSIGNMENT: Set unique component ID at offset 0x334 to 242. [field:this:0x00000334, source:raw]
    // CALL: Insert the off_5BE704 text handle into the component's linked list with node allocation and owner index -1. [callee:0x00486F30, global:0x005BE704, source:raw]
    // CALL: Insert the aOn string handle into the component's linked list with node allocation and owner index -1. [callee:0x00486F30, global:0x005C32C8, source:raw]
    // CALL: Dispatch post-construction behavior via SwitchOnActionIDVirtualCall(this). [callee:0x004670E0, source:raw]
    // RETURN: Return the constructed object pointer. [source:raw, function:0x00471860]

    // Conservative worker pseudocode:
    //   Base_init(this, 1);
    //   this->vtable = &off_5A12C0;
    //   this->dataSource = &dword_7CE7CC;
    //   this->valueCount = 1; this->state = 0; this->min = 1; this->max = 1; this->componentId = 242;
    //   InsertTextHandle(this, &off_5BE704); InsertTextHandle(this, aOn);
    //   PostInitDispatch(this);
}
