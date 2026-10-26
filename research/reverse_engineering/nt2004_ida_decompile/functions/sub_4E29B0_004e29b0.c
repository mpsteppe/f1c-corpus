int sub_4E29B0()
{
  int result; // eax
  int i; // ebp
  int v2; // ebx
  int v3; // edi
  int v4; // [esp-14h] [ebp-20h]
  int v5; // [esp-10h] [ebp-1Ch]
  int v6; // [esp+4h] [ebp-8h]

  result = dword_5FD344;
  for ( i = 0; i < dword_5FD344; ++i )
  {
    if ( dword_7D5DA4 == 2 )
    {
      sub_51BC20(3, 0);
    }
    else
    {
      if ( dword_75CBAC == 2 )
        v4 = 2;
      else
        v4 = 1;
      sub_51BC20(v4, 0);
    }
    if ( i )
    {
      v5 = sub_4E33C0(1);
      sub_4EEAE0(v5);
    }
    else
    {
      v2 = 0;
      v6 = 0;
      if ( dword_7D6A58 > 0 )
      {
        v3 = 0;
        while ( !(v3 + dword_7D6A5C) || _strcmpi(aPaceCar, (const char *)(v3 + dword_7D6A5C + 246)) )
        {
          ++v2;
          v3 += 1232;
          if ( v2 >= dword_7D6A58 )
            goto LABEL_14;
        }
        v6 = v2;
      }
LABEL_14:
      sub_4EEAE0(v6);
    }
    sub_4EDDB0(i + 48);
    result = dword_5FD344;
  }
  return result;
}
