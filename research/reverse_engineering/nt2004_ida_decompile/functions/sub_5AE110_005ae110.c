int __thiscall sub_5AE110(int this, float *a2)
{
  int result; // eax
  int v4; // ebp
  _DWORD *i; // esi

  result = sub_59E210(this, a2, 0);
  v4 = result;
  if ( (*(_BYTE *)(this + 60) & 4) == 0 )
  {
    for ( i = *(_DWORD **)(this + 516); i; i = (_DWORD *)i[4] )
    {
      if ( v4 )
        i[5] &= 0xDFFFFFD7;
      if ( (i[5] & 0x200000) == 0 )
      {
        if ( i[79] )
          result = sub_5AE180(a2, i, 0);
        else
          result = sub_5AE2B0(a2, i, v4);
      }
    }
  }
  return result;
}
