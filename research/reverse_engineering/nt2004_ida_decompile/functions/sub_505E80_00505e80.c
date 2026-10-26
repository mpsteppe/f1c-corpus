int __fastcall sub_505E80(const char *a1, int a2, char *Source, char *a4, char *a5, int a6)
{
  int v8; // eax
  int v9; // esi
  int result; // eax
  char v12[509]; // [esp+14h] [ebp-600h] BYREF
  __int16 v13; // [esp+211h] [ebp-403h]
  char v14; // [esp+213h] [ebp-401h]
  char v15[509]; // [esp+214h] [ebp-400h] BYREF
  __int16 v16; // [esp+411h] [ebp-203h]
  char v17; // [esp+413h] [ebp-201h]
  char Destination[509]; // [esp+414h] [ebp-200h] BYREF
  __int16 v19; // [esp+611h] [ebp-3h]
  char v20; // [esp+613h] [ebp-1h]

  if ( !a1 )
    return 1;
  if ( !sub_505AD0(a6) )
    return 1;
  v8 = sub_59A660(a1);
  v9 = v8;
  if ( !v8 )
    return 1;
  if ( (!Source || (result = sub_505AF0(v8, a2, Source)) != 0)
    && (!a4 || (result = sub_505AF0(v9, a2, a4)) != 0)
    && (!a5 || (result = sub_505AF0(v9, a2, a5)) != 0) )
  {
    Destination[0] = byte_629120;
    memset(&Destination[1], 0, 0x1FCu);
    v19 = 0;
    v20 = 0;
    v15[0] = byte_629120;
    memset(&v15[1], 0, 0x1FCu);
    v16 = 0;
    v17 = 0;
    v12[0] = byte_629120;
    memset(&v12[1], 0, 0x1FCu);
    v13 = 0;
    v14 = 0;
    if ( Source )
    {
      strncpy(Destination, Source, 0x1FFu);
      v20 = 0;
    }
    if ( a4 )
    {
      strncpy(v15, a4, 0x1FFu);
      v17 = 0;
    }
    if ( a5 )
    {
      strncpy(v12, a5, 0x1FFu);
      v14 = 0;
    }
    if ( sub_500F90(&unk_7D7920, 1, aDDevNascar2004_23, 390) )
      sub_500FE0(
        (int)&unk_7D7920,
        "Unable to adjust texture for material: %s, tex1=%s, tex2=%s, tex3=%s",
        a1,
        Destination,
        v15,
        v12);
    return 1;
  }
  return result;
}
