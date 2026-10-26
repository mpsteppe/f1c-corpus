int __thiscall sub_4D5900(_DWORD *this, int a2, int a3)
{
  int v5; // [esp+4h] [ebp-4h] BYREF

  if ( a2 )
  {
    if ( a2 == 1 )
    {
      LOBYTE(a2) = 1;
    }
    else if ( a2 == 2 )
    {
      LOBYTE(a2) = 2;
    }
    else
    {
      LOBYTE(a2) = -1;
    }
  }
  else
  {
    a2 = 3;
  }
  sub_4D5BE0(&a2, 1);
  v5 = a3 ^ this[2];
  return sub_4D5BE0(&v5, 4);
}

