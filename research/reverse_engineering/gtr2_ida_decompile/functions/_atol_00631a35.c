int __cdecl atol(const char *String)
{
  int *v1; // edi
  int v3; // eax
  int v5; // ecx
  const char *v6; // esi
  int v7; // edx
  int result; // eax
  int v9; // ecx

  v1 = *(int **)(_getptd() + 100);
  if ( v1 != off_91290C )
    v1 = (int *)__updatetlocinfo();
  while ( 1 )
  {
    v3 = *(unsigned __int8 *)String;
    if ( !(v1[10] <= 1 ? *(_BYTE *)(v1[18] + 2 * v3) & 8 : __isctype_mt(v1, v3, 8)) )
      break;
    ++String;
  }
  v5 = *(unsigned __int8 *)String;
  v6 = String + 1;
  v7 = v5;
  if ( v5 == 45 || v5 == 43 )
    v5 = *(unsigned __int8 *)v6++;
  result = 0;
  while ( 1 )
  {
    v9 = v5 < 48 || v5 > 57 ? -1 : v5 - 48;
    if ( v9 == -1 )
      break;
    result = v9 + 10 * result;
    v5 = *(unsigned __int8 *)v6++;
  }
  if ( v7 == 45 )
    return -result;
  return result;
}
