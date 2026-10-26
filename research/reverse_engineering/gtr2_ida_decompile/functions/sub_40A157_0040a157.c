int __thiscall sub_40A157(float *this)
{
  float *v1; // ebp
  int v2; // eax
  int v3; // ecx
  int result; // eax
  float *v5; // edx
  int *v6; // eax
  char v7; // bl
  int v8; // esi
  double v9; // st7
  int v10; // eax
  int *v11; // eax
  char *v12; // eax
  char v13; // cl
  char *v14; // eax
  char v15; // cl
  char *v16; // eax
  char v17; // cl
  char *v18; // eax
  char v19; // cl
  int v20; // edi
  char *v21; // ebp
  char *v22; // esi
  const char *v23; // eax
  char *v24; // ebx
  const char *v25; // eax
  char *v26; // edi
  int v27; // ebx
  int v28; // eax
  bool v29; // zf
  char *v30; // [esp+18h] [ebp-E8h]
  char *v31; // [esp+2Ch] [ebp-D4h]
  float *v32; // [esp+30h] [ebp-D0h]
  float *v33; // [esp+34h] [ebp-CCh]
  int v34; // [esp+38h] [ebp-C8h]
  _BYTE v35[5]; // [esp+3Ch] [ebp-C4h] BYREF
  __int64 v36; // [esp+41h] [ebp-BFh]
  int v37; // [esp+49h] [ebp-B7h]
  int v38; // [esp+4Dh] [ebp-B3h]
  int v39; // [esp+51h] [ebp-AFh]
  int v40; // [esp+55h] [ebp-ABh]
  __int16 v41; // [esp+59h] [ebp-A7h]
  char v42; // [esp+5Bh] [ebp-A5h]
  char v43; // [esp+5Ch] [ebp-A4h] BYREF
  int v44; // [esp+5Dh] [ebp-A3h]
  int v45; // [esp+61h] [ebp-9Fh]
  int v46; // [esp+65h] [ebp-9Bh]
  int v47; // [esp+69h] [ebp-97h]
  int v48; // [esp+6Dh] [ebp-93h]
  int v49; // [esp+71h] [ebp-8Fh]
  int v50; // [esp+75h] [ebp-8Bh]
  __int16 v51; // [esp+79h] [ebp-87h]
  char v52; // [esp+7Bh] [ebp-85h]
  char String2[61]; // [esp+80h] [ebp-80h] BYREF
  __int16 v55; // [esp+BDh] [ebp-43h]
  char v56; // [esp+BFh] [ebp-41h]
  _BYTE v57[61]; // [esp+C0h] [ebp-40h] BYREF
  __int16 v58; // [esp+FDh] [ebp-3h]
  char v59; // [esp+FFh] [ebp-1h]

  v1 = this;
  v2 = *((_DWORD *)this + 723229);
  v33 = this;
  if ( v2 )
    v3 = *((_DWORD *)this + 723231);
  else
    v3 = 0;
  if ( v2 )
    result = *((_DWORD *)v1 + 723231) + 1;
  else
    result = 104;
  if ( v3 < result )
  {
    v31 = (char *)&unk_9204A0 + 22616 * v3;
    v5 = &v1[4 * v3 + 16];
    v32 = v5;
    v34 = result - v3;
    while ( 1 )
    {
      memset(String2, 0, sizeof(String2));
      v55 = 0;
      v56 = 0;
      memset(v57, 0, sizeof(v57));
      v58 = 0;
      v59 = 0;
      v44 = 0;
      v45 = 0;
      v46 = 0;
      v36 = 0;
      v47 = 0;
      v48 = 0;
      v37 = 0;
      v49 = 0;
      v38 = 0;
      v50 = 0;
      v51 = 0;
      v39 = 0;
      v52 = 0;
      memset(v35, 0, sizeof(v35));
      v6 = *(int **)v5;
      v40 = 0;
      v41 = 0;
      v7 = 0;
      v43 = 0;
      v42 = 0;
      *((_DWORD *)v5 + 2) = v6;
      if ( v6 )
      {
        v8 = *v6;
        if ( *v6 )
        {
          while ( 1 )
          {
            v9 = v1[723213];
            if ( (*(_DWORD *)(v8 + 196) == -190986834 || v9 >= *(float *)(v8 + 196))
              && (*(_DWORD *)(v8 + 200) == -190986834 || v9 <= *(float *)(v8 + 200)) )
            {
              break;
            }
            v10 = *((_DWORD *)v5 + 2);
            if ( v10 )
              v5[2] = *(float *)(v10 + 4);
            v11 = (int *)*((_DWORD *)v5 + 2);
            if ( !v11 )
              goto LABEL_21;
            v8 = *v11;
            if ( !*v11 )
              goto LABEL_33;
          }
          v12 = (char *)(v8 + 65);
          do
          {
            v13 = *v12;
            String2[(_DWORD)v12 - 65 - v8] = *v12;
            ++v12;
          }
          while ( v13 );
          v14 = (char *)(v8 + 129);
          do
          {
            v15 = *v14;
            v57[(_DWORD)v14 - 129 - v8] = *v14;
            ++v14;
          }
          while ( v15 );
          v16 = (char *)(v8 + 1);
          do
          {
            v17 = *v16;
            v16[(_DWORD)(&v43 - v8 - 1)] = *v16;
            ++v16;
          }
          while ( v17 );
          v18 = (char *)(v8 + 33);
          do
          {
            v19 = *v18;
            v35[(_DWORD)v18 - 33 - v8] = *v18;
            ++v18;
          }
          while ( v19 );
          if ( *((_DWORD *)v1 + 723229) )
            v7 = 1;
          else
            v7 = *(_BYTE *)(v8 + 204);
        }
      }
      else
      {
LABEL_21:
        v8 = 0;
      }
LABEL_33:
      v20 = *((_DWORD *)v31 + 678);
      v21 = v31 + 2856;
      if ( strlen(String2) )
      {
        v30 = String2;
        v23 = (const char *)sub_53E440(v31);
        if ( _stricmp(v23, v30) || !v20 || v7 != v21[11960] )
        {
          v24 = v31;
          sub_53FFB0(v31, String2);
          sub_615860(v57);
          v30 = String2;
          v25 = (const char *)sub_53E440(v24);
          if ( !_stricmp(v25, v30) )
          {
            if ( v20 )
            {
              v26 = v24;
              sub_53F7C0(v24);
              sub_53FFB0(v24, &String2[16]);
              sub_615860(&v57[16]);
            }
            else
            {
              ++dword_757C10;
              sub_42CC30(&unk_920488);
              v26 = *(char **)v35;
            }
            v27 = *(_DWORD *)((char *)&v36 + 3);
            if ( *(_DWORD *)(*(_DWORD *)((char *)&v36 + 3) + 2892916) || (v28 = 3, *(_BYTE *)(v8 + 204)) )
              v28 = 4;
            sub_53E6A0(v26, v28);
            sub_53F5D0(v26, 1, 1);
            sub_53E6F0(COERCE_FLOAT(1));
            sub_52B7E0(v21 + 16416);
            sub_53E6A0(v26, (*(_DWORD *)(v27 + 2892916) != 0) + 3);
          }
        }
      }
      else if ( v20 )
      {
        v22 = v31;
        sub_53F7C0(v31);
        sub_53E6A0(v22, -1);
        --dword_757C10;
        sub_42CC30(&unk_920488);
      }
      if ( strcmp(v21 + 18712, &v43) )
        sub_53F530(v31, 0, &v43, 1);
      if ( strcmp(v21 + 18820, v35) )
        sub_53F530(v31, 1, v35, 1);
      result = v34 - 1;
      v29 = v34 == 1;
      v32 += 4;
      v31 += 22616;
      --v34;
      if ( v29 )
        break;
      v5 = v32;
      v1 = v33;
    }
  }
  return result;
}
