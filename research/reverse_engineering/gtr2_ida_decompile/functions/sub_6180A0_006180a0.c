char __thiscall sub_6180A0(int this, int a2)
{
  int v3; // ecx
  unsigned int v4; // esi
  char result; // al
  int v6; // eax
  size_t v7; // ebp
  unsigned int v8; // ecx
  void *v9; // eax
  void *v10; // [esp+10h] [ebp+4h]

  v3 = *(_DWORD *)(this + 4);
  v4 = a2 + *(_DWORD *)(this + 16);
  result = 1;
  if ( v4 > 8 * v3 )
  {
    v6 = *(_DWORD *)(this + 24);
    v7 = v6 + v3;
    if ( (unsigned int)(v6 + v3) < 0x1F400 )
    {
      v8 = 8 * v7;
      do
      {
        if ( v8 >= v4 )
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
      j__free(*(void **)this);
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
