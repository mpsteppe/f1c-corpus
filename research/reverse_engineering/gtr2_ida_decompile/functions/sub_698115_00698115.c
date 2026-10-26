int __thiscall sub_698115(void *this, int a2, int a3, int a4, char a5)
{
  int v5; // eax
  int v6; // edi
  int v7; // eax
  int v8; // ecx
  int v9; // esi
  int v10; // eax
  int *v11; // ebx
  int v12; // eax
  int v13; // eax
  int v15; // [esp+Ch] [ebp-20h] BYREF
  int v16; // [esp+10h] [ebp-1Ch]
  int v17; // [esp+18h] [ebp-14h] BYREF
  int v18; // [esp+1Ch] [ebp-10h]
  int v19; // [esp+24h] [ebp-8h]
  int v20; // [esp+28h] [ebp-4h]
  int *v22; // [esp+38h] [ebp+Ch]

  v19 = (int)this;
  v20 = 0;
  if ( a3 && (v5 = *(_DWORD *)(a2 + 28)) != 0 )
  {
    if ( sub_6460B4(*(const char **)(v5 + 24), 0, &v17) >= 0 && sub_6460B4(*(const char **)(a3 + 24), 0, &v15) >= 0 )
    {
      if ( v18 == v16 )
        goto LABEL_14;
      if ( ((v18 ^ v16) & 0xFFFF0000) == 0 && (!(_WORD)v18 || !(_WORD)v16) )
      {
        v20 = ((unsigned __int16)v16 == 0) + 1;
        goto LABEL_14;
      }
      return -1;
    }
    if ( strcmp(*(const char **)(a3 + 24), *(const char **)(*(_DWORD *)(a2 + 28) + 24)) )
      return -1;
  }
  else if ( (a3 == 0) != (*(_DWORD *)(a2 + 28) == 0) )
  {
    v20 = 2;
  }
LABEL_14:
  v6 = *(_DWORD *)(a2 + 36);
  while ( v6 )
  {
    v7 = *(_DWORD *)(v6 + 8);
    v6 = *(_DWORD *)(v6 + 12);
    v8 = 0;
    if ( v6 && *(_DWORD *)(*(_DWORD *)(v6 + 8) + 4) == 12 )
    {
      v6 = *(_DWORD *)(v6 + 12);
      v8 = 1;
    }
    if ( (a5 & 0x10) == 0 || (*(_BYTE *)(*(_DWORD *)(v7 + 24) + 28) & 0x40) != 0 )
    {
      if ( a4 )
      {
        v9 = *(_DWORD *)(v7 + 24);
        v10 = *(_DWORD *)(a4 + 8);
        v11 = *(int **)(v9 + 32);
        if ( v10 )
          v22 = *(int **)(v10 + 16);
        else
          v22 = 0;
        if ( (*(_BYTE *)(v9 + 28) & 0x10) != 0 )
        {
          if ( !sub_696CB7((void *)v19, v11, v22, 0) )
            return -1;
          v12 = sub_696AE1((_DWORD *)v19, v11, v22);
          v20 += v12;
        }
        if ( (*(_BYTE *)(v9 + 28) & 0x20) != 0 )
        {
          if ( sub_6950BD((_DWORD *)v19, v22) || !sub_696CB7((void *)v19, v22, v11, 0) )
            return -1;
          v13 = sub_696AE1((_DWORD *)v19, v22, v11);
          v20 += v13;
        }
        a4 = *(_DWORD *)(a4 + 12);
      }
      else if ( !v8 )
      {
        return -1;
      }
    }
  }
  if ( a4 )
    return -1;
  return v20;
}
