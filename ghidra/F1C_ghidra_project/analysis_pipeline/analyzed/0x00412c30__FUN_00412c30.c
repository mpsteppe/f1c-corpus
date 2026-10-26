// Function: FUN_00412c30 @ 00412c30
// Size (bytes): 406


undefined4 FUN_00412c30(int param_1,int param_2,undefined4 param_3,char param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0xffffffff;
  if (param_2 == 0) {
    switch(param_3) {
    case 1:
      iVar2 = 0xbd - (uint)(param_4 != '\0');
      break;
    case 2:
      iVar2 = 0xbb - (uint)(param_4 != '\0');
      break;
    case 3:
      iVar2 = 0xb9 - (uint)(param_4 != '\0');
      break;
    case 4:
      iVar2 = 0xb7 - (uint)(param_4 != '\0');
      break;
    case 5:
      iVar2 = 0xb5 - (uint)(param_4 != '\0');
      break;
    case 6:
      iVar2 = 0xb3 - (uint)(param_4 != '\0');
      break;
    case 7:
      iVar2 = 0xb1 - (uint)(param_4 != '\0');
      break;
    case 8:
      iVar2 = 0xaf - (uint)(param_4 != '\0');
      break;
    case 9:
      iVar2 = 0xad - (uint)(param_4 != '\0');
      break;
    case 10:
      iVar2 = 0xab - (uint)(param_4 != '\0');
      break;
    case 0xb:
      iVar2 = 0xa9 - (uint)(param_4 != '\0');
      break;
    case 0xc:
      iVar2 = 0xa7 - (uint)(param_4 != '\0');
      break;
    default:
      goto switchD_00412c54_caseD_d;
    case 0xf:
      iVar2 = 0xa5 - (uint)(param_4 != '\0');
      break;
    case 0x14:
      iVar2 = 0xa3 - (uint)(param_4 != '\0');
      break;
    case 0x19:
      iVar2 = 0xa1 - (uint)(param_4 != '\0');
      break;
    case 0x1e:
      iVar2 = 0x9f - (uint)(param_4 != '\0');
      break;
    case 0x23:
      iVar2 = 0x9d - (uint)(param_4 != '\0');
      break;
    case 0x28:
      iVar2 = 0x9b - (uint)(param_4 != '\0');
      break;
    case 0x32:
      iVar2 = 0x99 - (uint)(param_4 != '\0');
    }
    if (-1 < iVar2) {
      *(int *)(param_1 + 8) = iVar2;
      uVar1 = FUN_00414180(0);
      *(undefined4 *)(param_1 + 0xc) = uVar1;
      uVar1 = 1;
    }
  }
switchD_00412c54_caseD_d:
  return uVar1;
}


