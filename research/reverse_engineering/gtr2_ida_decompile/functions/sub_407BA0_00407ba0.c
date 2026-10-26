void __noreturn sub_407BA0()
{
  _DWORD v0[16]; // [esp+18h] [ebp-40h] BYREF

  v0[2] = 15;
  v0[1] = 0;
  sub_406190();
  v0[13] = 0;
  sub_4062A0();
  v0[0] = &std::length_error::`vftable';
  sub_63153D(v0, &_TI3_AVlength_error_std___0);
  JUMPOUT(0x407C09);
}
