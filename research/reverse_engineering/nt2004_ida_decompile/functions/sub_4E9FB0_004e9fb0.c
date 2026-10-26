char __thiscall sub_4E9FB0(_DWORD *this)
{
  int v2; // eax
  _DWORD *v3; // esi
  CHAR *v4; // edi

  v2 = this[10];
  v3 = this + 10;
  if ( v2 )
  {
    sub_592310(v2);
    *v3 = 0;
  }
  v4 = (CHAR *)this[3];
  if ( !v4 )
    v4 = &byte_629120;
  if ( !sub_5922A0(v3, v4, 8, 1) )
    return 1;
  *v3 = 0;
  return 0;
}
