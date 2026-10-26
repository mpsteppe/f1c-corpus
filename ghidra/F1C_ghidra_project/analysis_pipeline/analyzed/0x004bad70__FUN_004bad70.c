// Function: FUN_004bad70 @ 004bad70
// Size (bytes): 176


void __thiscall FUN_004bad70(int *param_1,int *param_2,char param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  
  if (param_2 != (int *)0x0) {
    puVar2 = operator_new(0xc);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = param_2;
      puVar2[1] = 0;
      *(undefined1 *)(puVar2 + 2) = 1;
    }
    if (*param_1 == 0) {
      *param_1 = (int)puVar2;
      param_1[2] = (int)puVar2;
    }
    else {
      *(undefined4 **)(param_1[1] + 4) = puVar2;
    }
    param_1[1] = (int)puVar2;
    param_1[3] = param_1[3] + 1;
  }
  _param_3 = (param_3 != '\0') - 1 & 2;
  if (_param_3 != 0) {
    iVar4 = 0;
    do {
      iVar1 = *param_2;
      if (iVar1 + iVar4 != 0) {
        piVar3 = operator_new(0xc);
        if (piVar3 == (int *)0x0) {
          piVar3 = (int *)0x0;
        }
        else {
          *piVar3 = iVar1 + iVar4;
          piVar3[1] = 0;
          *(undefined1 *)(piVar3 + 2) = 0;
        }
        if (param_1[4] == 0) {
          param_1[5] = (int)piVar3;
          param_1[6] = (int)piVar3;
        }
        else {
          piVar3[1] = param_1[4];
        }
        param_1[4] = (int)piVar3;
        param_1[7] = param_1[7] + 1;
      }
      iVar4 = iVar4 + 0x374;
      _param_3 = _param_3 - 1;
    } while (_param_3 != 0);
  }
  return;
}


