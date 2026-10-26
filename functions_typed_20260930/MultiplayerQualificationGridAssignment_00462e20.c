char __thiscall sub_462E20(void *this)
{
  int v2; // edi
  int v3; // esi
  const char *v4; // eax
  char result; // al
  int v6; // esi
  char v7; // [esp+Bh] [ebp-Dh]
  int v8; // [esp+Ch] [ebp-Ch]
  int v9; // [esp+10h] [ebp-8h]
  int v10; // [esp+14h] [ebp-4h]

  v7 = 0;
  v10 = SingleFunctionDispatch(this);
  v8 = 0;
  if ( *(char *)(*(_DWORD *)this + 16345) <= 0 )
    goto LABEL_19;
  v9 = 0;
  do
  {
    v2 = 0;
    v3 = 15896;
    while ( 1 )
    {
      if ( dword_7C569C != 5 && StringSplitLoop(dword_8AD25C, 1, (int)aDDevF119992002_1, 6774) )
        DebugLogWrite(
          (int)dword_8AD25C,
          (int)"       comparing NODEIDs (nodemap[%d]=%d,pos[%d]=%d)",
          v2,
          *(_DWORD *)(v3 + *(_DWORD *)this),
          v8,
          *(_DWORD *)(v9 + *(_DWORD *)this + 16346));
      if ( *(_DWORD *)(v3 + *(_DWORD *)this) == *(_DWORD *)(v9 + *(_DWORD *)this + 16346) )
        break;
      v3 += 4;
      ++v2;
      if ( v3 >= 16312 )
        goto LABEL_17;
    }
    if ( v10 == *(_DWORD *)(*(_DWORD *)this + 4 * v2 + 15896) )
      v7 = 1;
    MEMORY[0x5F0730][4656 * v2] = v8 + 1;
    if ( dword_7C569C != 5 && StringSplitLoop(dword_8AD25C, 1, (int)aDDevF119992002_1, 6783) )
    {
      v4 = aLocal;
      if ( v10 != *(_DWORD *)(*(_DWORD *)this + 4 * v2 + 15896) )
        v4 = byte_5EA438;
      DebugLogWrite((int)dword_8AD25C, (int)"--Set slot %d to place %d %s", v2, v8 + 1, v4);
    }
LABEL_17:
    v9 += 4;
    ++v8;
  }
  while ( v8 < *(char *)(*(_DWORD *)this + 16345) );
  result = v7;
  if ( !v7 )
  {
LABEL_19:
    v6 = dword_5C329C;
    ConditionalFieldSetter(dword_7C54E8 + 16436, dword_5C329C);
    result = FieldCopy(dword_7C54E8 + 16436);
    if ( dword_7C569C != 5 )
    {
      result = StringSplitLoop(dword_8AD25C, 1, (int)aDDevF119992002_1, 6794);
      if ( result )
        return DebugLogWrite(
                 (int)dword_8AD25C,
                 (int)"!!!!!  Could not find self in server's qualification view, setting self in last position (%d)",
                 v6);
    }
  }
  return result;
}

