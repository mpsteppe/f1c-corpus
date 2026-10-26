int __thiscall sub_62E340(int this)
{
  int v2; // ecx
  char v3; // bl
  int v4; // edx
  int v5; // ecx
  int v6; // edx
  int v7; // ecx
  char v8; // bl
  int v9; // edx
  int v10; // ecx
  int v11; // edx
  int result; // eax
  int v13; // ecx
  char v14; // bl
  int v15; // edx
  int v16; // ecx
  int v17; // edx
  int v18; // ecx
  char v19; // bl
  int v20; // edx
  int v21; // ecx
  int v22; // edx

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
    v4 = *(_DWORD *)(this + 8);
    v5 = *(_DWORD *)(this + 20) + 1;
    *(_DWORD *)(this + 20) = v5;
    *(_BYTE *)(v5 + v4) = v3;
    v6 = *(_DWORD *)(this + 5805);
    ++*(_DWORD *)(this + 20);
    *(_WORD *)(this + 5803) = 2u >> (16 - v6);
    *(_DWORD *)(this + 5805) = v6 - 13;
  }
  v7 = *(_DWORD *)(this + 5805);
  *(_WORD *)(this + 5803) = *(_WORD *)(this + 5803);
  if ( v7 <= 9 )
  {
    *(_DWORD *)(this + 5805) = v7 + 7;
  }
  else
  {
    *(_BYTE *)(*(_DWORD *)(this + 8) + *(_DWORD *)(this + 20)) = *(_BYTE *)(this + 5803);
    v8 = *(_BYTE *)(this + 5804);
    v9 = *(_DWORD *)(this + 8);
    v10 = *(_DWORD *)(this + 20) + 1;
    *(_DWORD *)(this + 20) = v10;
    *(_BYTE *)(v10 + v9) = v8;
    v11 = *(_DWORD *)(this + 5805);
    ++*(_DWORD *)(this + 20);
    *(_WORD *)(this + 5803) = 0;
    *(_DWORD *)(this + 5805) = v11 - 9;
  }
  result = sub_62DDD0();
  v13 = *(_DWORD *)(result + 5805);
  if ( *(_DWORD *)(result + 5799) - v13 + 11 < 9 )
  {
    *(_WORD *)(result + 5803) |= 2 << v13;
    if ( v13 <= 13 )
    {
      *(_DWORD *)(result + 5805) = v13 + 3;
    }
    else
    {
      *(_BYTE *)(*(_DWORD *)(result + 8) + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5803);
      v14 = *(_BYTE *)(result + 5804);
      v15 = *(_DWORD *)(result + 8);
      v16 = *(_DWORD *)(result + 20) + 1;
      *(_DWORD *)(result + 20) = v16;
      *(_BYTE *)(v16 + v15) = v14;
      v17 = *(_DWORD *)(result + 5805);
      ++*(_DWORD *)(result + 20);
      *(_WORD *)(result + 5803) = 2u >> (16 - v17);
      *(_DWORD *)(result + 5805) = v17 - 13;
    }
    v18 = *(_DWORD *)(result + 5805);
    *(_WORD *)(result + 5803) = *(_WORD *)(result + 5803);
    if ( v18 > 9 )
    {
      *(_BYTE *)(*(_DWORD *)(result + 8) + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5803);
      v19 = *(_BYTE *)(result + 5804);
      v20 = *(_DWORD *)(result + 8);
      v21 = *(_DWORD *)(result + 20) + 1;
      *(_DWORD *)(result + 20) = v21;
      *(_BYTE *)(v21 + v20) = v19;
      v22 = *(_DWORD *)(result + 5805) - 9;
      ++*(_DWORD *)(result + 20);
      *(_WORD *)(result + 5803) = 0;
      *(_DWORD *)(result + 5805) = v22;
      result = sub_62DDD0();
      *(_DWORD *)(result + 5799) = 7;
      return result;
    }
    *(_DWORD *)(result + 5805) = v18 + 7;
    result = sub_62DDD0();
  }
  *(_DWORD *)(result + 5799) = 7;
  return result;
}
