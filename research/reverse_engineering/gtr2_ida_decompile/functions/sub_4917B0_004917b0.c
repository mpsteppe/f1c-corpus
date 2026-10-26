int __thiscall sub_4917B0(_DWORD **this)
{
  int v2; // eax
  const char *v3; // eax
  char v4; // cl
  char v6; // [esp+4h] [ebp-8h]

  v6 = 1;
  v2 = (*(int (__thiscall **)(_DWORD *, int))(*this[12] + 28))(this[12], 60);
  if ( v2 )
  {
    v3 = (const char *)sub_4CE170(v2);
    if ( v3 )
    {
      if ( strlen(v3) )
        v6 = v4;
    }
  }
  ((void (__thiscall *)(_DWORD **, char))(*this)[9])(this, v6);
  return 0;
}
