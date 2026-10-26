int sub_4F8C90()
{
  if ( !hLibModule )
    return 3;
  VFXClose();
  FreeLibrary(hLibModule);
  hLibModule = 0;
  return 0;
}

