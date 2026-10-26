void __thiscall sub_4DD030(int this, int a2, int a3, int a4, int a5, _DWORD *a6, float a7, float a8, char *a9)
{
  int v10; // esi
  int v11; // edi
  int v12; // ebx
  int v13; // ecx
  int v14; // esi
  float v15; // eax
  float v16; // ecx
  int v17; // ecx
  unsigned int v18; // edx
  int v19; // eax
  char v20; // cl
  char *v21; // eax
  int v22; // edx
  char v23; // cl
  unsigned int v24; // edx
  float v25; // [esp-4h] [ebp-150h]
  int v26; // [esp+10h] [ebp-13Ch] BYREF
  int v27; // [esp+14h] [ebp-138h] BYREF
  int v28; // [esp+18h] [ebp-134h] BYREF
  int v29; // [esp+1Ch] [ebp-130h]
  int v30; // [esp+20h] [ebp-12Ch] BYREF
  int v31; // [esp+24h] [ebp-128h] BYREF
  int v32; // [esp+28h] [ebp-124h] BYREF
  int v33; // [esp+2Ch] [ebp-120h] BYREF
  int v34; // [esp+30h] [ebp-11Ch] BYREF
  int v35; // [esp+34h] [ebp-118h] BYREF
  _BYTE v36[13]; // [esp+38h] [ebp-114h] BYREF
  __int16 v37; // [esp+45h] [ebp-107h]
  char v38; // [esp+47h] [ebp-105h]
  int v39; // [esp+48h] [ebp-104h] BYREF
  char v40[125]; // [esp+4Ch] [ebp-100h] BYREF
  __int16 v41; // [esp+C9h] [ebp-83h]
  char v42; // [esp+CBh] [ebp-81h]
  _BYTE v43[125]; // [esp+CCh] [ebp-80h] BYREF
  __int16 v44; // [esp+149h] [ebp-3h]
  char v45; // [esp+14Bh] [ebp-1h]
  int v46; // [esp+154h] [ebp+8h]
  int v47; // [esp+158h] [ebp+Ch]

  if ( a2 )
  {
    v40[0] = byte_5EA438[0];
    memset(&v40[1], 0, 0x7Cu);
    v41 = 0;
    v42 = 0;
    if ( !a9 )
    {
      a9 = *(char **)(this + 40);
      if ( !a9 )
        a9 = byte_5EA438;
    }
    if ( a7 > 0.0 )
      *(float *)(this + 48) = a7;
    if ( a8 > 0.0 )
      *(float *)(this + 52) = a8;
    sub_587DD0(v40, a2, 127);
    v42 = 0;
    TripleFieldGetter((_DWORD *)this, &v30, &v28, 0);
    TwinFieldGetter_cf30((_DWORD *)this, &v27, &v26);
    v27 += v30;
    v29 = v28 + v26;
    v46 = v30 + a3;
    v47 = v28 + a4;
    if ( v40[0] )
    {
      while ( 1 )
      {
        SurfaceSizeQuery((int)a9, (int)v40, &v31, &v34, *(float *)(this + 48), *(float *)(this + 52));
        v10 = v34;
        v11 = v31;
        AlignmentPositionSwitch(v46, v47, v31, v34, a6, &v35, &v33);
        v12 = v35;
        v26 = v35 + v11;
        v13 = v33 + v10;
        v14 = v30;
        if ( v35 >= v30 )
        {
          if ( v33 < v28 )
            return;
          if ( v26 <= v27 && v13 <= v29 )
            break;
        }
        if ( v33 < v28 || v13 > v29 || v11 <= 0 )
          return;
        *(_DWORD *)&v36[5] = 0;
        *(_DWORD *)&v36[9] = 0;
        strcpy(v36, "AbCd");
        v15 = *(float *)(this + 52);
        v37 = 0;
        v25 = v15;
        v16 = *(float *)(this + 48);
        v38 = 0;
        SurfaceSizeQuery((int)a9, (int)v36, &v32, &v39, v16, v15);
        v17 = v32 / 4;
        if ( v32 / 4 >= 1 )
        {
          if ( v17 > 1000 )
            v17 = 1000;
        }
        else
        {
          v17 = 1;
        }
        if ( v12 >= v14 )
        {
          v24 = (v26 - v27) / v17;
          if ( v24 )
          {
            if ( v24 > 0x3E8 )
              v24 = 1000;
          }
          else
          {
            v24 = 1;
          }
          if ( v24 >= strlen(v40) )
            return;
          v40[strlen(v40) - v24] = 0;
        }
        else
        {
          v18 = (v14 - v12) / v17;
          if ( v18 )
          {
            if ( v18 > 0x3E8 )
              v18 = 1000;
          }
          else
          {
            v18 = 1;
          }
          if ( v18 >= strlen(v40) )
            return;
          v43[0] = byte_5EA438[0];
          memset(&v43[1], 0, 0x7Cu);
          v44 = 0;
          v45 = 0;
          v19 = 0;
          do
          {
            v20 = v40[v19];
            v43[v19++] = v20;
          }
          while ( v20 );
          v21 = &v43[v18];
          v22 = v40 - &v43[v18];
          do
          {
            v23 = *v21;
            v21[v22] = *v21;
            ++v21;
          }
          while ( v23 );
        }
        if ( !v40[0] )
          return;
      }
      ScaledTextureRender((int)a9, (int)v40, v46, v47, a5, a6, *(_DWORD *)(this + 48), *(_DWORD *)(this + 52), 0);
    }
  }
}

