int __thiscall sub_582780(int *this)
{
  int result; // eax
  _DWORD *v3; // ebp
  _DWORD *v4; // esi
  int v5; // ebp
  int v6; // esi
  int v7; // eax
  int v8; // ecx
  _DWORD *v9; // [esp+Ch] [ebp-14h]

  result = sub_587C03(4);
  v3 = (_DWORD *)result;
  v4 = 0;
  if ( result )
  {
    result = sub_587C03(340);
    if ( result )
    {
      v4 = (_DWORD *)(result + 4);
      *(_DWORD *)result = 4;
      result = sub_58A6EB(result + 4, 84, 4, sub_586700, sub_5867B0);
    }
    *v3 = v4;
    v4 = v3;
    v9 = v3;
  }
  else
  {
    v9 = 0;
  }
  v5 = 0;
  if ( v4 )
  {
    result = sub_587C03(12);
    if ( result )
    {
      *(_DWORD *)result = v4;
      *(_DWORD *)(result + 4) = 0;
      *(_BYTE *)(result + 8) = 1;
    }
    else
    {
      result = 0;
    }
    if ( *this )
    {
      *(_DWORD *)(this[1] + 4) = result;
      this[1] = result;
      ++this[3];
    }
    else
    {
      *this = result;
      this[2] = result;
      this[1] = result;
      result = this[3] + 1;
      this[3] = result;
    }
  }
  while ( 1 )
  {
    v6 = v5 + *v4;
    if ( v6 )
    {
      v7 = sub_587C03(12);
      if ( v7 )
      {
        *(_DWORD *)v7 = v6;
        *(_DWORD *)(v7 + 4) = 0;
        *(_BYTE *)(v7 + 8) = 0;
      }
      else
      {
        v7 = 0;
      }
      v8 = this[4];
      if ( v8 )
      {
        *(_DWORD *)(v7 + 4) = v8;
      }
      else
      {
        this[5] = v7;
        this[6] = v7;
      }
      this[4] = v7;
      result = this[7] + 1;
      this[7] = result;
    }
    v5 += 84;
    if ( v5 >= 336 )
      break;
    v4 = v9;
  }
  return result;
}
