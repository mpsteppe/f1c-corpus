// Function: FUN_0045c0c0 @ 0045c0c0
// Size (bytes): 380


void __thiscall FUN_0045c0c0(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  char *pcVar7;
  undefined4 local_204;
  char local_200 [512];
  
  FUN_00565f80(param_2,1,param_3,1);
  FUN_00565f50();
  iVar3 = FUN_005662d0();
  do {
    if (iVar3 == 0) {
      return;
    }
    FUN_0058815f(local_200,&DAT_005be860,param_3,iVar3);
    if (param_4 == 1) {
      cVar2 = FUN_0045c400(local_200,&local_204);
    }
    else if (param_4 == 2) {
      cVar2 = FUN_0045c650(local_200,&local_204);
    }
    else {
      cVar2 = FUN_00568a60(*(undefined1 *)(param_1 + 1),&local_204);
    }
    if (cVar2 != '\0') {
      uVar6 = 0xffffffff;
      pcVar7 = local_200;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar2 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar2 != '\0');
      pcVar7 = local_200 + (~uVar6 - 1);
      if (local_200 < pcVar7) {
        do {
          if (*pcVar7 == '\\') {
            pcVar7 = pcVar7 + 1;
            break;
          }
          pcVar7 = pcVar7 + -1;
        } while (local_200 < pcVar7);
      }
      puVar4 = operator_new(0xc);
      uVar1 = local_204;
      if (puVar4 == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)0x0;
      }
      else {
        *puVar4 = 0;
        puVar4[1] = 0xffffffff;
        FUN_00566650(pcVar7);
        puVar4[2] = uVar1;
      }
      if (puVar4 != (undefined4 *)0x0) {
        puVar5 = operator_new(0xc);
        if (puVar5 == (undefined4 *)0x0) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          *puVar5 = puVar4;
          puVar5[1] = 0;
          *(undefined1 *)(puVar5 + 2) = 1;
        }
        if (*(int *)(param_1 + 4) == 0) {
          *(undefined4 **)(param_1 + 4) = puVar5;
          *(undefined4 **)(param_1 + 0xc) = puVar5;
        }
        else {
          *(undefined4 **)(*(int *)(param_1 + 8) + 4) = puVar5;
        }
        *(undefined4 **)(param_1 + 8) = puVar5;
        *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
      }
    }
    cVar2 = FUN_00565f20();
    if (cVar2 == '\0') {
      return;
    }
    iVar3 = FUN_005662d0();
  } while( true );
}


