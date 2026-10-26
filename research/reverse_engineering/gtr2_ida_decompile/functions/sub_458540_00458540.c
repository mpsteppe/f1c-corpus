double *__thiscall sub_458540(double *this, int a2)
{
  char v3; // fps^1
  double v4; // st7
  char v5; // ah
  bool v6; // c0
  bool v7; // c3
  int v8; // edi
  double *v10; // eax
  double *v11; // eax

  while ( 1 )
  {
    while ( *(float *)a2 == *(float *)this && *(float *)(a2 + 16) == *((float *)this + 4) )
    {
      if ( *(double *)(a2 + 8) == this[1] )
        return this;
      if ( !*((_DWORD *)this + 25) )
      {
        v10 = (double *)operator new(0x68u);
        *((_DWORD *)this + 25) = v10;
        sub_458480(v10, a2);
        return (double *)*((_DWORD *)this + 25);
      }
      this = (double *)*((_DWORD *)this + 25);
    }
    v4 = *(float *)(a2 + 16);
    v5 = v3;
    v6 = v4 < *((float *)this + 4);
    v7 = v4 == *((float *)this + 4);
    if ( __SETP__(v5 & 0x41, 0) )
      v8 = v6 || v7 ? 2 : 0;
    else
      v8 = v6 || v7 ? 3 : 1;
    if ( !*((_DWORD *)this + v8 + 21) )
      break;
    this = (double *)*((_DWORD *)this + v8 + 21);
  }
  v11 = (double *)operator new(0x68u);
  *((_DWORD *)this + v8 + 21) = v11;
  sub_458480(v11, a2);
  return (double *)*((_DWORD *)this + v8 + 21);
}
