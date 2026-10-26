int sub_531280()
{
  int v0; // edx
  int result; // eax
  int v2; // ebp
  int v3; // ecx
  int v4; // esi
  int v5; // eax
  int v6; // ecx
  int *v7; // edi
  int v8; // edx
  int v9; // edx
  int v10; // edx
  int v11; // [esp+8h] [ebp-1A8h]
  int v12; // [esp+Ch] [ebp-1A4h]
  _DWORD v13[104]; // [esp+10h] [ebp-1A0h] BYREF

  v0 = dword_757C10;
  memset(v13, 0xFFu, sizeof(v13));
  result = 0;
  v2 = 1;
  if ( dword_757C10 > 0 )
  {
    do
    {
      v3 = *(&dword_91E088 + result++);
      v13[*(_DWORD *)(v3 + 22468)] = *(_DWORD *)(v3 + 22080);
    }
    while ( result < v0 );
  }
  v12 = 0;
  if ( v0 > 0 )
  {
    do
    {
      v4 = -1;
      v5 = 999;
      v6 = 2;
      v7 = &v13[1];
      do
      {
        v8 = *(v7 - 1);
        if ( v8 != -1 && v8 < v5 )
        {
          v5 = *(v7 - 1);
          v4 = v6 - 2;
        }
        if ( *v7 != -1 && *v7 < v5 )
        {
          v5 = *v7;
          v4 = v6 - 1;
        }
        v9 = v7[1];
        if ( v9 != -1 && v9 < v5 )
        {
          v5 = v7[1];
          v4 = v6;
        }
        v10 = v7[2];
        if ( v10 != -1 && v10 < v5 )
        {
          v5 = v7[2];
          v4 = v6 + 1;
        }
        v6 += 4;
        v7 += 4;
      }
      while ( v6 - 2 < 104 );
      if ( v5 != 999 && v4 != -1 )
      {
        sub_52C360(v2);
        v13[v4 - 1] = -1;
        ++v2;
      }
      result = ++v11;
    }
    while ( v11 < dword_757C10 );
  }
  return result;
}
