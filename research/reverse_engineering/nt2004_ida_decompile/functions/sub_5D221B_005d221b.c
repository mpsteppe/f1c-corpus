exception *__thiscall sub_5D221B(exception *this, _DWORD *a2)
{
  char *v4[4]; // [esp+10h] [ebp-10h] BYREF

  v4[0] = &byte_629120;
  exception::exception(this, (const char *const *)v4);
  v4[3] = 0;
  *((_BYTE *)this + 12) = *(_BYTE *)a2;
  std::string::_Tidy((_DWORD *)this + 3, 0);
  std::string::assign((int)this + 12, a2, 0, 0xFFFFFFFF);
  *(_DWORD *)this = &std::logic_error::`vftable';
  return this;
}
