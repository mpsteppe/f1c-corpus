int __thiscall sub_4D8800(int this, _DWORD *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  int v6; // ecx
  int *v7; // eax
  int v8; // eax
  int v9; // eax
  int *v10; // eax
  int v11; // ecx
  int v12; // edx
  int v13; // edi
  int v14; // ebp
  char v15; // al
  int v16; // eax
  int *v17; // eax
  int v18; // ecx
  unsigned __int64 v19; // rax
  int v20; // ebp
  double v21; // st7
  int v22; // eax
  int v24; // [esp-34h] [ebp-48h]
  int v25; // [esp-30h] [ebp-44h]
  int v26; // [esp-1Ch] [ebp-30h]
  int v27; // [esp-18h] [ebp-2Ch]
  int v28; // [esp-14h] [ebp-28h]
  int v29; // [esp-10h] [ebp-24h]
  int v30; // [esp-Ch] [ebp-20h]
  int v31; // [esp-8h] [ebp-1Ch]
  int v32; // [esp-4h] [ebp-18h]
  int v33; // [esp+Ch] [ebp-8h] BYREF
  int v34; // [esp+10h] [ebp-4h] BYREF

  *a4 = *(_DWORD *)(this + 12);
  *a5 = *(_DWORD *)(this + 16);
  *a2 = *(_DWORD *)(this + 4);
  *a3 = *(_DWORD *)(this + 8);
  v34 = 0;
  v33 = 0;
  sub_4DE540(&v34, &v33);
  v6 = *(_DWORD *)(this + 420);
  if ( v6 >= 0 && v6 < *(_DWORD *)(this + 296) )
  {
    v7 = *(int **)(this + 284);
    if ( v6 <= 0 )
    {
LABEL_6:
      if ( v7 )
      {
        v8 = *v7;
        if ( v8 )
        {
          if ( *(_DWORD *)(this + 272) && *(_BYTE *)(v8 + 44) )
          {
            v32 = *(_DWORD *)(v8 + 16);
            v31 = *(_DWORD *)(v8 + 12);
            v30 = *(_DWORD *)(this + 272);
            sub_4D7830();
          }
        }
      }
    }
    else
    {
      while ( v7 )
      {
        v7 = (int *)v7[1];
        if ( --v6 <= 0 )
          goto LABEL_6;
      }
    }
  }
  if ( *(_BYTE *)(this + 431) )
  {
    v29 = *(_DWORD *)(this + 416);
    v9 = sub_49EE60();
    if ( v9 )
    {
      if ( *(_DWORD *)(this + 276) && *(_BYTE *)(v9 + 44) )
      {
        v28 = *(_DWORD *)(v9 + 16);
        v27 = *(_DWORD *)(v9 + 12);
        v26 = *(_DWORD *)(this + 272);
        sub_4D7830();
      }
    }
  }
  v10 = *(int **)(this + 284);
  *(_DWORD *)(this + 292) = v10;
  if ( v10 )
  {
    v11 = *v10;
    if ( *v10 )
    {
      do
      {
        v12 = *(_DWORD *)(this + 340);
        v13 = *(_DWORD *)(this + 336);
        v14 = *(_DWORD *)(this + 368);
        *(_DWORD *)(v11 + 32) = *(_DWORD *)(this + 372);
        v15 = *(_BYTE *)(v11 + 44);
        *(_DWORD *)(v11 + 28) = v14;
        *(_DWORD *)(v11 + 36) = v13;
        *(_DWORD *)(v11 + 40) = v12;
        if ( v15 )
          (*(void (__thiscall **)(int, int, int, int, int, int, int, int))(*(_DWORD *)v11 + 12))(
            v11,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32);
        v16 = *(_DWORD *)(this + 292);
        if ( !v16 )
          break;
        v17 = *(int **)(v16 + 4);
        *(_DWORD *)(this + 292) = v17;
        if ( !v17 )
          break;
        v11 = *v17;
      }
      while ( *v17 );
    }
  }
  if ( *(_DWORD *)(this + 308) == 4 )
    goto LABEL_30;
  v18 = *(_DWORD *)(this + 280);
  LODWORD(v19) = 0;
  if ( v18 )
  {
    v20 = *(_DWORD *)(v18 + 20);
    v21 = 0.0;
    if ( *(_DWORD *)(this + 300) == 1 )
    {
      if ( *(_DWORD *)(this + 412) )
        v21 = (double)*(int *)(this + 408) / (double)*(int *)(this + 412);
      v19 = (unsigned __int64)((double)(*(_DWORD *)(this + 380) - *(_DWORD *)(this + 376) - *(_DWORD *)(v18 + 24)) * v21);
    }
    v25 = v19 + *(_DWORD *)(this + 376);
    v24 = *(_DWORD *)(this + 344);
    v22 = sub_4DDFE0(&unk_B6E2A0, v24);
    sub_4D5E10((void *)this, *(_DWORD *)(this + 280), 0, 0, v22, v24, v25, v20);
LABEL_30:
    LODWORD(v19) = 0;
  }
  return v19;
}
