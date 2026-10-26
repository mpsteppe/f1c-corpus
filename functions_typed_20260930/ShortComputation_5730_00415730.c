int __thiscall sub_415730(int **this, int a2)
{
  int result; // eax
  int v4; // eax

  sub_415700(this);
  VehicleLookupByName(a2);
  result = CurrentVehicleAccessor(&unk_8AC388);
  if ( result )
  {
    v4 = NamedEntryLookupInFormatList((char ****)this, (const char *)(result + 188), a2);
    result = LinkedListIndexedAccessor(this, v4);
    if ( result )
      *(_BYTE *)(result + 12) = 1;
  }
  return result;
}

