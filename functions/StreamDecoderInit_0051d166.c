int __cdecl sub_51D166(int a1)
{
  int v1; // esi
  int v3; // [esp-4h] [ebp-Ch]

  v1 = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 48);
  *(_DWORD *)(a1 + 412) = v1;
  *(_BYTE *)(v1 + 8) = 0;
  *(_DWORD *)v1 = PhysicsObjectStateSetter;
  *(_DWORD *)(v1 + 40) = *(_DWORD *)(a1 + 92) * *(_DWORD *)(a1 + 100);
  if ( *(_DWORD *)(a1 + 272) == 2 )
  {
    v3 = *(_DWORD *)(v1 + 40);
    *(_DWORD *)(v1 + 4) = AudioSampleStream;
    *(_DWORD *)(v1 + 12) = sub_51CF80;
    *(_DWORD *)(v1 + 32) = (*(int (__cdecl **)(int, int, int))(*(_DWORD *)(a1 + 4) + 4))(a1, 1, v3);
  }
  else
  {
    *(_DWORD *)(v1 + 32) = 0;
    *(_DWORD *)(v1 + 4) = VirtualDispatchWrapper_cdf9;
    *(_DWORD *)(v1 + 12) = TexturePaletteColorLookup;
  }
  return WheelGeometryDataInitialization(a1);
}
