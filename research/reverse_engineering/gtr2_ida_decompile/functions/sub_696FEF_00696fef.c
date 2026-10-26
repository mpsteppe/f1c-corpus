int __thiscall sub_696FEF(void *this, int a2, const char *ArgList, int *a4, int *a5, int a6)
{
  int *v6; // esi
  int *v7; // edi
  int v8; // ecx
  int v9; // eax
  const char *v10; // edi
  _DWORD *v11; // ebx
  unsigned int v13; // eax
  int v14; // edi
  bool v15; // zf
  unsigned int v16; // eax
  int v17; // esi
  int v18; // edi
  int v19; // esi
  int v20; // esi
  unsigned int v21; // ebx
  unsigned int v22; // esi
  char v23[256]; // [esp+Ch] [ebp-24Ch] BYREF
  char v24[256]; // [esp+10Ch] [ebp-14Ch] BYREF
  int v25[4]; // [esp+20Ch] [ebp-4Ch] BYREF
  int v26; // [esp+21Ch] [ebp-3Ch]
  int v27; // [esp+224h] [ebp-34h]
  int v28; // [esp+228h] [ebp-30h]
  int v29[4]; // [esp+230h] [ebp-28h] BYREF
  int v30; // [esp+240h] [ebp-18h]
  int v31; // [esp+248h] [ebp-10h]
  int v32; // [esp+24Ch] [ebp-Ch]
  int v33; // [esp+254h] [ebp-4h]

  v33 = (int)this;
  if ( a6 )
    goto LABEL_68;
  v6 = a4;
  if ( !a4 )
    goto LABEL_68;
  if ( !a5 )
  {
LABEL_17:
    v10 = "implicitly ";
    goto LABEL_18;
  }
  sub_67F2AD(v29);
  sub_67F2AD(v25);
  if ( a4[1] != 9 )
  {
    v6 = v29;
    v30 = 4;
    v31 = 1;
    v32 = sub_6951CB((_DWORD *)v33, a4);
    if ( sub_695154((_DWORD *)v33, a4) )
      v30 = 1;
  }
  v7 = a5;
  if ( a5[1] != 9 )
  {
    v7 = v25;
    v26 = 4;
    v27 = 1;
    v28 = sub_6951CB((_DWORD *)v33, a5);
    if ( sub_695154((_DWORD *)v33, a5) )
      v26 = 1;
  }
  v8 = v6[4];
  if ( v8 == 4 || (v9 = v7[4], v9 == 4) )
  {
    v21 = v6[6] * v6[7];
    if ( v21 > v7[6] * v7[7] )
      goto LABEL_17;
    v22 = 0;
    if ( v21 )
    {
      while ( sub_6955DE((_DWORD *)v33, (int)a4, v22, v29) >= 0
           && sub_6955DE((_DWORD *)v33, (int)a5, v22, v25) >= 0
           && sub_696CB7((void *)v33, v29, v25, 1) )
      {
        if ( ++v22 >= v21 )
          goto LABEL_68;
      }
      goto LABEL_17;
    }
    goto LABEL_68;
  }
  if ( !v8 )
    goto LABEL_42;
  if ( v8 != 1 )
  {
    if ( v8 == 2 )
    {
      if ( !v9 )
        goto LABEL_68;
      if ( v9 != 1 )
      {
        if ( v9 == 2 )
        {
          if ( v6[6] > (unsigned int)v7[6] || v6[7] > (unsigned int)v7[7] )
            goto LABEL_17;
          goto LABEL_68;
        }
        goto LABEL_42;
      }
      v16 = v6[6];
      if ( v16 == 1 && v6[7] > (unsigned int)v7[7] )
        goto LABEL_17;
      v17 = v6[7];
      if ( v17 == 1 && v16 > v7[7] )
        goto LABEL_17;
      if ( v16 == 1 || v17 == 1 )
        goto LABEL_68;
      v15 = v17 * v16 == v7[7];
    }
    else
    {
      if ( v8 != 3 )
        goto LABEL_68;
      if ( v9 != 3 )
        goto LABEL_17;
      v18 = v7[5];
      switch ( v18 )
      {
        case 13:
          goto LABEL_68;
        case 15:
          v19 = v6[5];
          if ( v19 == 15 || v19 == 16 || v19 == 17 || v19 == 18 )
            goto LABEL_68;
          v15 = v19 == 19;
          break;
        case 20:
          v20 = v6[5];
          if ( v20 == 20 || v20 == 21 || v20 == 22 || v20 == 23 )
            goto LABEL_68;
          v15 = v20 == 24;
          break;
        default:
          v15 = v6[5] == v18;
          break;
      }
    }
LABEL_59:
    if ( !v15 )
      goto LABEL_17;
    goto LABEL_68;
  }
  if ( !v9 )
    goto LABEL_68;
  if ( v9 != 1 )
  {
    if ( v9 == 2 )
    {
      v13 = v7[6];
      if ( v13 == 1 && v6[7] > (unsigned int)v7[7] )
        goto LABEL_17;
      v14 = v7[7];
      if ( v14 == 1 && v6[7] > v13 )
        goto LABEL_17;
      if ( v13 == 1 || v14 == 1 )
        goto LABEL_68;
      v15 = v14 * v13 == v6[7];
      goto LABEL_59;
    }
LABEL_42:
    if ( v9 == 3 )
      goto LABEL_17;
    goto LABEL_68;
  }
  if ( v6[7] > (unsigned int)v7[7] )
    goto LABEL_17;
LABEL_68:
  v10 = WindowName;
LABEL_18:
  v11 = (_DWORD *)v33;
  sub_69530B((_DWORD *)v33, v24, 0xFFu, (int)a4);
  sub_69530B(v11, v23, 0xFFu, (int)a5);
  if ( ArgList )
    return sub_694B97((int)v11, a2, 3017, "'%s': cannot %sconvert from '%s' to '%s'", ArgList, v10, v23, v24);
  else
    return sub_694B97((int)v11, a2, 3017, "cannot %sconvert from '%s' to '%s'", v10, v23, v24);
}
