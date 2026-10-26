void __thiscall sub_4BEF30(_DWORD *this, int a2, int a3)
{
  const char *v4; // eax
  CHAR *v5; // eax
  _DWORD **v6; // eax
  _DWORD *v7; // ecx
  int v8; // ecx
  double v9; // st7
  int v10; // ecx
  double v11; // st7
  unsigned __int8 v13; // c0
  unsigned __int8 v14; // c3
  int v15; // eax
  _DWORD **v16; // eax

  this[1] = a3;
  v4 = (const char *)this[2 * a2 + 17];
  if ( !v4 )
    v4 = &byte_629120;
  if ( strcmp(v4, &byte_629120) )
  {
    v5 = (CHAR *)this[2 * a2 + 17];
    if ( !v5 )
      v5 = &byte_629120;
    sub_4F0320(v5, dword_76782C);
  }
  v6 = (_DWORD **)this[46];
  this[48] = v6;
  if ( v6 )
  {
    v7 = *v6;
    if ( *v6 )
    {
      do
      {
        if ( sub_4BD140(v7, a2) )
        {
          v9 = *(float *)(32 * a2 + v8 + 124);
          v10 = 32 * a2 + v8 + 108;
          v11 = v9 - *(float *)(v10 + 12);
          *(_DWORD *)v10 = 0;
          *(float *)(v10 + 4) = v11;
          if ( v13 | v14 )
            *(_DWORD *)(v10 + 8) = 0;
          else
            *(float *)(v10 + 8) = 1.0 / v11;
        }
        v15 = this[48];
        if ( !v15 )
          break;
        v16 = *(_DWORD ***)(v15 + 4);
        this[48] = v16;
        if ( !v16 )
          break;
        v7 = *v16;
      }
      while ( *v16 );
    }
  }
  *this |= 2u;
  this[50] = a2;
  sub_4BECA0(this, 1);
}
