char *sub_599AD9()
{
  bool v0; // zf
  bool v1; // bl
  char *result; // eax
  _BYTE v3[4]; // [esp+4h] [ebp-4h] BYREF

  sub_59A54D(v3);
  v0 = dword_5EA04C-- == 1;
  v1 = v0;
  result = (char *)sub_59A5E9(v3);
  if ( v1 )
  {
    StatusCheckWithErrorDispatch(byte_8D4568);
    StatusCheckWithErrorDispatch((char *)dword_8D4400);
    return StatusCheckWithErrorDispatch((char *)dword_8D4440);
  }
  return result;
}

