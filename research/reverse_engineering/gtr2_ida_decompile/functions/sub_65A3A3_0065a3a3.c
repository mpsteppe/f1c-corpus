int __thiscall sub_65A3A3(int this)
{
  char *v2; // esi
  _BYTE *v3; // edx
  _BYTE *v4; // eax
  unsigned int v5; // ebx
  char v6; // cl
  unsigned int v7; // ebx
  char ArgList[256]; // [esp+8h] [ebp-104h] BYREF
  unsigned int v10; // [esp+108h] [ebp-4h]

  v2 = **(char ***)(this + 620);
  sub_65D86A();
  if ( *(_DWORD *)(this + 80) )
  {
    while ( (unsigned int)v2 < **(_DWORD **)(this + 620) && (*v2 == 32 || *v2 == 9) )
      ++v2;
    v10 = 0;
    v3 = v2 + 2;
    v4 = v2 + 1;
    while ( 1 )
    {
      v5 = **(_DWORD **)(this + 620);
      if ( (unsigned int)v2 >= v5 )
      {
LABEL_21:
        ArgList[v10] = 0;
        sub_65DD1F(this + 24, this + 632, 0, "error: %s", (char)ArgList);
        *(_DWORD *)(this + 72) = 1;
        *(_DWORD *)(this + 68) = 1;
        return 0;
      }
      v6 = *v2;
      if ( *v2 != 92 )
        break;
      if ( (unsigned int)v4 < v5 && *v4 == 10 )
      {
        v2 += 2;
        v4 += 2;
        v3 += 2;
      }
      else
      {
        if ( (unsigned int)v3 >= v5 || *v4 != 13 || *v3 != 10 )
          break;
        v2 += 3;
        v4 += 3;
        v3 += 3;
      }
LABEL_20:
      if ( v10 >= 0xFF )
        goto LABEL_21;
    }
    if ( v6 != 13 )
    {
      v7 = v10++;
      ArgList[v7] = v6;
    }
    ++v2;
    ++v4;
    ++v3;
    goto LABEL_20;
  }
  return 0;
}
