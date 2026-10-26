int *sub_4906E0()
{
  _DWORD *v0; // eax
  _DWORD *v1; // esi
  _DWORD *v2; // ebp
  _DWORD *v3; // eax
  _DWORD *v4; // edi
  int v5; // ebx
  _DWORD *v6; // eax
  int v7; // eax
  int i; // ebp
  int v9; // edi
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  _DWORD *v14; // [esp+0h] [ebp-4h]
  _DWORD *v15; // [esp+0h] [ebp-4h]

  if ( (byte_7CD9C8 & 1) == 0 )
  {
    byte_7CD9C8 |= 1u;
    v0 = (_DWORD *)sub_587C03(32);
    v1 = v0;
    if ( v0 )
    {
      *v0 = 0;
      v0[1] = 0;
      v0[2] = 0;
      v0[3] = 0;
      v0[4] = 0;
      v0[5] = 0;
      v0[6] = 0;
      v0[7] = 0;
      v2 = (_DWORD *)sub_587C03(4);
      if ( v2 )
      {
        v3 = (_DWORD *)sub_587C03(516);
        if ( v3 )
        {
          *v3 = 32;
          v14 = v3 + 1;
          v4 = v3 + 1;
          v5 = 32;
          do
          {
            sub_4912F0(v4);
            v4 += 4;
            --v5;
          }
          while ( v5 );
          v6 = v14;
        }
        else
        {
          v6 = 0;
        }
        *v2 = v6;
        v15 = v2;
        v7 = sub_587C03(12);
        if ( v7 )
        {
          *(_DWORD *)v7 = v2;
          *(_DWORD *)(v7 + 4) = 0;
          *(_BYTE *)(v7 + 8) = 1;
        }
        else
        {
          v7 = 0;
        }
        if ( *v1 )
        {
          *(_DWORD *)(v1[1] + 4) = v7;
        }
        else
        {
          *v1 = v7;
          v1[2] = v7;
        }
        v1[1] = v7;
        ++v1[3];
      }
      else
      {
        v15 = 0;
      }
      for ( i = 0; i < 512; i += 16 )
      {
        v9 = i + *v15;
        if ( v9 )
        {
          v10 = sub_587C03(12);
          if ( v10 )
          {
            *(_DWORD *)v10 = v9;
            *(_DWORD *)(v10 + 4) = 0;
            *(_BYTE *)(v10 + 8) = 0;
          }
          else
          {
            v10 = 0;
          }
          v11 = v1[4];
          if ( v11 )
          {
            *(_DWORD *)(v10 + 4) = v11;
          }
          else
          {
            v1[5] = v10;
            v1[6] = v10;
          }
          v1[4] = v10;
          ++v1[7];
        }
      }
      dword_7CD9CC = (int)v1;
    }
    else
    {
      dword_7CD9CC = 0;
    }
    if ( sub_587C03(4) )
      v12 = sub_491710(1);
    else
      v12 = 0;
    dword_7CD9D0 = v12;
    sub_587B3E(sub_490850);
  }
  return &dword_7CD9CC;
}
