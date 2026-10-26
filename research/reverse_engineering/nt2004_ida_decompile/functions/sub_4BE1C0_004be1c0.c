int __stdcall sub_4BE1C0(const char *a1, const char *a2, const char *a3, const char *a4, const char *a5)
{
  char *v5; // eax
  const char *v6; // ecx
  const char *v7; // eax
  char ArgList[509]; // [esp+8h] [ebp-A00h] BYREF
  __int16 v10; // [esp+205h] [ebp-803h]
  char v11; // [esp+207h] [ebp-801h]
  char v12[509]; // [esp+208h] [ebp-800h] BYREF
  __int16 v13; // [esp+405h] [ebp-603h]
  char v14; // [esp+407h] [ebp-601h]
  char Source[509]; // [esp+408h] [ebp-600h] BYREF
  __int16 v16; // [esp+605h] [ebp-403h]
  char v17; // [esp+607h] [ebp-401h]
  char v18[509]; // [esp+608h] [ebp-400h] BYREF
  __int16 v19; // [esp+805h] [ebp-203h]
  char v20; // [esp+807h] [ebp-201h]
  char Buffer[509]; // [esp+808h] [ebp-200h] BYREF
  __int16 v22; // [esp+A05h] [ebp-3h]
  char v23; // [esp+A07h] [ebp-1h]

  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0x1FCu);
  v22 = 0;
  v23 = 0;
  Source[0] = byte_629120;
  memset(&Source[1], 0, 0x1FCu);
  v16 = 0;
  v17 = 0;
  v12[0] = byte_629120;
  memset(&v12[1], 0, 0x1FCu);
  v13 = 0;
  v14 = 0;
  v18[0] = byte_629120;
  memset(&v18[1], 0, 0x1FCu);
  v19 = 0;
  v20 = 0;
  ArgList[0] = byte_629120;
  memset(&ArgList[1], 0, 0x1FCu);
  v10 = 0;
  v11 = 0;
  strcpy(ArgList, a3);
  v5 = &ArgList[strlen(ArgList)];
  if ( v5 > ArgList )
  {
    while ( *v5 != 46 )
    {
      if ( --v5 <= ArgList )
        goto LABEL_6;
    }
    *v5 = 0;
  }
LABEL_6:
  sub_405480(Buffer, 0x1FFu, "%s%s", ArgList, a1);
  sub_405480(Source, 0x1FFu, "%s%s", a4, a2);
  sub_405480(v12, 0x1FFu, "%s%s", a5, a2);
  v6 = (const char *)dword_62A0B8;
  if ( !dword_62A0B8 )
    v6 = &byte_629120;
  v7 = *(const char **)dword_62A068;
  if ( !*(_DWORD *)dword_62A068 )
    v7 = &byte_629120;
  sub_405480(v18, 0x1FFu, "%s%s%s%s%s", v7, v6, (const char *)&dword_609F38, a1, aBmp_0);
  sub_505E80(Source, v12, v18, 0);
  return sub_505E40(a1, Buffer);
}
