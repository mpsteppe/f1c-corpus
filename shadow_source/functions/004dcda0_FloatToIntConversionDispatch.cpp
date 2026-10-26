// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DCDA0
// Canonical corpus name: FloatToIntConversionDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatToIntConversionDispatch_004dcda0.c

void UnknownObject::FloatToIntConversionDispatch()
{
    // Converts two floating-point arguments to integers after scaling them by the two global multipliers dword_5D6D60 and dword_5D6D64, then delegates to TwoFieldSetterUpdate with the two converted integers to update two fields on the receiver and re-render. Unconditional __thiscall with no guards.
    // CALL: Scale a3 by the global multiplier dword_5D6D64 and convert the product to an integer via CRTFtol, storing the result as v6. [global:0x005D6D64, callee:0x00587BDC]
    // CALL: Scale a2 by the global multiplier dword_5D6D60 and convert the product to an integer via CRTFtol, storing the result as v4. [global:0x005D6D60, callee:0x00587BDC]
    // CALL: Call TwoFieldSetterUpdate(this, v4, v6) to write the two converted integers into two receiver fields and re-render through sub_4DCA80. [callee:0x004DCD80]
    // RETURN: Return the value produced by TwoFieldSetterUpdate. [callee:0x004DCD80, source:raw]
    // CALL: Invoked by UICursorSelectionRectangleRenderWithInterpolatio (0x0045B660) as the integer-coordinate update dispatch for cursor-selection rectangle rendering. [caller:0x0045B660]

    // Conservative worker pseudocode:
    //   int sub_4DCDA0(void* self, float a2, float a3) {
    //     int v6 = CRTFtol((double)dword_5D6D64 * a3);
    //     int v4 = CRTFtol((double)dword_5D6D60 * a2);
    //     return TwoFieldSetterUpdate(self, v4, v6);
    //   }
    // UNRESOLVED: Purpose of the global multipliers dword_5D6D60 and dword_5D6D64 (resolution or screen scale factors) is not established by this packet.
    // UNRESOLVED: Object type and the semantic role of the two fields written by TwoFieldSetterUpdate are not established here.
}
