int __thiscall sub_4A4300(_DWORD *this)
{
  const char *v2; // esi
  const char *v3; // eax
  CHAR *v4; // eax

  v2 = dword_7656D8;
  if ( !dword_7656D8 )
    v2 = &byte_629120;
  v3 = (const char *)this[42];
  if ( !v3 )
    v3 = &byte_629120;
  if ( strcmp(v3, v2) )
  {
    v4 = (CHAR *)this[42];
    if ( !v4 )
      v4 = &byte_629120;
    sub_578600(v4);
    (*(void (__thiscall **)(_DWORD *))(*this + 164))(this);
  }
  return 0;
}
