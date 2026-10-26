int __thiscall sub_65DAD4(_DWORD *this, _BYTE *a2, int a3)
{
  char *v4; // edx
  char v5; // bl
  char v6; // cl
  char v7; // dl
  _BYTE *v8; // ecx
  unsigned int v12; // [esp+1Ch] [ebp+Ch]

  *(_DWORD *)a3 = 0;
  *(_BYTE *)a3 = *a2;
  v4 = a2 + 1;
  v12 = this[1];
  if ( (unsigned int)(a2 + 1) >= v12 )
    return 1;
  v5 = *a2;
  if ( *a2 == 35 )
  {
    v6 = *v4;
    if ( *v4 == 35 || v6 == 64 )
    {
      *(_BYTE *)(a3 + 1) = v6;
      return 2;
    }
  }
  v7 = *v4;
  if ( v5 != v7 )
  {
    if ( v7 == 61 )
    {
      if ( v5 > 47 )
      {
        if ( v5 != 60 && v5 != 62 && v5 != 94 && v5 != 124 )
          return 1;
      }
      else if ( v5 != 47 && v5 != 33 && (v5 <= 36 || v5 > 38 && (v5 <= 41 || v5 > 43 && v5 != 45)) )
      {
        return 1;
      }
      *(_BYTE *)(a3 + 1) = 61;
      return 2;
    }
    if ( v5 == 45 && v7 == 62 )
    {
      *(_BYTE *)(a3 + 1) = 62;
      return 2;
    }
    return 1;
  }
  if ( v5 <= 58 )
  {
    if ( v5 != 58 && v5 != 38 && v5 != 43 && v5 != 45 )
    {
      if ( v5 == 46 )
      {
        v8 = a2 + 2;
        if ( (unsigned int)(a2 + 2) < v12 && *v8 == 46 )
        {
          *(_BYTE *)(a3 + 1) = v7;
          *(_BYTE *)(a3 + 2) = *v8;
          return 3;
        }
      }
      return 1;
    }
LABEL_20:
    *(_BYTE *)(a3 + 1) = v7;
    return 2;
  }
  if ( v5 != 60 )
  {
    if ( v5 == 61 )
      goto LABEL_20;
    if ( v5 != 62 )
    {
      if ( v5 != 124 )
        return 1;
      goto LABEL_20;
    }
  }
  *(_BYTE *)(a3 + 1) = v7;
  if ( (unsigned int)(a2 + 2) >= this[1] || a2[2] != 61 )
    return 2;
  *(_BYTE *)(a3 + 2) = 61;
  return 3;
}
