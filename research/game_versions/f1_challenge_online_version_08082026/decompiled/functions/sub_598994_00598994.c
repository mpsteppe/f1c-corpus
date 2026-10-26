int sub_598994()
{
  bool v0; // zf
  bool v1; // bl
  int result; // eax
  _BYTE v3[4]; // [esp+4h] [ebp-4h] BYREF

  sub_59A54D(v3);
  v0 = dword_5E9EF4-- == 1;
  v1 = v0;
  result = sub_59A5E9(v3);
  if ( v1 )
  {
    sub_598AA0(&unk_8D42A0);
    sub_598AA0(&dword_8D43C8);
    return sub_598AA0(dword_8D4210);
  }
  return result;
}
