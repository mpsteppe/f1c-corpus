int __thiscall sub_4C5070(void *this, int a2)
{
  __int64 v2; // rax
  int v3; // edx
  int v4; // ecx
  int v5; // eax
  int *v6; // eax
  int v7; // eax

  if ( a2 < 0 )
    return 0;
  v2 = ReadFieldAtOffset0x14(this);
  if ( SHIDWORD(v2) >= (int)v2 )
    return 0;
  BoundsCheckedIndexSetter_6760(HIDWORD(v2));
  if ( v3 < *(_DWORD *)(v4 + 20) )
  {
    v5 = *(_DWORD *)(v4 + 8);
    if ( v3 <= 0 )
    {
LABEL_7:
      if ( v5 )
      {
        v6 = *(int **)v5;
        goto LABEL_10;
      }
    }
    else
    {
      while ( v5 )
      {
        v5 = *(_DWORD *)(v5 + 4);
        if ( --v3 <= 0 )
          goto LABEL_7;
      }
    }
  }
  v6 = 0;
LABEL_10:
  v7 = *v6;
  if ( v7 >= 0 && v7 < dword_8AC390 )
    return dword_8AC394 + 1060 * v7;
  return 0;
}
