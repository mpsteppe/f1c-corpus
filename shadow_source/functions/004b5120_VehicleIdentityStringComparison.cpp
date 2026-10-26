// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B5120
// Canonical corpus name: VehicleIdentityStringComparison
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleIdentityStringComparison_004b5120.c

void UnknownObject::VehicleIdentityStringComparison()
{
    // Thiscall identity/path comparison on two strings. Computes the end of the path string stored at object offset 18196 of a2, then scans backward for the last backslash (92). The trailing filename v3 is compared with the string at this+65, and the string at this+1 is compared with the string at object offset 17952 of a2; the function returns true when both match. When the path has no backslash, the comparison is performed against the whole path string. Invoked by VehicleInstanceListBuilder (0x004B5C50).
    // ASSIGNMENT: v3 = a2 + 18196 + strlen(a2 + 18196): locate the null terminator of the path string stored at object offset 18196 of a2. [source:raw]
    // GUARD: Scan for a backslash only while (unsigned int)v3 > a2 + 18196, i.e. the path string at offset 18196 is non-empty; an empty path skips the scan entirely. [source:raw]
    // LOOP: Walk v3 backward while *v3 != 92 (backslash) to find the last path separator; if the backward scan reaches a2 + 18196 the identity comparison is evaluated and returned directly. [source:raw]
    // CALCULATION: After a backslash is found, advance v3 by one so it points past the separator to the trailing filename. [source:raw]
    // RETURN: Return !strcmp(this + 65, v3) && !strcmp(this + 1, a2 + 17952): true when the string at this+65 equals the trailing filename v3 AND the string at this+1 equals the string at object offset 17952 of a2. [function:0x004B5120, source:raw]
    // CALL: Invoked by VehicleInstanceListBuilder (0x004B5C50) to match a vehicle's identity strings against a path-derived name. [caller:0x004B5C50, source:raw]

    // Conservative worker pseudocode:
    //   bool sub_4B5120(const char *this, int a2) {
    //     const char *v3 = (const char *)(a2 + 18196 + strlen((const char *)(a2 + 18196)));
    //     if ((unsigned int)v3 > (unsigned int)(a2 + 18196)) {
    //       while (*v3 != 92) {
    //         if ((unsigned int)--v3 <= (unsigned int)(a2 + 18196))
    //           return !strcmp(this + 65, v3) && !strcmp(this + 1, (const char *)(a2 + 17952));
    //       }
    //       ++v3;
    //     }
    //     return !strcmp(this + 65, v3) && !strcmp(this + 1, (const char *)(a2 + 17952));
    //   }
    // UNRESOLVED: The type of object a2 (owner of offsets 18196 and 17952) and the meanings of the identity strings at this+1 and this+65 are caller-defined; VehicleInstanceListBuilder context is out of packet scope.
    // UNRESOLVED: The unsigned comparison (unsigned int)v3 <= a2 + 18196 is the decompiler's rendering of the pointer boundary; its exact intent when the path contains no backslash is inferred from the fall-through return.
}
