// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054EE90
// Canonical corpus name: F_2DCrossProduct
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_2DCrossProduct_0054ee90.c

void UnknownObject::F_2DCrossProduct()
{
    // Pure 2D cross product helper. Interprets a1, a2 and a3 as pointers to float points and a4, a5 as coordinate-axis indices, and computes the z-component of the cross product of the edge vectors (a3 - a2) and (a1 - a2) restricted to the two axes, returned as a double. Consumed by F_2D3DTrianglePointTest (0x0054EB40) for signed-area point-in-triangle tests.
    // CALCULATION: Compute axis component differences: (a3[axis] - a2[axis]) and (a1[axis] - a2[axis]) for each of the two coordinate indices a5 and a4, reading floats at 4 * index offsets. [source:raw]
    // CALCULATION: Form the 2D cross product: dx1 * dy2 - dy1 * dx2 using the four axis-aligned edge components. [source:raw]
    // RETURN: Return the scalar cross-product value as a double. [source:raw]

    // Conservative worker pseudocode:
    //   double F_2DCrossProduct(const float* a, const float* b, const float* c, int axis1, int axis2) {
    //     float dx1 = c[axis2] - b[axis2], dx2 = c[axis1] - b[axis1];
    //     float dy1 = a[axis2] - b[axis2], dy2 = a[axis1] - b[axis1];
    //     return (double)(dx1 * dy2 - dy1 * dx2);
    //   }
    // UNRESOLVED: Ownership: the owning object/class is unknown; only the caller F_2D3DTrianglePointTest ties it to triangle point tests.
    // UNRESOLVED: Whether the two points share the same base a2 (interpreted as the common origin) is an interpretation of the subtractive form, not independently proven.
}
