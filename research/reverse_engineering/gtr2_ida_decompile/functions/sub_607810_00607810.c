int __thiscall sub_607810(_DWORD *this, const char *a2, int a3, int a4, _DWORD *a5, int **a6)
{
  int *v7; // eax
  int *v8; // esi
  unsigned int v10; // eax

  v7 = (int *)operator new(0x68u);
  if ( v7 )
    v8 = sub_6076E0(v7);
  else
    v8 = 0;
  if ( sub_6072F0((int)v8, (int)this, a2, a3, (int)this, a4) )
    return -1;
  v8[21] = (int)a5;
  if ( a5 && (*a5 & 0x10) != 0 )
    v10 = *v8 | 0x10;
  else
    v10 = *v8 & 0xFFFFFFEF;
  *v8 = v10;
  v8[9] = this[136];
  sub_5FDFB0(this + 133, (int)v8, 1);
  if ( a6 )
    *a6 = v8;
  return 0;
}
