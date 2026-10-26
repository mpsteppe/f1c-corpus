int __thiscall sub_4A0140(_DWORD *this, int a2)
{
  int v2; // ebx
  __int64 v3; // rax
  int v4; // edx
  int v5; // edi
  int v6; // esi

  v2 = this[97];
  LODWORD(v3) = -1;
  if ( v2 > 0 )
  {
    v4 = this[1];
    if ( a2 > v4 && a2 < this[2] )
    {
      v5 = this[94];
      v3 = (__int64)((double)(a2 - this[88] - v4) / (double)(v2 + this[90]) + (double)v5);
      if ( (int)v3 < v5 )
        LODWORD(v3) = this[94];
      if ( (int)v3 > this[100] + v5 - 1 )
        LODWORD(v3) = this[100] + v5 - 1;
      v6 = this[37];
      if ( (int)v3 >= v6 )
        LODWORD(v3) = v6 - 1;
    }
  }
  return v3;
}
