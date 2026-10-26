int __thiscall sub_434000(char **this)
{
  char *v1; // eax
  char v2; // bl
  int result; // eax

  v1 = *this;
  v2 = byte_7C56C0;
  if ( !*this )
    v1 = &byte_5EA438;
  result = VehicleSetupFileWriter(&byte_7C56C0, (int)v1, 1);
  byte_7C56C0 = v2;
  return result;
}

