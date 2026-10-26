int __thiscall sub_598C90(int this)
{
  int v2; // eax
  _DWORD *v3; // ebx
  _DWORD *v4; // eax
  _DWORD *v5; // ecx
  _DWORD *v7; // eax
  int v8; // edi
  int v9; // esi
  int v11; // [esp+4h] [ebp-4h]

  if ( (*(_BYTE *)(this + 156) & 2) != 0 )
    return -2;
  v2 = *(_DWORD *)(this + 136) - 1;
  --*(_DWORD *)(this + 132);
  *(_DWORD *)(this + 136) = v2;
  if ( v2 )
    return -2;
  v11 = 0;
  if ( *(int *)(this + 172) > 0 )
  {
    v3 = (_DWORD *)(*(_DWORD *)(this + 176) + 140);
    do
    {
      v4 = *(_DWORD **)(*(_DWORD *)(this + 192) + 40);
      if ( v4 )
      {
        v5 = (_DWORD *)*v3;
        while ( v4 != v5 )
        {
          v4 = (_DWORD *)v4[3];
          if ( !v4 )
            goto LABEL_15;
        }
        if ( (*v5)-- == 1 )
        {
          v7 = (_DWORD *)*v3;
          v8 = 0;
          if ( *(int *)(*v3 + 88) > 0 )
          {
            v9 = 0;
            do
            {
              sub_5A2660(&v7[v9]);
              v7 = (_DWORD *)*v3;
              ++v8;
              v9 += 24;
            }
            while ( v8 < *(_DWORD *)(*v3 + 88) );
          }
          sub_599CB0(*v3);
          *v3 = 0;
        }
      }
LABEL_15:
      v3 += 37;
      ++v11;
    }
    while ( v11 < *(_DWORD *)(this + 172) );
  }
  *(_DWORD *)(this + 156) |= 3u;
  return 0;
}
