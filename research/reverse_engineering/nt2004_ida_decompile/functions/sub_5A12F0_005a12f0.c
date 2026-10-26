int __thiscall sub_5A12F0(_DWORD *this, int a2)
{
  int result; // eax
  int v3; // ecx

  result = this[129];
  v3 = *(_DWORD *)(result + 20);
  if ( a2 )
    *(_DWORD *)(result + 20) = v3 | 0x40;
  else
    *(_DWORD *)(result + 20) = v3 & 0xFFFFFFBF;
  return result;
}
