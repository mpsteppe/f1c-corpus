int __userpurge sub_4F59C8@<eax>(int a1@<eax>, int a2@<ecx>, int a3@<ebx>, int a4@<ebp>, int a5, int a6)
{
  int v7; // edi
  int v8; // eax
  double v9; // st7
  double v10; // st6
  double v11; // st5
  float *v12; // eax
  _DWORD *v13; // eax
  int v14; // ecx
  int v15; // edx
  int v16; // ecx
  int v17; // ebp
  int v18; // ebx
  int v19; // ebp
  int v20; // ebx
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  _DWORD *i; // ebp
  int v26; // eax
  int v27; // ecx
  int v28; // eax
  int v29; // ecx
  int v30; // eax
  int v31; // eax
  int v32; // ecx
  int v33; // eax
  int v34; // eax
  int v35; // ecx
  int v36; // eax
  int v37; // eax
  int result; // eax
  double v39; // st7
  int v40; // ecx
  int v41; // eax
  int v42; // ebp
  float v43; // [esp+24h] [ebp-5Ch]
  int v44; // [esp+38h] [ebp-48h] BYREF
  int v45; // [esp+3Ch] [ebp-44h]
  float v46; // [esp+40h] [ebp-40h]
  int v47; // [esp+44h] [ebp-3Ch] BYREF
  int v48; // [esp+48h] [ebp-38h]
  int v49; // [esp+4Ch] [ebp-34h]
  int v50; // [esp+50h] [ebp-30h]
  int v51; // [esp+58h] [ebp-28h]
  int v52; // [esp+60h] [ebp-20h]
  int v53; // [esp+64h] [ebp-1Ch]
  int v54; // [esp+6Ch] [ebp-14h]
  int v55; // [esp+78h] [ebp-8h]
  void *v56; // [esp+7Ch] [ebp-4h]

  v56 = &loc_6E5738;
  v55 = a1;
  v45 = a3;
  v44 = a4;
  v7 = *(_DWORD *)(a2 + 156) + 120 * a6;
  if ( *(_BYTE *)(a2 + 240) )
  {
    v8 = 60 * *(_DWORD *)(a2 + 268);
    v9 = *(float *)(v8 + a2 + 252);
    v10 = *(float *)(v8 + a2 + 248);
    v11 = *(float *)(v8 + a2 + 244);
    v12 = *(float **)(*(_DWORD *)(a2 + 140) + 8);
    v12[57] = v11;
    v12[58] = v10;
    v12[59] = v9;
    v46 = *(float *)(a2 + 752);
    sub_4F21D0((float *)&v47, 0.0, v46, 0.0);
    v13 = *(_DWORD **)(*(_DWORD *)(a2 + 140) + 8);
    v14 = v48;
    v13[53] = v47;
    v15 = v49;
    v13[54] = v14;
    v16 = v50;
    v13[55] = v15;
    v13[56] = v16;
    v17 = *(_DWORD *)(*(_DWORD *)(a2 + 140) + 8);
    v18 = *(_DWORD *)(a2 + 168);
    if ( (unsigned __int8)sub_405250() )
      sub_5BC080(v17, v18, 0);
    *(_DWORD *)(a2 + 168) = 0;
    *(_BYTE *)(a2 + 240) = 0;
  }
  if ( *(_DWORD *)(a2 + 160) )
  {
    v19 = *(_DWORD *)(a2 + 168);
    if ( v19 )
    {
      v20 = *(_DWORD *)(*(_DWORD *)(a2 + 140) + 8);
      if ( (unsigned __int8)sub_405250() )
      {
        v21 = *(_DWORD *)(v19 + 48);
        if ( (v21 == -1 || *(_DWORD *)(v19 + 44) < v21) && !*(_BYTE *)(v19 + 80) && !*(_BYTE *)(v19 + 81) )
        {
          sub_5BC080(v20, v19, *(_DWORD *)(*(_DWORD *)(a2 + 160) + 12));
          *(_DWORD *)(a2 + 168) = 0;
        }
      }
    }
    if ( *(float *)(*(_DWORD *)(a2 + 160) + 52) != 99999.0 )
    {
      v22 = *(_DWORD *)(a2 + 192);
      if ( v22 )
      {
        *(_BYTE *)(v22 + 12) = 0;
        if ( !*(_BYTE *)(*(_DWORD *)(a2 + 160) + 80) )
          *(_BYTE *)(*(_DWORD *)(a2 + 192) + 13) = 1;
        *(_DWORD *)(a2 + 192) = 0;
      }
    }
    if ( *(float *)(*(_DWORD *)(a2 + 160) + 64) != 99999.0 )
    {
      v23 = *(_DWORD *)(a2 + 196);
      if ( v23 )
      {
        *(_BYTE *)(v23 + 12) = 0;
        if ( !*(_BYTE *)(*(_DWORD *)(a2 + 160) + 80) )
          *(_BYTE *)(*(_DWORD *)(a2 + 196) + 13) = 1;
        *(_DWORD *)(a2 + 196) = 0;
      }
    }
    if ( *(float *)(*(_DWORD *)(a2 + 160) + 76) != 99999.0 )
    {
      v24 = *(_DWORD *)(a2 + 200);
      if ( v24 )
      {
        *(_BYTE *)(v24 + 12) = 0;
        if ( !*(_BYTE *)(*(_DWORD *)(a2 + 160) + 80) )
          *(_BYTE *)(*(_DWORD *)(a2 + 200) + 13) = 1;
        *(_DWORD *)(a2 + 200) = 0;
      }
    }
  }
  for ( i = *(_DWORD **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 140) + 8) + 532) + 8); *i; sub_5C21F0(i, 0) )
    ;
  if ( *(_DWORD *)(v7 + 32) )
  {
    *(_DWORD *)(a2 + 84) = *(_DWORD *)(a2 + 120);
    v26 = *(_DWORD *)(a2 + 128);
    *(_DWORD *)(a2 + 88) = *(_DWORD *)(a2 + 124);
    *(_DWORD *)(a2 + 92) = v26;
    sub_4F4440();
  }
  v27 = *(_DWORD *)(v7 + 88);
  v43 = 1.0;
  if ( v27
    && (v54 >= *(_DWORD *)(a2 + 152) - 1 || *(_DWORD *)(v7 + 236) != 36 ? (v28 = 0) : (v28 = v7 + 120),
        v43 = sub_4F4930(a2, v27, *(_DWORD *)(v7 + 92), v28),
        v43 == 0.0) )
  {
    v29 = *(_DWORD *)(v7 + 44);
    if ( v29 )
    {
      v30 = *(_DWORD *)(a2 + 192);
      if ( v30 != v29 )
      {
        if ( v30 )
        {
          *(_BYTE *)(v30 + 12) = 0;
          if ( !*(_BYTE *)(v7 + 80) )
            *(_BYTE *)(*(_DWORD *)(a2 + 192) + 13) = 1;
        }
        v31 = *(_DWORD *)(v7 + 44);
        *(_DWORD *)(a2 + 192) = v31;
        *(_BYTE *)(v31 + 12) = 1;
        if ( *(_DWORD *)(a2 + 216) )
          sub_4F08B0(*(_DWORD *)(a2 + 192));
      }
    }
    v32 = *(_DWORD *)(v7 + 56);
    if ( v32 )
    {
      v33 = *(_DWORD *)(a2 + 196);
      if ( v33 != v32 )
      {
        if ( v33 )
        {
          *(_BYTE *)(v33 + 12) = 0;
          if ( !*(_BYTE *)(v7 + 80) )
            *(_BYTE *)(*(_DWORD *)(a2 + 196) + 13) = 1;
        }
        v34 = *(_DWORD *)(v7 + 56);
        *(_DWORD *)(a2 + 196) = v34;
        *(_BYTE *)(v34 + 12) = 1;
        if ( *(_DWORD *)(a2 + 220) )
          sub_4F08B0(*(_DWORD *)(a2 + 196));
      }
    }
    v35 = *(_DWORD *)(v7 + 68);
    if ( v35 )
    {
      v36 = *(_DWORD *)(a2 + 200);
      if ( v36 != v35 )
      {
        if ( v36 )
        {
          *(_BYTE *)(v36 + 12) = 0;
          if ( !*(_BYTE *)(v7 + 80) )
            *(_BYTE *)(*(_DWORD *)(a2 + 200) + 13) = 1;
        }
        v37 = *(_DWORD *)(v7 + 68);
        *(_DWORD *)(a2 + 200) = v37;
        *(_BYTE *)(v37 + 12) = 1;
        if ( *(_DWORD *)(a2 + 224) )
          sub_4F08B0(*(_DWORD *)(a2 + 200));
      }
    }
    result = v52;
    if ( v52 < *(_DWORD *)(a2 + 152) - 1 && *(_DWORD *)(v7 + 236) == 36 )
      return sub_4F59C0();
  }
  else
  {
    sub_5BFC10(&v44);
    v39 = v43 * *(float *)(v7 + 4);
    v53 = 0;
    v46 = v39;
    v44 = *(_DWORD *)(v7 + 8);
    v45 = *(_DWORD *)(v7 + 12);
    v48 = *(_DWORD *)(v7 + 16);
    BYTE2(v51) = *(_BYTE *)(v7 + 36);
    sub_405080();
    v40 = *(_DWORD *)(a2 + 140);
    v41 = *(_DWORD *)(v40 + 12);
    v42 = v53;
    *(_DWORD *)(a2 + 168) = v41;
    *(_DWORD *)(a2 + 160) = v41 != 0 ? v7 : 0;
    *(_DWORD *)(a2 + 164) = v42;
    sub_405F00((_BYTE *)v40, *(_DWORD *)(v7 + 100) == 0);
    return off_16C94B0(a5);
  }
  return result;
}
