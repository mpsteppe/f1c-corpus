// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DAEA0
// Canonical corpus name: Direct3DObjectFactory
// Owner: UiWidgetFactory [DERIVED]
// Raw source: functions/Direct3DObjectFactory_004daea0.c

void UiWidgetFactory::CreateUiWidget()
{
    // Factory that allocates and initializes a UI widget object from a type id passed in ecx. A switch dispatches to per-type cases: each allocates a fixed size (24, 20, 32 or 44 bytes) with OperatorNewNhMallocWrapper, installs a per-type vtable pointer from a fixed vtable table, and fills common fields (dword index 1, byte at offset 8, dword index 3). Types 7 and 0x11 run ConstructorVTable3Fields(1, 1) first; type 8 runs SmallStructConstructor_b0e0 first. Returns the constructed object, or null on allocation failure or an unhandled type id.
    // GUARD: Dispatch on the widget type id held in ecx through the switch jump table; unhandled type ids fall through to the default case and return null. [source:raw, global:0x004DB02C]
    // CALL: Allocate the object with OperatorNewNhMallocWrapper: size 24 for type 0 (and type 0x11), size 20 for types 1, 2, 6, 7 and 8, size 32 for type 0xD, size 44 for type 0x13. [callee:0x00587C03, source:raw]
    // GUARD: A null allocation result jumps to the common failure label, which zeroes the result and returns null. [source:raw]
    // ASSIGNMENT: Install the per-type vtable into dword index 0: type 0 stores &off_5AD050, type 1 &off_5AD034, type 2 &off_5AD018, type 6 &off_5ACFFC, type 0xD &off_5ACFA8 and type 0x13 &off_5ACF70. [global:0x005AD050, global:0x005AD034, global:0x005AD018, global:0x005ACFFC, global:0x005ACFA8, global:0x005ACF70, source:raw]
    // ASSIGNMENT: Set dword index 1 to 2 for type 0 and to 1 for the other simple types. [source:raw]
    // ASSIGNMENT: Set the byte at offset 8 to 1 for the simple types. [source:raw]
    // ASSIGNMENT: Clear dword index 3 to 0 for the simple types. [source:raw]
    // CALL: For type 7, run ConstructorVTable3Fields(1, 1), then install vtable &off_5ACFE0 at dword index 0. [callee:0x004DB070, global:0x005ACFE0, source:raw]
    // CALL: For type 8, run SmallStructConstructor_b0e0 on the object, then install vtable &off_5ACFC4 at dword index 0. [callee:0x004DB0E0, global:0x005ACFC4, source:raw]
    // CALL: For type 0x11, run ConstructorVTable3Fields(1, 1), then install vtable &off_5ACF8C at dword index 0. [callee:0x004DB070, global:0x005ACF8C, source:raw]
    // RETURN: Return the constructed object pointer, or null when the type id was unhandled or an allocation failed. [source:raw, caller:0x004D88D0]

    // Conservative worker pseudocode:
    //   DWORD* CreateUiWidget(DWORD typeId) {
    //     DWORD* obj = 0;
    //     switch (typeId) {
    //       case 0:  obj = Alloc(24); if (!obj) break; obj[1] = 2; ((BYTE*)obj)[8] = 1; obj[0] = &off_5AD050; obj[3] = 0; break;
    //       case 1:  obj = Alloc(20); if (!obj) break; obj[0] = &off_5AD034; obj[1] = 1; ((BYTE*)obj)[8] = 1; obj[3] = 0; break;
    //       case 2:  obj = Alloc(20); if (!obj) break; obj[0] = &off_5AD018; obj[1] = 1; ((BYTE*)obj)[8] = 1; obj[3] = 0; break;
    //       case 6:  obj = Alloc(20); if (!obj) break; obj[0] = &off_5ACFFC; obj[1] = 1; ((BYTE*)obj)[8] = 1; obj[3] = 0; break;
    //       case 7:  obj = Alloc(20); if (!obj) break; ConstructorVTable3Fields(1, 1); obj[0] = &off_5ACFE0; break;
    //       case 8:  obj = Alloc(20); if (!obj) break; SmallStructConstructor_b0e0(obj); obj[0] = &off_5ACFC4; break;
    //       case 0xD:  obj = Alloc(32); if (!obj) break; obj[0] = &off_5ACFA8; obj[1] = 1; ((BYTE*)obj)[8] = 1; obj[3] = 0; break;
    //       case 0x11: obj = Alloc(24); if (!obj) break; ConstructorVTable3Fields(1, 1); obj[0] = &off_5ACF8C; break;
    //       case 0x13: obj = Alloc(44); if (obj) { obj[0] = &off_5ACF70; obj[1] = 1; ((BYTE*)obj)[8] = 1; obj[3] = 0; } else obj = 0; break;
    //       default:   return obj;
    //     }
    //     return obj;
    //   }
    // UNRESOLVED: Concrete widget class per vtable (off_5ACF70, off_5ACF8C, off_5ACFA8, off_5ACFC4, off_5ACFE0, off_5ACFFC, off_5AD018, off_5AD034, off_5AD050) is not resolved from this function alone.
    // UNRESOLVED: Role of the metadata byte near the switch table (byte_4DB054) is not referenced by the visible source body.
}
