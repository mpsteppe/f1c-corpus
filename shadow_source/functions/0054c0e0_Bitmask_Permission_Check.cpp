// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054C0E0
// Canonical corpus name: sub_54C0E0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_54C0E0_0054c0e0.c

void UnknownObject::Bitmask_Permission_Check()
{
    // __thiscall visibility/classification mask test. Loads this object's bitmask from this+0x38; if it is 0, returns TRUE unconditionally (pass-all). Otherwise returns TRUE only when every set bit of this+0x38 is also present in both the global mask dword_8B8E34 (0x008B8E34) and the target object's mask read from a2+132: (dword_8B8E34 & v2 & *(DWORD*)(a2+132)) == v2. Used as a visibility filter on the scene traversal path, called by ArithmeticComparison_9000 (0x004C9000).
    // ASSIGNMENT: Load v2 = this[14], the mask stored at this+0x38. [field:this:0x00000038, source:raw]
    // GUARD: Guard: if v2 is zero, return TRUE (unconditional pass) without consulting the masks. [field:this:0x00000038, source:raw]
    // CALCULATION: Compute (dword_8B8E34 & v2 & *(DWORD*)(a2+132)) and compare it for equality with v2. [global:0x008B8E34, source:raw]
    // RETURN: Return TRUE when the intersection equals v2 (all mask bits satisfied), otherwise FALSE; v2 == 0 already returned TRUE above. [field:this:0x00000038, global:0x008B8E34, source:raw]
    // CALL: This function is used as a visibility/permission filter by caller ArithmeticComparison_9000 (0x004C9000) on the scene traversal path. [caller:0x004C9000, function:0x0054C0E0, source:raw]

    // Conservative worker pseudocode:
    //   BOOL Bitmask_Permission_Check(DWORD *this, int a2) {
    //     int v2 = this[14];
    //     return !v2 || (dword_8B8E34 & v2 & *(DWORD *)(a2 + 132)) == v2;
    //   }
    // UNRESOLVED: a2+132 is read but has no field evidence entry in the packet, so its semantic role (target object mask) is proposed only from the existing analysis.
    // UNRESOLVED: The roles of dword_8B8E34 (global render visibility mask) and of the this+0x38 mask bits are not independently confirmed by the packet.
    // UNRESOLVED: The owning object types of this and a2 are unknown.
}
