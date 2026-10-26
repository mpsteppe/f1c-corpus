void __thiscall sub_4B5DA0(_DWORD *this, int a2, int a3)
{
  int v4; // ebx
  int v5; // edi
  int v6; // eax
  int v7; // ecx

  v4 = ((int (*)(void))CircularBufferCheck)();
  if ( !v4 )
  {
    PitstopActionSet(*(float *)&a3);
    v4 = CircularBufferCheck(this);
  }
  v5 = 0;
  if ( v4 > 0 )
  {
    while ( 1 )
    {
      v6 = this[622] - v5;
      if ( v6 < 0 )
        v6 += this[621];
      v7 = IndexedPointerLookup(v6);
      if ( *(float *)(a2 + 4) >= (double)*(float *)(v7 + 108) )
        break;
      if ( ++v5 >= v4 )
        return;
    }
    if ( *(float *)(a2 + 4) - *(float *)(v7 + 108) < 1.5 )
      CollisionObjectInsertion((_BYTE *)v7, (_DWORD *)a2, a3);
  }
}

