int __thiscall sub_5D28E0(_DWORD *this)
{
  _DWORD *v2; // ecx
  int result; // eax
  int v4; // edi
  int v5; // ebx
  _DWORD *v6; // ebp
  _DWORD *i; // eax
  int v8; // esi
  char v9; // al
  long double v10; // st7
  int v11; // ecx
  int v12; // eax
  int v13; // eax
  double v14; // st7
  double v15; // st7
  double v16; // st6
  float *v17; // eax
  int v18; // esi
  float v19; // ecx
  float v20; // edx
  float v21; // edx
  double v22; // st7
  double v23; // st6
  double v24; // st5
  double v25; // st6
  double v26; // st7
  double v27; // st6
  double v28; // st5
  int v29; // ebp
  float *v30; // esi
  double v31; // st7
  double v32; // st6
  double v33; // st5
  double v34; // st6
  float v35; // [esp+10h] [ebp-98h]
  float v36; // [esp+14h] [ebp-94h] BYREF
  float v37; // [esp+18h] [ebp-90h]
  float v38; // [esp+1Ch] [ebp-8Ch]
  float v39; // [esp+20h] [ebp-88h]
  float v40; // [esp+24h] [ebp-84h]
  float v41; // [esp+28h] [ebp-80h]
  _DWORD *v42; // [esp+2Ch] [ebp-7Ch]
  int v43; // [esp+30h] [ebp-78h]
  int v44; // [esp+34h] [ebp-74h]
  float v45; // [esp+38h] [ebp-70h]
  float v46; // [esp+3Ch] [ebp-6Ch]
  float v47; // [esp+40h] [ebp-68h]
  int v48; // [esp+44h] [ebp-64h]
  float v49[2]; // [esp+48h] [ebp-60h] BYREF
  float v50; // [esp+50h] [ebp-58h]
  int v51; // [esp+54h] [ebp-54h]
  float v52[2]; // [esp+58h] [ebp-50h] BYREF
  float v53; // [esp+60h] [ebp-48h]
  int v54; // [esp+64h] [ebp-44h]
  float v55; // [esp+68h] [ebp-40h]
  float v56; // [esp+6Ch] [ebp-3Ch]
  float v57[4]; // [esp+74h] [ebp-34h] BYREF
  float v58; // [esp+84h] [ebp-24h]
  float v59; // [esp+88h] [ebp-20h]
  float v60; // [esp+8Ch] [ebp-1Ch]
  float v61; // [esp+A4h] [ebp-4h]

  v2 = (_DWORD *)this[1];
  result = v2[1];
  v4 = *(_DWORD *)(result + 528);
  v42 = this;
  if ( v4 )
  {
    result = sub_5C1530(v2);
    if ( result )
    {
      v5 = *(_DWORD *)(this[1] + 4);
      if ( *(_DWORD *)(v5 + 548) )
      {
        v6 = (_DWORD *)result;
        for ( i = *(_DWORD **)(result + 16); i; i = (_DWORD *)i[4] )
          v6 = i;
        do
        {
          v8 = v6[2];
          v48 = *(_DWORD *)(v8 + 60);
          if ( sub_5BFD60((_DWORD *)v4, v48) )
          {
            v9 = *(_BYTE *)(v8 + 80);
            v10 = 3.1415927 * *(float *)(v8 + 32);
            v43 = *(int *)(v8 + 40);
            v39 = 0.0;
            v40 = 0.0;
            v41 = 0.0;
            memset(v57, 0, 12);
            v57[3] = 1.0;
            v35 = (1.0 - cos(v10)) * 0.5;
            *(float *)&v44 = *(double *)v8;
            if ( !v9 )
            {
              if ( !*(_BYTE *)(v8 + 84) )
              {
                v11 = *(_DWORD *)(v8 + 44);
                if ( v11 != *(_DWORD *)(v8 + 52) )
                {
                  v12 = *(_DWORD *)(v8 + 48);
                  if ( v12 == -1 || v11 < v12 )
                  {
                    if ( *(double *)(v8 + 8) < 0.0 )
                      sub_5D27E0(v42, v8, v4, 0, v43, v57);
                    else
                      sub_5D27E0(v42, v8, v4, *(_DWORD *)(v48 + 20), v43, v57);
                    v40 = v59;
                    v39 = v58;
                    v41 = v60;
                    v13 = sub_5C2520((_DWORD *)v8);
                    *(float *)&v43 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v13 + 16))(v13);
                  }
                }
              }
              sub_5D27E0(v42, v8, v4, v44, v43, v57);
              v39 = v58 + v39;
              v40 = v59 + v40;
              v41 = v60 + v41;
            }
            if ( v6[4] )
            {
              if ( *(_DWORD *)(v8 + 72) == 1 )
              {
                v61 = v41 * v35;
                v36 = v39 * v35 + v36;
                v37 = v40 * v35 + v37;
                v38 = v61 + v38;
              }
              else
              {
                v14 = 1.0 - v35;
                v55 = v36 * v14;
                v56 = v37 * v14;
                v46 = v40 * v35;
                v47 = v41 * v35;
                v53 = v47 + v14 * v38;
                v38 = v53;
                v36 = v39 * v35 + v55;
                v37 = v46 + v56;
              }
            }
            else
            {
              v50 = v41 * v35;
              v38 = v50;
              v36 = v39 * v35;
              v37 = v40 * v35;
            }
          }
          v6 = (_DWORD *)v6[3];
        }
        while ( v6 );
        v15 = *(float *)(v5 + 240);
        v16 = *(float *)(v5 + 244);
        v17 = *(float **)(v5 + 548);
        v50 = *(float *)(v5 + 248);
        v18 = (unsigned __int8)v17 & 0x10;
        v42 = v17;
        v36 = v36 * v15;
        v44 = v18;
        v37 = v37 * v16;
        v38 = v38 * v50;
        if ( ((unsigned __int8)v17 & 0x10) != 0 )
        {
          sub_4F2680((_DWORD *)v5, (_DWORD *)(v4 + 212));
          LOWORD(v17) = (_WORD)v42;
        }
        v48 = (unsigned __int16)v17 & 0x100;
        if ( ((unsigned __int16)v17 & 0x100) != 0 )
        {
          *(_DWORD *)(v5 + 240) = *(_DWORD *)(v4 + 240);
          *(_DWORD *)(v5 + 244) = *(_DWORD *)(v4 + 244);
          *(_DWORD *)(v5 + 248) = *(_DWORD *)(v4 + 248);
        }
        if ( *(float *)&v18 == 0.0 )
        {
          v19 = *(float *)(v5 + 220);
          v20 = *(float *)(v5 + 212);
          v52[1] = *(float *)(v5 + 216);
          v53 = v19;
          v52[0] = v20;
          v54 = *(_DWORD *)(v5 + 224);
          v17 = sub_5D2860(v52, v49, &v36);
          v21 = *v17;
          v38 = v17[2];
          LOBYTE(v17) = (_BYTE)v42;
          v36 = v21;
        }
        if ( ((unsigned __int8)v17 & 1) != 0 )
        {
          v22 = *(float *)(v5 + 232);
          v23 = *(float *)(v5 + 236);
          v45 = *(float *)(v5 + 228);
          v24 = v23;
          v25 = v45 + v36;
          v47 = v24 + v38;
          *(float *)(v5 + 236) = v47;
          *(float *)(v5 + 228) = v25;
          *(float *)(v5 + 232) = v22;
          v26 = *(float *)(v4 + 228);
          v27 = *(float *)(v4 + 232);
          v28 = *(float *)(v4 + 236);
          *(_DWORD *)(v4 + 228) = 0;
          *(_DWORD *)(v4 + 236) = 0;
          v36 = v26 + v36;
          v38 = v28 + v38;
          *(float *)(v4 + 232) = v27;
          v29 = *(_DWORD *)(v5 + 336);
          if ( v29 > 0 )
          {
            do
            {
              v30 = *(float **)(*(_DWORD *)(v5 + 344) + 4 * v29-- - 4);
              if ( v30 != (float *)v4
                && !(*(unsigned __int8 (__thiscall **)(float *, _DWORD))(*(_DWORD *)v30 + 16))(v30, 0) )
              {
                v31 = v30[58];
                v32 = v30[59];
                v45 = v30[57];
                v33 = v32;
                v34 = v45 - v36;
                v47 = v33 - v38;
                v30[59] = v47;
                v30[57] = v34;
                v30[58] = v31;
              }
            }
            while ( v29 > 0 );
            v18 = v44;
          }
        }
        if ( *(float *)&v18 != 0.0 )
        {
          v49[0] = 0.0;
          v49[1] = 0.0;
          v50 = 0.0;
          v51 = 1065353216;
          sub_4F2680((_DWORD *)v4, v49);
        }
        result = v48;
        if ( v48 )
        {
          result = 1065353216;
          *(_DWORD *)(v4 + 240) = 1065353216;
          *(_DWORD *)(v4 + 244) = 1065353216;
          *(_DWORD *)(v4 + 248) = 1065353216;
        }
      }
    }
  }
  return result;
}
