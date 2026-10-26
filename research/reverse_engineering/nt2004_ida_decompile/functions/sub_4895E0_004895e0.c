int __thiscall sub_4895E0(int *this)
{
  int *v1; // ebp
  _DWORD *v2; // esi
  _DWORD *v3; // edi
  void *v4; // ebp
  char *v5; // eax
  int v6; // eax
  int v7; // ebp
  _DWORD *v8; // esi
  _DWORD *v9; // eax
  int v10; // eax
  int v11; // edx
  int i; // ecx
  int v15; // [esp+14h] [ebp-Ch]
  char Buffer[8]; // [esp+18h] [ebp-8h] BYREF

  v1 = this;
  v2 = (_DWORD *)this[216];
  v3 = this + 216;
  if ( v2 )
  {
    do
    {
      v4 = v2;
      v2 = (_DWORD *)v2[1];
      sub_492CF0(v4);
      sub_5BE8AE(v4);
    }
    while ( v2 );
    v1 = this;
  }
  *v3 = 0;
  v3[1] = 0;
  v3[2] = 0;
  v3[3] = 0;
  v5 = dword_7665D8;
  if ( !dword_7665D8 )
    v5 = &byte_629120;
  sub_4E7690(v5);
  v6 = sub_4E7760(&unk_7D6A50);
  v15 = v6;
  if ( v6 && *(int *)(v6 + 1228) > 0 && *(_BYTE *)(v6 + 1164) )
  {
    v7 = 0;
    Buffer[0] = 0;
    do
    {
      v8 = operator new(8u);
      if ( v8 )
      {
        if ( sub_41F230(dword_62A170, aPaintScheme, Destination) )
        {
          strncpy(Destination, aPaintScheme, 0x1FFu);
          byte_62A37B = 0;
        }
        *v8 = 0;
        v8[1] = -1;
        sub_578600(Destination);
      }
      else
      {
        v8 = 0;
      }
      sprintf(Buffer, off_601E8C, ++v7);
      sub_578560(Buffer);
      if ( v8 )
      {
        v9 = operator new(0x10u);
        if ( v9 )
        {
          *v9 = v8;
          v9[1] = 0;
          v9[2] = 0;
          *((_BYTE *)v9 + 12) = 1;
        }
        else
        {
          v9 = 0;
        }
        if ( *v3 )
        {
          *(_DWORD *)(v3[1] + 4) = v9;
          v9[2] = v3[1];
        }
        else
        {
          *v3 = v9;
          v3[2] = v9;
        }
        v3[1] = v9;
        ++v3[3];
      }
    }
    while ( v7 < *(_DWORD *)(v15 + 1228) );
    v1 = this;
  }
  v10 = sub_492B60(*v3);
  v11 = 0;
  *v3 = v10;
  if ( v10 )
  {
    for ( i = *(_DWORD *)(v10 + 4); i; i = *(_DWORD *)(i + 4) )
    {
      *(_DWORD *)(v10 + 8) = v11;
      v11 = v10;
      v10 = i;
    }
    *(_DWORD *)(v10 + 8) = v11;
  }
  v3[2] = *v3;
  v3[1] = v10;
  if ( v1[219] >= 2 )
    return (*(int (__thiscall **)(int *, _DWORD))(*v1 + 36))(v1, 0);
  else
    return (*(int (__thiscall **)(int *, int))(*v1 + 36))(v1, 1);
}
