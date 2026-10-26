char __thiscall sub_50A950(char *this, char a2)
{
  int v3; // ecx
  double v4; // st7
  int v5; // edi
  double v6; // st7
  _BYTE *v7; // eax
  int v8; // ecx
  int v10; // [esp+0h] [ebp-14h]
  int v11; // [esp+4h] [ebp-10h]

  v3 = *((_DWORD *)this + 640);
  this[2884] = 0;
  if ( v3 )
    sub_5A2930(0, 0, 0);
  v4 = flt_7D3C54[(unsigned __int8)dword_7D3C50++] * 0.14;
  *((float *)this + 704) = v4 + 0.0099999998;
  sub_50AFB0(this);
  if ( a2 )
  {
    sub_50EC00(this);
  }
  else if ( *(_DWORD *)(*(_DWORD *)this + 16584) <= 1u )
  {
    v5 = dword_7D3C44;
    if ( dword_79FC40 < 1023 )
    {
      ++dword_79FC40;
      dword_7D3C44 += 208;
    }
    *(float *)&v10 = dbl_7DA9D0;
    sub_4D0D00((_DWORD *)v5, 2, 8, 4, *(_DWORD *)(*(_DWORD *)this + 25248), v10, 0);
    *(float *)(v5 + 8) = dbl_7DA9D0;
  }
  v11 = *((_DWORD *)this + 717);
  this[2876] = 1;
  this[2877] = 1;
  sub_50B4E0(v11, 1);
  this[2888] = 0;
  sub_50E010(1.0);
  *((_DWORD *)this + 698) = 0;
  *((_DWORD *)this + 699) = 0;
  *((_DWORD *)this + 700) = 0;
  *((_DWORD *)this + 701) = 0;
  *((_DWORD *)this + 702) = 0;
  *((_WORD *)this + 1406) = 0;
  this[2712] = 1;
  *((_DWORD *)this + 725) = -1;
  *((_DWORD *)this + 726) = -8388609;
  if ( flt_767B5C >= 1.0 )
    v6 = flt_767B5C;
  else
    v6 = 1.0;
  LOBYTE(v7) = this[2912];
  *((float *)this + 727) = 32.0 / v6;
  if ( (_BYTE)v7 )
  {
    this[2912] = 0;
    v7 = this + 2916;
    v8 = 17;
    do
    {
      *v7 = 0;
      v7 += 28;
      --v8;
    }
    while ( v8 );
  }
  return (char)v7;
}
