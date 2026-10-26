int __thiscall sub_556980(int this, float *a2)
{
  int result; // eax
  int v4; // ebp
  _DWORD *i; // esi

  result = sub_54B570(this, a2, 0);
  v4 = result;
  if ( (*(_BYTE *)(this + 60) & 4) == 0 )
  {
    for ( i = *(_DWORD **)(this + 516); i; i = (_DWORD *)i[4] )
    {
      result = i[5];
      if ( v4 )
        i[5] = result & 0xDFFFFFD7;
      if ( (result & 0x200000) == 0 )
      {
        if ( i[79] )
          result = sub_5569F0(a2, i);
        else
          result = sub_556B10(a2, i);
      }
    }
  }
  return result;
}
