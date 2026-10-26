int __thiscall sub_4F18E0(int this, int a2, char ArgList, int a4, _DWORD *a5)
{
  int v7; // esi
  int *v8; // eax
  _DWORD *v9; // edi
  int v10; // edx
  int v11; // eax
  char *v12; // eax
  char *v13; // esi
  int v14; // ebp
  _DWORD *v15; // ebp
  int v16; // eax
  _DWORD *v17; // [esp+8h] [ebp-10h]

  if ( !*(_DWORD *)(this + 136) )
    return 0;
  v7 = *(_DWORD *)(this + 152) + 1;
  v8 = (int *)operator new(120 * v7 + 4);
  if ( v8 )
  {
    v9 = v8 + 1;
    *v8 = v7;
    sub_630A11(v8 + 1, 120, v7, sub_4F1770, sub_4F09B0);
    v17 = v9;
  }
  else
  {
    v17 = 0;
  }
  v10 = 0;
  if ( *(int *)(this + 152) > 0 )
  {
    v11 = 0;
    do
    {
      qmemcpy(&v17[v11], (const void *)(v11 * 4 + *(_DWORD *)(this + 156)), 0x78u);
      *(_DWORD *)(*(_DWORD *)(this + 156) + v11 * 4 + 112) = 0;
      ++v10;
      v11 += 30;
    }
    while ( v10 < *(_DWORD *)(this + 152) );
  }
  v12 = *(char **)(this + 156);
  if ( v12 )
  {
    v13 = v12 - 4;
    `eh vector destructor iterator'(v12, 0x78u, *((_DWORD *)v12 - 1), (void (__thiscall *)(void *))sub_4F09B0);
    j_j__free(v13);
  }
  v14 = 30 * *(_DWORD *)(this + 152);
  *(_DWORD *)(this + 156) = v17;
  v15 = &v17[v14];
  v16 = sub_408F00();
  v15[28] = v16;
  if ( v16 )
  {
    if ( a5[6] )
      sub_405CA0(*(_DWORD **)(this + 140), v16);
    qmemcpy(v15, a5, 0x70u);
    if ( a4 )
      v15[29] = sub_4F02A0();
    else
      v15[29] = 35;
    ++*(_DWORD *)(this + 152);
    return 0;
  }
  else
  {
    if ( (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\pitcrew.cpp", 1146) )
      sub_561210((int)byte_FAE910, "Error loading animation file %s", ArgList);
    return -1;
  }
}
