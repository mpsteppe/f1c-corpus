int __fastcall sub_4A4ED0(int a1, int a2, int a3, int a4, int a5, float a6)
{
  int v6; // ebp
  int v7; // ebx
  int result; // eax
  char v9; // bl
  int v10; // esi
  float v11; // [esp+10h] [ebp-3E4h] BYREF
  float v12[2]; // [esp+14h] [ebp-3E0h] BYREF
  CHAR v13[61]; // [esp+1Ch] [ebp-3D8h] BYREF
  __int16 v14; // [esp+59h] [ebp-39Bh]
  char v15; // [esp+5Bh] [ebp-399h]
  char v16[64]; // [esp+5Ch] [ebp-398h] BYREF
  CHAR v17[64]; // [esp+9Ch] [ebp-358h] BYREF
  _BYTE v18[384]; // [esp+DCh] [ebp-318h] BYREF
  int v19; // [esp+25Ch] [ebp-198h]
  char v20; // [esp+260h] [ebp-194h]
  int v21; // [esp+268h] [ebp-18Ch]
  int v22; // [esp+26Ch] [ebp-188h]
  int v23; // [esp+270h] [ebp-184h]
  char v24[384]; // [esp+274h] [ebp-180h] BYREF

  LODWORD(v12[1]) = a1;
  if ( sub_588410(a4, aLftire) )
  {
    if ( sub_588410(a4, aRftire) )
    {
      if ( sub_588410(a4, aLrtire) )
        v6 = sub_588410(a4, aRrtire) != 0 ? -1 : 3;
      else
        v6 = 2;
    }
    else
    {
      v6 = 1;
    }
  }
  else
  {
    v6 = 0;
  }
  v7 = a3;
  memset(v24, 0, sizeof(v24));
  v19 = 0;
  v23 = 0;
  v21 = 0;
  v22 = 0;
  v20 = 1;
  result = sub_566CC0(v24, 384);
  if ( result )
  {
    while ( 1 )
    {
      result = sub_5651B0(v18);
      if ( result )
        goto LABEL_24;
      if ( !strcmp(v24, asc_5CC4F4) )
        return result;
      if ( sub_565520(aInstance, v17, 0) )
        sub_4A4ED0(v7, v17, a5, LODWORD(a6));
      if ( v6 == -1 )
        goto LABEL_24;
      if ( !sub_565520(aMeshfile, v16, 0) )
        goto LABEL_24;
      v12[0] = -1.0;
      v11 = -1.0;
      sub_565870(aLodin, v12, 0, 0, 0, 0, 0, 0, 0);
      sub_565870(aLodout, &v11, 0, 0, 0, 0, 0, 0, 0);
      if ( a6 < (double)v12[0] || a6 >= (double)v11 )
        goto LABEL_24;
      v13[0] = byte_5EA438[0];
      memset(&v13[1], 0, 0x3Cu);
      v14 = 0;
      v15 = 0;
      if ( !sub_565520(aShadowobject, v13, 0) || sub_588410(v13, aTrue) )
        break;
      v9 = 1;
      if ( dword_7CF884 >= 2 )
        goto LABEL_20;
LABEL_24:
      v7 = a3;
      result = sub_566CC0(v24, 384);
      if ( !result )
        return result;
    }
    v9 = 0;
LABEL_20:
    v10 = sub_587C03(72);
    if ( v10 )
    {
      strcpy((char *)v10, v16);
      if ( !sub_566810(v10, aMts) )
        strcat((char *)v10, ".MTS");
      *(_BYTE *)(v10 + 64) = v9;
      *(_DWORD *)(v10 + 68) = *(_DWORD *)(a5 + 4 * v6);
      *(_DWORD *)(a5 + 4 * v6) = v10;
    }
    goto LABEL_24;
  }
  return result;
}
