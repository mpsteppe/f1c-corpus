// f1c  0x00560eb0  size=91
int __thiscall sub_560EB0(_DWORD *this, _DWORD *a2)
{
  int v2; // eax
  int v3; // edx
  int v4; // eax
  int v5; // eax
  int i; // eax
  int result; // eax

  v2 = a2[12];
  v3 = 0;
  if ( v2 )
    *(_DWORD *)(v2 + 52) = a2[13];
  v4 = a2[13];
  if ( v4 )
    *(_DWORD *)(v4 + 48) = a2[12];
  v5 = this[11];
  if ( v5 )
  {
    v3 = this[11];
    for ( i = *(_DWORD *)(v5 + 52); i; i = *(_DWORD *)(i + 52) )
      v3 = i;
    *(_DWORD *)(v3 + 52) = a2;
  }
  else
  {
    this[11] = a2;
  }
  result = a2[9] | 4;
  a2[12] = v3;
  a2[13] = 0;
  a2[9] = result;
  return result;
}
