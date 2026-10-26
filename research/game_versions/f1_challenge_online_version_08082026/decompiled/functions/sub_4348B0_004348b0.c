int __thiscall sub_4348B0(int this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  _DWORD v6[3]; // [esp+8h] [ebp-Ch] BYREF

  if ( *(_DWORD *)(this + 12) )
    sub_434D40();
  v2 = sub_587C03(208);
  if ( v2 )
    v3 = sub_4583B0(v2);
  else
    v3 = 0;
  *(_DWORD *)(this + 12) = v3;
  if ( !v3 || sub_4349A0(this) )
    return 1;
  sub_566650(aGridwalkCam);
  v4 = *(_DWORD *)(this + 12);
  *(float *)(v4 + 56) = *(float *)(this + 16);
  *(_DWORD *)(v4 + 60) = 1115291648;
  sub_4582C0(0.0);
  *(float *)(*(_DWORD *)(this + 12) + 168) = *(float *)(this + 48);
  *(_DWORD *)(*(_DWORD *)(this + 12) + 164) = 0x40000000;
  *(_DWORD *)(*(_DWORD *)(this + 12) + 72) = 1067450368;
  memset(v6, 0, sizeof(v6));
  sub_456150(v6);
  (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(this + 12) + 28))(*(_DWORD *)(this + 12));
  sub_434D60(0);
  return 0;
}
