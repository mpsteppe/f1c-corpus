int __stdcall sub_4C40B0(int a1)
{
  int result; // eax

  result = 0;
  if ( a1 )
  {
    VehicleLookupByName(a1);
    return CurrentVehicleAccessor();
  }
  return result;
}

