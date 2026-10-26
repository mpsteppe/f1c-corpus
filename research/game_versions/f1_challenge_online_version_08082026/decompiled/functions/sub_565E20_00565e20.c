int __thiscall sub_565E20(LPVOID ****this)
{
  int result; // eax
  LPVOID ***v3; // ebx
  LPVOID **v4; // esi
  LPVOID **v5; // edi
  LPVOID *v6; // ebp

  result = sub_565D50(*this);
  v3 = *this;
  if ( *this )
  {
    if ( v3[132] )
      sub_587BCF(v3[132]);
    v4 = *v3;
    while ( v4 )
    {
      v5 = v4;
      v4 = (LPVOID **)v4[1];
      if ( *((_BYTE *)v5 + 8) )
      {
        v6 = *v5;
        if ( *v5 )
        {
          sub_414370(v6 + 81);
          sub_587BCF(v6);
        }
      }
      sub_587BCF(v5);
    }
    *v3 = 0;
    v3[1] = 0;
    v3[2] = 0;
    v3[3] = 0;
    return sub_587BCF(v3);
  }
  return result;
}
