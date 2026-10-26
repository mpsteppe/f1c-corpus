// f1c  0x00461d20  size=143
char __thiscall sub_461D20(void *this)
{
  int v2; // eax
  int v3; // eax
  char v4; // cl

  v2 = sub_461CD0(this);
  if ( v2 > 0 && v2 <= 3 )
  {
    *(float *)(*(_DWORD *)this + 896) = *(float *)(*(_DWORD *)this + 896) - dbl_8AFE90;
    v2 = sub_57A900(*(_DWORD *)(*(_DWORD *)this + 16312));
    if ( !v2 )
    {
      LOBYTE(v2) = *(_BYTE *)(*(_DWORD *)this + 48);
      if ( !(_BYTE)v2 )
      {
        if ( sub_423A00(byte_5EC4C0, aYouHaveBeenBoo, byte_5EC4CC) )
        {
          v3 = 0;
          do
          {
            v4 = aYouHaveBeenBoo[v3];
            byte_5EC4CC[v3++] = v4;
          }
          while ( v4 );
        }
        LOBYTE(v2) = sub_45BD10(&dword_7CD204, (int)byte_5EC4CC, 3, 16909060);
        *(_BYTE *)(*(_DWORD *)this + 48) = 1;
      }
    }
  }
  return v2;
}
