char __thiscall sub_414090(_DWORD *this)
{
  int v1; // eax

  if ( *(_DWORD *)dword_B72314 != 8 || (LOBYTE(v1) = byte_91E048) != 0 )
  {
    v1 = *(_DWORD *)(*(&dword_91E088 + dword_91E078) + 22468);
    if ( v1 != *(_DWORD *)(*(&dword_91E088 + dword_91E080) + 22468) )
    {
      v1 = this[3];
      switch ( v1 )
      {
        case -1:
        case 1:
          goto LABEL_6;
        case 2:
          if ( !dword_B71890 )
          {
LABEL_6:
            this[7] = v1;
            LOBYTE(v1) = sub_412EB0(this, 5, 0);
          }
          break;
        default:
          return v1;
      }
    }
  }
  return v1;
}
