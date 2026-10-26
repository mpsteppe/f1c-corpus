// Function: FUN_0052da30 @ 0052da30
// Strings:  [D:\Dev\AudioDev\Shared\Engine\Dev\LbMpeg.cpp, CMpegBase::ProcessHeader() : bad bit rate, returning fail]


undefined4 __thiscall FUN_0052da30(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  byte bVar6;
  uint uVar7;
  
  if ((param_2 & 0xfff00000) != 0xfff00000) {
    return 0xffffffff;
  }
  bVar3 = 4 - ((byte)(param_2 >> 0x11) & 3);
  uVar7 = param_2 >> 9;
  *(byte *)(param_1 + 0x24c5) = (byte)uVar7 & 1;
  *(byte *)(param_1 + 0x2490) = bVar3;
  bVar6 = (byte)(param_2 >> 6) & 3;
  *(byte *)(param_1 + 0x24c6) = bVar6;
  *(byte *)(param_1 + 0x24c7) = (byte)(param_2 >> 4) & 3;
  *(byte *)(param_1 + 0x24c2) = (byte)(param_2 >> 0x10) & 1;
  *(byte *)(param_1 + 0x24c8) = (byte)(param_2 >> 3) & 1;
  uVar5 = param_2 >> 0xc;
  bVar4 = (byte)uVar5 & 0xf;
  *(byte *)(param_1 + 0x24c1) = (byte)(param_2 >> 0x13) & 1;
  *(byte *)(param_1 + 0x24c3) = bVar4;
  *(byte *)(param_1 + 0x24c9) = (byte)(param_2 >> 2) & 1;
  if ((param_2 & 0x100000) == 0) {
    *(undefined1 *)(param_1 + 0x24be) = 1;
    *(undefined1 *)(param_1 + 0x24bd) = 1;
  }
  else {
    *(bool *)(param_1 + 0x24be) = (param_2 >> 0x13 & 1) == 0;
    *(undefined1 *)(param_1 + 0x24bd) = 0;
  }
  if (*(char *)(param_1 + 0x24bd) == '\0') {
    param_2._0_1_ = (byte)(param_2 >> 10) & 3;
    *(byte *)(param_1 + 0x24c4) = *(char *)(param_1 + 0x24be) * '\x03' + (byte)param_2;
    *(byte *)(param_1 + 0x24bf) = ((*(char *)(param_1 + 0x24be) != '\0') - 1U & 3) + (byte)param_2;
  }
  else {
    *(byte *)(param_1 + 0x24c4) = ((byte)(param_2 >> 10) & 3) + 6;
  }
  iVar2 = (bVar6 != 3) + 1;
  *(int *)(param_1 + 0x24cc) = iVar2;
  uVar1 = *(undefined4 *)(&DAT_005b4764 + (uint)*(byte *)(param_1 + 0x24c4) * 4);
  *(int *)(param_1 + 0x24d0) = iVar2 * 0x20;
  *(undefined4 *)(param_1 + 0x2488) = uVar1;
  *(undefined4 *)(param_1 + 0x2484) = uVar1;
  if ((uVar5 & 0xf) == 0) {
    (*(code *)PTR_FUN_005da714)(s_AUDIO_ASSERT_________005da5e0);
    (*(code *)PTR_FUN_005da714)
              (s__s__d_____s_005da564,s_D__Dev_AudioDev_Shared_Engine_De_005da574,0x51e,
               s_CMpegBase__ProcessHeader_____bad_005da5a4);
    (*(code *)PTR_FUN_005da718)();
    return 0xffffffff;
  }
  iVar2 = (int)*(short *)(&DAT_005b4684 +
                         (((uint)*(byte *)(param_1 + 0x24be) * 3 + (uint)bVar3) * 0x10 + (uint)bVar4
                         ) * 2);
  *(int *)(param_1 + 0x2494) = iVar2;
  if (bVar3 == 1) {
    *(uint *)(param_1 + 0x2498) =
         ((iVar2 * 12000) / *(int *)(param_1 + 0x2484) + (uVar7 & 1)) * 4 + -4;
    return 0;
  }
  iVar2 = (iVar2 * 0x23280) / *(int *)(param_1 + 0x2484);
  *(int *)(param_1 + 0x2498) = iVar2;
  if ((uVar7 & 1) != 0) {
    *(int *)(param_1 + 0x2498) = iVar2 + 1;
  }
  *(int *)(param_1 + 0x2498) = *(int *)(param_1 + 0x2498) + -4;
  return 0;
}


