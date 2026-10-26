// Function: FUN_0047eb70
// Address:  0047eb70
// Trigger:  "Changing weather"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0047eb70(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 auStack_50 [4];
  undefined4 uStack_40;
  undefined1 *puStack_3c;
  char *pcStack_38;
  undefined8 local_34;
  char local_20 [32];
  
  switch(*(undefined4 *)(param_1 + 0xf4)) {
  case 0x1e4:
    local_34 = 2.32871666346699e-317;
    cVar1 = FUN_004b15d0();
    if (cVar1 != '\0') {
      local_34 = 2.32872506258296e-317;
      uVar2 = FUN_00487010();
      local_34 = (double)CONCAT44(uVar2,0x47ebb8);
      FUN_0047e940();
      return 0;
    }
    break;
  case 0x1e5:
    local_34 = 2.12432453035576e-314;
    cVar1 = FUN_004b15d0();
    if (cVar1 != '\0') {
      local_34 = 2.32874778960267e-317;
      uVar2 = FUN_00487010();
      local_34 = (double)CONCAT44(uVar2,0x47ebe6);
      FUN_0047e940();
      return 0;
    }
    break;
  case 0x1e6:
    local_34 = 4.24632034404805e-314;
    cVar1 = FUN_004b15d0();
    if (cVar1 != '\0') {
      local_34 = 2.32877051662238e-317;
      uVar2 = FUN_00487010();
      local_34 = (double)CONCAT44(uVar2,0x47ec14);
      FUN_0047e940();
      return 0;
    }
    break;
  case 0x1e7:
    local_34 = 6.36831615774034e-314;
    cVar1 = FUN_004b15d0();
    if (cVar1 != '\0') {
      local_34 = 2.32879324364209e-317;
      uVar2 = FUN_00487010();
      local_34 = (double)CONCAT44(uVar2,0x47ec42);
      FUN_0047e940();
      return 0;
    }
    break;
  case 0x1e8:
    local_34 = 8.49031197143264e-314;
    cVar1 = FUN_004b15d0();
    if (cVar1 != '\0') {
      local_34 = 2.3288159706618e-317;
      uVar2 = FUN_00487010();
      local_34 = (double)CONCAT44(uVar2,0x47ec70);
      FUN_0047e940();
      return 0;
    }
    break;
  case 0x1e9:
    local_34 = 1.06123077851249e-313;
    cVar1 = FUN_004b15d0();
    if (cVar1 != '\0') {
      local_34 = 2.32883869768151e-317;
      uVar2 = FUN_00487010();
      local_34 = (double)CONCAT44(uVar2,0x47ec9e);
      FUN_0047e940();
      return 0;
    }
    break;
  case 0x1ea:
    local_34 = 1.27343035988172e-313;
    cVar1 = FUN_004b15d0();
    if (cVar1 != '\0') {
      local_34 = 2.32886142470122e-317;
      uVar2 = FUN_00487010();
      local_34 = (double)CONCAT44(uVar2,0x47eccc);
      FUN_0047e940();
      return 0;
    }
    break;
  case 0x1eb:
    local_34 = 1.48562994125095e-313;
    cVar1 = FUN_004b15d0();
    if (cVar1 != '\0') {
      local_34 = 2.32888415172093e-317;
      uVar2 = FUN_00487010();
      local_34 = (double)CONCAT44(uVar2,0x47ecfa);
      FUN_0047e940();
      return 0;
    }
    break;
  case 0x1ec:
    local_34 = 1.69782952262018e-313;
    cVar1 = FUN_004b15d0();
    if (cVar1 != '\0') {
      local_34 = 2.32890687874063e-317;
      uVar2 = FUN_00487010();
      local_34 = (double)CONCAT44(uVar2,0x47ed28);
      FUN_0047e940();
      return 0;
    }
    break;
  case 0x1ed:
    local_34 = 1.91002910398941e-313;
    cVar1 = FUN_004b15d0();
    if (cVar1 != '\0') {
      local_34 = 2.32892762949776e-317;
      uVar2 = FUN_00487010();
      local_34 = (double)CONCAT44(uVar2,0x47ed52);
      FUN_0047e940();
      return 0;
    }
    break;
  case 0x1ee:
    local_34 = 2.12222868516101e-313;
    cVar1 = FUN_004b15d0();
    if (cVar1 != '\0') {
LAB_0047ed6d:
      local_34 = 2.32894838025488e-317;
      uVar2 = FUN_00487010();
      local_34 = (double)CONCAT44(uVar2,0x47ed7c);
      FUN_0047e940();
      return 0;
    }
    break;
  case 0x1ef:
  case 0x1f0:
    local_34 = 6.330541558929873e-307;
    FUN_0047e940();
    return 0;
  case 0x1f1:
    pcStack_38 = local_20;
    local_34 = (double)CONCAT44(DAT_007d0014,&DAT_005c37cc);
    puStack_3c = (char *)0x47edaf;
    FUN_0058815f();
    goto LAB_0047ef60;
  case 0x1f2:
    if (DAT_007cf038 == 0) goto LAB_0047ed6d;
    break;
  case 499:
    iVar3 = DAT_007d0c18;
    goto LAB_0047ede6;
  case 500:
    iVar3 = DAT_007d0d14;
LAB_0047ede6:
    if ((-1 < iVar3) && (iVar3 < 2)) {
      local_34 = (double)CONCAT44(iVar3,0x47edf7);
      uVar2 = FUN_00487010();
      local_34 = (double)CONCAT44(uVar2,0x47edff);
      FUN_0047e940();
      return 0;
    }
    local_34 = (double)CONCAT44(iVar3,&PTR_DAT_005c74fc);
LAB_0047ee3a:
    pcStack_38 = local_20;
    puStack_3c = (undefined1 *)0x47ee44;
    FUN_0058815f();
    local_34 = (double)CONCAT44(local_20,0x47ee53);
    FUN_0047e940();
    return 0;
  case 0x1f5:
    local_34 = (double)CONCAT44(DAT_007ceb10,0x47ee1d);
    uVar2 = FUN_00487010();
    local_34 = (double)CONCAT44(uVar2,0x47ee25);
    FUN_0047e940();
    return 0;
  case 0x1f6:
    local_34 = (double)CONCAT44(DAT_007d0ebc,&DAT_005c3280);
    goto LAB_0047ee3a;
  case 0x1f7:
    puVar4 = &DAT_007d0a30;
    puVar5 = auStack_50;
    for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    FUN_0058815f(local_20,&DAT_005c3280);
    local_34 = (double)CONCAT44(local_20,0x47ee8b);
    FUN_0047e940();
    return 0;
  case 0x1f8:
    switch(DAT_007cf134) {
    case 0:
      local_34 = 6.331818151597949e-307;
      FUN_0047e940();
      return 0;
    case 1:
      local_34 = 6.326114226911851e-307;
      FUN_0047e940();
      return 0;
    case 2:
      local_34 = 6.326331519280862e-307;
      FUN_0047e940();
      return 0;
    case 3:
      local_34 = 6.326290776961692e-307;
      FUN_0047e940();
      return 0;
    case 4:
      local_34 = 6.326263615415585e-307;
      FUN_0047e940();
      return 0;
    case 5:
      local_34 = 6.326236453869477e-307;
      FUN_0047e940();
      return 0;
    default:
      local_34 = 6.3106457263941134e-307;
      FUN_0047e940();
      return 0;
    }
  case 0x1f9:
    puStack_3c = local_20;
    local_34 = (double)(DAT_007d084c * _DAT_0059e6f8);
    pcStack_38 = s__0_0f___005c74e0;
    uStack_40 = 0x47ef5d;
    FUN_0058815f();
LAB_0047ef60:
    local_34 = (double)CONCAT44(local_20,0x47ef6c);
    FUN_0047e940();
switchD_0047eb8c_default:
    return 0;
  default:
    goto switchD_0047eb8c_default;
  }
  local_34 = 2.12432478134111e-314;
  uVar2 = FUN_00487010();
  local_34 = (double)CONCAT44(uVar2,0x47edd1);
  FUN_0047e940();
  return 0;
}


