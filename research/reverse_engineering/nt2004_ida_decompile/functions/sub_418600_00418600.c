int __thiscall sub_418600(_DWORD *this, int a2, char a3)
{
  char *v3; // edi
  int v4; // esi
  int *v5; // ebp
  int v6; // ebx
  int v7; // eax
  int i; // esi
  int v9; // eax
  int v10; // esi
  int *v11; // edi
  int v12; // ebp
  int v13; // eax
  int result; // eax

  v3 = (char *)&unk_62C6CC + 25304 * a2;
  v4 = 160 * a2;
  v5 = (int *)(v3 + 340);
  v6 = 4;
  do
  {
    if ( a3 )
      v7 = *v5;
    else
      v7 = 0;
    sub_415800((_DWORD *)(v4 + this[19]), v7);
    v4 += 40;
    v5 += 76;
    --v6;
  }
  while ( v6 );
  for ( i = 0; i < 2; ++i )
  {
    if ( a3 )
    {
      if ( i )
        v9 = *((_DWORD *)v3 + 406);
      else
        v9 = *((_DWORD *)v3 + 389);
    }
    else
    {
      v9 = 0;
    }
    sub_415800((_DWORD *)(this[22] + 40 * (i + 2 * a2)), v9);
  }
  v10 = 480 * a2;
  v11 = (int *)(v3 + 1692);
  v12 = 12;
  do
  {
    if ( a3 )
      v13 = *v11;
    else
      v13 = 0;
    result = sub_415800((_DWORD *)(v10 + this[25]), v13);
    v10 += 40;
    v11 += 17;
    --v12;
  }
  while ( v12 );
  return result;
}
