// f1c  0x004918d0  size=140
char __thiscall sub_4918D0(int **this, __int16 a2, __int16 a3, int a4, int a5)
{
  int v7; // ebx
  int v8; // esi

  if ( a4 <= 0 || a5 <= 0 )
    return 0;
  if ( (unsigned __int8)sub_4F9B20(&unk_8AFE18) )
  {
    v7 = **this;
    if ( v7 > 0 )
    {
      v8 = 0;
      do
      {
        sub_490EE0((void ***)(v8 + (*this)[2]), a2, a3, a4, a5);
        v8 += 16;
        --v7;
      }
      while ( v7 );
    }
    return 1;
  }
  else
  {
    sub_490EE0((void ***)((*this)[2] + 16 * (*this)[1]), a2, a3, a4, a5);
    return 1;
  }
}
