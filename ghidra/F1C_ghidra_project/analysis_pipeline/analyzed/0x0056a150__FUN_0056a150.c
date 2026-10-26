// Function: FUN_0056a150 @ 0056a150
// Size (bytes): 233


void __fastcall FUN_0056a150(undefined4 *param_1)

{
  double *pdVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  double *pdVar5;
  
  puVar3 = param_1 + 0x59;
  puVar4 = param_1;
  for (iVar2 = 6; puVar4 = puVar4 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
  }
  puVar4 = param_1 + 0x5f;
  puVar3 = param_1 + 7;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar4 = param_1 + 0x71;
  puVar3 = param_1 + 0x19;
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar3 = puVar3 + 1;
  }
  pdVar1 = (double *)(param_1 + 0x25);
  puVar4 = param_1 + 0x77;
  pdVar5 = pdVar1;
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined4 *)pdVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    pdVar5 = (double *)((int)pdVar5 + 4);
  }
  puVar4 = param_1 + 0x7d;
  puVar3 = param_1 + 0x4d;
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar4 = param_1 + 0x83;
  puVar3 = param_1 + 0x53;
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_005692a0();
  *(double *)(param_1 + 0x1f) =
       *(double *)(param_1 + 0x3b) * *pdVar1 +
       *(double *)(param_1 + 0x3d) * *(double *)(param_1 + 0x27) +
       *(double *)(param_1 + 0x3f) * *(double *)(param_1 + 0x29);
  *(double *)(param_1 + 0x21) =
       *(double *)(param_1 + 0x41) * *pdVar1 +
       *(double *)(param_1 + 0x43) * *(double *)(param_1 + 0x27) +
       *(double *)(param_1 + 0x45) * *(double *)(param_1 + 0x29);
  *(double *)(param_1 + 0x23) =
       *(double *)(param_1 + 0x47) * *pdVar1 +
       *(double *)(param_1 + 0x49) * *(double *)(param_1 + 0x27) +
       *(double *)(param_1 + 0x4b) * *(double *)(param_1 + 0x29);
  return;
}


