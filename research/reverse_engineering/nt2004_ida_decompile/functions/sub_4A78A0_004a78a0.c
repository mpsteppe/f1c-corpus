int **__thiscall sub_4A78A0(_DWORD *this)
{
  _DWORD *v1; // ebp
  LPVOID *v2; // esi
  int **result; // eax
  int **v4; // edi
  int *v5; // ebp
  int v6; // esi
  _DWORD *v7; // edi
  bool v8; // zf
  int **v10; // [esp+14h] [ebp-8h]
  int **v11; // [esp+18h] [ebp-4h]

  v1 = this;
  v2 = (LPVOID *)this[67];
  if ( v2 )
  {
    sub_506C70(v2 + 12);
    if ( v2[24] )
      sub_5BE8AE(v2[24]);
    sub_40D5B0(v2 + 22);
    sub_506920(v2 + 12);
    sub_4A8160(v2 + 7);
    if ( v2[4] )
      sub_5BE8AE(v2[4]);
    if ( v2[2] )
      sub_5BE8AE(v2[2]);
    if ( *v2 )
      sub_5BE8AE(*v2);
    sub_5BE8AE(v2);
  }
  v1[67] = 0;
  result = (int **)v1[68];
  if ( result )
  {
    while ( 1 )
    {
      v4 = result;
      v10 = (int **)result[1];
      v11 = result;
      if ( *((_BYTE *)result + 8) )
      {
        v5 = *result;
        if ( *result )
        {
          v6 = *v5;
          if ( *v5 )
          {
            do
            {
              v7 = (_DWORD *)v6;
              v8 = *(_BYTE *)(v6 + 8) == 0;
              v6 = *(_DWORD *)(v6 + 4);
              if ( !v8 && *v7 )
                sub_4A79D0(1);
              sub_5BE8AE(v7);
            }
            while ( v6 );
            v4 = v11;
          }
          *v5 = 0;
          v5[1] = 0;
          v5[2] = 0;
          v5[3] = 0;
          sub_5BE8AE(v5);
        }
        v1 = this;
      }
      sub_5BE8AE(v4);
      result = v10;
      if ( !v10 )
        break;
      result = v10;
    }
  }
  v1[68] = 0;
  v1[69] = 0;
  v1[70] = 0;
  v1[71] = 0;
  return result;
}
