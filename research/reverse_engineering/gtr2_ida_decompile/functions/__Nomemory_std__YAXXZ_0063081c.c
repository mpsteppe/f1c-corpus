void __cdecl __noreturn std::_Nomemory()
{
  _DWORD v0[3]; // [esp+4h] [ebp-10h] BYREF
  char *v1; // [esp+10h] [ebp-4h] BYREF

  if ( (dword_FB8174 & 1) == 0 )
  {
    dword_FB8174 |= 1u;
    v1 = "bad allocation";
    exception::exception((exception *)dword_FB8168, (const char *const *)&v1);
    dword_FB8168[0] = &std::bad_alloc::`vftable';
    atexit(sub_6EFFFA);
  }
  exception::exception((exception *)v0, (const struct exception *)dword_FB8168);
  v0[0] = &std::bad_alloc::`vftable';
  sub_63153D(v0, &_TI2_AVbad_alloc_std__);
  __debugbreak();
}
