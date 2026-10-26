int __thiscall sub_61DD30(int this)
{
  int v2; // ecx
  int i; // edx
  int v4; // edi
  int v5; // eax
  int v6; // edi
  int v7; // ebx
  int v8; // ebx
  int v9; // ebp
  int v10; // eax
  char v11; // cl
  int v12; // eax
  int v13; // edi
  int v14; // ebx
  int v15; // ebp
  int v16; // edx
  int v17; // edi
  int v18; // ebx
  int v19; // edi
  int v20; // ecx

  if ( *(_DWORD *)(this + 48) )
  {
    (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(this + 48) + 28))(*(_DWORD *)(this + 48));
  }
  else
  {
    v2 = *(_DWORD *)(this + 32);
    for ( i = 0; i < v2; ++i )
    {
      v4 = *(_DWORD *)(*(_DWORD *)(this + 40) + 4 * i);
      v5 = 0;
      if ( v2 > 0 )
      {
        do
        {
          ++v5;
          *(double *)(v4 + 8 * v5 - 8) = 0.0;
        }
        while ( v5 < *(_DWORD *)(this + 32) );
      }
      *(double *)(*(_DWORD *)(this + 44) + 8 * i) = 0.0;
      v2 = *(_DWORD *)(this + 32);
    }
  }
  sub_61DC40((_DWORD *)this);
  v6 = 0;
  if ( *(int *)this > 0 )
  {
    v7 = 0;
    do
    {
      sub_61B750((double *)(v7 + *(_DWORD *)(this + 4)));
      ++v6;
      v7 += 584;
    }
    while ( v6 < *(_DWORD *)this );
  }
  v8 = 0;
  if ( *(int *)(this + 8) > 0 )
  {
    v9 = 0;
    do
    {
      v10 = *(_DWORD *)(this + 12);
      v11 = *(_BYTE *)(v10 + v9 + 48);
      v12 = v9 + v10;
      if ( (v11 & 1) != 0 )
      {
        v13 = *(_DWORD *)(*(_DWORD *)(v12 + 8) + 48);
        sub_61DCB0(this, v13++);
        sub_61DCB0(this, v13);
        sub_61DCB0(this, v13 + 1);
      }
      ++v8;
      v9 += 56;
    }
    while ( v8 < *(_DWORD *)(this + 8) );
  }
  v14 = 0;
  if ( *(int *)(this + 16) > 0 )
  {
    v15 = 0;
    do
    {
      v16 = *(_DWORD *)(this + 20);
      if ( (*(_BYTE *)(v16 + v15 + 48) & 1) != 0 )
      {
        v17 = *(_DWORD *)(*(_DWORD *)(v16 + v15 + 8) + 124);
        sub_61DCB0(this, v17);
        sub_61DCB0(this, v17 + 1);
      }
      ++v14;
      v15 += 56;
    }
    while ( v14 < *(_DWORD *)(this + 16) );
  }
  v18 = 0;
  if ( *(int *)(this + 24) > 0 )
  {
    v19 = 0;
    do
    {
      v20 = *(_DWORD *)(this + 28);
      if ( (*(_BYTE *)(v19 + v20 + 72) & 1) != 0 )
        sub_61DCB0(this, *(_DWORD *)(*(_DWORD *)(v19 + v20 + 8) + 48));
      ++v18;
      v19 += 80;
    }
    while ( v18 < *(_DWORD *)(this + 24) );
  }
  if ( *(_DWORD *)(this + 48) )
    return (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 48) + 20))(*(_DWORD *)(this + 48));
  else
    return sub_61C150((_DWORD *)(this + 52), *(_DWORD *)(this + 40), *(_DWORD *)(this + 44), *(_DWORD *)(this + 32));
}
