char __thiscall sub_57BA00(int this, int a2)
{
  int v3; // ecx
  char result; // al
  unsigned int v5; // esi
  int v6; // eax
  unsigned int v7; // ebp
  unsigned int v8; // ecx
  void *v9; // eax
  void *v10; // [esp+10h] [ebp+4h]

  v3 = *(_DWORD *)(this + 4);
  result = 1;
  v5 = a2 + *(_DWORD *)(this + 16);
  if ( v5 > 8 * v3 )
  {
    v6 = *(_DWORD *)(this + 24);
    v7 = v6 + v3;
    if ( (unsigned int)(v6 + v3) < 0x1F400 )
    {
      v8 = 8 * v7;
      do
      {
        if ( v8 >= v5 )
          break;
        v7 += v6;
        v8 += 8 * v6;
      }
      while ( v7 < 0x1F400 );
    }
    v9 = operator new(v7);
    v10 = v9;
    if ( v9 )
    {
      qmemcpy(v9, *(const void **)this, *(_DWORD *)(this + 4));
      sub_5BE8AE();
      *(_DWORD *)this = v10;
      *(_DWORD *)(this + 4) = v7;
      return 1;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
