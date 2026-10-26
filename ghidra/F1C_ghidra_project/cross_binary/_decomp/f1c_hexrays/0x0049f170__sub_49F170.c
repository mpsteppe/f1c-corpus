// f1c  0x0049f170  size=71
int __thiscall sub_49F170(_DWORD *this, char a2)
{
  int result; // eax
  int v3; // ebp
  int v4; // ebp
  int v5; // ebp

  result = dword_7C54E8 + 13004;
  do
  {
    v3 = this[1];
    if ( a2 )
    {
      v4 = v3 - 1;
      this[1] = v4;
      if ( v4 < 0 )
        this[1] = 4;
    }
    else
    {
      v5 = v3 + 1;
      this[1] = v5;
      if ( v5 >= 5 )
        this[1] = 0;
    }
  }
  while ( *(int *)(result + (this[1] << 6) + 40) <= 1 );
  return result;
}
