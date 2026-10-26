int __thiscall sub_466A70(_DWORD *this)
{
  int v2; // esi
  LPVOID **v3; // ebp
  char v4; // al
  LPVOID *v5; // edi

  this[65] = dword_7C7368[this[66]];
  StringCopyWithBufferRealloc(byte_5EA438);
  if ( !byte_7C7064 )
    VehicleStatsEstimationDisplay(&byte_7C56C0);
  v2 = this[17];
  while ( v2 )
  {
    v3 = (LPVOID **)v2;
    v4 = *(_BYTE *)(v2 + 8);
    v2 = *(_DWORD *)(v2 + 4);
    if ( v4 )
    {
      v5 = *v3;
      if ( *v3 )
      {
        if ( *v5 )
          FreeWrapper_7bcf(*v5);
        FreeWrapper_7bcf(v5);
      }
    }
    FreeWrapper_7bcf(v3);
  }
  this[17] = 0;
  this[18] = 0;
  this[19] = 0;
  this[20] = 0;
  LinkedListInsertWithNodeAllocation(aCustom_0, -1);
  return 0;
}
