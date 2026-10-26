// Function: FUN_0041f8a0 @ 0041f8a0
// Strings:  [TOYOTA, TOYOTA, STEWART, STEWART, RENAULT, RENAULT, BENETTON, BENETTON]


/* WARNING: Removing unreachable block (ram,0x0041fa6f) */
/* WARNING: Removing unreachable block (ram,0x0041fa8a) */

undefined4 FUN_0041f8a0(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  char *pcVar7;
  int local_44;
  int local_38 [14];
  
  iVar5 = 0;
  local_44 = -1;
  FUN_004c2850();
  iVar2 = FUN_004c11d0();
  piVar6 = local_38;
  for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar6 = 0;
    piVar6 = piVar6 + 1;
  }
  do {
    switch(iVar5) {
    case 0:
      pcVar7 = s_ARROWS_005c25f4;
      break;
    case 1:
      pcVar7 = (char *)&PTR_DAT_005c25e0;
      break;
    case 2:
      pcVar7 = s_RENAULT_005c25c4;
      break;
    case 3:
      pcVar7 = s_FERRARI_005c2618;
      break;
    case 4:
      pcVar7 = s_JAGUAR_005c25d8;
      break;
    case 5:
      pcVar7 = s_JORDAN_005c2604;
      break;
    case 6:
      pcVar7 = s_MCLAREN_005c2620;
      break;
    case 7:
      pcVar7 = s_MINARDI_005c25e4;
      break;
    case 8:
      pcVar7 = s_PROST_005c25ec;
      break;
    case 9:
      pcVar7 = s_SAUBER_005c25fc;
      break;
    case 10:
      pcVar7 = s_WILLIAMS_005c260c;
      break;
    case 0xb:
      pcVar7 = s_TOYOTA_005c25b4;
      break;
    case 0xc:
      pcVar7 = s_BENETTON_005c25cc;
      break;
    case 0xd:
      pcVar7 = s_STEWART_005c25bc;
      break;
    default:
      goto LAB_0041f962;
    }
    FUN_00566650(pcVar7);
LAB_0041f962:
    iVar4 = FUN_00566810();
    if (iVar4 != 0) {
      local_44 = iVar5;
    }
    iVar5 = iVar5 + 1;
    if (0xd < iVar5) {
      if (local_44 != -1) {
        iVar4 = 0;
        if (0 < iVar2 + -2) {
          do {
            bVar1 = true;
            iVar5 = 0;
            do {
              switch(iVar5) {
              case 0:
                pcVar7 = s_ARROWS_005c25f4;
                break;
              case 1:
                pcVar7 = (char *)&PTR_DAT_005c25e0;
                break;
              case 2:
                pcVar7 = s_RENAULT_005c25c4;
                break;
              case 3:
                pcVar7 = s_FERRARI_005c2618;
                break;
              case 4:
                pcVar7 = s_JAGUAR_005c25d8;
                break;
              case 5:
                pcVar7 = s_JORDAN_005c2604;
                break;
              case 6:
                pcVar7 = s_MCLAREN_005c2620;
                break;
              case 7:
                pcVar7 = s_MINARDI_005c25e4;
                break;
              case 8:
                pcVar7 = s_PROST_005c25ec;
                break;
              case 9:
                pcVar7 = s_SAUBER_005c25fc;
                break;
              case 10:
                pcVar7 = s_WILLIAMS_005c260c;
                break;
              case 0xb:
                pcVar7 = s_TOYOTA_005c25b4;
                break;
              case 0xc:
                pcVar7 = s_BENETTON_005c25cc;
                break;
              case 0xd:
                pcVar7 = s_STEWART_005c25bc;
                break;
              default:
                goto LAB_0041fa29;
              }
              FUN_00566650(pcVar7);
LAB_0041fa29:
              iVar3 = FUN_0041f220();
              local_38[iVar5] = iVar3;
              iVar5 = iVar5 + 1;
            } while (iVar5 < 0xe);
            iVar5 = 0;
            do {
              if ((iVar5 != local_44) && (local_38[local_44] < local_38[iVar5])) {
                bVar1 = false;
              }
              iVar5 = iVar5 + 1;
            } while (iVar5 < 0xe);
            if (bVar1) {
              return 1;
            }
            iVar4 = iVar4 + 1;
          } while (iVar4 < iVar2 + -2);
        }
      }
      return 0;
    }
  } while( true );
}


