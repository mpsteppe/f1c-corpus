// f1c  0x0040a910  size=270
char __thiscall sub_40A910(_DWORD *this, int a2, char a3)
{
  char result; // al
  int v5; // ebx
  int v6; // edi
  int i; // edx

  result = 0;
  if ( a2 )
  {
    if ( a2 == this[4] )
    {
      sub_409440((int)this, 0, 1, 1);
    }
    else if ( a2 == this[5] )
    {
      sub_409440((int)this, 1, 1, 1);
    }
    else if ( a2 == this[6] )
    {
      sub_409440((int)this, 2, 1, 1);
    }
    else if ( a2 == this[7] )
    {
      sub_409440((int)this, 3, 1, 1);
    }
    else if ( a2 == this[9] )
    {
      sub_409440((int)this, 5, 1, 1);
    }
    else if ( a2 == this[10] )
    {
      sub_409440((int)this, 6, 1, 1);
    }
    else if ( a2 == this[11] )
    {
      sub_409440((int)this, 7, 1, 1);
    }
    else if ( a2 == this[12] )
    {
      sub_409440((int)this, 8, 1, 1);
    }
    else
    {
      v5 = this[14];
      v6 = 0;
      if ( v5 <= 0 )
        return result;
      for ( i = this[8]; i != a2; i += 200 )
      {
        if ( ++v6 >= v5 )
          return result;
      }
      sub_409440((int)this, 4, 1, 1);
      this[15] = v6;
    }
    if ( a3 )
      (*(void (__thiscall **)(_DWORD *))(*this + 16))(this);
    return 1;
  }
  return result;
}
