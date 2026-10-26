void __thiscall sub_41BBF0(void *this)
{
  _DWORD *v2; // esi
  int v3; // esi
  float v4; // [esp+0h] [ebp-10h]

  if ( dword_7688A0 )
  {
    if ( flt_7678BC != 0.0 )
    {
      if ( byte_6292D8 )
      {
        if ( sub_4633A0(&unk_764D70) != 1 )
        {
          v2 = off_5FD348;
          if ( off_5FD348 )
          {
            if ( *((int *)off_5FD348 + 6312) >= 0
              && (unsigned __int8)sub_4BBF20(&unk_766220)
              && v2[6061] == 1
              && v2[6062] != 1 )
            {
              sub_41BCD0(this);
              v3 = dword_7D3C44;
              if ( dword_79FC40 < 1023 )
              {
                ++dword_79FC40;
                dword_7D3C44 += 208;
              }
              v4 = dbl_7DA9D0;
              sub_4D0D00(4, 39, 1, 63, LODWORD(v4), 3);
              *(_BYTE *)(v3 + 8) = 1;
            }
          }
        }
      }
    }
  }
}
