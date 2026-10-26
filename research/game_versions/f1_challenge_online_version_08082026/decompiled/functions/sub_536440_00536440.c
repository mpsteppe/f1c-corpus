int __thiscall sub_536440(char *this)
{
  unsigned int v2; // ebp
  unsigned int v3; // eax
  int v4; // ecx
  int v5; // edx
  int v6; // eax
  unsigned int v7; // ecx
  int v8; // esi
  int v9; // ecx
  _WORD *v10; // ecx
  __int16 v11; // ax
  unsigned int v12; // esi
  _WORD *v13; // ecx
  __int16 v14; // ax
  int result; // eax
  unsigned int v16; // esi
  int v17; // ecx
  int v18; // edx
  int v19; // eax
  int v20; // edi
  int v21; // ecx

  v2 = *(_DWORD *)(this + 34);
  do
  {
    v3 = *(_DWORD *)(this + 98);
    v4 = *(_DWORD *)(this + 106);
    v5 = *(_DWORD *)(this + 50) - v3 - v4;
    if ( v5 )
    {
      if ( v5 == -1 )
      {
        v5 = -2;
        goto LABEL_20;
      }
    }
    else if ( !v3 && !v4 )
    {
      v5 = v2;
      goto LABEL_20;
    }
    if ( v3 >= *(_DWORD *)(this + 34) + v2 - 262 )
    {
      qmemcpy(*(void **)(this + 46), (const void *)(*(_DWORD *)(this + 46) + v2), v2);
      v6 = *(_DWORD *)(this + 82);
      v7 = *(_DWORD *)(this + 98) - v2;
      *(_DWORD *)(this + 102) -= v2;
      v8 = *(_DWORD *)(this + 66);
      *(_DWORD *)(this + 98) = v7;
      v9 = *(_DWORD *)(this + 58);
      *(_DWORD *)(this + 82) = v6 - v2;
      v10 = (_WORD *)(v9 + 2 * v8);
      do
      {
        if ( (unsigned __int16)*--v10 < v2 )
          v11 = 0;
        else
          v11 = *v10 - v2;
        --v8;
        *v10 = v11;
      }
      while ( v8 );
      v12 = v2;
      v13 = (_WORD *)(*(_DWORD *)(this + 54) + 2 * v2);
      do
      {
        if ( (unsigned __int16)*--v13 < v2 )
          v14 = 0;
        else
          v14 = *v13 - v2;
        --v12;
        *v13 = v14;
      }
      while ( v12 );
      v5 += v2;
    }
LABEL_20:
    result = *(_DWORD *)(*(_DWORD *)this + 4);
    if ( !result )
      break;
    result = sub_536560(v5);
    v16 = result + *(_DWORD *)(this + 106);
    *(_DWORD *)(this + 106) = v16;
    if ( v16 >= 3 )
    {
      v17 = *(_DWORD *)(this + 98);
      v18 = *(_DWORD *)(this + 46);
      v19 = *(unsigned __int8 *)(v17 + v18);
      v20 = v17 + v18;
      v21 = *(_DWORD *)(this + 78);
      *(_DWORD *)(this + 62) = v19;
      result = *(_DWORD *)(this + 74) & (*(unsigned __int8 *)(v20 + 1) ^ (v19 << v21));
      *(_DWORD *)(this + 62) = result;
    }
    if ( v16 >= 0x106 )
      break;
    result = *(_DWORD *)(*(_DWORD *)this + 4);
  }
  while ( result );
  return result;
}
