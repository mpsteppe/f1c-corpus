// Function: FUN_005592b0 @ 005592b0
// Size (bytes): 122


undefined4 __thiscall FUN_005592b0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x148);
  do {
    if (iVar2 == 0) {
LAB_00559311:
      piVar1 = (int *)(param_1 + 0x144);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        *(undefined4 *)(param_1 + 0x148) = 0;
      }
      return 0;
    }
    if (iVar2 == param_2) {
      if (*(int *)(iVar2 + 100) != 0) {
        *(undefined4 *)(*(int *)(iVar2 + 100) + 0x68) = *(undefined4 *)(iVar2 + 0x68);
      }
      if (*(int *)(iVar2 + 0x68) != 0) {
        *(undefined4 *)(*(int *)(iVar2 + 0x68) + 100) = *(undefined4 *)(iVar2 + 100);
      }
      if (iVar2 == *(int *)(param_1 + 0x148)) {
        *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(iVar2 + 0x68);
      }
      FUN_005574b0();
      FUN_00557470();
      FUN_00587bcf(iVar2);
      goto LAB_00559311;
    }
    iVar2 = *(int *)(iVar2 + 0x68);
  } while( true );
}


