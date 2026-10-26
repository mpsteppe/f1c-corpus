// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00438930
// Canonical corpus name: ConstraintProjectGramSchmidt
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConstraintProjectGramSchmidt_00438930.c

void UnknownObject::ConstraintProjectGramSchmidt()
{
    // Gram-Schmidt projection step of the constraint solver. Loads the constraint data pointer at this+0x15C (dword index 87 of this), computes the dot product between the reference constraint direction vector (components at constraint+28/+52/+76) and the direction vector being orthogonalized (components at constraint+332/+340/+348), then subtracts the scaled projection from each axis of the second vector, leaving an orthogonal residual. Returns the dot product used as the projection factor.
    // ASSIGNMENT: Load the constraint data pointer stored at this+0x15C (dword index 87 of this). [field:this:0x0000015C, source:raw]
    // CALCULATION: Compute the dot product of the reference constraint direction vector (components at constraint+28/+52/+76) with the direction vector being orthogonalized (components at constraint+332/+340/+348). [field:this:0x00000178, field:this:0x00000190, field:this:0x000001A8, source:raw]
    // CALCULATION: Subtract the projected component from each axis of the second vector: constraint+332 -= result * (constraint+28); constraint+340 -= result * (constraint+52); constraint+348 -= result * (constraint+76). The result is an orthogonal residual. [field:this:0x000002A8, field:this:0x000002B0, field:this:0x000002B8, source:raw]
    // RETURN: Return the dot product used as the projection factor. [source:raw]

    // Conservative worker pseudocode:
    //   double ConstraintProjectGramSchmidt(int *this) {
    //     double *c = (double *)this[87];
    //     double a0 = *(double *)((char *)c + 28);
    //     double a1 = *(double *)((char *)c + 52);
    //     double a2 = *(double *)((char *)c + 76);
    //     double b0 = *(double *)((char *)c + 332);
    //     double b1 = *(double *)((char *)c + 340);
    //     double b2 = *(double *)((char *)c + 348);
    //     double result = a2*b2 + a1*b1 + a0*b0;
    //     *(double *)((char *)c + 332) = b0 - result*a0;
    //     *(double *)((char *)c + 340) = b1 - result*a1;
    //     *(double *)((char *)c + 348) = b2 - result*a2;
    //     return result;
    //   }
    // UNRESOLVED: Owner of the constraint data structure is unknown.
    // UNRESOLVED: The mapping between the packet's this-relative field offsets (0x178/0x190/0x1A8 for the reference vector, 0x2A8/0x2B0/0x2B8 for the orthogonalized vector) and the source's constraint-pointer-relative offsets (+28/+52/+76 and +332/+340/+348) is not established by the packet.
    // UNRESOLVED: The physical meaning of the two vectors (e.g. suspension direction vs. constraint axis) is not determinable from this function alone.
}
