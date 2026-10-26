int __userpurge sub_476B30@<eax>(_DWORD *a1@<ecx>, int *a2@<ebp>, int *a3, int *a4, int *a5, int *a6)
{
  int v7; // eax
  int v8; // edi
  _DWORD *v9; // ecx
  int v10; // ebx
  int v11; // ebp
  int v12; // eax
  int v13; // ebp
  int v14; // ebp
  int v15; // eax
  char *v16; // eax
  const char *v17; // eax
  char *v18; // eax
  char *v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // edi
  int v23; // ebx
  _DWORD *v24; // eax
  _DWORD *v25; // edi
  int v26; // ebx
  int v27; // eax
  int v28; // ecx
  _DWORD *v29; // eax
  int v30; // eax
  float v32; // [esp+4h] [ebp-50h]
  float v33; // [esp+8h] [ebp-4Ch]
  int v35; // [esp+20h] [ebp-34h]
  _DWORD *v36; // [esp+24h] [ebp-30h]
  int v37; // [esp+28h] [ebp-2Ch]
  int v38; // [esp+2Ch] [ebp-28h]
  int v39; // [esp+30h] [ebp-24h]
  int v40; // [esp+34h] [ebp-20h]
  int v41; // [esp+34h] [ebp-20h]
  int v42; // [esp+34h] [ebp-20h]
  int v43; // [esp+3Ch] [ebp-18h]
  int v44; // [esp+44h] [ebp-10h]
  int v45; // [esp+48h] [ebp-Ch] BYREF
  int v46; // [esp+4Ch] [ebp-8h] BYREF
  int v47; // [esp+50h] [ebp-4h] BYREF
  _UNKNOWN *retaddr; // [esp+54h] [ebp+0h] BYREF

  v7 = a1[94];
  v8 = a1[36];
  v9 = 0;
  v35 = v8;
  v36 = 0;
  if ( v7 > 0 )
  {
    do
    {
      if ( !v8 )
        break;
      --v7;
      v9 = (_DWORD *)((char *)v9 + 1);
      v35 = *(_DWORD *)(v8 + 140);
      v8 = v35;
    }
    while ( v7 > 0 );
    v36 = v9;
  }
  sub_49FF10(a1);
  v10 = 0;
  v37 = 0;
  if ( (int)a1[97] < 1 || (int)a1[102] < 1 )
    return -1;
  v40 = a1[100];
  if ( v8 )
  {
    while ( 1 )
    {
      if ( v40 <= 0 )
        return 0;
      if ( (*(int (__thiscall **)(_DWORD *, int *))(*a1 + 4))(a1, a2) <= 0 )
        v41 = a1[4];
      else
        v41 = (*(int (__thiscall **)(_DWORD *))(*a1 + 4))(a1);
      if ( (int)sub_49D7F0(2) <= 0 )
      {
        v12 = a1[1];
        v13 = a1[88] + v10 * (a1[97] + a1[90]);
      }
      else
      {
        v11 = sub_49D7F0(2);
        v12 = a1[88];
        v13 = v10 * (a1[97] + a1[90]) + v11;
      }
      v14 = v12 + v13;
      v39 = v14;
      if ( v37 == a1[101] )
      {
        v15 = a1[61];
        if ( !v15 )
          goto LABEL_34;
        v16 = *(char **)(v15 + 72);
      }
      else
      {
        v17 = *(const char **)(v8 + 272);
        if ( !v17 )
          v17 = &byte_629120;
        if ( !strlen(v17) )
          goto LABEL_29;
        v18 = (char *)v36[68];
        if ( !v18 )
          v18 = &byte_629120;
        sub_4ADDF0(v18);
        v19 = (char *)v36[68];
        if ( !v19 )
          v19 = &byte_629120;
        if ( (unsigned __int8)sub_4ADEF0(v19) )
        {
          v16 = (char *)v36[68];
        }
        else
        {
LABEL_29:
          v20 = a1[61];
          if ( !v20 )
            goto LABEL_34;
          v16 = *(char **)(v20 + 64);
        }
      }
      if ( !v16 )
        v16 = &byte_629120;
      sub_4AE350(v16);
LABEL_34:
      v21 = a1[91];
      v22 = v21 + a1[3];
      v42 = v41 - v21;
      v23 = v14 + a1[97];
      v44 = v23;
      v43 = v22;
      if ( v37 == a1[101] )
      {
        v24 = (_DWORD *)sub_49CB60(4);
        v25 = v24;
        if ( v24 )
        {
          v26 = v24[3] - v24[2];
          v27 = (__int64)((double)v26 * -0.5) - (__int64)((double)(int)a1[97] * -0.5);
          sub_49D330(4, 0, v14 + v27, v14 + v27 + v26, a1[3], a1[3] + v25[1] - *v25);
          v23 = v44;
        }
        v22 = v43;
      }
      v28 = a1[v38 + 108 + a1[94]];
      if ( v28 >= 0 && v28 < a1[107] )
      {
        v29 = (_DWORD *)a1[104];
        if ( v28 <= 0 )
        {
LABEL_43:
          if ( v29 && *v29 )
          {
            v33 = (double)v14 * 0.0016666667;
            v32 = (double)(v22 + a1[156]) * 0.00125;
            sub_506AE0(v32, v33, 1.0, 0);
          }
        }
        else
        {
          while ( v29 )
          {
            v29 = (_DWORD *)v29[1];
            if ( --v28 <= 0 )
              goto LABEL_43;
          }
        }
      }
      sub_4B13F0(v14, v23, v22, v42);
      a2 = &v45;
      (*(void (__thiscall **)(_DWORD *, _UNKNOWN **, int *, int *))(*v36 + 24))(v36, &retaddr, &v47, &v46);
      if ( v37 && v14 >= *a3 )
        v14 = *a3;
      *a3 = v14;
      if ( v37 && v23 <= *a4 )
        v23 = *a4;
      *a4 = v23;
      if ( v37 && v22 >= *a5 )
        v22 = *a5;
      *a5 = v22;
      if ( v37 )
      {
        v30 = *a6;
        if ( v39 > *a6 )
          v30 = v39;
      }
      else
      {
        v30 = v39;
      }
      *a6 = v30;
      v35 = *(_DWORD *)(v35 + 140);
      v40 = v42 - 1;
      v36 = (_DWORD *)((char *)v36 + 1);
      ++v37;
      if ( !v35 )
        return 0;
      v8 = v35;
      v10 = v37;
    }
  }
  return 0;
}
