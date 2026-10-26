char __thiscall sub_473E5E(char *this, int a2, _DWORD *a3)
{
  char *v3; // eax
  int v4; // ebx
  int v5; // ebp
  int i; // esi
  int v7; // edi
  char v9; // [esp+1h] [ebp-205h]
  int v10; // [esp+2h] [ebp-204h] BYREF
  char String1[512]; // [esp+6h] [ebp-200h] BYREF

  *a3 = 0;
  v9 = 1;
  if ( (unsigned __int8)sub_617BD0(this[1], &v10) )
    *a3 += v10;
  else
    v9 = 0;
  sub_630FE0(String1, a2, 511);
  String1[511] = 0;
  v3 = &String1[strlen(String1)];
  if ( v3 > String1 )
  {
    while ( *v3 != 46 )
    {
      if ( --v3 <= String1 )
        goto LABEL_9;
    }
    *v3 = 0;
  }
LABEL_9:
  v4 = dword_BE1CD0;
  v5 = 0;
  if ( dword_BE1CD0 > 0 )
  {
    for ( i = 0; ; i += 396 )
    {
      v7 = i + dword_BE1CD8;
      if ( !_stricmp(String1, (const char *)(i + dword_BE1CD8 + 4)) )
        break;
      if ( ++v5 >= v4 )
        return v9;
    }
    *a3 += *(_DWORD *)(v7 + 392);
  }
  return v9;
}
