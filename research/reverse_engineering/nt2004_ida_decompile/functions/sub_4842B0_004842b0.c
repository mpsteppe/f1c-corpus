int __thiscall sub_4842B0(int *this)
{
  const char *v2; // esi
  const char *v3; // eax
  CHAR *v4; // eax

  v2 = dword_766578;
  if ( !dword_766578 )
    v2 = &byte_629120;
  v3 = (const char *)this[220];
  if ( !v3 )
    v3 = &byte_629120;
  if ( strcmp(v3, v2) )
  {
    v4 = dword_766578;
    if ( !dword_766578 )
      v4 = &byte_629120;
    sub_578600(v4);
    sub_484360(this);
    sub_484680(this);
  }
  if ( this[219] > 1 )
    (*(void (__thiscall **)(int *, _DWORD))(*this + 36))(this, 0);
  else
    (*(void (__thiscall **)(int *, int))(*this + 36))(this, 1);
  return 0;
}
