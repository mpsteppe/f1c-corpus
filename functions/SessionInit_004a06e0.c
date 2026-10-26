int sub_4A06E0()
{
  int v0; // eax
  int v1; // eax

  if ( dword_5EB10C )
    (*(void (__thiscall **)(int))(*(_DWORD *)dword_5EB10C + 12))(dword_5EB10C);
  BufferInitWith10fDefaults(flt_5EA618);
  sub_4B0EF0(4);
  dword_5CC9E8 = 1;
  dword_8AB6E4 = dword_7D0038 != 0;
  ArrayCheckInit(&dword_7D2DB0);
  byte_7C5690 = 1;
  v0 = LinkedListDereference(&dword_7D2DB0);
  if ( v0 )
  {
    v1 = TireWearGetter(v0);
    MultiplayerVehiclePlacement(&dword_7C569C, v1);
  }
  return 0;
}
