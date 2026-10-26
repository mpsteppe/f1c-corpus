int __thiscall sub_6866FF(_DWORD *this, int a2, int a3, int a4)
{
  int v4; // esi
  int v5; // edx
  int v6; // ebx
  int v7; // eax
  int result; // eax
  const char *v9; // [esp-8h] [ebp-14h]
  _BYTE *v10; // [esp-4h] [ebp-10h]

  v4 = *(_DWORD *)(this[4] + 4 * *(_DWORD *)(a2 + 4));
  v5 = *(_DWORD *)(a2 + 56);
  if ( v5 == -1 )
    v6 = a2;
  else
    v6 = *(_DWORD *)(this[5] + 4 * v5);
  if ( !**(_BYTE **)v4 || *(_BYTE *)(*(_DWORD *)v4 + 1) )
  {
    v10 = *(_BYTE **)v4;
    v9 = (const char *)&off_73D088;
  }
  else
  {
    v10 = *(_BYTE **)v4;
    v9 = "%s";
  }
  v7 = sub_632041(a3, a4, v9, v10);
  if ( *(_DWORD *)(v6 + 12) == -1 )
    result = sub_632041(a3 + v7, a4 - v7, "?");
  else
    result = sub_632041(a3 + v7, a4 - v7, "%u", *(_DWORD *)(v6 + 12));
  *(_BYTE *)(a3 + a4 - 1) = 0;
  return result;
}
