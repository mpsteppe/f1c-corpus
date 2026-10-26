// Function: FUN_00559a70 @ 00559a70
// Size (bytes): 85


int __fastcall FUN_00559a70(int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    if (param_1[2] <= param_1[1]) {
      *param_1 = 3;
      break;
    }
    *(undefined1 *)(iVar3 + 0xc + (int)param_1) = *(undefined1 *)(param_1[1] + param_1[0xc4]);
    cVar1 = *(char *)(param_1[1] + param_1[0xc4]);
    iVar3 = iVar3 + 1;
    param_1[1] = param_1[1] + 1;
  } while (cVar1 != '\n');
  *(undefined1 *)(iVar3 + 0xc + (int)param_1) = 0;
  iVar2 = *param_1;
  if (0 < iVar3) {
    if (iVar2 != 3) {
      iVar3 = FUN_00559ad0();
      *param_1 = iVar3;
    }
    iVar2 = *param_1;
  }
  return iVar2;
}


