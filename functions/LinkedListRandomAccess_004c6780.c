int __thiscall sub_4C6780(void *this, int a2)
{
  int v2; // ebx
  __int64 v3; // rax
  _DWORD *v4; // ecx
  int v5; // edx
  int v6; // ecx
  int v7; // esi
  _DWORD *v8; // eax
  int v9; // eax
  int *v10; // eax
  int v11; // eax

  v2 = 0;
  if ( a2 < 0 )
    return v2;
  v3 = ReadFieldAtOffset0x14(this);
  if ( SHIDWORD(v3) >= (int)v3 )
    return v2;
  BoundsCheckedIndexSetter_6760(v4, SHIDWORD(v3));
  v7 = v5;
  if ( v5 >= *(_DWORD *)(v6 + 20) )
    return v2;
  v8 = *(_DWORD **)(v6 + 8);
  if ( v5 <= 0 )
  {
LABEL_7:
    if ( !v8 || !*v8 )
      return v2;
    if ( v5 < *(_DWORD *)(v6 + 20) )
    {
      v9 = *(_DWORD *)(v6 + 8);
      if ( v5 <= 0 )
      {
LABEL_13:
        if ( v9 )
        {
          v10 = *(int **)v9;
          goto LABEL_16;
        }
      }
      else
      {
        while ( v9 )
        {
          v9 = *(_DWORD *)(v9 + 4);
          if ( --v5 <= 0 )
            goto LABEL_13;
        }
      }
    }
    v10 = 0;
LABEL_16:
    v11 = *v10;
    if ( v11 >= 0 && v11 < dword_8AC488 )
      return dword_8AC490 + 396 * v11;
    return v2;
  }
  while ( v8 )
  {
    v8 = (_DWORD *)v8[1];
    if ( --v7 <= 0 )
      goto LABEL_7;
  }
  return v2;
}
