int __thiscall sub_547920(_DWORD *this, const char *a2)
{
  int v3; // esi
  int v5; // eax
  CHAR *v6; // eax
  CHAR v7; // cl
  int v8; // ebp
  char *v9; // ebx
  CHAR *v10; // edi
  char *v11; // eax
  char v12; // cl
  int v13; // [esp+10h] [ebp-208h]
  BOOL v14; // [esp+14h] [ebp-204h] BYREF
  CHAR v15[256]; // [esp+18h] [ebp-200h] BYREF
  CHAR SrcStr[256]; // [esp+118h] [ebp-100h] BYREF

  strcpy(SrcStr, a2);
  sub_589901(SrcStr);
  v14 = StringDotFinder(SrcStr) != 0;
  v3 = this[10];
  v13 = v3;
  if ( !v3 )
    return 0;
  while ( 1 )
  {
    v5 = *(_DWORD *)(v3 + 76);
    if ( v5 != 1 )
      break;
    v6 = (CHAR *)(v3 + 4);
    do
    {
      v7 = *v6;
      v15[(_DWORD)v6 - 4 - v3] = *v6;
      ++v6;
    }
    while ( v7 );
    sub_589901(v15);
    if ( v14 )
      StringDotFinder(v15);
    if ( !strcmp(v15, SrcStr) )
      return v13;
LABEL_19:
    v3 = v13;
LABEL_20:
    v13 = *(_DWORD *)(v3 + 92);
    if ( !v13 )
      return 0;
    v3 = *(_DWORD *)(v3 + 92);
  }
  v8 = 0;
  if ( v5 <= 0 )
    goto LABEL_20;
  v9 = (char *)(v3 + 4);
  v10 = &v15[-v3 - 4];
  while ( 1 )
  {
    v11 = v9;
    do
    {
      v12 = *v11;
      v11[(_DWORD)v10] = *v11;
      ++v11;
    }
    while ( v12 );
    sub_589901(v15);
    if ( v14 )
      StringDotFinder(v15);
    if ( !strcmp(v15, SrcStr) )
      return v13 + 96 * v8;
    ++v8;
    v10 -= 96;
    v9 += 96;
    if ( v8 >= *(_DWORD *)(v13 + 76) )
      goto LABEL_19;
  }
}

