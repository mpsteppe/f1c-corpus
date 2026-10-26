exception *__thiscall sub_5D1BF9(exception *this, struct exception *a2)
{
  exception::exception(this, a2);
  *((_BYTE *)this + 12) = *((_BYTE *)a2 + 12);
  std::string::_Tidy((_DWORD *)this + 3, 0);
  std::string::assign((char *)a2 + 12, 0, -1);
  *(_DWORD *)this = &std::runtime_error::`vftable';
  return this;
}
