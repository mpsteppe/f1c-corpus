// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005692A0
// Canonical corpus name: F_3x3InertiaTensorTransform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3x3InertiaTensorTransform_005692a0.c

void UnknownObject::F_3x3InertiaTensorTransform()
{
    // Transforms the diagonal body-space inertia tensor into world space as R * I * R^T using the 3x3 rotation matrix (doubles at 0x1C..0x5C) and the diagonal inertia components (0xD4, 0xDC, 0xE4). Writes the symmetric world-space inertia matrix at 0xEC..0x12C, computing the upper triangle then mirroring it to the lower triangle via paired DWORD half-copies.
    // CALCULATION: Load the 3x3 rotation matrix R (doubles at 0x1C, 0x24, 0x2C, 0x34, 0x3C, 0x44, 0x4C, 0x54, 0x5C) and the diagonal body inertia components Ixx (0xD4), Iyy (0xDC), Izz (0xE4). [field:this:0x0000001C, field:this:0x00000024, field:this:0x0000002C, field:this:0x00000034, field:this:0x0000003C, field:this:0x00000044, field:this:0x0000004C, field:this:0x00000054, field:this:0x0000005C, field:this:0x000000D4, field:this:0x000000DC, field:this:0x000000E4]
    // CALCULATION: Compute column products of matrix column 0 scaled by the inertia diagonal: v1 = R00*Ixx, v2 = R10*Iyy, v3 = R20*Izz. [field:this:0x0000001C, field:this:0x00000024, field:this:0x0000002C, field:this:0x000000D4, field:this:0x000000DC, field:this:0x000000E4]
    // CALCULATION: Compute column products of matrix column 1 scaled by the inertia diagonal: v5 = R01*Ixx, v6 = R11*Iyy, v7 = R21*Izz. [field:this:0x00000034, field:this:0x0000003C, field:this:0x00000044, field:this:0x000000D4, field:this:0x000000DC, field:this:0x000000E4]
    // CALCULATION: Compute column products of matrix column 2 scaled by the inertia diagonal: v8 = R02*Ixx, v9 = R12*Iyy, v10 = R22*Izz. [field:this:0x0000004C, field:this:0x00000054, field:this:0x0000005C, field:this:0x000000D4, field:this:0x000000DC, field:this:0x000000E4]
    // ASSIGNMENT: Write world-space inertia element (0,0) at 0xEC as v1*R00 + v2*R10 + v3*R20. [field:this:0x000000EC, field:this:0x0000001C, field:this:0x00000024, field:this:0x0000002C]
    // ASSIGNMENT: Write world-space inertia element (0,1) at 0xF4 as v1*R01 + v2*R11 + v3*R21. [field:this:0x000000F4, field:this:0x00000034, field:this:0x0000003C, field:this:0x00000044]
    // ASSIGNMENT: Write world-space inertia element (0,2) at 0xFC as v1*R02 + v2*R12 + v3*R22. [field:this:0x000000FC, field:this:0x0000004C, field:this:0x00000054, field:this:0x0000005C]
    // ASSIGNMENT: Mirror element (0,1) into (1,0) at 0x104/0x108 by copying the two DWORD halves of the double at 0xF4, reading the high DWORD from 0xF8. [field:this:0x00000104, field:this:0x00000108, field:this:0x000000F8]
    // ASSIGNMENT: Write world-space inertia element (1,1) at 0x10C as v5*R01 + v6*R11 + v7*R21. [field:this:0x0000010C, field:this:0x00000034, field:this:0x0000003C, field:this:0x00000044]
    // ASSIGNMENT: Write world-space inertia element (1,2) at 0x114 as v5*R02 + v6*R12 + v7*R22. [field:this:0x00000114, field:this:0x0000004C, field:this:0x00000054, field:this:0x0000005C]
    // ASSIGNMENT: Mirror element (0,2) into (2,0) at 0x11C/0x120 by copying the two DWORD halves of the double at 0xFC, reading the high DWORD from 0x100. [field:this:0x0000011C, field:this:0x00000120, field:this:0x00000100]
    // ASSIGNMENT: Mirror element (1,2) into (2,1) at 0x124/0x128 by copying the two DWORD halves of the double at 0x114, reading the high DWORD from 0x118. [field:this:0x00000124, field:this:0x00000128, field:this:0x00000118]
    // ASSIGNMENT: Write world-space inertia element (2,2) at 0x12C as v8*R02 + v9*R12 + v10*R22. [field:this:0x0000012C, field:this:0x0000004C, field:this:0x00000054, field:this:0x0000005C]
    // RETURN: Return the low DWORD of the (1,2) element (0x114), the value left in EAX by the final DWORD half-copy. [function:0x005692A0, source:raw]

    // Conservative worker pseudocode:
    //   // diagonal I = {0xD4, 0xDC, 0xE4}; rotation R (doubles) at 0x1C..0x5C; output W = R*I*R^T at 0xEC..0x12C.
    //   // upper triangle W[0][c] = v_row_c dot column c of R, where v_row_c = column c of R * I diagonal.
    //   // lower triangle mirrors the upper via two DWORD half-copies per double element.
    // UNRESOLVED: Exact matrix element ordering (column-major vs row-major) cannot be decided from this packet alone.
    // UNRESOLVED: The lower triangle is written by DWORD copies of doubles (high half read from the adjacent 0xF8/0x100/0x118), a compiler artifact of symmetric layout.
    // UNRESOLVED: Return value (low DWORD of element (1,2)) has no obvious semantic purpose; callers likely ignore it.
}
