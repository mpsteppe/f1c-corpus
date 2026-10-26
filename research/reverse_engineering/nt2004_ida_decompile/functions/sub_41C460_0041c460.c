char __thiscall sub_41C460(_DWORD *this, _DWORD *a2, char a3)
{
  _DWORD *v4; // edi
  int v6; // ebx
  int v7; // esi
  int v8; // eax
  int v9; // ecx
  int v10; // ecx
  int v11; // edi
  int *v12; // edx
  int v13; // ecx
  char v14; // bl
  int v15; // [esp+Ch] [ebp-Ch]
  int v16; // [esp+10h] [ebp-8h]
  int v17; // [esp+14h] [ebp-4h]

  sub_59FDC0(
    0,
    0,
    this[1],
    0,
    0,
    *(_DWORD *)(*(_DWORD *)(*this + 16) + 28),
    *(_DWORD *)(*(_DWORD *)(*this + 16) + 32),
    -2,
    0);
  v4 = a2;
  if ( !a2 && !a3 )
    return 1;
  v6 = 0;
  v7 = sub_59FD80(1, 0);
  v17 = v7;
  v15 = 0;
  if ( a2 )
  {
    if ( a2[12] == 8 )
    {
      v8 = this[1];
      if ( a2[7] >= *(_DWORD *)(v8 + 28) && a2[8] >= *(_DWORD *)(v8 + 32) )
        v15 = sub_59FD80(0, 0);
    }
  }
  if ( v7 )
  {
    v9 = this[1];
    v16 = 0;
    if ( *(int *)(v9 + 28) > 0 )
    {
      v10 = *(_DWORD *)(v9 + 32);
      do
      {
        v11 = 0;
        if ( v10 > 0 )
        {
          v12 = (int *)(v7 + 4 * v6);
          do
          {
            if ( v15 )
            {
              v13 = *(int *)((char *)v12 + v15 - v7) ^ (*(int *)((char *)v12 + v15 - v7) ^ *v12) & 0xFFFFFF;
            }
            else
            {
              v13 = *v12;
              if ( a3 )
                v13 |= 0xFF000000;
            }
            *v12 = v13;
            v10 = *(_DWORD *)(this[1] + 32);
            ++v6;
            ++v12;
            ++v11;
          }
          while ( v11 < v10 );
          v7 = v17;
        }
        ++v16;
      }
      while ( v16 < *(_DWORD *)(this[1] + 28) );
      v4 = a2;
    }
    v14 = 1;
  }
  else
  {
    v14 = 0;
  }
  if ( v4 )
    sub_59FDA0(0, 0);
  sub_59FDA0(1, 0);
  return v14;
}
