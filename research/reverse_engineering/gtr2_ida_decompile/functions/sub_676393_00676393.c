int __thiscall sub_676393(int this, unsigned int a2)
{
  unsigned __int16 v3; // cx
  void *v5; // edi
  int v6; // eax
  bool v7; // zf
  _DWORD *v8; // eax
  _DWORD *v9; // esi
  __int16 v10; // ax
  unsigned __int16 v11; // dx
  unsigned __int16 v12; // cx
  unsigned __int16 v13; // si
  int v14; // ecx
  int v15; // eax
  int v16; // esi
  int *v17; // eax
  _DWORD *v18; // eax
  int v19; // ecx
  int v20; // esi
  void *v21; // ecx
  _DWORD v22[5]; // [esp+8h] [ebp-18h] BYREF
  int v23; // [esp+1Ch] [ebp-4h]

  v3 = *(_WORD *)(*(_DWORD *)(this + 24) + 8);
  if ( a2 >= v3 )
    return 0;
  if ( v3 == 1 )
    return this;
  if ( !*(_DWORD *)(this + 60) )
  {
    v5 = operator new(4 * v3);
    *(_DWORD *)(this + 60) = v5;
    if ( !v5 )
      return 0;
    memset(v5, 0, 4 * *(unsigned __int16 *)(*(_DWORD *)(this + 24) + 8));
  }
  v6 = 4 * a2;
  v7 = *(_DWORD *)(4 * a2 + *(_DWORD *)(this + 60)) == 0;
  v23 = 4 * a2;
  if ( v7 )
  {
    if ( !*(_DWORD *)(this + 64) )
    {
      v8 = operator new(0x10u);
      *(_DWORD *)(this + 64) = v8;
      if ( !v8 )
        return 0;
      v9 = *(_DWORD **)(this + 24);
      *v8 = *v9++;
      v8[1] = *v9++;
      v8[2] = *v9;
      v8[3] = v9[1];
      *(_WORD *)(*(_DWORD *)(this + 64) + 8) = 1;
    }
    v10 = a2 * *(_WORD *)(this + 44);
    v11 = *(_WORD *)(this + 10);
    qmemcpy(v22, (const void *)(this + 4), sizeof(v22));
    v12 = *(_WORD *)(this + 12);
    v13 = *(_WORD *)(this + 44);
    HIWORD(v22[1]) = v11 + v10;
    LOWORD(v22[2]) = v13;
    if ( v13 > v11 + v12 - (unsigned __int16)(v11 + v10) )
      LOWORD(v22[2]) = v11 + v12 - HIWORD(v22[1]);
    v14 = *(_DWORD *)(this + 20);
    v15 = *(_WORD *)(this + 8) != 0 ? 4 : 1;
    if ( v14 )
      v22[4] = v14 + 4 * a2 * v15 * *(_DWORD *)(this + 44);
    v16 = *(_DWORD *)(this + 32) + 4 * a2 * v15 * *(_DWORD *)(this + 44);
    v17 = (int *)operator new(0x44u);
    if ( v17 )
      v18 = sub_6734BB(v17, *(_DWORD *)this, v22, *(_DWORD *)(this + 64), *(_DWORD *)(this + 28), v16);
    else
      v18 = 0;
    v19 = v23;
    *(_DWORD *)(v23 + *(_DWORD *)(this + 60)) = v18;
    if ( !v18 )
      return 0;
    if ( sub_67620F(*(int **)(v19 + *(_DWORD *)(this + 60))) < 0 )
    {
      v20 = v23;
      v21 = *(void **)(v23 + *(_DWORD *)(this + 60));
      if ( v21 )
        sub_673A75(v21, 1);
      *(_DWORD *)(v20 + *(_DWORD *)(this + 60)) = 0;
      return 0;
    }
    v6 = v23;
  }
  return *(_DWORD *)(v6 + *(_DWORD *)(this + 60));
}
