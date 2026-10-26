// Function: FUN_0041f5d0 @ 0041f5d0
// Strings:  [TOYOTA, TOYOTA, STEWART, STEWART, RENAULT, RENAULT, BENETTON, BENETTON]


/* WARNING: Removing unreachable block (ram,0x0041f7fb) */
/* WARNING: Removing unreachable block (ram,0x0041f818) */

undefined4 * __fastcall FUN_0041f5d0(int param_1,char param_2)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined4 *local_14;
  
  local_14 = operator_new(8);
  iVar5 = 0;
  if (local_14 == (undefined4 *)0x0) {
    local_14 = (undefined4 *)0x0;
  }
  else {
    *local_14 = 0;
    local_14[1] = 0xffffffff;
  }
  iVar4 = -1;
  FUN_004c2850();
  iVar1 = FUN_004c11d0();
  if (iVar1 < 2) {
    return (undefined4 *)0x0;
  }
  do {
    switch(iVar5) {
    case 0:
      pcVar6 = s_ARROWS_005c25f4;
      break;
    case 1:
      pcVar6 = (char *)&PTR_DAT_005c25e0;
      break;
    case 2:
      pcVar6 = s_RENAULT_005c25c4;
      break;
    case 3:
      pcVar6 = s_FERRARI_005c2618;
      break;
    case 4:
      pcVar6 = s_JAGUAR_005c25d8;
      break;
    case 5:
      pcVar6 = s_JORDAN_005c2604;
      break;
    case 6:
      pcVar6 = s_MCLAREN_005c2620;
      break;
    case 7:
      pcVar6 = s_MINARDI_005c25e4;
      break;
    case 8:
      pcVar6 = s_PROST_005c25ec;
      break;
    case 9:
      pcVar6 = s_SAUBER_005c25fc;
      break;
    case 10:
      pcVar6 = s_WILLIAMS_005c260c;
      break;
    case 0xb:
      pcVar6 = s_TOYOTA_005c25b4;
      break;
    case 0xc:
      pcVar6 = s_BENETTON_005c25cc;
      break;
    case 0xd:
      pcVar6 = s_STEWART_005c25bc;
      break;
    default:
      goto LAB_0041f6b2;
    }
    FUN_00566650(pcVar6);
LAB_0041f6b2:
    iVar1 = FUN_0041f220();
    if ((iVar4 < iVar1) && ((param_1 == 0 || (iVar2 = FUN_00566810(), iVar2 == 0)))) {
      FUN_00566650(&DAT_005ea438);
      iVar4 = iVar1;
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0xe);
  if (param_2 == '\0') {
    iVar5 = 0;
    do {
      switch(iVar5) {
      case 0:
        pcVar6 = s_ARROWS_005c25f4;
        break;
      case 1:
        pcVar6 = (char *)&PTR_DAT_005c25e0;
        break;
      case 2:
        pcVar6 = s_RENAULT_005c25c4;
        break;
      case 3:
        pcVar6 = s_FERRARI_005c2618;
        break;
      case 4:
        pcVar6 = s_JAGUAR_005c25d8;
        break;
      case 5:
        pcVar6 = s_JORDAN_005c2604;
        break;
      case 6:
        pcVar6 = s_MCLAREN_005c2620;
        break;
      case 7:
        pcVar6 = s_MINARDI_005c25e4;
        break;
      case 8:
        pcVar6 = s_PROST_005c25ec;
        break;
      case 9:
        pcVar6 = s_SAUBER_005c25fc;
        break;
      case 10:
        pcVar6 = s_WILLIAMS_005c260c;
        break;
      case 0xb:
        pcVar6 = s_TOYOTA_005c25b4;
        break;
      case 0xc:
        pcVar6 = s_BENETTON_005c25cc;
        break;
      case 0xd:
        pcVar6 = s_STEWART_005c25bc;
        break;
      default:
        goto LAB_0041f794;
      }
      FUN_00566650(pcVar6);
LAB_0041f794:
      puVar3 = (undefined1 *)*local_14;
      if (puVar3 == (undefined1 *)0x0) {
        puVar3 = &DAT_005ea438;
      }
      iVar1 = FUN_00588410(puVar3,&DAT_005ea438);
      if ((iVar1 != 0) &&
         (((param_1 == 0 || (iVar1 = FUN_00566810(), iVar1 == 0)) &&
          (iVar1 = FUN_0041f220(), iVar4 == iVar1)))) {
        return (undefined4 *)0x0;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0xe);
  }
  return local_14;
}


