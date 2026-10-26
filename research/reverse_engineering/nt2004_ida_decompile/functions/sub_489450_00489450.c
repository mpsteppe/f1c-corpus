int __thiscall sub_489450(_DWORD *this)
{
  const char *v2; // ebx
  const char *v3; // eax
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  int i; // edx
  int v8; // eax
  int v9; // edx
  int v10; // eax

  v2 = dword_7665D8;
  if ( !dword_7665D8 )
    v2 = &byte_629120;
  v3 = (const char *)this[220];
  if ( !v3 )
    v3 = &byte_629120;
  if ( _strcmpi(v3, v2) )
  {
    sub_578600(v2);
    sub_4895E0(this);
    v4 = sub_4893A0();
    if ( !(unsigned __int8)sub_489810(v4) )
      sub_489810(0);
  }
  v5 = this[218];
  if ( v5 )
  {
    v6 = this[216];
    for ( i = 0; v6; ++i )
    {
      if ( v6 == v5 )
        break;
      v6 = *(_DWORD *)(v6 + 4);
    }
  }
  v8 = sub_4893A0();
  if ( v8 != v9 )
  {
    v10 = sub_4893A0();
    sub_489810(v10);
  }
  if ( this[219] == 1 )
    (*(void (__thiscall **)(_DWORD *, int))(*this + 36))(this, 1);
  else
    (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 36))(this, 0);
  return 0;
}
