int __thiscall sub_490AA0(void *this)
{
  _DWORD *v2; // esi
  int result; // eax
  int v4; // ecx

  v2 = (_DWORD *)GlobalDataRead();
  result = ShortArrayZeroInit(this);
  if ( this )
  {
    result = OperatorNewNhMallocWrapper(12);
    if ( result )
    {
      *(_DWORD *)result = this;
      *(_DWORD *)(result + 4) = 0;
      *(_BYTE *)(result + 8) = 0;
    }
    else
    {
      result = 0;
    }
    v4 = v2[4];
    if ( v4 )
    {
      *(_DWORD *)(result + 4) = v4;
      v2[4] = result;
      ++v2[7];
    }
    else
    {
      v2[5] = result;
      v2[6] = result;
      v2[4] = result;
      result = v2[7] + 1;
      v2[7] = result;
    }
  }
  return result;
}
