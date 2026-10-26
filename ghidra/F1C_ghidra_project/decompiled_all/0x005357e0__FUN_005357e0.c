// Function: FUN_005357e0 @ 005357e0
// Strings:  [need dictionary, incorrect data check, incorrect header check, invalid window size, unknown compression method]


uint __fastcall FUN_005357e0(int *param_1,int param_2)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  
  if (((param_1 == (int *)0x0) || (param_1[7] == 0)) || (*param_1 == 0)) {
switchD_0053582b_default:
    return 0xfffffffe;
  }
  uVar5 = (param_2 != 4) - 1 & 0xfffffffb;
  uVar4 = 0xfffffffb;
  do {
    switch(*(undefined4 *)param_1[7]) {
    case 0:
      if (param_1[1] == 0) {
        return uVar4;
      }
      param_1[1] = param_1[1] + -1;
      param_1[2] = param_1[2] + 1;
      ((undefined4 *)param_1[7])[1] = (uint)*(byte *)*param_1;
      puVar3 = (undefined4 *)param_1[7];
      uVar2 = puVar3[1];
      *param_1 = *param_1 + 1;
      if (((byte)uVar2 & 0xf) != 8) {
        *puVar3 = 0xd;
        param_1[6] = (int)s_unknown_compression_method_005da7fc;
        *(undefined4 *)(param_1[7] + 4) = 5;
        uVar4 = uVar5;
        break;
      }
      if ((uint)puVar3[4] < ((uint)puVar3[1] >> 4) + 8) {
        *puVar3 = 0xd;
        param_1[6] = (int)s_invalid_window_size_005da7e8;
        *(undefined4 *)(param_1[7] + 4) = 5;
        uVar4 = uVar5;
        break;
      }
      *puVar3 = 1;
      uVar4 = uVar5;
    case 1:
      if (param_1[1] == 0) {
        return uVar4;
      }
      param_1[1] = param_1[1] + -1;
      puVar3 = (undefined4 *)param_1[7];
      param_1[2] = param_1[2] + 1;
      bVar1 = *(byte *)*param_1;
      *param_1 = (int)((byte *)*param_1 + 1);
      if ((puVar3[1] * 0x100 + (uint)bVar1) % 0x1f == 0) {
        if ((bVar1 & 0x20) != 0) {
          *(undefined4 *)param_1[7] = 2;
          uVar4 = uVar5;
          goto switchD_0053582b_caseD_2;
        }
        *puVar3 = 7;
        uVar4 = uVar5;
      }
      else {
        *puVar3 = 0xd;
        param_1[6] = (int)s_incorrect_header_check_005da7d0;
        *(undefined4 *)(param_1[7] + 4) = 5;
        uVar4 = uVar5;
      }
      break;
    case 2:
switchD_0053582b_caseD_2:
      if (param_1[1] == 0) {
        return uVar4;
      }
      param_1[2] = param_1[2] + 1;
      param_1[1] = param_1[1] + -1;
      *(uint *)(param_1[7] + 8) = (uint)*(byte *)*param_1 << 0x18;
      *param_1 = *param_1 + 1;
      *(undefined4 *)param_1[7] = 3;
      uVar4 = uVar5;
switchD_0053582b_caseD_3:
      if (param_1[1] == 0) {
        return uVar4;
      }
      param_1[1] = param_1[1] + -1;
      param_1[2] = param_1[2] + 1;
      *(uint *)(param_1[7] + 8) = *(int *)(param_1[7] + 8) + (uint)*(byte *)*param_1 * 0x10000;
      *param_1 = *param_1 + 1;
      *(undefined4 *)param_1[7] = 4;
      uVar4 = uVar5;
switchD_0053582b_caseD_4:
      if (param_1[1] == 0) {
        return uVar4;
      }
      param_1[1] = param_1[1] + -1;
      param_1[2] = param_1[2] + 1;
      *(uint *)(param_1[7] + 8) = *(int *)(param_1[7] + 8) + (uint)*(byte *)*param_1 * 0x100;
      *param_1 = *param_1 + 1;
      *(undefined4 *)param_1[7] = 5;
      uVar4 = uVar5;
switchD_0053582b_caseD_5:
      if (param_1[1] == 0) {
        return uVar4;
      }
      param_1[1] = param_1[1] + -1;
      param_1[2] = param_1[2] + 1;
      *(uint *)(param_1[7] + 8) = *(int *)(param_1[7] + 8) + (uint)*(byte *)*param_1;
      *param_1 = *param_1 + 1;
      param_1[0xc] = ((undefined4 *)param_1[7])[2];
      *(undefined4 *)param_1[7] = 6;
      return 2;
    case 3:
      goto switchD_0053582b_caseD_3;
    case 4:
      goto switchD_0053582b_caseD_4;
    case 5:
      goto switchD_0053582b_caseD_5;
    case 6:
      *(undefined4 *)param_1[7] = 0xd;
      param_1[6] = (int)s_need_dictionary_005da7a8;
      *(undefined4 *)(param_1[7] + 4) = 0;
      return 0xfffffffe;
    case 7:
      uVar4 = FUN_00537110(uVar4);
      if (uVar4 == 0xfffffffd) {
        *(undefined4 *)param_1[7] = 0xd;
        *(undefined4 *)(param_1[7] + 4) = 0;
        uVar4 = 0xfffffffd;
      }
      else {
        if (uVar4 == 0) {
          uVar4 = uVar5;
        }
        if (uVar4 != 1) {
          return uVar4;
        }
        FUN_00537000(param_1[7] + 4);
        puVar3 = (undefined4 *)param_1[7];
        if (puVar3[3] == 0) {
          *puVar3 = 8;
          uVar4 = uVar5;
          goto switchD_0053582b_caseD_8;
        }
        *puVar3 = 0xc;
        uVar4 = uVar5;
      }
      break;
    case 8:
switchD_0053582b_caseD_8:
      if (param_1[1] == 0) {
        return uVar4;
      }
      param_1[2] = param_1[2] + 1;
      param_1[1] = param_1[1] + -1;
      *(uint *)(param_1[7] + 8) = (uint)*(byte *)*param_1 << 0x18;
      *param_1 = *param_1 + 1;
      *(undefined4 *)param_1[7] = 9;
      uVar4 = uVar5;
switchD_0053582b_caseD_9:
      if (param_1[1] == 0) {
        return uVar4;
      }
      param_1[2] = param_1[2] + 1;
      param_1[1] = param_1[1] + -1;
      *(uint *)(param_1[7] + 8) = *(int *)(param_1[7] + 8) + (uint)*(byte *)*param_1 * 0x10000;
      *param_1 = *param_1 + 1;
      *(undefined4 *)param_1[7] = 10;
      uVar4 = uVar5;
switchD_0053582b_caseD_a:
      if (param_1[1] == 0) {
        return uVar4;
      }
      param_1[2] = param_1[2] + 1;
      param_1[1] = param_1[1] + -1;
      *(uint *)(param_1[7] + 8) = *(int *)(param_1[7] + 8) + (uint)*(byte *)*param_1 * 0x100;
      *param_1 = *param_1 + 1;
      *(undefined4 *)param_1[7] = 0xb;
      uVar4 = uVar5;
switchD_0053582b_caseD_b:
      if (param_1[1] == 0) {
        return uVar4;
      }
      param_1[1] = param_1[1] + -1;
      param_1[2] = param_1[2] + 1;
      *(uint *)(param_1[7] + 8) = *(int *)(param_1[7] + 8) + (uint)*(byte *)*param_1;
      *param_1 = *param_1 + 1;
      puVar3 = (undefined4 *)param_1[7];
      if (puVar3[1] == puVar3[2]) {
        *(undefined4 *)param_1[7] = 0xc;
switchD_0053582b_caseD_c:
        return 1;
      }
      *puVar3 = 0xd;
      param_1[6] = (int)s_incorrect_data_check_005da7b8;
      *(undefined4 *)(param_1[7] + 4) = 5;
      uVar4 = uVar5;
      break;
    case 9:
      goto switchD_0053582b_caseD_9;
    case 10:
      goto switchD_0053582b_caseD_a;
    case 0xb:
      goto switchD_0053582b_caseD_b;
    case 0xc:
      goto switchD_0053582b_caseD_c;
    case 0xd:
      return 0xfffffffd;
    default:
      goto switchD_0053582b_default;
    }
  } while( true );
}


