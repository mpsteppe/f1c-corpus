int __thiscall sub_415090(void *this)
{
  int result; // eax

  if ( VehicleListBuilderFromGlobalArray() )
    return 1;
  if ( NameListBuilderFromVehicleArray(this) )
    return 1;
  result = SceneListBuilderFromGlobalArray(this);
  if ( result )
    return 1;
  return result;
}
