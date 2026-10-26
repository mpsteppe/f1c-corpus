int __thiscall sub_65E657(int this, _BYTE *a2, _DWORD *a3)
{
  unsigned int v5; // ecx
  char *v6; // esi
  _BYTE *v7; // ecx
  char v8; // al
  unsigned int v9; // edx
  _BYTE *v10; // ebx
  char *v11; // esi
  _BYTE *v12; // edx
  _BYTE *v13; // eax
  int v15; // [esp+Ch] [ebp-8h]
  char *v16; // [esp+10h] [ebp-4h]
  unsigned int v17; // [esp+1Ch] [ebp+8h]
  char v18; // [esp+1Fh] [ebp+Bh]

  v5 = *(_DWORD *)(this + 4);
  if ( (unsigned int)a2 >= v5 )
    return 0;
  if ( *a2 == 34 )
  {
    v18 = 34;
    goto LABEL_7;
  }
  if ( *a2 != 60 || (*(_BYTE *)(this + 40) & 8) == 0 )
    return 0;
  v18 = 62;
LABEL_7:
  v6 = a2 + 1;
  v16 = a2 + 1;
  if ( (unsigned int)(a2 + 1) < v5 )
  {
    v7 = a2 + 2;
    do
    {
      v8 = *v6;
      if ( v18 == *v6 || v8 == 10 )
        break;
      if ( v8 == 92 && (*(_BYTE *)(this + 40) & 4) == 0 )
      {
        v9 = *(_DWORD *)(this + 4);
        ++v6;
        ++v7;
        if ( (unsigned int)v6 < v9 )
        {
          if ( *v6 != 10 )
          {
            if ( *v6 != 13 || (unsigned int)v7 >= v9 || *v7 != 10 )
              goto LABEL_20;
            ++v6;
            ++v7;
          }
          ++*(_DWORD *)(this + 28);
        }
      }
LABEL_20:
      ++v6;
      ++v7;
    }
    while ( (unsigned int)v6 < *(_DWORD *)(this + 4) );
  }
  if ( (unsigned int)v6 < *(_DWORD *)(this + 4) )
  {
    if ( *v6 == 10 )
      sub_65DD1F(*(_DWORD **)(this + 48), this + 8, 1005, "string continues past end of line");
  }
  else
  {
    v6 = *(char **)(this + 4);
    sub_65DD1F(*(_DWORD **)(this + 48), this + 8, 1006, "string continues past end of file");
  }
  v17 = (unsigned int)v6;
  v15 = v6 - a2;
  v10 = (_BYTE *)sub_67EB7E(v6 - a2, 1u);
  if ( !v10 )
    return 0;
  v11 = v16;
  *a3 = v10;
  while ( 1 )
  {
    if ( (unsigned int)(v11 + 1) < v17 )
    {
      v12 = v11 + 1;
      v13 = v11 + 2;
      while ( *v11 == 92 && (*(_BYTE *)(this + 40) & 4) == 0 )
      {
        if ( *v12 == 10 )
        {
          v11 += 2;
          v13 += 2;
          v12 += 2;
        }
        else
        {
          if ( *v12 != 13 || (unsigned int)v13 >= v17 || *v13 != 10 )
            break;
          v11 += 3;
          v13 += 3;
          v12 += 3;
        }
        if ( (unsigned int)v12 >= v17 )
          break;
      }
    }
    if ( (unsigned int)v11 >= v17 )
      break;
    v11 = &v11[(_DWORD)sub_65E376(this, v11, (int *)&a3)];
    *v10++ = (_BYTE)a3;
  }
  *v10 = 0;
  return v15 + 1;
}
