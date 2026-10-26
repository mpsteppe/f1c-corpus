int sub_46BD20()
{
  LRESULT v0; // edx
  _DWORD *v1; // ecx
  LRESULT v2; // edi
  CHAR ***v3; // esi
  _DWORD *v4; // ebx
  _DWORD *v5; // eax
  _DWORD *v6; // esi
  _DWORD *v7; // eax
  CHAR **i; // edi
  CHAR *v9; // eax
  CHAR *v10; // eax
  LRESULT v11; // eax
  int result; // eax
  _DWORD *j; // ebp
  _DWORD *v14; // edi
  char v15; // al
  LPVOID *v16; // esi
  _DWORD *v17; // [esp+10h] [ebp-514h]
  int v18; // [esp+1Ch] [ebp-508h]
  LRESULT v19; // [esp+20h] [ebp-504h]
  _BYTE v20[256]; // [esp+24h] [ebp-500h] BYREF
  LPARAM lParam[256]; // [esp+124h] [ebp-400h] BYREF

  v0 = SendDlgItemMessageA(hWnd, 1003, 0x191u, 0x100u, (LPARAM)lParam);
  v20[0] = byte_629120;
  memset(&v20[1], 0, 255);
  v1 = 0;
  v2 = 0;
  v3 = 0;
  v4 = 0;
  v19 = v0;
  v17 = 0;
  v18 = 0;
  if ( v0 > 0 )
  {
    do
    {
      SendDlgItemMessageA(hWnd, 1003, 0x189u, lParam[v2], (LPARAM)v20);
      v5 = operator new(8u);
      v6 = v5;
      if ( v5 )
      {
        *v5 = 0;
        v5[1] = -1;
        sub_578600(v20);
        v7 = operator new(0xCu);
        if ( v7 )
        {
          *v7 = v6;
          v7[1] = 0;
          *((_BYTE *)v7 + 8) = 1;
        }
        else
        {
          v7 = 0;
        }
        v1 = v17;
        if ( v17 )
          v4[1] = v7;
        else
          v17 = v7;
        v4 = v7;
        ++v18;
      }
      ++v2;
    }
    while ( v2 < v19 );
    v3 = (CHAR ***)v17;
  }
  if ( v3 )
  {
    for ( i = *v3; *v3; i = *v3 )
    {
      v9 = *i;
      if ( !*i )
        v9 = &byte_629120;
      SendDlgItemMessageA(hWnd, 1000, 0x180u, 0, (LPARAM)v9);
      v10 = *i;
      if ( !*i )
        v10 = &byte_629120;
      v11 = SendDlgItemMessageA(hWnd, 1003, 0x18Fu, 0, (LPARAM)v10);
      SendDlgItemMessageA(hWnd, 1003, 0x182u, v11, 0);
      v3 = (CHAR ***)v3[1];
      if ( !v3 )
        break;
    }
  }
  LOBYTE(v0) = 0;
  LOBYTE(v1) = 0;
  result = sub_46BEE0(v1, v0);
  for ( j = v17; j; result = sub_5BE8AE(v14) )
  {
    v14 = j;
    v15 = *((_BYTE *)j + 8);
    j = (_DWORD *)j[1];
    if ( v15 )
    {
      v16 = (LPVOID *)*v14;
      if ( *v14 )
      {
        if ( *v16 )
          sub_5BE8AE(*v16);
        sub_5BE8AE(v16);
      }
    }
  }
  return result;
}
