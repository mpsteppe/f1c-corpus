char *__thiscall sub_52A580(char *this, int a2)
{
  char *result; // eax
  int v3; // ebp
  int v4; // ebx
  int v5; // esi
  int v6; // eax
  int v7; // edx
  int v8; // [esp+Ch] [ebp-80Ch]
  int v10; // [esp+14h] [ebp-804h]
  _DWORD v11[512]; // [esp+18h] [ebp-800h]

  result = *(char **)(a2 + 280);
  v3 = 0;
  v4 = 0;
  v8 = 0;
  if ( (int)result > 0 )
  {
    v10 = *(_DWORD *)(a2 + 280);
    do
    {
      v5 = v3 + *(_DWORD *)(a2 + 296);
      if ( !strncmp((const char *)(v5 + 20), aClouds, 6u) && v4 < 256 )
        v11[v4++] = v5;
      if ( !strncmp((const char *)(v5 + 20), aCloudr, 6u) && v8 < 256 )
        v11[v8++ + 256] = v5;
      v3 += 256;
      result = (char *)--v10;
    }
    while ( v10 );
    if ( v4 > 0 )
    {
      v6 = rand();
      result = strncpy(this + 80, (const char *)(v11[v6 % v4] + 20), 0x1Fu);
      this[111] = 0;
    }
    if ( v8 > 0 )
    {
      v7 = rand() % v8;
      result = strncpy(this + 132, (const char *)(v11[v7 + 256] + 20), 0x1Fu);
      this[163] = 0;
    }
  }
  return result;
}
