int __thiscall sub_489AF0(_DWORD *this)
{
  char *v2; // eax

  v2 = (char *)sub_4ED620(this[218]);
  if ( v2 )
    sub_4A1AC0(v2);
  else
    (*(void (__thiscall **)(_DWORD *, int))(*this + 36))(this, 1);
  return 0;
}
