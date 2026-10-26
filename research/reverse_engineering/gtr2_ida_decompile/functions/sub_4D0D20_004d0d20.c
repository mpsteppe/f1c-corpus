int __thiscall sub_4D0D20(_DWORD *this, int a2)
{
  int v2; // ebx
  unsigned __int64 v3; // rax
  int v4; // edx
  int v5; // esi

  v2 = this[142];
  LODWORD(v3) = -1;
  if ( v2 > 0 )
  {
    v4 = this[1];
    if ( a2 > v4 && a2 < this[2] )
    {
      v3 = (unsigned __int64)((double)(a2 - this[133] - v4) / (double)(v2 + this[135]) + (double)(int)this[139]);
      if ( (int)v3 < this[139] )
        LODWORD(v3) = this[139];
      HIDWORD(v3) = this[139];
      if ( (int)v3 > this[145] + HIDWORD(v3) - 1 )
        LODWORD(v3) = this[145] + HIDWORD(v3) - 1;
      v5 = this[37];
      if ( (int)v3 >= v5 )
        LODWORD(v3) = v5 - 1;
    }
  }
  return v3;
}
