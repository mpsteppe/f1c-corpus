int __thiscall sub_5F34A0(int this, int a2, int a3)
{
  int v3; // ebx
  int v5; // ebp
  _BYTE *v6; // eax
  int v7; // ecx
  _BYTE *v8; // eax
  int v9; // ecx
  int v10; // edi

  v3 = 0;
  v5 = 2;
  if ( a2 )
  {
    if ( (*(_BYTE *)(this + 4) & 1) != 0 )
    {
      if ( a2 == 1 )
      {
        v3 = 1;
      }
      else
      {
        v5 = 3;
        v3 = a2;
        if ( a2 >= *(_DWORD *)(this + 4872) )
          v3 = *(_DWORD *)(this + 4872);
      }
      v8 = (_BYTE *)(this + 3057);
      v9 = 8;
      do
      {
        *v8 = 1;
        v8 += 248;
        --v9;
      }
      while ( v9 );
    }
  }
  else
  {
    v3 = 1;
    v6 = (_BYTE *)(this + 3057);
    v7 = 8;
    do
    {
      *v6 = 0;
      v6 += 248;
      --v7;
    }
    while ( v7 );
  }
  if ( a3 != -1 )
  {
    if ( (*(_BYTE *)(this + 4) & 2) != 0 )
      *(_DWORD *)(this + 8) = (*(int (__stdcall **)(_DWORD, int, int, int))(**(_DWORD **)(this + 9548) + 276))(
                                *(_DWORD *)(this + 9548),
                                a3,
                                6,
                                v5);
    if ( (*(_DWORD *)(this + 4) & 0x4000) != 0 )
      *(_DWORD *)(this + 8) = (*(int (__stdcall **)(_DWORD, int, int, int))(**(_DWORD **)(this + 9548) + 276))(
                                *(_DWORD *)(this + 9548),
                                a3,
                                5,
                                v5);
    *(_DWORD *)(this + 8) = (*(int (__stdcall **)(_DWORD, int, int, int))(**(_DWORD **)(this + 9548) + 276))(
                              *(_DWORD *)(this + 9548),
                              a3,
                              10,
                              v3);
    goto LABEL_25;
  }
  v10 = 0;
  if ( *(int *)(this + 4824) <= 0 )
  {
LABEL_25:
    *(_DWORD *)(this + 4868) = v3;
    return 0;
  }
  do
  {
    if ( (*(_BYTE *)(this + 4) & 2) != 0 )
      *(_DWORD *)(this + 8) = (*(int (__stdcall **)(_DWORD, int, int, int))(**(_DWORD **)(this + 9548) + 276))(
                                *(_DWORD *)(this + 9548),
                                v10,
                                6,
                                v5);
    if ( (*(_DWORD *)(this + 4) & 0x4000) != 0 )
      *(_DWORD *)(this + 8) = (*(int (__stdcall **)(_DWORD, int, int, int))(**(_DWORD **)(this + 9548) + 276))(
                                *(_DWORD *)(this + 9548),
                                v10,
                                5,
                                v5);
    *(_DWORD *)(this + 8) = (*(int (__stdcall **)(_DWORD, int, int, int))(**(_DWORD **)(this + 9548) + 276))(
                              *(_DWORD *)(this + 9548),
                              v10++,
                              10,
                              v3);
  }
  while ( v10 < *(_DWORD *)(this + 4824) );
  *(_DWORD *)(this + 4868) = v3;
  return 0;
}
