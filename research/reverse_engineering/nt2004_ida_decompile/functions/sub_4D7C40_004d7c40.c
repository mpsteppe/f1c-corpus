BOOL __thiscall sub_4D7C40(int this, float a2)
{
  double v3; // st7
  char v4; // al
  ULARGE_INTEGER TotalNumberOfFreeBytes; // [esp+0h] [ebp-18h] BYREF
  ULARGE_INTEGER FreeBytesAvailableToCaller; // [esp+8h] [ebp-10h] BYREF
  ULARGE_INTEGER TotalNumberOfBytes; // [esp+10h] [ebp-8h] BYREF

  v3 = a2 + *(float *)(this + 2072);
  v4 = *(_BYTE *)(this + 2068);
  *(float *)(this + 2072) = v3;
  if ( v4 )
    return *(_BYTE *)(this + 2068) == 0;
  if ( v3 <= 60.0 )
    return *(_BYTE *)(this + 2068) == 0;
  *(_DWORD *)(this + 2072) = 0;
  GetDiskFreeSpaceExA(0, &FreeBytesAvailableToCaller, &TotalNumberOfBytes, &TotalNumberOfFreeBytes);
  if ( TotalNumberOfFreeBytes.QuadPart >> 20 >= 0x200 )
    return *(_BYTE *)(this + 2068) == 0;
  *(_BYTE *)(this + 2068) = 1;
  if ( sub_41F230(dword_62A170, aDiskSpaceLowRe, Destination) )
  {
    strncpy(Destination, aDiskSpaceLowRe, 0x1FFu);
    byte_62A37B = 0;
  }
  sub_45D100(&byte_764D68, (int)Destination, 3, 16909060, 0);
  return *(_BYTE *)(this + 2068) == 0;
}
