int __thiscall sub_497A20(_DWORD *this)
{
  float *v1; // esi
  int v2; // edi
  int v3; // esi
  char *v4; // eax
  char *v6; // [esp-4h] [ebp-50h]
  char *v7; // [esp-4h] [ebp-50h]
  char Buffer[61]; // [esp+Ch] [ebp-40h] BYREF
  __int16 v9; // [esp+49h] [ebp-3h]
  char v10; // [esp+4Bh] [ebp-1h]

  v1 = (float *)this[217];
  memset(Buffer, 0, sizeof(Buffer));
  v9 = 0;
  v10 = 0;
  v2 = (unsigned __int64)(*v1 * 24.0);
  v3 = -60 * v2 - (unsigned __int64)(*v1 * -1440.0);
  if ( v2 == 1 )
  {
    v6 = sub_41D840(&byte_91CC38, "Hour");
    sub_41D810(Buffer, 0x3Fu, "%d %s", 1, v6);
  }
  else if ( v2 > 0 )
  {
    v7 = sub_41D840(&byte_91CC38, "Hours");
    sub_41D810(Buffer, 0x3Fu, "%d %s", v2, v7);
  }
  if ( v3 > 0 )
  {
    v4 = sub_41D840(&byte_91CC38, "Minutes");
    sub_41D810(Buffer, 0x3Fu, "%s %d %s", Buffer, v3, v4);
  }
  return sub_4CE770(Buffer);
}
