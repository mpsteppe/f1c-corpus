int __fastcall sub_5BA610(
        char **a1,
        int a2,
        int a3,
        const char *a4,
        char *a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14)
{
  char *v16; // esi
  char *v17; // eax
  DWORD TickCount; // eax
  const char *v19; // eax
  char v20; // cl
  char *v21; // eax
  char v22; // cl
  int i; // edi
  char *v24; // ecx
  char Buffer[64]; // [esp+Ch] [ebp-40h] BYREF

  if ( a1 )
  {
    v17 = (char *)malloc(0x108u);
    *a1 = v17;
    v16 = v17;
  }
  else
  {
    v16 = (char *)&unk_624908;
  }
  TickCount = GetTickCount();
  srand(TickCount);
  v19 = a4;
  do
  {
    v20 = *v19;
    v19[v16 - a4 + 4] = *v19;
    ++v19;
  }
  while ( v20 );
  v21 = a5;
  do
  {
    v22 = *v21;
    v21[v16 - a5 + 68] = *v21;
    ++v21;
  }
  while ( v22 );
  *((_DWORD *)v16 + 46) = a3;
  *((_DWORD *)v16 + 65) = a14;
  *((_DWORD *)v16 + 34) = a8;
  *((_DWORD *)v16 + 35) = a9;
  *((_DWORD *)v16 + 36) = a10;
  *((_DWORD *)v16 + 37) = a11;
  *(_DWORD *)v16 = a2;
  *((_DWORD *)v16 + 42) = 0;
  *((_DWORD *)v16 + 43) = 0;
  *((_DWORD *)v16 + 44) = 1;
  *((_DWORD *)v16 + 38) = a12;
  *((_DWORD *)v16 + 39) = a13;
  *((_DWORD *)v16 + 40) = 0;
  *((_DWORD *)v16 + 41) = 0;
  *((_DWORD *)v16 + 53) = 0;
  *((_DWORD *)v16 + 45) = a6;
  *((_DWORD *)v16 + 47) = 0;
  *((_DWORD *)v16 + 48) = a7;
  for ( i = 0; i < 4; v16[i + 131] = rand() % 255 )
    ++i;
  memset(v16 + 216, 0xFFu, 0x28u);
  *((_DWORD *)v16 + 64) = 0;
  if ( !dword_7FEFDC )
    sub_5BAC00();
  if ( !a6 )
    return 0;
  if ( byte_800140 )
  {
    v24 = &byte_800140;
  }
  else
  {
    sprintf(Buffer, "%s.master.gamespy.com", a4);
    v24 = Buffer;
  }
  if ( sub_5BAC40(v24, 0x6CFCu, (int)(v16 + 196), 0) )
    return 0;
  else
    return 3;
}
