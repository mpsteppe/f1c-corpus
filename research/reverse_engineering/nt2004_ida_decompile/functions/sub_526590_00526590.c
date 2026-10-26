int sub_526590()
{
  if ( !hLibModule )
    return 3;
  VFXClose();
  FreeLibrary(hLibModule);
  hLibModule = 0;
  return 0;
}
