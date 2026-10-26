// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00503888
// Canonical corpus name: FunctionPointerSwitch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FunctionPointerSwitch_00503888.c

void UnknownObject::FunctionPointerSwitch()
{
    // Selects a rendering function-pointer pair based on the sub_50FC7D() condition: on true it installs sub_503772 into both off_5D76C0 (primary) and off_5D76C4 (secondary); on false it installs ImageBlendingCompositing into off_5D76C0 and F_2DImageBoxFilter into off_5D76C4. It then calls the primary pointer off_5D76C0 and returns its result.
    // GUARD: Branch on the return value of sub_50FC7D() to select which function-pointer pair to install. [callee:0x0050FC7D, source:raw]
    // ASSIGNMENT: When the guard is true, set the primary pointer off_5D76C0 to sub_503772. [global:0x005D76C0, global:0x00503772, source:raw]
    // ASSIGNMENT: When the guard is true, set the secondary pointer off_5D76C4 to sub_503772. [global:0x005D76C4, global:0x00503772, source:raw]
    // ASSIGNMENT: When the guard is false, set the primary pointer off_5D76C0 to ImageBlendingCompositing. [global:0x005D76C0, global:0x00503533, source:raw]
    // ASSIGNMENT: When the guard is false, set the secondary pointer off_5D76C4 to F_2DImageBoxFilter. [global:0x005D76C4, global:0x0050368A, source:raw]
    // CALL: Indirect call through the installed primary pointer off_5D76C0 and return its integer result. [global:0x005D76C0, source:raw]

    // Conservative worker pseudocode:
    //   int FunctionPointerSwitch() {
    //     if (sub_50FC7D()) {
    //       off_5D76C0 = (_DWORD (*)())sub_503772;
    //       off_5D76C4 = (int (*)())sub_503772;
    //     } else {
    //       off_5D76C0 = (_DWORD (*)())ImageBlendingCompositing;
    //       off_5D76C4 = (int (*)())F_2DImageBoxFilter;
    //     }
    //     return off_5D76C0();
    //   }
    // UNRESOLVED: What sub_50FC7D() measures (hardware capability, config flag, or render state) is not grounded by the packet.
    // UNRESOLVED: The secondary pointer off_5D76C4 is written but never consumed inside this function; its downstream consumer is unknown.
    // UNRESOLVED: Why sub_503772 is used for both slots on the true path while the false path uses two distinct functions is unexplained.
}
