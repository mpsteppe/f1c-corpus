int __thiscall sub_4C50E0(void *this, int a2)
{
  __int64 v2; // rax
  int v3; // edx
  int v4; // ecx
  _DWORD *v5; // eax

  if ( a2 < 0 )
    return 0;
  v2 = ReadFieldAtOffset0x14(this);
  if ( SHIDWORD(v2) >= (int)v2 )
    return 0;
  BoundsCheckedIndexSetter_6760(HIDWORD(v2));
  if ( v3 >= *(_DWORD *)(v4 + 20) )
    return MEMORY[0];
  v5 = *(_DWORD **)(v4 + 8);
  if ( v3 > 0 )
  {
    while ( v5 )
    {
      v5 = (_DWORD *)v5[1];
      if ( --v3 <= 0 )
        goto LABEL_7;
    }
    return MEMORY[0];
  }
LABEL_7:
  if ( !v5 )
    return MEMORY[0];
  return *(_DWORD *)*v5;
}

