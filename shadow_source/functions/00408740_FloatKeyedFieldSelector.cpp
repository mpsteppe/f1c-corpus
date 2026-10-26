// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00408740
// Canonical corpus name: FloatKeyedFieldSelector
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatKeyedFieldSelector_00408740.c

void UnknownObject::FloatKeyedFieldSelector()
{
    // Switch-based field selector keyed on the integer bit pattern of the float argument a2 (LODWORD(a2)). Nine cases select one dword field from this[4..12]; case 4 additionally offsets its field by 200 * this[15]. When the selected value and the enable flag this[1] are both non-zero, the function extracts two float components via DualFieldGetter, converts them from degrees to radians using flt_59E65C (0.01745433), calls the trigonometry helper sub_542050, and stores the original key back into this[13]. The default case returns without processing.
    // STATE_TRANSITION: Dispatch on LODWORD(a2) through the jump table jpt_408752 over nine cases, each selecting a dword field this[4] through this[12] (byte offsets 0x10 to 0x30) as the working value. [function:0x00408740, global:0x004087DC, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, source:raw]
    // CALCULATION: Case 4 combines the base field with a scaled offset: working value = this[8] + 200 * this[15] (byte offsets 0x20 and 0x3C). [field:this:0x00000020, field:this:0x0000003C, source:raw]
    // GUARD: Proceed only when the selected working value and the enable flag this[1] (byte offset 0x4) are both non-zero. [field:this:0x00000004, source:raw]
    // CALL: Call DualFieldGetter to extract two float components from the input, writing them into the out-parameter and the transformed key. [callee:0x00456060, source:raw]
    // CALCULATION: Convert both extracted components from degrees to radians by multiplying by the constant flt_59E65C (0.01745433). [global:0x0059E65C, source:raw]
    // CALL: Call the trigonometry helper sub_542050 with the two converted components and a zero third argument; its return value becomes the function result. [callee:0x00542050, source:raw]
    // ASSIGNMENT: Store the original float key a2 back into this[13] (byte offset 0x34). [field:this:0x00000034, source:raw]
    // RETURN: Return the computation result; the default case returns without touching the selected fields or the stored key. [function:0x00408740, source:raw]

    // Conservative worker pseudocode:
    //   int FloatKeyedFieldSelector(float* this, float key) {
    //     float keyCopy = key;
    //     int v4 = 0;
    //     switch ((int)key) {
    //       case 0: v4 = this[4]; break;
    //       case 1: v4 = this[5]; break;
    //       case 2: v4 = this[6]; break;
    //       case 3: v4 = this[7]; break;
    //       case 4: v4 = this[8] + 200 * this[15]; break;
    //       case 5: v4 = this[9]; break;
    //       case 6: v4 = this[10]; break;
    //       case 7: v4 = this[11]; break;
    //       case 8: v4 = this[12]; break;
    //       default: return 0;
    //     }
    //     if (v4 && this[1]) {
    //       float a, b;
    //       DualFieldGetter(&b, &key);
    //       float r = key * 0.01745433;
    //       float r2 = b * 0.01745433;
    //       int result = sub_542050(r2, r, 0);
    //       this[13] = keyCopy;
    //       return result;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The semantic meaning of the nine selected fields and the special 200-scaled case 4 is unconfirmed.
    // UNRESOLVED: The exact role of sub_542050 (trigonometry) and why the selected field must be non-zero are unresolved.
    // UNRESOLVED: The degrees-to-radians factor flt_59E65C (0.01745433) is applied as a literal conversion constant; its camera-shake interpretation is DERIVED prose, not runtime evidence.
    // UNRESOLVED: The owning camera/view object is unknown; the sole caller is ViewCameraModeDispatch.
}
