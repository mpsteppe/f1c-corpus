int __thiscall sub_4A4AA0(int this, _DWORD *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  int v6; // eax
  int v7; // ecx
  int v8; // ecx
  int *v9; // eax
  int v10; // eax
  _DWORD **v11; // eax
  _DWORD *v12; // ecx
  _BYTE *v13; // ecx
  int v14; // eax
  _DWORD **v15; // eax
  int v16; // ecx
  __int64 v17; // rax
  double v18; // st7
  int v19; // ebp
  float v20; // edi
  int v21; // eax
  char **v23; // [esp-20h] [ebp-2Ch]
  int v24; // [esp-1Ch] [ebp-28h]
  int v25; // [esp+4h] [ebp-8h] BYREF
  int v26; // [esp+8h] [ebp-4h] BYREF

  *a4 = *(_DWORD *)(this + 12);
  *a5 = *(_DWORD *)(this + 16);
  *a2 = *(_DWORD *)(this + 4);
  *a3 = *(_DWORD *)(this + 8);
  v26 = 0;
  v25 = 0;
  sub_4AE870(&v26, &v25);
  v6 = sub_4A50D0(this);
  if ( v6 )
  {
    v7 = *(_DWORD *)(this + 272);
    if ( v7 )
    {
      if ( *(_BYTE *)(v6 + 44) )
        sub_4A4C90(v7, *(_DWORD *)(v6 + 12), *(_DWORD *)(v6 + 16));
    }
  }
  if ( *(_BYTE *)(this + 431) )
  {
    v8 = *(_DWORD *)(this + 416);
    if ( v8 >= 0 && v8 < *(_DWORD *)(this + 296) )
    {
      v9 = *(int **)(this + 284);
      if ( v8 <= 0 )
      {
LABEL_11:
        if ( v9 )
        {
          v10 = *v9;
          if ( v10 )
          {
            if ( *(_DWORD *)(this + 276) && *(_BYTE *)(v10 + 44) )
              sub_4A4C90(*(_DWORD *)(this + 272), *(_DWORD *)(v10 + 12), *(_DWORD *)(v10 + 16));
          }
        }
      }
      else
      {
        while ( v9 )
        {
          v9 = (int *)v9[1];
          if ( --v8 <= 0 )
            goto LABEL_11;
        }
      }
    }
  }
  v11 = *(_DWORD ***)(this + 284);
  *(_DWORD *)(this + 292) = v11;
  if ( v11 )
  {
    v12 = *v11;
    if ( *v11 )
    {
      do
      {
        sub_4A4660(
          v12,
          *(_DWORD *)(this + 336),
          *(_DWORD *)(this + 340),
          *(_DWORD *)(this + 368),
          *(_DWORD *)(this + 372));
        if ( v13[44] )
          (*(void (__thiscall **)(_BYTE *))(*(_DWORD *)v13 + 12))(v13);
        v14 = *(_DWORD *)(this + 292);
        if ( !v14 )
          break;
        v15 = *(_DWORD ***)(v14 + 4);
        *(_DWORD *)(this + 292) = v15;
        if ( !v15 )
          break;
        v12 = *v15;
      }
      while ( *v15 );
    }
  }
  if ( *(_DWORD *)(this + 308) == 4 )
    goto LABEL_30;
  v16 = *(_DWORD *)(this + 280);
  LODWORD(v17) = 0;
  if ( v16 )
  {
    v18 = 0.0;
    v19 = *(_DWORD *)(v16 + 20);
    v20 = *(float *)(v16 + 24);
    if ( *(_DWORD *)(this + 300) == 1 )
    {
      if ( *(_DWORD *)(this + 412) )
        v18 = (double)*(int *)(this + 408) / (double)*(int *)(this + 412);
      v17 = (__int64)((double)(*(_DWORD *)(this + 380) - *(_DWORD *)(this + 376) - LODWORD(v20)) * v18);
    }
    v24 = v17 + *(_DWORD *)(this + 376);
    v23 = *(char ***)(this + 344);
    v21 = sub_4AB570(&unk_765B00);
    sub_49CB80(*(char ***)(this + 280), 0, 0, v21, v23, v24, v19, v20, 0, 0);
LABEL_30:
    LODWORD(v17) = 0;
  }
  return v17;
}
