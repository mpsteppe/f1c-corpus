// Function: FUN_0052e090 @ 0052e090
// Strings:  [D:\Dev\AudioDev\Shared\Engine\Dev\LbMpeg.cpp, CMpegBase::Open GetHeader() failed]


undefined4 __thiscall FUN_0052e090(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x24ec) != '\0') {
    FUN_0052e320();
  }
  *(undefined1 *)(param_1 + 0x24ec) = 1;
  *(undefined4 *)(param_1 + 0x24a4) = 0;
  *(undefined4 *)(param_1 + 0x24f0) = param_2;
  iVar1 = FUN_0052de40(param_2);
  if (iVar1 != 0) {
    (*(code *)PTR_FUN_005da714)(s_AUDIO_ASSERT_________005da5e0);
    (*(code *)PTR_FUN_005da714)
              (s__s__d_____s_005da564,s_D__Dev_AudioDev_Shared_Engine_De_005da574,0x6a2,
               s_CMpegBase__Open_GetHeader___fail_005da674);
    (*(code *)PTR_FUN_005da718)();
    return 0xffffffff;
  }
  FUN_0052da10();
  FUN_0052de60();
  FUN_0052e2f0();
  iVar1 = FUN_0052e080(*(int *)(param_1 + 0x24d4) + param_3,*(int *)(param_1 + 0x24e0),
                       (*(int *)(param_1 + 0x24d8) * *(int *)(param_1 + 0x24e0) +
                       *(int *)(param_1 + 0x24dc)) * *(int *)(param_1 + 0x24d4));
  *(int *)(param_1 + 0x24a0) = iVar1;
  *(int *)(param_1 + 0x24b0) = *(int *)(param_1 + 0x248c) * iVar1;
  return 0;
}


