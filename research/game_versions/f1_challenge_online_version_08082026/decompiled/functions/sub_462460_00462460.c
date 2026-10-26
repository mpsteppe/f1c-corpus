char __thiscall sub_462460(int *this, int a2, void *a3, _DWORD *a4)
{
  int v5; // ecx
  int v6; // eax
  int v7; // edx
  int v8; // ebp
  char v10; // [esp+Bh] [ebp-1h]

  v5 = *this;
  v6 = 0;
  v10 = 0;
  if ( *(int *)(v5 + 15892) <= 0 )
    return 0;
  v7 = 0;
  v8 = 15476;
  do
  {
    if ( *(char *)(v7 + v5 + 1040) == a2 )
    {
      qmemcpy(a3, (const void *)(v7 + v5 + 916), 0x8Cu);
      *a4 = *(_DWORD *)(*this + v8);
      v10 = 1;
    }
    v5 = *this;
    ++v6;
    v8 += 4;
    v7 += 140;
  }
  while ( v6 < *(_DWORD *)(*this + 15892) );
  return v10;
}
