int __thiscall sub_41FE00(void *this)
{
  int v1; // ebp
  int v2; // eax
  int v3; // ebx
  int v4; // edi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // esi
  int v10; // eax
  int v11; // eax
  int v13; // [esp-4h] [ebp-68h]
  _BYTE v15[80]; // [esp+14h] [ebp-50h] BYREF

  v1 = 0;
  v2 = sub_4C2990(&dword_7D2DB0);
  if ( v2 )
  {
    v3 = v2 - 1;
    if ( v2 - 1 >= 0 )
    {
      v4 = 4 * v3 + 216;
      do
      {
        v5 = LinkedListDereference(&dword_7D2DB0);
        if ( *(_DWORD *)(v4 + FixedOffsetReturn(v5)) == 10 )
        {
          v6 = LinkedListDereference(&dword_7D2DB0);
          v7 = FixedOffsetReturn(v6);
          v13 = SceneNamePointer(v7);
          v8 = sub_588410(this, v13);
        }
        else
        {
          v9 = 0;
          v10 = LinkedListDereference(&dword_7D2DB0);
          if ( ActiveEntityCounter(v10) <= 0 )
            return v1;
          while ( 1 )
          {
            LinkedListDereference(&dword_7D2DB0);
            ShortComputation_13a0(v9);
            SceneNameLookupBySeason(v15, 80);
            LinkedListDereference(&dword_7D2DB0);
            if ( *(_DWORD *)(v4 + ShortComputation_13a0(v9)) == 10 )
              break;
            ++v9;
            v11 = LinkedListDereference(&dword_7D2DB0);
            if ( v9 >= ActiveEntityCounter(v11) )
              return v1;
          }
          v8 = sub_588410(v15, this);
        }
        if ( v8 )
          break;
        ++v1;
        --v3;
        v4 -= 4;
      }
      while ( v3 >= 0 );
    }
  }
  return v1;
}

