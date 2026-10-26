int __thiscall sub_4FE730(_DWORD *this, int Buffer, int a3)
{
  int v5; // [esp+4h] [ebp-4h] BYREF

  if ( Buffer )
  {
    if ( Buffer == 1 )
    {
      LOBYTE(Buffer) = 1;
    }
    else if ( Buffer == 2 )
    {
      LOBYTE(Buffer) = 2;
    }
    else
    {
      LOBYTE(Buffer) = -1;
    }
  }
  else
  {
    Buffer = 3;
  }
  sub_4FEA10(&Buffer, 1u);
  v5 = a3 ^ this[2];
  return sub_4FEA10(&v5, 4u);
}
