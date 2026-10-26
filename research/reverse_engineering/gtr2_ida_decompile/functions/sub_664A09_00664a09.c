int __thiscall sub_664A09(_DWORD *this, _DWORD *a2, int a3, int a4)
{
  char *v5; // eax
  char *v6; // ebx
  _DWORD *v8; // ecx
  _DWORD *v9; // eax

  v5 = (char *)operator new(4 * a4);
  v6 = v5;
  if ( !v5 )
    return -2147024882;
  sub_663D59((int)this, a2, v5);
  if ( a4 )
  {
    v8 = v6;
    do
    {
      v9 = *(_DWORD **)(*(_DWORD *)(this[2] + 20) + 4 * *(_DWORD *)((char *)v8 + a3 - (_DWORD)v6));
      *v9 |= *v8++;
      --a4;
    }
    while ( a4 );
  }
  j__free(v6);
  return 0;
}
