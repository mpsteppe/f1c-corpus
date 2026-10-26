int __thiscall sub_5FCA00(int *this, int a2)
{
  int result; // eax
  int v4; // edx
  int v5; // edx

  result = this[16];
  v4 = *(_DWORD *)(result + 44);
  if ( !v4 || *(_BYTE *)(dword_FB27A4 + 4813) )
  {
    this[17] = 0;
  }
  else if ( (*this & 0x100000) == 0 )
  {
    (*(void (__stdcall **)(int, _DWORD, _DWORD, int))(*(_DWORD *)dword_FB27A4 + 412))(
      v4,
      *(_DWORD *)(result + 52),
      *(_DWORD *)(result + 8),
      a2);
    result = *(_DWORD *)(this[16] + 44);
    if ( *(char *)result >= 0 )
    {
      this[17] = 0;
    }
    else
    {
      v5 = *(_DWORD *)(result + 76);
      result = *this | 0x100000;
      this[17] = v5;
      *this = result;
    }
  }
  return result;
}
