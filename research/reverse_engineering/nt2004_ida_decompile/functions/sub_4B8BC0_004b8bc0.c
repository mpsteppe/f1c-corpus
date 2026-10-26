char sub_4B8BC0()
{
  int v0; // eax
  int v1; // edi
  int v2; // ebx
  int v3; // esi
  int v4; // ebp

  LOBYTE(v0) = byte_76617C;
  if ( !byte_76617C )
  {
    LOBYTE(v0) = sub_463490(dword_764D70);
    if ( (_BYTE)v0 )
    {
      if ( sub_4633A0(dword_764D70) == 3 || (v0 = sub_463BD0(dword_764D70), v0 > 1) )
      {
        if ( !sub_463520() || (v0 = sub_463BD0(dword_764D70), v0 > 2) )
        {
          LOBYTE(v0) = sub_4651D0(dword_764D70);
          if ( (_BYTE)v0 )
          {
            v1 = dword_766088;
          }
          else
          {
            LOBYTE(v0) = sub_4651E0(dword_764D70);
            if ( (_BYTE)v0 )
            {
              v1 = dword_76608C;
            }
            else
            {
              LOBYTE(v0) = sub_465190(dword_764D70);
              if ( !(_BYTE)v0 )
                return v0;
              v1 = dword_766084;
            }
          }
          if ( v1 )
          {
            v2 = dword_6152EC;
            v3 = dword_6152EC / 8;
            v4 = sub_4B1A80(150994943, -1, 0.0);
            sub_5069D0(dword_6152E8 - v3 - 4, v2 / 2 - v3 / 2, 1, 0);
            sub_506980(v3, v3);
            sub_506B20(v4);
            LOBYTE(v0) = sub_506960(0);
          }
        }
      }
    }
  }
  return v0;
}
