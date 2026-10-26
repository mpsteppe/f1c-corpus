// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059532B
// Canonical corpus name: BigIntegerRightShift
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BigIntegerRightShift_0059532b.c

void UnknownObject::BigIntegerRightShift()
{
    // In-place right shift of a 3-limb big integer a1 by a2 bits (a2 = whole-word shift v8 * 32 + bit shift v3). First pass walks the 3 limbs ascending, shifting each limb right by v3 bits and ORing in the carry produced from the low bits of the previous limb. Second pass walks the limbs descending, zeroing limbs below the whole-word shift (i < v8) and copying limbs down by v8 words otherwise. Returns the final assigned limb value.
    // CALCULATION: Decompose the shift: whole-word shift v8 = a2 / 32 and bit shift v3 = a2 % 32; seed the carry-in v11 to 0 and the limb countdown v10 to 3. [source:raw]
    // LOOP: Bit-shift pass over the 3 limbs (countdown v10 from 3 to 1): for each limb extract the low v3 bits into v9, write (carry-in v11 | (unsigned)limb >> v3), and propagate the extracted bits left-shifted by (32 - v3) into v11 as the carry for the next limb. [field:this:0x00000000, source:raw]
    // CALCULATION: Carry extraction and propagation: v9 = ~(-1 << v3) & *v2 captures the low v3 bits being shifted out; v11 = v9 << (32 - v3) moves them into the next limb's high bits. [field:this:0x00000000, source:raw]
    // LOOP: Whole-word shift pass over limb indices 2 down to 0: when the index is below v8 the limb is zeroed; otherwise the limb is replaced by the limb v8 words lower, a1[i] = a1[i - v8]. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Zero the limbs covered entirely by the whole-word shift (i < v8). [field:this:0x00000000, source:raw]
    // RETURN: Return result, the limb value assigned on the final (i = 0) iteration. [function:0x0059532B, source:raw]
    // CALL: Called by sub_5953B8 (0x005953B8), the same caller as the sibling ArrayOf3ZeroCheck, to shift a 3-limb integer right. [caller:0x005953B8, source:raw]

    // Conservative worker pseudocode:
    //   int* sub_59532B(int* a1, int a2) {
    //     int v8 = a2 / 32; int v3 = a2 % 32; int v11 = 0;
    //     int* v2 = a1; int v10 = 3;
    //     do {
    //       int v9 = ~(-1 << v3) & *v2;
    //       *v2 = v11 | ((unsigned int)*v2 >> v3);
    //       ++v2;
    //       v11 = v9 << (32 - v3);
    //     } while (--v10 != 0);
    //     int result;
    //     for (int i = 2; i >= 0; --i) {
    //       if (i < v8) { result = (int)a1; a1[i] = 0; }
    //       else { result = a1[i - v8]; a1[i] = result; }
    //     }
    //     return (int*)result;
    //   }
    // UNRESOLVED: The prelabel cluster note ('structural twin of FloatClamp 004646c0') is a template-cluster artifact and does not describe this function's arithmetic; it is not adopted.
    // UNRESOLVED: The limb ordering implied by the ascending carry pass (index 0 least significant) is inferred from the shift direction and is not independently evidenced by the packet.
}
