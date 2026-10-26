void __thiscall sub_57DFE0(char *this)
{
  char *v2; // esi
  int v3; // edi
  int v4; // eax
  long double v5; // st7
  float *v6; // eax
  float v7; // ecx
  float v8; // edx
  float v9; // eax
  double v10; // st7
  float v11; // [esp+Ch] [ebp-40h]
  float v12; // [esp+10h] [ebp-3Ch]
  float v13; // [esp+14h] [ebp-38h]
  float v14; // [esp+18h] [ebp-34h]
  float v15; // [esp+1Ch] [ebp-30h]
  float v16; // [esp+20h] [ebp-2Ch]
  float v17; // [esp+24h] [ebp-28h]
  float v18; // [esp+24h] [ebp-28h]
  float v19; // [esp+28h] [ebp-24h] BYREF
  float v20; // [esp+2Ch] [ebp-20h]
  float v21; // [esp+30h] [ebp-1Ch]
  float v22; // [esp+34h] [ebp-18h]
  float v23; // [esp+38h] [ebp-14h]
  float v24; // [esp+3Ch] [ebp-10h]
  float v25[3]; // [esp+40h] [ebp-Ch] BYREF

  v12 = 0.0;
  v13 = 0.0;
  v14 = 0.0;
  v19 = 0.0;
  v20 = 0.0;
  v21 = 0.0;
  v15 = *(float *)&dword_B70C84;
  v17 = *(float *)&dword_B70CA8;
  v16 = *(float *)&dword_B70CCC;
  v2 = this + 16228;
  v3 = 4;
  do
  {
    v4 = *((_DWORD *)v2 + 39);
    if ( v4 && *(_DWORD *)(*(_DWORD *)(v4 + 84) + 48) == 35 && *(float *)v2 > -0.22 && *(float *)v2 < 0.81 )
    {
      if ( *(float *)v2 <= 0.47 )
        v5 = (0.47 - *(float *)v2) * 4.5530329 + 3.1415927;
      else
        v5 = (0.81 - *(float *)v2) * 9.2399788;
      v11 = (1.0 - cos(v5)) * 0.5 * *((float *)v2 - 1) * v15;
      if ( v11 > (double)v12 )
        v12 = v11;
      if ( v11 > 0.0 )
      {
        v13 = v11 + v13;
        v14 = (v16 * *((float *)v2 - 2) + v17 * *(float *)v2 + 1.05) * v11 + v14;
        v6 = sub_4012D0((float *)v2 - 17, v25, v11);
        v7 = *v6;
        v8 = v6[1];
        v9 = v6[2];
        v22 = v7;
        v23 = v8;
        v24 = v9;
        v19 = v7 + v19;
        v20 = v8 + v20;
        v21 = v9 + v21;
      }
    }
    v2 += 252;
    --v3;
  }
  while ( v3 );
  if ( v12 > 0.001 )
  {
    v10 = 1.0 / v13;
    v18 = v14 * v10;
    v22 = v19 * v10;
    v19 = v22;
    v23 = v20 * v10;
    v20 = v23;
    v24 = v10 * v21;
    v21 = v24;
    if ( v12 <= 1.0 )
      sub_58C6C0(this + 8, 34, 2, LODWORD(v12), LODWORD(v18), &v19);
    else
      sub_58C6C0(this + 8, 34, 2, 1065353216, LODWORD(v18), &v19);
  }
}
