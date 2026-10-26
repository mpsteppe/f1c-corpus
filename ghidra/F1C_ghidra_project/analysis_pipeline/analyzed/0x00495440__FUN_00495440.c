// Function: FUN_00495440 @ 00495440
// Size (bytes): 314


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00495440(int param_1)

{
  float10 fVar1;
  int iVar2;
  undefined4 uVar3;
  short *psVar4;
  bool bVar5;
  float10 fVar6;
  undefined4 uVar7;
  int local_28;
  int local_24;
  undefined1 local_20 [32];
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x1598)) {
    psVar4 = (short *)(param_1 + 0x159c);
    do {
      if (*psVar4 == 0x1021) {
        bVar5 = *(char *)(param_1 + 0xe0) == '\0';
        *(bool *)(param_1 + 0xe0) = bVar5;
        if (!bVar5) {
          *(undefined4 *)(param_1 + 0xe4) = 0;
          *(undefined4 *)(param_1 + 0xe8) = 0;
          *(undefined4 *)(param_1 + 0xec) = 0;
        }
        break;
      }
      iVar2 = iVar2 + 1;
      psVar4 = psVar4 + 1;
    } while (iVar2 < *(int *)(param_1 + 0x1598));
  }
  if (*(char *)(param_1 + 0xe0) != '\0') {
    *(int *)(param_1 + 0xe8) = *(int *)(param_1 + 0xe8) + 1;
    fVar6 = (float10)FUN_00498730();
    fVar6 = fVar6 + (float10)*(float *)(param_1 + 0xec);
    fVar1 = (float10)_DAT_0059e450;
    *(float *)(param_1 + 0xec) = (float)fVar6;
    if (fVar1 < fVar6) {
      uVar3 = __ftol();
      *(undefined4 *)(param_1 + 0xe4) = uVar3;
      *(undefined4 *)(param_1 + 0xec) = 0;
      *(undefined4 *)(param_1 + 0xe8) = 0;
    }
    if (-1 < *(int *)(param_1 + 0xe4)) {
      FUN_0058815f(local_20,&DAT_005c3280,*(int *)(param_1 + 0xe4));
      FUN_004983b0(param_1 + 0x166c,&local_24,&local_28,1);
      if ((0 < local_24) && (0 < local_28)) {
        FUN_00498560(param_1 + 0x166c);
        FUN_004981f0(local_20,0,local_28,0,local_24,1);
        uVar7 = 0;
        uVar3 = 0;
        FUN_00490920(0,0,local_24,local_28);
        FUN_004918d0(uVar3,uVar7,local_24,local_28);
      }
    }
  }
  return;
}


