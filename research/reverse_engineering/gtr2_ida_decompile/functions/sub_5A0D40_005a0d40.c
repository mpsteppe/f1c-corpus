char __thiscall sub_5A0D40(_DWORD *this)
{
  void *v2; // eax
  int **v3; // edi
  DWORD v4; // eax
  int **v5; // esi
  int *v6; // eax
  bool v7; // zf
  int i; // eax
  int *v9; // eax
  int *v10; // eax
  _DWORD *v11; // edi
  u_short v12; // ax
  int v13; // ebp
  bool v14; // bl
  char v15; // al
  void *v16; // eax
  int **v17; // edi
  DWORD v18; // eax
  int *v19; // eax
  int v20; // esi
  int v21; // ebx
  int v22; // ebp
  int v23; // esi
  int *v24; // eax
  int *v25; // eax
  int v26; // ebx
  int v27; // ecx
  int *v28; // eax
  int v29; // edi
  char v30; // al
  int v31; // esi
  int v32; // eax
  void *v33; // eax
  int **v34; // ebx
  DWORD v35; // eax
  int *v36; // eax
  int v37; // esi
  int v38; // edi
  int v39; // eax
  _DWORD *v40; // edi
  int v41; // ebp
  int v42; // esi
  int *v43; // eax
  int *v44; // eax
  char v46; // [esp+3h] [ebp-2Dh]
  char v47; // [esp+6h] [ebp-2Ah]
  char v48; // [esp+7h] [ebp-29h]
  _DWORD *v49; // [esp+8h] [ebp-28h]
  int v50; // [esp+Ch] [ebp-24h]
  _DWORD *v51; // [esp+10h] [ebp-20h] BYREF
  _DWORD *v52; // [esp+14h] [ebp-1Ch]
  int v53; // [esp+18h] [ebp-18h] BYREF
  __int16 v54; // [esp+1Ch] [ebp-14h] BYREF
  u_short v55; // [esp+1Eh] [ebp-12h]
  u_long v56; // [esp+20h] [ebp-10h]

  v2 = (void *)this[694];
  v3 = (int **)(this + 690);
  v52 = this;
  HIBYTE(v51) = 0;
  if ( v2 && ((v4 = WaitForSingleObject(v2, this[695])) == 0 || v4 == 128) )
    v5 = v3;
  else
    v5 = 0;
  v6 = *v5;
  v7 = *v5 == 0;
  v5[2] = *v5;
  if ( !v7 )
  {
    for ( i = *v6; i; i = *v10 )
    {
      sub_59CA30(this, i, 0, 0);
      v9 = v5[2];
      if ( !v9 )
        break;
      v10 = (int *)v9[1];
      v5[2] = v10;
      if ( !v10 )
        break;
    }
  }
  if ( v3[4] )
    ReleaseMutex(v3[4]);
  if ( !(unsigned __int8)sub_5A59B0(this, &v53) )
    return 0;
  v11 = v51;
  while ( 1 )
  {
    v54 = 2;
    v56 = htonl(0);
    v12 = htons(0);
    v13 = v52[18];
    v55 = v12;
    v53 = v13;
    v14 = !v13 || *(_BYTE *)(v13 + 4);
    v15 = sub_5A6BF0(v52);
    if ( v14 && !v15 )
    {
      if ( sub_5A4330(v11) )
      {
        sub_5A4130();
        v16 = (void *)v11[701];
        v17 = (int **)(v11 + 697);
        if ( !v16 || (v18 = WaitForSingleObject(v16, (DWORD)v17[5])) != 0 && v18 != 128 )
          v17 = 0;
        v19 = *v17;
        v7 = *v17 == 0;
        v17[2] = *v17;
        if ( !v7 )
        {
          v20 = *v19;
          if ( *v19 )
          {
            do
            {
              v21 = (int)v52;
              v22 = sub_5A6E90(v20);
              if ( v22 != sub_5A4130() )
              {
                v23 = *(_DWORD *)(v20 + 28);
                if ( v23 )
                  sub_5A0970(v51, v21, v23);
              }
              v24 = v17[2];
              if ( !v24 )
                break;
              v25 = (int *)v24[1];
              v17[2] = v25;
              if ( !v25 )
                break;
              v20 = *v25;
            }
            while ( *v25 );
          }
        }
        if ( v51[701] )
          ReleaseMutex((HANDLE)v51[701]);
      }
      else
      {
        v55 = *((_WORD *)v11 + 1174);
        v56 = -1;
        sub_5A0970(v11, (int)v52, (int)&v54);
      }
      goto LABEL_84;
    }
    BYTE2(v50) = 1;
    if ( v15 )
    {
      v47 = sub_59D860();
      goto LABEL_83;
    }
    v26 = 0;
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)v13 + 28))(v13) > 0 )
    {
      while ( 1 )
      {
        v27 = v26;
        if ( v26 < 0 || v26 >= *(_DWORD *)(v13 + 20) )
          goto LABEL_46;
        v28 = *(int **)(v13 + 8);
        if ( v26 > 0 )
          break;
LABEL_45:
        if ( !v28 )
          goto LABEL_46;
        v29 = *v28;
LABEL_48:
        v30 = sub_5A0970(v51, (int)v52, v29);
        if ( BYTE2(v50) && v30 )
        {
          BYTE2(v50) = 1;
          if ( v29 )
          {
            v31 = *(_DWORD *)(v13 + 8);
            v32 = 0;
            if ( v31 )
            {
              while ( *(_DWORD *)v31 != v29 )
              {
                v32 = v31;
                v31 = *(_DWORD *)(v31 + 4);
                if ( !v31 )
                  goto LABEL_66;
              }
              if ( v31 == *(_DWORD *)(v13 + 16) )
                *(_DWORD *)(v13 + 16) = *(_DWORD *)(v31 + 4);
              if ( v32 )
                *(_DWORD *)(v32 + 4) = *(_DWORD *)(v31 + 4);
              else
                *(_DWORD *)(v13 + 8) = *(_DWORD *)(v31 + 4);
              if ( *(_DWORD *)(v13 + 12) == v31 )
                *(_DWORD *)(v13 + 12) = v32;
              --*(_DWORD *)(v13 + 20);
              if ( *(_BYTE *)(v31 + 8) )
                j__free(*(void **)v31);
              j__free((void *)v31);
            }
          }
        }
        else
        {
          BYTE2(v50) = 0;
        }
LABEL_66:
        if ( ++v26 >= (*(int (__thiscall **)(int))(*(_DWORD *)v13 + 28))(v13) )
          goto LABEL_67;
      }
      while ( v28 )
      {
        v28 = (int *)v28[1];
        if ( --v27 <= 0 )
          goto LABEL_45;
      }
LABEL_46:
      v29 = 0;
      goto LABEL_48;
    }
LABEL_67:
    v33 = (void *)v51[701];
    v34 = (int **)(v51 + 697);
    if ( !v33 || (v35 = WaitForSingleObject(v33, v51[702])) != 0 && v35 != 128 )
      v34 = 0;
    v36 = *v34;
    v7 = *v34 == 0;
    v34[2] = *v34;
    if ( !v7 )
    {
      v37 = *v36;
      if ( *v36 )
      {
        do
        {
          v38 = *(_DWORD *)v13;
          v39 = sub_5A6E90(v37);
          if ( (*(unsigned __int8 (__thiscall **)(int, int))(v38 + 16))(v13, v39) )
          {
            v40 = v51;
            v41 = sub_5A6E90(v37);
            if ( v41 != sub_5A4130() )
            {
              v42 = *(_DWORD *)(v37 + 28);
              if ( v42 )
                sub_5A0970((_DWORD *)v50, (int)v40, v42);
            }
            v13 = (int)v52;
          }
          v43 = v34[2];
          if ( !v43 )
            break;
          v44 = (int *)v43[1];
          v34[2] = v44;
          if ( !v44 )
            break;
          v37 = *v44;
        }
        while ( *v44 );
      }
    }
    if ( *(_DWORD *)(v50 + 2804) )
      ReleaseMutex(*(HANDLE *)(v50 + 2804));
LABEL_83:
    if ( !v47 )
      break;
LABEL_84:
    v11 = v51;
    (*(void (__thiscall **)(_DWORD *, _DWORD *))(*v51 + 92))(v51, v52);
    HIBYTE(v49) = 1;
    if ( !(unsigned __int8)sub_5A59B0(v11, &v51) )
      return v48;
  }
  if ( (unsigned __int8)sub_5A6A20() )
  {
    *(_DWORD *)(v50 + 76) = v49[407];
    sub_5A4760();
  }
  else
  {
    (*(void (**)(void))(*v49 + 92))();
  }
  return v46;
}
