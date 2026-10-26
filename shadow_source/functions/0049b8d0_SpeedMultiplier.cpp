// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049B8D0
// Canonical corpus name: SpeedMultiplier
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SpeedMultiplier_0049b8d0.c

void UnknownObject::SpeedMultiplier()
{
    // Reads a float from the global-pointered data block dword_7C54E0 at field offset 14752 (0x39A0), scales it by the fixed constant 9.549296585513721 stored in dbl_59EA38, and returns the product as a double. No arguments and no side effects; the scaling factor likely converts the stored unit into speed per time, but the semantic role is caller-dependent.
    // CALCULATION: Dereference the global pointer dword_7C54E0 and load a float at field offset 14752 within the pointed-to data block. [global:0x007C54E0, source:raw]
    // CALCULATION: Multiply the loaded float by the double constant 9.549296585513721 from dbl_59EA38. [global:0x0059EA38, source:raw]
    // RETURN: Return the scaled value as a double. [function:0x0049B8D0, source:raw]

    // Conservative worker pseudocode:
    //   double SpeedMultiplier(void) {
    //     return *(float *)(*(char **)dword_7C54E0 + 14752) * dbl_59EA38;
    //   }
    // UNRESOLVED: Meaning of the float field at offset 14752 and of the scale factor 9.549296585513721 is unresolved; both depend on the caller context.
    // UNRESOLVED: Semantic role of dword_7C54E0 as the root of the data block is DERIVED; the raw source only shows it as a pointer base.
}
