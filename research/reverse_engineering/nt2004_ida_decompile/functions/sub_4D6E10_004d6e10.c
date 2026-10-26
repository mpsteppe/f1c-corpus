BOOL __thiscall sub_4D6E10(int this, char *Source, char a3)
{
  _DWORD *v4; // edi
  void *v5; // ebp
  const char *v6; // edx
  const char *v7; // ecx
  const char *v8; // edx
  const char *v9; // ecx
  char *v10; // eax
  int *v12; // edi
  int v13; // ecx

  sub_4D7020(1);
  if ( a3 )
  {
    sub_4D5820((_DWORD *)this);
    sub_4D5710((_DWORD *)this);
    v4 = *(_DWORD **)(this + 848);
    while ( v4 )
    {
      v5 = v4;
      v4 = (_DWORD *)v4[1];
      sub_4DBC90(v5);
      sub_5BE8AE(v5);
    }
    *(_DWORD *)(this + 848) = 0;
    *(_DWORD *)(this + 852) = 0;
    *(_DWORD *)(this + 856) = 0;
    *(_DWORD *)(this + 860) = 0;
    sub_578600(Source);
    v6 = dword_766578;
    if ( !dword_766578 )
      v6 = &byte_629120;
    v7 = &v6[strlen(v6)];
    if ( v7 > v6 )
    {
      while ( *v7 != 92 )
      {
        if ( --v7 <= v6 )
          goto LABEL_11;
      }
      ++v7;
    }
LABEL_11:
    sub_578600(v7);
    v8 = ::Source;
    if ( !::Source )
      v8 = &byte_629120;
    v9 = &v8[strlen(v8)];
    if ( v9 > v8 )
    {
      while ( *v9 != 92 )
      {
        if ( --v9 <= v8 )
          goto LABEL_18;
      }
      ++v9;
    }
LABEL_18:
    sub_578600(v9);
    sub_4D7B10(this);
    sub_4D9840(this + 916);
    v10 = *(char **)(this + 916);
    if ( !v10 )
      v10 = &byte_629120;
    if ( (unsigned __int8)sub_57A110(v10, 0, 0, 1) )
    {
      *(_DWORD *)(this + 912) = 1;
    }
    else
    {
      sub_578600(&byte_629120);
      *(_DWORD *)(this + 912) = 0;
    }
    *(_DWORD *)(this + 2048) = 0;
    *(_DWORD *)(this + 2052) = 0;
    *(_DWORD *)(this + 2056) = 0;
    *(_BYTE *)(this + 2068) = 0;
    *(_DWORD *)(this + 2072) = 0;
    *(_DWORD *)(this + 1760) = 0;
    *(_BYTE *)(this + 2140) = 0;
    *(_DWORD *)(this + 2040) = *(_DWORD *)(dword_75AAD0[dword_75AAC8] + 25248);
    *(_DWORD *)(this + 2044) = dword_75CBB0;
    return *(_DWORD *)(this + 884) != 0;
  }
  else
  {
    v12 = (int *)(this + 884);
    sub_57A2F0(Source, 0);
    *(_DWORD *)(this + 2160) = 0;
    if ( sub_4D6660((_DWORD *)this, this + 884) )
    {
      sub_4D82E0(*(_DWORD *)(this + 2060));
      v13 = *v12;
      *(_DWORD *)(this + 912) = 2;
      return v13 != 0;
    }
    else
    {
      sub_57A360(this + 884);
      return *v12 != 0;
    }
  }
}
