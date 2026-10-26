void __thiscall sub_5E3670(_DWORD *this, int a2, int a3, int a4)
{
  int v4; // ebx
  int v6; // esi
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // ebp
  int v12; // edx
  int v13; // ecx
  int v14; // eax
  int i; // [esp+18h] [ebp+8h]

  v4 = 0;
  if ( a3 )
  {
    v9 = sub_5E8220(99);
    v10 = sub_5E80D0(a4 + v9);
    v11 = *(_DWORD *)(v10 + 80);
    if ( *(int *)(v10 + 4) > 1 )
    {
      v12 = 0;
      if ( (int)this[90] > 0 )
      {
        v13 = 0;
        do
        {
          v14 = v13 + this[91];
          if ( *(_DWORD *)(v14 + 4) == a3 && a2 < v11 )
            *(_DWORD *)(v14 + 92) = a2;
          ++v12;
          v13 += 108;
        }
        while ( v12 < this[90] );
      }
    }
  }
  else
  {
    for ( i = 0; i < this[90]; ++i )
    {
      v6 = v4 + this[91];
      v7 = sub_5E8220(99);
      v8 = sub_5E80D0(a4 + v7);
      if ( *(int *)(v8 + 4) > 1 && a2 < *(_DWORD *)(v8 + 80) )
        *(_DWORD *)(v6 + 92) = a2;
      v4 += 108;
    }
  }
}
