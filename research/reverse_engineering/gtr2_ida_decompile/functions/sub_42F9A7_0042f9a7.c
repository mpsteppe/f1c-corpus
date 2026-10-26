void __noreturn sub_42F9A7()
{
  _DWORD v0[14]; // [esp+18h] [ebp-38h] BYREF

  v0[2] = 15;
  v0[1] = 0;
  sub_406190();
  v0[13] = 0;
  sub_4062A0();
  v0[0] = &std::out_of_range::`vftable';
  sub_63153D(v0, &_TI3_AVout_of_range_std___0);
  JUMPOUT(0x42FA09);
}
