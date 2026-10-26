int __userpurge sub_4A01C0@<eax>(int *a1@<ecx>, int *a2@<ebx>, int *a3, int *a4, int *a5, int *a6)
{
  int v7; // eax
  int v8; // ebp
  int v9; // ecx
  int v10; // edi
  int v11; // ebx
  int v12; // eax
  int v13; // ebx
  int v14; // ebx
  int v15; // eax
  char *v16; // eax
  const char *v17; // eax
  char *v18; // eax
  char *v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // ebp
  int v23; // edi
  _DWORD *v24; // eax
  int v25; // edi
  int v26; // eax
  int v27; // ecx
  int v28; // eax
  int v29; // ebp
  int v30; // eax
  int v33; // [esp+10h] [ebp-34h]
  int v34; // [esp+14h] [ebp-30h]
  int v35; // [esp+18h] [ebp-2Ch]
  int v36; // [esp+1Ch] [ebp-28h]
  int v37; // [esp+20h] [ebp-24h]
  int v38; // [esp+20h] [ebp-24h]
  int v39; // [esp+20h] [ebp-24h]
  int v40; // [esp+28h] [ebp-1Ch]
  int v41; // [esp+2Ch] [ebp-18h]
  int v42; // [esp+30h] [ebp-14h]
  int v43; // [esp+34h] [ebp-10h]
  int v44; // [esp+38h] [ebp-Ch] BYREF
  int v45; // [esp+3Ch] [ebp-8h] BYREF
  int v46; // [esp+40h] [ebp-4h] BYREF
  _UNKNOWN *retaddr; // [esp+44h] [ebp+0h] BYREF

  v7 = a1[94];
  v8 = a1[36];
  v9 = 0;
  v33 = v8;
  v34 = 0;
  if ( v7 > 0 )
  {
    do
    {
      if ( !v8 )
        break;
      --v7;
      ++v9;
      v33 = *(_DWORD *)(v8 + 140);
      v8 = v33;
    }
    while ( v7 > 0 );
    v34 = v9;
  }
  sub_49FF10(a1);
  v10 = 0;
  v35 = 0;
  if ( a1[97] < 1 || a1[102] < 1 )
    return -1;
  v37 = a1[100];
  if ( v8 )
  {
    while ( 1 )
    {
      if ( v37 <= 0 )
        return 0;
      if ( (*(int (__thiscall **)(int *, int *))(*a1 + 4))(a1, a2) <= 0 )
        v38 = a1[4];
      else
        v38 = (*(int (__thiscall **)(int *))(*a1 + 4))(a1);
      if ( sub_49D7F0(a1, 2) <= 0 )
      {
        v12 = a1[1];
        v13 = a1[88] + v10 * (a1[97] + a1[90]);
      }
      else
      {
        v11 = sub_49D7F0(a1, 2);
        v12 = a1[88];
        v13 = v10 * (a1[97] + a1[90]) + v11;
      }
      v14 = v12 + v13;
      if ( v35 == a1[101] )
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
        v18 = *(char **)(v8 + 272);
        if ( !v18 )
          v18 = &byte_629120;
        sub_4ADDF0(v18);
        v19 = *(char **)(v8 + 272);
        if ( !v19 )
          v19 = &byte_629120;
        if ( (unsigned __int8)sub_4ADEF0(v19) )
        {
          v16 = *(char **)(v8 + 272);
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
      v39 = v38 - v21;
      v23 = v14 + a1[97];
      v42 = v23;
      v43 = v22;
      if ( v35 == a1[101] )
      {
        v24 = (_DWORD *)sub_49CB60(a1, 4);
        if ( v24 )
        {
          v41 = v24[1] - *v24;
          v25 = v24[3] - v24[2];
          v26 = sub_49D770(a1, 2);
          v27 = a1[97];
          v40 = v26;
          if ( v25 <= v27 )
            v28 = v27 - v25;
          else
            v28 = v25 - v27;
          v29 = v28 / 2;
          sub_49D7F0(a1, 2);
          sub_49D330(a1, 4, 0, v14 - v29, v14 - v29 + v25, v40, v40 + v41);
          v23 = v42;
          v22 = v43;
        }
      }
      sub_4B13F0(v14, v23, v22, v39);
      a2 = &v44;
      (*(void (__thiscall **)(int, _UNKNOWN **, int *, int *))(*(_DWORD *)v34 + 24))(v34, &retaddr, &v46, &v45);
      if ( v35 && v14 >= *a3 )
        v14 = *a3;
      *a3 = v14;
      if ( v35 && v23 <= *a4 )
        v23 = *a4;
      *a4 = v23;
      if ( v35 && v22 >= *a5 )
        v22 = *a5;
      *a5 = v22;
      if ( v35 )
      {
        v30 = *a6;
        if ( v36 > *a6 )
          v30 = v36;
      }
      else
      {
        v30 = v36;
      }
      *a6 = v30;
      v33 = *(_DWORD *)(v33 + 140);
      v37 = v39 - 1;
      ++v34;
      ++v35;
      if ( !v33 )
        return 0;
      v10 = v35;
      v8 = v33;
    }
  }
  return 0;
}
