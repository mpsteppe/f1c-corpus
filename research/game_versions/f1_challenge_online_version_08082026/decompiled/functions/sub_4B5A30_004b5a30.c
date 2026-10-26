int __thiscall sub_4B5A30(int this)
{
  int v2; // esi
  int v3; // ecx
  int v4; // esi
  _DWORD *v5; // ebx
  int v6; // esi
  bool v7; // zf
  int v9; // [esp+10h] [ebp-4h]

  sub_4B6130();
  sub_4B5E50(this);
  sub_4B5F60(this);
  if ( *(_DWORD *)(this + 3988) )
    sub_587BCF(*(LPVOID *)(this + 3988));
  sub_4B52A0((_DWORD *)(this + 3908));
  sub_4BA9F0(this + 3940);
  sub_4BA9F0(this + 3924);
  sub_4BB4F0(this + 3908);
  nullsub_3();
  nullsub_3();
  if ( *(_DWORD *)(this + 1836) )
    sub_587BCF(*(LPVOID *)(this + 1836));
  if ( *(_DWORD *)(this + 1828) )
    sub_587BCF(*(LPVOID *)(this + 1828));
  sub_4BB400(this + 1812);
  if ( *(_DWORD *)(this + 1804) )
    sub_587BCF(*(LPVOID *)(this + 1804));
  if ( *(_DWORD *)(this + 1796) )
    sub_587BCF(*(LPVOID *)(this + 1796));
  sub_5668D0(this + 1764);
  v2 = *(_DWORD *)(this + 1748);
  while ( v2 )
  {
    v3 = v2;
    v2 = *(_DWORD *)(v2 + 4);
    sub_4646F0(v3, 1);
  }
  *(_DWORD *)(this + 1748) = 0;
  *(_DWORD *)(this + 1752) = 0;
  *(_DWORD *)(this + 1756) = 0;
  *(_DWORD *)(this + 1760) = 0;
  v4 = *(_DWORD *)(this + 1728);
  while ( v4 )
  {
    v4 = *(_DWORD *)(v4 + 4);
    sub_4BA900(1);
  }
  *(_DWORD *)(this + 1728) = 0;
  *(_DWORD *)(this + 1732) = 0;
  *(_DWORD *)(this + 1736) = 0;
  *(_DWORD *)(this + 1740) = 0;
  v5 = (_DWORD *)(this + 1728);
  v9 = 104;
  do
  {
    v6 = *(v5 - 4);
    v5 -= 4;
    while ( v6 )
    {
      v6 = *(_DWORD *)(v6 + 4);
      sub_4BA8C0(1);
    }
    v7 = v9 == 1;
    *v5 = 0;
    v5[1] = 0;
    v5[2] = 0;
    v5[3] = 0;
    --v9;
  }
  while ( !v7 );
  sub_49AF30((int *)(this + 48));
  sub_49AF30((int *)(this + 48));
  sub_4BB650(this + 32);
  sub_4BAEB0(this + 16);
  sub_4BAEB0(this + 16);
  return sub_4BB5A0(this);
}
