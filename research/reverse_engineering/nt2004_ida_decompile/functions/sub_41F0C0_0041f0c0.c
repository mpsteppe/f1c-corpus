int __thiscall sub_41F0C0(int this, int a2, int a3)
{
  int v4; // ebp
  int v5; // esi
  char Buffer[128]; // [esp+Ch] [ebp-480h] BYREF
  char Str[509]; // [esp+8Ch] [ebp-400h] BYREF
  __int16 v9; // [esp+289h] [ebp-203h]
  char v10; // [esp+28Bh] [ebp-201h]
  char v11[256]; // [esp+28Ch] [ebp-200h] BYREF
  char v12[256]; // [esp+38Ch] [ebp-100h] BYREF

  v4 = 0;
  if ( a3 )
  {
    if ( a2 )
      sprintf(Buffer, "%s%s", a2, a3);
  }
  else
  {
    sprintf(Buffer, "%s%s", a2, aGameDic);
  }
  v5 = sub_536110();
  if ( !v5 )
    return -1;
  Str[0] = byte_629120;
  memset(&Str[1], 0, 0x1FCu);
  v9 = 0;
  v10 = 0;
  while ( sub_5367E0(256) )
  {
    if ( sub_41EF20(Str, v12, v11) != -1 && !sub_41ED60((int *)this, v12, v11) )
      ++v4;
  }
  sub_536BE0(v5);
  qsort(*(void **)(this + 8), *(_DWORD *)(this + 4), 0x10u, (_CoreCrtNonSecureSearchSortCompareFunction)CompareFunction);
  Buffer[0] = 0;
  if ( !sub_41F230(aOscLocaleStrin, Buffer) )
  {
    if ( strlen(Buffer) )
      setlocale(2, Buffer);
  }
  return v4;
}
