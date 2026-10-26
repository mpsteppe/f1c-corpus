int __stdcall sub_645FAC(_DWORD *a1, int a2, _DWORD *a3, _DWORD *a4)
{
  _DWORD *v4; // ebx
  unsigned int v6; // eax
  unsigned int *i; // ecx
  unsigned int v8; // eax
  int v9; // esi
  unsigned int v10; // eax

  if ( a3 )
    *a3 = 0;
  v4 = a4;
  if ( a4 )
    *a4 = 0;
  if ( !a1 )
    return -2005530516;
  v6 = *a1 & 0xFFFF0000;
  if ( v6 != 1180172288 && v6 != 1415053312 && v6 != 2147352576 && v6 != 2147418112 && v6 != -131072 && v6 != -65536 )
    return -2005529767;
  for ( i = a1 + 1; ; ++i )
  {
    v8 = *i;
    if ( (*i & 0x80000000) != 0 )
      goto LABEL_31;
    v9 = (unsigned __int16)*i;
    if ( v9 == 0xFFFF )
      return 1;
    if ( v9 == 65534 )
      break;
    if ( (unsigned __int16)*a1 >= 0x200u )
    {
      v10 = HIBYTE(v8) & 0xF;
LABEL_28:
      i += v10;
      goto LABEL_31;
    }
    if ( v9 == 81 )
      i += 5;
LABEL_31:
    v4 = a4;
  }
  v10 = HIWORD(v8) & 0x7FFF;
  if ( v10 <= 1 || a2 != i[1] )
    goto LABEL_28;
  if ( a3 )
    *a3 = i + 2;
  if ( v4 )
    *v4 = 4 * v10 - 4;
  return 0;
}
