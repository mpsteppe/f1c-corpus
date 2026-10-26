// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005414C0
// Canonical corpus name: UIToggleState
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIToggleState_005414c0.c

void UnknownObject::UIToggleState()
{
    // Trivial __thiscall UI state toggle: computes result = 1 - this[0x1148], stores it back to this[0x1148], and returns the new value. Flips the integer field at offset 0x1148 between 0 and 1 on every call. No guards, globals, or callees.
    // CALCULATION: result = 1 - this[0x1148]; compute the complement of the current state field [field:this:0x00001148, source:raw]
    // ASSIGNMENT: this[0x1148] = result; write the new boolean state back to the field [field:this:0x00001148, source:raw]
    // RETURN: return result; yield the new state value to the caller [field:this:0x00001148, source:raw]
    // CALL: Called by sub_5613E0 (0x005613E0), which invokes this toggle on its UI state. [caller:0x005613E0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_5414C0(_DWORD *this) {
    //     int result = 1 - this[1106];
    //     this[1106] = result;
    //     return result;
    //   }
    // UNRESOLVED: Semantic meaning of the toggled state field at this+0x1148 and of the owning object are not identified in the packet.
    // UNRESOLVED: Whether the toggle is one of several mutually exclusive UI states depends on callers outside this packet.
}
