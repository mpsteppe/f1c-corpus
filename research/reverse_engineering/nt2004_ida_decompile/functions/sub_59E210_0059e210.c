int __thiscall sub_59E210(int this, float *a2, int a3)
{
  int v4; // eax
  float v5; // ecx
  float v6; // edx
  char *v7; // eax
  char *v8; // ecx
  char *v9; // edx
  char *v10; // edi
  long double v11; // st7
  long double v12; // st6
  long double v13; // st5
  long double v14; // st4
  long double v15; // st3
  float v17; // [esp+4h] [ebp-48h]
  float v18; // [esp+8h] [ebp-44h]
  char v19; // [esp+Ch] [ebp-40h] BYREF
  char v20; // [esp+1Ch] [ebp-30h] BYREF
  char v21; // [esp+2Ch] [ebp-20h] BYREF
  char v22; // [esp+3Ch] [ebp-10h] BYREF
  float v23; // [esp+50h] [ebp+4h]

  if ( (*(_DWORD *)(this + 60) & 0x2100) != 0 )
    sub_59DFD0((_DWORD *)this, 64, 0, 0);
  v4 = *(_DWORD *)(this + 60);
  if ( (v4 & 0x40) != 0 )
    return 0;
  if ( a2 )
  {
    if ( (v4 & 0x2000) != 0 )
    {
      *(float *)(this + 48) = 3.1415927 - a2[13];
    }
    else if ( (v4 & 0x100) != 0 )
    {
      *(float *)(this + 48) = 3.1415927 - a2[13];
      *(float *)(this + 44) = -a2[12];
      *(float *)(this + 52) = -a2[14];
    }
  }
  if ( (v4 & 0x20) != 0 )
  {
    v5 = *(float *)(this + 100);
    v6 = *(float *)(this + 96);
    *(_DWORD *)(this + 60) = v4 & 0xFFFFFFDF;
    sub_5905D0(this + 108, v6, v5, *(float *)(this + 104));
    sub_590590((_DWORD *)(this + 108), *(_DWORD *)(this + 84), *(_DWORD *)(this + 88), *(_DWORD *)(this + 92));
  }
  if ( (*(_BYTE *)(this + 60) & 1) != 0 )
  {
    v7 = &v19;
    v8 = &v20;
    v9 = &v21;
    v10 = &v22;
  }
  else if ( *(_DWORD *)(this + 64) )
  {
    v7 = (char *)(this + 212);
    v8 = (char *)(this + 228);
    v9 = (char *)(this + 244);
    v10 = (char *)(this + 260);
  }
  else
  {
    v7 = (char *)(this + 276);
    v8 = (char *)(this + 292);
    v9 = (char *)(this + 308);
    v10 = (char *)(this + 324);
  }
  v11 = sin(*(float *)(this + 44));
  v12 = cos(*(float *)(this + 44));
  v13 = sin(*(float *)(this + 48));
  v23 = cos(*(float *)(this + 48));
  v14 = sin(*(float *)(this + 52));
  v15 = cos(*(float *)(this + 52));
  *((_DWORD *)v7 + 3) = 0;
  v18 = v15 * v23;
  v17 = v14 * v23;
  *(float *)v7 = v13 * v11 * v14 + v18;
  *((float *)v7 + 1) = v14 * v12;
  *((float *)v7 + 2) = v17 * v11 - v15 * v13;
  *((_DWORD *)v8 + 3) = 0;
  *(float *)v8 = v13 * v11 * v15 - v17;
  *((float *)v8 + 1) = v15 * v12;
  *((float *)v8 + 2) = v14 * v13 + v18 * v11;
  *((_DWORD *)v9 + 3) = 0;
  *(float *)v9 = v13 * v12;
  *((float *)v9 + 1) = -v11;
  *((float *)v9 + 2) = v23 * v12;
  *(_DWORD *)v10 = *(_DWORD *)(this + 32);
  *((_DWORD *)v10 + 1) = *(_DWORD *)(this + 36);
  *((_DWORD *)v10 + 2) = *(_DWORD *)(this + 40);
  *((_DWORD *)v10 + 3) = 1065353216;
  *(_DWORD *)(this + 60) |= 0x40u;
  sub_59E400(0);
  (*(void (__thiscall **)(int, int, int))(*(_DWORD *)dword_7E8E58 + 44))(dword_7E8E58, this + 276, this + 340);
  if ( a3 )
    *(_DWORD *)(a3 + 20) &= 0xDFFFFFD7;
  return 1;
}
