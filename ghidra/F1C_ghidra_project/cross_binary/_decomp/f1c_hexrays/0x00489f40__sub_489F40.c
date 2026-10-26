// f1c  0x00489f40  size=136
int __thiscall sub_489F40(_DWORD *this, int a2, char a3)
{
  int result; // eax
  int v5; // edx
  int v6; // edi
  int v7; // esi
  int v8; // [esp+8h] [ebp-8h]

  result = -1;
  v8 = this[86];
  if ( v8 > 0 )
  {
    v5 = this[1];
    if ( a2 > v5 && a2 < this[2] )
    {
      v6 = this[83];
      result = sub_587BDC((double)(a2 - this[79] - this[77] - v5) / (double)v8 + (double)v6);
      if ( result < v6 )
        result = v6;
      if ( a3 )
      {
        if ( result > this[89] + v6 - 1 )
          result = this[89] + v6 - 1;
        v7 = this[37];
        if ( result >= v7 )
          return v7 - 1;
      }
    }
  }
  return result;
}
