int __thiscall sub_4B09A0(int this, const char *a2)
{
  unsigned int v4; // esi
  unsigned int v5; // kr04_4
  char *v6; // eax
  int v7; // eax
  char *v8; // esi
  CHAR v9[512]; // [esp+4h] [ebp-600h] BYREF
  CHAR PathName[1024]; // [esp+204h] [ebp-400h] BYREF

  if ( !a2 )
    return -1;
  sub_4B0180(a2, this + 20);
  sub_568620(512);
  v4 = 0;
  v5 = strlen(v9) + 1;
  if ( (int)(v5 - 1) > 0 )
  {
    do
    {
      if ( v4 >= 0x400 )
        break;
      if ( v9[v4] == 92 )
      {
        sub_587DD0(PathName, v9, v4);
        PathName[v4] = 0;
        CreateDirectoryAWrapper(PathName);
      }
      ++v4;
    }
    while ( (int)v4 < (int)(v5 - 1) );
  }
  CreateDirectoryAWrapper(v9);
  sub_4B01B0(a2, (char *)(this + 20));
  if ( (byte_7CB710 & 1) != 0 )
    sub_4AE750((int *)this, 2);
  else
    sub_4AE750((int *)this, 1);
  if ( dword_8AC488 > 0 )
    AIW(this);
  if ( dword_8AC390 > 0 )
  {
    v6 = *(char **)CurrentVehicleAccessor(&unk_8AC388);
    if ( !v6 )
      v6 = byte_5EA438;
    StringCopyWithBufferRealloc(v6);
    v7 = CurrentVehicleAccessor(&unk_8AC388);
    StringCopyWithBufferRealloc(v7 + 188);
    v8 = *(char **)(this + 436);
    if ( !v8 )
      v8 = byte_5EA438;
    ShortComputation_5730((int **)&dword_5EA5E8, (int)v8);
  }
  sub_4ADD50();
  TrackEnvironmentSelect((_DWORD *)this, 1);
  DualLinkedListCleanup((int)&dword_7C73E8);
  sub_4B0770((int *)this, 1);
  return 0;
}
