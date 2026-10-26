char __stdcall sub_67B522(int *a1, char *a2)
{
  char *v2; // eax
  char v3; // dl
  int v4; // ecx
  int v5; // esi
  char v6; // dl
  int v7; // esi
  char v8; // dl
  int v9; // esi
  char v10; // cl
  char v11; // dl
  char v12; // cl
  int v13; // esi
  char v14; // cl
  char v15; // dl
  char v16; // cl

  LOBYTE(v2) = (_BYTE)a1;
  v3 = *((_BYTE *)a1 + 8);
  if ( (v3 & 2) != 0 )
  {
    v4 = *a1;
    LOBYTE(v2) = *((_BYTE *)a1 + 9);
    if ( (_BYTE)v2 == 8 )
    {
      if ( v3 == 2 )
      {
        v2 = a2;
        if ( v4 )
        {
          v5 = *a1;
          do
          {
            v6 = *v2;
            *v2 = v2[2];
            v2[2] = v6;
            v2 += 3;
            --v5;
          }
          while ( v5 );
        }
      }
      else if ( v3 == 6 )
      {
        v2 = a2;
        if ( v4 )
        {
          v7 = *a1;
          do
          {
            v8 = *v2;
            *v2 = v2[2];
            v2[2] = v8;
            v2 += 4;
            --v7;
          }
          while ( v7 );
        }
      }
    }
    else if ( (_BYTE)v2 == 16 )
    {
      if ( v3 == 2 )
      {
        if ( v4 )
        {
          v2 = a2 + 1;
          v9 = *a1;
          do
          {
            v10 = *(v2 - 1);
            *(v2 - 1) = v2[3];
            v11 = v2[4];
            v2[3] = v10;
            v12 = *v2;
            *v2 = v11;
            v2[4] = v12;
            v2 += 6;
            --v9;
          }
          while ( v9 );
        }
      }
      else if ( v3 == 6 && v4 )
      {
        v2 = a2 + 1;
        v13 = *a1;
        do
        {
          v14 = *(v2 - 1);
          *(v2 - 1) = v2[3];
          v15 = v2[4];
          v2[3] = v14;
          v16 = *v2;
          *v2 = v15;
          v2[4] = v16;
          v2 += 8;
          --v13;
        }
        while ( v13 );
      }
    }
  }
  return (char)v2;
}
