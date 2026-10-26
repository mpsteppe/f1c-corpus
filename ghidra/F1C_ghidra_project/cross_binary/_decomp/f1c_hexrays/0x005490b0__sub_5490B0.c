// f1c  0x005490b0  size=84
int __thiscall sub_5490B0(_DWORD *this, _DWORD *a2)
{
  int v2; // edx
  int result; // eax
  int i; // ecx

  v2 = this[59];
  result = 0;
  if ( v2 )
  {
    result = this[59];
    for ( i = *(_DWORD *)(v2 + 76); i; i = *(_DWORD *)(i + 76) )
      result = i;
    *(_DWORD *)(result + 76) = a2;
    a2[18] = result;
    a2[19] = 0;
    a2[17] = 0;
  }
  else
  {
    this[59] = a2;
    a2[18] = 0;
    a2[19] = 0;
    a2[17] = 0;
  }
  return result;
}
