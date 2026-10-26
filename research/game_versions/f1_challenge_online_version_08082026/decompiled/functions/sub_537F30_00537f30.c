int __thiscall sub_537F30(int this, int a2, int a3)
{
  int v4; // ecx
  int v5; // edx
  int v6; // ecx
  int v7; // edx
  char v8; // bl
  int v9; // ecx
  int v10; // ebx

  v4 = *(_DWORD *)(this + 5805);
  if ( v4 <= 13 )
  {
    *(_DWORD *)(this + 5805) = v4 + 3;
    *(_WORD *)(this + 5803) |= a3 << v4;
  }
  else
  {
    v5 = a3 << v4;
    v6 = *(_DWORD *)(this + 8);
    *(_WORD *)(this + 5803) |= v5;
    *(_BYTE *)(v6 + *(_DWORD *)(this + 20)) = *(_BYTE *)(this + 5803);
    v7 = *(_DWORD *)(this + 8);
    v8 = *(_BYTE *)(this + 5804);
    v9 = *(_DWORD *)(this + 20) + 1;
    *(_DWORD *)(this + 20) = v9;
    *(_BYTE *)(v9 + v7) = v8;
    ++*(_DWORD *)(this + 20);
    v10 = *(_DWORD *)(this + 5805);
    *(_DWORD *)(this + 5805) = v10 - 13;
    *(_WORD *)(this + 5803) = (unsigned __int16)a3 >> (16 - v10);
  }
  return sub_5397A0(a2, 1);
}
