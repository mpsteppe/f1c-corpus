void __stdcall sub_5410E0(int a1)
{
  const CHAR *v1; // eax
  int v2; // kr00_4
  char *i; // eax
  void *Block[4]; // [esp+10h] [ebp-324h] BYREF
  char v5; // [esp+20h] [ebp-314h]
  char v7[256]; // [esp+24h] [ebp-310h] BYREF
  char ArgList[509]; // [esp+124h] [ebp-210h] BYREF
  __int16 v9; // [esp+321h] [ebp-13h]
  char v10; // [esp+323h] [ebp-11h]
  int v11; // [esp+330h] [ebp-4h]

  if ( dword_BE1D14 )
  {
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)dword_BE1D14 + 8))(dword_BE1D14) )
      (*(void (__thiscall **)(int))(*(_DWORD *)dword_BE1D14 + 12))(dword_BE1D14);
    v1 = dword_B6F68C;
    if ( !dword_B6F68C )
      v1 = WindowName;
    sub_630FE0(v7, v1, 255);
    v7[255] = 0;
    v2 = strlen(v7);
    if ( v2 > 0 )
    {
      for ( i = &v7[v2 - 1]; i >= v7; *i-- = 0 )
      {
        if ( *i == 92 )
          break;
      }
    }
    sub_40B430();
    memset(ArgList, 0, sizeof(ArgList));
    v9 = 0;
    v10 = 0;
    v11 = 0;
    sub_632041(ArgList, 511, "%sComments\\corner%d.mp3", v7, a1);
    if ( dword_B640C0 != 5
      && (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\sound.cpp", 980) )
    {
      sub_561210((int)byte_FAE910, "%s", (char)ArgList);
    }
    sub_615860(ArgList);
    Block[2] = (void *)-1;
    Block[3] = (void *)-1;
    v5 = 0;
    (*(void (__thiscall **)(int, void **, int, _DWORD))(*(_DWORD *)dword_BE1D14 + 4))(dword_BE1D14, Block, 1, 0);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)dword_BE1D14 + 28))(dword_BE1D14, LODWORD(flt_B70A44));
    if ( Block[0] )
      j_j__free(Block[0]);
  }
}
