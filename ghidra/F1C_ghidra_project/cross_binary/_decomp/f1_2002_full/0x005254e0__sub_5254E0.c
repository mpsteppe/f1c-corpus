// f1_2002_full  0x005254e0  size=578
int __stdcall sub_5254E0(_DWORD *a1, char *a2)
{
  char *v2; // eax
  int v3; // ebx
  char v4; // cl
  FILE *v5; // esi
  bool v6; // zf
  const char *v7; // edi
  void *v9; // eax
  _DWORD *v10; // esi
  int v11; // eax
  size_t v12; // ecx
  size_t i; // eax
  int v14; // [esp+10h] [ebp-214h]
  char v15[16]; // [esp+14h] [ebp-210h] BYREF
  char String[256]; // [esp+24h] [ebp-200h] BYREF
  char Buffer[256]; // [esp+124h] [ebp-100h] BYREF

  v2 = a2;
  v3 = 0;
  v14 = 0;
  if ( !a2 || !*a2 )
    return v14;
  do
  {
    v4 = *v2;
    v2[String - a2] = *v2;
    ++v2;
  }
  while ( v4 );
  _strupr(String);
  v5 = fopen(String, aRb);
  if ( !v5 )
  {
    v6 = dword_6C8BFC == 0;
    if ( dword_6C8BFC > 0 )
    {
      v7 = &byte_6C5814;
      do
      {
        sprintf(Buffer, "%s\\%s", v7, String);
        v5 = fopen(Buffer, aRb);
        if ( v5 )
          break;
        ++v3;
        v7 += 132;
      }
      while ( v3 < dword_6C8BFC );
      v6 = v3 == dword_6C8BFC;
    }
    if ( v6 )
    {
      sprintf(Buffer, "Error opening MAS file %s", String);
      sub_524EB0(-2, Buffer);
      return -2;
    }
  }
  sub_56D0C9(v15, 1u, 0xCu, v5);
  fclose(v5);
  if ( !strcmp(v15, aCubemas410) )
  {
    v9 = operator new(0x134u);
    if ( v9 )
      v10 = (_DWORD *)sub_547B60(v9);
    else
      v10 = 0;
    v11 = sub_547BC0(v10, (int)String);
    switch ( v11 )
    {
      case -2:
        if ( v10 )
        {
          j_nullsub_8(v10);
          sub_56BEF1(v10);
        }
        v14 = -2;
        break;
      case -1:
        if ( v10 )
        {
          j_nullsub_8(v10);
          sub_56BEF1(v10);
        }
        v14 = -1;
        break;
      case 0:
        v12 = ElementCount;
        if ( ElementCount )
        {
          for ( i = *(_DWORD *)(ElementCount + 304); i; i = *(_DWORD *)(i + 304) )
            v12 = i;
          *(_DWORD *)(v12 + 304) = v10;
          v10[75] = v12;
        }
        else
        {
          ElementCount = (size_t)v10;
        }
        ++dword_6C6898;
        v14 = 0;
        break;
    }
    if ( a1 )
      *a1 = v10;
    return v14;
  }
  if ( strcmp(v15, aCubemas400) && strcmp(v15, aCubemas401) )
    return v14;
  sub_524EB0(-2, aIncorrectMasFi);
  return -1;
}
