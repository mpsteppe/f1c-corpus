int __usercall sub_62A360@<eax>(_DWORD *a1@<esi>)
{
  int result; // eax
  int v2; // eax
  int v3; // edx

  if ( a1[15] )
    return -1;
  if ( a1[1] )
    goto LABEL_8;
  *_errno() = 0;
  v2 = sub_6318A2(a1[17], 1, 0x4000, a1[16]);
  a1[1] = v2;
  if ( v2 )
  {
    *a1 = a1[17];
LABEL_8:
    --a1[1];
    return *(unsigned __int8 *)(*a1)++;
  }
  v3 = a1[16];
  a1[15] = 1;
  result = -1;
  if ( (*(_BYTE *)(v3 + 12) & 0x20) != 0 )
    a1[14] = -1;
  return result;
}
