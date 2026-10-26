char __thiscall sub_4D4340(char *Buffer, int a2)
{
  int v3; // edi
  _DWORD *v4; // ebp
  _DWORD *v5; // edi
  _DWORD *v6; // eax
  _DWORD *v7; // edi
  _DWORD *v8; // eax
  _DWORD *v9; // eax
  _DWORD *v10; // edi
  _DWORD *v11; // eax
  _DWORD *v12; // eax
  _DWORD *v13; // edi
  _DWORD *v14; // ebp
  _DWORD *v15; // eax
  unsigned __int8 v17; // [esp+11h] [ebp-87h] BYREF
  unsigned __int8 i; // [esp+12h] [ebp-86h]
  char Buffera; // [esp+13h] [ebp-85h] BYREF
  int v20; // [esp+14h] [ebp-84h] BYREF
  _BYTE v21[125]; // [esp+18h] [ebp-80h] BYREF
  __int16 v22; // [esp+95h] [ebp-3h]
  char v23; // [esp+97h] [ebp-1h]

  Buffera = 0;
  sub_57A3D0(Buffer, 1u);
  sub_4D4300(a2, Buffer + 1, 64);
  sub_57A3D0(Buffer + 65, 0x20u);
  sub_57A3D0(Buffer + 97, 0x20u);
  sub_57A3D0(Buffer + 132, 4u);
  sub_57A3D0(Buffer + 136, 4u);
  sub_57A3D0(&Buffera, 1u);
  if ( Buffera )
  {
    v21[0] = byte_629120;
    memset(&v21[1], 0, 0x7Cu);
    v22 = 0;
    v23 = 0;
    v3 = *((_DWORD *)Buffer + 35);
    v4 = 0;
    v17 = 0;
    if ( v3 )
    {
      sub_4667A0((_DWORD *)(v3 + 72));
      sub_4DB110(v3 + 56);
      sub_4DB110(v3 + 40);
      if ( *(_DWORD *)(v3 + 32) )
        sub_5BE8AE(*(LPVOID *)(v3 + 32));
      sub_40D5B0((LPVOID *)(v3 + 24));
      sub_40D5B0((LPVOID *)(v3 + 16));
      sub_40D5B0((LPVOID *)(v3 + 8));
      sub_40D5B0((LPVOID *)v3);
      sub_5BE8AE((LPVOID)v3);
    }
    v5 = operator new(0x58u);
    if ( v5 )
    {
      *v5 = 0;
      v5[1] = -1;
      v5[2] = 0;
      v5[3] = -1;
      v5[4] = 0;
      v5[5] = -1;
      sub_578600(a100);
      v5[6] = 0;
      v5[7] = -1;
      v5[8] = 0;
      v5[9] = -1;
      v5[10] = 0;
      v5[11] = 0;
      v5[12] = 0;
      v5[13] = 0;
      v5[14] = 0;
      v5[15] = 0;
      v5[16] = 0;
      v5[17] = 0;
      sub_414400(v5 + 18);
    }
    else
    {
      v5 = 0;
    }
    *((_DWORD *)Buffer + 35) = v5;
    sub_4D4300(a2, v21, 128);
    sub_578600(v21);
    sub_4D4300(a2, v21, 128);
    sub_578600(v21);
    sub_4D4300(a2, v21, 128);
    sub_578600(v21);
    sub_4D4300(a2, v21, 128);
    sub_578600(v21);
    sub_4D4300(a2, v21, 128);
    sub_578600(v21);
    sub_57A3D0(&v17, 1u);
    for ( i = 0; i < v17; ++i )
    {
      v20 = 0;
      sub_57A3D0(&v20, 4u);
      v6 = operator new(4u);
      if ( v6 )
      {
        *v6 = v20;
        v4 = v6;
      }
      v7 = (_DWORD *)(*((_DWORD *)Buffer + 35) + 40);
      if ( v4 )
      {
        v8 = operator new(0xCu);
        if ( v8 )
        {
          *v8 = v4;
          v8[1] = 0;
          *((_BYTE *)v8 + 8) = 1;
        }
        else
        {
          v8 = 0;
        }
        if ( *v7 )
        {
          *(_DWORD *)(v7[1] + 4) = v8;
        }
        else
        {
          *v7 = v8;
          v7[2] = v8;
        }
        v7[1] = v8;
        ++v7[3];
      }
      v4 = 0;
    }
    sub_57A3D0(&v17, 1u);
    for ( i = 0; i < v17; ++i )
    {
      v20 = 0;
      sub_57A3D0(&v20, 4u);
      v9 = operator new(4u);
      if ( v9 )
      {
        *v9 = v20;
        v4 = v9;
      }
      v10 = (_DWORD *)(*((_DWORD *)Buffer + 35) + 56);
      if ( v4 )
      {
        v11 = operator new(0xCu);
        if ( v11 )
        {
          *v11 = v4;
          v11[1] = 0;
          *((_BYTE *)v11 + 8) = 1;
        }
        else
        {
          v11 = 0;
        }
        if ( *v10 )
        {
          *(_DWORD *)(v10[1] + 4) = v11;
        }
        else
        {
          *v10 = v11;
          v10[2] = v11;
        }
        v10[1] = v11;
        ++v10[3];
      }
      v4 = 0;
    }
    sub_57A3D0(&v17, 1u);
    for ( i = 0; i < v17; ++i )
    {
      sub_4D4300(a2, v21, 128);
      v12 = operator new(8u);
      v13 = v12;
      if ( v12 )
      {
        *v12 = 0;
        v12[1] = -1;
        sub_578600(v21);
      }
      else
      {
        v13 = 0;
      }
      v14 = (_DWORD *)(*((_DWORD *)Buffer + 35) + 72);
      if ( v13 )
      {
        v15 = operator new(0xCu);
        if ( v15 )
        {
          *v15 = v13;
          v15[1] = 0;
          *((_BYTE *)v15 + 8) = 1;
        }
        else
        {
          v15 = 0;
        }
        if ( *v14 )
        {
          *(_DWORD *)(v14[1] + 4) = v15;
        }
        else
        {
          *v14 = v15;
          v14[2] = v15;
        }
        v14[1] = v15;
        ++v14[3];
      }
    }
  }
  return 1;
}
