// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00476240
// Canonical corpus name: WidgetNameAccessor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WidgetNameAccessor_00476240.c

void UnknownObject::WidgetNameAccessor()
{
    // Accessor that returns a widget's name string pointer stored at this+0x40. When that pointer is null it returns the global default string byte_5EA438 (an application/default directory path).
    // GUARD: Guard on widget name pointer at this+0x40: if null, fall through to return the default string. [field:this:0x00000040, global:0x005EA438]
    // ASSIGNMENT: Load the widget name string pointer from this[16] (byte offset 0x40). [field:this:0x00000040, source:raw]
    // RETURN: Return the widget name pointer, or byte_5EA438 when the pointer is null. [global:0x005EA438, source:raw, function:0x00476240]

    // Conservative worker pseudocode:
    //   char *sub_476240(void *this) {
    //     char *name = *(char **)((char *)this + 0x40);
    //     if (!name) return byte_5EA438;
    //     return name;
    //   }
    // UNRESOLVED: Object type holding the name at this+0x40 is unknown.
    // UNRESOLVED: Semantics of byte_5EA438 (default directory path) are DERIVED, not CONFIRMED.
}
