// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DCEE0
// Canonical corpus name: sub_4DCEE0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4DCEE0_004dcee0.c

void UnknownObject::FloatToIntChainDelegate()
{
    // Converts three float arguments to integers — a4 directly, a2 and a3 scaled by the global multipliers dword_5D6D60 and dword_5D6D64 — then delegates to PositionComputationWithAlignment with the three converted integers plus the pass-through a5 to compute an aligned screen position and re-render. Unconditional __thiscall with no guards. Structural twin of FloatToIntConversionDispatch, which resolves two conversions and dispatches to TwoFieldSetterUpdate instead.
    // CALL: Convert a4 directly to an integer via CRTFtol, storing the result as v9. [callee:0x00587BDC]
    // CALL: Scale a3 by the global multiplier dword_5D6D64 and convert the product to an integer via CRTFtol, storing the result as v8. [global:0x005D6D64, callee:0x00587BDC]
    // CALL: Scale a2 by the global multiplier dword_5D6D60 and convert the product to an integer via CRTFtol, storing the result as v6. [global:0x005D6D60, callee:0x00587BDC]
    // CALL: Call PositionComputationWithAlignment(this, v6, v8, v9, a5) to compute and store the aligned position fields and re-render through sub_4DCA80. [callee:0x004DCDD0]
    // RETURN: Return the value produced by PositionComputationWithAlignment. [callee:0x004DCDD0, source:raw]
    // CALL: Invoked by UICursorSelectionRectangleRenderWithInterpolatio (0x0045B660) alongside FloatToIntConversionDispatch as the aligned-position variant of the same UI rendering path. [caller:0x0045B660]

    // Conservative worker pseudocode:
    //   int sub_4DCEE0(void* self, float a2, float a3, float a4, int a5) {
    //     int v9 = CRTFtol(a4);
    //     int v8 = CRTFtol((double)dword_5D6D64 * a3);
    //     int v6 = CRTFtol((double)dword_5D6D60 * a2);
    //     return PositionComputationWithAlignment(self, v6, v8, v9, a5);
    //   }
    // UNRESOLVED: Purpose of the global multipliers dword_5D6D60 and dword_5D6D64 (resolution or screen scale factors) is not established by this packet.
    // UNRESOLVED: Object type and the semantic role of a5 passed to PositionComputationWithAlignment are not established here.
}
