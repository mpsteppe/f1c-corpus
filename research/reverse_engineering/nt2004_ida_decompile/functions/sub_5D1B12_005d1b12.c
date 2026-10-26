exception *__thiscall sub_5D1B12(exception *this, _BYTE *a2)
{
  char *v4[4]; // [esp+10h] [ebp-10h] BYREF

  v4[0] = &byte_629120;
  exception::exception(this, (const char *const *)v4);
  v4[3] = 0;
  *((_BYTE *)this + 12) = *a2;
  std::string::_Tidy((_DWORD *)this + 3, 0);
  std::string::assign(a2, 0, -1);
  *(_DWORD *)this = &std::runtime_error::`vftable';
  return this;
}
