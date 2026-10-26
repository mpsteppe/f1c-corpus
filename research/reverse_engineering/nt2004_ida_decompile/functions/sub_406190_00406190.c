int __thiscall sub_406190(int this, unsigned int a2)
{
  FILE *v3; // eax
  int v4; // ebx
  int v5; // edi
  int v6; // eax
  int v7; // eax
  int v9; // eax
  FILE *v10; // eax
  int v11; // ecx
  FILE *v12; // [esp-Ch] [ebp-44h]
  _BYTE Buffer[4]; // [esp+10h] [ebp-28h] BYREF
  int v14; // [esp+14h] [ebp-24h]
  char v15; // [esp+2Bh] [ebp-Dh]
  int v16; // [esp+30h] [ebp-8h]

  v3 = *(FILE **)(this + 12);
  v4 = 1;
  if ( !v3 || a2 >= *(_DWORD *)(this + 20) )
    return v4;
  v5 = *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * a2);
  if ( fseek(v3, v5, 0) )
    return 1;
  if ( !sub_5BED6F(Buffer, 0x28u, 1u, *(FILE **)(this + 12)) )
    return 1;
  v4 = 0;
  sub_405C90();
  v6 = sub_408CD0(Buffer);
  *(_DWORD *)(this + 44) = v6;
  if ( v6 == -1 )
    return 1;
  sub_406350(Buffer);
  v7 = *(_DWORD *)(this + 44);
  *(_DWORD *)(this + 28) = a2;
  *(_DWORD *)(this + 32) = 0;
  *(_DWORD *)(this + 40) = v5 + 40;
  if ( !v7 )
  {
    *(_DWORD *)(this + 36) = v14 + 44;
    return 0;
  }
  if ( v7 == 1 )
  {
    if ( (v15 & 4) != 0 )
      *(_DWORD *)(this + 36) = v16 + 44;
    else
      v4 = 1;
    v9 = _dup(*(_DWORD *)(this + 16));
    v10 = _fdopen(v9, aRb);
    v11 = *(_DWORD *)(this + 40);
    *(_DWORD *)(this + 56) = v10;
    (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)(this + 52) + 12))(this + 52, v11, 0);
    if ( (unsigned __int8)sub_52EF30(this + 52, *(_DWORD *)(this + 40), *(_DWORD *)(this + 36) - 44) )
      return v4;
    sub_4062E0(this);
    return 1;
  }
  if ( v7 != 2 )
    return v4;
  v12 = *(FILE **)(this + 12);
  *(_DWORD *)(this + 36) = v14;
  fseek(v12, v5 + 40, 0);
  return 0;
}
