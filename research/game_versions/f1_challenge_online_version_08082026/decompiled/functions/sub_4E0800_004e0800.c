char __thiscall sub_4E0800(char *this, char a2)
{
  int v3; // ecx
  double v4; // st7
  int v5; // edi
  double v6; // st7
  int v7; // eax
  int v8; // ebx
  int *v9; // edi
  int *v10; // ebp
  _BYTE *v11; // eax
  int v12; // ecx
  int v14; // [esp+0h] [ebp-14h]
  int v15; // [esp+4h] [ebp-10h]

  v3 = *((_DWORD *)this + 553);
  this[2420] = 0;
  if ( v3 )
    sub_5506A0(0, 0, 0);
  v4 = flt_8AAE74[(unsigned __int8)dword_8AAE70++];
  *((float *)this + 595) = v4 * 0.14 + 0.0099999998;
  sub_4E0DB0(this);
  if ( a2 )
  {
    sub_4E3890(this);
  }
  else if ( *(_DWORD *)(*(_DWORD *)this + 13000) <= 1u )
  {
    v5 = dword_8AAE64;
    if ( dword_83EE60 < 1023 )
    {
      ++dword_83EE60;
      dword_8AAE64 += 432;
    }
    *(float *)&v14 = dbl_8AFEA0;
    sub_4B33B0((_DWORD *)v5, 2, 8, 4, *(_DWORD *)(*(_DWORD *)this + 18580), v14, 0);
    *(float *)(v5 + 8) = dbl_8AFEA0;
  }
  v15 = *((_DWORD *)this + 601);
  this[2412] = 1;
  this[2413] = 1;
  sub_4E0ED0(v15);
  this[2425] = 0;
  sub_4E2CA0(1.0);
  *((_DWORD *)this + 589) = 0;
  *((_DWORD *)this + 590) = 0;
  *((_DWORD *)this + 591) = 0;
  *((_DWORD *)this + 592) = 0;
  *((_DWORD *)this + 593) = 0;
  *((_WORD *)this + 1188) = 0;
  *((_DWORD *)this + 608) = -1;
  *((_DWORD *)this + 609) = -8388609;
  if ( flt_7CF740 >= 1.0 )
    v6 = flt_7CF740;
  else
    v6 = 1.0;
  v7 = *((_DWORD *)this + 550);
  *((float *)this + 610) = 32.0 / v6;
  if ( v7 )
  {
    v8 = 0;
    if ( *((int *)this + 557) > 0 )
    {
      v9 = (int *)(this + 2232);
      v10 = (int *)(this + 2244);
      do
      {
        sub_551810(*v9, *v10, 1.0);
        ++v8;
        ++v9;
        v10 += 4;
      }
      while ( v8 < *((_DWORD *)this + 557) );
    }
  }
  LOBYTE(v11) = this[2444];
  if ( (_BYTE)v11 )
  {
    this[2444] = 0;
    v11 = this + 2448;
    v12 = 17;
    do
    {
      *v11 = 0;
      v11 += 28;
      --v12;
    }
    while ( v12 );
  }
  return (char)v11;
}
