char __thiscall sub_463D40(int *this, int a2, void *a3, _DWORD *a4)
{
  int v5; // ecx
  int v6; // eax
  int v7; // edx
  int v8; // ebp
  char v10; // [esp+Bh] [ebp-1h]

  v5 = *this;
  v6 = 0;
  v10 = 0;
  if ( *(int *)(v5 + 6512) <= 0 )
    return 0;
  v7 = 0;
  v8 = 6320;
  do
  {
    if ( *(char *)(v7 + v5 + 852) == a2 )
    {
      qmemcpy(a3, (const void *)(v7 + v5 + 752), 0x74u);
      *a4 = *(_DWORD *)(*this + v8);
      v10 = 1;
    }
    v5 = *this;
    ++v6;
    v8 += 4;
    v7 += 116;
  }
  while ( v6 < *(_DWORD *)(*this + 6512) );
  return v10;
}
