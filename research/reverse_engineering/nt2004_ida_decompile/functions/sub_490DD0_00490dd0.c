int __thiscall sub_490DD0(_DWORD *this)
{
  const char *v2; // esi
  const char *v3; // eax

  v2 = (const char *)this[104];
  if ( !v2 )
    v2 = &byte_629120;
  v3 = dword_76662C;
  if ( !dword_76662C )
    v3 = &byte_629120;
  if ( strcmp(v3, v2) )
    ((void (__thiscall *)(_DWORD *))loc_490B70)(this);
  return 0;
}
