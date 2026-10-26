char __thiscall sub_4D5C20(int this, int a2, int a3, int a4)
{
  _DWORD *v4; // ebx
  int v7; // eax
  int v8; // esi
  int v9; // edx
  int v10; // eax
  int v11; // ecx
  int v12; // edx
  int v13; // ecx
  int v14; // edx
  int v15; // eax
  float v16; // ecx
  float v17; // edx
  int v18; // esi
  char v19; // bl
  double v20; // st7
  double v21; // st7
  double v22; // st7
  double v23; // st7
  double v24; // st7
  double v25; // st7
  float v26; // [esp+4h] [ebp-154h]
  float v27; // [esp+4h] [ebp-154h]
  float v28; // [esp+4h] [ebp-154h]
  float v29; // [esp+1Ch] [ebp-13Ch]
  float v30; // [esp+1Ch] [ebp-13Ch]
  float v31; // [esp+1Ch] [ebp-13Ch]
  float v32; // [esp+1Ch] [ebp-13Ch]
  int v33; // [esp+20h] [ebp-138h]
  int v34; // [esp+20h] [ebp-138h]
  float v35; // [esp+24h] [ebp-134h]
  float v36; // [esp+28h] [ebp-130h]
  float v37; // [esp+2Ch] [ebp-12Ch]
  float v38; // [esp+30h] [ebp-128h]
  float v39; // [esp+34h] [ebp-124h]
  float v40; // [esp+38h] [ebp-120h]
  float v41; // [esp+3Ch] [ebp-11Ch]
  float v42; // [esp+40h] [ebp-118h]
  float v43; // [esp+44h] [ebp-114h]
  float v44; // [esp+48h] [ebp-110h]
  float v45; // [esp+4Ch] [ebp-10Ch]
  float v46; // [esp+50h] [ebp-108h]
  float v47; // [esp+54h] [ebp-104h]
  _DWORD v48[3]; // [esp+58h] [ebp-100h]
  _DWORD v49[3]; // [esp+64h] [ebp-F4h]
  _DWORD v50[3]; // [esp+70h] [ebp-E8h]
  _DWORD v51[3]; // [esp+7Ch] [ebp-DCh]
  int v52[52]; // [esp+88h] [ebp-D0h] BYREF

  v4 = (_DWORD *)a2;
  if ( *(_DWORD *)a2 >> 28 != 1 )
    return 0;
  if ( (*(_BYTE *)(a2 + 2) & 0x3F) != 0 )
    return 0;
  if ( byte_768594
    && !dword_630030[6326 * (*(_DWORD *)a2 & 0x3F)]
    && fabs(*(float *)(a2 + 4) - *(float *)(a4 + 4)) > 0.02 )
  {
    return 0;
  }
  if ( (*(_BYTE *)(a3 + 15) & 1) != 0 || (*(_BYTE *)(a4 + 15) & 1) != 0 )
  {
    v7 = *(_DWORD *)(this + 1316);
    if ( v7 < 3 || v7 > 4 )
    {
LABEL_16:
      sub_4D1850((_DWORD *)(this + 1552), v4);
      sub_4D1850((_DWORD *)(this + 1344), (_DWORD *)a4);
      v9 = *(_DWORD *)(this + 1592);
      v10 = *(_DWORD *)(this + 1596);
      v51[0] = *(_DWORD *)(this + 1588);
      v51[1] = v9;
      v51[2] = v10;
      v44 = *(float *)(this + 1600);
      v45 = *(float *)(this + 1604);
      v46 = *(float *)(this + 1608);
      v11 = *(_DWORD *)(this + 1384);
      v12 = *(_DWORD *)(this + 1388);
      v48[0] = *(_DWORD *)(this + 1380);
      v48[1] = v11;
      v38 = *(float *)(this + 1392);
      v13 = 25304 * (*(_DWORD *)a3 & 0x3F);
      v48[2] = v12;
      v39 = *(float *)(this + 1396);
      v40 = *(float *)(this + 1400);
      sub_52E870(*(float *)(a3 + 4), (int)v52, *(float *)(v13 + 6492356));
      v14 = *(_DWORD *)(a3 + 40);
      v15 = *(_DWORD *)(a3 + 44);
      v50[0] = *(_DWORD *)(a3 + 36);
      v16 = *(float *)(a3 + 48);
      v50[1] = v14;
      v17 = *(float *)(a3 + 52);
      v50[2] = v15;
      v41 = v16;
      v42 = v17;
      v43 = *(float *)(a3 + 56);
      v49[0] = v52[9];
      v49[1] = v52[10];
      v49[2] = v52[11];
      v18 = 0;
      v35 = *(float *)&v52[12];
      v36 = *(float *)&v52[13];
      v37 = *(float *)&v52[14];
      v34 = 0;
      while ( 1 )
      {
        v19 = 1;
        if ( v18 )
        {
          if ( v38 <= (double)v44 )
            v20 = v44 - v38;
          else
            v20 = v38 - v44;
          v30 = v20;
          if ( v20 > 3.141592653589793 )
            v30 = v30 - (v30 - 3.141592653589793);
          if ( v41 <= (double)v35 )
            v21 = v35 - v41;
          else
            v21 = v41 - v35;
          if ( v21 > 3.141592653589793 )
            v21 = v21 - (v21 - 3.141592653589793);
          v26 = v21;
          if ( !(unsigned __int8)sub_4D6190(v26, v30) )
            return 0;
          if ( v39 <= (double)v45 )
            v22 = v45 - v39;
          else
            v22 = v39 - v45;
          v31 = v22;
          if ( v22 > 3.141592653589793 )
            v31 = v31 - (v31 - 3.141592653589793);
          if ( v42 <= (double)v36 )
            v23 = v36 - v42;
          else
            v23 = v42 - v36;
          if ( v23 > 3.141592653589793 )
            v23 = v23 - (v23 - 3.141592653589793);
          v27 = v23;
          if ( !(unsigned __int8)sub_4D6190(v27, v31) )
            return 0;
          if ( v40 <= (double)v46 )
            v24 = v46 - v40;
          else
            v24 = v40 - v46;
          v32 = v24;
          if ( v24 > 3.141592653589793 )
            v32 = v32 - (v32 - 3.141592653589793);
          if ( v43 <= (double)v37 )
            v25 = v37 - v43;
          else
            v25 = v43 - v37;
          if ( v25 > 3.141592653589793 )
            v25 = v25 - (v25 - 3.141592653589793);
          v28 = v25;
          if ( !(unsigned __int8)sub_4D6190(v28, v32) )
            return 0;
        }
        else
        {
          do
          {
            v29 = *(float *)&v49[v18] - *(float *)&v50[v18];
            if ( v18 == 1 )
              v29 = v29 + v29;
            v47 = *(float *)&v48[v18] - *(float *)&v51[v18];
            if ( !(unsigned __int8)sub_4D60A0(v29, v47) )
              break;
            if ( v18 == 2 )
              v19 = 0;
            ++v18;
          }
          while ( v18 < 3 );
          if ( v19 )
            return 0;
          v18 = v34;
        }
        v34 = ++v18;
        if ( v18 >= 2 )
          return 1;
      }
    }
    v8 = 0;
    while ( 1 )
    {
      v33 = sub_4D04F0((_DWORD *)(a4 + 8), v8);
      if ( sub_4D04F0(v4 + 2, v8) != v33 )
        return 0;
      v4 = (_DWORD *)a2;
      if ( ++v8 >= 18 )
        goto LABEL_16;
    }
  }
  return 1;
}
