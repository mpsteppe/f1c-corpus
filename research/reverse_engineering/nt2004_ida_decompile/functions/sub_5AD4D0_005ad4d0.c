double **__thiscall sub_5AD4D0(double **this, double *a2)
{
  _DWORD *v3; // eax
  double *v4; // eax
  double *v5; // ebx
  double **v6; // eax
  double *v7; // ebp
  _DWORD *v8; // edi

  sub_5918B0(this);
  v3 = operator new(0x4Cu);
  if ( v3 )
    v4 = (double *)sub_5AC560(v3);
  else
    v4 = 0;
  *this = v4;
  sub_5AC5A0(v4, 1);
  v5 = a2;
  v6 = (double **)operator new(136 * (_DWORD)a2 + 4);
  if ( v6 )
  {
    v7 = (double *)(v6 + 1);
    *v6 = a2;
    v8 = v6 + 1;
    if ( (int)a2 - 1 >= 0 )
    {
      do
      {
        sub_5ACAF0(v8);
        v8 += 34;
        a2 = (double *)((char *)a2 - 1);
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
  this[6] = v7;
  this[5] = v5;
  this[1] = (double *)0x20000;
  return this;
}
