int __thiscall sub_6ACD31(int this)
{
  bool v2; // zf
  int *v4; // eax
  _DWORD *v5; // edx
  int v6; // ebx
  int v7; // ecx
  int v8; // edx
  unsigned int i; // edx
  int *v10; // eax
  int v11; // ecx
  int *v12; // ecx
  int v13; // edi
  int v14; // eax
  unsigned int j; // eax
  int v16[4]; // [esp+8h] [ebp-2Ch] BYREF
  int v17[4]; // [esp+18h] [ebp-1Ch] BYREF
  int v18; // [esp+28h] [ebp-Ch]
  unsigned int v19; // [esp+2Ch] [ebp-8h]
  int v20; // [esp+30h] [ebp-4h]

  v2 = *(_DWORD *)(this + 76) == 4;
  v18 = 0;
  if ( !v2 )
    return -2147467259;
  memset(v17, 0, sizeof(v17));
  memset(v16, 0, sizeof(v16));
  v20 = 0;
  v19 = 0;
  do
  {
    v4 = (int *)(*(_DWORD *)(this + 560) + 4 * v19);
    v5 = (_DWORD *)*v4;
    if ( *v4 && *v5 )
    {
      if ( (*v5 & 0xFFF00000) == 0x72100000 )
      {
        v7 = *v4;
      }
      else
      {
        v6 = 0;
        if ( (*v5 & 0xFFF00000) != 0x11000000 )
          v6 = *v5 & 0xFFFFF;
        v7 = *v4;
        if ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *(_DWORD *)(v5[2] + 4 * v6)) + 4) == *(_DWORD *)(this + 136) )
        {
          v8 = v20++;
          v16[v8] = v7;
LABEL_13:
          *v4 = 0;
          goto LABEL_14;
        }
      }
      v17[v19] = v7;
      goto LABEL_13;
    }
LABEL_14:
    ++v19;
  }
  while ( v19 < *(_DWORD *)(this + 76) );
  for ( i = 0; i < *(_DWORD *)(this + 76); ++i )
  {
    v10 = (int *)(*(_DWORD *)(this + 556) + 4 * i);
    if ( *v10 )
    {
      v11 = *(_DWORD *)*v10;
      if ( v11 )
      {
        if ( (v11 & 0xFFF00000) != 0x72100000 )
        {
          v12 = &v17[i];
          if ( *v12 )
          {
            v13 = -2147467259;
            goto LABEL_36;
          }
          *v12 = *v10;
          *v10 = 0;
        }
      }
    }
  }
  if ( (unsigned __int16)*(_DWORD *)(this + 200) > 0x101u )
  {
    v13 = sub_6AA1A9((_DWORD *)this, (int **)v16, v20, (int)v17, 1u);
    if ( v13 < 0 )
      goto LABEL_36;
  }
  v13 = sub_6AA1A9((_DWORD *)this, (int **)v16, v20, (int)v17, 2u);
  if ( v13 < 0 )
    goto LABEL_36;
  v13 = sub_6AA1A9((_DWORD *)this, (int **)v16, v20, (int)v17, 3u);
  if ( v13 < 0 )
    goto LABEL_36;
  v13 = sub_6A9CD5((_DWORD *)this, (int)v16, v20, (int)v17);
  if ( v13 < 0 )
    goto LABEL_36;
  v2 = *(_DWORD *)(this + 76) == 0;
  v19 = 0;
  if ( !v2 )
  {
    do
    {
      v14 = v16[v19];
      if ( v14 )
      {
        v13 = -2147467259;
        sub_686791(
          this,
          *(_DWORD *)(v14 + 60),
          4523,
          "cannot map this dependent texture read to ps_1_%i",
          (unsigned __int8)*(_DWORD *)(this + 200));
        v18 = 1;
      }
      ++v19;
    }
    while ( v19 < *(_DWORD *)(this + 76) );
  }
  if ( v13 != -2147467259 )
  {
    for ( j = 0; j < *(_DWORD *)(this + 76); ++j )
      *(_DWORD *)(*(_DWORD *)(this + 560) + 4 * j) = v17[j];
    j__free(*(void **)(this + 556));
    *(_DWORD *)(this + 556) = 0;
    *(_DWORD *)(this + 544) = 0;
    v13 = 0;
  }
  if ( v13 < 0 )
  {
LABEL_36:
    if ( !v18 )
      sub_686791(
        this,
        0,
        4523,
        "shader cannot compile to a ps_1_%i shader because this model can't match all the dependent texture read(s) this shader requires",
        (unsigned __int8)*(_DWORD *)(this + 200));
  }
  return v13;
}
