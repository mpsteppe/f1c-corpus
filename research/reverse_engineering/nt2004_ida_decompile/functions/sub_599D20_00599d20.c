int __thiscall sub_599D20(_DWORD *this, const char *a2)
{
  int v3; // esi
  int v5; // eax
  char *v6; // eax
  char v7; // cl
  int v8; // ebp
  char *v9; // ebx
  char *v10; // edi
  char *v11; // eax
  char v12; // cl
  int v13; // [esp+10h] [ebp-208h]
  BOOL v14; // [esp+14h] [ebp-204h]
  char v15[256]; // [esp+18h] [ebp-200h] BYREF
  char String[256]; // [esp+118h] [ebp-100h] BYREF

  strcpy(String, a2);
  _strupr(String);
  v14 = sub_599EF0(String) != 0;
  v3 = this[10];
  v13 = v3;
  if ( !v3 )
    return 0;
  while ( 1 )
  {
    v5 = *(_DWORD *)(v3 + 88);
    if ( v5 != 1 )
      break;
    v6 = (char *)(v3 + 20);
    do
    {
      v7 = *v6;
      v15[(_DWORD)v6 - 20 - v3] = *v6;
      ++v6;
    }
    while ( v7 );
    _strupr(v15);
    if ( v14 )
      sub_599EF0(v15);
    if ( !strcmp(v15, String) )
      return v13;
LABEL_19:
    v3 = v13;
LABEL_20:
    v13 = *(_DWORD *)(v3 + 12);
    if ( !v13 )
      return 0;
    v3 = *(_DWORD *)(v3 + 12);
  }
  v8 = 0;
  if ( v5 <= 0 )
    goto LABEL_20;
  v9 = (char *)(v3 + 20);
  v10 = &v15[-v3 - 20];
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
    _strupr(v15);
    if ( v14 )
      sub_599EF0(v15);
    if ( !strcmp(v15, String) )
      return v13 + 96 * v8;
    ++v8;
    v10 -= 96;
    v9 += 96;
    if ( v8 >= *(_DWORD *)(v13 + 88) )
      goto LABEL_19;
  }
}
