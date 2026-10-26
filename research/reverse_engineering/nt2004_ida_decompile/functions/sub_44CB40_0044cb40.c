int __thiscall sub_44CB40(void **Buffer, _DWORD *Buffera)
{
  _DWORD *v2; // esi
  __int16 v5; // ax
  bool v6; // cc
  int v7; // ebx
  int v8; // ebp
  unsigned __int8 v9; // [esp+13h] [ebp-5h] BYREF
  int v10; // [esp+14h] [ebp-4h]

  v2 = Buffera;
  if ( sub_57A3D0(Buffer, 4u) != 4 )
    return -1;
  if ( sub_57A3D0(Buffer + 1, 4u) != 4 )
    return -1;
  if ( sub_57A3D0(&Buffera, 1u) != 1 )
    return -1;
  v5 = (char)Buffera;
  v6 = (char)Buffera <= -3;
  *((_WORD *)Buffer + 4) = (char)Buffera;
  if ( v6 )
    return -1;
  v7 = 2;
  if ( v5 >= 2 )
    return -1;
  v8 = 0;
  if ( v5 < 0 )
  {
    if ( v5 == -1 )
    {
      v7 = 1;
    }
    else if ( v5 != -2 )
    {
      v7 = (int)Buffera;
    }
    Buffer[3] = (void *)(v2[9] + 92 * v2[7]);
    v2[7] += v7;
    if ( v7 > 0 )
    {
      v10 = 0;
      while ( !sub_44C3A0((char *)Buffer[3] + v10, (int)v2) )
      {
        ++v8;
        v10 += 92;
        if ( v8 >= v7 )
          return 0;
      }
      return -1;
    }
    return 0;
  }
  if ( sub_57A3D0(&v9, 1u) != 1 )
    return -1;
  *((_WORD *)Buffer + 5) = v9;
  Buffer[3] = (void *)(v2[12] + 16 * v2[10]);
  v2[10] += 2;
  if ( sub_44CB40(Buffer[3], (int)v2) )
    return -1;
  if ( !sub_44CB40((char *)Buffer[3] + 16, (int)v2) )
    return 0;
  return -1;
}
