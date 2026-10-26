int __thiscall sub_60AD50(_DWORD *this, int a2, int a3, int a4)
{
  int v5; // ecx
  int v7; // [esp+14h] [ebp-4h] BYREF

  v5 = this[8];
  v7 = 0;
  if ( v5 )
  {
    if ( (*(int (__stdcall **)(int, int, int, int *, int))(*(_DWORD *)v5 + 44))(v5, a3 * this[5], a4 * this[5], &v7, a2) )
      return 0;
    ++this[4];
  }
  return v7;
}
