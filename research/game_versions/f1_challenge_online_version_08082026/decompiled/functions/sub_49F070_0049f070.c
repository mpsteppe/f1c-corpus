char __thiscall sub_49F070(void *this)
{
  int v2; // eax
  int v3; // edi
  int v4; // ebx
  int v5; // esi
  int v6; // ebp

  sub_49F790();
  sub_4082B0(&flt_5EA4E8);
  sub_461D20(dword_7CD25C);
  sub_4D8450(&dword_8AD298);
  sub_49D070(&dword_7CE058);
  if ( dword_8AB6E4 != 2 )
    sub_45BC00((int *)&dword_7CD204);
  sub_49F870(this);
  LOBYTE(v2) = byte_7CE254;
  if ( !byte_7CE254 )
  {
    LOBYTE(v2) = sub_461DB0(dword_7CD25C);
    if ( (_BYTE)v2 )
    {
      if ( sub_461CD0(dword_7CD25C) == 3 || (v2 = sub_462380(dword_7CD25C), v2 > 1) )
      {
        LOBYTE(v2) = sub_4636E0(dword_7CD25C);
        if ( (_BYTE)v2 )
        {
          v3 = dword_7CE244;
        }
        else
        {
          LOBYTE(v2) = sub_4636F0(dword_7CD25C);
          if ( (_BYTE)v2 )
          {
            v3 = dword_7CE248;
          }
          else
          {
            LOBYTE(v2) = sub_4636A0(dword_7CD25C);
            if ( !(_BYTE)v2 )
              return v2;
            v3 = dword_7CE240;
          }
        }
        if ( v3 )
        {
          v4 = dword_5D6D64;
          v5 = dword_5D6D64 / 8;
          v6 = sub_49B200(150994943, -1, 0.0);
          sub_4DCDD0(dword_5D6D60 - v5 - 4, v4 / 2 - v5 / 2, 1, 0);
          sub_4DCD80(v5, v5);
          sub_4DCF20(v6);
          LOBYTE(v2) = sub_4DCD60(0);
        }
      }
    }
  }
  return v2;
}
