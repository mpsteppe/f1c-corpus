void __thiscall sub_4AEA10(_BYTE *this, char *Source, char a3)
{
  int v3; // ebx
  char v4; // al
  int v5; // esi
  const char *v6; // eax
  int v7; // ebx
  int v8; // edi
  int v9; // ebp
  int v10; // eax
  int v11; // eax
  double v12; // st7
  double v13; // st7
  double v14; // st7
  int v15; // edi
  int v16; // ebp
  unsigned __int16 v17; // cx
  int v18; // eax
  int v19; // esi
  int v20; // [esp-28h] [ebp-3A8h]
  int v21; // [esp-24h] [ebp-3A4h]
  int v22; // [esp-14h] [ebp-394h]
  float v23; // [esp+10h] [ebp-370h]
  int v24; // [esp+14h] [ebp-36Ch] BYREF
  _BYTE *v25; // [esp+18h] [ebp-368h]
  int v26; // [esp+1Ch] [ebp-364h]
  int v27; // [esp+20h] [ebp-360h] BYREF
  int v28; // [esp+24h] [ebp-35Ch]
  int v30; // [esp+2Ch] [ebp-354h]
  int v31; // [esp+30h] [ebp-350h]
  char v32[76]; // [esp+34h] [ebp-34Ch] BYREF
  char Destination[256]; // [esp+80h] [ebp-300h] BYREF
  char Buffer[509]; // [esp+180h] [ebp-200h] BYREF
  __int16 v35; // [esp+37Dh] [ebp-3h]
  char v36; // [esp+37Fh] [ebp-1h]

  v3 = (int)this;
  v4 = this[1172];
  v25 = this;
  if ( !v4 )
  {
    this[1172] = 1;
    if ( !Source )
      goto LABEL_33;
    if ( !strlen(Source) )
      goto LABEL_33;
    Destination[0] = 0;
    strncpy(Destination, Source, 0xFFu);
    Destination[255] = 0;
    if ( !a3 && sub_4AD050(v3, 0) == -1 )
      goto LABEL_33;
    v5 = sub_4AD970((_DWORD *)v3, aSavingreplay00, 0, 0, 1);
    if ( v5 )
      goto LABEL_12;
    Buffer[0] = byte_629120;
    memset(&Buffer[1], 0, 0x1FCu);
    v35 = 0;
    v36 = 0;
    v6 = (const char *)dword_62A098;
    v24 = 0;
    if ( !dword_62A098 )
      v6 = &byte_629120;
    sprintf(Buffer, "%s%s", v6, aOptionsMas);
    sub_5924D0(dword_7DA988, (int)&v24, (int)Buffer);
    v5 = sub_4AD970((_DWORD *)v3, aSavingreplay00, 0, 0, 1);
    if ( v24 )
      sub_592750(v24);
    if ( v5 )
    {
LABEL_12:
      v7 = *(_DWORD *)(v5 + 20);
      v8 = dword_6152E8 / 2 - v7 / 2;
      v26 = *(int *)(v5 + 24);
      v9 = dword_6152EC / 2 - v26 / 2;
      v24 = sub_4AB570();
      if ( sub_4B07C0(v5) && *(_DWORD *)(sub_4B07C0(v5) + 16) )
      {
        v22 = v26;
        v21 = v24;
        v20 = v26;
        v10 = sub_4B07C0(v5);
        sub_4AAF50(*(float *)(v10 + 16), 0, 0, v7, v20, v21, v8, v9, v7, v22, -1, -1, -1, -1);
      }
      v11 = sub_592CD0(a2003euro24);
      if ( v11 || (v11 = *(_DWORD *)(*((_DWORD *)v25 + 91) + 16)) != 0 )
        sub_505D00(v11 + 36, Destination, 1057300152, 1056964608, -1, 8, 1065353216, 1065353216, 0);
      sub_4AB400(0);
      if ( !a3 )
        sub_4D20D0(2, 2, 1036831949, 1);
    }
    else
    {
      if ( !*(_DWORD *)(*(_DWORD *)(v3 + 364) + 16) )
      {
LABEL_33:
        *(_BYTE *)(v3 + 1172) = 0;
        return;
      }
      v27 = 0;
      v24 = 0;
      sub_5A41F0(Destination, &v27, &v24, 1);
      v30 = 400 - v27 / 2;
      v31 = 300 - v24 / 2;
      v28 = sub_4AB570();
      sub_57B5D0(v32);
      sub_57B610(1);
      sub_57B690(v32);
      do
      {
        v12 = sub_57B7C0(v32);
        *(float *)&v26 = v12;
        v13 = v12 * 2.2222223;
        v23 = v13;
        if ( v13 >= 0.0 )
        {
          if ( v23 > 1.0 )
            v23 = 1.0;
        }
        else
        {
          v23 = 0.0;
        }
        v14 = v23;
        if ( v23 >= 0.0 )
        {
          if ( v23 > 1.0 )
            v14 = 1.0;
        }
        else
        {
          v14 = 0.0;
        }
        v15 = (__int64)((double)v24 * v23) + 8;
        v16 = (unsigned __int8)(__int64)(255.0 * (1.0 - v14) + v14 * 8.0);
        LOBYTE(v17) = 0;
        HIBYTE(v17) = (__int64)((1.0 - v14) * 0.0 + v14 * 0.0);
        v18 = (__int64)((double)v27 * v23) + 8;
        v19 = v28;
        sub_4AB0E0(v28, 400 - v18 / 2, 300 - v15 / 2, v18, v15, v16 | ((v16 | ((v16 | v17) << 8)) << 8));
        sub_4AB400(0);
      }
      while ( *(float *)&v26 <= 0.44999999 );
      sub_5A3FF0(Destination, v30, v31, v19, 0);
      nullsub_6(v32);
    }
    v3 = (int)v25;
    goto LABEL_33;
  }
}
