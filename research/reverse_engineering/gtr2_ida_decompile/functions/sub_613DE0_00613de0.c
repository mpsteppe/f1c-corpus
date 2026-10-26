char *__thiscall sub_613DE0(int this, char *Buffer, int MaxCount)
{
  int v4; // eax
  char *result; // eax
  char *v6; // esi
  char *v7; // edi
  int v8; // eax
  int v9; // eax
  int v10; // ecx
  char v11; // dl

  v4 = *(_DWORD *)(this + 20);
  if ( !v4 )
    return fgets(Buffer, MaxCount, *(FILE **)(this + 4));
  if ( v4 != 5 )
    return (char *)sub_62AF80(MaxCount);
  v6 = Buffer;
  v7 = *(_DWORD *)(*(_DWORD *)(this + 4) + 20) != *(_DWORD *)(*(_DWORD *)(this + 4) + 24) ? Buffer : 0;
  while ( 1 )
  {
    v8 = 32;
    if ( MaxCount - 1 <= 32 )
      v8 = MaxCount - 1;
    v9 = sub_613A50(*(_DWORD **)(this + 4), (int)v6, v8);
    v10 = 0;
    if ( v9 > 0 )
      break;
LABEL_11:
    if ( v9 == MaxCount - 1 )
    {
      result = v7;
      v6[MaxCount - 1] = 0;
      return result;
    }
    if ( !v9 )
    {
      result = v7;
      *v6 = 0;
      return result;
    }
    v6 += v9;
    MaxCount -= v9;
  }
  while ( 1 )
  {
    v11 = v6[v10++];
    if ( v11 == 10 )
      break;
    if ( v10 >= v9 )
      goto LABEL_11;
  }
  *(_DWORD *)(*(_DWORD *)(this + 4) + 24) += v10 - v9;
  result = v7;
  v6[v10] = 0;
  return result;
}
