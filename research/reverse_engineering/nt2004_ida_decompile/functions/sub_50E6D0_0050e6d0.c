int __thiscall sub_50E6D0(_DWORD *this)
{
  CHAR *v2; // eax
  int v3; // esi
  CHAR *v4; // ebx
  _DWORD *v5; // eax
  _DWORD *v6; // edx
  _DWORD *v7; // eax
  int v8; // ecx
  int *v9; // eax
  int *v10; // eax
  int v11; // ecx
  int v12; // ecx
  char *v13; // esi
  int v14; // ebx
  _DWORD *v15; // ecx
  int result; // eax
  int v17; // [esp+10h] [ebp-3D58h] BYREF
  int v18; // [esp+14h] [ebp-3D54h] BYREF
  int v19; // [esp+18h] [ebp-3D50h]
  float *v20; // [esp+1Ch] [ebp-3D4Ch]
  int v21; // [esp+20h] [ebp-3D48h]
  _DWORD *v22; // [esp+24h] [ebp-3D44h]
  int v23; // [esp+28h] [ebp-3D40h] BYREF
  int v24; // [esp+2Ch] [ebp-3D3Ch] BYREF
  int v25; // [esp+30h] [ebp-3D38h] BYREF
  int v26; // [esp+34h] [ebp-3D34h] BYREF
  int v27; // [esp+38h] [ebp-3D30h]
  _BYTE v28[28]; // [esp+3Ch] [ebp-3D2Ch] BYREF
  _BYTE v29[384]; // [esp+58h] [ebp-3D10h] BYREF
  int v30; // [esp+1D8h] [ebp-3B90h]
  char v31; // [esp+1DCh] [ebp-3B8Ch]
  int v32; // [esp+1E4h] [ebp-3B84h]
  int v33; // [esp+1E8h] [ebp-3B80h]
  int v34; // [esp+1ECh] [ebp-3B7Ch]
  char Buffer[384]; // [esp+1F0h] [ebp-3B78h] BYREF
  _DWORD v36[9]; // [esp+370h] [ebp-39F8h] BYREF
  char *Source; // [esp+394h] [ebp-39D4h]
  int v38; // [esp+39Ch] [ebp-39CCh]
  char v39[104]; // [esp+2048h] [ebp-1D20h] BYREF
  int v40; // [esp+20B0h] [ebp-1CB8h]
  int v41[236]; // [esp+39B8h] [ebp-3B0h] BYREF

  sub_430BC0(v39);
  sub_5208C0(v36);
  v2 = *(CHAR **)(1232 * *(_DWORD *)(*this + 25252) + dword_7D6A5C + 8);
  v3 = 0;
  if ( !v2 )
    v2 = &byte_629120;
  sub_521740((char)v2, (int)v39, 2);
  v4 = Source;
  if ( !Source )
    v4 = &byte_629120;
  sub_507520(&v18);
  v27 = 0;
  sub_57A080(v28);
  memset(Buffer, 0, sizeof(Buffer));
  v30 = 0;
  v34 = 0;
  v32 = 0;
  v33 = 0;
  v31 = 1;
  if ( (unsigned __int8)sub_57A2F0(v4, 0) )
  {
    while ( sub_57A490(Buffer, 384) )
    {
      if ( !sub_577B60(v29) )
      {
        if ( sub_578220(aRestrictionsph, (int)&v23, (int)&v24, (int)&v25, (int)&v17, 0, 0, 0, 0) )
          ++v27;
        if ( sub_578220(aForcefieldsphe, (int)&v23, (int)&v24, (int)&v25, (int)&v17, 0, 0, 0, 0) )
          ++v3;
      }
    }
    v5 = operator new(24 * v3 + 4);
    if ( v5 )
    {
      *v5 = v3;
      v6 = v5 + 1;
      if ( v3 - 1 >= 0 )
      {
        v7 = v5 + 6;
        v8 = v3;
        do
        {
          *(v7 - 1) = 0;
          *v7 = 0;
          v7 += 6;
          --v8;
        }
        while ( v8 );
      }
      v22 = v6;
    }
    else
    {
      v22 = 0;
    }
    v20 = (float *)operator new(20 * v27);
    sub_57A530(v28);
    *(float *)&v26 = 1.0;
    while ( sub_57A490(Buffer, 384) )
    {
      if ( !sub_577B60(v29) )
      {
        if ( sub_578220(aDefaultlimit, (int)&v18, 0, 0, 0, 0, 0, 0, 0) )
          *(float *)&v18 = *(float *)&v18 * *(float *)&v18;
        sub_578220(aRestrictionlim, (int)&v26, 0, 0, 0, 0, 0, 0, 0);
        if ( sub_578220(aRestrictionsph, (int)&v23, (int)&v24, (int)&v25, (int)&v17, 0, 0, 0, 0) )
        {
          v9 = (int *)&v20[5 * v19];
          *v9 = v23;
          v9[1] = v24;
          v9[2] = v25;
          v20[5 * v19 + 3] = *(float *)&v17 * *(float *)&v17;
          v20[5 * v19++ + 4] = *(float *)&v26 * *(float *)&v26;
        }
        if ( sub_578220(aForcefieldsphe, (int)&v23, (int)&v24, (int)&v25, (int)&v17, 0, 0, 0, 0) )
        {
          v10 = &v22[6 * v21];
          *v10 = v23;
          v10[1] = v24;
          v10[2] = v25;
          *(float *)&v22[6 * v21 + 3] = *(float *)&v17 * *(float *)&v17;
          v22[6 * v21 + 4] = 0;
          v22[6 * v21++ + 5] = 0;
        }
      }
    }
    sub_57A360(v28);
  }
  this[867] = 1;
  sub_508220(this + 868, &v18, this + 1);
  if ( this[389] && *((_BYTE *)this + 1620) && *((_BYTE *)this + 1621) )
  {
    v11 = 187 * this[867]++;
    sub_508220(&this[v11 + 868], &v18, this + 389);
  }
  if ( this[406] && *((_BYTE *)this + 1688) && *((_BYTE *)this + 1689) )
  {
    v12 = 187 * this[867]++;
    sub_508220(&this[v12 + 868], &v18, this + 406);
  }
  v13 = (char *)(this + 423);
  v14 = 12;
  do
  {
    if ( *(_DWORD *)v13 && v13[64] && v13[65] )
    {
      v15 = &this[187 * this[867]++ + 868];
      sub_508220(v15, &v18, v13);
    }
    v13 += 68;
    --v14;
  }
  while ( v14 );
  sub_57A0A0(v28);
  sub_507540(&v18);
  if ( v38 )
    sub_5BE8AE();
  if ( Source )
    sub_5BE8AE();
  if ( v36[7] )
    sub_5BE8AE();
  if ( v36[5] )
    sub_5BE8AE();
  if ( v36[3] )
    sub_5BE8AE();
  if ( v36[0] )
    sub_5BE8AE();
  sub_430670(v41);
  result = v40;
  if ( v40 )
    return sub_5BE8AE();
  return result;
}
