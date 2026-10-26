int __thiscall sub_44C310(_DWORD *this, int a2, int a3)
{
  int v4; // eax
  int v5; // ecx
  int v6; // edx
  int i; // eax
  int v9; // [esp+10h] [ebp-30h]
  int v10; // [esp+14h] [ebp-2Ch]
  int v11; // [esp+18h] [ebp-28h]
  _DWORD Buffer[8]; // [esp+1Ch] [ebp-24h] BYREF
  __int16 v13; // [esp+3Ch] [ebp-4h]

  v4 = 0;
  v5 = a2 + 4;
  do
  {
    v6 = *(_DWORD *)v5;
    Buffer[2 * v4] = *(_DWORD *)(*(_DWORD *)v5 + 16);
    Buffer[2 * v4++ + 1] = *(_DWORD *)(v6 + 20);
    v5 += 8;
  }
  while ( v4 < 3 );
  for ( i = 0; i < 3; ++i )
    *(&v9 + i) = *(_DWORD *)(*(_DWORD *)(a2 + 8 * i) + 72);
  Buffer[6] = v9 + (v10 << 21);
  Buffer[7] = (v11 << 10) + (v10 >> 11);
  v13 = *(_WORD *)(a2 + 26);
  sub_57A3A0(Buffer, 0x22u);
  return sub_44BEC0(this, a2, 1);
}
