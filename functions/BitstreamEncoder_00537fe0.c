int __thiscall sub_537FE0(int this)
{
  int v2; // ecx
  char v3; // dl
  int v4; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // ecx
  char v9; // dl
  int v10; // ecx
  int result; // eax
  int v12; // ecx
  char v13; // dl
  int v14; // ecx
  int v15; // eax
  int v16; // ecx
  int v17; // eax
  int v18; // ecx
  char v19; // dl
  int v20; // ecx

  v2 = *(_DWORD *)(this + 5805);
  *(_WORD *)(this + 5803) |= 2 << v2;
  if ( v2 <= 13 )
  {
    *(_DWORD *)(this + 5805) = v2 + 3;
  }
  else
  {
    *(_BYTE *)(*(_DWORD *)(this + 8) + *(_DWORD *)(this + 20)) = *(_BYTE *)(this + 5803);
    v3 = *(_BYTE *)(this + 5804);
    v4 = *(_DWORD *)(this + 20) + 1;
    *(_DWORD *)(this + 20) = v4;
    *(_BYTE *)(v4 + *(_DWORD *)(this + 8)) = v3;
    ++*(_DWORD *)(this + 20);
    v5 = *(_DWORD *)(this + 5805);
    *(_DWORD *)(this + 5805) = v5 - 13;
    *(_WORD *)(this + 5803) = 2u >> (16 - v5);
  }
  v6 = *(_DWORD *)(this + 5805);
  if ( v6 <= 9 )
  {
    *(_WORD *)(this + 5803) = *(_WORD *)(this + 5803);
    *(_DWORD *)(this + 5805) = v6 + 7;
  }
  else
  {
    v7 = *(_DWORD *)(this + 8);
    v8 = *(_DWORD *)(this + 20);
    *(_WORD *)(this + 5803) = *(_WORD *)(this + 5803);
    *(_BYTE *)(v7 + v8) = *(_BYTE *)(this + 5803);
    v9 = *(_BYTE *)(this + 5804);
    v10 = *(_DWORD *)(this + 20) + 1;
    *(_DWORD *)(this + 20) = v10;
    *(_BYTE *)(v10 + *(_DWORD *)(this + 8)) = v9;
    ++*(_DWORD *)(this + 20);
    *(_DWORD *)(this + 5805) -= 9;
    *(_WORD *)(this + 5803) = 0;
  }
  result = BitStreamWriter(this);
  v12 = *(_DWORD *)(this + 5805);
  if ( *(_DWORD *)(this + 5799) - v12 + 11 < 9 )
  {
    *(_WORD *)(this + 5803) |= 2 << v12;
    if ( v12 <= 13 )
    {
      *(_DWORD *)(this + 5805) = v12 + 3;
    }
    else
    {
      *(_BYTE *)(*(_DWORD *)(this + 8) + *(_DWORD *)(this + 20)) = *(_BYTE *)(this + 5803);
      v13 = *(_BYTE *)(this + 5804);
      v14 = *(_DWORD *)(this + 20) + 1;
      *(_DWORD *)(this + 20) = v14;
      *(_BYTE *)(v14 + *(_DWORD *)(this + 8)) = v13;
      ++*(_DWORD *)(this + 20);
      v15 = *(_DWORD *)(this + 5805);
      *(_DWORD *)(this + 5805) = v15 - 13;
      *(_WORD *)(this + 5803) = 2u >> (16 - v15);
    }
    v16 = *(_DWORD *)(this + 5805);
    if ( v16 > 9 )
    {
      v17 = *(_DWORD *)(this + 8);
      v18 = *(_DWORD *)(this + 20);
      *(_WORD *)(this + 5803) = *(_WORD *)(this + 5803);
      *(_BYTE *)(v17 + v18) = *(_BYTE *)(this + 5803);
      v19 = *(_BYTE *)(this + 5804);
      v20 = *(_DWORD *)(this + 20) + 1;
      *(_DWORD *)(this + 20) = v20;
      *(_BYTE *)(v20 + *(_DWORD *)(this + 8)) = v19;
      ++*(_DWORD *)(this + 20);
      *(_DWORD *)(this + 5805) -= 9;
      *(_WORD *)(this + 5803) = 0;
      result = BitStreamWriter(this);
      *(_DWORD *)(this + 5799) = 7;
      return result;
    }
    *(_DWORD *)(this + 5805) = v16 + 7;
    *(_WORD *)(this + 5803) = *(_WORD *)(this + 5803);
    result = BitStreamWriter(this);
  }
  *(_DWORD *)(this + 5799) = 7;
  return result;
}
