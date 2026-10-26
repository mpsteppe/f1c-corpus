void __thiscall sub_508B80(int this, float a2, float *a3, float *a4)
{
  float v4; // edx
  int v5; // eax
  double v6; // st7
  double v7; // st6
  double v8; // st5
  int v9; // edx
  long double v10; // st7
  float v11[2]; // [esp+0h] [ebp-24h] BYREF
  float v12; // [esp+8h] [ebp-1Ch]
  float v13; // [esp+Ch] [ebp-18h]
  float v14; // [esp+10h] [ebp-14h]
  float v15; // [esp+14h] [ebp-10h]
  int v16; // [esp+18h] [ebp-Ch]
  int v17; // [esp+1Ch] [ebp-8h]
  float v18; // [esp+20h] [ebp-4h]

  v11[1] = a2;
  v12 = *a3;
  v4 = a3[2];
  v13 = a3[1];
  v5 = *(_DWORD *)(this + 4);
  v14 = v4;
  LOBYTE(v4) = *(_BYTE *)(v5 + 66);
  v11[0] = 0.0;
  if ( LOBYTE(v4) )
  {
    v12 = v12 - *(float *)(v5 + 4);
    v13 = v13 - *(float *)(v5 + 8);
    v14 = v14 - *(float *)(v5 + 12);
  }
  v6 = a4[2];
  v7 = a4[1];
  v8 = *a4;
  v15 = *a4;
  v9 = *((_DWORD *)a4 + 2);
  v16 = *((_DWORD *)a4 + 1);
  v17 = v9;
  v10 = sqrt(v8 * v8 + v7 * v7 + v6 * v6);
  v18 = v10;
  if ( v10 > 0.0 )
    sub_5089C0((float *)this, v11);
}
