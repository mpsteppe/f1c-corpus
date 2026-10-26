int __thiscall sub_6C6A81(_DWORD *this, int a2, int a3)
{
  int v4; // ecx
  int result; // eax
  bool v6; // zf
  int v7; // eax
  char *v8; // ebx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  const char *v12; // [esp-8h] [ebp-218h]
  char ArgList[512]; // [esp+8h] [ebp-208h] BYREF
  int v14; // [esp+208h] [ebp-8h]
  int v15; // [esp+20Ch] [ebp-4h] BYREF

  v4 = *(_DWORD *)(a2 + 104);
  v15 = 0;
  if ( !v4 )
  {
    *(_BYTE *)(a2 + 3) |= 0x40u;
    *(_DWORD *)(a2 + 108) = (*(int (__thiscall **)(_DWORD *, _DWORD, _DWORD))(*this + 80))(this, 0, 0);
    return 0;
  }
  v6 = this[86] == 0;
  v7 = *(_DWORD *)(this[4] + 4 * *(_DWORD *)(a2 + 4));
  v8 = *(char **)(v4 + 24);
  v14 = v7;
  if ( !v6 )
  {
    if ( strlen(v8) > 2 && *(_WORD *)"r_" == *(_WORD *)v8 )
    {
      if ( *(_DWORD *)(a2 + 112) > 4u )
      {
        sub_686791((int)this, v4, 4543, "multi-register semantics are not allowed in fragments '%s'", v8);
        v15 = 1;
      }
      v9 = sub_65EBEC(this + 109, v8);
      if ( v9 )
      {
        v10 = *(_DWORD *)(v9 + 4);
      }
      else
      {
        result = sub_66078B(this + 109, v8, this[116], 1);
        if ( result < 0 )
          return result;
        v10 = this[116];
        this[116] = v10 + 1;
      }
      *(_DWORD *)(a2 + 108) = (*(int (__thiscall **)(_DWORD *, int, int))(*this + 80))(this, 0xFFFF, v10);
      return v15 != 0 ? 0x80004005 : 0;
    }
    v7 = v14;
  }
  if ( *(_DWORD *)(a2 + 108) != -1 && (*(_BYTE *)(a2 + 3) & 0x40) != 0 && !a3 )
  {
    sub_681DE0(this, a2, (int)ArgList, 512);
    sub_686791((int)this, *(_DWORD *)(a2 + 104), 4502, "invalid %s", ArgList);
LABEL_20:
    v15 = 1;
    return v15 != 0 ? 0x80004005 : 0;
  }
  v11 = *(_DWORD *)(v7 + 4);
  if ( (this[28] & 0x40) == 0 )
  {
    if ( (v11 & 0x10) != 0 && (v11 & 0x200) == 0 )
    {
      result = sub_6BC1E5(this, a2, this[61], 1u, &v15);
      if ( result >= 0 )
      {
        if ( this[10] == 2 && (*(int (__thiscall **)(_DWORD *, _DWORD))(*this + 84))(this, *(_DWORD *)(a2 + 108)) == 11 )
        {
          *(_WORD *)a2 |= 0x114u;
          *(double *)(a2 + 32) = 0.0;
          *(double *)(a2 + 40) = 1.0;
        }
        return v15 != 0 ? 0x80004005 : 0;
      }
      return result;
    }
    if ( (v11 & 0x20) == 0 )
      return v15 != 0 ? 0x80004005 : 0;
    result = sub_6BC1E5(this, a2, this[62], 1u, &v15);
    goto LABEL_30;
  }
  if ( (v11 & 0x10) == 0 || (v11 & 0x200) != 0 )
  {
    if ( (v11 & 0x20) == 0 )
      return v15 != 0 ? 0x80004005 : 0;
    result = sub_6BC1E5(this, a2, this[61], 2u, &v15);
LABEL_30:
    if ( result >= 0 )
      return v15 != 0 ? 0x80004005 : 0;
    return result;
  }
  result = sub_6BC1E5(this, a2, this[60], 2u, &v15);
  if ( result >= 0 )
  {
    if ( *(_DWORD *)(a2 + 108) != 10 || *(_DWORD *)(a2 + 16) )
      return v15 != 0 ? 0x80004005 : 0;
    v12 = sub_681C52(this, a2);
    sub_686791((int)this, *(_DWORD *)(a2 + 104), 4502, "Invalid %s semantics - POSITIONT0", v12);
    goto LABEL_20;
  }
  return result;
}
