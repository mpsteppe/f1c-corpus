char *__thiscall sub_44AA10(char *this, int a2)
{
  char v3; // fps^1
  double v4; // st7
  char v5; // ah
  bool v6; // c0
  bool v7; // c3
  int v8; // edi
  _DWORD *v10; // eax
  _DWORD *v11; // eax

  while ( 1 )
  {
    while ( *(float *)a2 == *(float *)this && *(float *)(a2 + 12) == *((float *)this + 3) )
    {
      if ( *(double *)(a2 + 4) == *(double *)(this + 4) )
        return this;
      if ( !*((_DWORD *)this + 23) )
      {
        v10 = operator new(0x60u);
        *((_DWORD *)this + 23) = v10;
        sub_44A950(v10, (_DWORD *)a2);
        return (char *)*((_DWORD *)this + 23);
      }
      this = (char *)*((_DWORD *)this + 23);
    }
    v4 = *(float *)(a2 + 12);
    v5 = v3;
    v6 = v4 < *((float *)this + 3);
    v7 = v4 == *((float *)this + 3);
    if ( __SETP__(v5 & 0x41, 0) )
      v8 = v6 || v7 ? 2 : 0;
    else
      v8 = v6 || v7 ? 3 : 1;
    if ( !*(_DWORD *)&this[4 * v8 + 76] )
      break;
    this = *(char **)&this[4 * v8 + 76];
  }
  v11 = operator new(0x60u);
  *(_DWORD *)&this[4 * v8 + 76] = v11;
  sub_44A950(v11, (_DWORD *)a2);
  return *(char **)&this[4 * v8 + 76];
}
