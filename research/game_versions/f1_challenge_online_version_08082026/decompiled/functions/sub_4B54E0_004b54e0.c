int __thiscall sub_4B54E0(int this, int a2)
{
  int v2; // ebp
  int *v4; // eax
  char v5; // cl
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  int *v9; // eax
  int v10; // eax
  int v11; // esi
  int v12; // eax
  int v13; // eax
  int v15; // [esp-8h] [ebp-20h]
  char v16; // [esp+13h] [ebp-5h]

  v2 = a2;
  v4 = *(int **)(this + 32);
  v5 = *(_BYTE *)(a2 + 8);
  v6 = (*(_DWORD *)a2 >> 18) & 0x3F;
  v16 = v5;
  *(_DWORD *)(this + 40) = v4;
  if ( v4 && (v7 = *v4) != 0 )
  {
    while ( v6 != *(_DWORD *)(v7 + 872) || v5 != *(_BYTE *)(v7 + 876) )
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
      if ( !(unsigned __int8)sub_4BA7A0(v15, 1) )
        v11 = 0;
    }
    if ( !v11 )
    {
      if ( sub_587C03(4) )
        v12 = sub_4BA980(0);
      else
        v12 = 0;
      sub_4BAD70(v12, 0);
      v11 = sub_4BAE20(this + 16);
    }
    sub_4FFFA0(v11);
    *(_BYTE *)(v11 + 876) = -1;
    *(_DWORD *)(v11 + 872) = 0;
    *(_DWORD *)(v11 + 880) = -51331646;
    *(_DWORD *)(v11 + 872) = v6;
    *(_BYTE *)(v11 + 876) = v16;
    *(_DWORD *)(v11 + 880) = *(_DWORD *)(this + 48);
    v13 = sub_587C03(12);
    if ( v13 )
    {
      *(_DWORD *)v13 = v11;
      *(_DWORD *)(v13 + 4) = 0;
      *(_BYTE *)(v13 + 8) = 0;
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
  return sub_4FFFB0(*(float *)(this + 48), v2);
}
