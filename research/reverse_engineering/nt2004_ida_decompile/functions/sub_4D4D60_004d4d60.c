int __thiscall sub_4D4D60(int this, int a2)
{
  int v2; // ebp
  char v4; // cl
  int v5; // esi
  int *v6; // eax
  int v7; // eax
  int v8; // eax
  int *v9; // eax
  int v10; // eax
  int v11; // esi
  int v12; // eax
  int *v13; // eax
  int v15; // [esp-8h] [ebp-1Ch]
  char v16; // [esp+Fh] [ebp-5h]
  int v17; // [esp+10h] [ebp-4h]

  v2 = a2;
  v4 = *(_BYTE *)(a2 + 8);
  v16 = v4;
  v5 = *(_BYTE *)(a2 + 2) & 0x3F;
  v6 = *(int **)(this + 32);
  v17 = v5;
  *(_DWORD *)(this + 40) = v6;
  if ( v6 && (v7 = *v6) != 0 )
  {
    while ( v5 != *(_DWORD *)(v7 + 424) || v4 != *(_BYTE *)(v7 + 428) )
    {
      v8 = *(_DWORD *)(this + 40);
      if ( v8 )
        *(_DWORD *)(this + 40) = *(_DWORD *)(v8 + 4);
      v9 = *(int **)(this + 40);
      if ( v9 )
      {
        v7 = *v9;
        if ( v7 )
          continue;
      }
      goto LABEL_9;
    }
  }
  else
  {
LABEL_9:
    v10 = *(_DWORD *)(this + 16);
    v11 = 0;
    *(_DWORD *)(this + 24) = v10;
    if ( v10 )
    {
      v11 = *(_DWORD *)v10;
      v15 = *(_DWORD *)v10;
      *(_BYTE *)(v10 + 8) = 0;
      if ( !(unsigned __int8)sub_4DADA0(v15, 1) )
        v11 = 0;
    }
    if ( !v11 )
    {
      if ( operator new(4u) )
        v12 = sub_4DAFD0(0);
      else
        v12 = 0;
      sub_4DB630(v12, 0);
      v11 = sub_4DB6E0(this + 16);
    }
    sub_52E5C0(v11);
    *(_DWORD *)(v11 + 424) = 0;
    *(_BYTE *)(v11 + 428) = -1;
    *(_DWORD *)(v11 + 432) = -51331646;
    *(_DWORD *)(v11 + 424) = v17;
    *(_BYTE *)(v11 + 428) = v16;
    *(_DWORD *)(v11 + 432) = *(_DWORD *)(this + 48);
    v13 = (int *)operator new(0xCu);
    if ( v13 )
    {
      *v13 = v11;
      v13[1] = 0;
      *((_BYTE *)v13 + 8) = 0;
    }
    else
    {
      v13 = 0;
    }
    if ( *(_DWORD *)(this + 32) )
    {
      *(_DWORD *)(*(_DWORD *)(this + 36) + 4) = v13;
    }
    else
    {
      *(_DWORD *)(this + 32) = v13;
      *(_DWORD *)(this + 40) = v13;
    }
    v2 = a2;
    *(_DWORD *)(this + 36) = v13;
    ++*(_DWORD *)(this + 44);
  }
  return sub_52E5D0(*(float *)(this + 48), v2);
}
