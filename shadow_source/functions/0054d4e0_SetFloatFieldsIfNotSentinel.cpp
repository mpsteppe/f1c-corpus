// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054D4E0
// Canonical corpus name: ConditionalFloatFieldSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalFloatFieldSetter_0054d4e0.c

void UnknownObject::SetFloatFieldsIfNotSentinel()
{
    // Conditional float-field setter on a float-array receiver: writes argument a2 into field +0xF4 (this[61]) and argument a3 into field +0xF8 (this[62]), each only when the argument is not the -1.0 sentinel (read-only constant dbl_59E428). The sentinel indicates 'no change', so fields whose argument is -1.0 are left untouched. Called by SceneNode (0x0055A910), which supplies the override values.
    // GUARD: First guard: proceed only when a2 differs from the -1.0 sentinel (read-only constant dbl_59E428). [global:0x0059E428, source:raw]
    // ASSIGNMENT: Write a2 into the float field at this+0xF4 (this[61]). [field:this:0x000000F4, source:raw]
    // GUARD: Second guard: proceed only when a3 differs from the -1.0 sentinel (read-only constant dbl_59E428). [global:0x0059E428, source:raw]
    // ASSIGNMENT: Write a3 into the float field at this+0xF8 (this[62]). [field:this:0x000000F8, source:raw]
    // CALL: Called by SceneNode (0x0055A910) during scene-node initialization to optionally override the two float fields. [caller:0x0055A910, source:raw]

    // Conservative worker pseudocode:
    //   if (a2 != -1.0) this[61] = a2;
    //   if (a3 != -1.0) this[62] = a3;
    // UNRESOLVED: The semantics of the two float fields +0xF4/+0xF8 (likely scene-node overrides) are not evidenced by this packet; the caller relationship is inferred from the caller evidence.
    // UNRESOLVED: The -1.0 sentinel meaning ('leave the field unchanged') is inferred from the guard structure; the caller's interpretation of a2/a3 is not evidenced.
}
