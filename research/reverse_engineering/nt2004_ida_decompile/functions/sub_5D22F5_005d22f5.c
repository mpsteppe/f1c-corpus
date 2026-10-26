exception *__thiscall sub_5D22F5(exception *this, struct exception *a2)
{
  exception::exception(this, a2);
  *((_BYTE *)this + 12) = *((_BYTE *)a2 + 12);
  std::string::_Tidy((_DWORD *)this + 3, 0);
  std::string::assign((int)this + 12, (_DWORD *)a2 + 3, 0, 0xFFFFFFFF);
  *(_DWORD *)this = &std::logic_error::`vftable';
  return this;
}
