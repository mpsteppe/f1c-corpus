int __thiscall sub_5E0740(void *this, const char *a2, int a3)
{
  void **v3; // esi
  void **v4; // eax
  FILE *v5; // eax
  FILE *v6; // edi
  void *v7; // eax
  int v9; // ebx
  FILE *v10; // eax
  FILE *v11; // edi
  void *v12; // eax
  int v13; // ebx
  FILE *v14; // eax
  FILE *v15; // edi
  void *v16; // eax
  int v17; // esi
  int v18; // esi
  void *v19; // [esp-28h] [ebp-640h]
  void *v20; // [esp-28h] [ebp-640h]
  void *v21; // [esp-28h] [ebp-640h]
  int v22; // [esp+10h] [ebp-608h]
  char String[765]; // [esp+18h] [ebp-600h] BYREF
  __int16 v25; // [esp+315h] [ebp-303h]
  char v26; // [esp+317h] [ebp-301h]
  char Buffer[765]; // [esp+318h] [ebp-300h] BYREF
  __int16 v28; // [esp+615h] [ebp-3h]
  char v29; // [esp+617h] [ebp-1h]

  v3 = 0;
  v22 = 0;
  if ( !a2 || !*a2 )
    return v22;
  v4 = (void **)operator new(0x10u);
  if ( v4 )
  {
    *v4 = 0;
    v4[1] = 0;
    v4[2] = 0;
    v4[3] = 0;
    v3 = v4;
  }
  memset(String, 0, sizeof(String));
  v25 = 0;
  v26 = 0;
  memset(Buffer, 0, sizeof(Buffer));
  v28 = 0;
  v29 = 0;
  v22 = (int)v3;
  sub_5D8EF0((int)String, a2, 767);
  _strupr(String);
  v5 = fopen(String, "rb");
  v6 = v5;
  if ( v5 )
  {
    fseek(v5, 0, 2);
    v3[2] = (void *)sub_634320(v6);
    fseek(v6, 0, 0);
    v7 = operator new((size_t)v3[2]);
    v19 = v3[2];
    *v3 = v7;
    sub_6318A2(v7, 1, v19, v6);
    fclose(v6);
    return v22;
  }
  if ( byte_910EFC )
  {
    dword_FB2874 = (int)dword_FB286C;
    if ( dword_FB286C )
    {
      v9 = *(_DWORD *)dword_FB286C;
      if ( *(_DWORD *)dword_FB286C )
      {
        while ( 1 )
        {
          sprintf(Buffer, "%s\\%s", (const char *)(v9 + 4), String);
          v10 = fopen(Buffer, "rb");
          v11 = v10;
          if ( v10 )
            break;
          if ( dword_FB2874 )
          {
            dword_FB2874 = *(_DWORD *)(dword_FB2874 + 4);
            if ( dword_FB2874 )
            {
              v9 = *(_DWORD *)dword_FB2874;
              if ( *(_DWORD *)dword_FB2874 )
                continue;
            }
          }
          goto LABEL_17;
        }
        fseek(v10, 0, 2);
        v3[2] = (void *)sub_634320(v11);
        fseek(v11, 0, 0);
        v12 = operator new((size_t)v3[2]);
        v20 = v3[2];
        *v3 = v12;
        sub_6318A2(v12, 1, v20, v11);
        fclose(v11);
        if ( v9 )
          return v22;
      }
    }
  }
LABEL_17:
  dword_FB27CC = (int)dword_FB27C4;
  if ( dword_FB27C4 )
  {
    v13 = *(_DWORD *)dword_FB27C4;
    if ( *(_DWORD *)dword_FB27C4 )
    {
      while ( 1 )
      {
        sprintf(Buffer, "%s\\%s", (const char *)(v13 + 4), String);
        v14 = fopen(Buffer, "rb");
        v15 = v14;
        if ( v14 )
          break;
        if ( dword_FB27CC )
        {
          dword_FB27CC = *(_DWORD *)(dword_FB27CC + 4);
          if ( dword_FB27CC )
          {
            v13 = *(_DWORD *)dword_FB27CC;
            if ( *(_DWORD *)dword_FB27CC )
              continue;
          }
        }
        goto LABEL_25;
      }
      fseek(v14, 0, 2);
      v3[2] = (void *)sub_634320(v15);
      fseek(v15, 0, 0);
      v16 = operator new((size_t)v3[2]);
      v21 = v3[2];
      *v3 = v16;
      sub_6318A2(v16, 1, v21, v15);
      fclose(v15);
      if ( v13 )
        return v22;
    }
  }
LABEL_25:
  if ( v3 )
  {
    if ( *v3 )
      j__free(*v3);
    if ( v3[1] )
      j__free(v3[1]);
    j__free(v3);
  }
  if ( byte_910EFC )
  {
    dword_FB27BC = dword_FB27B4;
    if ( dword_FB27B4 )
    {
      v17 = *(_DWORD *)dword_FB27B4;
      if ( *(_DWORD *)dword_FB27B4 )
      {
        while ( 1 )
        {
          v22 = sub_5EE620(v17, (char)String);
          if ( v22 )
            break;
          if ( dword_FB27BC )
          {
            dword_FB27BC = *(_DWORD *)(dword_FB27BC + 4);
            if ( dword_FB27BC )
            {
              v17 = *(_DWORD *)dword_FB27BC;
              if ( *(_DWORD *)dword_FB27BC )
                continue;
            }
          }
          goto LABEL_40;
        }
        if ( v17 )
          return v22;
      }
    }
  }
LABEL_40:
  dword_FB2854 = dword_FB284C;
  if ( dword_FB284C )
  {
    v18 = *(_DWORD *)dword_FB284C;
    if ( *(_DWORD *)dword_FB284C )
    {
      while ( 1 )
      {
        v22 = sub_5EE620(v18, (char)String);
        if ( v22 )
          break;
        if ( dword_FB2854 )
        {
          dword_FB2854 = *(_DWORD *)(dword_FB2854 + 4);
          if ( dword_FB2854 )
          {
            v18 = *(_DWORD *)dword_FB2854;
            if ( *(_DWORD *)dword_FB2854 )
              continue;
          }
        }
        goto LABEL_48;
      }
      if ( v18 )
        return v22;
    }
  }
LABEL_48:
  sub_5D8C80((int)this, (char *)0xFFFFFFFE, "Could not locate file %s", (char)String);
  return 0;
}
