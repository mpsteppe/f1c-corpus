int __thiscall sub_48C1C0(_DWORD *this)
{
  const char *v2; // esi
  const char *v3; // eax
  CHAR *v4; // eax

  v2 = dword_766578;
  if ( !dword_766578 )
    v2 = &byte_629120;
  v3 = (const char *)this[90];
  if ( !v3 )
    v3 = &byte_629120;
  if ( strcmp(v3, v2) )
  {
    v4 = dword_766578;
    if ( !dword_766578 )
      v4 = &byte_629120;
    sub_578600(v4);
    (*(void (__thiscall **)(_DWORD *))(*this + 152))(this);
  }
  return 0;
}
