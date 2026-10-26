int __thiscall sub_5404D0(int *this, _DWORD *a2, int a3, int a4, signed int a5, char *a6, int a7)
{
  int v8; // eax
  int v9; // eax
  int v11; // edi
  _DWORD *v12; // ecx
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  char *v18; // edx
  int v19; // eax
  int v20; // esi
  char *v21; // edx
  int v22; // esi
  int v23; // esi
  int v24; // ebp
  __int16 v25; // ax
  char *v26; // edx
  int v27; // esi
  int v28; // esi
  char *v29; // edi
  char *v30; // edi
  int i; // ecx
  int v32; // eax
  int v33; // eax
  int v34; // eax
  int v35; // eax
  int v37; // [esp+34h] [ebp-28h] BYREF
  char *v38; // [esp+38h] [ebp-24h]
  int v39; // [esp+3Ch] [ebp-20h] BYREF
  int v40; // [esp+40h] [ebp-1Ch]
  int v41; // [esp+44h] [ebp-18h]
  char *v42; // [esp+48h] [ebp-14h]
  _DWORD v43[4]; // [esp+4Ch] [ebp-10h] BYREF
  int v44; // [esp+70h] [ebp+14h]
  int v45; // [esp+74h] [ebp+18h]

  v8 = a2[6];
  if ( (v8 & 0x40000) != 0 )
  {
    sub_55CA90(a2, 0);
    v43[0] = a3;
    v43[2] = a5 + a3;
    v43[1] = a4;
    v9 = this[1088];
    v43[3] = &a6[a4];
    *this = (*(int (__stdcall **)(int, int, _DWORD *, int, int, _DWORD, _DWORD))(*(_DWORD *)v9 + 144))(
              v9,
              1,
              v43,
              1,
              a7,
              0,
              0);
    sub_55CA90(0, 0);
    return 0;
  }
  v11 = (int)a6;
  v12 = a2;
  if ( (v8 & 1) != 0 )
  {
    v13 = a2[2];
  }
  else
  {
    if ( (v8 & 2) == 0 )
      goto LABEL_10;
    v13 = a2[3];
  }
  if ( v13 )
  {
    v42 = &a6[a4];
    v39 = a3;
    v40 = a4;
    v41 = a5 + a3;
    v14 = (*(int (__stdcall **)(int, int *, int *, _DWORD))(*(_DWORD *)v13 + 36))(v13, &v37, &v39, 0);
    *this = v14;
    if ( v14 )
      return -1;
    a6 = v38;
    a2[10] = v37;
    v12 = a2;
  }
LABEL_10:
  v15 = v12[6];
  if ( (v15 & 4) != 0 )
  {
    v16 = v12[4];
  }
  else
  {
    if ( (v15 & 8) == 0 )
      goto LABEL_17;
    v16 = v12[5];
  }
  if ( v16 )
  {
    v39 = a3;
    v40 = a4;
    v41 = a5 + a3;
    v42 = (char *)(v11 + a4);
    v17 = (*(int (__stdcall **)(int, _DWORD, int *, int *, _DWORD))(*(_DWORD *)v16 + 64))(v16, 0, &v37, &v39, 0);
    *this = v17;
    if ( !v17 )
    {
      v12 = a2;
      v18 = v38;
      a2[10] = v37;
      a6 = v18;
      goto LABEL_17;
    }
    return -1;
  }
LABEL_17:
  v19 = v12[12];
  v20 = v12[10];
  switch ( v19 )
  {
    case 7:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
      break;
    case 8:
      v21 = a6;
      v22 = v20 >> 2;
      if ( v11 > 0 )
      {
        v23 = 4 * (v22 - a5);
        v24 = v11;
        do
        {
          if ( a5 > 0 )
          {
            memset32(v21, a7, a5);
            v12 = a2;
            v21 += 4 * a5;
          }
          v21 += v23;
          --v24;
        }
        while ( v24 );
      }
      break;
    default:
      v25 = RGBAByteExtraction(v19, a7);
      v26 = a6;
      v27 = v20 >> 1;
      if ( v11 > 0 )
      {
        v28 = 2 * (v27 - a5);
        v44 = v28;
        v45 = v11;
        do
        {
          if ( a5 > 0 )
          {
            LOWORD(v28) = v25;
            v29 = v26;
            v26 += 2 * a5;
            v28 <<= 16;
            LOWORD(v28) = v25;
            memset32(v29, v28, (unsigned int)a5 >> 1);
            v30 = &v29[4 * ((unsigned int)a5 >> 1)];
            for ( i = a5 & 1; i; --i )
            {
              *(_WORD *)v30 = v25;
              v30 += 2;
            }
          }
          v26 += v44;
          --v45;
        }
        while ( v45 );
      }
      v12 = a2;
      break;
  }
  v32 = v12[6];
  if ( (v32 & 1) != 0 )
  {
    v33 = v12[2];
  }
  else
  {
    if ( (v32 & 2) == 0 )
      goto LABEL_39;
    v33 = v12[3];
  }
  if ( v33 )
  {
    *this = (*(int (__stdcall **)(int))(*(_DWORD *)v33 + 40))(v33);
    v12 = a2;
  }
LABEL_39:
  v34 = v12[6];
  if ( (v34 & 4) != 0 )
  {
    v35 = v12[4];
    goto LABEL_43;
  }
  if ( (v34 & 8) != 0 )
  {
    v35 = v12[5];
LABEL_43:
    if ( v35 )
    {
      *this = (*(int (__stdcall **)(int, _DWORD))(*(_DWORD *)v35 + 68))(v35, 0);
      v12 = a2;
    }
  }
  v12[6] &= ~0x400u;
  return 0;
}

