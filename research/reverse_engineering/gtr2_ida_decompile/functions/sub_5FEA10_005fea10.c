int __thiscall sub_5FEA10(int *this, char a2, int a3)
{
  int v4; // eax
  void **v5; // esi
  int v6; // ecx
  int v7; // ecx
  int v8; // edx
  void *v9; // ebx
  int v11; // edx
  int v12; // [esp-4h] [ebp-10h]

  if ( (*this & 0x10000) != 0 && !a2 )
    return 0;
  v4 = this[41];
  v5 = (void **)(this + 41);
  if ( v4 )
  {
    v6 = *(_DWORD *)(v4 + 12);
    if ( v6 <= 0 || (v7 = v6 - 1, (*(_DWORD *)(v4 + 12) = v7) == 0) )
      (*(void (__thiscall **)(int, void *, _DWORD))(*(_DWORD *)dword_FB27A4 + 408))(dword_FB27A4, *v5, 0);
  }
  v8 = this[39];
  *v5 = 0;
  if ( !(*(int (__thiscall **)(int, int *, int, int, int))(*(_DWORD *)dword_FB27A4 + 404))(
          dword_FB27A4,
          this + 41,
          v8,
          0x4000,
          14) )
  {
    ++*((_DWORD *)*v5 + 3);
    sub_60ADF0(32, 0);
    v11 = *this | 0x10000;
    *this = v11;
    if ( a2 )
      *this = v11 | 4;
    return 0;
  }
  nullsub_7(*v5);
  v9 = *v5;
  if ( *v5 )
  {
    nullsub_7(*v5);
    j__free(v9);
  }
  v12 = this[10];
  *v5 = 0;
  sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error creating vertex buffer for projector %d", v12);
  return -1;
}
