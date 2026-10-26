int __cdecl sub_58DCD0(int a1)
{
  int v1; // edi
  int v2; // ebx
  signed int v3; // esi
  signed int v4; // edi

  v1 = a1;
  v2 = 0;
  if ( dword_7FFA40[a1] )
  {
    v3 = sub_58DD70(a1);
    if ( v3 >= 0 )
    {
      while ( 1 )
      {
        a1 = dword_7FFAB4[24 * v3];
        if ( sub_58E0B0(&a1) == 1 )
          break;
        sub_58DB10(v3);
        v3 = sub_58DD70(v1);
        if ( v3 < 0 )
          return v2;
      }
      sub_58E000(v3);
      v4 = v3;
      sub_58E130();
      do
      {
        v2 = sub_58F8C0(v4);
        v4 = word_7FFAAE[48 * v4];
      }
      while ( v4 != -1 && v2 );
      sub_58DB10(v3);
    }
  }
  return v2;
}
