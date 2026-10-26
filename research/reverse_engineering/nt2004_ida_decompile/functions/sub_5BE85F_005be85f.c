int sub_5BE85F()
{
  int result; // eax

  _cfltcvt_init_46();
  dword_7FF0F0 = _ms_p5_mp_test_fdiv();
  result = _setdefaultprecision();
  __asm { fnclex }
  return result;
}
