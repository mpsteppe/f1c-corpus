int *__thiscall sub_5510F0(int *this, int a2)
{
  int v3; // eax
  int v4; // eax
  int v5; // ebx
  int *v6; // eax
  _DWORD *v7; // ebp
  _DWORD *v8; // edi

  GlobalZeroInit_c2a0(this);
  v3 = OperatorNewNhMallocWrapper(76);
  if ( v3 )
    v4 = sub_556220(v3);
  else
    v4 = 0;
  *this = v4;
  sub_556260(1);
  v5 = a2;
  v6 = (int *)OperatorNewNhMallocWrapper(136 * a2 + 4);
  if ( v6 )
  {
    v7 = v6 + 1;
    *v6 = a2;
    v8 = v6 + 1;
    if ( a2 - 1 >= 0 )
    {
      do
      {
        StructInitWithScaleDefaults(v8);
        v8 += 34;
        --a2;
      }
      while ( a2 );
    }
  }
  else
  {
    v7 = 0;
  }
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  this[7] = 0;
  this[8] = 0;
  this[9] = 0;
  this[6] = (int)v7;
  this[5] = v5;
  this[1] = 0x20000;
  return this;
}

