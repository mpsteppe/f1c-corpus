int __thiscall sub_4C71C0(int this, _DWORD *a2)
{
  int v2; // ebx
  _DWORD *v4; // esi
  int v5; // eax
  unsigned int v6; // eax
  int i; // ebx
  char v8; // al
  int v9; // eax
  unsigned int v10; // eax
  int v11; // eax
  unsigned int v12; // eax
  int v13; // eax
  unsigned int v14; // eax
  int v15; // eax
  unsigned int v16; // eax
  int v17; // eax
  unsigned int v18; // eax
  int v19; // eax
  int v21; // [esp+0h] [ebp-1Ch]
  float v22; // [esp+0h] [ebp-1Ch]
  float *v23; // [esp+18h] [ebp-4h]
  int v24; // [esp+20h] [ebp+4h]

  v2 = 0;
  *(float *)&v21 = dbl_8AFEA0;
  sub_4B33B0(a2, 1, 0, 52, *(_DWORD *)(this + 18580), v21, 0);
  v4 = a2 + 2;
  sub_4B2310(a2 + 2, (_DWORD *)(this + 1860), (float *)(this + 1796));
  sub_4B2480((_WORD *)a2 + 4, (float *)(this + 13560));
  sub_4B25D0((int)(a2 + 2), (float *)(this + 13584));
  sub_4B2750((_WORD *)a2 + 4, (float *)(this + 13632));
  v24 = 0;
  v23 = (float *)(this + 13756);
  do
  {
    v22 = *(float *)(v2 + this + 1776 + 332) + *(float *)(this + 1852);
    sub_4B2840(v4, v24, v22, *v23);
    v2 += 296;
    ++v24;
    v23 += 62;
  }
  while ( v2 < 1184 );
  sub_4B2930(v4, *(float *)(this + 14752));
  sub_4B29B0(v4, *(float *)(this + 13692));
  sub_4B2A10(v4, *(_DWORD *)(this + 14844));
  v5 = v4[11];
  if ( *(_BYTE *)(this + 4201) )
    v6 = v5 | 0x80;
  else
    v6 = v5 & 0xFFFFFF7F;
  v4[11] = v6;
  sub_4B2A40(v4, *(float *)(this + 13696));
  for ( i = 0; i < 14; ++i )
  {
    v8 = sub_4E18C0(i);
    sub_4B2AA0(v4, i, v8);
  }
  v9 = v4[12];
  if ( *(_BYTE *)(this + 4189) )
    v10 = v9 | 0x8000000;
  else
    v10 = v9 & 0xF7FFFFFF;
  v4[12] = v10;
  v11 = v4[12];
  if ( *(float *)(this + 13700) <= 0.0099999998 )
    v12 = v11 & 0xFBFFFFFF;
  else
    v12 = v11 | 0x4000000;
  v4[12] = v12;
  v13 = v4[12];
  if ( *(_BYTE *)(this + 4199) )
    v14 = v13 | 0x2000000;
  else
    v14 = v13 & 0xFDFFFFFF;
  v4[12] = v14;
  v15 = v4[12];
  if ( *(_BYTE *)(this + 13388) )
    v16 = v15 | 0x80000000;
  else
    v16 = v15 & 0x7FFFFFFF;
  v4[12] = v16;
  v17 = v4[12];
  if ( *(_BYTE *)(this + 16420) )
    v18 = v17 | 0x1000000;
  else
    v18 = v17 & 0xFEFFFFFF;
  v4[12] = v18;
  sub_4B2B10(v4, *(float *)(this + 16424));
  sub_4B2B60(v4, *(_DWORD *)(dword_7C54F0[dword_7C54DC] + 18580));
  v19 = sub_4C7C00(this);
  return sub_4B2AE0(v4, v19);
}
