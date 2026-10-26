// Function: FUN_0041f340 @ 0041f340
// Strings:  [TOYOTA, TOYOTA, STEWART, STEWART, RENAULT, RENAULT, BENETTON, BENETTON]


/* WARNING: Removing unreachable block (ram,0x0041f52b) */
/* WARNING: Removing unreachable block (ram,0x0041f548) */

undefined4 * __fastcall FUN_0041f340(int param_1,char param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 *local_10;
  int local_c;
  
  local_10 = operator_new(8);
  iVar3 = 0;
  if (local_10 == (undefined4 *)0x0) {
    local_10 = (undefined4 *)0x0;
  }
  else {
    *local_10 = 0;
    local_10[1] = 0xffffffff;
  }
  local_c = -1;
  do {
    switch(iVar3) {
    case 0:
      pcVar4 = s_ARROWS_005c25f4;
      break;
    case 1:
      pcVar4 = (char *)&PTR_DAT_005c25e0;
      break;
    case 2:
      pcVar4 = s_RENAULT_005c25c4;
      break;
    case 3:
      pcVar4 = s_FERRARI_005c2618;
      break;
    case 4:
      pcVar4 = s_JAGUAR_005c25d8;
      break;
    case 5:
      pcVar4 = s_JORDAN_005c2604;
      break;
    case 6:
      pcVar4 = s_MCLAREN_005c2620;
      break;
    case 7:
      pcVar4 = s_MINARDI_005c25e4;
      break;
    case 8:
      pcVar4 = s_PROST_005c25ec;
      break;
    case 9:
      pcVar4 = s_SAUBER_005c25fc;
      break;
    case 10:
      pcVar4 = s_WILLIAMS_005c260c;
      break;
    case 0xb:
      pcVar4 = s_TOYOTA_005c25b4;
      break;
    case 0xc:
      pcVar4 = s_BENETTON_005c25cc;
      break;
    case 0xd:
      pcVar4 = s_STEWART_005c25bc;
      break;
    default:
      goto LAB_0041f402;
    }
    FUN_00566650(pcVar4);
LAB_0041f402:
    iVar1 = FUN_0041f220();
    if ((local_c < iVar1) && ((param_1 == 0 || (iVar2 = FUN_00566810(), iVar2 == 0)))) {
      FUN_00566650(&DAT_005ea438);
      local_c = iVar1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0xe);
  if (param_2 == '\0') {
    iVar3 = 0;
    do {
      switch(iVar3) {
      case 0:
        pcVar4 = s_ARROWS_005c25f4;
        break;
      case 1:
        pcVar4 = (char *)&PTR_DAT_005c25e0;
        break;
      case 2:
        pcVar4 = s_RENAULT_005c25c4;
        break;
      case 3:
        pcVar4 = s_FERRARI_005c2618;
        break;
      case 4:
        pcVar4 = s_JAGUAR_005c25d8;
        break;
      case 5:
        pcVar4 = s_JORDAN_005c2604;
        break;
      case 6:
        pcVar4 = s_MCLAREN_005c2620;
        break;
      case 7:
        pcVar4 = s_MINARDI_005c25e4;
        break;
      case 8:
        pcVar4 = s_PROST_005c25ec;
        break;
      case 9:
        pcVar4 = s_SAUBER_005c25fc;
        break;
      case 10:
        pcVar4 = s_WILLIAMS_005c260c;
        break;
      case 0xb:
        pcVar4 = s_TOYOTA_005c25b4;
        break;
      case 0xc:
        pcVar4 = s_BENETTON_005c25cc;
        break;
      case 0xd:
        pcVar4 = s_STEWART_005c25bc;
        break;
      default:
        goto LAB_0041f4f3;
      }
      FUN_00566650(pcVar4);
LAB_0041f4f3:
      iVar1 = FUN_00566810();
      if ((iVar1 == 0) && (iVar1 = FUN_0041f220(), local_c == iVar1)) {
        return (undefined4 *)0x0;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0xe);
  }
  return local_10;
}


