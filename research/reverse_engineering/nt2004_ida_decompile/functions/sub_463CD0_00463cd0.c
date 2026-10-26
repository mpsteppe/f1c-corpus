_DWORD *__thiscall sub_463CD0(_DWORD *this, int a2, void *a3, _DWORD *a4)
{
  _DWORD *v4; // esi
  int v5; // ecx
  _DWORD *result; // eax
  int v7; // edx
  int v8; // ebx
  int v9; // ebp
  _DWORD *v10; // [esp+8h] [ebp-4h]

  v4 = this;
  v5 = *this;
  LOBYTE(result) = 0;
  v7 = 0;
  v10 = v4;
  if ( *(int *)(v5 + 6512) > 0 )
  {
    v8 = 0;
    v9 = 6320;
    do
    {
      if ( *(_DWORD *)(v5 + v9) == a2 )
      {
        result = a4;
        qmemcpy(a3, (const void *)(v8 + v5 + 752), 0x74u);
        v4 = v10;
        *a4 = v7;
        LOBYTE(result) = 1;
      }
      v5 = *v4;
      ++v7;
      v9 += 4;
      v8 += 116;
    }
    while ( v7 < *(_DWORD *)(*v4 + 6512) );
  }
  return result;
}
