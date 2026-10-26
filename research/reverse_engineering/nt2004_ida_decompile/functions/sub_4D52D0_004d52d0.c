int __thiscall sub_4D52D0(int this)
{
  int v2; // esi
  int v3; // ecx
  int v4; // esi
  _DWORD *v5; // ebx
  int v6; // esi
  bool v7; // zf
  int v9; // [esp+10h] [ebp-4h]

  sub_4D5A00();
  sub_4D5710(this);
  sub_4D5820(this);
  if ( *(_DWORD *)(this + 2172) )
    sub_5BE8AE(*(LPVOID *)(this + 2172));
  sub_4D4B20((_DWORD *)(this + 2088));
  sub_4DB5B0(this + 2120);
  sub_4DB5B0(this + 2104);
  sub_4DBD50(this + 2088);
  nullsub_6((void *)(this + 1764));
  nullsub_6((void *)(this + 1336));
  if ( *(_DWORD *)(this + 956) )
    sub_5BE8AE(*(LPVOID *)(this + 956));
  if ( *(_DWORD *)(this + 948) )
    sub_5BE8AE(*(LPVOID *)(this + 948));
  sub_4DAEB0(this + 932);
  if ( *(_DWORD *)(this + 924) )
    sub_5BE8AE(*(LPVOID *)(this + 924));
  if ( *(_DWORD *)(this + 916) )
    sub_5BE8AE(*(LPVOID *)(this + 916));
  sub_57A0A0(this + 884);
  v2 = *(_DWORD *)(this + 868);
  while ( v2 )
  {
    v3 = v2;
    v2 = *(_DWORD *)(v2 + 4);
    sub_466750(v3, 1);
  }
  *(_DWORD *)(this + 868) = 0;
  *(_DWORD *)(this + 872) = 0;
  *(_DWORD *)(this + 876) = 0;
  *(_DWORD *)(this + 880) = 0;
  v4 = *(_DWORD *)(this + 848);
  while ( v4 )
  {
    v4 = *(_DWORD *)(v4 + 4);
    sub_4DAF50(1);
  }
  *(_DWORD *)(this + 848) = 0;
  *(_DWORD *)(this + 852) = 0;
  *(_DWORD *)(this + 856) = 0;
  *(_DWORD *)(this + 860) = 0;
  v5 = (_DWORD *)(this + 848);
  v9 = 49;
  do
  {
    v6 = *(v5 - 4);
    v5 -= 4;
    while ( v6 )
    {
      v6 = *(_DWORD *)(v6 + 4);
      sub_4DAF10(1);
    }
    v7 = v9 == 1;
    *v5 = 0;
    v5[1] = 0;
    v5[2] = 0;
    v5[3] = 0;
    --v9;
  }
  while ( !v7 );
  sub_4DB110(this + 48);
  sub_4DB110(this + 48);
  sub_4DBEB0(this + 32);
  sub_4DB770(this + 16);
  sub_4DB770(this + 16);
  return sub_4DBE00(this);
}
