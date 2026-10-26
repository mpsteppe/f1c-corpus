int sub_4E92D0()
{
  int result; // eax
  int v1; // ebp
  _DWORD *v2; // eax
  int v3; // edx
  _DWORD *v4; // ebx
  const char *v5; // edi
  int v6; // esi
  int v7; // eax
  const char *v8; // eax
  int v9; // edi
  int v10; // ecx
  int v11; // eax
  int v12; // esi
  int v13; // ecx
  void *v14; // eax
  int v15; // [esp+4h] [ebp-19Ch]
  int v16; // [esp+4h] [ebp-19Ch]
  int v17; // [esp+8h] [ebp-198h]
  int v18; // [esp+Ch] [ebp-194h]
  char Buffer[400]; // [esp+10h] [ebp-190h] BYREF

  result = sub_57AE50(aRaceorder);
  v1 = 0;
  if ( result )
  {
    v17 = sub_57A6E0(result);
    v2 = operator new(4 * dword_7D6B50);
    v3 = dword_7D6B50;
    v4 = v2;
    if ( dword_7D6B50 > 0 )
    {
      v15 = 0;
      do
      {
        v5 = (const char *)(v15 + dword_7D6B58 + 260);
        v6 = 0;
        if ( v17 <= 0 )
          goto LABEL_9;
        while ( 1 )
        {
          v7 = sub_57A700(v6);
          v8 = (const char *)sub_57A6C0(v7);
          if ( !_strcmpi(v8, v5) )
            break;
          if ( ++v6 >= v17 )
            goto LABEL_9;
        }
        if ( v6 >= v17 )
LABEL_9:
          sprintf(Buffer, "Scenefile not listed among game.gdb season races: \"%s\" ", v5);
        v4[v1] = v6;
        v3 = dword_7D6B50;
        ++v1;
        v15 += 400;
      }
      while ( v1 < dword_7D6B50 );
    }
    v9 = 0;
    if ( v3 > 0 )
    {
      v16 = 0;
      do
      {
        v10 = v9 + 1;
        v11 = v9;
        if ( v9 + 1 < v3 )
        {
          v12 = v9;
          v18 = v9;
          do
          {
            if ( v4[v10] < v4[v12] )
            {
              v11 = v10;
              v12 = v10;
            }
            v3 = dword_7D6B50;
            ++v10;
          }
          while ( v10 < dword_7D6B50 );
          if ( v11 != v9 )
          {
            v13 = v4[v11];
            v4[v11] = v4[v18];
            v4[v18] = v13;
            v14 = (void *)(dword_7D6B58 + 400 * v11);
            qmemcpy(Buffer, v14, sizeof(Buffer));
            qmemcpy(v14, (const void *)(dword_7D6B58 + v16), 0x190u);
            qmemcpy((void *)(dword_7D6B58 + v16), Buffer, 0x190u);
            v3 = dword_7D6B50;
          }
          v10 = v9 + 1;
        }
        v9 = v10;
        v16 += 400;
      }
      while ( v10 < v3 );
    }
    return sub_5BE8AE(v4);
  }
  return result;
}
